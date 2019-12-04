/*File Description:
	This header file contains the definition of the List class. This class will be able to create
	and maintain a linked list by inserting a new Node into the list, editing a node on the list, 
	or deleting a node on the list
*/
//Created by Andrew Mock
#include <string>
using namespace std;

//Creates a data type alias to be specific when declaring strings for the List
typedef string ListType;

//Node definition: This node is what is used to build the linked list. It has two pointer fields
//and a string field
struct Node
{
	ListType info;
	Node* next;
	Node* prev;
};

class List
{
public:
	//Constructs list
	List();
	//Destroys a list
	~List();
	//Inserts a ListType into the correct alpha location in a new Node (returns "true" if successfull)
	bool Insert(ListType);
	//Deletes a node form the list (returns "true" if successfull
	bool Delete(ListType);
	//Takes two ListTypes, one to replace a ListType, and the ListType to replace. It then calls the 
	//Insert() and Delete() functions, and returns "true" if both of those functions return "true
	bool Edit(ListType, ListType);
	//Prints out all of the ListTypes in the List
	void Print() const;

private:
	//The pointer to the first node in the List. Should start out as NULL
	Node* Head;

};
