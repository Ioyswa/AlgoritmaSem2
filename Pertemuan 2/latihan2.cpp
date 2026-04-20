#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

void insertFront(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

int main()
{
    Node *node1 = new Node{50, nullptr};
    Node *node2 = new Node{60, nullptr};
    Node *node3 = new Node{70, nullptr};
    
    head = node1;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;
    

    insertFront(30);
    insertFront(20);
    insertFront(10);

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "Null\n";
}

