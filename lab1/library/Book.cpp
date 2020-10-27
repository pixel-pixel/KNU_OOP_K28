#include "Book.h"

#include <utility>

/**
  * @brief
  * Constructor without parameters
  */
Book::Book() {
    Book::name = "";
    Book::pages = 0;
    Book::annotation = "";
    Book::date = "";
}

/**
 * Constructor which copy all from pointer on book to this book
 * @param   pBook   Pointer on book
 */
Book::Book(Book *pBook) {
    Book::name = pBook->name;
    Book::pages = pBook->pages;
    Book::annotation = pBook->annotation;
    Book::date = pBook->date;
    Book::authors = pBook->authors;
}

/**
 * @brief
 * Constructor with original to class`s members
 * @param   name        Name of book.
 * @param   pages       Count of pages in book.
 * @param   annotation  Short book`s annotation.
 * @param   date        Date of book`s release (yyyy.mm.dd).
 * @param   authors     Pointer on vector with authors.
 */
Book::Book(std::string name,
           int pages,
           std::string annotation,
           std::string date,
           std::vector<std::string> &authors) :
        name(std::move(name)),
        pages(pages),
        annotation(std::move(annotation)),
        date(std::move(date)),
        authors(authors) {}

/**
 * @brief
 * Simple constructor for compact create book.
 * @param   name        Name of book.
 * @param   pages       Count of pages in book.
 * @param   annotation  Short book`s annotation.
 * @param   author1     First author which will be added to 'authors'.
 * @param   author2     Second author which will be added to 'authors'.
 * @param   author3     Third author which will be added to 'authors'.
 */
Book::Book(std::string name,
           int pages,
           std::string annotation,
           std::string date,
           const std::string &author1,
           const std::string &author2,
           const std::string &author3) :
        name(std::move(name)),
        pages(pages),
        annotation(std::move(annotation)),
        date(std::move(date)) {
    if (!author1.empty())
        Book::authors.push_back(author1);
    if (!author2.empty())
        Book::authors.push_back(author2);
    if (!author3.empty())
        Book::authors.push_back(author3);
}

/**
 * @brief
 * Name getter.
 * @return  Name.
 */
const std::string &Book::getName() const {
    return name;
}

/**
 * @brief
 * Name setter.
 * @param   name    New name.
 */
void Book::setName(const std::string &name) {
    Book::name = name;
}

/**
 * @brief
 * Pages getter.
 * @return  Count of pages in book.
 */
int Book::getPages() const {
    return pages;
}

/**
 * @brief
 * Pages setter.
 * @param   pages   New count of pages in book.
 */
void Book::setPages(int pages) {
    Book::pages = pages;
}

/**
 * @brief
 * Annotation getter.
 * @return  String - annotation of book.
 */
const std::string &Book::getAnnotation() const {
    return annotation;
}

/**
 * @brief
 * Annotation setter.
 * @param   annotation  String - new annotation of book.
 */
void Book::setAnnotation(const std::string &annotation) {
    Book::annotation = annotation;
}

/**
 * Date getter.
 * @return  String - date of book`s release.
 */
const std::string &Book::getDate() const {
    return date;
}

/**
 * @brief
 * Date setter.
 * @param   date    String - new date book`s release (yyyy.mm.dd).
 */
void Book::setDate(const std::string &date) {
    Book::date = date;
}

/**
 * Authors` vector getter.
 * @return  Vector with strings - names of book`s authors.
 */
const std::vector<std::string> &Book::getAuthors() const {
    return authors;
}

/**
 * @brief
 * Authors` vector setter.
 * @param   authors Vector with strings - names of book`s authors.
 */
void Book::setAuthors(std::vector<std::string> &authors) {
    Book::authors = authors;
}

/**
 * @brief
 * Override operator<< of ostream.
 * Out look like:
 * @code
 * ("book name", 'count of pages', "annotation", "date", {"first author", "second author", ...})
 * @endcode
 */
std::ostream &operator<<(std::ostream &os, const Book &book) {
    os << '(';
    if (book.name.empty())
        os << "no name, ";
    else
        os << book.name << ", ";

    if (book.pages <= 0)
        os << "no pages, ";
    else
        os << book.pages << ", ";

    if (book.annotation.empty())
        os << "no annotation, ";
    else
        os << book.annotation << ", ";

    if (book.date.empty())
        os << "no date, ";
    else
        os << book.date << ", ";

    if (book.authors.size() != 0) {
        os << '{';
        for (int i = 0; i < book.authors.size() - 1; i++) {
            os << book.authors[i] << ' ';
        }
        os << book.authors[book.authors.size() - 1] << '}';
    } else {
        os << "no authors";
    }
    os << ')';
    return os;
}

/**
 * @brief
 * Equality operator.
 * @param   rhs Second Book.
 * @return      If all fields in book == fields in rhs -> true, else -> false.
 */
bool Book::operator==(const Book &rhs) const {
    return name == rhs.name &&
           pages == rhs.pages &&
           annotation == rhs.annotation &&
           date == rhs.date &&
           authors == rhs.authors;
}

/**
 * @brief
 * Inequality operator.
 * @param   rhs Second Book.
 * @return      If one or more fields in book != fields in rhs -> false, else -> true.
 */
bool Book::operator!=(const Book &rhs) const {
    return !(rhs == *this);
}

/**
 * @brief
 * Relation 'less that' operator.
 * Compare first by name, than by pages, then by annotation, then by date, then by authors` vector` size.
 * @param   rhs     Second Book.
 * @return          If book < rhs -> true, else -> false.
 */
bool Book::operator<(const Book &rhs) const {
    if (name < rhs.name)
        return true;
    if (rhs.name < name)
        return false;
    if (pages < rhs.pages)
        return true;
    if (rhs.pages < pages)
        return false;
    if (annotation < rhs.annotation)
        return true;
    if (rhs.annotation < annotation)
        return false;
    if (date < rhs.date)
        return true;
    if (rhs.date < date)
        return false;
    return authors.size() < rhs.authors.size();
}

/**
 * @brief
 * Relation 'great that' operator.
 * Compare first by name, than by pages, then by annotation, then by date, then by authors` vector` size.
 * @param   rhs     Second Book.
 * @return          rhs < *this.
 */
bool Book::operator>(const Book &rhs) const {
    return rhs < *this;
}

/**
 * @brief
 * Relation 'less or equal' operator.
 * Compare first by name, than by pages, then by annotation, then by date, then by authors` vector` size.
 * @param   rhs     Second Book.
 * @return          !(rhs < *this).
 */
bool Book::operator<=(const Book &rhs) const {
    return !(rhs < *this);
}

/**
 * @brief
 * Relation 'great or equal' operator.
 * Compare first by name, than by pages, then by annotation, then by date, then by authors` vector` size.
 * @param   rhs     Second Book.
 * @return          !(rhs > *this).
 */
bool Book::operator>=(const Book &rhs) const {
    return !(*this < rhs);
}