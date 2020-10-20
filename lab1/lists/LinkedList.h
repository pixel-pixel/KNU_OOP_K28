#ifndef KNU_OOP_K28_LINKEDLIST_H
#define KNU_OOP_K28_LINKEDLIST_H

#include "List.h"

/**
 * @brief
 * Class of dynamic array(list) based on linked nodes. Implements the List interface.
 * @tparam  T   Class or primitive with override operators: std::ostream<< and (relational operators or have it own Comparator).
 */
template<class T>
class LinkedList : public List<T> {
private:
    /**
     * @brief
     * Inner class which contains pointer on next Node. They contain our objects.
     */
    class Node {
    public:
        T obj;                  ///< Object which we add, remove, find...
        Node *next = nullptr;   ///< Pointer on next Node.

        Node(T &obj) {
            this->obj = obj;
        }

    };

    int size = 0;               ///< Value for saving count of elements.
    Node *head = nullptr;       ///< Pointer on first Node in LinkedList.
    Node *tail = nullptr;       ///< Pointer on last Node in LinkedList

public:
    /**
     * @brief
     * Destructor of LinkedList. Delete all Nodes.
     */
    ~LinkedList() {
        if (size > 0) {
            tail = head->next;
            for (int i = 0; i < size - 1; i++) {
                delete head;
                head = tail;
                tail = tail->next;
            }
            delete head;
            delete tail;
        }
    }

    /**
     * @brief
     * Add element to LinkedList.
     * @details
     * Adds an element and puts it in a certain position.
     * If the index is not specified or less than zero - adds an item to the end of the LinkedList.
     * If an item is not added to the end of the LinkedList, the item that belonged to that index(and all after it) moves forward.
     * @throw   std::out_of_range If index is bigger than size.
     * @param   obj     The element which we want to add to LinkedList.
     * @param   index   The index on which we want to place the element.
     */
    void add(T obj, int index = -1) override {
        if (index < 0)
            index = size;
        else if (index > size)
            throw std::out_of_range("your index " + std::to_string(index) + " is greater then the size");

        if (index == 0) {
            if (size == 0) {
                head = new Node(obj);
                tail = head;
            } else {
                Node *n = new Node(obj);
                n->next = head;
                head = n;
            }
        } else if (index < size) {
            Node *temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            Node *new_node = new Node(obj);
            new_node->next = temp->next;
            temp->next = new_node;
        } else if (index == size) {
            tail->next = new Node(obj);
            tail = tail->next;
        }
        size++;
    }

    /**
     * @brief
     * Remove element by index from LinkedList.
     * @details
     * If we remove element by index, all elements with bigger index moved:
     * index+1 -> index, index+2 -> index+1;
     * But:
     * index-1 -> index-1, index-2 -> index-2;
     * If index is less than 0, than index = size - 1 (remove last element in LinkedList).
     * @throw   std::out_of_range If index is bigger than size - 1.
     * @param   index   The index by which we want to delete the item.
     */
    void remove(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");
        else if (index < 0)
            index = size - 1;

        if (index == 0) {
            Node *temp = head;
            head = head->next;
            delete temp;
        } else {
            Node *temp = head;
            while (index != 1) {
                temp = temp->next;
                index--;
            }
            Node *temp2 = temp->next;
            temp->next = temp2->next;
            delete temp2;
        }
        size--;
    }

    /**
     * @brief
     * Get element by index from LinkedList.
     * @details
     * Method returns reference not an element.
     * If index is less than 0, than index = size - 1 (remove last element from the LinkedList).
     * If index is bigger or equals to the size, than method must throw std::out_of_range.
     * @param   index   The index of the element in the LinkedList we want to get.
     * @return          Element from the LinkedList by index.
     */
    T &get(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");
        else if (index < 0)
            index = size - 1;

        if (index == 0) {
            return head->obj;
        } else {
            Node *temp = head;
            while (index != 0) {
                temp = temp->next;
                index--;
            }
            return temp->obj;
        }
    }

    /**
     * @brief
     * Find the index of an element in the LinkedList.
     * @details
     * If the element is not contained in the LinkedList, method return -1.
     * If the LinkedList contains great than 1 such element, method return tne first index.
     * @param   obj     The element which index we want to know.
     * @return          The index of the element in the LinkedList or -1 if element is not contained.
     */
    int find(T obj) override {
        int res = -1;

        Node *temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->obj == obj) {
                res = i;
                break;
            }
            temp = temp->next;
        }
        return res;
    }

    /**
     * @brief
     * Remove all elements of the LinkedList.
     * Now size = 0;
     */
    void clear() override {
        Node *temp = head;
        for (int i = 0; i < size; i++) {
            if (head->next != nullptr) temp = head->next;
            delete head;
            head = temp;
        }
        head = nullptr;
        size = 0;
    }

    /**
     * @brief
     * Method for sort the LinkedList by Comparator.
     * @details
     * If the pointer on Comparator is not specified or equals 'nullptr', the LinkedList will be sorted by object`s relational operators.
     * Method creates array of elements in the LinkedList for pass to Sort`s method.
     * Then the method clears the LinkedList and add all elements from array to LinkedList.
     * Sort`s method is 'QuickSort'.
     * @param   comparator   The point on Comparator which compare two objects. DefaultComparator if not init.
     */
    void sort(Comparator<T> *comparator = nullptr) override {
        T *arr = new T[size];

        tail = head;
        for (int i = 0; i < size; i++) {
            arr[i] = tail->obj;
            tail = tail->next;
        }

        QuickSort<T> quickSort;

        if (comparator) {
            quickSort.sort(arr, size, comparator);
        } else {
            DefaultComparator<T> defaultComparator;
            quickSort.sort(arr, size, &defaultComparator);
        }

        tail = head;
        for (int i = 0; i < size; i++) {
            tail->obj = arr[i];
            tail = tail->next;
        }

        delete [] arr;
    }

    /**
     * @brief
     * Override method for sort the LinkedList by Comparator and certain sort.
     * @details
     * If the pointer on Comparator is not specified or equals 'nullptr', the LinkedList will be sorted by object`s relational operators.
     * Method creates array of elements in the LinkedList for pass to Sort`s method.
     * Then the method clears the LinkedList and add all elements from array to LinkedList.
     * @param   sort        The pointer on Sort object which have one method - 'sort'. It sort LinkedList by certain type.
     * @param   comparator  The point on Comparator which compare two objects. DefaultComparator if not init.
     */
    void sort(Sort<T> *sort, Comparator<T> *comparator = nullptr) override {
        T *arr = new T[size];

        tail = head;
        for (int i = 0; i < size; i++) {
            arr[i] = tail->obj;
            tail = tail->next;
        }

        if(comparator) {
            sort->sort(arr, size, comparator);
        }else{
            DefaultComparator<T> defaultComparator;
            sort->sort(arr, size, &defaultComparator);
        }

        tail = head;
        for (int i = 0; i < size; i++) {
            tail->obj = arr[i];
            tail = tail->next;
        }

        delete [] arr;
    }

    /**
     * @brief
     * Return the size of LinkedList.
     * @return  size of LinkedList.
     */
    int get_size() override {
        return size;
    }

    /**
     * @brief
     * Return std::string representation.
     * Out look like:
     * @code
     * [T, T, T, T, T]
     * @endcode
     * @return The string of this LinkedList.
     */
    std::string to_string() override {
        std::stringstream ss;

        ss << '[';
        tail = head;
        if (size != 0) {
            for (int i = 0; i < size - 1; i++) {
                ss << tail->obj << ", ";
                tail = tail->next;
            }
            ss << tail->obj;
        }
        ss << ']';

        return ss.str();
    }
};

#endif