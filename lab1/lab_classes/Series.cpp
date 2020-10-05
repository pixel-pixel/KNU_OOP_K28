#include "Series.h"
#include "../lists/VectorList.h"
#include "../sorts/sorts.h"
#include "../compare_functions/compare.h"

Series::Series(Character *main_character) {
    Series::main_character = main_character;
}

int Series::add_book(Book &book) {
    if(Series::main_character){
        for(int i = 0; i < Series::main_character->getRoles()->size(); i++){
            if(Series::main_character->getRoles()->operator[](i).getBook() == book){
                books.push_back(book);
                break;
            }
        }
        return -1;
    } else{
        books.push_back(book);
    }
    return 0;
}

int Series::remove_book(Book &book) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i] == book){
            books.erase(books.begin() + i);
            return 0;
        };
    }
    return -1;
}


std::vector<Book> &Series::getBooks() {
    VectorList<Book>::sort(books, quick_sort, compare_book_by_date);
    return books;
}

std::ostream &operator<<(std::ostream &os, Series &series) {
    VectorList<Book>::sort(series.getBooks(), quick_sort);
    os << '{';
    if (!series.getBooks().empty()) {
        for (int i = 0; i < series.getBooks().size() - 1; i++) {
            os << series.getBooks()[i] << ", ";
        }
        os << series.getBooks().at(series.getBooks().size() - 1);
    }
    os << '}';

    return os;
}

bool Series::operator==(Series &rhs) {
    return books == rhs.getBooks();
}

bool Series::operator!=(Series &rhs) {
    return !(rhs == *this);
}

bool Series::operator<(Series &rhs) {
    return books < rhs.books;
}

bool Series::operator>(Series &rhs) {
    return rhs < *this;
}

bool Series::operator<=(Series &rhs) {
    return !(rhs < *this);
}

bool Series::operator>=(Series &rhs) {
    return !(*this < rhs);
}


