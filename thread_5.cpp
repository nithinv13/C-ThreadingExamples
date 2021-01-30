// mutex try_lock, non blocking lock which returns immediately

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
std::mutex mtx;

void incrementCounterFor10000times() {
    for (int i = 0; i < 10000; i++) {
        if (mtx.try_lock()) {
            counter += 1;
            mtx.unlock();
        }
    }
}

int main() {
    std::thread t1(incrementCounterFor10000times);
    std::thread t2(incrementCounterFor10000times);

    t1.join();
    t2.join();

    cout << "Counter could increment upto " << counter << endl;
}