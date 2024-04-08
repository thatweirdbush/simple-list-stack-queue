#include "Header.h"

int main() {
	cout << "*** LIST ***\n";
	// Khai báo danh sách liên kết đơn
	SList list;

	// Khởi tạo ds rỗng
	initialize(list);
	int n = 10;
	for (int i = 0; i < n; i++) {
		Student s = inputStudent(to_string(i), i, i * 1.0);
		SNode* node = createNode(s);
		addTail(list, node);
	}

	// Xuất ds sinh viên
	cout << "Danh sach sinh vien:\n";
	printList(list);

	// Xóa node đầu tiên trong danh sách
	cout << "Xoa node dau tien.\n";
	removeHead(list);

	// Xóa node cuối cùng trong danh sách
	cout << "Xoa node cuoi cung.\n";
	removeTail(list);

	// Nhập điểm số, xóa tất cả sinh viên có điểm số vừa nhập
	int grade = -1;
	cout << "Nhap diem so sinh vien can xoa: ";
	cin >> grade;
	removeWithGrade(list, grade);

	cout << "Danh sach sinh vien:\n";
	printList(list);

	// Nhập thông tin 1 sinh viên và thêm vào sau node đầu tiên của danh sách.
	cout << "Them sinh vien sau node dau tien.\n";
	Student s1 = inputStudent("101", 101, 101);
	SNode* node1 = createNode(s1);
	addAfterHead(list, node1);

	// Nhập thông tin 1 sinh viên và thêm vào sau node cuối cùng của danh sách.
	cout << "Them sinh vien sau node cuoi cung.\n";
	Student s2 = inputStudent("102", 102, 102);
	SNode* node2 = createNode(s2);
	addBeforeTail(list, node2);

	cout << "Danh sach sinh vien:\n";
	printList(list);

	// Đảo ngược danh sách cho tất cả các node.
	cout << "Dao nguoc danh sach:\n";
	reverseList(list);

	// Xuất danh sách sinh viên với thứ tự mới sau khi đảo ngược
	printList(list);

	cout << "Xoa List...\n";
	deleteList(list);
	printList(list);

	/**************************************/
	cout << "\n*** STACK ***\n";

	Stack stack;
	// Khởi tạo stack rỗng.
	initialize(stack);

	// Nhập thông tin 1 sinh viên và thêm vào stack.
	cout << "Nhap sinh vien '201' va them vao Stack.\n";
	Student s3 = inputStudent("201", 201, 201);
	SNode* node3 = createNode(s3);
	push(stack, node3);

	// Thêm n phần tử sinh viên vào stack
	cout << "Them 10 sinh vien vao Stack:\n";
	n = 10;
	for (int i = 0; i < n; i++) {
		Student s = inputStudent(to_string(i), i, i * 1.0);
		SNode* node = createNode(s);
		push(stack, node);
	}
	printStack(stack);

	// Xóa 1 phần tử sinh viên khỏi stack
	cout << "Xoa sinh vien tren dau Stack:\n";
	pop(stack);
	printStack(stack);

	// Nhập điểm số, xóa tất cả sinh viên có điểm số vừa nhập khỏi stack
	cout << "Nhap diem sinh vien can xoa: ";
	cin >> grade;
	removeWithGrade(stack, grade);

	// Xuất danh sách sinh viên
	printStack(stack);
	
	//Tính điểm trung bình của tất cả sinh viên trong stack
	cout << "Diem trung binh cua cac sinh vien la: " << getAverageGrade(stack) << endl;

	// Xóa tất cả phần tử của stack
	cout << "Xoa Stack...\n";
	deleteStack(stack);
	printStack(stack);

	return 0;
}