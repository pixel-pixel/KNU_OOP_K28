#ifndef KNU_OOP_K28_LINKEDLIST_H
#define KNU_OOP_K28_LINKEDLIST_H

#include <iostream>
#include "List.h"

template<class T>
class LinkedList : List<T> {
private:
    class Node {
    public:
        T obj;
        Node *next = nullptr;

        Node(T &obj) {
            this->obj = obj;
        }

        ~Node(){
            delete next;
        }
    };

    int size = 0;
    Node *head = nullptr;
    Node *ass = nullptr;

    ~LinkedList(){
        ass = head->next;
        for(int i = 0; i < size; i++){
            delete head;
            head = ass;
            ass = ass->next;
        }

    }

public:
    void add(T obj) override {
        if (size == 0) {
            head = new Node(obj);
            ass = head;
        } else {
            ass->next = new Node(obj);
            ass = ass->next;
        }
        size++;
    }

    void add(T obj, int index) override {
        while (index < 0) {
            if (size == 0) index += 1;
            else index += size;
        }

        if (index == 0) {
            Node *n = new Node(obj);
            n->next = head;
            head = n;
        } else if (index >= size) {
            ass->next = new Node(obj);
            ass = ass->next;
        } else {
            Node *temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            Node *new_node = new Node(obj);
            new_node->next = temp->next;
            temp->next = new_node;
        }
        size++;
    }

    void remove(int index) override {
        if (index >= size) index = size - 1;
        while (index < 0) {
            if (size == 0) index += 1;
            else index += size;
        }

        if (index == 0) {
            head = head->next;
        } else {
            Node *temp = head;
            while (index != 1) {
                temp = head->next;
                index--;
            }
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        size--;
    }

    T &get(int index) override {
        if (index >= size) index = size - 1;
        while (index < 0) index += size;

        if (index == 0) {
            return head->obj;
        } else {
            Node *temp = head;
            while (index != 0) {
                temp = temp->next;
                index--;
            }
            return temp->obj;
        }
    }

    int find(T obj) override {
        int res = -1;

        Node *temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->obj == obj) {
                res = i;
                break;
            }
            temp = temp->next;
        }
        return res;
    }

    void clear() override {
        Node *temp = head;
        for (int i = 0; i < size; i++) {
            if (head->next != nullptr) temp = head->next;
            delete head;
            head = temp;
        }
        head = nullptr;
        size = 0;
    }

    void sort(void (*sort_func)(T *, int)){
        T *arr = new T[size];

        ass = head;
        for (int i = 0; i < size; i++) {
            arr[i] = ass->obj;
            ass = ass->next;
        }

        sort_func(arr, size);

        ass = head;
        for (int i = 0; i < size; i++) {
            ass->obj = arr[i];
            ass = ass->next;
        }
    }

    void sort(void (*sort_func)(T *, int, int(*)(T &obj1, T &obj2)),
              int(*compare_func)(T &obj1, T &obj2) = nullptr) override {
        T *arr = new T[size];

        ass = head;
        for (int i = 0; i < size; i++) {
            arr[i] = ass->obj;
            ass = ass->next;
        }

        sort_func(arr, size, compare_func);

        ass = head;
        for (int i = 0; i < size; i++) {
            ass->obj = arr[i];
            ass = ass->next;
        }
    }

    int get_size() override {
        return size;
    }

    friend std::ostream &operator<<(std::ostream &out, LinkedList<T> &list) {
        std::cout << '[';
        list.ass = list.head;
        for (int i = 0; i < list.size - 1; i++) {
            std::cout << list.ass->obj << ", ";
            list.ass = list.ass->next;
        }
        std::cout << list.ass->obj << ']';
    }
};


#endif
