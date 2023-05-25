#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedlist {
private:
	Node* START;
public:
	DoubleLinkedlist();
	void addNode();
	bool search(int rolNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedlist::DoubleLinkedlist() {
	START = NULL;
}

void DoubleLinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();  //step 1
	newNode->noMhs = nim;   //step 2
	newNode->name = nm; //step 2

	/*insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim < -START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDupclicate number not allowed" << endl;
			return;
		}
		newNode->next = START;   //step3
		if (START != NULL)
			START->prev = newNode;  //step 4
		newNode->prev = NULL;      //step 5
		START = newNode;           //step 6
		return;
	}

	/*Inserting a Node Between Two Nodes in the List*/
	Node* current = START;  // step 1.a
	Node* previous = NULL; //step 1.b
	while (current->next != NULL && current->next->noMhs < nim) //step 1.c
	{
		previous = current; //1.d
		current = current->next; //1.e
	}

	if (current->next != NULL && nim == current->next > noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}
		
	}
















	}
