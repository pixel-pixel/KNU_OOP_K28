#ifndef KNU_OOP_K28_LISTGENERATOR_H
#define KNU_OOP_K28_LISTGENERATOR_H

#include <ctime>
#include <string>
#include <vector>
#include "../lab_classes/Book.h"
#include "../lab_classes/Character.h"
#include "../lists/List.h"


class ListGenerator {
public:
    static void random_int(int count, List<int> *list);

    static void random_double(int count, List<double> *list);

    static void random_string(int count, List<std::string> *list);

    static void random_vector_int(int count, List<std::vector<int>> *list);

    static void random_book(int count, List<Book> *list);

    static void random_character(int count, List<Character> * list);
};


#endif
