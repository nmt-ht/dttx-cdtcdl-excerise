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
		*latestBag = newBag(value, 0);
	}
	else
	{
		if ((*latestBag)->value == value)
		{
			(*latestBag)->seq = (*latestBag)->seq + 1;
		}
		else
		{
			myBag* tmp = newBag(value, 0);
			(*latestBag)->next = tmp;
		}
	}
}

void printBag(myBag* bag) {
	//Node current will point to head  
	myBag* current = bag;
	if (bag == NULL) {
		cout << "Bag is empty" << endl;
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
		cout << "0.Init Multiset/Bag" << endl;
		cout << "1.Insert Number into the Multiset/Bag" << endl;
		cout << "2.Delete Element from the Multiset/Bag" << endl;
		cout << "3.Find Element in a Multiset/Bag" << endl;
		cout << "4.Count Elements with a specific key" << endl;
		cout << "5.Size of the Multiset/Bag" << endl;
		cout << "6.Display Multiset/Bag" << endl;
		cout << "7.First Element of the Multiset/Bag" << endl;
		cout << "8.Exit" << endl;
		cout << "Enter your Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			bag = initBag();
			cout << "Initizised bag.";
			break;
		case 1:
			cout << "Enter value to be inserted: ";
			cin >> item;
			insert(&bag, item);
			printBag(bag);
			break;
		case 2:
			cout << "Enter value to be deleted: ";
			cin >> item;

			break;
		case 3:
			cout << "Enter element to find ";
			cin >> item;

			break;
		case 4:
			cout << "Enter element to be counted: ";
			cin >> item;
			//cout << item << " appears " << ms.count(item) << " times." << endl;
			break;
		case 5:
			//cout << "Size of the Multiset: " << ms.size() << endl;
			break;
		case 6:
			cout << "Elements of the Multiset:  ";

			cout << endl;
			break;
		case 7:

			break;
		case 8:
			exit(1);
			break;
		default:
			cout << "Wrong Choice" << endl;
		}
	}

	return 0;
}