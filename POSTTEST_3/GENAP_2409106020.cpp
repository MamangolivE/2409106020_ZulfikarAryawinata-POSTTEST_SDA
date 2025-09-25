#include <iostream>

using namespace std;

string nama;
string nim;

int pilihan;
struct jadwalPenerbangan {
    string kodePenerbangan;
    string tujuan;
    string Status[4] = {"Tepat Waktu", "Tertunda", "Naik Pesawat", "Sudah Sampai"};
};
struct node {
    jadwalPenerbangan data;
    node *prev;
    node *next;
};

node *head = nullptr;
node *tail = nullptr;

void daftar() {
    cout << "============================" << endl;
    cout << "Nama: "; 
    getline(cin, nama);
    while (true) {
        cout << "NIM: ";
        cin >> nim;
        if (nim.length() < 10) {
            cout << "NIM minimal 10 digit!" << endl;
        }
        else {
            break;
        }
    }
    system("cls");
}
void menu_Utama() {
    cout << "====================================" << endl;
    cout << "     SISTEM JADWAL PENERBANGAN      " << endl;
    cout << "           SELAMAT DATANG:            " << endl;
    cout << nama << " - " << nim << endl; 
    cout << "====================================" << endl;
    cout << "1. Tambah Jadwal Penerbangan" << endl;
    cout << "2. Sisipkan Jadwal Penerbangan" << endl;
    cout << "3. Hapus Jadwal Paling Awal" << endl;
    cout << "4. Update Status Penerbangan" << endl;
    cout << "5. Tampilkan Jadwal" << endl;
    cout << "0. Keluar" << endl;
    cout << "====================================" << endl;
}
string formatKode(int kode) {
    string angka = to_string(kode);
    while (angka.length() < 3) angka = "0" + angka;
    return "JT-" + angka;
}
void addSpesific(node **head, node **tail) {
    cin.ignore();
    cout << "==========Informasi Jadwal==========" << endl;
    static int lastKode = -1;
    node* newNode = new node();
    newNode->next = nullptr;
    if (lastKode == -1){
        string tigaDigit = nim.substr(nim.length() - 3);
        lastKode = stoi(tigaDigit);
        newNode->data.kodePenerbangan = formatKode(lastKode);
        cout << "Kode Penerbangan: " << newNode->data.kodePenerbangan << endl;
    } 
    else {
        lastKode += 1;
        newNode->data.kodePenerbangan = formatKode(lastKode);
        cout << "Kode Penerbangan: " << newNode->data.kodePenerbangan << endl;
    }
    cout << "Masukkan Tujuan: ";
    getline(cin, newNode->data.tujuan);
    newNode->data.Status[0];
    if (*head == nullptr){
        *head = newNode;
    }
    else{
        node* temp = *head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        *tail = newNode;
        newNode->prev = temp;
        newNode->next = nullptr;
    }
    system("cls");
    cout << "Data penerbangan berhasil ditambahkan!" << endl;
}
void deleteFirst(node **head) {
    if (*head == nullptr){
        cout << "Tidak ada jadwal penerbangan untuk dihapus." << endl;
        return;
    }
    node* hapus = *head;
    *head = (*head)->next;
    delete hapus;
    cout << "Jadwal penerbangan pertama berhasil dihapus!" << endl;
}
void updateStatus(node *head) {
    if (head == nullptr){
        cout << "Tidak ada jadwal penerbangan." << endl;
        return;
    }
    node* temp = head;
    cout << "=================== DAFTAR JADWAL ===================" << endl;
    while (temp != nullptr){
        cout << temp->data.kodePenerbangan 
             << " - " << temp->data.tujuan
             << " - Status: " << temp->data.Status[0] << endl;
        temp = temp->next;
    }
    cout << "=====================================================" << endl;
    string kodeCari;
    cout << "Masukkan kode penerbangan yang mau diupdate: ";
    cin >> kodeCari;
    temp = head;
    while (temp != nullptr && temp->data.kodePenerbangan != kodeCari){
        temp = temp->next;
    }
    if (temp == nullptr){
        cout << "Kode penerbangan tidak ditemukan." << endl;
        return;
    }
    cout << "=======Pilih Status Baru=======" << endl;
    cout << "1. Tepat Waktu" << endl;
    cout << "2. Tertunda" << endl;
    cout << "3. Naik Pesawat" << endl;
    cout << "4. Sudah Sampai" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    if (pilihan >= 1 && pilihan <= 4){
        temp->data.Status[0] = temp->data.Status[pilihan - 1];
        system("cls");
        cout << "Status penerbangan berhasil diupdate menjadi: " << temp->data.Status[0] << endl;
    } 
    else{
        cout << "Pilihan status tidak valid." << endl;
    }
}
void tampilkanTraversal(node* head) {
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan." << endl;
        return;
    }
    int idx = 1;
    node *temp = head;
    cout << "=================== DAFTAR JADWAL ===================" << endl;
    while (temp != nullptr) {
        cout << idx << ". " << temp->data.kodePenerbangan
             << " | Tujuan: " << temp->data.tujuan
             << " | Status: " << temp->data.Status[0] << endl;
        idx++;
        temp = temp->next;
    }
    cout << "=====================================================" << endl;
}

void tampilkanReverseTraversal(node *tail) {
    if (tail == nullptr) {
        cout << "Tidak ada jadwal penerbangan." <<  endl;
        return;
    }
    int idx = 1;
    node *temp = tail;
    cout << "=================== DAFTAR JADWAL ===================" << endl;
    while (temp != nullptr) {
        cout << idx << ". " << temp->data.kodePenerbangan
             << " | Tujuan: " << temp->data.tujuan
             << " | Status: " << temp->data.Status[0] << endl;
        idx++;
        temp = temp->prev;
    }
    cout << "=====================================================" << endl;
}

void tampilkanSpesifik () {
    system("cls");
    if (head == nullptr){
        cout << "Tidak ada jadwal penerbangan." << endl;
        return;
    }
    node* temp = head;
    string kodeCari;
    cout << "Kode yang Dicari: ";
    cin >> kodeCari;
    while (temp != nullptr && temp->data.kodePenerbangan != kodeCari){
        temp = temp->next;
    }
    if (temp == nullptr){
        cout << "Kode penerbangan tidak ditemukan." << endl;
        return;
    }
    else if (temp != nullptr && temp->data.kodePenerbangan == kodeCari){
        cout << "======== Jadwal Ditemukan ==========" << endl;
        cout << "Kode: " << temp->data.kodePenerbangan << endl
             << "Tujuan: " << temp->data.tujuan << endl
             << "Status: " << temp->data.Status[0] << endl;
        cout << "====================================" << endl;
    }
}

int main(){
    daftar();
    while (true) {
        menu_Utama();
        cout << "Pilihan: ";
        cin >> pilihan;
        if (pilihan == 1){
            system("cls");
            addSpesific(&head, &tail);
        }
        else if (pilihan == 2){
            system("cls");
            addSpesific(&head, &tail);
        }
        else if (pilihan == 3){
            system("cls");
            deleteFirst(&head);
        }
        else if (pilihan == 4){
            system("cls");
            updateStatus(head);
        }
        else if (pilihan == 5){
            system("cls");
            cout << "====================================" << endl;
            cout << "1. Tampilkan dari depan" << endl;
            cout << "2. Tampilkan dari belakang" << endl;
            cout << "3. Cari Jadwal Penerbangan" << endl;
            cout << "====================================" << endl;
            cout << "Pilihan: ";cin >> pilihan;
            if (pilihan == 1)
            {
                tampilkanTraversal(head);
            }
            else if (pilihan == 2)
            {
                tampilkanReverseTraversal(tail);
            }
            else if (pilihan == 3)
            {
                tampilkanSpesifik();
            }
            else {
                system("cls");
                cout << "Input Tidak Valid" << endl;
            }
        }
        else if (pilihan == 0){
            cout << endl << "Keluar dari Sistem Jadwal Penerbangan" << endl << "TERIMA KASIH";
            return 0;
        }
        else {
            system("cls");
            cout << "Input Tidak Valid." << endl;
        }
    }
}