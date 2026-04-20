#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> data;
    data.push_back(10);
    data.push_back(20);
    data.push_back(30);
    data.push_back(40);
    cout << "Isi vector:\n";
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
    cout << "\nJumlah data: " << data.size() << endl;
    cout << "\nMenghapus data terakhir...\n";
    data.pop_back();
    cout << "\nIsi vector setelah pop_back:\n";
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }
    return 0;
}