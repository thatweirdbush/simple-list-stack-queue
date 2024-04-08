#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Student {
	string name;
	int id;
	double grade;
};

struct SNode {
	Student student;
	SNode* next;
};

struct SList {
	SNode* head;
};

Student inputStudent(string name, int id, double grade);
void printStudent(const Student& student);
bool isEmpty(const SList& list);
void initialize(SList& list);
SNode* createNode(const Student& student);
void printList(const SList& list);
void addTail(SList& list, SNode* node);
void addHead(SList& list, SNode* node);
void removeTail(SList& list);
void removeHead(SList& list);
void deleteList(SList& list);
void removeWithGrade(SList& list, const int& grade);
void addAfterHead(SList& list, SNode* node);
void addBeforeTail(SList& list, SNode* node);
void reverseList(SList& list);

/**************************************/
struct Stack {
	SNode* top;
};

void initialize(Stack& stack);
bool isEmpty(const Stack& stack);
void push(Stack& stack, SNode* node);
void pop(Stack& stack);
SNode* peek(const Stack& stack);
void deleteStack(Stack& stack);
void printStack(const Stack& stack);
void removeWithGrade(Stack& stack, const int& grade);
double getAverageGrade(const Stack& stack);
