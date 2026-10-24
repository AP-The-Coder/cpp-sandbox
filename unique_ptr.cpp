#include <iostream>


class APunique_ptr {

public:
    int *new_unique_ptr;

    APunique_ptr(int ptr) {
        new_unique_ptr = new int;
        *new_unique_ptr = ptr;
    }

    ~APunique_ptr() {
        delete new_unique_ptr;
    }

    int operator*() {
        return *new_unique_ptr;
    }

    // move semantics for ownership transfer - btw what happens if u try pass into function and u dont hv this

    // Ownership moved?
    APunique_ptr(APunique_ptr&& other) : new_unique_ptr(other.new_unique_ptr) {
        other.new_unique_ptr = nullptr;

        std::cout << "Unique_ptr : Move Constructed!";
    }

    // Learn more about this, i still dont really understand the move assignment operator, mainly why the return type is a reference
    // why we return a dereferences pointer, and how this == &other works, and also how do we acutally call this, we do it using std::move
    // but i wanna be more familiar with whats happening
    // APunique_ptr& operator=(APunique_ptr&& other) {
    //     if (this == &other) {
    //         return;
    //     }

    //     if (new_unique_ptr != nullptr) {
    //         delete new_unique_ptr;
    //     }

    //     new_unique_ptr = other.new_unique_ptr;
    //     other.new_unique_ptr = nullptr;

    //     std::cout << "Unique_ptr : Move assigned!";

    //     return *this;
    // }

    APunique_ptr(const APunique_ptr& other) = delete;
    void operator=(const APunique_ptr& other) = delete;    
};

APunique_ptr make_unique(int ptr) {
    return APunique_ptr(ptr);
}

int main() {
    APunique_ptr myPtr = make_unique(9);

    std::cout << *myPtr;
}

// LEARN A BIT MORE ABOUT WHAT HAPPENS WHEN U PASS IT IN AS A R VALUE REFERENCE RATHER THAN JUST A REFERENCE, CONST REFERENCE OR BY VALUE.
// LEARN WHAT NO EXCEPT IS ASW