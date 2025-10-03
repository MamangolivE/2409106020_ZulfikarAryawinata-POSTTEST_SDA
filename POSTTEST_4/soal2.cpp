#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// Anda bisa menggunakan fungsi push dan pop dari soal sebelumnya.
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Return null character jika stack kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // --- LENGKAPI DI SINI ---
    // 1. Loop setiap karakter dalam `expr`.
    for (int i = 0; i < expr.length(); i++) {
        char data = expr[i];
    // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack.
        if (data == '(' || data == '{' || data == '[') {
            push(stackTop, data);
        }
    // 3. Jika karakter adalah kurung tutup ')', '}', ']', cek:
    //    a. Apakah stack kosong? Jika ya, return false.
    //    b. Pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka. Jika tidak, return false.
        else if (data == ')' || data == '}' || data == ']') {
            if (stackTop == nullptr) {
                return false; // tidak ada pasangan buka
            }
            char topChar = pop(stackTop);
            if ((data == ')' && topChar != '(') ||
                (data == '}' && topChar != '{') ||
                (data == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    // 4. Setelah loop selesai, jika stack kosong, return true. Jika tidak, return false.
    // --- LENGKAPI DI SINI ---

    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}