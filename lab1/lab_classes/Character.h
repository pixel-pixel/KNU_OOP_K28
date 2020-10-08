#ifndef KNU_OOP_K28_CHARACTER_H
#define KNU_OOP_K28_CHARACTER_H

#include <ostream>
#include "Book.h"

/**
 *@brief
 * Class which contains all names of character and all roles(book + part in this book).
 */
class Character {
public:
    /**
     * @brief
     * Inner class for saving books where character play with part which character play in book to vector 'roles'.
     */
    class Role {
    public:
        /**
         * @brief
         * Part - what part person/character plays in book.
         */
        enum Part {
            MAIN,       ///< Generous person. Story about him.
            MINOR,      ///< Secondary person. A significant part of story about him.
            EPISODIC,   ///< Cameo person. He can be skipped.
            NONE        ///< This person not in this book.
        };
    private:
        Book *book;     ///< Pointer on book where is character.
        Part part;      ///< Part of character in book;

    public:
        /**
         * Constructor with all parameters.
         * @param   book    Pointer on book where play character.
         * @param   part    Part which plays character in book.
         */
        Role(Book *book, Part part);

        Book &getBook();

        void setBook(Book *book);

        Part getPart();

        void setPart(Part part);

        bool operator<(const Role &rhs) const;

        bool operator>(const Role &rhs) const;

        bool operator<=(const Role &rhs) const;

        bool operator>=(const Role &rhs) const;

        bool operator==(const Role &rhs) const;

        bool operator!=(const Role &rhs) const;

        /**
        * @brief
        * Override operator<< of ostream.
        * Out look like:
        * @code
        * {'book', 'role'}
        * @endcode
        */
        friend std::ostream &operator<<(std::ostream &os, const Role &role);
    };

private:
    std::vector<std::string> *names;    ///< Pointer on vector where all names of this character.
    std::vector<Role> *roles;           ///< Pointer on vector where all roles of this character.

public:
    Character();

    Character(Character *pCharacter);

    /**
     * @brief
     * Constructor with original to class`s members
     * @param   names   Pointer on vector where all names of this character.
     * @param   roles   Pointer on vector where all roles of this character.
     */
    Character(std::vector<std::string> *names, std::vector<Role> *roles);

    /**
     * @brief
     * Simple constructor for compact create character.
     * @param   name1   First name which will be added to 'names'.
     * @param   name2   Second name which will be added to 'names'.
     * @param   name3   Third name which will be added to 'names'.
     */
    Character(const std::string &name1, const std::string &name2 = "", const std::string &name3 = "");

    /**
     * @brief
     * Add one more name to vector 'names'.
     * @param   name    One more name.
     */
    void add_name(const std::string &name);

    /**
     * @brief
     * Add one more role to vector 'roles'.
     * @param   role    One more role.
     */
    void add_role(Role role);

    std::vector<std::string> *getNames() const;

    void setNames(std::vector<std::string> *names);

    std::vector<Role> *getRoles() const;

    void setRoles(std::vector<Role> *roles);

    /**
     * @brief
     * Override operator<< of ostream.
     * Out look like:
     * @code
     * {{'name 1', 'name 2', ...}, {'role 1', 'role 2', ...}}
     * @endcode
     */
    friend std::ostream &operator<<(std::ostream &os, const Character &character);

    bool operator==(const Character &rhs) const;

    bool operator!=(const Character &rhs) const;

    bool operator<(const Character &rhs) const;

    bool operator>(const Character &rhs) const;

    bool operator<=(const Character &rhs) const;

    bool operator>=(const Character &rhs) const;
};


#endif
