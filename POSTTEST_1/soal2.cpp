#include <iostream>
using namespace std;

int matriks[3][3]={
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

void tampilkan_matriks(int matriks[3][3]){
    cout << "Isi Matriks: " << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
}

void hitung_baris_genap(int matriks[3][3]){
    int jumlah_baris_index0 = 0;
    int jumlah_baris_index2 = 0;
    for(int j=0; j<3; j++){
        jumlah_baris_index0 += matriks[0][j];
        jumlah_baris_index2 += matriks[2][j];
    }
    int total = jumlah_baris_index0 + jumlah_baris_index2;
    cout << "Jumlah Baris ke-2: " << total << endl;
}

int main() {
    tampilkan_matriks(matriks);
    cout << endl;
    hitung_baris_genap(matriks);
    return 0;
}