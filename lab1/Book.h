#ifndef KNU_OOP_K28_BOOK_H
#define KNU_OOP_K28_BOOK_H

#include <string>
#include <iostream>

using namespace std;


class Book {
private:
    string name;
    //ArrayList<string> authors;
    //Date release = Date(nullptr);
    int pages;
    string annotation;

public:
    Book() {
        name = "noname";
        //release = new Date(0, 0, 0);
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

    friend std::ostream &operator<<(std::ostream &out, const Book &book) {
        cout << '{' << book.name << ", " << book.pages << ", " << book.annotation << '}';
    }

    friend bool operator==(Book &book1, Book &book2) {
        if (book1.name == book2.name &&
            book1.pages == book2.pages &&
            book1.annotation == book2.annotation)
            return true;
        return false;
    }
};


#endif //KNU_OOP_K28_BOOK_H