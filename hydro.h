// hydro.h
// ENSF 337 Fall 2020 Lab 8 Exercise B
// Abhay Khosla Lab B02 
// Submission Date November 23rd , 2020

#ifndef HYDRO_H
#define HYDRO_H

void displayHeader();
int readData(FlowList & x);
int menu();
void display(const FlowList &x);
int addData(FlowList &x);
int removeData(FlowList &x, int numRecords);
double average(const FlowList &x);
void saveData (const FlowList & x);
void pressEnter();
void cleanStandardInputStream();

#endif