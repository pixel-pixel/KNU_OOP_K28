#include "Character.h"
/**
 * Constructor with all parameters.
 * @param   book    Pointer on book where play character.
 * @param   part    Part which plays character in book.
 */
Character::Role::Role(Book book, Character::Role::Part part) : book(book), part(part) {}

/**
 * @brief
 * Book getter.
 * @return  Book from role.
 */
Book &Character::Role::getBook() {
    return book;
}

/**
 * @brief
 * Book setter.
 * @param   book    New book from.
 */
void Character::Role::setBook(Book &book) {
    Role::book = book;
}

/**
 * @brief
 * Part getter.
 * @return  Enum - part of Character in Book.
 */
Character::Role::Part Character::Role::getPart() {
    return part;
}

/**
 * @brief
 * Part setter.
 * @param part
 */
void Character::Role::setPart(Character::Role::Part part) {
    Role::part = part;
}

/**
 * @brief
 * Override operator<< of ostream.
 * Out look like:
 * @code
 * {'book', 'role'}
 * @endcode
 */
std::ostream &operator<<(std::ostream &os, const Character::Role &role) {
    os << "{" << role.book << ", " << role.part << '}';
    return os;
}

/**
 * @brief
 * Equal operator.
 * @param   rhs Second Role.
 * @return      If all fields in Role equal to rhs` fields -> true, else -> false.
 */
bool Character::Role::operator==(const Character::Role &rhs) const {
    return book == rhs.book &&
           part == rhs.part;
}

/**
 * @brief
 * Unequal operator.
 * @param   rhs Second Role.
 * @return      If one or more fields in Role unequal to rhs` fields -> false, else -> true.
 */
bool Character::Role::operator!=(const Character::Role &rhs) const {
    return !(rhs == *this);
}

/**
 * Less than operator.
 * Compare first by book, than by part.
 * @param   rhs Second Role.
 * @return      If *this < rhs -> true, else -> false.
 */
bool Character::Role::operator<(const Character::Role &rhs) const {
    if (book < rhs.book)
        return true;
    if (rhs.book < book)
        return false;
    return part < rhs.part;
}

/**
 * Great than operator.
 * Compare first by book, than by part.
 * @param   rhs Second Role.
 * @return      rhs < *this.
 */
bool Character::Role::operator>(const Character::Role &rhs) const {
    return rhs < *this;
}

/**
 * Less or equal operator.
 * Compare first by book, than by part.
 * @param   rhs Second Role.
 * @return      !(rhs < *this).
 */
bool Character::Role::operator<=(const Character::Role &rhs) const {
    return !(rhs < *this);
}

/**
 * Great or equal operator.
 * Compare first by book, than by part.
 * @param   rhs Second Role.
 * @return      !(rhs > *this).
  */
bool Character::Role::operator>=(const Character::Role &rhs) const {
    return !(*this < rhs);
}

/**
 * Constructor which copy all from pointer on Character to this Character
 * @param   pCharacter   Pointer on Character
 */
Character::Character(Character *pCharacter) {
    Character::names = pCharacter->names;
    Character::roles = pCharacter->roles;
}

/**
 * @brief
 * Constructor with original to class`s members
 * @param   names   Pointer on vector where all names of this character.
 * @param   roles   Pointer on vector where all roles of this character.
 */
Character::Character(std::vector<std::string> &names,
                     std::vector<Role> &roles) :
        names(names), roles(roles) {}

/**
 * @brief
 * Simple constructor for compact create character.
 * @param   name1   First name which will be added to 'names'.
 * @param   name2   Second name which will be added to 'names'.
 * @param   name3   Third name which will be added to 'names'.
 */
Character::Character(const std::string &name1,
                     const std::string &name2,
                     const std::string &name3) {

    if(!name1.empty())
        names.push_back(name1);
    if (!name2.empty())
        names.push_back(name2);
    if (!name3.empty())
        names.push_back(name3);
}

/**
 * @brief
 * Add one more name to vector 'names'.
 * @param   name    One more name.
 */
void Character::add_name(const std::string &name) {
    Character::names.push_back(name);
}

/**
 * @brief
 * Add one more role to vector 'roles'.
 * @param   role    One more role.
 */
void Character::add_role(Role role) {
    Character::roles.push_back(role);
}

/**
 * Names` vector getter.
 * @return  Vector of strings - names of Character.
 */
std::vector<std::string> &Character::getNames() {
    return names;
}

/**
 * Names` vector setter.
 * @param   names   New vector of strings - names of Character.
 */
void Character::setNames(std::vector<std::string> &names) {
    Character::names = names;
}

/**
 * Roles` vector getter.
 * @return  Vector of Roles - roles of Character.
 */
std::vector<Character::Role> &Character::getRoles() {
    return roles;
}

/**
 * Roles` vector setter.
 * @param   roles   New vector of Roles - roles of Character.
 */
void Character::setRoles(std::vector<Role> &roles) {
    Character::roles = roles;
}

/**
 * @brief
 * Override operator<< of ostream.
 * Out look like:
 * @code
 * {{'name 1', 'name 2', ...}, {'role 1', 'role 2', ...}}
 * @endcode
 */
std::ostream &operator<<(std::ostream &os, const Character &character) {
    os << '{';
    if (!character.names.empty()) {
        os << '{';
        for (int i = 0; i < character.names.size() - 1; i++) {
            os << character.names.operator[](i) << ", ";
        }
        os << character.names[character.names.size() - 1] << "}, ";
    }else{
        os << "no names, ";
    }

    if (!character.roles.empty()) {
        os << '{';
        for (int i = 0; i < character.roles.size() - 1; i++) {
            os << character.roles[i] << ", ";
        }
        os << character.roles[character.roles.size() - 1] << "}, ";
    } else{
        os << "no roles";
    }
    os << '}';

    return os;
}

/**
 * Equal operator.
 * @param   rhs Second Character.
 * @return      If all vectors in Character equal to vectors in rhs -> true, else -> false.
 */
bool Character::operator==(const Character &rhs) const{
    return names == rhs.names &&
           roles == rhs.roles;
}

/**
 * Unequal operator.
 * @param   rhs Second Character.
 * @return      If one or more vectors in Character unequal to vectors in rhs -> true, else -> false.
 */
bool Character::operator!=(const Character &rhs) const{
    return !(rhs == *this);
}

/**
 * Less than operator.
 * Compare first by names, then by roles.
 * @param   rhs Second Character.
 * @return      *this < rhs.
 */
bool Character::operator<(const Character &rhs) const{
    if (names < rhs.names)
        return true;
    if (rhs.names < names)
        return false;
    return roles < rhs.roles;
}

/**
 * Great than operator.
 * Compare first by names, then by roles.
 * @param   rhs Second Character.
 * @return      rhs < *this.
 */
bool Character::operator>(const Character &rhs) const{
    return rhs < *this;
}

/**
 * Less or equal operator.
 * Compare first by names, then by roles.
 * @param   rhs Second Character.
 * @return      !(rhs < *this).
 */
bool Character::operator<=(const Character &rhs) const{
    return !(rhs < *this);
}

/**
 * Great or equal operator.
 * Compare first by names, then by roles.
 * @param   rhs Second Character.
 * @return      !(rhs > *this).
 */
bool Character::operator>=(const Character &rhs) const{
    return !(*this < rhs);
}