#ifndef KNU_OOP_K28_VECTORLIST_H
#define KNU_OOP_K28_VECTORLIST_H

#include "List.h"
#include <vector>
#include <iostream>

template<class T>
class VectorList : List<T> {
    std::vector<T> vect;

public:
    ~VectorList(){
        clear();
    }

    void add(T obj, int index = NAN) override {
        if(index == NAN)
            index = vect.size();

        while (index < 0) {
            if (vect.size() == 0) index += 1;
            else index += vect.size();
        }

        if (index == vect.size()) vect.push_back(obj);
        else if(index < vect.size()) vect.insert(vect.begin() + index, obj);
        else throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");
    }

    void remove(int index) override {
        if (index >= vect.size()) index = vect.size() - 1;
        while (index < 0) {
            if (vect.size() == 0) index += 1;
            else index += vect.size();
        }

        vect.erase(vect.begin() + index);
    }

    T &get(int index) override {
        if (index >= vect.size()) index = vect.size() - 1;
        while (index < 0) index += vect.size();

        return vect.at(index);
    }

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

    void clear() override {
        vect.clear();
    }

    void sort(void (*sort_func)(T *, int)){
        sort_func(&vect[0], vect.size());
    }

    void sort(void (*sort_func)(T *, int, int (*)(T &, T &)), int (*compare_func)(T &, T &) = nullptr) override {
        sort_func(&vect[0], vect.size(), compare_func);
    }

    int get_size() override {
        return vect.size();
    }

    friend std::ostream &operator<<(std::ostream &out, VectorList<T> &list) {
        out << '[';
        for (int i = 0; i < list.get_size() - 1; i++) {
            out << list.get(i) << ", ";
        }
        out << list.get(list.get_size() - 1) << ']';
    }

};


#endif
