#include <iostream>

//struct for Node
template <typename elemType>
struct Node {
    elemType elem;
    Node *next;
};

//class for Stack
template <typename elemType>
class Stack {
    private:
        Node<elemType> *top;
        int max_size;
        int current_size;
    public:
        Stack();
        Stack(int size);

        bool isEmpty() const;

        void push(elemType new_elem);
        elemType pop();

        ~Stack();
};

/*
    Time complexity: O(1).
*/
template <typename elemType>
Stack<elemType>::Stack() {
    this->max_size = -1;
    this->top = nullptr;
}

/*
    Time complexity: O(1).
*/
template <typename elemType>
Stack<elemType>::Stack(int max_size) {
    this->max_size = max_size;
    this->current_size = 0;
    this->top = nullptr;
}

/*
    Time complexity: O(1).
*/
template <typename elemType>
bool Stack<elemType>::isEmpty() const {
    return (current_size == 0);
}

/*
    Time complexity: O(1).
*/
template <typename elemType>
void Stack<elemType>::push(elemType new_elem) {
    if (this->current_size == this->max_size) {
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }

    Node<elemType> *new_top = new Node<elemType>;
    new_top->elem = new_elem;
    new_top->next = this->top;
    this->top = new_top;

    this->current_size++;
}

/*
    Time complexity: O(1).
*/
template <typename elemType>
elemType Stack<elemType>::pop() {
    if (this->isEmpty()) {
        throw std::out_of_range("Stack Underflow!");
    }

    elemType deleted_elem = this->top->elem;

    Node<elemType> *curr_top = top;
    this->top = this->top->next;
    delete curr_top;

    this->current_size--;

    return deleted_elem;
}

/*
    Time complexity: O(n).
*/
template <typename elemType>
Stack<elemType>::~Stack() {
    Node<elemType> *temp;
    while (top != nullptr) {
        temp = top;
        top = top->next;
        delete temp;
    }
}