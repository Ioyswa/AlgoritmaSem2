#include <iostream>
#include <string>
#include <iomanip>
#define MAX 15

using namespace std;

struct DataNilai {
    string nrp;
    string nama;
    double nilai;
};

DataNilai data[MAX];
int jumlah_data = 0;

void tambah_data(){
    char jawab;
    cout << "Masukkan Data" << endl;
    for (int i = 0; i < MAX; i++){
        cout << "NRP : "; cin >> data[i].nrp;
        cout << "Nama: "; cin >> data[i].nama;
        cout << "Nilai Test: "; cin >> data[i].nilai;
        jumlah_data++;

        cout << "\nAda data lagi?(y/t): ";cin >> jawab;
        if (jawab == 't' || jawab == 'T') break;
        
    }
    cout << "Data telah berhasil dimasukkan / mencapai batas maksimal" << endl;

}


    
void tampil_data() {
    cout << "Data Mahasiswa\n\n";

    cout << left
         << setw(15) << "NRP"
         << setw(25) << "Nama"
         << right
         << setw(10) << "Nilai"
         << endl;

    cout << string(50, '-') << endl;

    for (int i = 0; i < jumlah_data; i++) {
        cout << left
             << setw(15) << data[i].nrp
             << setw(25) << data[i].nama
             << right
             << setw(10) << fixed << setprecision(2) << data[i].nilai
             << endl;
    }
}

int main(){
    tambah_data();
    tampil_data();
}
