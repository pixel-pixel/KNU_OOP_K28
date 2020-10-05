#include "create.h"
#include <cstdlib>
#include <ctime>

int create_int_random(int index){
    srand(time(nullptr) + index);
    int res = rand() % 100;
    return res;
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

std::vector<int> create_vector_int_random(int index){
    std::vector<int> vect;

    srand(time(nullptr) + index);
    for(int i = 0; i < rand() % 20 + 1; i++){
        vect.push_back(rand() % 100);
    }
    return vect;
}