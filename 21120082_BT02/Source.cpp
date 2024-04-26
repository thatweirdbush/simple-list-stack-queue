#include "Header.h"

/**************************************/
// LIST FUNCTION
Student inputStudent(string name = "", int id = 0, double grade = 0.0) {
	Student student;
	student.name = name;
	student.id = id;
	student.grade = grade;
	return student;
}

void printStudent(const Student& student) {
	cout << student.name << ", " << student.id << ", " << student.grade;
}

bool isEmpty(const SList& list) {
	return list.head == nullptr;
}

void initialize(SList& list) {
	list.head = nullptr;
}

SNode* createNode(const Student& student) {
	SNode* node = new SNode;
	node->student = student;
	node->next = nullptr;

	return node;
}

void printList(const SList& list) {
	if (isEmpty(list)) {
		cout << "List is empty!\n";
		return;
	}
	SNode* temp = list.head;
	while (temp != nullptr) {
		printStudent(temp->student);
		cout << endl;
		temp = temp->next;
	}
}

void addTail(SList& list, SNode* node) {
	if (isEmpty(list)) {
		list.head = node;
	}
	else {
		SNode* temp = list.head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = node;
	}
}

void addHead(SList& list, SNode* node) {
	if (isEmpty(list)) {
		list.head = node;
	}
	else {
		node->next = list.head;
		list.head = node;
	}
}

void removeTail(SList& list) {
	if (isEmpty(list)) {
		cerr << "List is empty!\n";
		return;
	}
	else {
		if (list.head->next == nullptr) {
			delete list.head;
			list.head = nullptr;
			return;
		}

		SNode* temp = list.head;
		SNode* temp_previous = list.head;

		while (temp->next != nullptr) {
			temp_previous = temp;
			temp = temp->next;
		}

		delete temp;
		temp_previous->next = nullptr;
		temp = nullptr;
	}
}

void removeHead(SList& list) {
	if (isEmpty(list)) {
		cerr << "List is empty!\n";
		return;
	}
	else {
		SNode* temp = list.head;
		list.head = list.head->next;

		delete temp;
		temp = nullptr;
	}
}

void deleteList(SList& list) {
	while (!isEmpty(list)) {
		removeTail(list);
	}
}

void removeWithGrade(SList& list, const int& grade) {
	if (isEmpty(list)) {
		cout << "List is empty!\n";
		return;
	}
	// Nếu các phần tử đầu liên tục thỏa mãn
	while (list.head != nullptr && list.head->student.grade == grade) {
		SNode* temp = list.head;
		list.head = list.head->next;

		delete temp;
		temp = nullptr;
	}

	// Nếu các phần tử còn lại thỏa mãn
	SNode* curr = list.head;
	while (curr != nullptr && curr->next != nullptr) {
		if (curr->next->student.grade == grade) {
			SNode* temp = curr->next;
			curr->next = curr->next->next;

			delete temp; 
			temp = nullptr;
		}
		else {
			curr = curr->next;
		}
	}
}

void addAfterHead(SList& list, SNode* node) {
	if (isEmpty(list)) {
		list.head = node;
	}
	else {
		SNode* temp = list.head;
		temp = temp->next;

		list.head->next = node;
		node->next = temp;
	}
}

void addBeforeTail(SList& list, SNode* node) {
	if (isEmpty(list)) {
		list.head = node;
		return;
	}

	// Tìm node cuối cùng và node trước đó
	SNode* curr = list.head;
	SNode* prev = nullptr;
	while (curr->next != nullptr) {
		prev = curr;
		curr = curr->next;
	}

	// Thêm node vào trước node cuối cùng
	// Nếu ds chỉ có một phần tử
	if (prev == nullptr) {
		node->next = list.head;
		list.head = node;
	}
	else {
		node->next = curr;
		prev->next = node;
	}
}

void reverseList(SList& list) {
	// Danh sách rỗng hoặc chỉ có một phần tử thì không cần đảo ngược
	if (list.head == nullptr || list.head->next == nullptr) {
		return;
	}

	SNode* prev = nullptr;
	SNode* curr = list.head;
	SNode* next = nullptr;

	while (curr != nullptr) {
		next = curr->next; 
		curr->next = prev;

		prev = curr;
		curr = next;
	}
	list.head = prev;
}

/**************************************/
// STACK FUNCTION
void initialize(Stack& stack) {
	stack.top = nullptr;
}

bool isEmpty(const Stack& stack) {
	return stack.top == nullptr;
}

void push(Stack& stack, SNode* node) {
	node->next = stack.top;
	stack.top = node;
}

void pop(Stack& stack) {
	if (isEmpty(stack)) {
		cerr << "Stack is empty\n";
		return;
	}
	SNode* temp = stack.top;
	stack.top = stack.top->next;

	delete temp;
	temp = nullptr;
}

SNode* peek(const Stack& stack) {
	if (isEmpty(stack)) {
		cerr << "Stack is empty\n";
		exit(1);
	}
	return stack.top;
}

void deleteStack(Stack& stack) {
	while (!isEmpty(stack)) {
		pop(stack);
	}
}

void printStack(const Stack& stack) {
	if (isEmpty(stack)) {
		cout << "Stack is empty.\n";
		return;
	}
	SNode* curr = stack.top;
	while (curr != nullptr) {
		printStudent(curr->student);
		cout << endl;
		curr = curr->next;
	}
}

void removeWithGrade(Stack& stack, const int& grade) {
	if (isEmpty(stack)) {
		cerr << "Stack is empty.\n";
		return;
	}

	SNode* curr = stack.top;
	SNode* prev = nullptr;

	while (curr != nullptr) {
		if (curr->student.grade == grade) {
			// Kiểm tra phần tử đầu tiên
			if (prev == nullptr) {
				pop(stack);
				curr = stack.top;
			}
			else {
				prev->next = curr->next;
				SNode* temp = curr;
				curr = curr->next;
				delete temp;
				temp = nullptr;
			}
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
}

double getAverageGrade(const Stack& stack) {
	if (isEmpty(stack)) {
		cerr << "Stack is empty.\n";
		exit(1);
	}

	double sum = 0;
	int count = 0;
	SNode* curr = stack.top;

	while (curr != nullptr) {
		sum += curr->student.grade;
		count++;
		curr = curr->next;
	}

	return sum / count;
}

/**************************************/
// QUEUE FUNCTION
void initialize(Queue& queue) {
	queue.head = nullptr;
	queue.tail = nullptr;
}

bool isEmpty(const Queue& queue) {
	return (queue.head == nullptr);
}

void enqueue(Queue& queue, SNode* node) {
	if (isEmpty(queue)) {
		queue.head = node;
		queue.tail = node;
		return;
	}
	queue.tail->next = node;
	queue.tail = node;
}

void deuque(Queue& queue) {
	if (isEmpty(queue)) {
		cerr << "Queue is empty.\n";
		return;
	}
	SNode* temp = queue.head;
	queue.head = queue.head->next;
	delete temp;
	temp = nullptr;
}

SNode* peek(const Queue& queue) {
	if (isEmpty(queue)) {
		cerr << "Queue is empty.\n";
		exit(1);
	}
	return queue.head;
}

void deleteQueue(Queue& queue) {
	while (!isEmpty(queue)) {
		deuque(queue);
	}
}

void printQueue(const Queue& queue) {
	if (isEmpty(queue)) {
		cout << "Queue is empty.\n";
		return;
	}
	SNode* curr = queue.head;
	while (curr != nullptr) {
		printStudent(curr->student);
		cout << endl;
		curr = curr->next;
	}
}

void removeWithGrade(Queue& queue, const int& grade) {
	if (isEmpty(queue)) {
		cerr << "Queue is empty.\n";
		return;
	}

	SNode* curr = queue.head;
	SNode* prev = nullptr;

	while (curr != nullptr) {
		if (curr->student.grade == grade) {
			// Kiểm tra phần tử đầu tiên
			if (prev == nullptr) {
				deuque(queue);
				curr = queue.head;
			}
			else {
				prev->next = curr->next;
				SNode* temp = curr;
				curr = curr->next;
				delete temp;
				temp = nullptr;
			}
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
}

double getAverageGrade(const Queue& queue) {
	if (isEmpty(queue)) {
		cerr << "Queue is empty.\n";
		exit(1);
	}

	double sum = 0;
	int count = 0;
	SNode* curr = queue.head;

	while (curr != nullptr) {
		sum += curr->student.grade;
		count++;
		curr = curr->next;
	}

	return sum / count;
}