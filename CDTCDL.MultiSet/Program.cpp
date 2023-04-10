#include <iostream>
using namespace std;

struct myBag {
	int value;
	int seq;
	myBag* next;
};

myBag* initBag() {
	return {};
}

bool isEmptyBag(myBag* bag) {
	if (bag == NULL)
	{
		return true;
	}
	return false;
}

myBag* newBag(int value, int seq) {
	myBag* temp = (myBag*)malloc(sizeof(myBag));

	temp->value = value;
	temp->seq = seq;
	temp->next = NULL;

	return temp;
}

// Function to push according to priority
void insert(myBag** latestBag, int value)
{
	if (*latestBag == NULL)
	{
		*latestBag = newBag(value, 1);
	}
	else
	{
		if ((*latestBag)->value == value)
		{
			(*latestBag)->seq = (*latestBag)->seq + 1;
		}
		else
		{
			myBag* tmp = newBag(value, 1);
			(*latestBag)->next = tmp;
		}
	}
}

void deleteItem(myBag** latestBag, int value) {
	if (isEmptyBag(*latestBag)) return;

	myBag* current = *latestBag, * index = NULL;
	bool isDeleted = false;

	while (current != NULL) {
		//Node index will point to node next to current  
		index = current->next;

		while (index != NULL) {
			if (current->value == value) {
				isDeleted = true;
				if (current->seq > 1)
				{
					current->seq = current->seq - 1;
					*latestBag = current;
					break;
				}
				else
				{
					myBag* temp = (*latestBag);
					(*latestBag) = (*latestBag)->next;
					free(temp);
					break;
				}
			}

			index = index->next;
		}
		current = current->next;
	}

	if (!isDeleted)
		cout << "\nBag does not contain value: " << value << ". Cannot delete." << endl;
}

void deleteAll(myBag** bag) {
	*bag = {};
}

int countItem(myBag** bag, int value) {
	if (isEmptyBag(*bag)) return 0;

	myBag* current = *bag, * index = NULL;

	while (current != NULL) {
		//Node index will point to node next to current  
		index = current->next;

		while (index != NULL) {
			if (current->value == value) {
				return current->seq;
			}

			index = index->next;
		}
		current = current->next;
	}

	return 0;
}

void printBag(myBag* bag) {
	//Node current will point to head  
	myBag* current = bag;
	if (isEmptyBag(bag)) {
		cout << "Bag is empty." << endl;
		return;
	}
	
	cout << "Current bag:" << endl;

	while (current != NULL) {
		//Prints each node by incrementing pointer  
		cout << " " << current->value << "[" << current->seq << "]";
		current = current->next;
	}
	cout << endl;
}

int main()
{
	myBag* bag;
	int choice, item;

	while (1)
	{
		cout << "\n---------------------" << endl;
		cout << "Multiset/Bag Example" << endl;
		cout << "\n---------------------" << endl;
		cout << "1.Init Multiset/Bag" << endl;
		cout << "2.Insert Number into the Multiset/Bag" << endl;
		cout << "3.Delete Element from the Multiset/Bag" << endl;
		cout << "4.Delete all element from the Multiset/Bag" << endl;
		cout << "5.Count Elements with a specific key" << endl;
		cout << "6.Check EQUAL of both Multiset/Bag" << endl;
		cout << "7.Check sub Mutiset/Bag" << endl;
		cout << "8.UNION Mutiset/Bag" << endl;
		cout << "9.Exit" << endl;
		cout << "Enter your Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			bag = initBag();
			cout << "Initizised bag.";
			break;
		case 2:
			cout << "Enter value to be inserted: ";
			cin >> item;
			insert(&bag, item);
			printBag(bag);
			break;
		case 3:
			cout << "Enter value to be deleted: ";
			cin >> item;
			deleteItem(&bag, item);
			printBag(bag);
			break;
		case 4:
			cout << "Delete all bag.";
			deleteAll(&bag);
			printBag(bag);
			break;
		case 5:
			cout << "Enter element to be counted: ";
			cin >> item;
			cout << item << " appears " << countItem(&bag, item) << " times." << endl;
			break;
		case 6:
			break;
		case 7:
			cout << "Elements of the Multiset:  ";

			cout << endl;
			break;
		case 8:

			break;
		case 9:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}

	return 0;
}