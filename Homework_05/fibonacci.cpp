#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

int naive_recursive(int n) {
    if (n < 2) {
        return n;
    }
    else {
        return naive_recursive(n-1) + naive_recursive(n-2);
    }
}

int bottom_up(int n) {
    int f0 = 0;
    int f1 = 1;

    if (n == f0) {
        return f0;
    }
    if (n == f1) {
        return f1;
    }

    int fn = 0;
    for (int i = 1; i < n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }

    return fn;
};

int closed_form(int n) {
    double phi = (1 + sqrt(5))/2.0;
    double fn = pow(phi,n)/sqrt(5);
    return round(fn);
}

void multiply(int matrixA[2][2], int matrixB[2][2]) {
    int a = matrixA[0][0]*matrixB[0][0] + matrixA[0][1]*matrixB[1][0];
    int b = matrixA[0][0]*matrixB[0][1] + matrixA[0][1]*matrixB[1][1];
    int c = matrixA[1][0]*matrixB[0][0] + matrixA[1][1]*matrixB[1][0];
    int d = matrixA[1][0]*matrixB[0][1] + matrixA[1][1]*matrixB[1][1];
    matrixA[0][0] = a;
    matrixA[0][1] = b;
    matrixA[1][0] = c;
    matrixA[1][1] = d;
}

void power(int matrix[2][2], int n) {
    if (n == 0 || n == 1) {
        return;
    }

    int matrixB[2][2] = {{1,1},{1,0}};
    power(matrix, n / 2);
    multiply(matrix, matrix);

    if (n % 2 != 0) {
        multiply(matrix, matrixB);
    }
}

int matrix_representation(int n) {
    int matrix[2][2] = {{1,1},{1,0}};
    if (n == 0) {
        return 0;
    }
    power(matrix, n - 1);

    return matrix[0][0];
}

int main() {
    int n = 1000;
    int timeLimit = 10;

    ofstream file("computations.txt");

    vector<int> naiveTimes;
    vector<int> bottomTimes;
    vector<int> closedTimes;
    vector<int> matrixTimes;

    cout << "Measuring naive recursion..." << endl;
    for (int i = 0; i < 40; i++) {
        auto start = high_resolution_clock::now();
        naive_recursive(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        if (duration.count() < timeLimit) {
            naiveTimes.push_back(duration.count());
        }
        else {
            naiveTimes.push_back(-1);
        }
    }
    cout << "Times: ";
    for (auto time : naiveTimes) {
        cout << time << ", ";
        file << time << " ";
    }
    cout << endl;
    file << endl;

    cout << "Measuring bottom up..." << endl;
    for (int i = 0; i < n; i++) {
        auto start = high_resolution_clock::now();
        bottom_up(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        if (duration.count() < timeLimit) {
            bottomTimes.push_back(duration.count());
        }
        else {
            bottomTimes.push_back(-1);
        }
    }
    cout << "Times: ";
    for (auto time : bottomTimes) {
        cout << time << ", ";
        file << time << " ";
    }
    cout << endl;
    file << endl;

    cout << "Measuring closed form.." << endl;
    for (int i = 0; i < n; i++) {
        auto start = high_resolution_clock::now();
        closed_form(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        if (duration.count() < timeLimit) {
            closedTimes.push_back(duration.count());
        }
        else {
            closedTimes.push_back(-1);
        }
    }
    cout << "Times: ";
    for (auto time : closedTimes) {
        cout << time << ", ";
        file << time << " ";
    }
    cout << endl;
    file << endl;

    cout << "Measuring matrix representation..." << endl;
    for (int i = 0; i < n; i++) {
        auto start = high_resolution_clock::now();
        matrix_representation(i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        if (duration.count() < timeLimit) {
            matrixTimes.push_back(duration.count());
        }
        else {
            matrixTimes.push_back(-1);
        }
    }
    cout << "Times: ";
    for (auto time : matrixTimes) {
        cout << time << ", ";
        file << time << " ";
    }
    cout << endl;
    file << endl;

    file.close();

    return 0;
}