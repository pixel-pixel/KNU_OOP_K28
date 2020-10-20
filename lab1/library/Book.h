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
 * std::vector<std::string> *authors.
 */
class Book {
private:
    std::string name;                   ///< Name of book.
    int pages;                          ///< Count of pages in book.
    std::string annotation;             ///< Short book`s annotation.
    std::string date;                   ///< Date of book`s release (yyyy.mm.dd).
    std::vector<std::string> *authors;  ///< Pointer on vector with authors.

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
         std::vector<std::string> *authors);

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
     * @return  Name.
     */
    const std::string &getName() const;

    /**
     * @brief
     * Name setter.
     * @param   name    New name.
     */
    void setName(const std::string &name);

    int getPages() const;

    void setPages(int pages);

    const std::string &getAnnotation() const;

    void setAnnotation(const std::string &annotation);

    const std::string &getDate() const;

    void setDate(const std::string &date);

    const std::vector<std::string> &getAuthors() const;

    void setAuthors(std::vector<std::string> *authors);

    /**
    * @brief
    * Override operator<< of ostream.
    * Out look like:
    * @code
    * ("book name", 'count of pages', "annotation", "date", {"first author", "second author", ...})
    * @endcode
    */
    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    bool operator==(const Book &rhs) const;

    bool operator!=(const Book &rhs) const;

    bool operator<(const Book &rhs) const;

    bool operator>(const Book &rhs) const;

    bool operator<=(const Book &rhs) const;

    bool operator>=(const Book &rhs) const;
};


#endif
