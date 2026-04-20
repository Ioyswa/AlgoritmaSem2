#include <iostream>
using namespace std;

#define MAX 10

class Stack
{
private:
    int top;
    string command[MAX];

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(string cmd)
    {
        cout << "\nPlayer Action -> " << cmd << endl;

        if (top == MAX - 1)
        {
            cout << "Command penuh\n";
            return;
        }

        top++;
        command[top] = cmd;

        debug();
    }

    void undo()
    {
        cout << "\nUNDO COMMAND\n";

        if (isEmpty())
        {
            cout << "Tidak ada command untuk undo\n";
            return;
        }

        cout << "Undo command: " << command[top] << endl;

        top--;

        debug();
    }

    void show()
    {
        if (isEmpty())
        {
            cout << "History kosong\n";
            return;
        }

        cout << "\nHistory Command (Top -> Bottom)\n";

        for (int i = top; i >= 0; i--)
        {
            cout << command[i] << endl;
        }
    }

    void debug()
    {
        cout << "\nVisual Command Stack\n";
        cout << "TOP index = " << top << "\n\n";

        for (int i = MAX - 1; i >= 0; i--)
        {
            cout << "+----------------+\n";

            if (i == top && !isEmpty())
                cout << "| " << command[i] << " |  <-- TOP\n";
            else if (i <= top)
                cout << "| " << command[i] << " |\n";
            else
                cout << "|                |\n";
        }

        cout << "+----------------+\n";
    }
};

int main()
{
    Stack action;

    action.push("Move Forward");
    action.push("Jump");
    action.push("Shoot");

    action.show();

    action.undo();

    action.show();

    return 0;
}