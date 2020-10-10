#ifndef KNU_OOP_K28_LISTGENERATOR_H
#define KNU_OOP_K28_LISTGENERATOR_H

#include <ctime>
#include <string>
#include <vector>
#include "../lab_classes/Book.h"
#include "../lab_classes/Character.h"
#include "../lists/List.h"

/**
 * @brief
 * Class with static methods.They generate and add objects to List.
 */
class ListGenerator {
public:
    /**
     * @brief
     * Generate 'count' random integers[0..99] and add everyone to List.
     * @param   count   Count of integers we want to add.
     * @param   list    Point on List.
     */
    static void random_int(int count, List<int> *list);

    /**
     * @brief
     * Generate 'count' random real numbers[0..99] and add everyone to List.
     * @param   count   Count of real numbers we want to add.
     * @param   list    Point on List.
     */
    static void random_double(int count, List<double> *list);

    /**
     * @brief
     * Generate 'count' random std::strings(size[0..99]) and add everyone to List.
     * @param   count   Count of strings we want to add.
     * @param   list    Point on List.
     */
    static void random_string(int count, List<std::string> *list);

    /**
     * @brief
     * Generate 'count' random std::vector<int>(size[1..20], int[0..99]) and add everyone to List.
     * @param   count   Count of vectors we want to add.
     * @param   list    Point on List.
     */
    static void random_vector_int(int count, List<std::vector<int>> *list);

    /**
     * @brief
     * Generate 'count' random Books and add everyone to List.
     * @param   count   Count of Books we want to add.
     * @param   list    Point on List.
     */
    static void random_book(int count, List<Book> *list);

    /**
     * @brief
     * Generate 'count' random Characters and add everyone to List.
     * @param   count   Count of Characters we want to add.
     * @param   list    Point on List.
     */
    static void random_character(int count, List<Character> * list);
};


#endif
