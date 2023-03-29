/*
	Student Name : Nguyễn Minh Tư
	Student Id   : 21850024
	Reference    : Vũ Quốc Hoàng, Bí kíp luyện Lập trình C (Quyển 1), hBook, 2017
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
	1. (3 đ) Mô hình dữ liệu hàng đợi ưu tiên (priority queue) là mô hình dữ liệu cho phép quản lý
	một tập các đối tượng theo độ ưu tiên. Độ ưu tiên của mỗi đối tượng là một con số nguyên.
	Một hàng đợi ưu tiên có hai thao tác đi kèm:
	- Insert: chèn một đối tượng có độ ưu tiên được cho vào hàng đợi.
	- RemoveMax: Gỡ đối tượng có độ ưu tiên lớn nhất ra khỏi hàng đợi và trả về đối tượng đó.
	a) Hãy đưa ra cấu trúc dữ liệu phù hợp và cài đặt cụ thể một hàng đợi ưu tiên quản lý các số
	nguyên.
	b) Từ cấu trúc dữ liệu đã xây dựng ở câu (a) hãy viết hàm sắp xếp tăng dần một dãy số
	nguyên.
*/

// Priority Queue
struct PQ {
	int data;
	int priority;
	PQ* next;
};

// Function to create a new node
PQ* newNode(int d, int p)
{
	PQ* temp = (PQ*)malloc(sizeof(PQ));
	temp->data = d;
	temp->priority = p;
	temp->next = NULL;

	return temp;
}

// Removes the element with the highest priority form the list
void RemoveMax(PQ** head)
{
	PQ* temp = (*head);
	(*head) = (*head)->next;
	free(temp);
}

// Function to push according to priority
void Insert(PQ** head, int d, int p)
{
	PQ* start = *head;

	// Create new Node
	PQ* temp = newNode(d, p);

	// Special Case: The head of list has
	// lesser priority than new node
	if ((*head)->priority < p) {

		// Insert New Node before head
		temp->next = (*head);
		(*head) = temp;
	}
	else {

		// Traverse the list and find a
		// position to insert new node
		while (start->next != NULL
			&& start->next->priority > p) {
			start = start->next;
		}

		// Either at the ends of the list
		// or at required position
		temp->next = start->next;
		start->next = temp;
	}
}

// Function to check is list is empty
int isEmpty(PQ* head) { return (head) == NULL; }

void printPQ(PQ* head) {
	//Node current will point to head  
	PQ* current = head;
	if (head == NULL) {
		printf("List is empty \n");
		return;
	}
	while (current != NULL) {
		//Prints each node by incrementing pointer  
		cout << " " << current->data << "[" << current->priority << "]";
		current = current->next;
	}
	cout << endl;
}

void sortList(PQ* head) {
	//Node current will point to head  
	PQ* current = head, * index = NULL;
	int temp;
	int temp_priority;

	if (head == NULL) {
		return;
	}
	else {
		while (current != NULL) {
			//Node index will point to node next to current  
			index = current->next;

			while (index != NULL) {
				//If current node's data is greater than index's node data, swap the data between them  
				if (current->data > index->data) {
					temp = current->data;
					temp_priority = current->priority;

					current->data = index->data;
					current->priority = index->priority;

					index->data = temp;
					index->priority = temp_priority;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

/*3. Hãy viết hàm int sumNeg(NODE *head) để tính tổng các số âm trong danh sách liên kết
có nút đầu trỏ bởi head bằng kĩ thuật đệ qui*/

struct NODE {
	int data;
	NODE* next;
};

int sumNeg(NODE* head) {
	if (head == NULL)
		return 0;

	int sum = 0;
	if (head->data < 0)
		sum = head->data;

	return sum + sumNeg(head->next);
}

/*4. Hãy viết hàm int sumNeg(NODE *root) để tính tổng các số âm của cây nhị phân có nút
gốc trỏ bởi root bằng kĩ thuật đệ qui.*/
struct TREE
{
	int data;
	TREE* left, * right;
};

TREE* Insert(TREE* root, int value)
{
	if (root == NULL)
	{
		TREE* node = (TREE*)malloc(sizeof(root));
		node->left = NULL;
		node->right = NULL;
		node->data = value;
		return node;
	}
	if (value > root->data)
		root->left = Insert(root->left, value);
	else if (value < root->data)
		root->right = Insert(root->right, value);
	return root;
}

void PreOrder(TREE* root) {
	if (root != NULL)
	{
		PreOrder(root->left);
		printf("%d ", root->data);
		PreOrder(root->right);
	}
}

int sumNegDup(TREE* root) {
	if (root == NULL)
		return 0;

	int sumLeft = sumNegDup(root->left);
	int sumRight = sumNegDup(root->right);
	if (root->data < 0)
		return root->data + sumLeft + sumRight;

	return sumLeft + sumRight;
}

int main()
{
	/*TREE* root = NULL;
	root = Insert(root, -1);
	root = Insert(root, 15);
	root = Insert(root, -12);
	root = Insert(root, 10);
	root = Insert(root, -20);
	root = Insert(root, 35);
	root = Insert(root, -3);
	root = Insert(root, 4);
	root = Insert(root, 12);
	root = Insert(root, 18);
	root = Insert(root, -9);
	root = Insert(root, 31);
	root = Insert(root, 44);
	root = Insert(root, -7);
	root = Insert(root, 90);
	PreOrder(root);
	
	int sumNeg = sumNegDup(root);
	printf("\nSum: %d", sumNeg);*/

	// Create a Priority Queue
	// 10->9->8->11
	PQ* pq = newNode(9, 1);
	Insert(&pq, 8, 2);
	Insert(&pq, 11, 3);
	Insert(&pq, 10, 0);

	cout << "The original priority queue (Liked List) is:" << endl;
	printPQ(pq);
	
	cout << "Priority queue (Liked List) after sorting is:" << endl;
	sortList(pq);
	printPQ(pq);

	return 0;
}