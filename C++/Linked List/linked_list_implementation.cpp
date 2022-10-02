// Author: Ishaan Kulkarni
// Date: 2-10-2022

/*

1. define node class
2. insert at head fxn
3. print LL
4. insert at middle of LL
5. deletion functions
6. searching functions
7. take_input function to make user create LL easily

*/

#include <bits/stdc++.h>
using namespace std;


// For simplicity, we should also maintain a tail pointer in node class which points to the tail



// define structure of node
class node{
public:
    int data;
    node* next;

    node(int d){
        data = d;
        next = NULL;
    }


};



// inserts data ahead of head and updated head of LL
// since we need to change the head of LL, we pass head by reference
void insertAtHead(node* &head, int d){

    if(head == NULL){
        head = new node(d);
        return;
    }

    node* n = new node(d);
    n->next = head;
    head = n;
    return;

}



// head that is recevived in the funxtion is a copy of the pointer we passed in the function. So changes made in the function are not reflected in the actual head
void printLL(node* head){

    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }

    return;

}




// returns length of LL
int length(node* head){

	int len = 0;

	while(head != NULL){
		head = head->next;
		len++;
	}

	return len;

}





void insertAtTail(node* &head, int val){

	if(head == NULL){
		head = new node(val);
		return;
	}

	// take curr to last node
	node *curr = head;
	while(curr->next != NULL) {
		curr = curr->next;
	}

	node* newnode = new node(val);
	curr->next = newnode;
	return;

}








// insert node with data d after p nodes in the LL
// p = 0 means insertion at head
// if p > length of LL, then insert at end of LL
// to reach the node after which we need to insert new node, take p-1 jumps
void insertAtMiddle(node* &head, int p, int d){

	if(head == NULL || p == 0){
		insertAtHead(head, d);
		return;
	}
    else if(p > length(head)){
		insertAtTail(head, d);
		return;
	}

	// take p-1 jumps
	node* curr = head;
	for(int i=0; i<p-1; i++){
		curr = curr->next;
	}

	node* newnode = new node(d);

	newnode->next = curr->next;
	curr->next = newnode;
	return;

}





/*
Insert at middle using dummy node   --- DO THIS CODE

Without dummy node, if we had to insert at 3rd position, then we had to travel to the node at 2nd position (ie one before 3rd) and make changes in 
links. But if we wanted to insert at 0th position, ie head node, then since there is no node before the head node, we have to handle this case 
separatly.
Using a dummy node, we dont have to write any separate code for the head node

*/

void insertAtMiddle(node* &head, int p, int d){

	node* dummy = new node(-1);  // create a dummy node
	dummy->next = head;

	node* p = dummy;  // p pointer is used to traverse the LL

	// if we want to insert node at 3rd position, then make 3 jumps
	for(int i=0; i<p; i++){
		p = p->next;
	}

	// make changes in connections:
	node* new_node = new node(d);
	new_node->next = p->next;
	p->next = new_node;

	return dummy->next;   // dummy->next always points to the head of the LL

}









// delete head node of LL
void deleteHead(node* &head){

	if(head == NULL){
		return;
	}

	node* temp = head;
	head = head->next;
	delete temp;

}





// deletes last node of LL
void deleteTail(node* &head){

	node* curr = head;

    // reach 2nd last node of LL
	while(curr->next->next != NULL){
		curr = curr->next;
	}

    // temp is the node to be deleted
	node* temp = curr->next;
	curr->next = NULL;
	delete temp;
}





// we want to delete node at index = pos. LL is 0 indexed
// if pos = 0, we need to delete head of LL
// to reach the node we want to delete, take pos-1 jumps
void deleteMiddle(node* &head, int pos){

	if(head == NULL){
	    return;
	}
    else if(pos > length(head)){
		deleteTail(head);
		return;
	}
    else if(pos == 0){
		deleteHead(head);
		return;
	}


	node* curr = head;

    // take pos-1 jumps to reach the node that has to be deleted
	for (int i=0; i<pos-1; i++) {
		curr = curr->next;
	}

	node* temp = curr->next;
	curr->next = temp->next; // or curr->next->next;
	delete temp;

}






// in LL we can only do linear search. Even if the LL is sorted, we cant apply binary search to it.
bool search(node* head, int key){

	node* curr = head;

	while(curr != NULL){
		if(curr->data == key){
            return true;
        } 

		curr = curr->next;
	}

	return false;
}





// recursive linear search
bool searchRecursive(node* head, int key){

	// Base Case
	if(head == NULL){
		return false;
	}

	if(head->data == key){
		return true;
	}

	return searchRecursive(head->next, key);

}





node* take_input(){

	node* head = NULL;

	int d;

    // when we take input from an input file, then this fxn will keep taking input till the end of the input file
	while(cin >> d){
		insertAtTail(head, d);
	}

	return head;

}








int main(){

    node* head = NULL;

    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    printLL(head);
	return;

}
