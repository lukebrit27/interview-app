#ifndef QUEST_H
#define QUEST_H
#include <string>

class Question{
private:
    std::string question;
    std::string answer;
    std::string category;    
public:
    Question(std::string quest, std::string ans, std::string cat);
    std::string getQuestion();
    std::string getAnswer();
    std::string getCategory();
    void ask(int num);   
};

#endif // QUEST_H