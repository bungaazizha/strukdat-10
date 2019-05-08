/*
Nama Program	: exercise-02
Nama			: Bunga Azizha N
NPM				: 140810180016
Kelas			: B
Tanggal Buat	: 8 Mei 2019
Deskripsi		: Queue Linked List
*/

#include<iostream>
using namespace std;

struct ElemenQueue {
	char info;
	ElemenQueue* next;
};

typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue {
	List Head;
	List Tail;
};

void createQueue(Queue& Q){
    Q.Head = NULL;
    Q.Tail = NULL;
}

void CreateElement(pointer& pBaru){
    pBaru = new ElemenQueue;
    cout << "Masukkan queue: "; cin >> pBaru->info;
    pBaru->next = NULL;
}

void insertQueue( Queue& Q, pointer pBaru){
	if (Q.Head==NULL && Q.Tail==NULL){		//kasus dimana head dan tailnya kosong
		Q.Head = pBaru;
		Q.Tail = pBaru;
	}
	else {
		Q.Tail->next = pBaru;
		Q.Tail = pBaru;
	}
}

void deleteQueue(Queue& Q, pointer& pHapus){
	cout<<"Delete Queue"<<endl;
	
	if(Q.Head==NULL && Q.Tail==NULL) {	//kasus kosong
	pHapus=NULL;
	cout<<"List Queue kosong "<<endl;
	}
	else if (Q.Head->next==NULL){
		pHapus=Q.Head;
		Q.Head=NULL;
		Q.Tail=NULL;
	}
	else {
		pHapus=Q.Head;
		Q.Head=Q.Head->next;
		pHapus->next=NULL;
	}
}

void printQueue(Queue Q){
    pointer pBantu;
    cout << "Queue : ";
    if(Q.Head==NULL){
        cout << "Queue is empty";
    }
    else{
        pBantu=Q.Head;
        do{
            cout << pBantu->info << " ";
            pBantu = pBantu->next;
        } while(pBantu != NULL);
    }
    cout << endl;
}

main(){
    Queue Q;
    pointer p;
    int pilih;

    createQueue(Q);
    do{
        system("cls");
        cout<<"Queue Linked List"<<endl;
		cout << "\tMenu" << endl;
        cout << "1. Insert Queue " << endl;
        cout << "2. Delete Queue" << endl;
        cout << "3. Print Queue" << endl;
        cout << "4. Exit" << endl;
        cout <<"----------------------------" <<endl;
        cout << "Pilih : "; cin>>pilih;
        switch(pilih){
        case 1:
            CreateElement(p);
            insertQueue(Q,p);
            printQueue(Q);
        break;

        case 2:
            deleteQueue(Q,p);
            printQueue(Q);
        break;

        case 3:
            printQueue(Q);
        break;

        default :
            exit(0);
        }
        cout << endl;
        system("pause");
    }while(pilih!=4);
}
