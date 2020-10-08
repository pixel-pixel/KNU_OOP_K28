#include "Series.h"
#include "../lists/VectorList.h"
#include "../comparators/BookByDateComparator.h"

Series::Series() {
    Series::main_character = nullptr;
    Series::books = new std::vector<Book>;
}

Series::Series(Series *pSeries) {
    Series::main_character = pSeries->main_character;
    Series::books = pSeries->books;
}

Series::Series(Character *main_character) {
    Series::main_character = main_character;
    Series::books = new std::vector<Book>;
}

int Series::add_book(Book &book) {
    if(Series::main_character != nullptr){
        for(int i = 0; i < Series::main_character->getRoles()->size(); i++){
            if(Series::main_character->getRoles()->operator[](i).getBook() == book){
                books->push_back(book);
                break;
            }
        }
        return -1;
    } else{
        books->push_back(book);
    }
    return 0;
}

int Series::remove_book(Book &book) {
    for (int i = 0; i < books->size(); i++) {
        if (books->operator[](i) == book){
            books->erase(books->begin() + i);
            return 0;
        }
    }
    return -1;
}

Character *Series::getMainCharacter() {
    return main_character;
}


std::vector<Book> *Series::getBooks() {
    VectorList<Book>::sort(*books, new QuickSort<Book>, new BookByDateComparator);
    return books;
}

std::ostream &operator<<(std::ostream &os, const Series &series) {
    VectorList<Book>::sort(*series.books, new QuickSort<Book>, new BookByDateComparator);
    os << '{';
    if (!series.books->empty()) {
        for (int i = 0; i < series.books->size() - 1; i++) {
            os << series.books->operator[](i) << ", ";
        }
        os << series.books->at(series.books->size() - 1);
    }
    os << '}';

    return os;
}

bool Series::operator==(const Series &rhs) const {
    return *books == *rhs.books;
}

bool Series::operator!=(const Series &rhs) const{
    return !(rhs == *this);
}

bool Series::operator<(const Series &rhs) const{
    return books < rhs.books;
}

bool Series::operator>(const Series &rhs) const{
    return rhs < *this;
}

bool Series::operator<=(const Series &rhs) const{
    return !(rhs < *this);
}

bool Series::operator>=(const Series &rhs) const{
    return !(*this < rhs);
}


