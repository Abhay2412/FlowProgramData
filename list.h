// list.h
// ENSF 337 Fall 2020 Lab 8 Exercise B
// Abhay Khosla Lab B02 
// Submission Date November 23rd , 2020


#ifndef LIST_H
#define LIST_H



struct ListItem {
	int year;
	double flow;
};

struct Node {
	ListItem item;
	Node *next;
};

class FlowList {
public:
	FlowList(); 
	FlowList(const FlowList& source);
	FlowList& operator =(const FlowList& rhs);
	~FlowList();
	
	Node* gethead()const;
	void sethead(Node* set);
	int counter();
	void insert(const ListItem& itemW);
	int remove(const ListItem& itemA, int numRecords);
  
private:
	Node *headM;
	Node *travel;
	void destroy(); 
	void copy(const FlowList& source); 
};
#endif
