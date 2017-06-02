#include "../headers/Score.h"

Score* Score::getInstance(){
    static Score score;
    return &score;
}

void Score::increase(int value){
    this->score += value/8;
    std::cout << this->score << std::endl;
    std::cout << this << std::endl;
}

std::string* Score::get_string(){
    std::cout << this << std::endl;
    return new std::string("Score: " + std::to_string(this->score));
}