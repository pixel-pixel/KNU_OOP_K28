#ifndef KNU_OOP_K28_BOOK_H
#define KNU_OOP_K28_BOOK_H

#include <string>
#include <iostream>
#include <vector>
#include "Date.h"

using namespace std;


class Book {
private:
    string name;
    vector<string> *authors;
    Date *release;
    int pages;
    string annotation;

public:
    Book() {
        name = "noname";
        authors = new vector<string>();
        release = new Date(0, 0, 0);
        pages = 0;
        annotation = "nothing";
    }

    Book(string name, vector<string> *authors, Date *release, int pages, string annotation){
        this->name = name;
        this->authors = authors;
        this->release = release;
        this->pages = pages;
        this->annotation = annotation;
    }

    Book(Book *book) {
        this->name = book->name;
        this->authors = book->authors;
        this->pages = book->pages;
        this->pages = book->pages;
        this->annotation = book->annotation;
    }

    const string &getName() const {
        return name;
    }

    int getPages() const {
        return pages;
    }

    const string &getAnnotation() const {
        return annotation;
    }

    friend std::ostream &operator<<(std::ostream &out, const Book &book) {
        cout << '{' << book.name << ", " << book.pages << ", " << book.annotation << '}';
    }
    friend bool operator==(Book &book1, Book &book2) {
        if (book1.name == book2.name &&
            *(book1.authors) == *(book2.authors) &&
            *(book1.release) == *(book2.release) &&
            book1.pages == book2.pages &&
            book1.annotation == book2.annotation)
            return true;
        return false;
    }

    friend bool operator>(Book &book1, Book &book2) {
        return book1.pages > book2.pages;
    }

    friend bool operator>=(Book &book1, Book &book2) {
        return book1.pages >= book2.pages;
    }

    friend bool operator<(Book &book1, Book &book2) {
        return book1.pages < book2.pages;
    }

    friend bool operator<=(Book &book1, Book &book2) {
        return book1.pages <= book2.pages;
    }
};


#endif
