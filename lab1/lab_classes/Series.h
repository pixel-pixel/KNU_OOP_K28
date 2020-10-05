#ifndef KNU_OOP_K28_SERIES_H
#define KNU_OOP_K28_SERIES_H

#include <ostream>
#include "Character.h"
#include "../lists/ArrayList.h"

/**
 * @brief
 * Class with one parameter vector which contains books from one series.
 */
class Series {
    Character *main_character = nullptr;    ///< Pointer on character for series.
    std::vector<Book> books;                ///< Vector with books from series.

public:
    /**
     * @brief
     * Constructor with main character if it != nullptr you can add all book to series.
     * If not - you can add only books where play this character.
     * @param   main_character  Pointer on character of series.
     */
    Series(Character *main_character = nullptr);

    /**
     * @brief
     * Add book to series.
     * If main 'main_character' == nullptr just add.
     * Else if main character contains this book - add, if not contains - no add.
     * @param   book    Link on book which we want to add.
     * @return          0 -> if add, -1 -> else.
     */
    int add_book(Book &book);

    /**
     * @brief
     * Remove book from series.
     * @param   book    Book which we want to remove.
     * @return          0 -> if remove, -1 -> if book not contains
     */
    int remove_book(Book &book);

    /**
     * @brief
     * Before method return vector, it sort all book by date.
     * @return  Vector of books of series.
     */
    std::vector<Book> &getBooks();

    /**
    * @brief
    * Override operator<< of ostream.
    * Out look like:
    * @code
    * {'book 1', 'book 2', ...}
    * @endcode
    */
    friend std::ostream &operator<<(std::ostream &os, Series &series);

    bool operator==(Series &rhs);

    bool operator!=(Series &rhs);

    bool operator<(Series &rhs);

    bool operator>(Series &rhs);

    bool operator<=(Series &rhs);

    bool operator>=(Series &rhs);
};

#endif
