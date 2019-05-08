/*
Nama Program	: exercise-01
Nama			: Bunga Azizha N
NPM				: 140810180016
Kelas			: B
Tanggal Buat	: 8 Mei 2019
Deskripsi		: Queue Array Circular
*/

#include <iostream>
#include<windows.h>
using namespace std;

const int maxElmt = 5;

struct Queue{
    char data[maxElmt];
    int head;
    int tail;
};
void createElmt(Queue& q){
    q.head = -1;
    q.tail = -1;
}
void insertQueue (Queue& q, char elmt){
    int temp;
    if (q.tail == -1){	//kasus kosong pertama kali
        q.head = 0;
        q.tail = 0;
        q.data[q.tail] = elmt;
    }
    else {
    	temp=q.tail;				//amankan posisi q.tail
        if (q.tail < maxElmt -1){	//proses circular
            q.tail+=1;
        }
        else {
            q.tail = 0;
        }
        if (q.tail == q.head){
            cout << "\nQueue is full\n";
            q.tail = temp;			//kembalikan posisi q.tail
        }
        else {
            q.data[q.tail] = elmt;
        }
    }
}
void deleteQueue(Queue& q, char& eDel){
    if (q.head == -1){				//kasus kosong
        cout << "\nQueue is Empty\n";
    }
    else if (q.head == q.tail){		//kasus isi 1 elemen
        eDel = q.data[q.head];
        q.data[q.head]= ' ';
        q.head = -1;				//kembalikan ke kosong
        q.tail = -1;
    }
    else {
        eDel = q.data[q.head];
        q.data[q.head] = ' ';
        if (q.head < maxElmt -1){
            q.head+=1;
        }
        else {						//q.head=maxElemen-1
            q.head = 0;
        }
    }
}
void printQueue(Queue& q){
    for(int i=q.head; i<=q.tail;i++){
        cout << q.data[i] << " "<<endl;
    }
}

main (){
   	Queue Q;
   	int n, menu;
    char e, pilih;
    
    cout<<"Queue Circular menggunakan Array"<<endl;
    do {
    cout<<"\tMenu"<<endl;
    cout << "1. Insert Queue\n";
    cout << "2. Delete Queue\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";
    cout << "Pilihan : "; cin >> menu;
    system("cls");
    if (menu <1 || menu >4){
        cout << "\Maaf , Anda Salah Input Data\n";
        system("pause");
        exit(0);
    }
    else {
    createElmt(Q);
    switch(menu){
    case 1 :
        cout << "Input Jumlah Data : "; cin >> n;
        for(int i=0; i<n;i++){
            cout << "Input Elemen : "; cin >> e;
            insertQueue(Q,e);
            }
            cout << "\n Data Queue\n";
            printQueue(Q);
            cout << endl;
            cout<<"Data Queue Setelah di delete"<<endl;
            deleteQueue(Q,e);
            printQueue(Q);
        system("pause");
        break;
    case 2 :
        deleteQueue(Q,e);
        cout << "\n Data Queue\n";
        printQueue(Q);
        break;
    case 3 :
	exit(0);
        break;
        }
    cout << "Back to menu (y/n)? "; cin >> pilih;
    system("cls");
    }
    } while (pilih == 'y' || pilih == 'Y');
}
