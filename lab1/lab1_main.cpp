#include <iostream>
#include <string>

using namespace std;

class Date {
    int year;
};

template<class T>
class List {
private:
    class Node {
    public:
        T obj;
        Node *next;

        Node(T obj) {
            this->obj = obj;
        }
    };

    int size = 0;
    Node *head = nullptr;
    Node *ass = nullptr;
public:
    void add(T obj) {
        if (size == 0) {
            head = new Node(obj);
            ass = head;
        } else {
            ass->next = new Node(obj);
            ass = ass->next;
        }
        size++;
    }

    void add_at(T obj, int index){
        while (index < 0){
            index = size + index + 1;
        }

        if(index == 0){
            Node* n = new Node(obj);
            n->next = head;
            head = n;
        }else if(index >= size){
            ass->next = new Node(obj);
            ass = ass->next;
        }else{
            Node* temp = head;
            for(int i = 1; i < index; i++){
                temp = temp->next;
            }
            Node* new_node = new Node(obj);
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    T get(int index){
        Node* temp = head;
        for(int i = 1; i < index; i++){
            temp = temp->next;
        }
    }

    void print(){
        ass = head;
        while (ass->next != nullptr){
            cout << ass->obj << endl;
            ass = ass->next;
        }
        cout << ass->obj << endl;
    }

};

int main() {
    List<int> kek;
    kek.add(0);
    kek.add(1);
    kek.add(2);
    kek.add(3);
    kek.add(4);
    kek.add_at(5, -12);
    kek.add(6);
    kek.print();


    return 0;
}
