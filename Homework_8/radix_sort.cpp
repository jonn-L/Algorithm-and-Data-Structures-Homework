#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

void counting_sort(pair<int,int> *t_arr, int size) {
    pair<int,int> sorted_t_arr[size];
    int digit_counter[10];

    for (int i = 0; i < 10; i++) {
        digit_counter[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        digit_counter[t_arr[i].first] = digit_counter[t_arr[i].first] + 1;
    }   

    for (int i = 1; i < 10; i++) {
        digit_counter[i] = digit_counter[i] + digit_counter[i-1];
    }

    for (int i = (size-1); i >= 0; i--) {
        sorted_t_arr[digit_counter[t_arr[i].first]-1] = t_arr[i];
        digit_counter[t_arr[i].first]--;
    }

    for (int i = 0; i < size; i++) {
        t_arr[i] = sorted_t_arr[i];
    }
}

int get_digit(int num, int n) {
    int reduced = num/pow(10, n-1);
    return reduced % 10;
}

void radix_sort(int *arr, int begin, int end, int digits) {
    int size = end-begin;
    if ((size > 1)) {
        pair<int,int> digit_number[size];
        int k = 0;
        for (int i = begin; i < end; i++) {
            int key = get_digit(arr[i], digits);
            digit_number[k] = make_pair(key, arr[i]);
            k++;
        }

        counting_sort(digit_number, size);

        vector<int> group_indecies;
        for (int i = 1; i < end; i++) {
            if (digit_number[i].first != digit_number[i-1].first) {
                group_indecies.push_back(i);
            }
        }
        group_indecies.push_back(end);

        int j = 0;
        for (int i = begin; i < end; i++) {
            arr[i] = digit_number[j].second;
            j++;
        }

        int begin_index = begin;
        for (auto elem : group_indecies) {
            radix_sort(arr, begin_index, elem, digits-1);
            begin_index = elem;
        }
    }
}

int largest_element(int *arr, int size) {
    int largest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int count_digits(int num) {
    int digits = 0;
    while (num) {
        num /= 10;
        digits++;
    }
    return digits;
}

void generate(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

int main() {
    srand(time(0));
    int test_cases = 10;
    int size = 10;

    for (int i = 0; i < test_cases; i++) {
        int *arr = new int[size];
        generate(arr, size);

        cout << "Unsorted: ";
        for (int j = 0; j < size; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;

        int largest = largest_element(arr, i);
        int digits = count_digits(largest);
        if (i == test_cases) {
            cout << digits << endl;
        }
        radix_sort(arr, 0, i, digits);

        cout << "Sorted: ";
        for (int j = 0; j < size; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;

        delete [] arr;
    }

    return 0;
}