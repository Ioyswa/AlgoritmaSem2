#include <iostream>
#include <vector>

using namespace std;

#define MAX 5

class CircularQueue
{
private:
    int front;
    int rear;
    string data[MAX];

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;

        for (int i = 0; i < MAX; i++)
            data[i] = "";
    }

    bool isFull()
    {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(string value)
    {
        cout << value << " Masuk Antrean" << endl;

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
    }

    void dequeue()
    {

        if (isEmpty())
        {
            cout << "Queue kosong\n";
            return;
        }

        cout << data[front] << " Dipanggil" << endl;

        data[front] = "";

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue kosong\n";
            return;
        }

        int i = front;

        cout << "\nIsi Antrean:\n";

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
    CircularQueue AntreanMatchmaking;
    string nama_pemain;
    int choice;
    bool running = true;
    while (running)
    {
        cout << "== Matchmaking Queue ==" << endl;
        cout << "1. Tambah Pemain" << endl;
        cout << "2. Panggil Pemain" << endl;
        cout << "3. Tampilkan Antrean" << endl;
        cout << "4. Keluar" << endl;

        cout << "Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Masukkan Pemain: ";
            cin >> nama_pemain;
            AntreanMatchmaking.enqueue(nama_pemain);
            break;
        case 2:
            AntreanMatchmaking.dequeue();
            break;

        case 3:
            AntreanMatchmaking.display();
            break;

        case 4:
            running = false;
            break;
        }
    }
}