#include "Interview.h"
#include "Question.h"
#include "utils.h"
#include <vector>
#include <fstream>
#include <iostream>

// Add a question to the interview
void Interview::addQuestion(Question quest){
    std::string category = quest.getCategory();

    //if category doesn't exist yet, create it
    if (questions.find(category) == questions.end()) {
        questions[category] = std::vector<Question>();
    }

    questions[category].push_back(quest);
};

// Load questions from a Markdown file
void Interview::loadQuestionsMD(std::string filepath){
    // Create a text string, which is used to output the text file
    std::string myText;
    std::string category;
    std::string question;
    std::string answer = "";

    // Read from the text file
    std::ifstream MyReadFile(filepath);

    while (std::getline (MyReadFile, myText)) {
        
        // Categories labeled with #
        if (myText.size() > 1 && myText[0] == '#') {
            // if there is a question already, push it to list of questions
            if ( question.size() > 0) {
                addQuestion(Question(question, answer, category));
            };

            category = myText.substr(1, myText.size()-1);

            //reset question and answer string
            question = "";
            answer = "";
        };

        // Questions labelled with *
        if (myText.size() > 1 && myText[0] == '*') {
            // if there is a question already, push it to list of questions
            if ( question.size() > 0) {
                addQuestion(Question(question, answer, category));
            };         

            //question = boost::algorithm::trim(myText.substr(1, size));
            question = myText.substr(1, myText.size()-1);

            //reset answer string
            answer = "";
        };      

        // Append lines to the answer if a question has been encountered
        if (myText[0] != '*' && question.size() > 0) {
            answer = answer + "\n" + myText;
        }

    };

    // Close the file
    MyReadFile.close();   
};

// Start the interview by iterating through the questions and asking them
void Interview::startInterview(const std::map<std::string, int>& numQuestionsPerCategory) {
    int questionNo = 0;

    std::cout << "Welcome to your interview! Let's begin. " << std::endl;
    std::cout << "" << std::endl;

    for (auto it = questions.begin(); it != questions.end(); it++) {
        const std::string& category = it->first;
        const std::vector<Question>& categoryQuestions = it->second;
        std::vector<int> questIndices = utils::til_shuffle(categoryQuestions.size());

        // Determine the number of questions to ask for the current category
        int numQuestions = 10;  // Default value if category is not specified

        // Check if a number of questions has been specified for this category. If not, use default
        if (numQuestionsPerCategory.find(category) != numQuestionsPerCategory.end()) {

            // Use .at() instead of [] as [] adds the category if it doesnt exist whereas .at() throws an error
            int numQuestions = numQuestionsPerCategory.at(category);     
        };

        // Ensure that the number of questions does not exceed the available questions
        numQuestions = std::min(numQuestions, static_cast<int>(questIndices.size()));        
                
        std::cout << "Category: " << category << std::endl;
        std::cout << "Number of Questions: " << numQuestions << std::endl;

        for (int i=0; i<numQuestions; i++){
            Question curQuestion = categoryQuestions[questIndices[i]];
            curQuestion.ask(++questionNo);
        };        
    };    
};