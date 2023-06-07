#include <string>
#include <iostream>
#include <map>
#include "Question.h"

// Constructor: Initialize the Question object with the provided question, answer, and category
Question::Question(std::string quest, std::string ans, std::string cat){
    question = quest;
    answer = ans;
    category = cat;
}

std::string Question::getQuestion(){
    return question;
}

std::string Question::getAnswer(){
    return answer;
}

std::string Question::getCategory(){
    return category;
}

// Ask the question and handle the user response
void Question::ask(int num){
    std::string resp;
    enum responses {n,N,y,Y}; // Enumeration to represent user responses
    std::map<std::string, responses> respMap = { {"y",y}, {"Y",Y}, {"n",n}, {"N",N}}; //map to map string values to responses enum

    std::cout << "Question " << num << ": " << question << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Show Answer? (y/n)" << std::endl;
    std::getline(std::cin, resp);
    std::cout << "" << std::endl;
   
    switch (respMap[resp]){
    case y: 
    case Y: 
        std::cout << "Answer: " << answer << std::endl;
        break;
    default:
        break;
    };

    std::cout << "" << std::endl;

}