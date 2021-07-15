// this is the class containing a list of useful functions that will
// access our elements
// in other words this is the class containing the
#ifndef CLINKED_LIST_H
#define CLINKED_LIST_H
#include <iostream>
#include "CNode.h"

template <typename T>
class CircleList{
    public:
        // constructor
        CircleList();
        // deconstructor
        ~CircleList();

        // function that checks if the list is empty
        bool empty() const;
        const T& front() const;
        const T& back() const;
        void advance();
        void add(const T& e);
        void remove();
        std::string toString();
    private:
        CNode<T>* cursor;
};

#include "CLinkedList.cpp"
#endif