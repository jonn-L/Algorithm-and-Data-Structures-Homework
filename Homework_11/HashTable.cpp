#include "HashTable.hpp"
#include <iostream>

HashTable::HashTable() {
    this->maxSize = 16;
    this->currentSize = 0;
    this->arr = new Node*[maxSize];

    for (int i = 0; i < maxSize; i++) {
        this->arr[i] = nullptr;
    }
}

int HashTable::hashCode(int key) {
    return key % maxSize;
}

void HashTable::insertNode(int key, int value) {
    int index = hashCode(key);
    int counter = 1;

    while (arr[index] != nullptr) {
        if (counter == maxSize) {
            std::cout << "Hash Table is full!" << std::endl;
            return;
        }

        //update value if key already is in use
        if (arr[index]->key == key) {
            arr[index]->value = value;
            return;
        }

        //increment and get new index
        index++;
        index = hashCode(index);

        counter++;
    }


    std::cout << index << std::endl;
    this->arr[index] = new Node(key, value);
    this->currentSize++;
}


int HashTable::get(int key) {
    int index = hashCode(key);
    int counter = 1;

    while (this->arr[index] != nullptr) {
        if (counter == maxSize) {
            break;
        }

        if (this->arr[index]->key == key) {
            return this->arr[index]->value;
        }

        index++;
        index = hashCode(index);

        counter++;
    }

    std::cout << "key does not exists!" << std::endl;
    return -1;
}

bool HashTable::isEmpty() const {
    return (currentSize == 0);
}
