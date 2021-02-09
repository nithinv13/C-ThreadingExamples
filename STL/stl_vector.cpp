// std::vector also called dynamic array or array list
// Array size is increased on push_back if no space is left

// std::vector<T> vec;

// Element access
// at(), [], front(), back(), data()

// Modifiers
// insert(), emplace(), push_back(), emplace_back()
// pop_back(), resize(), swap(), erase(), clear()
// size(), capacity()

#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Declearations
    std::vector<int> arr1;
    std::vector<int> arr2 (5, 10);
    std::vector<int> arr3 = {1, 2, 3, 4, 5}; 
    std::vector<int> arr4 {1, 2, 3, 4, 5};

    // Accessing elements
    arr2[3] = 0;
    arr2.at(3) = 10;

    return 0;
}
