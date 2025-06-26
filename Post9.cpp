#include <iostream>
using namespace std;

// Fungsi untuk melakukan bubble sort pada array 1D
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {               // Loop luar untuk setiap pass
        for (int j = 0; j < size - i - 1; j++) {       // Loop dalam untuk membandingkan elemen yang berdekatan
            if (arr[j] > arr[j + 1]) {                 // Jika elemen kiri lebih besar, tukar
                int temp = arr[j];                     // Simpan sementara nilai
                arr[j] = arr[j + 1];                   // Geser elemen kanan ke kiri
                arr[j + 1] = temp;                     // Temp disimpan ke kanan
            }
        }
    }
}

int main() {
    int array2D[3][3];     // Deklarasi array 2D berukuran 3x3
    int array1D[9];        // Deklarasi array 1D untuk menyimpan semua elemen
    int index = 0;         // Index untuk mengisi array 1D

    // Input dari user
    cout << "Masukkan elemen array 3x3 (total 9 angka):" << endl;
    for (int i = 0; i < 3; i++) {               // Baris
        for (int j = 0; j < 3; j++) {           // Kolom
            cin >> array2D[i][j];               // Input elemen ke array 2D
            array1D[index++] = array2D[i][j];   // Simpan juga ke array 1D
        }
    }

    // Lakukan bubble sort pada array 1D
    bubbleSort(array1D, 9);

    // Masukkan kembali hasil yang telah diurutkan ke array 2D
    index = 0;
    for (int i = 0; i < 3; i++) {               // Baris
        for (int j = 0; j < 3; j++) {           // Kolom
            array2D[i][j] = array1D[index++];   // Salin dari array 1D ke array 2D
        }
    }

    // Tampilkan array 2D setelah diurutkan
    cout << "Array setelah diurutkan (3x3):" << endl;
    for (int i = 0; i < 3; i++) {               // Baris
        for (int j = 0; j < 3; j++) {           // Kolom
            cout << array2D[i][j] << " ";       // Tampilkan elemen
        }
        cout << endl;                           // Ganti baris setelah 1 baris selesai
    }

    return 0;
}
