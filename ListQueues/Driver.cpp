#include <iostream>
#include <string>
#include "Queue.h"

int main(){
    // the queue is initialized with int values
    // so we can only use them OBV ;/
    LinkedQueue<int> Q;
    Q.enqueue(1);
    Q.enqueue(90);
    Q.enqueue(3);
    std::cout << "The front of the queue is " << Q.front() << " | The back of the queue is " << Q.back() << std::endl;
    Q.dequeue();
    std::cout << "The front of the queue is " << Q.front() << " | The back of the queue is " << Q.back() << std::endl;
    Q.dequeue();
    std::cout << "The front of the queue is " << Q.front() << " | The back of the queue is " << Q.back() << std::endl;
    Q.dequeue();
    return 0;
}