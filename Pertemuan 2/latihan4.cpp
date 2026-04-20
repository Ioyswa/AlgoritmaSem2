#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

void insertBack(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

void insertFront(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAfter(int key, int value)
{
    Node *temp = head;
    while (temp != nullptr && temp->data != key)
        temp = temp->next;
    if (temp == nullptr)
        return;
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertBefore(int key, int value)
{
    if (head == nullptr)
        return;
    if (head->data == key)
    {
        insertFront(value);
        return;
    }
    Node *prev = nullptr;
    Node *curr = head;
    while (curr != nullptr && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr)
        return;
    Node *newNode = new Node;
    newNode->data = value;
    prev->next = newNode;
    newNode->next = curr;
}

int main()
{
    Node *node1 = new Node{50, nullptr};
    Node *node2 = new Node{60, nullptr};
    Node *node3 = new Node{70, nullptr};

    head = node1;

    node1->next = node2;
    node2->next = node3;

    insertFront(30);
    insertFront(20);
    insertFront(10);

    insertBack(80);
    insertAfter(30, 40);
    insertBefore(60, 55);

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "Null\n";
}
