template <typename T> class CircleList;

// think that this is the element contained inside the list
// so the T as a template is the element and the CNode* is the pointer
// to the next element of the queue
template <typename T>
class CNode{
    private:
        // template element, can contain anything we pass to it
        T elem;
        // pointer element to the next element (CNode as type so we're pointing to the class element)
        CNode* next;
        // a friend class can access private and protected members of other class in which it is declared as friend.
        friend class CircleList<T>;
};