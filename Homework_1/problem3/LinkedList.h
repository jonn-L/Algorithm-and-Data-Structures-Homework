#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class Node {
    public:
        Node<T> *next;  //pointer to the next element
        Node<T> *prev;  //pointer to the previous element
        T elem;
        
        Node(T elem);    //parametric constuructor
};

template <class T>
class LinkedList {
    private:
        Node<T> *head;      //node pointer that points to the head of the list
        Node<T> *tail;      //mode pointer that points to the tail of the list
        int size;
    public:
        //constructor and destructor
        LinkedList();
        ~LinkedList();

        //methods to return element with or without removing it from the list
        T returnFirst();
        T returnFirstRemove();
        T returnLast();
        T returnLastRemove();

        //methods to insert elements into the list 
        void insertFront(T elem);
        void insertBack(T elem);

        int entities();
};


#endif