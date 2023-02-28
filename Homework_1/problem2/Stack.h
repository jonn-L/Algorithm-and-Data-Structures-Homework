#ifndef STACK_H
#define STACK_H

template <class T>
class Stack {
    private:
        T *storage;         //holds the elements
        int max_size;       //the current max size of the stack
        int last_elem;      //index of the next free position in stack

    public:
        //Default constructor with default settings
        Stack();

        //Copy constructor
        Stack(const Stack& copyStack);

        //Constructor that sets a custom size for the stack
        Stack(int size);

        //Push function that adds an element
        bool push(T element);

        //Pop function that moves the last element to the "out" stack
        bool pop(T &out);

        //Function that returns the last element in the stack
        T back(void);

        //Function that returns the number of elements in the stack
        int getNumEntries();

        //Destructor
        ~Stack();
};

#endif