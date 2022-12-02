#include <iostream>
#include <string>
using namespace std;

class tumpukan {
public:
    tumpukan() {
        //buat link list kosong
        head = NULL;
        tail = NULL;
        size = 0;
    }
    //menambahkan data pada stack/membuat node baru
    void push(char a) {
        //buat node baru
        node* tmp = new node;
        //masukkan data ke node
        tmp->data = a;
        //tentukan node setelahnya
        tmp->next = NULL;
        //jika LL kosong
        if (size == 0) {
            //head dan tail adalah node yg baru dibuat
            head = tmp;
            tail = tmp;
            //node sebelumnya belum ada
            tail->prev = NULL;
        }
        //jika LL tidak kosong
        else {
            //node setelah tail adalah node baru
            tail->next = tmp;
            //node sebelum node baru adalah tail
            tmp->prev = tail;
            //pindahkan tail ke node baru
            tail = tmp;
        }
        //jumlah node bertambah
        size++;
    }
    //mengambil data dan menghapus node yang terakhir
    char pop() {
        //ambil data di tail
        data = tail->data;
        if (head == tail) {
            delete head;
        }
        else {
            //akses tail
            node* tmp = tail;
            //pindah tail
            tail = tail->prev;
            //hapus link
            tail->next = NULL;
            tmp->prev = NULL;
            //hapus mantan tail (tmp)
            delete tmp;
        }
        size--;
        return data;
    }
private:
    struct node {
        char data;
        node* next;
        node* prev;
    };

    node* head;
    node* tail;
    int size;
    char data;
};

class antrian {
public:
    antrian() {
        //buat link list kosong
        head = NULL;
        tail = NULL;
        size = 0;
    }
    //menambahkan data pada stack/membuat node baru
    void push(char a) {
        //buat node baru
        node* tmp = new node;
        //masukkan data ke node
        tmp->data = a;
        //tentukan node setelahnya
        tmp->next = NULL;
        //jika LL kosong
        if (size == 0) {
            //head dan head adalah node yg baru dibuat
            head = tmp;
            tail = tmp;
            //node selanjutnya belum ada
            head->prev = NULL;
        }
        //jika LL tidak kosong
        else {
            //node setelah head adalah node baru
            tail->next = tmp;
            //node sebelum node baru adalah head
            tmp->prev = tail;
            //pindahkan head ke node baru
            tail = tmp;
        }
        //jumlah node bertambah
        size++;
    }
    //mengambil data dan menghapus node yang pertama
    char pop() {
        //ambil data di head
        data = head->data;
        if (head == tail) {
            delete head;
        }
        else {
            //akses head
            node* tmp = head;
            //pindah head
            head = head->next;
            //hapus link
            head->prev = NULL;
            tmp->next = NULL;
            //hapus mantan head (tmp)
            delete tmp;
        }
        size--;
        return data;
    }
private:
    struct node {
        char data;
        node* next;
        node* prev;
    };
    node* head;
    node* tail;
    int size;
    char data;
};

int main() {
    //membuat stack
    tumpukan s;
    //membuat queue
    antrian q;
    //membuat variabel bool palindrome
    bool palindrome = true;
    cout << "Pengecekan Palindrome" << endl << endl;
    //membuat variabel penampungan kata
    string kata;
    //meminta user memasukkan kata
    char a, b, c;
    do {
        cout << "Masukkan kata : ";cin >> kata;cout << endl;
        //loop untuk memasukkan semua isi dari string kata ke stack dan queue
        for (int i = 0;i < kata.length();i++) {
            s.push(kata[i]);
            q.push(kata[i]);
        }
        //loop untuk membandingkan hasil popping dari stack dan queue
        for (int l = 0;l < kata.length();l++) {
            //jika keluaran popping berbeda
            a = q.pop(); b = s.pop();
            if (a != b) {
                cout << a << " != " << b << endl;
                palindrome = false;
            }
            else {
                cout << a << " == " << b << endl;
            }
        }
        //jika semua hasil perbandingan popping stack dan queue sama
        if (palindrome == true) {
            cout << "Kata tersebut adalah kata palindrome";
        }
        else {
            cout << "Kata tersebut tidak palindrome";
        }
        cout << "\n\nCek kata lainnya ? (Y/N)";cin >> c;cout << endl;
    } while (c == 'Y' || c == 'y');
    cout << endl;
    system("pause");
    return 0;
}