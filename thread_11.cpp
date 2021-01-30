// Future and promise

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>
using namespace std;
using namespace std::chrono;
typedef long int ull;

void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end) {
    ull oddSum = 0;
    for (ull i = start; i <= end; i++) {
        if (i & 1) {
            oddSum += i;
        }
    }
    OddSumPromise.set_value(oddSum);
}

int main() {
    ull start = 0, end = 1900000000;

    std::promise<ull> oddSum;
    std::future<ull> oddFuture = oddSum.get_future();

    cout << "Thread created!!" << endl;

    std::thread t1(findOdd, std::move(oddSum), start, end);

    cout << "Waiting for results" << endl;
    cout << "OddSum : " << oddFuture.get() << endl;
    cout << "Completed" << endl;
    t1.join();
    return 0;
}


