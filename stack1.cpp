#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node
{ // stack node struct
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{ // stack head struct
    int count;
    int maxSize;
    struct Node *top;
} Stack;

Stack stack;

void createStack(int size)
{ // Membuat awal stack dengan count = 0
    stack.count = 0;
    stack.maxSize = size;
    stack.top = NULL;
}

bool isFull()
{ // Cek apakah stack penuh
    return stack.count >= stack.maxSize;
}

bool isEmpty()
{ // Cek apakah stack kosong
    return stack.count == 0;
}

void push(int data)
{ // Menambah data
    if (isFull())
    {
        cout << "Stack penuh! Tidak dapat menambah data.\n";
        return;
    }

    Node *newPtr = new Node;
    if (newPtr == NULL)
    {
        cout << "Alokasi memori gagal!";
        return;
    }
    newPtr->data = data;
    newPtr->next = stack.top;
    stack.top = newPtr;
    stack.count++;
    cout << "Nilai " << data << " ditambahkan ke stack.\n";
}

void pop()
{ // Menghapus data
    if (isEmpty())
    {
        cout << "Stack kosong! Tidak ada data untuk dihapus.\n";
        return;
    }
    Node *dltPtr = stack.top;
    cout << "Menghapus nilai: " << dltPtr->data << endl;
    stack.top = stack.top->next;
    stack.count--;
    delete dltPtr;
}

void stackTop()
{ // Menampilkan data pada top stack
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }
    cout << "Nilai pada top: " << stack.top->data << endl;
}

int stackCount()
{ // Menghitung jumlah elemen dalam stack
    return stack.count;
}

void destroyStack()
{ // Menghapus seluruh elemen dari stack
    while (stack.top != NULL)
    {
        Node *temp = stack.top;
        stack.top = stack.top->next;
        delete temp;
    }
    stack.count = 0;
    cout << "Stack telah dihapus.\n";
}

void printStack()
{ // Mencetak isi stack
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }
    Node *pwalker = stack.top;
    cout << "Isi stack dari atas ke bawah:\n";
    cout << "------------------------------\n";
    while (pwalker != NULL)
    {
        cout << pwalker->data << endl;
        pwalker = pwalker->next;
    }
    cout << "------------------------------\n";
}

int main()
{
    int pilihan, value, maxSize;

    cout << "Masukkan ukuran maksimum stack: ";
    cin >> maxSize;
    createStack(maxSize);

    do
    {
        system("cls");
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Ukuran\n5. Destroy\n6. Print Stack\n7. Exit\n";
        cout << "Masukkan pilihan : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan nilai untuk di push: ";
            cin >> value;
            push(value);
            cin.ignore();
            cin.get();
            break;
        case 2:
            pop();
            cin.ignore();
            cin.get();
            break;
        case 3:
            stackTop();
            cin.ignore();
            cin.get();
            break;
        case 4:
            cout << "Ukuran stack: " << stackCount() << endl;
            cin.ignore();
            cin.get();
            break;
        case 5:
            destroyStack();
            cin.ignore();
            cin.get();
            break;
        case 6:
            printStack();
            cin.ignore();
            cin.get();
            break;
        case 7:
            cout << "Keluar dari program...\n";
            break;
        default:
            cout << "Input tidak valid!\n";
            cin.ignore();
            cin.get();
            break;
        }
    } while (pilihan != 7);

    return 0;
}
