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

    virtual void sort_by(void (*sort)(T *, int)) = 0;

    virtual int get_size() = 0;
};

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
            if(size == 0) index += 1;
            else index += size;
        }

        T temp1 = obj;
        T temp2;
        while (index <= size) {
            temp2 = arr[index];
            arr[index] = temp1;
            swap(temp1, temp2);
            index++;
        }
        size++;
    }

    void remove(int index) override {
        if (index > size) index = size;
        while (index < 0) {
            if(size == 0) index += 1;
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

    }

    int get_size() override {
        return size;
    }

    friend std::ostream& operator<< (std::ostream &out, const ArrayList<T> &list){
        cout << '[';
        for(int i = 0; i < list.size - 1; i++){
            cout << list.arr[i] << ", ";
        }
        cout << list.arr[list.size - 1] << ']';
    }
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
            if(size == 0) index += 1;
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
            if(size == 0) index += 1;
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

    void sort_by(void (*sort)(T *, int)) override {
        T *arr = new T[size];

        ass = head;
        for (int i = 0; i < size; i++) {
            arr[i] = ass->obj;
            ass = ass->next;
        }

        sort(arr, size);

        ass = head;
        for (int i = 0; i < size; i++) {
            ass->obj = arr[i];
            ass = ass->next;
        }
    }

    int get_size() override {
        return size;
    }

    friend std::ostream& operator<< (std::ostream &out, LinkedList<T> &list){
        cout << '[';
        list.ass = list.head;
        for(int i = 0; i < list.size - 1; i++){
            cout << list.ass->obj << ", ";
            list.ass = list.ass->next;
        }
        cout << list.ass->obj << ']';
    }
};

class Date{
private:
    int year;
    int month;
    int day;
public:
    Date(int year, int month, int day) : year(year), month(month), day(day) {}

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        this->year = year;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int month) {
        this->month = month;
    }

    int getDay() const {
        return day;
    }

    void setDay(int day) {
        this->day = day;
    }
};

class Book {
private:
    string name;
    //ArrayList<string> authors;
    //Date release;
    int pages;
    string annotation;

public:
    Book() {
        name = "noname";
        pages = 0;
        annotation = "nothing";
    }

    Book(string name, int pages, string annotation)
            : name(name), pages(pages), annotation(annotation) {

    }

    Book(Book *book) {
        this->name = book->name;
        this->pages = book->pages;
        this->annotation = book->annotation;
    }

    friend std::ostream& operator<< (std::ostream &out, const Book &book){
        cout << '{' << book.name << ", " << book.pages << ", " << book.annotation << '}';
    }

    friend bool operator== (Book &book1, Book &book2){
        if(book1.name == book2.name &&
            book1.pages == book2.pages &&
            book1.annotation == book2.annotation) return true;
        return false;
    }
};

int main() {
    LinkedList<Book> kek;
    kek.add(new Book("kek", 15, "huinya"));
    kek.add(new Book("kel", 15, "huinya"));
    kek.add(new Book("lol", 15, "huinya"));
    kek.remove(-1);
    cout << kek;


    return 0;
}
