#ifndef KNU_OOP_K28_LIST_H
#define KNU_OOP_K28_LIST_H

template<class T>
class List {
public:
    virtual void add(T obj) = 0;

    virtual void add(T obj, int index) = 0;

    virtual void remove(int index) = 0;

    virtual T &get(int index) = 0;

    virtual int find(T obj) = 0;

    virtual void clear() = 0;

    virtual void sort(void (*sort_func)(T *, int)) = 0;

    virtual void sort(void (*)(T *, int, int(*)(T &obj1, T &obj2)),
                      int(*)(T &obj1, T &obj2) = nullptr) = 0;

    virtual int get_size() = 0;
};


#endif
