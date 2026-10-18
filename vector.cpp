#include <iostream>

template<typename T>
class APVector {
    int maxSize;
    int currentSize;
    T *data;

public:

    APVector(int initialSize = 0) : maxSize(initialSize) {
        data = new T[maxSize];
        currentSize = initialSize;

        for (int i = 0; i < initialSize; i++) {
            data[i] = T{};
        }

        std::cout << "Created Vector\n";
    }

    // Copy constructor

    APVector(const APVector &other) : maxSize(other.maxSize), currentSize(other.currentSize), data(new T[other.maxSize]) {
        for (int i = 0; i < other.currentSize; i++) {
            data[i] = other.data[i];
        }

        std::cout << "Copied Vector\n";
    }

    APVector& operator=(const APVector &other) {
        if (this == &other) {
            return *this;
        }

        maxSize = other.maxSize;

        T *pointerToOldData = data;

        data = new T[other.maxSize];
        currentSize = other.currentSize;

        for (int i = 0; i < other.currentSize; i++) {
            data[i] = other.data[i];
        }

        delete[] pointerToOldData;

        std::cout << "Copy Assigned Vector\n";

        return *this;
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

    T &operator[](int index) {
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
        delete[] data;
        data = nullptr;
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


    ~APVector() {
        clear();
    }

    private:
    
    void resize() {
        maxSize = maxSize != 0 ? maxSize * 2 : 1;

        T *newData = new T[maxSize];

        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        std::cout << "Resized Vector\n";
    }
    
    void resize(int newCap) {
        maxSize = newCap;

        T *newData = new T[maxSize];

        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }

        delete[] data;

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

    APVector<int> b = v; // Copy constructor
    APVector<int> c;
    c.push_back(1);

    b = c; // Copy assignment

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << '\n';
    }

    std::cout << '\n';

    for (int i = 0; i < b.size(); i++) {
        std::cout << b[i] << '\n';
    }

    std::cout << '\n';

    for (int i = 0; i < c.size(); i++) {
        std::cout << c[i] << '\n';
    }
}