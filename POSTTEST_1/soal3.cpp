#include <iostream>
using namespace std;

struct mhs {
    string nama;
    string nim;
    float ipk;
};

mhs mahasiswa[4];

void tambah_mhs() {
    for(int i=0; i<4; i++){
        cout << "Masukkan data mahasiswa ke-" << i+1 << endl;
        cout << "Nama: ";
        cin >> mahasiswa[i].nama;
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "IPK: ";
        cin >> mahasiswa[i].ipk;
        cout << endl;
    }
}

void urutkan_ipk_ascending() {
    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){
            if(mahasiswa[i].ipk > mahasiswa[j].ipk){
                mhs temp = mahasiswa[i];
                mahasiswa[i] = mahasiswa[j];
                mahasiswa[j] = temp;
            }
        }
    }
    cout << "Urutan IPK Ascending: " << endl;
    for(int i=0; i<4; i++){
        cout << "Nama: " << mahasiswa[i].nama << ", NIM: " << mahasiswa[i].nim << ", IPK: " << mahasiswa[i].ipk << endl;
    }
}

int main() {
    tambah_mhs();
    urutkan_ipk_ascending();
    return 0;
}