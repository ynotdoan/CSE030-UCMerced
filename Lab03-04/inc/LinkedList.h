#ifndef LinkedList_h
#define LinkedList_h
 
#include <iostream>
#include <ostream>
 
using namespace std;
 
struct Node{
    int data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int n){
        data = n;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList(){
        head = NULL;
    }
    void append(int value){
        if (head == NULL){
            head = new Node(value);
        }
        else{
            // Allocate a new node with value
            // Go to the last element of the list
            // Make the next of the last element point to the new node
            Node* newNode = new Node(value);
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            // At this point, temp is pointing to the last existing element of list
            temp->next = newNode;
        }
    }
	bool operator==(const LinkedList& other) const {
		Node* ours = head;
		Node* theirs = other.head;

		while (ours != NULL){
			if (theirs == NULL){
				return false;
			}
			if (ours->data != theirs->data){
				return false;
			}
			else{
				ours = ours->next;
				theirs = theirs->next;
			}
		}
		return theirs == NULL;
	}
    
    int get(int index){
    // Provide your code here
		Node* temp = head;
		return temp-> data;
    }
    void set(int index, int value){
    // Provide your code here
		Node* temp = head;
		temp-> data = value;
    }
	void insert(int index, int value) {
    // Provide your code here
		Node* temp = head;
		// head
		if (index == 1) {
			head = new Node (value);
			head-> next = temp;
		}
		// else {
			// head->append (0)
		// }
		
		// Finding position in list
		for (int i = 1; i < index; i++) {
			if (temp-> next == NULL) {
				Node* NEWNode = new Node (0);
				temp-> next = NEWNode;
			}
			temp = temp-> next;
		}
		// Node insertion
		Node* Node2 = new Node (value);
		Node2-> next = temp->next;
		temp-> next = Node2;

	}
    
    void print (){
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    ~LinkedList() {
        Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
            delete head;
            head = temp;
        }
    }
};
 
#endif

