#ifndef KNU_OOP_K28_ARRAYLIST_H
#define KNU_OOP_K28_ARRAYLIST_H

#include <iostream>
#include "List.h"

template<class T>
class ArrayList : List<T> {
private:
    int size = 0;
    int arr_size = 2;
    T *arr = new T[16];

    void change_arr_size(int new_size) {
        if (new_size <= size) new_size *= 2;

        T *temp = new T[new_size];
        for (int i = 0; i < arr_size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        arr_size = new_size;
    }

public:
    void add(T obj) override {
        if (size == arr_size)
            change_arr_size(arr_size / 2 * 3 + 2);

        arr[size] = obj;
        size++;
    }

    void add(T obj, int index) override {
        if (size == arr_size)
            change_arr_size(arr_size / 2 * 3 + 2);

        if (index > size) index = size;
        while (index < 0) {
            if (size == 0) index += 1;
            else index += size;
        }

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

    void remove(int index) override {
        if (index > size) index = size;
        while (index < 0) {
            if (size == 0) index += 1;
            else index += size;
        }

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    T &get(int index) override {
        if (index >= size) index = size - 1;
        while (index < 0) index += size;
        return arr[index];
    }

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

    void clear() override {
        delete[] arr;
        size = 0;
        arr_size = 16;
        arr = new T[arr_size];
    }

    void sort_by(void (*sort)(T *, int)) override {
        sort(arr, size);
    }

    int get_size() override {
        return size;
    }

    friend std::ostream &operator<<(std::ostream &out, const ArrayList<T> &list) {
        std::cout << '[';
        for (int i = 0; i < list.size - 1; i++) {
            std::cout << list.arr[i] << ", ";
        }
        std::cout << list.arr[list.size - 1] << ']';
    }
};


#endif //KNU_OOP_K28_ARRAYLIST_H
