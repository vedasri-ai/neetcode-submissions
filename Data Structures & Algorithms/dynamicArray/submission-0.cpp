#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    // Constructor
    DynamicArray(int capacity) {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    // Get element at index i
    int get(int i) {
        return arr[i];
    }

    // Set element at index i
    void set(int i, int n) {
        arr[i] = n;
    }

    // Double the capacity
    void resize() {
        capacity *= 2;

        int* newArr = new int[capacity];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    // Add element at end
    void pushback(int n) {
        if (size == capacity) {
            resize();
        }

        arr[size] = n;
        size++;
    }

    // Remove and return last element
    int popback() {
        int val = arr[size - 1];
        size--;
        return val;
    }

    // Return current size
    int getSize() {
        return size;
    }

    // Return current capacity
    int getCapacity() {
        return capacity;
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }
};