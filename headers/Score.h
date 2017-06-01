#ifndef SFML_TUT_SCORE_H
#define SFML_TUT_SCORE_H
#include <iostream>
#include <string>

class Score{
public:
    void increase(int value);
    std::string* get_string();
    int score;
    static Score* getInstance();
private:
};

#endif //SFML_TUT_SCORE_H
