#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

void max_heapify(vector<int> &A, int &heapSize, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if ((l < heapSize) && (A[l] > A[largest])) {
        largest = l;
    }
    if ((r < heapSize) && (A[r] > A[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(A[i], A[largest]);
        max_heapify(A, heapSize, largest);
    }
}

void build_max_heap(vector<int> &A, int &heapSize) {
    for (int i = round(A.size()/2.0)-1; i >= 0; i--) {
        max_heapify(A, heapSize, i);
    }
}

void float_down(vector<int> &A, int &heapSize, int i) {
    while (i*2 + 1 < heapSize) {
        int j = i*2 + 1;
        if ((j + 1 < heapSize) && (A[j] < A[j+1])) {
            j++;
        }
        if (A[i] < A[j]) {
            swap(A[i], A[j]);
            i = j;
        } 
        else {
            break;
        }
    }
}

void heap_sort(vector<int> &A) {
    int heapSize = A.size();
    build_max_heap(A, heapSize); 

    for (int i = A.size() - 1; i >= 1; i--) {
        swap(A[0], A[i]);
        heapSize--;
        float_down(A, heapSize, 0);
    }
}

vector<int> randomVec(int size) {
    vector<int> vec;

    for (int i = 0; i < size; i++) {
        int elem = rand() % 50;
        vec.push_back(elem);
    }

    return vec;
}

int main () {
    srand(time(0));

    int testCases = 1000;
    ofstream file("time_computations.txt", ios::app);

    file << "Heap Sort Variant: " << endl;
    for (int i = 1; i <= testCases; i++) {
        vector<int> vec = randomVec(i);

        auto start = high_resolution_clock::now(); 
        heap_sort(vec);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        file << duration.count() << " ";
    } 

    file.close();

    return 0;
}