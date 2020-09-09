#include <iostream>
#include <string>

using namespace std;

template<class T>
class List {
public:
    virtual void add(T obj) = 0;

    virtual void add(T obj, int index) = 0;

    virtual void remove(int index) = 0;

    virtual T &get(int index) = 0;

    virtual int find(T obj) = 0;

    virtual void clear() = 0;

    virtual void sort_by(void (*sort)(T*, int)) = 0;

    virtual int get_size() = 0;
};

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
    };

    int size = 0;
    Node *head = nullptr;
    Node *ass = nullptr;

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
            index = size + index + 1;
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
        if(index >= size) index = size - 1;
        while (index < 0) index += size;

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
            while (index != 0){
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

    void sort_by(void (*sort)(T*, int)) override {
        T* arr = new T[size];

        ass = head;
        for(int i = 0; i < size; i++){
            arr[i] = ass->obj;
            ass = ass->next;
        }

        sort(arr, size);

        ass = head;
        for(int i = 0; i < size; i++){
            ass->obj = arr[i];
            ass = ass->next;
        }
    }

    int get_size() override {
        return size;
    }

    void print() {
        if (size != 0) {
            ass = head;
            while (ass->next != nullptr) {
                cout << ass->obj << endl;
                ass = ass->next;
            }
            cout << ass->obj << endl;
        } else {
            cout << "Empty" << endl;
        }
    }
};

int main() {
    LinkedList<string> kek;
    int n = 7;
    kek.add("aaa");
    kek.add("bbb");
    kek.add("ccc", 1);
    kek.print();


    return 0;
}
