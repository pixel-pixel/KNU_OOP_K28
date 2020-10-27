#ifndef KNU_OOP_K28_BOOK_H
#define KNU_OOP_K28_BOOK_H

#include <vector>
#include <string>
#include <ostream>

/**
 * @brief
 * Class Book contain:
 * std::string name,
 * int pages,
 * std::string annotation,
 * std::string date,
 * std::vector<std::string> authors.
 */
class Book {
private:
    std::string name;                   ///< Name of book.
    int pages;                          ///< Count of pages in book.
    std::string annotation;             ///< Short book`s annotation.
    std::string date;                   ///< Date of book`s release (yyyy.mm.dd).
    std::vector<std::string> authors;  ///< Vector with authors.

public:
    /**
     * @brief
     * Constructor without parameters
     */
    Book();

    /**
     * Constructor which copy all from pointer on book to this book
     */
    Book(Book *pBook);

    /**
     * @brief
     * Constructor with original to class`s members
     */
    Book(std::string name,
         int pages,
         std::string annotation,
         std::string date,
         std::vector<std::string> &authors);

    /**
     * @brief
     * Simple constructor for compact create book.
     */
    Book(std::string name,
         int pages = 0,
         std::string annotation = "",
         std::string date = "",
         const std::string &author1 = "",
         const std::string &author2 = "",
         const std::string &author3 = "");

    /**
     * @brief
     * Name getter.
     */
    const std::string &getName() const;

    /**
     * @brief
     * Name setter.
     */
    void setName(const std::string &name);

    /**
     * @brief
     * Pages getter.
     */
    int getPages() const;

    /**
     * @brief
     * Pages setter.
     */
    void setPages(int pages);

    /**
     * @brief
     * Annotation getter.
     */
    const std::string &getAnnotation() const;

    /**
     * @brief
     * Annotation setter.
     */
    void setAnnotation(const std::string &annotation);

    /**
     * Date getter.
     */
    const std::string &getDate() const;

    /**
     * @brief
     * Date setter.
     */
    void setDate(const std::string &date);

    /**
     * Authors` vector getter.
     */
    const std::vector<std::string> &getAuthors() const;

    /**
     * @brief
     * Authors` vector setter.
     */
    void setAuthors(std::vector<std::string> &authors);

    /**
    * @brief
    * Override operator<< of ostream.
    */
    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    /**
     * @brief
     * Equality operator.
     */
    bool operator==(const Book &rhs) const;

    /**
     * @brief
     * Inequality operator.
     */
    bool operator!=(const Book &rhs) const;

    /**
     * @brief
     * Relation 'less that' operator.
     */
    bool operator<(const Book &rhs) const;

    /**
     * @brief
     * Relation 'great that' operator.
     */
    bool operator>(const Book &rhs) const;

    /**
     * @brief
     * Relation 'less or equal' operator.
     */
    bool operator<=(const Book &rhs) const;

    /**
     * @brief
     * Relation 'great or equal' operator.
     */
    bool operator>=(const Book &rhs) const;
};


#endif
