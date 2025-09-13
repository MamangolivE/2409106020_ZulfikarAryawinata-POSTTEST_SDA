#include <iostream>
using namespace std;

int nilai1;
int nilai2;

void tukar(int &nilai1, int &nilai2){
    int temp = nilai1;
    nilai1 = nilai2;
    nilai2 = temp;
}

int main() {
    cout << "Masukkan nilai 1: ";
    cin >> nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> nilai2;
    cout << endl;

    cout << "Sebelum ditukar: " << endl;
    cout << "Nilai 1: " << nilai1 << endl;
    cout << "Nilai 2: " << nilai2 << endl;
    cout << endl;

    tukar(nilai1, nilai2);

    cout << "Setelah ditukar: " << endl;
    cout << "Nilai 1: " << nilai1 << endl;
    cout << "Nilai 2: " << nilai2 << endl;

    return 0;
}