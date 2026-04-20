#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node *left;
    Node *right;
};
Node *createNode(char data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    // Membuat node
    Node *A = createNode('A');
    Node *B = createNode('B');
    Node *C = createNode('C');
    // Menghubungkan node
    A->left = B;
    A->right = C;
    // Output
    cout << "Root : " << A->data << endl;
    cout << "Left Child : " << A->left->data << endl;
    cout << "Right Child : " << A->right->data << endl;
    return 0;
}