#include <iostream>
#include <deque>
#include <chrono>   //library to compute the computation time
using namespace std;
using namespace chrono;

/*
    Implementation of Selection Sort - Jon Lumi
    deq - deque to be sorted
    swaps - variable that holds the number of swaps
*/
void selectionSort(deque<int> &deq, int &swaps) {
    for (auto i = deq.begin(); i != deq.end(); i++) {   //loop through deque
        auto smallestIT = i;    //set current element to be the smallest

        for (auto j = i+1; j != deq.end(); j++) {   //loop the rest elements
            if (*j < *smallestIT) {     //check if element is smaller
                smallestIT = j;     
            }
        }

        if (*smallestIT != *i) {    //check if a smaller element has been found
            //swap the elements
            int temp = *i;
            *i = *smallestIT;
            *smallestIT = temp;
            swaps++;
        }
    }
}

/*
    Create a deque with random values and return it
    size - size of the deque to be generated
*/
deque<int> randomDeq(int size) {
    deque<int> deq;

    for (int i = 0; i < size; i++) {
        int elem = rand() % 50;     //generate random number 0 - 50
        deq.push_back(elem);        //add the element to the back
    }

    return deq;
} 

/*
    Create a deque with random values and return it.
    Deque will always take size-1 swaps to sort.
    size - size of the deque to be generated
*/
deque<int> caseA(int size) {
    deque<int> deq;

    int elem = rand() % 50;     //generate first element 0-50
    deq.push_back(elem);        //add it to the deque

    for (int i = 1; i < size; i++) {    //start from second spot
        int increment = 1 + rand() % 10;    //generate a random increment
        elem += increment;      //add increment to previous elem
        deq.push_back(elem);    //add element to the back
    }

    //move the last element to the front
    auto lastElem = deq.back(); 
    deq.push_front(lastElem);
    deq.pop_back();

    return deq;
}

/*
    Create a deque with random values and return it.
    Deque will always take 0 swaps to sort/
    size - size of the deque to be generated

*/
deque<int> caseB(int size) {
    deque<int> deq;

    int elem = rand() % 50;
    deq.push_back(elem);

    for (int i = 1; i < size; i++) {
        int increment = 1 + rand() % 10;
        elem += increment;
        deq.push_back(elem);
    }

    return deq;
}


int main () {
    srand(time(0));     //reset seed

    //create deques to hold the computation times
    deque<double> computationCaseRandom;
    deque<double> computationCaseA;
    deque<double> computationCaseB;


    cout << "====Random Deques====" << endl;
    for (int i = 0; i < 50; i++) {
        //create deque using function with size going from 1 - 50
        deque<int> deq = randomDeq(i+1);    
        
        //print out the unsorted deque
        cout << "Unsorted: ";
        for (auto j : deq) {
            cout << j << " ";
        }
        cout << endl;

        int swaps = 0;  //variable that will hold number of swaps
        auto start = high_resolution_clock::now();  //start the clock
        selectionSort(deq, swaps);  //sort the deque
        auto stop = high_resolution_clock::now();   //stop the clock
        //find the time taken
        auto duration = duration_cast<microseconds>(stop - start);

        //print sorted deque
        cout << "Sorted: ";
        for (auto j : deq) {
            cout << j << " ";
        }
        cout << endl;

        cout << "Number of swaps: " << swaps << endl;   //print number of swaps
        //add time to deque
        computationCaseRandom.push_back(duration.count());  
        cout << endl;
    } 

    cout << "====Case A====" << endl;
    for (int i = 0; i < 50; i++) {
        //create deque using function with size going from 1 - 50
        deque<int> deq = caseA(i+1);    
        
        //print out the unsorted deque
        cout << "Unsorted: ";
        for (auto j : deq) {
            cout << j << " ";
        }
        cout << endl;

        int swaps = 0;  //variable that will hold number of swaps
        auto start = high_resolution_clock::now();  //start the clock
        selectionSort(deq, swaps);  //sort the deque
        auto stop = high_resolution_clock::now();   //stop the clock
        //find the time taken
        auto duration = duration_cast<microseconds>(stop - start);

        //print sorted deque
        cout << "Sorted: ";
        for (auto j : deq) {
            cout << j << " ";
        }
        cout << endl;

        cout << "Number of swaps: " << swaps << endl;   //print number of swaps
        //add time to deque
        computationCaseA.push_back(duration.count());  
        cout << endl;
    } 

    cout << "====Case B====" << endl;
    for (int i = 0; i < 50; i++) {
                //create deque using function with size going from 1 - 50
        deque<int> deq = caseB(i+1);    
        
        //print out the unsorted deque
        cout << "Unsorted: ";
        for (auto j : deq) {
            cout << j << " ";
        }
        cout << endl;

        int swaps = 0;  //variable that will hold number of swaps
        auto start = high_resolution_clock::now();  //start the clock
        selectionSort(deq, swaps);  //sort the deque
        auto stop = high_resolution_clock::now();   //stop the clock
        //find the time taken
        auto duration = duration_cast<microseconds>(stop - start);

        //print sorted deque
        cout << "Sorted: ";
        for (auto j : deq) {
            cout << j << " ";
        }
        cout << endl;

        cout << "Number of swaps: " << swaps << endl;   //print number of swaps
        //add time to deque
        computationCaseB.push_back(duration.count());  
        cout << endl;
    } 

    //print out the deques with the computed times
    cout << "Computations for random deques in microseconds: ";
    for (auto elem : computationCaseRandom) {
        cout << elem << ", ";
    }
    cout << endl;

    cout << "Computations for case A deques in microseconds: ";
    for (auto elem : computationCaseA) {
        cout << elem << ", ";
    }
    cout << endl;

    cout << "Computations for case B deques in microseconds: ";
    for (auto elem : computationCaseB) {
        cout << elem << ", ";
    }
    cout << endl;

    return 0;
}