#include <iostream>
using namespace std;

struct Binary {
    int data;
    Binary *left, *right;
    Binary(int data): data(data), left(nullptr), right(nullptr) {}
};

void print_bfs(Binary *root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    print_bfs(root->left);
    print_bfs(root->right);
}

int main() {
    Binary *root = new Binary(1);
    Binary *left = new Binary(2);
    Binary *right = new Binary(3);

    root->left = left;
    root->right = right;

    print_bfs(root);
    return 0;
}