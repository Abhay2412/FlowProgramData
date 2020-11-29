// list.cpp
// ENSF 337 Fall 2020 Lab 8 Exercise B
// Abhay Khosla Lab B02 
// Submission Date November 23rd , 2020



#include <iostream>
#include <stdlib.h>
using namespace std;
#include "list.h"
#include "hydro.h"

FlowList::FlowList()
: headM(0){

}

FlowList::FlowList(const FlowList &source){
    copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

FlowList::~FlowList()
{
    destroy();
}
void FlowList::insert(const ListItem& itemW)
{
	
    Node *new_node = new Node;
    new_node->item = itemW;
    
    if (headM == 0 || itemW.year <= headM->item.year ) {
        new_node->next = headM;
        headM = new_node;
    }

    else {
        Node *before = headM;      
        Node *after = headM->next; 
        while(after != 0 && itemW.year > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
	
}

int FlowList::counter()
{
	int counter=1;
	if (headM!=0)
	travel=headM;
	while (travel->next!=0){
	travel=travel->next;
	counter++;
	}
	return counter;
	
}

Node* FlowList::gethead()const
{
	return headM;
}

void FlowList::sethead(Node* set)
{
	headM=set;
}

int FlowList::remove(const ListItem& itemA, int numRecords)
{
	if(headM == 0){
		cout << "Error: No such a data";
		return numRecords;
	}
	Node *doomed_node = 0;
	if(itemA.year == headM->item.year){
		doomed_node = headM;
		headM = headM->next;
		delete doomed_node;
		cout<<"\nRecord was successfully removed.";
		return(--numRecords);
	}

	Node *before = headM;
	Node *maybe_doomed = headM -> next;
	while(before->next != 0)
	{
		if(itemA.year == maybe_doomed -> item.year){
		before -> next = maybe_doomed->next;
		maybe_doomed ->next = 0;
		delete maybe_doomed;
		cout<<"\nRecord was successfully removed.";
		return(--numRecords);
	}
		before = maybe_doomed;
		maybe_doomed=maybe_doomed->next;
	
}
cout << "Error: No such a data";
return numRecords;
    }

	
void FlowList::destroy()
{
     Node *remove = headM;
	while (headM!= NULL)
		{
			headM = headM->next;
			delete remove;
			remove = headM;
		}	
	delete remove;

}

void FlowList::copy(const FlowList& source)
{
    if (source.headM == 0) 
		headM = 0;
	else{
		headM = new Node;
		Node * s = source.headM;
		Node * copy = headM;
		while (s != 0){
			copy -> item = s -> item;
			if (s -> next !=0){
				copy -> next = new Node;
				copy = copy -> next;
				s = s -> next;
			}
			else {
				copy -> next= 0;
				s = 0;
			}
		}
	}
}
