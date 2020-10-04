#include "create.h"
#include <cstdlib>
#include <ctime>

int create_int_random(int index){
    srand(time(nullptr) + index);
    return rand() % 100;
}

double create_double_random(int index){
    srand(time(nullptr) + index);
    double res = rand() % 50;
    res += ((rand() % 51)) / (rand() % 50 + 1.0);
    return res;
}

std::string create_string_random(int index){
    srand(time(nullptr) + index);
    std::string res;
    for(int i = 0; i < rand() % 100; i++){
        res += (char)(rand() % 127 - 33) + 33;
    }
    return res;
}