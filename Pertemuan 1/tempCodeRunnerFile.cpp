#include <iostream>
#include <iomanip>

using namespace std;

struct Inventory{
    string item_name;
    int item_quantity;
    int item_price;
};

struct Player {
    string player_name;
    int player_level;
    Inventory player_inventory[5];
    int inventory_size;
};

void input_item(Player& p) {
    
    cout << "Masukan Jumlah Item (Max 5): ";
    cin >> p.inventory_size;

    if (p.inventory_size > 5) p.inventory_size = 5;

    cout << "Input 5 item (nama, qty, harga)" << endl;

    for (int i = 0; i < p.inventory_size; i++){
        cout << "Item ke-" << i + 1 << " nama : "; cin >> p.player_inventory[i].item_name;
        cout << "Item ke-" << i + 1 << " qty : "; cin >> p.player_inventory[i].item_quantity;
        cout << "Item ke-" << i + 1 << " harga : "; cin >> p.player_inventory[i].item_price; cout << endl;
    }

    cout << "Item berhasil dimasukkan " << endl;
    
}

#include <iomanip>
#include <limits>

void output_inventory(const Player& p) {
    cout << "Selamat datang, " << p.player_name << endl;
    cout << "\nInventory\n\n";

    cout << left
         << setw(20) << "Nama Item"
         << right
         << setw(8)  << "Qty"
         << setw(10) << "Harga"
         << setw(10) << "Nilai"
         << endl;

    cout << string(48, '-') << endl;

    int total_nilai = 0;
    int max_nilai = numeric_limits<int>::min();
    int index_max = -1;

    for (int i = 0; i < p.inventory_size; i++) {
        int nilai = p.player_inventory[i].item_quantity *
                    p.player_inventory[i].item_price;

        total_nilai += nilai;

        if (nilai > max_nilai) {
            max_nilai = nilai;
            index_max = i;
        }

        cout << left
             << setw(20) << p.player_inventory[i].item_name
             << right
             << setw(8)  << p.player_inventory[i].item_quantity
             << setw(10) << p.player_inventory[i].item_price
             << setw(10) << nilai
             << endl;
    }

    cout << string(48, '-') << endl;


    cout << left
         << setw(38) << "Total Nilai Inventory"
         << right
         << setw(10) << total_nilai
         << endl;

    if (index_max != -1) {
        cout << "\nItem dengan nilai terbesar:\n";
        cout << "Nama  : " << p.player_inventory[index_max].item_name << endl;
        cout << "Qty   : " << p.player_inventory[index_max].item_quantity << endl;
        cout << "Harga : " << p.player_inventory[index_max].item_price << endl;
        cout << "Nilai : " << max_nilai << endl;
    }
}

int main() {
    Player player;
    player.player_name = "Test";
    player.player_level = 1;

    input_item(player);
    output_inventory(player);
}