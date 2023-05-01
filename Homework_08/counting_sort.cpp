#include <iostream>

using namespace std;

void counting_sort(int arr[], int size, int k) {
    int sorted_arr[size], digit_counter[k];

    for (int i = 0; i < k; i++) {
        digit_counter[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        digit_counter[arr[i]] = digit_counter[arr[i]] + 1;
    }

    for (int i = 1; i < k; i++) {
        digit_counter[i] = digit_counter[i] + digit_counter[i-1];
    }

    for (int i = (size-1); i >= 0; i--) {
        sorted_arr[digit_counter[arr[i]]-1] = arr[i];
        digit_counter[arr[i]]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = sorted_arr[i];
    }
}

int main() {
    int size = 7;
    int arr[size] = { 9, 1, 6, 7, 6, 2, 1};

    for (auto elem : arr) {
        cout << elem <<  " ";
    }
    cout << endl;

    counting_sort(arr, size, 10);

    for (auto elem : arr) {
        cout << elem <<  " ";
    }
    cout << endl;

    return 0;
}