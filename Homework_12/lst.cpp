#include <iostream>
#include <vector>

int max(int num1, int num2) {
    if (num1 >= num2) {
        return num1;
    }
    return num2;
}

void lst(int **arr, int lines) {
    int memo[lines][lines];

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            memo[i][j] = arr[i][j];
        }
    }

    for (int i = lines-1; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            memo[i-1][j-1] += max(memo[i][j], memo[i][j-1]);
        }
    }

    int solution[lines];
    int i = 0, j = 0;
    solution[i] = arr[i][j];

    while (i < lines) {
        if (memo[i][j] > memo[i][j+1]) {
            solution[i] = arr[i][j];
        }
        else {
            solution[i] = arr[i][j+1];
            j++;
        }
        i++;
    }
    
    std::cout << memo[0][0] << std::endl;
    for (auto elem : solution) {
        std::cout << elem << " ";
    }
}

int main() {
    int lines;
    std::cin >> lines;

    int **arr = new int *[lines];
    for (int i = 0; i < lines; i++) {
        arr[i] = new int[lines];
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < lines; j++) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < i+1; j++) {
            std::cin >> arr[i][j];
        }
    }

    lst(arr, lines);    

    for (int i = 0; i < lines; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}