#ifndef KNU_OOP_K28_LISTGENERATOR_H
#define KNU_OOP_K28_LISTGENERATOR_H

#include <string>
#include <vector>
#include "../lists/List.h"
#include <ctime>

class ListGenerator {
public:
    static void random_int(int count, List<int> *list);

    static void random_double(int count, List<double> *list);

    static void random_string(int count, List<std::string> *list);

    static void random_vector_int(int count, List<std::vector<int>> *list);
};


#endif
