// hydro.cpp
// ENSF 337 Fall 2020 Lab 8 Exercise B
// Abhay Khosla Lab B02 
// Submission Date November 23rd , 2020


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include<iomanip>
using namespace std;
#include "list.h"
#include "hydro.h"
#include "list.cpp"

int main(void) 
{
	FlowList x;
	int numRecords;
	displayHeader();
	numRecords = readData(x);
	int quit = 0;
	 
	 while(1)
	 {
		switch(menu())
		{
			case 1: 
			        display(x);// call display function;
                    pressEnter();
                    break;
			case 2:
			        numRecords = addData(x);    // call addData function
                    pressEnter();
                    break;
			case 3:
			        saveData(x);// call saveData function;
                    pressEnter();
                    break;
			case 4:
				   	numRecords = removeData(x, numRecords);// call removeData
                    pressEnter();
                    break;
			case 5:
				cout << "\nProgram terminated!\n\n";
				quit = 1;
				break;
			default:
				cout << "\nNot a valid input.\n";
				pressEnter();// pressEnter();
		}
	if(quit == 1) 
		break;
	}
}

void displayHeader(){
	
	cout << "\nProgram: Flow Studies, Fall 2020."; 
	cout << "\n Version: 1.0";
	cout <<"\n Lab Section: B02";
	cout <<"\n Produced by: Abhay Khosla";
	pressEnter();
}

int menu()
{
	int userChoice; 
	cout<<"Please select on the following operations"<<endl;
	cout<<"		1. Display flow list, and average "<<endl;
	cout<<"		2. Add data"<<endl;
	cout<<"		3. Save data into the file"<<endl;
	cout<<"		4. Remove data"<<endl;
	cout<<"		5. Quit"<<endl;
	cout<<"		Enter your choice (1, 2, 3, 4, or 5):";
	cin >> userChoice;
	return userChoice; 
}



void display(const FlowList &x){
	cout<<"Year          Flow (in billions of cubic meters)"<<endl;
	Node* m=x.gethead();
	while(m)
	{
		cout<< m->item.year <<"		"<< m->item.flow;
		cout<<endl;
		m=m->next;

	}
	cout<<"The annual average of the flow is: "<< average(x)<<" millions cubic meter"<<endl;
	cout<< endl;
}

int readData(FlowList & x)
{
	ifstream object;
	object.open("flow.txt");
	
	if (! object)
	{
		cerr<< "Error: cannot open the file" << "flow.txt" << endl;
		exit(1);
	}
	
	while (!object.eof())
	{
		ListItem items;
		int yr;
		double flw;
		
		object >> yr >> flw; //Using the bitwise right shift operator to go through the data
		
		items.year= yr;
		items.flow = flw;
		x.insert(items);
	}
	
	return (x.counter());
}

int addData(FlowList &x)
{
	ListItem temp; 
	int val=x.counter();
	cout << "Please enter a year: ";
	cin >> temp.year;
	cleanStandardInputStream();
	cout << "Please enter the flow: ";
	cin >> temp.flow;
	cleanStandardInputStream();
	
	Node* m=x.gethead();
	
	while(m!=0)
	{
		if(m->item.year==temp.year)
		{
			cout<<"Error: duplicate data."<<endl;
			return val;
		}
		m=m->next;
	}
	x.insert(temp);
	cout<<"New record inserted successfully."<<endl;
	return val;
	}
int removeData(FlowList &x, int numRecords)
{
	ListItem temp;
	cout << "Please enter the year that you want to remove: ";
	cin >> temp.year;
	cleanStandardInputStream();

	numRecords = x.remove(temp, numRecords);
	return numRecords;
}


double average(const FlowList &x)
{
	Node* m=x.gethead();
	if(m==0)
		return 0;
	double counter=0, sum=0;
	while(m)
	{
		sum+=m->item.flow;
		counter++;
		m=m->next;
	}
	return sum/counter;
}

void saveData (const FlowList & x)
{
	ofstream outobject;
	outobject.open("flow.txt", std::ofstream::trunc);
	
	if (! outobject)
	{
		cerr<< "Error: cannot open the file" << endl;
		exit(1);
	}
	
	Node* data=x.gethead();
	
	while (data!=NULL)
	{
		outobject<< setw(4) << data->item.year << setw(12) << data->item.flow;
		if (data->next !=NULL)
			outobject<<endl; 
		data=data->next;
	}
	cout<<endl<<"Data are saved into the file."<<endl;
	outobject.close();
}

void pressEnter()
{
	cout <<"\n<<<Press Enter to Continue>>>";
	cin.get();
	cleanStandardInputStream();
}
void cleanStandardInputStream(){
	char ch;
	cin.clear();
	do{
		ch=cin.get();
	}while(ch != '\n' && ch != EOF);
}