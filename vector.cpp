#include <iostream>

class APVector {
    private:

    int maxSize;
    int currentSize;
    int *data;

    public:

    APVector(int initialSize = 0, int initialValue = 0) : maxSize(initialSize) {
        data = new int[maxSize];
        currentSize = initialSize;

        for (int i = 0; i < initialSize; i++) {
            data[i] = initialValue;
        }
    }

    void push_back(int value) {
        if (currentSize == maxSize) {
            resize();
        }

        data[currentSize++] = value;
    }

    void pop_back() {
        currentSize--;
    }

    int operator[](int index) {
        if (index < 0 || index >= currentSize) {
            return -1;
        }

        return data[index];
    }

    int size() {
        return currentSize;
    }

    int front() {
        return data[0];
    }

    int back() {
        return data[currentSize - 1];
    }

    // emplace back
    
    void clear() {
        delete data;
        maxSize = 0;
        currentSize = 0;
    }

    // reserve

    void reserve(int newCap) {
        if (newCap > maxSize) {
            resize(newCap);
        }
    }

    // public resize

    // capacity

    private:
    
    void resize() {
        maxSize = maxSize * 2 ? maxSize != 0 : 1;

        int *newData = new int[maxSize];

        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }

        delete data;

        data = newData;
    }
    
    void resize(int newCap) {
        maxSize = newCap;

        int *newData = new int[maxSize];

        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }

        delete data;

        data = newData;
    }
};

int main() {
    APVector v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    v.push_back(4);

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << '\n';
    }
}