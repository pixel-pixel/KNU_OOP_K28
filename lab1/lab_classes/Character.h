#ifndef KNU_OOP_K28_CHARACTER_H
#define KNU_OOP_K28_CHARACTER_H

#include <vector>
#include "Book.h"

class Character {
    class Role {
        enum Part {
            main,
            minor,
            episodic
        };
        Book *book;
        Part part;

    public:
        Role(Book *book = new Book,
             Part part = Part::main){
            this->book = book;
            this->part = part;
        }

        Book *getBook() const {
            return book;
        }

        void setBook(Book *book) {
            this->book = book;
        }

        Part getPart() const {
            return part;
        }

        void setPart(Part part) {
            this->part = part;
        }
    };

    vector<string> *names;
    vector<Role> *roles;

public:
    Character(vector<string> *names = new vector<string>,
            vector<Role> *roles = new vector<Role>){
        this->names = names;
        this->roles = roles;
    }

    void add_name(string new_name){
        names->push_back(new_name);
    }

    void add_role(Role new_role){
        roles->push_back(new_role);
    }

    vector<string> &getNames() const {
        return *names;
    }

    void setNames(vector<string> *names) {
        this->names = names;
    }

    vector<Role> &getRoles() const {
        return *roles;
    }

    void setRoles(vector<Role> *roles) {
        this->roles = roles;
    }
};


#endif
