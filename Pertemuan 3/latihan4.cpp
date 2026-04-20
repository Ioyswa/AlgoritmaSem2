#include <iostream>
using namespace std;

#define MAX 4

class EnemyQueue
{
public:
    int front;
    int rear;
    string enemy[MAX];

    EnemyQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void display()
    {
        cout << "\nQueue State\n";
        cout << "Front : " << front << endl;
        cout << "Rear  : " << rear << endl;

        cout << "Index : ";
        for (int i = 0; i < MAX; i++)
            cout << i << " ";

        cout << "\nData  : ";
        for (int i = 0; i < MAX; i++)
        {
            if (enemy[i] == "")
                cout << "- ";
            else
                cout << enemy[i] << " ";
        }

        cout << "\n\n";
    }

    void enqueue(string e)
    {
        cout << "\nEnqueue -> " << e << endl;

        if ((rear + 1) % MAX == front)
        {
            cout << "Queue penuh\n";
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        enemy[rear] = e;

        display();
    }

    void spawnEnemy()
    {
        cout << "\nSpawn Enemy\n";

        if (isEmpty())
        {
            cout << "Tidak ada enemy\n";
            return;
        }

        cout << "Enemy Spawn: " << enemy[front] << endl;

        front = (front + 1) % MAX;

        display();
    }
};

int main()
{
    EnemyQueue spawn;

    spawn.enqueue("Zombie");
    spawn.enqueue("Goblin");
    spawn.enqueue("Orc");
    spawn.enqueue("Skeleton");

    spawn.spawnEnemy();
    spawn.spawnEnemy();
    spawn.spawnEnemy();

    spawn.enqueue("Dragon");

    spawn.spawnEnemy();
    spawn.spawnEnemy();

    return 0;
}