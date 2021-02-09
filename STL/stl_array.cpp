// Syntax: std::array<T, N> array;


// Traditional array: int arr[5], int arr[N]
// Pointer is passed when passed to a function
// Array size is needed at compile time
// Assign by value is actually by value
// Access elements:
// at(), [], front(), back(), fill(), data()
// gives access to underlying array in template

#include<iostream>
#include <array>
using namespace std;

int main() { 
    // Declaration
    std::array<int, 5> myarray;

    // Initialization
    std::array<int, 5> myarray1 = {1, 2, 3, 4, 5}; 
    // std::array<int, 5> myarray2 {1, 2, 3, 4, 5};

    // Assign using initializer list, not in traditional array
    std::array<int, 5> myarray3;
    // myarray3 = {1, 2, 3, 4, 5};
    myarray3.fill(0);

    for (int i = 0; i < myarray3.size(); i++) {
        cout << myarray3.at(i) << endl;
    }

    return 0;
}