#include <iostream>
using namespace std;

#define MAX 5

class Stack
{
private:
    int top;
    string data[MAX];

public:
    Stack()
    {
        top = -1;
    }

    bool isFull()
    {
        return top == MAX - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(string item)
    {
        cout << "\nPush -> " << item << endl;

        if (isFull())
        {
            cout << "Inventory penuh!\n";
            return;
        }

        top++;
        data[top] = item;

        debug();
    }

    void pop()
    {
        cout << "\nPop\n";

        if (isEmpty())
        {
            cout << "Inventory kosong!\n";
            return;
        }

        cout << "Item digunakan: " << data[top] << endl;
        top--;

        debug();
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Inventory kosong\n";
            return;
        }

        cout << "Item terakhir: " << data[top] << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Inventory kosong\n";
            return;
        }

        cout << "\nIsi Inventory (Top -> Bottom):\n";

        for (int i = top; i >= 0; i--)
        {
            cout << data[i] << endl;
        }
    }

    void debug()
    {
        cout << "\nVisual Stack\n";
        cout << "TOP index = " << top << "\n\n";

        for (int i = MAX - 1; i >= 0; i--)
        {
            cout << "+---------+\n";

            if (i == top && !isEmpty())
                cout << "| " << data[i] << " |  <-- TOP\n";
            else if (i <= top)
                cout << "| " << data[i] << " |\n";
            else
                cout << "|         |\n";
        }

        cout << "+---------+\n\n";
    }
};

int main()
{
    Stack inventory;

    inventory.push("Potion");
    inventory.push("Sword");
    inventory.push("Shield");

    inventory.display();

    inventory.pop();

    inventory.display();

    return 0;
}