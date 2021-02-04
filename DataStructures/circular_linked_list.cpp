// How to make a single linked list work like a double linked list
// Uses
// CPU scheduling
// 

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node * next;
};

struct Node * addToEmpty(struct Node *last, int data) {
    if (last != NULL) return last;

    // C style memory allocation 
    // struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    // CPP style memory allocation
    struct Node *temp = new Node();

    temp->data = data;
    last = temp;
    last->next = last;
    return last;
}

struct Node *addEnd(struct Node* last, int data) {
    if (last == NULL) {
        return addToEmpty(last, data);
    }

    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;
    return last;
}

void traverse(struct Node *first) {
    struct Node *tmp = first;

    if (first != NULL) {
        do {
            cout << tmp->data << " ";
            tmp = tmp->next;
        } while (tmp != first);
    }
}

int main() {
    struct Node *last = NULL;
    last = addToEmpty(last, 6);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    traverse(last->next);
    return 0;
}