// Join, Joinable, and detach

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void run(int count) {
    while (count --> 0) {
        cout << "Hello there" << endl;
    }
    std::this_thread::sleep_for(chrono::seconds(3));
}

int main() {
    std::thread t(run, 10);
    cout << "main()" << endl;
    // t.join(); 
    // if (t.joinable()) 
    //     // Used to see that the thread is actually joinable
    //     t.join();
    t.detach();
    cout << "main() after" << endl;
}