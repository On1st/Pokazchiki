#include <iostream>
#include <ctime>
using namespace std;

int* allocate(int size) {
    return new int[size];
}

void initialize(int* arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 41 - 20;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void deallocate(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

void addElement(int*& arr, int& size, int value) {
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
    newArr[size] = value;
    delete[] arr;
    arr = newArr;
    size++;
}

void insertElement(int*& arr, int& size, int index, int value) {
    if (index < 0 || index > size) return;
    int* newArr = new int[size + 1];
    for (int i = 0; i < index; i++)
        newArr[i] = arr[i];
    newArr[index] = value;
    for (int i = index; i < size; i++)
        newArr[i + 1] = arr[i];
    delete[] arr;
    arr = newArr;
    size++;
}

void removeElement(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) return;
    int* newArr = new int[size - 1];
    for (int i = 0, j = 0; i < size; i++)
        if (i != index)
            newArr[j++] = arr[i];
    delete[] arr;
    arr = newArr;
    size--;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int* removePrimes(int* arr, int& size) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (!isPrime(arr[i]))
            count++;
    int* newArr = new int[count];
    for (int i = 0, j = 0; i < size; i++)
        if (!isPrime(arr[i]))
            newArr[j++] = arr[i];
    size = count;
    return newArr;
}

void splitArray(int* arr, int size, int*& positives, int& posSize, int*& negatives, int& negSize, int*& zeros, int& zeroSize) {
    posSize = negSize = zeroSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) posSize++;
        else if (arr[i] < 0) negSize++;
        else zeroSize++;
    }
    positives = new int[posSize];
    negatives = new int[negSize];
    zeros = new int[zeroSize];
    int p = 0, n = 0, z = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) positives[p++] = arr[i];
        else if (arr[i] < 0) negatives[n++] = arr[i];
        else zeros[z++] = arr[i];
    }
}

int main() {
    srand(time(0));

    int size = 5;
    int* arr = allocate(size);
    initialize(arr, size);

    cout << "Task 1\nOriginal array: ";
    printArray(arr, size);

    addElement(arr, size, 10);
    cout << "After add: ";
    printArray(arr, size);

    insertElement(arr, size, 2, 99);
    cout << "After insert: ";
    printArray(arr, size);

    removeElement(arr, size, 1);
    cout << "After remove: ";
    printArray(arr, size);

    int newSize = size;
    int* noPrimes = removePrimes(arr, newSize);
    cout << "\nTask 2\nWithout primes: ";
    printArray(noPrimes, newSize);

    int staticArr[10];
    for (int i = 0; i < 10; i++)
        staticArr[i] = rand() % 11 - 5;

    int* pos, * neg, * zero;
    int ps, ns, zs;
    splitArray(staticArr, 10, pos, ps, neg, ns, zero, zs);

    cout << "\nTask 3\nOriginal static array: ";
    printArray(staticArr, 10);
    cout << "Positives: ";
    printArray(pos, ps);
    cout << "Negatives: ";
    printArray(neg, ns);
    cout << "Zeros: ";
    printArray(zero, zs);

    deallocate(arr);
    deallocate(noPrimes);
    deallocate(pos);
    deallocate(neg);
    deallocate(zero);

    return 0;
}

