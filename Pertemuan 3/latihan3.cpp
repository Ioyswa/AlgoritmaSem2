#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
private:
    int front;
    int rear;
    int data[MAX];

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;

        for (int i = 0; i < MAX; i++)
            data[i] = 0;
    }

    bool isFull()
    {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void debug()
    {
        cout << "\nQueue State\n";
        cout << "Front = " << front << endl;
        cout << "Rear  = " << rear << endl;

        cout << "\nIndex : ";
        for (int i = 0; i < MAX; i++)
            cout << i << " ";

        cout << "\nData  : ";
        for (int i = 0; i < MAX; i++)
            cout << data[i] << " ";

        cout << "\n";
    }

    void enqueue(int value)
    {
        cout << "\nEnqueue -> " << value << endl;

        if (isFull())
        {
            cout << "Queue penuh\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        data[rear] = value;

        debug();
    }

    void dequeue()
    {
        cout << "\nDequeue\n";

        if (isEmpty())
        {
            cout << "Queue kosong\n";
            return;
        }

        cout << "Data keluar: " << data[front] << endl;

        data[front] = 0; // membersihkan slot

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;

        debug();
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue kosong\n";
            return;
        }

        int i = front;

        cout << "\nIsi Queue:\n";

        while (true)
        {
            cout << data[i] << endl;

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();
}