#ifndef KNU_OOP_K28_LINKEDLIST_H
#define KNU_OOP_K28_LINKEDLIST_H

#include "List.h"

/**
 * @brief
 * Class of dynamic array(list) based on linked nodes.
 * @tparam  T   Class or primitive with override operators: std::ostream<<, >, <, ==, !=, >=, <=.
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
     * If the element is not contained in the list, method return -1.
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
     * Method for sort the LinkedList.
     * @details
     * If the sort function is not specified or equals 'nullptr', the LinkedList will be sorted by quick sort function.
     * Method creates array of elements in the LinkedList for pass to sort function.
     * Then the method clears the list and add all elements from array to LinkedList.
     * @param   sort_func   The function for sort which takes the array of elements from the LinkedList and size of the LinkedList.
     */
    void sort(Comparator<T> *comparator = nullptr) {
        T *arr = new T[size];

        tail = head;
        for (int i = 0; i < size; i++) {
            arr[i] = tail->obj;
            tail = tail->next;
        }

        QuickSort<T> quickSort;
        quickSort.sort(arr, size, comparator);

        tail = head;
        for (int i = 0; i < size; i++) {
            tail->obj = arr[i];
            tail = tail->next;
        }
    }

    /**
     * @brief
     * Override method for sort the LinkedList by compare function.
     * @details
     * If the compare function is not specified or equals 'nullptr', the LinkedList will be sorted by default operators(>, <, ==, !=, >=, <=).
     * Method also creates array of elements from the Linked for pass to sort function.
     * Then the method clears the LinkedList and add all elements from array to LinkedList.
     * @param   sort_func       The function for sort which takes the array of elements from the LinkedList, size of the list and compare function.
     * @param   compare_func    The function which takes 2 elements and return: 1 -> if first is bigger, -1 -> if first is less, 0 -> else.
     */
    void sort(Sort<T> *sort, Comparator<T> *comparator = nullptr) override {
        T *arr = new T[size];

        tail = head;
        for (int i = 0; i < size; i++) {
            arr[i] = tail->obj;
            tail = tail->next;
        }

        sort->sort(arr, size, comparator);

        tail = head;
        for (int i = 0; i < size; i++) {
            tail->obj = arr[i];
            tail = tail->next;
        }
    }

    /**
     * @brief
     * Return the size of LinkedList.
     * @return  size of LinkedList.
     */
    int get_size() override {
        return size;
    }

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

    /**
     * @brief
     * Override operator<< of ostream.
     * Out look like:
     * @code
     * [T, T, T, T, T]
     * @endcode
     */
    friend std::ostream &operator<<(std::ostream &out, LinkedList<T> &list) {
        return list.print(out);
    }

    bool operator==(LinkedList &rhs) {
        if (get_size() != rhs.get_size()) return false;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) != rhs.get(i)) return false;
        }
        return true;
    }

    bool operator!=(LinkedList &rhs) {
        return !(rhs == *this);
    }

    bool operator<(LinkedList &rhs) {
        if (get_size() < rhs.get_size()) return true;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) < rhs.get(i)) return true;
        }
        return false;
    }

    bool operator>(LinkedList &rhs) {
        return rhs < *this;
    }

    bool operator<=(LinkedList &rhs) {
        return !(rhs < *this);
    }

    bool operator>=(LinkedList &rhs) {
        return !(*this < rhs);
    }
};


#endif
