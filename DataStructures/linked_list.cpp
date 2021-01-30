#include <iostream>
using namespace std;

struct LinkedList
{
    int data;
    LinkedList *next;
    LinkedList(int data) : data(data) {}
};

void printLinkedList(LinkedList *root) 
{
    while (root) {
        printf("%d ", root->data);
        root = root->next;
    }
}

int main()
{
    LinkedList *root, *second, *third;
    
    root = new LinkedList(10);
    second = new LinkedList(10);
    third = new LinkedList(10);

    // root->data = 10;
    root->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printLinkedList(root);

    return 0;
}