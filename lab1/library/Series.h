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
private:
    Character *main_character = nullptr;    ///< Pointer on character for series.
    std::vector<Book> *books;                ///< Vector with books from series.

public:
    Series();

    Series(Series *pSeries);

    /**
     * @brief
     * Constructor with main character if it != nullptr you can add all book to series.
     * If not - you can add only books where play this character.
     */
    Series(Character *main_character);

    /**
     * @brief
     * Add book to series.
     */
    int add_book(Book &book);

    /**
     * @brief
     * Remove book from series.
     */
    int remove_book(Book &book);

    /**
     * @brief
     * Before method return vector, it sort all book by date.
     */
    std::vector<Book> *getBooks();

    /**
     * @brief
     * Character getter.
     */
    Character *getMainCharacter();

    /**
    * @brief
    * Override operator<< of ostream.
    */
    friend std::ostream &operator<<(std::ostream &os, const Series &series);

    /**
     * @brief
     * Equal operator.
     */
    bool operator==(const Series &rhs) const;

    /**
     * @brief
     * Not equal operator.
     */
    bool operator!=(const Series &rhs) const;

    /**
     * @brief
     * Less than operator.
     */
    bool operator<(const Series &rhs) const;

    /**
    * @brief
    * Great than operator.
    */
    bool operator>(const Series &rhs) const;

    /**
     * @brief
     * Less or equal operator.
     */
    bool operator<=(const Series &rhs) const;

    /**
     * @brief
     * Great or equal operator.
     */
    bool operator>=(const Series &rhs) const;
};

#endif
