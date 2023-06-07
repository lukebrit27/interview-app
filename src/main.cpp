#include "Question.h"
#include "Interview.h"
#include "utils.h"
#include <vector>
#include <iostream>


int main(int argc, char* argv[]){

   std::string markdownFile = "data/InterviewQuestions.md"; // Default Markdown file
   std::map<std::string, int> numQuestionsPerCategory;

   // Parse command-line arguments
   for (int i = 1; i < argc; i++) {
      std::string arg = argv[i];

      if (arg == "-f") {
         // Get the Markdown file from the next argument
         if (i + 1 < argc) {
               markdownFile = argv[i + 1];
               i++;  // Skip the next argument
         }
      }
      else if (arg == "-c") {
         // Get the category name from the next argument
         if (i + 1 < argc) {
               std::string category = argv[i + 1];
               i++;  // Skip the next argument

               // Assume the following argument is the number of questions for the current category
               if (i + 1 < argc) {
                  int numQuestions = std::stoi(argv[i + 1]);
                  numQuestionsPerCategory[category] = numQuestions;
                  i++;  // Skip the next argument
               }               
         }
      } 
   }

   // Create an instance of the Interview class
   Interview interview;

   // Load questions from a Markdown file
   interview.loadQuestionsMD(markdownFile);

   // Start the interview process
   interview.startInterview(numQuestionsPerCategory);

};