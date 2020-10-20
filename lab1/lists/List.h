#ifndef KNU_OOP_K28_LIST_H
#define KNU_OOP_K28_LIST_H

#include "sstream"
#include "../sorts/Sort.h"
#include "../sorts/QuickSort.h"

/**
 * @brief
 * Interface for working with dynamic arrays(lists).
 * @tparam  T   Class or primitive with override operators: std::ostream<< and (relational operators or have it own Comparator).
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
     * Method for sort the list by Comparator.
     * @details
     * If the pointer on Comparator is not specified or equals 'nullptr', the list must be sorted by object`s relational operators.
     * Method must create array of elements in the list for pass to Sort`s method.
     * Then the method must clear the list and add all elements from array to list.
     * @param   comparator   The point on Comparator which compare two objects. DefaultComparator if not init.
     */
    virtual void sort(Comparator<T> *comparator = nullptr) = 0;

    /**
     * @brief
     * Override method for sort the list by Comparator and certain sort.
     * @details
     * If the pointer on Comparator is not specified or equals 'nullptr', the list must be sorted by object`s relational operators.
     * Method must create array of elements in the list for pass to Sort`s method.
     * Then the method must clear the list and add all elements from array to list.
     * @param   sort        The pointer on Sort object which have one method - 'sort'. It sort list by certain type.
     * @param   comparator  The point on Comparator which compare two objects. DefaultComparator if not init.
     */
    virtual void sort(Sort<T> *sort, Comparator<T> *comparator = nullptr) = 0;

    /**
     * @brief
     * Return the size of list.
     * @return  size of list.
     */
    virtual int get_size() = 0;

    /**
     * @brief
     * Return std::string representation.
     * @return The string of this List.
     */
    virtual std::string to_string() = 0;

    /**
     * @brief
     * Override operator<< of ostream.
     * Out look like:
     * @code
     * [T, T, T, T, T]
     * @endcode
     */
    friend std::ostream &operator<<(std::ostream &out, List<T> &list) {
        out << list.to_string();
        return out;
    };

    /**
     * @brief
     * Equality operator.
     * @param   rhs     Second List.
     * @return          If sizes and object in lists are the same -> true, else -> false.
     */
    bool operator==(List &rhs) {
        if (get_size() != rhs.get_size()) return false;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) != rhs.get(i)) return false;
        }
        return true;
    }

    /**
     * @brief
     * Inequality operator.
     * @param   rhs     Second List.
     * @return          If sizes and object in lists are the same -> false, else -> true.
     */
    bool operator!=(List &rhs) {
        return !(rhs == *this);
    }

    /**
     * @brief
     * Relation 'less that' operator.
     * @param   rhs     Second List.
     * @return          If size == rhs`s size -> [i] < rhs`s[i], else -> size < rhs`s size.
     */
    bool operator<(List &rhs) {
        if(get_size() == rhs.get_size()){
            for (int i = 0; i < get_size(); i++) {
                if (get(i) < rhs.get(i)) return true;
            }
            return false;
        }
        return get_size() < rhs.get_size();
    }

    /**
    * @brief
    * Relation 'great that' operator.
    * @param   rhs     Second List.
    * @return          rhs < *this.
    */
    bool operator>(List &rhs) {
        return rhs < *this;
    }

    /**
     * @brief
     * Relation 'less or equals' operator.
     * @param   rhs     Second List.
     * @return          !(rhs < *this).
     */
    bool operator<=(List &rhs) {
        return !(rhs < *this);
    }

    /**
    * @brief
    * Relation 'great or equals' operator.
    * @param   rhs     Second List.
    * @return          !(*this < rhs).
    */
    bool operator>=(List &rhs) {
        return !(*this < rhs);
    }
};


#endif
