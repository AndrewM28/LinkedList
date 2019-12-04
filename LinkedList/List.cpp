//This is the Implementation of the List Class
//Created by Andrew Mock
#include "List.h"
#include <iostream>
using namespace std;

//Places NULL in head when list is constructed 
List::List() {
	Head = NULL;
}

//Destroys all nodes in the List
List::~List() {
	
	for (Node* cur = Head; cur != NULL; cur = cur->next) {
		Head = Head->next;
		delete cur;
		cur = Head;
	}
	
}


//Attempts to insert a new Node into the List
bool List::Insert(ListType insertStr) {
	Node* p = new Node;
	bool success = true;

	//Determins if there is enough memory to make a new Node. If not, returns "false"
	if (p == NULL) {
		success = false;
		return success;
	}

	else{
		//Places the desired ListType into the new Node
		p->info = insertStr;
		//Checks if the list is empty
		if (Head == NULL) {
			Head = p;
			Head->next = NULL;
		}

		//Checks if the first item in the list should be placed after the new Node
		else if(p->info < Head->info){
			p->next = Head;
			Head->prev = p;
			Head = p;
		}
		else {
			for (Node* cur = Head; cur != NULL; cur = cur->next) {

				//Checks if the new Node should be placed at the end of the List
				if (cur->next == NULL) {
					cur->next = p;
					p->prev = cur;
					p->next = NULL;
					return success;
				}
				//Checks if the new Node should be placed in the middle of the List
				else if (p->info > cur->info && p->info < cur->next->info) {
					p->next = cur->next;
					p->prev = cur;
					cur->next = p;
					return success;
				}
				
			}
		}
		return success;
	}
	
}

//Attempts to Delete a Node from the List
bool List::Delete(ListType deleteStr) {
	bool success = false;

	//Checks to see if the first Node is the one to delete
	if (Head->info == deleteStr) {
		Head = Head->next;
		delete Head->prev;
		success = true;
		return success;
	}
	else {
		for (Node* cur = Head; cur != NULL; cur = cur->next) {
			if (cur->info == deleteStr) {
				//Checks if the last Node is the one to delete
				if(cur->next == NULL){
					cur->prev->next = NULL;
					delete cur;
					success = true;
					return success;
				}
				//Checks if the Node to delete is in the middle of the List
				else {
					cur->prev->next = cur->next;
					cur->next->prev = cur->prev;
					delete cur;
					success = true;
					return success;
				}
				
				
			}
		}
	}
	//Returns false, since no Node was deleted 
	return success; 
	
}

//Takes in too ListTypes and calls Insert and Delete in order to replace one of the Nodes
bool List::Edit(ListType deleteThis, ListType insertThis) {
	bool deleteSuccess = false;
	bool insertSuccess = false;
	for (Node* cur = Head; cur != NULL; cur = cur->next) {
		if (cur->info == deleteThis) {
			//Attempts to delete node 
			deleteSuccess = Delete(deleteThis);
			//Attempts to insert new Node
			insertSuccess = Insert(insertThis);
			return deleteSuccess && insertSuccess;
			
		}
	}
	return deleteSuccess && insertSuccess;
}

//Prints out the List
void List::Print() const {
	for (Node* cur = Head; cur != NULL; cur = cur->next) {
		cout << cur->info << endl;
	}
}