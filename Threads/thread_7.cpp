#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::recursive_mutex m1;
int buffer = 0;

void recursive(char c, int loopFor) {
    if (loopFor < 0) {
        return;
    }
    m1.lock();
    cout << c << " " << buffer++ << endl;
    recursive(c, --loopFor);
    m1.unlock();
}

int main() {
    thread t1(recursive, '0', 10);
    thread t2(recursive, '1', 10);
    t1.join();
    t2.join();
    return 0;
}

// int main() {
//     for (int i=0; i<5; i++) {
//         m1.lock();
//         cout << "locked " << i << endl;
//     }

//     for (int i=0; i<5; i++) {
//         m1.unlock();
//         cout << "unlocked " << i << endl;
//     }
// }