#include <iostream>

using namespace std;

// deklarasi single linked list
struct node{

  // komponen / member
  int data;

  node *next;
};

node *head, *tail, *cur, *newNode, *del, *before;

// create single linked list
void createSingleLinkedList(int data){
  head = new node();
  head->data = data;
  head->next = NULL;
  tail = head;
}

// print single linked list
int countSingleLinkedList(){
  cur = head;
  int jumlah = 0;
  while( cur != NULL ){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}

// tambahAwal Single linked list atau Insert First
void addFirst(int data){
  newNode = new node();
  newNode->data = data;
  newNode->next = head;
  head = newNode;
}

// tambahAkhir Single linked list atau Insert last
void addLast(int data){
  newNode = new node();
  newNode->data = data;
  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

// tambahTengah Single linked list atau Insert Before
void addMiddle(int data, int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    newNode = new node();
    newNode->data = data;

    // tranversing
    cur = head;
    int nomor = 1;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    newNode->next = cur->next;
    cur->next = newNode;
  }
}


// Remove First atau Delete First
void removeFirst(){
  del = head;
  head = head->next;
  delete del;
}

// Remove Last atau Delete Last
void removeLast(){
  del = tail;
  cur = head;
  while( cur->next != tail ){
    cur = cur->next;
  }
  tail = cur;
  tail->next = NULL;
  delete del;
}

// Remove Middle atau Delete Before
void removeMiddle(int posisi){
  if( posisi < 1 || posisi > countSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    int nomor = 1;
    cur = head;
    while( nomor <= posisi ){
      if( nomor == posisi-1 ){
        before = cur;
      }
      if( nomor == posisi ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    before->next = cur;
    delete del;
  }
}

// print single linked list
void printSingleLinkedList(){
  cout << "Jumlah data ada : " << countSingleLinkedList() << endl;
  cur = head;
  while( cur != NULL ){
    cout << "Data : " << cur->data << endl;

    cur = cur->next;
  }
}

// searching (sequential)
bool searchNode(node **head, int key)
{
    node *cur = *head;
    while (cur != NULL)
    {
        if (cur->data == key)
            return true;
        cur = cur->next;
    }
    return false;
}

int main(){
	cout << "Membuat data Single Linked List" << endl;
	createSingleLinkedList(2);
	printSingleLinkedList();
	cout << "\n" << endl;

	cout << "Insert First" << endl;
	addFirst(1);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Insert Last" << endl;
	addLast(3);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Delete First" << endl;
	removeFirst();
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Insert Last" << endl;
	addLast(4);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Delete Last" << endl;
	removeLast();
	printSingleLinkedList();
	cout << "\n" << endl;

	cout << "Insert Before Data Ke-2" << endl;
	addMiddle(10, 2);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Insert Before Data Ke-2" << endl;
	addMiddle(11, 2);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Delete Before Data Ke-6" << endl;
	removeMiddle(5);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	cout << "Delete Before Data Ke-4" << endl;
	removeMiddle(3);
	printSingleLinkedList();
	cout << "\n" << endl;
	
	int key = 27;
	cout << "Searching Data : " << key << endl;
    if (searchNode(&head, key))
        cout << "Data " << key << " Ditemukan";
    else
        cout << "Data " << key << " Tidak Ditemukan";
}
