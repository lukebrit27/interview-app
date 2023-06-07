#ifndef INTERVIEW_H
#define INTERVIEW_H

#include <string>
#include <vector>
#include <map>
#include "Question.h"

class Interview{
private:
    std::map<std::string, std::vector<Question>> questions;
public:
    void addQuestion(Question quest);
    void loadQuestionsMD(std::string filepath);
    void startInterview(const std::map<std::string, int>& numQuestionsPerCategory);
};

#endif //INTERVIEW_H