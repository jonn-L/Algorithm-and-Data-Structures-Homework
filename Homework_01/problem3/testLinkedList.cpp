#include<iostream>
#include"LinkedList.h"

using namespace std;

//Node parametric constructor
template <class T>
Node<T>::Node(T elem) {
    next = nullptr;
    prev = nullptr;
    this->elem = elem;
}

//Default linkedlist constructor
template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//LinkedList destructor
template <class T>
LinkedList<T>::~LinkedList() {
    Node<T> *curr = head;               //pointer that points to the first node
    for (int i = 0; i < size; i++) {    //iterate through all the elements
        head = head->next;              
        delete curr;            
        curr = head;
    }
}

//Return the first element of the list
template <class T>
T LinkedList<T>::returnFirst() {
    if (head != nullptr) {                  //check if list is empty
        return head->elem;
    }
    throw runtime_error("List is empty");   //if it's empty, throw an error
}

//Return the first element and remove it
template <class T>
T LinkedList<T>::returnFirstRemove() {
    if (head != nullptr) {              //Check if list is empty               
        T removedELem = head->elem;     //Element to return
        Node<T> *curr = head;

        head = head->next;              //Change the position of the head
        if (head != nullptr) {          //Check if the new head is null       
            head->prev = nullptr;       //If so, its prev should point to null
        }

        delete curr;                    //Remove the first element
        size--;                         //Decrement the size

        return removedELem;             //Return the removed element
        
    }
    throw runtime_error("List is empty");
}

//Return the last element
template <class T>
T LinkedList<T>::returnLast() {
    if (tail != nullptr) {             //check if list is empty
        return tail->elem;              
    }    
    throw runtime_error("List is empty");
}

//Return the last element and remove it from the list
template <class T>
T LinkedList<T>::returnLastRemove() {
    if (this->tail != nullptr) {        //check if list is empty
        T removedElem = tail->elem;     //element to return later
        Node<T> *curr = tail;           //pointer to the tail node

        tail = tail->prev;              //change the positon of tail
        if (tail != nullptr) {          //check if the new tail is null
            tail->next = nullptr;       //if so, change its next to null
        }

        delete curr;                    //remove the item
        size--;                         //decrement the size

        return removedElem;             //retrun the element
    }
    throw runtime_error("List is empty");
}

//Method to insert element to the front
template <class T>
void LinkedList<T>::insertFront(T elem) {
    Node<T> *newHead = new Node<T>(elem);   //create node that holds element

    newHead->next = head;       //put current head after the newHead
    if (head != nullptr) {      //check if head is null
        head->prev = newHead;   //if not, link it to the newhead
    }

    if (tail == nullptr) {      //check if the list has only one element
        tail = newHead;         //if so, make it point to newHead
    }

    head = newHead;             //update head to newHead
    size++;                     //increment size
}

//Method to insert element to the back
template <class T>
void LinkedList<T>::insertBack(T elem) {
    Node<T> *newTail = new Node<T>(elem);   //create node that holds element

    newTail->prev = tail;       //put current tail before newTail
    if (tail != nullptr) {      //check if current tail is null
        tail->next = newTail;   //if not, link it to newTail
    }

    if (head == nullptr) {      //check if list has only one element
        head = newTail;         //if so, make it point to newTail 
    }

    tail = newTail;             //update tail to newTail
    size++;                     //increment size
}

//Method that returns number of elements
template <class T>
int LinkedList<T>::entities() {
    return size;
}

int main () {
    LinkedList<int> intList;

    intList.insertFront(2);
    cout << "Added 2 to the front: " << intList.returnFirst() << endl;

    intList.insertBack(3);
    cout << "Added 3 to the back: " << intList.returnLast() << endl;

    intList.insertFront(1);
    cout << "Added 1 to the front " << intList.returnFirst() << endl;

    cout << "Current number of elements: " << intList.entities() << endl;

    cout << "Removed first element: " << intList.returnFirstRemove() << endl;
    cout << "Removed last element: " << intList.returnLastRemove() << endl;

    cout << "Current number of elements: " << intList.entities() << endl;

    return 0;
}