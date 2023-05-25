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

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next; //step 4
	newNode->prev = current;      //step 5
	if (current->next != NULL)    
		current->next->prev = newNode; //step 6
	current->next = newNode;  //step 7
}

bool DoubleLinkedlist::search(int rollNo, Node** previous, Node** current) {
	*previous = START;   //step 1.a
	*current = START;   //step1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {  //step1.c
		*previous = *current;     //step 1.d
		*current = (*current)->next;  //step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedlist::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL; 
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;
	
	double current;
	return true;
}

bool DoubleLinkedlist::listEmpty() {
	return (START == NULL);
}

void DoubleLinkedlist::traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
	}
}

void DoubleLinkedlist::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}

	else {
		cout << "\nRecords in descending order of the roll number are:" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << "" << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void DoubleLinkedlist::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedlist::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << "deleted" << endl;
}















	
