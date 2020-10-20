#include "ListGenerator.h"

/**
     * @brief
     * Generate 'count' random integers[0..99] and add everyone to List.
     * @param   count   Count of integers we want to add.
     * @param   list    Point on List.
     */
void ListGenerator::random_int(int count, List<int> *list) {
    int res;

    for(int i = 0; i < count; i++){
        srand(time(nullptr) + i);
        res = rand() % 100;

        list->add(res);
    }
}

/**
     * @brief
     * Generate 'count' random real numbers[0..99] and add everyone to List.
     * @param   count   Count of real numbers we want to add.
     * @param   list    Point on List.
     */
void ListGenerator::random_double(int count, List<double> *list) {
    double res;

    for(int i = 0; i < count; i++){
        srand(time(nullptr) + i);
        res = rand() % 50;
        res += ((rand() % 51)) / (rand() % 50 + 1.0);

        list->add(res);
    }
}

/**
     * @brief
     * Generate 'count' random std::strings(size[0..99]) and add everyone to List.
     * @param   count   Count of strings we want to add.
     * @param   list    Point on List.
     */
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

/**
     * @brief
     * Generate 'count' random std::vector<int>(size[1..20], int[0..99]) and add everyone to List.
     * @param   count   Count of vectors we want to add.
     * @param   list    Point on List.
     */
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

/**
     * @brief
     * Generate 'count' random Books and add everyone to List.
     * @param   count   Count of Books we want to add.
     * @param   list    Point on List.
     */
void ListGenerator::random_book(int count, List<Book> *list) {
    std::string name;
    int pages;
    std::string description;
    std::string date;
    std::string author;
    for(int i = 0; i < count; i++){
        srand(time(nullptr) + i);

        name = "";
        pages = 0;
        description = "";
        date = "";
        author = "";
        int date_prob;

        for(int i = 0; i < rand() % 20 + 1; i++){
            name += (char)(rand() % 57 + 65) ;
        }
        pages = rand() % 1000 + 1;
        for(int i = 0; i < rand() % 250 + 1; i++){
            description += (char)(rand() % 57 + 65);
        }

        date_prob = rand() % 2021;
        if(date_prob < 1000) date += "0";
        if(date_prob < 100) date += "0";
        if(date_prob < 10) date += "0";
        date += std::to_string(date_prob) + ":";

        date_prob = rand() % 12 + 1;
        if(date_prob < 10) date += "0";
        date += std::to_string(date_prob) + ":";

        date_prob = rand() % 30 + 1;
        if(date_prob < 10) date += "0";
        date += std::to_string(date_prob);

        for(int i = 0; i < rand() % 250 + 1; i++){
            author += (char)(rand() % 57 + 65);
        }

        list->add(new Book(name, pages, description, date, new std::vector<std::string>{author}));
    }
}

/**
     * @brief
     * Generate 'count' random Characters and add everyone to List.
     * @param   count   Count of Characters we want to add.
     * @param   list    Point on List.
     */
void ListGenerator::random_character(int count, List<Character> *list) {
    std::string str;

    for(int i = 0; i < count; i++){
        srand(time(nullptr) + i);
        str = "";
        for(int i = 0; i < rand() % 100; i++){
            str += (char)(rand() % 127 - 33) + 33;
        }

        list->add(new Character(str));
    }
}
