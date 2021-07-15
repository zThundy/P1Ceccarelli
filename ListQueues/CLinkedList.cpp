#include <iostream>
#include <sstream>

// the constructor of the circleList class will just instantiate
// the cursor private element of the class as a null pointer (empty pointer)
// so we can fill this up with whatever we want
template <typename T>
CircleList<T>::CircleList()
    : cursor {nullptr} {
}

// the deconstructor of this class will check if the class current pointer
// has an element inside, if true, it will remove the element
template <typename T>
CircleList<T>::~CircleList(){
    while(!empty())
        remove();
}

// this method will check if the current cursor is empty or not (so the list is empty or not)
template <typename T>
bool CircleList<T>::empty() const{
    return cursor == nullptr;
}

// the back function will return us the value of the first element of the list
template <typename T>
const T& CircleList<T>::back() const {
    return cursor->elem;
}

// the front method will return the last element of the queue (the right one)
template <typename T>
const T& CircleList<T>::front() const {
    return cursor->next->elem;
}

// the advance function will advance the current cursor pointer that will point to the
// rughtest element of the queue (wich will be a null ptr)
template <typename T>
void CircleList<T>::advance(){
    // std::cout << "before advance " << cursor << std::endl;
    cursor = cursor->next;
    // std::cout << "after advance " << cursor << std::endl;
}

template <typename T>
void CircleList<T>::add(const T& e){
    CNode<T> *v = new CNode<T>;
    v->elem = e;
    // std::cout << cursor << std::endl;
    if(cursor == nullptr){
        v->next = v;
        cursor = v;
    } else {
        v->next = cursor->next;
        cursor->next = v;
    }
}

template <typename T>
void CircleList<T>::remove() {
    CNode<T> *old = cursor->next;
    if(old == cursor){
        cursor = nullptr;
    } else{
        cursor->next = old->next;
    }
    delete old;
}

template <typename T>
std::string CircleList<T>::toString() {
    std::ostringstream out;
    CNode<T> *u = cursor;
    out << "Cursor --> ";
    out << u->elem << " --> ";
    u = u->next;
    while(u != cursor){
        out << u->elem << " --> ";
        u = u->next; 
    }
    out <<"Cursor";
    return out.str();
}