#include <iostream>
#include <stack>

using namespace std;
stack<string> AksiTerakhir;

void tambah_aksi(string nama_aksi)
{
    AksiTerakhir.push(nama_aksi);
    cout << "Berhasil Menambahkan " << nama_aksi << endl;
}

void history_aksi(stack<string> a)
{
    int index = a.size() + 1;
    while (!a.empty())
    {
        index--;
        cout << index << ". " << a.top() << endl;
        a.pop();
    }
}

void undo_aksi()
{
    if (AksiTerakhir.empty())
        return;

    cout << "Berhasil Undo " << AksiTerakhir.top() << endl;
    AksiTerakhir.pop();
}

int main()
{
    string aksi;
    int choice;
    bool running = true;
    while (running)
    {
        cout << "== Undo System (Stack) ==" << endl;
        cout << "1. Tambah Aksi" << endl;
        cout << "2. Undo Aksi" << endl;
        cout << "3. Tampilkan History" << endl;
        cout << "4. Keluar" << endl;

        cout << "Pilih: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Masukkan Aksi: ";
            cin >> aksi;
            tambah_aksi(aksi);
            break;
        case 2:
            undo_aksi();
            break;

        case 3:
            history_aksi(AksiTerakhir);
            break;

        case 4:
            running = false;
            break;
        }
    }
}