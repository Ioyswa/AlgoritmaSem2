#include <iostream>
#include <vector>
using namespace std;
// =====================
// STRUCT NODE
// =====================
struct Node
{
    string data;
    vector<Node *> children;
};
// =====================
// CREATE NODE
// =====================
Node *createNode(string data)
{
    Node *node = new Node();
    node->data = data;
    return node;
}
// =====================
// TAMBAH CHILD
// =====================
void addChild(Node *parent, Node *child)
{
    parent->children.push_back(child);
}
// =====================
// TAMPILKAN TREE (RECURSIVE)
// =====================
void printTree(Node *root, int level = 0)
{
    if (root == NULL)
        return;
    // indentasi biar terlihat tree
    for (int i = 0; i < level; i++)
    {
        cout << "--";
    }
    cout << root->data << endl;
    // tampilkan semua child
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i], level + 1);
    }
}
// =====================
// MAIN
// =====================
int main()
{
    // root
    Node *fire = createNode("Fire");
    // child
    Node *fireball = createNode("Fireball");
    Node *flame = createNode("Flame Burst");
    Node *meteor = createNode("Meteor");
    // hubungan
    addChild(fire, fireball);
    addChild(fire, flame);
    addChild(fire, meteor);
    // tampilkan tree
    cout << "Skill Tree:\n";
    printTree(fire);
    return 0;
}