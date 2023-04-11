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
void insert(myBag** latestBag, int value, int seqValue = 0)
{
	if (*latestBag == NULL)
	{
		*latestBag = newBag(value, 1);
	}
	else
	{
		if ((*latestBag)->value == value)
		{
			(*latestBag)->seq = seqValue == 0 ? (*latestBag)->seq + 1 : (*latestBag)->seq + seqValue;
		}
		else
		{
			myBag* tmp = newBag(value, seqValue == 0 ? 1 : seqValue);
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

	myBag* current = *bag;

	while (current != NULL) {
		if (current->value == value)
		{
			return current->seq;
		}
		current = current->next;
	}

	return 0;
}

void printBag(myBag* bag) {
	myBag* current = bag;
	if (isEmptyBag(bag)) {
		cout << "Bag is empty." << endl;
		return;
	}

	cout << "Current bag:" << endl;

	while (current != NULL) {
		cout << " " << current->value << "[" << current->seq << "]";
		current = current->next;
	}
	cout << endl;
}

myBag* insertBagByElements(int elements) {
	myBag* bag = initBag();

	int item = 0;
	for (int i = 0; i < elements; i++) {
		cout << "Enter value of element " << i+1 << ":";
		cin >> item;
		insert(&bag, item);
	}

	return bag;
}

void sortBag(myBag* bag) {
	//Node current will point to head  
	myBag* current = bag, * index = NULL;
	int temp_value;
	int temp_seq;

	if (bag == NULL) {
		return;
	}
	else {
		while (current != NULL) {
			//Node index will point to node next to current  
			index = current->next;

			while (index != NULL) {
				//If current node's data is greater than index's node data, swap the data between them  
				if (current->value > index->value) {
					temp_value = current->value;
					temp_seq = current->seq;

					current->value = index->value;
					current->seq = index->seq;

					index->value = temp_value;
					index->seq = temp_seq;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

void compareBags(myBag* bag1, myBag* bag2) {
	while (bag1 != NULL) {
		while (bag2 != NULL)
		{
			if (bag1->value != bag2->value) {
				cout << "RESULT: BAG 1 is not equal BAG 2";
				return;
			}

			if (bag1->value == bag2->value && bag1->seq != bag2->seq)
			{
				cout << "RESULT: BAG 1 is not equal BAG 2";
				return;
			}

			break;
		}

		bag2 = bag2->next;
		bag1 = bag1->next;
	}

	cout << "RESULT: BAG 1 is equal BAG 2";
}

void checkSubBag(myBag* bag1, myBag* bag2) {
	while (bag1 != NULL) {
		while (bag2 != NULL)
		{
			if (bag1->value != bag2->value) {
				cout << "RESULT: BAG 1 is not equal BAG 2";
				return;
			}

			if (bag1->value == bag2->value && bag1->seq != bag2->seq)
			{
				cout << "RESULT: BAG 1 is not equal BAG 2";
				return;
			}

			break;
		}

		bag2 = bag2->next;
		bag1 = bag1->next;
	}

	cout << "RESULT: BAG 1 is equal BAG 2";
}

void unionAllBag(myBag* bag1, myBag* bag2) {
	myBag* result_bag = initBag();

	while (bag1 != NULL) {
		insert(&result_bag, bag1->value, bag1->seq);
		bag1 = bag1->next;
	}

	while (bag2 != NULL)
	{
		insert(&result_bag, bag2->value, bag2->seq);
		bag2 = bag2->next;
	}

	cout << "BAG 1 UNION ALL BAG 2" << endl;
	printBag(result_bag);
}

void multipleBagActions(int action) {
	int el1 = 0;
	cout << "BAG 1. Please input number of elements:";
	cin >> el1;
	myBag* bag1 = insertBagByElements(el1);
	
	int el2 = 0;
	cout << "BAG 2. Please input number of elements:";
	cin >> el2;
	myBag* bag2 = insertBagByElements(el2);

	printBag(bag1);
	printBag(bag2);

	if (el1 != el2 && action == 1)
	{
		cout << "RESULT: BAG 1 is not equal BAG 2.";
		return;
	}

	sortBag(bag1);
	sortBag(bag2);

	switch (action)
	{
		case 1:
			compareBags(bag1, bag2);
			break;
		case 2:
			checkSubBag(bag1, bag2);
		case 3:
			unionAllBag(bag1, bag2);
		default:
			break;
	}
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
		cout << "7.Check SUB Mutiset/Bag" << endl;
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
			cout << "Check EQUAL of both Multiset/Bag: " << endl;
			multipleBagActions(1);
			break;
		case 7:
			cout << "Check SUB Mutiset/Bag:"<<endl;
			multipleBagActions(2);
			break;
		case 8:
			cout << "UNION Mutiset/Bag:" << endl;
			multipleBagActions(3);
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