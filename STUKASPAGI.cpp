#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Konstanta
const int MAKS_PRODUK = 100;     // Maksimal jumlah produk
const int JUMLAH_GUDANG = 3;     // Jumlah gudang

// Kelas Inventaris
class Inventaris {
private:
    string namaProduk[MAKS_PRODUK];           // Menyimpan nama-nama produk
    int stok[MAKS_PRODUK][JUMLAH_GUDANG];     // Menyimpan stok tiap produk per gudang
    double harga[MAKS_PRODUK][JUMLAH_GUDANG]; // Menyimpan harga per unit tiap produk per gudang
    int jumlahProduk;                         // Jumlah produk yang telah ditambahkan

public:
    // Konstruktor untuk inisialisasi
    Inventaris() {
        jumlahProduk = 0;
        for (int i = 0; i < MAKS_PRODUK; i++) {
            for (int j = 0; j < JUMLAH_GUDANG; j++) {
                stok[i][j] = 0;
                harga[i][j] = 0.0;
            }
        }
    }

    // Tambah produk baru
    void tambahProduk() {
        if (jumlahProduk >= MAKS_PRODUK) {
            cout << "Jumlah maksimum produk tercapai!" << endl;
            return;
        }
        cout << "Masukkan nama produk baru: ";
        cin.ignore();
        getline(cin, namaProduk[jumlahProduk]);
        cout << "Produk '" << namaProduk[jumlahProduk] << "' berhasil ditambahkan.\n";
        jumlahProduk++;
    }

    // Perbarui stok atau harga
    void perbaruiInventaris() {
        int idGudang, idProduk;
        char pilihan;
        double nilaiBaru;

        cout << "Pilih Gudang (0-" << JUMLAH_GUDANG - 1 << "): ";
        cin >> idGudang;
        cout << "Pilih Produk (0-" << jumlahProduk - 1 << "): ";
        cin >> idProduk;
        cout << namaProduk[idProduk] << endl;

        cout << "Apa yang ingin Anda perbarui? (S)tok atau (H)arga? ";
        cin >> pilihan;
        cout << "Masukkan nilai baru: ";
        cin >> nilaiBaru;

        if (pilihan == 'S' || pilihan == 's') {
            stok[idProduk][idGudang] = static_cast<int>(nilaiBaru);
            cout << "Stok produk '" << namaProduk[idProduk] << "' di Gudang " << idGudang
                 << " diperbarui menjadi " << stok[idProduk][idGudang] << endl;
        } else if (pilihan == 'H' || pilihan == 'h') {
            harga[idProduk][idGudang] = nilaiBaru;
            cout << "Harga produk '" << namaProduk[idProduk] << "' di Gudang " << idGudang
                 << " diperbarui menjadi " << harga[idProduk][idGudang] << endl;
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    }

    // Tampilkan semua inventaris dalam format tabel
    void tampilkanInventaris() {
        cout << left << setw(15) << "Produk";
        for (int g = 0; g < JUMLAH_GUDANG; g++) {
            cout << "G" << g << " Stok" << setw(8) << " " << "G" << g << " Harga" << setw(8) << " ";
        }
        cout << endl;

        for (int i = 0; i < jumlahProduk; i++) {
            cout << left << setw(15) << namaProduk[i];
            for (int j = 0; j < JUMLAH_GUDANG; j++) {
                cout << setw(10) << stok[i][j] << setw(12) << fixed << setprecision(2) << harga[i][j];
            }
            cout << endl;
        }
    }

    // Hitung dan tampilkan total nilai per gudang
    void totalNilaiPerGudang() {
        for (int g = 0; g < JUMLAH_GUDANG; g++) {
            double total = 0;
            for (int i = 0; i < jumlahProduk; i++) {
                total += stok[i][g] * harga[i][g];
            }
            cout << "Total nilai inventaris di Gudang " << g << " = Rp " << fixed << setprecision(2) << total << endl;
        }
    }

    // Hitung dan tampilkan total nilai keseluruhan
    void totalNilaiKeseluruhan() {
        double total = 0;
        for (int g = 0; g < JUMLAH_GUDANG; g++) {
            for (int i = 0; i < jumlahProduk; i++) {
                total += stok[i][g] * harga[i][g];
            }
        }
        cout << "Total nilai inventaris keseluruhan = Rp " << fixed << setprecision(2) << total << endl;
    }
};

// Fungsi utama
int main() {
    Inventaris sistem;      // Buat objek sistem inventaris
    int pilihan;            // Menyimpan pilihan menu

    do {
        // Menu utama
        cout << "\n--- Menu Manajemen Inventaris ---\n";
        cout << "1. Tambah Produk Baru\n";
        cout << "2. Perbarui Stok/Harga Inventaris\n";
        cout << "3. Tampilkan Semua Inventaris\n";
        cout << "4. Hitung Total Nilai Inventaris per Gudang\n";
        cout << "5. Hitung Total Nilai Inventaris Keseluruhan\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                sistem.tambahProduk();
                break;
            case 2:
                sistem.perbaruiInventaris();
                break;
            case 3:
                sistem.tampilkanInventaris();
                break;
            case 4:
                sistem.totalNilaiPerGudang();
                break;
            case 5:
                sistem.totalNilaiKeseluruhan();
                break;
            case 6:
                cout << "Terima kasih. Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 6);

    return 0;
}
