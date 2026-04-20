#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> nama;
    
    nama.push_back("Andi");
    nama.push_back("Budi");
    nama.push_back("Citra");
    nama.push_back("Dina");

    vector<string>::iterator it = nama.begin();
    cout << *(it + 1) << endl;

    cout << "Data awal:\n";
    for (int i = 0; i < nama.size(); i++)
    {
        cout << nama[i] << endl;
    }
    cout << "\nMenghapus data kedua...\n";
    nama.erase(nama.begin() + 1);
    cout << "\nData setelah dihapus:\n";
    for (int i = 0; i < nama.size(); i++)
    {
        cout << nama[i] << endl;
    }
    return 0;
}