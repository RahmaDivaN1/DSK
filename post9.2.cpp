#include <iostream> // Library input/output
using namespace std;

// Deklarasi class ArraySorter
class ArraySorter {
private:
    int data2D[3][3];   // Array 2 dimensi ukuran 3x3
    int data1D[9];      // Array 1 dimensi untuk proses sorting
    int index;          // Variabel bantu index

public:
    // Konstruktor untuk menginisialisasi index ke 0
    ArraySorter() {
        index = 0;
    }

    // Method untuk input array 2D dari user
    void inputArray() {
        cout << "Masukkan elemen array 3x3 (total 9 angka):" << endl;
        for (int i = 0; i < 3; i++) {            // Loop baris
            for (int j = 0; j < 3; j++) {        // Loop kolom
                cin >> data2D[i][j];             // Input elemen ke array 2D
                data1D[index++] = data2D[i][j];  // Simpan juga ke array 1D untuk sorting
            }
        }
    }

    // Method untuk melakukan bubble sort pada array 1D
    void bubbleSort() {
        for (int i = 0; i < 8; i++) {                // Loop untuk pass sebanyak n-1
            for (int j = 0; j < 8 - i; j++) {        // Loop untuk membandingkan elemen
                if (data1D[j] > data1D[j + 1]) {     // Jika elemen kiri > kanan, tukar
                    int temp = data1D[j];           // Simpan sementara
                    data1D[j] = data1D[j + 1];       // Geser ke kiri
                    data1D[j + 1] = temp;           // Simpan nilai temp ke kanan
                }
            }
        }
    }

    // Method untuk mengembalikan array 1D ke bentuk 2D
    void convertTo2D() {
        index = 0;                                  // Reset index
        for (int i = 0; i < 3; i++) {               // Loop baris
            for (int j = 0; j < 3; j++) {           // Loop kolom
                data2D[i][j] = data1D[index++];     // Salin elemen dari array 1D ke 2D
            }
        }
    }

    // Method untuk menampilkan isi array 2D setelah sorting
    void displayArray() {
        cout << "Array setelah diurutkan (3x3):" << endl;
        for (int i = 0; i < 3; i++) {               // Loop baris
            for (int j = 0; j < 3; j++) {           // Loop kolom
                cout << data2D[i][j] << " ";        // Tampilkan elemen
            }
            cout << endl;                           // Ganti baris
        }
    }
};

// Fungsi utama (main)
int main() {
    ArraySorter sorter;         // Membuat objek dari class ArraySorter

    sorter.inputArray();        // Memanggil method untuk input array
    sorter.bubbleSort();        // Memanggil method untuk mengurutkan array 1D
    sorter.convertTo2D();       // Memanggil method untuk konversi ke array 2D
    sorter.displayArray();      // Memanggil method untuk menampilkan array

    return 0;                   // Akhiri program
}
