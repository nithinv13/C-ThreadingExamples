#include <iostream>
using namespace std;

char tree[10];
void root(char key) {
    if (tree[1] !='\0') cout  << "Tree already had root";
    else tree[1] = key;
}

void set_left(char key, int parent) {
    if (tree[parent] == '\0') cout << "\nCan't set child at" << (parent*2)+1 << " ' no parent found";
    else tree[parent*2] = key;
}

void set_right(char key, int parent) {
    if (tree[parent] == '\0') cout << "\nCant't set child at" << (parent*2)+2 << " , no parent found";
    else tree[parent*2 + 1] = key; 
}

void print_tree() {
    for (int i = 0; i < 4; i++) {
        if (tree[i] != '\0') cout << tree[i];
        else cout << ".";
    }
}

int main() {
    root('A');
    set_left('B', 1);
    set_right('C', 1);
    print_tree();
    return 0;
}

