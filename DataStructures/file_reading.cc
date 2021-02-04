#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream f("");
    string str;
    if (f) {
        ostringstream ss;
        ss << f.rdbuf();
        str = ss.str();
    }
    cout << str;
}