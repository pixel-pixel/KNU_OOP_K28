#include "ListGenerator.h"

void ListGenerator::random_int(int count, List<int> *list) {
    int res;

    for(int i = 0; i < count; i++){
        srand(time(nullptr) + i);
        res = rand() % 100;

        list->add(res);
    }
}

void ListGenerator::random_double(int count, List<double> *list) {
    double res;

    for(int i = 0; i < count; i++){
        srand(time(nullptr) + i);
        res = rand() % 50;
        res += ((rand() % 51)) / (rand() % 50 + 1.0);

        list->add(res);
    }
}

void ListGenerator::random_string(int count, List<std::string> *list) {
    std::string res;

    for(int i = 0; i < count; i++){
        srand(time(nullptr) + i);
        res = "";
        for(int i = 0; i < rand() % 100; i++){
            res += (char)(rand() % 127 - 33) + 33;
        }

        list->add(res);
    }
}

void ListGenerator::random_vector_int(int count, List<std::vector<int>> *list) {
    std::vector<int> res;

    for (int i = 0; i < count; ++i) {
        res.clear();

        srand(time(nullptr) + i);
        for(int i = 0; i < rand() % 20 + 1; i++){
            res.push_back(rand() % 100);
        }

        list->add(res);
    }
}
