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

    virtual void sort_by() = 0;
};

template <class T>
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
//TODO зробити якщо index > size або index < 0
    void remove(int index) override {
        if(index == 0){
            head = head->next;
        }else{
            Node* temp = head;
            while (index != 1){
                temp = head->next;
                index--;
            }
            Node* temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        size--;
    }
    //TODO доробить
    T &get(int index) override {
        if(index == 0){
            return head->obj;
        }else{

        }
    }

    int find(T obj) override {
        int res = -1;

        Node* temp = head;
        for(int i = 0; i < size; i++){
            if(temp->obj == obj){
                res = i;
                break;
            }
            temp = temp->next;
        }
        return res;
    }

    void clear() override {
        Node* temp = head;
        for(int i = 0; i < size; i++){
            if(head->next != nullptr) temp = head->next;
            delete head;
            head = temp;
        }
        head = nullptr;
        size = 0;
    }

    void sort_by() override {

    }

    void print(){
        if(size != 0){
            ass = head;
            while (ass->next != nullptr) {
                cout << ass->obj << endl;
                ass = ass->next;
            }
            cout << ass->obj << endl;
        }else {
            cout << "Empty" << endl;
        }
    }
};

int main() {
    LinkedList<int> kek;
    int n = 7;
    kek.add(n);
    kek.add(3);
    kek.add(24, 1);
    kek.clear();
    kek.print();


    return 0;
}
