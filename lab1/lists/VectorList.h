#ifndef KNU_OOP_K28_VECTORLIST_H
#define KNU_OOP_K28_VECTORLIST_H

#include "List.h"
#include <vector>
#include <iostream>

/**
 * @brief
 * Class of dynamic array(list) based on std::vector.
 * @tparam  T   Class or primitive with override operators: std::ostream<<, >, <, ==, !=, >=, <=.
 */
template<class T>
class VectorList : public List<T> {
    std::vector<T> vect;    ///< Vector we work with.

public:
    ~VectorList() {
        clear();
    }

    /**
     * @brief
     * Add element to VectorList.
     * @details
     * Adds an element and puts it in a certain position.
     * If the index is not specified or less than zero - adds an item to the end of the VectorList.
     * If an item is not added to the end of the VectorList, the item that belonged to that index(and all after it) moves forward.
     * @throw   std::out_of_range If index is bigger than size.
     * @param   obj     The element which we want to add to VectorList.
     * @param   index   The index on which we want to place the element.
     */
    void add(T obj, int index = -1) override {
        if (index < 0)
            index = vect.size();
        else if (index > vect.size())
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");

        if (index == vect.size()) vect.push_back(obj);
        else vect.insert(vect.begin() + index, obj);
    }

    /**
    * @brief
    * Remove element by index from VectorList.
    * @details
    * If we remove element by index, all elements with bigger index moved:
    * index+1 -> index, index+2 -> index+1;
    * But:
    * index-1 -> index-1, index-2 -> index-2;
    * If index is less than 0, than index = size - 1 (remove last element in VectorList).
    * @throw   std::out_of_range If index is bigger than size - 1.
    * @param   index   The index by which we want to delete the item.
    */
    void remove(int index) override {
        if ((index >= 0 && index >= vect.size()) || (index < 0 && vect.size() == 0))
            throw std::out_of_range(
                    "index " + std::to_string(index) + " is greater then the size-1 :" + std::to_string(vect.size()));
        else if (index < 0)
            index = vect.size() - 1;

        vect.erase(vect.begin() + index);
    }

    /**
     * @brief
     * Get element by index from VectorList.
     * @details
     * Method returns reference not an element.
     * If index is less than 0, than index = size - 1 (remove last element from the VectorList).
     * If index is bigger or equals to the size, than method must throw std::out_of_range.
     * @param   index   The index of the element in the VectorList we want to get.
     * @return          Element from the VectorList by index.
     */
    T &get(int index) override {
        if ((index >= 0 && index >= vect.size()) || (index < 0 && vect.size() == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = vect.size() - 1;

        return vect.at(index);
    }

    /**
     * @brief
     * Find the index of an element in the VectorList.
     * @details
     * If the element is not contained in the list, method return -1.
     * If the VectorList contains great than 1 such element, method return tne first index.
     * @param   obj     The element which index we want to know.
     * @return          The index of the element in the VectorList or -1 if element is not contained.
     */
    int find(T obj) override {
        int res = -1;

        for (int i = 0; i < vect.size(); i++) {
            if (vect[i] == obj) {
                res = i;
                break;
            }
        }
        return res;
    }

    /**
     * @brief
     * Remove all elements of the VectorList.
     * Now size = 0;
     */
    void clear() override {
        vect.clear();
    }

    /**
    * @brief
    * Method for sort the VectorList.
    * @details
    * If the sort function is not specified or equals 'nullptr', the VectorList will be sorted by quick sort function.
    * Method creates array of elements in the VectorList for pass to sort function.
    * Then the method clears the list and add all elements from array to VectorList.
    * @param   sort_func   The function for sort which takes the array of elements from the VectorList and size of the VectorList.
    */
    void sort(Comparator<T> *comparator = nullptr) {
        QuickSort<T> quickSort;
        quickSort.sort(&vect[0], vect.size(), comparator);
    }

    /**
     * @brief
     * Override method for sort the VectorList by compare function.
     * @details
     * If the compare function is not specified or equals 'nullptr', the VectorList will be sorted by default operators(>, <, ==, !=, >=, <=).
     * Method also creates array of elements from the Linked for pass to sort function.
     * Then the method clears the VectorList and add all elements from array to VectorList.
     * @param   sort_func       The function for sort which takes the array of elements from the VectorList, size of the list and compare function.
     * @param   compare_func    The function which takes 2 elements and return: 1 -> if first is bigger, -1 -> if first is less, 0 -> else.
     */
    void sort(Sort<T> *sort, Comparator<T> *comparator = nullptr) override {
        sort->sort(&vect[0], vect.size(), comparator);
    }

    /**
     * @brief
     * Static method for sort any other array
     * @details
     * Same to not static method but instead of a private vector pass it as parameter.
     * @param   global_vector   Vector we want to sort.
     * @param   sort_func       The function for sort which takes the array of elements in the list, size of the list and compare function.
     * @param   compare_func    The function which takes 2 elements and return: 1 -> if first is bigger, -1 -> if first is less, 0 -> else.
     */

    static void sort(std::vector<T> global_vector, Sort<T> *sort = nullptr, Comparator<T> *comparator = nullptr) {
        if(sort)
            sort->sort(&global_vector[0], global_vector.size(), comparator);
        else{
            QuickSort<T> quickSort;
            quickSort.sort(&global_vector[0], global_vector.size(), comparator);
        }
    }

    /**
    * @brief
    * Return the size of VectorList.
    * @return  size of VectorList.
    */
    int get_size() override {
        return vect.size();
    }

    std::string to_string() override{
        std::stringstream ss;

        ss << '[';
        if (vect.size() != 0) {
            for (int i = 0; i < vect.size() - 1; i++) {
                ss << vect[i] << ", ";
            }
            ss << vect[vect.size() - 1];
        }
        ss << ']';

        return ss.str();
    }

    /**
     * @brief
     * Override operator<< of ostream.
     * Out look like:
     * @code
     * [T, T, T, T, T]
     * @endcode
     */
    friend std::ostream &operator<<(std::ostream &out, VectorList<T> &list) {
        out << list.to_string();
        return out;
    }

    bool operator==(VectorList &rhs) {
        if (get_size() != rhs.get_size()) return false;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) != rhs.get(i)) return false;
        }
        return true;
    }

    bool operator!=(VectorList &rhs) {
        return !(rhs == *this);
    }

    bool operator<(VectorList &rhs) {
        if (get_size() < rhs.get_size()) return true;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) < rhs.get(i)) return true;
        }
        return false;
    }

    bool operator>(VectorList &rhs) {
        return rhs < *this;
    }

    bool operator<=(VectorList &rhs) {
        return !(rhs < *this);
    }

    bool operator>=(VectorList &rhs) {
        return !(*this < rhs);
    }

};


#endif
