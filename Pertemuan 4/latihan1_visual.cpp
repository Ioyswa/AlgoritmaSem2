#include <iostream>
#include <vector>
#include <thread>   // untuk sleep
#include <chrono>   // untuk delay
using namespace std;

// Fungsi untuk menampilkan isi vector secara visual
void printVector(const vector<int>& data)
{
    cout << "\n=== Kondisi Vector ===\n";
    cout << "Size  : " << data.size() << endl;

    cout << "Index : ";
    for (int i = 0; i < data.size(); i++)
        cout << "[" << i << "] ";
    cout << endl;

    cout << "Data  : ";
    for (int i = 0; i < data.size(); i++)
        cout << " " << data[i] << "  ";
    cout << endl;
}

// Fungsi delay (biar terlihat step-by-step)
void pause()
{
    chrono::seconds(1);
}

int main()
{
    vector<int> data;

    cout << "Program Visualisasi Vector\n";
    pause();

    // Step 1
    cout << "\n[STEP 1] push_back(10)";
    data.push_back(10);
    printVector(data);
    pause();

    // Step 2
    cout << "\n[STEP 2] push_back(20)";
    data.push_back(20);
    printVector(data);
    pause();

    // Step 3
    cout << "\n[STEP 3] push_back(30)";
    data.push_back(30);
    printVector(data);
    pause();

    // Step 4
    cout << "\n[STEP 4] push_back(40)";
    data.push_back(40);
    printVector(data);
    pause();

    // Step 5
    cout << "\n[STEP 5] Menampilkan isi vector:";
    cout << "\nIsi vector:\n";
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
    cout << "Jumlah data: " << data.size() << endl;
    pause();

    // Step 6
    cout << "\n[STEP 6] pop_back() -> menghapus elemen terakhir";
    data.pop_back();
    printVector(data);
    pause();

    // Step 7
    cout << "\n[STEP 7] Isi vector setelah pop_back:\n";
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }

    cout << "\nProgram selesai.\n";
    return 0;
}