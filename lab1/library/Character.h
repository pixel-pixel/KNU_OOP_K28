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
        Book book;     ///< Pointer on book where is character.
        Part part;      ///< Part of character in book;

    public:
        /**
         * Constructor with all parameters.
         */
        Role(Book book, Part part);

        /**
         * @brief
         * Book getter.
         */
        Book &getBook();

        /**
         * @brief
         * Book setter.
         */
        void setBook(Book &book);

        /**
         * @brief
         * Part getter.
         */
        Part getPart();

        /**
         * @brief
         * Part setter.
         */
        void setPart(Part part);

        /**
        * @brief
        * Override operator<< of ostream.
        */
        friend std::ostream &operator<<(std::ostream &os, const Role &role);

        /**
         * @brief
         * Equal operator.
         */
        bool operator==(const Role &rhs) const;

        /**
         * @brief
         * Unequal operator.
         */
        bool operator!=(const Role &rhs) const;

        /**
         * Less than operator.
         */
        bool operator<(const Role &rhs) const;

        /**
         * Great than operator.
         */
        bool operator>(const Role &rhs) const;

        /**
         * Less or equal operator.
         */
        bool operator<=(const Role &rhs) const;

        /**
         * Great or equal operator.
         */
        bool operator>=(const Role &rhs) const;
    };

private:
    std::vector<std::string> names;    ///< Pointer on vector where all names of this character.
    std::vector<Role> roles;           ///< Pointer on vector where all roles of this character.

public:
    /**
     * @brief
     * Constructor without parameters
     */
    Character() = default;
    /**
     * Constructor which copy all from pointer on Character to this Character
     * @param   pCharacter   Pointer on Character
     */
    Character(Character *pCharacter);

    /**
     * @brief
     * Constructor with original to class`s members
     * @param   names   Pointer on vector where all names of this character.
     * @param   roles   Pointer on vector where all roles of this character.
     */
    Character(std::vector<std::string> &names, std::vector<Role> &roles);

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

    /**
     * Names` vector getter.
     */
    std::vector<std::string> &getNames();

    /**
     * Names` vector setter.
     */
    void setNames(std::vector<std::string> &names);

    /**
     * Roles` vector getter.
     */
    std::vector<Role> &getRoles();

    /**
     * Roles` vector setter.
     */
    void setRoles(std::vector<Role> &roles);

    /**
     * @brief
     * Override operator<< of ostream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Character &character);

    /**
     * Equal operator.
     */
    bool operator==(const Character &rhs) const;

    /**
     * Unequal operator.
     */
    bool operator!=(const Character &rhs) const;

    /**
     * Less than operator.
     */
    bool operator<(const Character &rhs) const;

    /**
     * Great than operator.
     */
    bool operator>(const Character &rhs) const;

    /**
     * Less or equal operator.
     */
    bool operator<=(const Character &rhs) const;

    /**
     * Great or equal operator.
     */
    bool operator>=(const Character &rhs) const;
};


#endif
