#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void insertion_sort(vector<double> vec) {
    for (unsigned int j = 0; j < vec.size(); j++) {
        int key = vec[j];

        int i = j-1;
        while ((i >= 0) && (vec[i] > key)) {
            vec[i+1] = vec[i];
            i--;
        }
        vec[i+1] = key;
    } 
}

void bucket_sort(vector<double> &vec) {
    int size = vec.size();
    vector<double> buckets[size];

    for (int i = 0; i < size; i++) {
        int index = round(size*vec[i]);
        buckets[index].push_back(vec[i]);
    }

    for (int i = 0; i < size; i++) {
        insertion_sort(buckets[i]);
    }

    vec.clear();
    for (int i = 0; i < size; i++) {
        vec.insert(vec.end(), buckets[i].begin(), buckets[i].end());
    }
}

int main() {
    vector<double> vec = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};

    bucket_sort(vec);

    for (auto elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}