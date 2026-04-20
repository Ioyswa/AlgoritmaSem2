#include <iostream>

using namespace std;

struct EnemyData
{
    string enemy_name;
    int enemy_health;
    int enemy_attack;
};

int nama;

struct Node
{
    EnemyData data;
    Node *next;
};

Node *head = nullptr;

int countEnemies()
{
    int count = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void printList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data.enemy_name << " (HP:"
             << temp->data.enemy_health << ", ATK:"
             << temp->data.enemy_attack << ") -> ";
        temp = temp->next;
    }
    cout << "Null\n";
}

void insertBack(const EnemyData &value)
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

void insertFront(const EnemyData &value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAfter(const string &key, const EnemyData &value)
{
    Node *temp = head;

    while (temp != nullptr && temp->data.enemy_name != key)
        temp = temp->next;

    if (temp == nullptr)
        return;

    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(const string &key, const EnemyData &value)
{
    if (head == nullptr)
        return;

    if (head->data.enemy_name == key)
    {
        insertFront(value);
        return;
    }

    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr && curr->data.enemy_name != key)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
        return;

    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = curr;
    prev->next = newNode;
}

void deleteByName(const string &key)
{
    if (head == nullptr)
    {
        cout << "List kosong.\n";
        return;
    }

    if (head->data.enemy_name == key)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Enemy " << key << " dihapus.\n";
        return;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr != nullptr && curr->data.enemy_name != key)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
    {
        cout << "Enemy tidak ditemukan.\n";
        return;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Enemy " << key << " dihapus.\n";
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== Enemy Manager =====\n";
        cout << "1. Spawn Enemy (Insert Back)\n";
        cout << "2. Insert Enemy BEFORE target (by name)\n";
        cout << "3. Kill Enemy (Delete by Name)\n";
        cout << "4. Show Enemy list\n";
        cout << "5. Count Enemies\n";
        cout << "0. Exit\n";
        cout << "Pilih: ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            cout << "======== Spawn Enemy ========\n";

            EnemyData e;
            cout << "Enemy Name: ";
            getline(cin, e.enemy_name);

            cout << "Enemy Health: ";
            cin >> e.enemy_health;

            cout << "Enemy Attack: ";
            cin >> e.enemy_attack;
            cin.ignore();

            insertBack(e);
            break;
        }

        case 2:
        {
            cout << "======== Insert BEFORE ========\n";

            string key;
            cout << "Insert before enemy name: ";
            getline(cin, key);

            EnemyData e;
            cout << "New Enemy Name: ";
            getline(cin, e.enemy_name);

            cout << "Enemy Health: ";
            cin >> e.enemy_health;

            cout << "Enemy Attack: ";
            cin >> e.enemy_attack;
            cin.ignore();

            insertBefore(key, e);
            break;
        }

        case 3:
        {
            cout << "======== Kill Enemy ========\n";
            cout << "List Enemy yang ada" << endl;
            printList();
            string key;
            cout << "Enemy name to delete: ";
            getline(cin, key);

            deleteByName(key);
            break;
        }

        case 4:
            printList();
            break;

        case 5:
            cout << "Total Enemies: " << countEnemies() << endl;
            break;

        case 0:
            cout << "Keluar...\n";
            return 0;

        default:
            cout << "Pilihan tidak valid\n";
        }
    }
}