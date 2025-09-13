#include <iostream>
using namespace std;

int bil_prima[7] = {1,3,5,7,11,13,17};
int *ptr = &bil_prima[6];

void balik_urutan(int *ptr){
    cout << "Array Setelah Dibalik: ";
    for(int i=0; i<=6; i++){
        cout << *(ptr-i) << " ";
    }
    cout << endl;
}

int main() {
    cout << "Array Sebelum Dibalik: ";
    for (int i=0; i<7; i++) {
        cout << bil_prima[i] << " ";
    }
    cout << endl;
    balik_urutan(ptr);
    return 0;
}