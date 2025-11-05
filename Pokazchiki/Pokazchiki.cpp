#include <iostream>
#include <ctime>
using namespace std;

void task1() {
    const int SIZE = 5;
    int arr1[SIZE];
    int arr2[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr1[i] = rand() % 100;
    int* p1 = arr1;
    int* p2 = arr2;
    for (int i = 0; i < SIZE; i++)
        *(p2 + i) = *(p1 + i);
    cout << "Task 1:\nOriginal: ";
    for (int i = 0; i < SIZE; i++)
        cout << arr1[i] << " ";
    cout << "\nCopied:   ";
    for (int i = 0; i < SIZE; i++)
        cout << arr2[i] << " ";
    cout << endl << endl;
}

void task2() {
    const int SIZE = 5;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 100;
    cout << "Task 2:\nOriginal: ";
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    int* left = arr;
    int* right = arr + SIZE - 1;
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
    cout << "\nReversed: ";
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";
    cout << endl << endl;
}

void task3() {
    const int SIZE = 5;
    int arr1[SIZE];
    int arr2[SIZE];
    for (int i = 0; i < SIZE; i++)
        arr1[i] = rand() % 100;
    int* p1 = arr1;
    int* p2 = arr2 + SIZE - 1;
    for (int i = 0; i < SIZE; i++) {
        *p2 = *p1;
        p1++;
        p2--;
    }
    cout << "Task 3:\nOriginal: ";
    for (int i = 0; i < SIZE; i++)
        cout << arr1[i] << " ";
    cout << "\nReversed copy: ";
    for (int i = 0; i < SIZE; i++)
        cout << arr2[i] << " ";
    cout << endl << endl;
}

int main() {
    task1();
    task2();
    task3();
    return 0;
}
