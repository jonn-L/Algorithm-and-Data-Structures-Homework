#include<iostream>
#include<string>
#include"Stack.h"

using namespace std;

//Default constructor
template<class T>
Stack<T>::Stack() {
    max_size = 10;
    last_elem = 0;
    storage = new T[10];
}

//Copy constructor
template<class T>
Stack<T>::Stack(const Stack& copyStack) {
    max_size = copyStack.max_size;
    last_elem = copyStack.last_elem;
    storage = new T[copyStack.max_size];

    for (int i = 0; i < this->max_size; i++) {
        storage[i] = copyStack.storage[i];
    }
}

//Constructor that sets a custom size for the stack
template<class T>
Stack<T>::Stack(int size) {
    max_size = size;
    last_elem = 0;
    storage = new T[size];
}

//Push function that adds an element
template<class T>
bool Stack<T>::push(T element) {
    if (last_elem == max_size) {            //check if stack is full
        return false;
    }

    storage[last_elem] = element;
    last_elem++;
    return true;
}

//Pop function that moves the last element to the "out" stack
template<class T>
bool Stack<T>::pop(T &out) {
    if (last_elem == 0) {                   //check if stack is empty
        return false;
    }
    T popElem = storage[last_elem-1];       //get the value of the elem
    out = popElem;

    last_elem--;
    T *newStorage = new T[max_size];        //create new storage

    for (int i = 0; i < last_elem; i++) {   //copy the leftover content
        newStorage[i] = storage[i];
    }

    delete [] storage;                      //delete the old storage
    storage = newStorage;                   //set new updated storage

    return true;
}

//Function that returns the last element in the stack
template<class T>
T Stack<T>::back(void) {
    return storage[last_elem-1];
}

//Function that returns the number of elements in the stack
template<class T>
int Stack<T>::getNumEntries() {
    return last_elem;
}

//Destructor
template<class T>
Stack<T>::~Stack() {
    delete [] storage;
}

int main () {
    //Created integer stack using default constructor and added elements to it
    Stack<int> intStack;
    for (int i = 0; i < 15; i++) {
        cout << intStack.push(i) << endl;
    }

    //Displayed the usage of .back and getNumEntries
    cout << "Last element of int stack: " << intStack.back() << endl;
    cout << 
        "Current number of entries of int stack: " << intStack.getNumEntries() 
    << endl;

    //Created intOut and used it to store the popped element
    int intOut;
    intStack.pop(intOut);
    //Printed out results
    cout << "Popped element of int stack: " << intOut << endl;
    cout << 
        "Changed number of entries of int stack: " << intStack.getNumEntries() 
    << endl;

    //Created string stack using size constructor and added elements to it
    Stack<string> strStack(15);
    string word = "occupied";
    for (int i = 0; i < 20; i++) {
        cout << strStack.push(word) << endl;
    }

    //Displayed the usage of .back and getNumEntries
    cout << "Last element of str stack: " << strStack.back() << endl;
    cout << 
        "Current number of entries of str copy: " << strStack.getNumEntries() 
    << endl;

    //Copied the strStack and then used .back .getNumEntries
    Stack<string> copyStrStack(strStack);
    cout << "Last element of copy str stack: " << strStack.back() << endl;
    cout << 
        "Current number of entries of copy str: " << strStack.getNumEntries() 
    << endl;

    return 0;
}