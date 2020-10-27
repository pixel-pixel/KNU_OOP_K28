#include "Series.h"
#include "../lists/VectorList.h"
#include "../comparators/BookByDateComparator.h"

/**
 * Constructor which copy all from pointer on Series to this Series
 * @param   pSeries   Pointer on Series
 */
Series::Series(Series *pSeries) {
    Series::main_character = pSeries->main_character;
    Series::books = pSeries->books;
}

/**
 * @brief
 * Constructor with main character if it != nullptr you can add all book to series.
 * If not - you can add only books where play this character.
 * @param   main_character  Pointer on character of series.
 */
Series::Series(Character &main_character) {
    Series::main_character = main_character;
}

/**
 * @brief
 * Add book to series.
 * If main 'main_character' == nullptr just add.
 * Else if main character contains this book - add, if not contains - no add.
 * @param   book    Link on book which we want to add.
 * @return          0 -> if add, -1 -> else.
 */
int Series::add_book(Book &book) {
    if (!Series::main_character.getNames().empty()) {
        for (int i = 0; i < Series::main_character.getRoles().size(); i++) {
            if (Series::main_character.getRoles()[i].getBook() == book) {
                books.push_back(book);
                break;
            }
        }
        return -1;
    } else {
        books.push_back(book);
    }
    return 0;
}

/**
 * @brief
 * Remove book from series.
 * @param   book    Book which we want to remove.
 * @return          0 -> if remove, -1 -> if book not contains
 */
int Series::remove_book(Book &book) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i] == book) {
            books.erase(books.begin() + i);
            return 0;
        }
    }
    return -1;
}

/**
 * @brief
 * Character getter.
 * @return  Character.
 */
Character &Series::getMainCharacter() {
    return main_character;
}

/**
 * @brief
 * Before method return vector, it sort all book by date.
 * @return  Vector of books of series.
 */
std::vector<Book> &Series::getBooks() {
    VectorList<Book>::sort(books, new QuickSort<Book>, new BookByDateComparator);
    return books;
}

/**
 * @brief
 * Override operator<< of ostream.
 * Out look like:
 * @code
 * {'book 1', 'book 2', ...}
 * @endcode
 */
std::ostream &operator<<(std::ostream &os, const Series &series) {
    QuickSort<Book> sort;
    BookByDateComparator comparator;

    VectorList<Book>::sort(series.books, &sort, &comparator);
    os << '{';
    if (!series.books.empty()) {
        for (int i = 0; i < series.books.size() - 1; i++) {
            os << series.books[i] << ", ";
        }
        os << series.books.at(series.books.size() - 1);
    }
    os << '}';

    return os;
}

/**
 * @brief
 * Equal operator.
 * @param   rhs     Second Series.
 * @return          If mainCharacter and books equals -> true.
 */
bool Series::operator==(const Series &rhs) const {
    return books == rhs.books;
}

/**
 * @brief
 * Not equal operator.
 * @param   rhs     Second Series.
 * @return          If mainCharacter and books equals -> false.
 */
bool Series::operator!=(const Series &rhs) const {
    return !(rhs == *this);
}

/**
 * @brief
 * Less than operator
 * @param   rhs     Second Series.
 * @return          If *books < *rhs.books -> true.
 */
bool Series::operator<(const Series &rhs) const {
    return books.size() < rhs.books.size();
}

/**
 * @brief
 * Great than operator
 * @param   rhs     Second Series.
 * @return          If *books < *rhs.books -> false.
 */
bool Series::operator>(const Series &rhs) const {
    return rhs < *this;
}

/**
 * @brief
 * Less or equal operator
 * @param   rhs     Second Series.
 * @return          If *books < *rhs.books || If *books == *rhs.books -> true.
 */
bool Series::operator<=(const Series &rhs) const {
    return !(rhs < *this);
}

/**
 * @brief
 * Great or equal operator
 * @param   rhs     Second Series.
 * @return          If *books < *rhs.books || If *books == *rhs.books -> false.
 */
bool Series::operator>=(const Series &rhs) const {
    return !(*this < rhs);
}


