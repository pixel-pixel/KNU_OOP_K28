#ifndef KNU_OOP_K28_BOOK_H
#define KNU_OOP_K28_BOOK_H

#include <string>
#include <iostream>
#include <vector>

#include "Date.h"

using namespace std;


class Book {
    string name;
    int pages;
    string annotation;
    Date *pRelease;
    vector<string> *pAuthors;

public:
    Book(string name = "noname",
         int pages = 0,
         string annotation = "without annotation",
         Date *release = new Date(),
         vector<string> *authors = new vector<string>) {
        this->name = name;
        this->pages = pages;
        this->annotation = annotation;
        this->pRelease = release;
        this->pAuthors = authors;
    }

    Book(Book *book) {
        this->name = book->name;
        this->pAuthors = book->pAuthors;
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
            *(book1.pAuthors) == *(book2.pAuthors) &&
            *(book1.pRelease) == *(book2.pRelease) &&
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
