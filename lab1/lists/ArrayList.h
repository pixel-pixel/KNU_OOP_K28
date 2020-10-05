#ifndef KNU_OOP_K28_ARRAYLIST_H
#define KNU_OOP_K28_ARRAYLIST_H

#include <iostream>
#include "List.h"

/**
 * @brief
 * Class of dynamic array(list) based on array.
 * @tparam  T   Class or primitive with override operators: std::ostream<<, >, <, ==, !=, >=, <=.
 */
template<class T>
class ArrayList : List<T> {
private:
    int size = 0;            ///< Value for saving count of elements in ArrayList.
    int arr_size = 2;        ///< Value for saving size of array in ArrayList.
    T *arr = new T[16];      ///< Array with elements.

    /**
     * @brief
     * Create new array[new_size], write all elements from old array, delete old array.
     * @param   new_size    Size of array which we want. While it < size -> it*=2.
     */
    void change_arr_size(int new_size) {
        while (new_size <= size) new_size *= 2;

        T *temp = new T[new_size];
        for (int i = 0; i < arr_size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        arr_size = new_size;
    }

public:
    ArrayList() = default;

    /**
     * @brief
     * Constructor which generate some elements by functions and add to ArrayList.
     * @param   count       Count of elements we want to generate.
     * @param   create_func Function which generate new element by index.
     */
    ArrayList(int count, T(*create_func)(int)){
        for(int i = 0; i < count; i++){
            ArrayList::add(create_func(i));
        }
    }

    ~ArrayList() {
        delete[] arr;
    }

    /**
     * @brief
     * Add element to ArrayList.
     * @details
     * Adds an element and puts it in a certain position.
     * If the index is not specified or less than zero - adds an item to the end of the ArrayList.
     * If an item is not added to the end of the ArrayList, the item that belonged to that index(and all after it) moves forward.
     * @throw   std::out_of_range If index is bigger than size.
     * @param   obj     The element which we want to add to ArrayList.
     * @param   index   The index on which we want to place the element.
     */
    void add(T obj, int index = -1) override {
        if (index < 0)
            index = size;
        else if (index > size)
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");

        if (size == arr_size)
            change_arr_size(arr_size / 2 * 3 + 2);

        T temp1 = obj;
        T temp2;
        while (index <= size) {
            temp2 = arr[index];
            arr[index] = temp1;
            std::swap(temp1, temp2);
            index++;
        }
        size++;
    }

    /**
     * @brief
     * Remove element by index from ArrayList.
     * @details
     * If we remove element by index, all elements with bigger index moved:
     * index+1 -> index, index+2 -> index+1;
     * But:
     * index-1 -> index-1, index-2 -> index-2;
     * If index is less than 0, than index = size - 1 (remove last element in ArrayList).
     * @throw   std::out_of_range If index is bigger than size - 1.
     * @param   index   The index by which we want to delete the item.
     */
    void remove(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = size - 1;

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    /**
     * @brief
     * Get element by index from ArrayList.
     * @details
     * Method returns reference not an element.
     * If index is less than 0, than index = size - 1 (remove last element from the ArrayList).
     * If index is bigger or equals to the size, than method must throw std::out_of_range.
     * @param   index   The index of the element in the list we want to get.
     * @return          The element from ArrayList by index.
     */
    T &get(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = size - 1;

        return arr[index];
    }

    /**
     * @brief
     * Find the index of an element in the ArrayList.
     * @details
     * If the element is not contained in the list, method return -1.
     * If the list contains great than 1 such element, method return tne first index.
     * @param   obj     The element which index we want to know.
     * @return          The index of the element in the ArrayList or -1 if element is not contained.
     */
    int find(T obj) override {
        int res = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == obj) {
                res = i;
                break;
            }
        }
        return res;
    }

    /**
     * @brief
     * Remove all elements of the ArrayList.
     * Now size = 0;
     */
    void clear() override {
        delete[] arr;
        size = 0;
        arr_size = 16;
        arr = new T[arr_size];
    }

    /**
     * @brief
     * Method for sort the ArrayList.
     * @details
     * If the sort function is not specified or equals 'nullptr', the ArrayList must be sorted by quick sort function.
     * Method pass array to sort function.
     * ArrayList is sorted by default operators(>, <, ==, !=, >=, <=).
     * @param   sort_func   The function for sort which takes the array of elements from the list and size of the ArrayList.
     */
    void sort(void (*sort_func)(T *, int) = nullptr) {
        if (!sort_func)
            quick_sort(arr, size);
        else
            sort_func(arr, size);
    }

    /**
     * @brief
     * Override method for sort the ArrayList by compare function.
     * @details
     * If the compare function is not specified or equals 'nullptr', the ArrayList will be sorted by default operators(>, <, ==, !=, >=, <=).
     * Method pass array to sort function.
     * @param   sort_func       The function for sort which takes the array of elements in the list, size of the list and compare function.
     * @param   compare_func    The function which takes 2 elements and return: 1 -> if first is bigger, -1 -> if first is less, 0 -> else.
     */
    void sort(void (*sort_func)(T *, int, int(*)(T &obj1, T &obj2)),
              int(*compare_func)(T &obj1, T &obj2) = nullptr) override {
        sort_func(arr, size, compare_func);
    }

    /**
     * @brief
     * Static method for sort any other array
     * @details
     * Same to not static method but instead of a private array and size pass them as parameter.
     * @param   global_arr      Array we want to sort.
     * @param   global_size     Size of our array.
     * @param   sort_func       The function for sort which takes the array of elements in the list, size of the list and compare function.
     * @param   compare_func    The function which takes 2 elements and return: 1 -> if first is bigger, -1 -> if first is less, 0 -> else.
     */
    static void sort(T *global_arr, int global_size, void (*sort_func)(T *, int, int(*)(T &obj1, T &obj2)),
                     int(*compare_func)(T &obj1, T &obj2) = nullptr) {
        sort_func(global_arr, global_size, compare_func);
    }

    /**
     * @brief
     * Return the size of ArrayList.
     * @return  size of ArrayList.
     */
    int get_size() override {
        return size;
    }

    /**
     * @brief
     * Override operator<< of ostream.
     * Out look like:
     * @code
     * [T, T, T, T, T]
     * @endcode
     */
    friend std::ostream &operator<<(std::ostream &out, const ArrayList<T> &list) {
        out << '[';
        for (int i = 0; i < list.size - 1; i++) {
            out << list.arr[i] << ", ";
        }
        if (list.size != 0)
            out << list.arr[list.size - 1];

        out << "]";

        return out;
    }

    bool operator==(ArrayList &rhs) {
        if (get_size() != rhs.get_size()) return false;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) != rhs.get(i)) return false;
        }
        return true;
    }

    bool operator!=(ArrayList &rhs) {
        return !(rhs == *this);
    }

    bool operator<(ArrayList &rhs) {
        if (get_size() < rhs.get_size()) return true;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) < rhs.get(i)) return true;
        }
        return false;
    }

    bool operator>(ArrayList &rhs) {
        return rhs < *this;
    }

    bool operator<=(ArrayList &rhs) {
        return !(rhs < *this);
    }

    bool operator>=(ArrayList &rhs) {
        return !(*this < rhs);
    }
};


#endif
