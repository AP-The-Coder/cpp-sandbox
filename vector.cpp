#include <iostream>

template<typename T>
class APVector {
    private:

    int maxSize;
    int currentSize;
    int *data;

    public:

    APVector(int initialSize = 0) : maxSize(initialSize) {
        data = new T[maxSize];
        currentSize = initialSize;

        for (int i = 0; i < initialSize; i++) {
            data[i] = T{};
        }

        std::cout << "Created Vector\n";
    }

    void push_back(T value) {
        if (currentSize == maxSize) {
            resize();
        }

        data[currentSize++] = value;
    }

    void pop_back() {
        currentSize--;
    }

    T operator[](int index) {
        if (index < 0 || index >= currentSize) {
            return -1;
        }

        return data[index];
    }

    int size() {
        return currentSize;
    }

    T front() {
        return data[0];
    }

    T back() {
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

        T *newData = new T[maxSize];

        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }

        delete data;

        data = newData;
        std::cout << "Resized Vector\n";
    }
    
    void resize(int newCap) {
        maxSize = newCap;

        T *newData = new T[maxSize];

        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }

        delete data;

        data = newData;
        std::cout << "Resized Vector\n";
    }
};

int main() {
    APVector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();
    v.push_back(4);

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << '\n';
    }
}