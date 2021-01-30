// Types of thread creation

// 1. Function pointer
// Thread ordering is not guaranteed

#include <iostream>
#include <thread>
using namespace std;

// void fun(int x) {
//     while (x-- > 0) {
//         cout << x << endl;
//     }
// }

// int main() {

//     std::thread t1(fun, 11);
//     t1.join();
//     return 0;
// }

// int main() {

//     // Lambda function example
//     // Can directly inject lambea at thread creation time
//     auto fun = [](int x) {
//         while (x-- > 0) {
//             cout << x << endl;
//         }
//     };

//     std::thread t1(fun, 11);
//     t1.join();
//     return 0;
// }

// 3. Using Functor (Function object)
// class Base {
//     public:
//     void operator () (int x) {
//         while (x-- > 0) {
//             cout << x << endl;
//         }
//     }
// };

// int main() {
//     std::thread t(Base(), 10);
//     t.join();
//     return 0;
// }


// 4. Non static member function
// class Base {
//     public:
//         void run(int x) {
//             while (x-- > 0) {
//                 cout << x << endl;
//             }
//         }
// };

// int main() {
//     Base b;
//     std::thread t(&Base::run, &b, 10);
//     t.join();
//     return 0;
// }

// 5. Static member function
class Base {
    public:
        static void run(int x) {
            while (x-- > 0) {
                cout << x << endl;
            }
        }
};

int main() {
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}