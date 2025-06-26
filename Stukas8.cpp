#include <iostream>
#include <iomanip>
using namespace std;

// Kelas Mahasiswa
class Mahasiswa {
private:
    string nama;
    float bindo, ipa, matematika;
    float rata_rata;

public:
    // Method untuk input data mahasiswa
    void input(int nomor) {
        cout << "Masukkan data Mahasiswa ke-" << nomor << endl;
        cout << "Nama           : ";
        cin.ignore(); // Menghindari masalah getline setelah input sebelumnya
        getline(cin, nama);
        cout << "Bahasa Indonesia : ";
        cin >> bindo;
        cout << "IPA              : ";
        cin >> ipa;
        cout << "Matematika       : ";
        cin >> matematika;

        // Hitung rata-rata
        rata_rata = (bindo + ipa + matematika) / 3.0;
        cout << endl;
    }

    // Method untuk menampilkan data dalam tabel
    void tampilkan(int no) {
        cout << setw(4) << no
             << setw(20) << nama
             << setw(10) << bindo
             << setw(10) << ipa
             << setw(12) << matematika
             << setw(12) << fixed << setprecision(2) << rata_rata << endl;
    }
};

int main() {
    const int jumlahMahasiswa = 4;
    Mahasiswa mhs[jumlahMahasiswa];

    // Input data untuk setiap mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {
        mhs[i].input(i + 1);
    }

    // Tampilkan tabel hasil
    cout << "\n---------------------------------------------------------------" << endl;
    cout << setw(4) << "No"
         << setw(20) << "Nama"
         << setw(10) << "B. Indo"
         << setw(10) << "IPA"
         << setw(12) << "Matematika"
         << setw(12) << "Rata-rata" << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        mhs[i].tampilkan(i + 1);
    }

    cout << "---------------------------------------------------------------" << endl;
    return 0;
}
