#include <iostream>
#include <vector>

using namespace std;

vector<string> enemy;

void tambah_enemy(string nama_enemy)
{
    enemy.push_back(nama_enemy);
    cout << "Berhasil menambahkan " << nama_enemy << endl;
}

void data_enemy()
{
    if (enemy.size() <= 0)
    {
        cout << "Data Kosong" << endl;
        return;
    }

    cout << "Daftar Enemy:" << endl;
    for (int i = 0; i < enemy.size(); i++)
    {
        cout << i + 1 << ". " << enemy[i] << endl;
    }
}

void hapus_enemy(int index)
{
    if (enemy.empty())
    {
        cout << "Data Kosong" << endl;
        return;
    }

    if (index < 1 || index > enemy.size())
    {
        cout << "Index tidak valid" << endl;
        return;
    }

    enemy.erase(enemy.begin() + (index - 1));
    cout << "Menghapus data ke-" << index << endl;
}

void menu_manager(int choice)
{
    switch (choice)
    {
    case 1:
    {
        cout << "Masukkan Nama Enemy: ";
        string nama_enemy;
        cin >> nama_enemy;
        tambah_enemy(nama_enemy);
        break;
    }

    case 2:
    {
        data_enemy();
        break;
    }

    case 3:
    {
        data_enemy();
        cout << "Pilih Enemy Yang ingin dikalahkan(berdasarkan index): ";
        int index;
        cin >> index;
        hapus_enemy(index);
        break;
    }

    case 4:
    {
        cout << "Jumlah Enemy Aktif: " << enemy.size() << endl;
        break;
    }
    default:
        cout << "Masukkan choice yang benar" << endl;
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "===Enemy Manager===" << endl;
        cout << "1. Tambah Enemy" << endl;
        cout << "2. Tampilkan Enemy" << endl;
        cout << "3. Enemy Dikalahkan" << endl;
        cout << "4. Jumlah Enemy" << endl;
        cout << "5. Keluar" << endl;
        cin >> choice;
        if (choice == 5) break;
        
        menu_manager(choice);
    }
}