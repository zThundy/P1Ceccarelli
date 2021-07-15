// this is the file that the driver (wich is our main file) will call
// and instantiate
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include <stdexcept>
#include <iostream>
#include "CLinkedList.h"

template <typename E>
class LinkedQueue {
    public:
        // constructor
        LinkedQueue();
        // dimension of queue
        int size() const;
        // check if queue is empty
        bool empty() const;
        // getter for front element (in fact it returns a reference)
        const E& front();
        // getter for back element (in fact it returns a reference)
        const E& back();
        // add a new element to the circular queue
        void enqueue(const E& e);
        // remove the front element of the queue
        void dequeue();
    private:
        CircleList<E> C; // circular list of elements
        int n; // number of elements in the queue
};

#endif

template <typename E>
LinkedQueue<E>::LinkedQueue()
    : C(), n{0}{
}

template <typename E>
int LinkedQueue<E>::size() const{return n; }

template <typename E>
bool LinkedQueue<E>::empty() const{return n==0; }

template <typename E>
const E& LinkedQueue<E>::front(){
    if(empty()) throw std::runtime_error("nothing at the front of the queue");
    return C.front();
}

template <typename E>
const E& LinkedQueue<E>::back() {
    if (empty()) throw std::runtime_error("nothing on the back of the queue");
    return C.back();
}

template <typename E>
void LinkedQueue<E>::enqueue(const E& e){
    C.add(e);
    C.advance();
    n++;
}

template <typename E>
void LinkedQueue<E>::dequeue(){
    if(empty()) throw std::runtime_error("dequeue of empty queue");
    C.remove();
    n--; 
}