#include "stack.cpp"    //import the stack implemented in a1
#include <iostream>
#include <cmath>

//class for queue
template <typename elemType>
class Queue {
    private:
        Stack<elemType> front;  //stack that holds the front half of the elems
        Stack<elemType> back;   //stack that holds the back half of the elems
        int max_size;
        int current_size;

    public:
        Queue();
        Queue(int max_size);

        bool isEmpty() const;

        void enqueue(elemType new_elem);
        elemType dequeue();

        ~Queue();
};

/*
    Time complexity: O(1). 
*/
template <typename elemType>
Queue<elemType>::Queue() {
    this->front = Stack<elemType>();
    this->back = Stack<elemType>();

    this->max_size = -1;
}

/*
    Time complexity: O(1). 
*/
template <typename elemType>
Queue<elemType>::Queue(int max_size) {
    this->front = Stack<elemType>(ceil(max_size/2));
    this->back = Stack<elemType>(floor(max_size/2));

    this->nax_size = max_size;
    this->current_size = 0;
}

/*
    Time complexity: O(1). 
*/
template <typename elemType>
bool Queue<elemType>::isEmpty() const {
    return (this->current_size == 0);
}

/*
    Time complexity: O(1). 
*/
template <typename elemType>
void Queue<elemType>::enqueue(elemType new_elem) {
    if (this->current_size == this->max_size) {
        std::cout << "Queue Overflow!" << std::endl;
    }

    this->back.push(new_elem);
    this->current_size++;
}

/*
    Time complexity: O(1). 
*/
template <typename elemType>
elemType Queue<elemType>::dequeue() {
    if (this->isEmpty()) {
        throw std::out_of_range("Queue Underflow!");
    }

    //if the front stack is empty transfer one element from the top of the back
    //half to the front
    if (this->front.isEmpty()) {
        elemType elem = back.pop();
        this->front.push(elem);
    }

    this->current_size--;
    return this->front.pop();
}

/*
    Time complexity: O(n).
*/
template <typename elemType>
Queue<elemType>::~Queue() {
    this->front.~Stack();
    this->back.~Stack();
}