#include <iostream>
#include <vector>
#include <algorithm>

void lis(int *arr, int size) {
    int lis_values[size];

    for (auto &elem : lis_values) {
        elem = 1;
    }

    for (int i = 1; i < size; i++) {
        std::vector<int> subproblems;
        for (int k = 0; k < i; k++) {
            if (arr[k] < arr[i]) {
                subproblems.push_back(lis_values[k]);
            }
        }

        if (!subproblems.empty()) {
            lis_values[i] = 1 + *(std::max_element(subproblems.begin(),
                                                   subproblems.end()));
        }
        else {
            lis_values[i] = 1;
        }
    }

    auto solution_ind = std::distance(lis_values, 
                                      std::max_element(lis_values, lis_values+size));

    int i = lis_values[solution_ind];
    int solution_arr[i];

    solution_arr[i-1] = arr[solution_ind];

    while (solution_ind != 0) {
        solution_ind--;
        if (lis_values[solution_ind] < lis_values[solution_ind+1]) {
            i--;
            solution_arr[i-1] = arr[solution_ind];
        }
    }

    for (auto elem : solution_arr) {
        std::cout << elem << " ";
    }
}

int main() {
    int size;
    std::cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    lis(arr, size); 
}