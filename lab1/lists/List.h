#ifndef KNU_OOP_K28_LIST_H
#define KNU_OOP_K28_LIST_H

#include "../sorts/sorts.h"

/**
 * @brief
 * Interface for working with dynamic arrays(lists).
 * @details
 * Classes must also implement a friend method for outputting elements.
 * Classes must also have two constructors - an empty one and one that looks like this:
 * @code
 * List(int count, T(*create_func)(int index));
 * @endcode
 * count - the number of items to be added to list.
 * create_func - function witch generate elements by index.
 * @tparam  T   Class or primitive with override operators: std::ostream<<, >, <, ==, !=, >=, <=.
 */

template<class T>
class List {
public:
    /**
     * @brief
     * Add element to list.
     * @details
     * Adds an element and puts it in a certain position.
     * If the index is not specified or less than zero - adds an item to the end of the list.
     * If an item is not added to the end of the list, the item that belonged to that index(and all after it) moves forward.
     * If index is bigger or equals to the size, than method must throw std::out_of_range.
     * @param   obj     The element which we want to add to list.
     * @param   index   The index on which we want to place the element.
     */
    virtual void add(T obj, int index = -1) = 0;

    /**
     * @brief
     * Remove element by index from list.
     * @details
     * If we remove element by index, all elements with bigger index moved:
     * index+1 -> index, index+2 -> index+1;
     * But:
     * index-1 -> index-1, index-2 -> index-2;
     * If index is less than 0, than index = size - 1 (remove last element in list).
     * If index is bigger or equals to the size, than method must throw std::out_of_range.
     * @param   index   The index by which we want to delete the item.
     */
    virtual void remove(int index) = 0;

    /**
     * @brief
     * Get element by index from list.
     * @details
     * Method returns reference not an element.
     * If index is less than 0, than index = size - 1 (remove last element from the list).
     * If index is bigger or equals to the size, than method must throw std::out_of_range exeption.
     * @param   index   The index of the element in the list we want to get.
     * @return          The element from list by index.
     */
    virtual T &get(int index) = 0;

    /**
     * @brief
     * Find the index of an element in the list.
     * @details
     * If the element is not contained in the list, method return -1.
     * If the list contains great than 1 such element, method return tne first index.
     * @param   obj     The element which index we want to know.
     * @return          The index of the element in the list or -1 if element is not contained.
     */
    virtual int find(T obj) = 0;

    /**
     * @brief
     * Remove all elements of the list.
     * Now size = 0;
     */
    virtual void clear() = 0;

    /**
     * @brief
     * Method for sort the list.
     * @details
     * If the sort function is not specified or equals 'nullptr', the list must be sorted by quick sort function.
     * Method must create array of elements in the list for pass to sort function.
     * Then the method must clear the list and add all elements from array to list.
     * @param   sort_func   The function for sort which takes the array of elements from the list and size of the list.
     */
    virtual void sort(void (*sort_func)(T *, int) = nullptr) = 0;

    /**
     * @brief
     * Override method for sort the list by compare function.
     * @details
     * If the compare function is not specified or equals 'nullptr', the list must be sorted by default operators(>, <, ==, !=, >=, <=).
     * Method also must create array of elements in the list for pass to sort function.
     * Then the method must clear the list and add all elements from array to list.
     * @param   sort_func       The function for sort which takes the array of elements in the list, size of the list and compare function.
     * @param   compare_func    The function which takes 2 elements and return: 1 -> if first is bigger, -1 -> if first is less, 0 -> else.
     */
    virtual void sort(void (*sort_func)(T *, int, int(*)(T &obj1, T &obj2)),
                      int(*compare_func)(T &obj1, T &obj2) = nullptr) = 0;

    /**
     * @brief
     * Return the size of list.
     * @return  size of list.
     */
    virtual int get_size() = 0;
};


#endif
