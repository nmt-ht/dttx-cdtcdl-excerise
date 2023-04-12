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
void insert(myBag** bag, int value, int seqValue = 1)
{
	myBag* start = *bag;

	if (*bag == NULL)
	{
		*bag = newBag(value, seqValue);
	}
	else
	{
		//create new bag
		myBag* temp = newBag(value, seqValue);

		while (start->next != NULL) 
		{
			if (start->next->value == value)
			{
				start->next->seq = start->next->seq + seqValue;
				free(temp);
				return;
			}
			start = start->next;
		}

		temp->next = start->next;
		start->next = temp;
	}
}

void deleteItem(myBag** latestBag, int value) {
	if (isEmptyBag(*latestBag)) return;

	myBag* current = *latestBag, * index = NULL;
	bool isDeleted = false;

	while (current != NULL) {
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
	for (int i = 1; i <= elements; i++) {
		cout << "Enter value of element " << i << ":";
		cin >> item;
		insert(&bag, item);
	}

	return bag;
}

void sortBag(myBag* bag) {
	myBag* current = bag, * index = NULL;
	int temp_value;
	int temp_seq;

	if (bag == NULL) {
		return;
	}
	else {
		while (current != NULL) {
			index = current->next;

			while (index != NULL) {
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

void checkSubBag(myBag* bag1, myBag* bag2, int elOfBag1, int elOfBag2) {
	int i = 0;
	int j = 0;
	while (bag1 != NULL) {
		while (bag2 != NULL)
		{
			if (bag1->value == bag2->value && bag1->seq <= bag2->seq)
			{
				break;
			}
			j++;
			bag2 = bag2->next;
		}

		if (j == elOfBag2)
		{
			cout << "RESULT: BAG 1 is not subset of BAG 2";
			return;
		}
		i++;
		bag1 = bag1->next;
	}

	cout << "RESULT: BAG 1 is subset of BAG 2";
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
			checkSubBag(bag1, bag2, el1, el2);
			break;
		case 3:
			unionAllBag(bag1, bag2);
			break;
		default:
			break;
	}
}

bool checkInitBag(bool value) {
	if (!value)
	{
		cout << "\n*** PLEASE INIT BAG TO CONTINUE. ***" << endl;
		return false;
	}
	return true;
}

int main()
{
	myBag* bag;
	int choice, item;
	bool hasInitBag = false;
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
			hasInitBag = true;
			cout << "WELCOME to your bag.";
			break;
		case 2:
			if (!checkInitBag(hasInitBag)) break;
			cout << "Enter value to be inserted: ";
			cin >> item;
			insert(&bag, item);
			printBag(bag);
			break;
		case 3:
			if (!checkInitBag(hasInitBag)) break;
			cout << "Enter value to be deleted: ";
			cin >> item;
			deleteItem(&bag, item);
			printBag(bag);
			break;
		case 4:
			if (!checkInitBag(hasInitBag)) break;
			cout << "Delete all bag.";
			deleteAll(&bag);
			printBag(bag);
			break;
		case 5:
			if (!checkInitBag(hasInitBag)) break;
			cout << "Enter element to be counted: ";
			cin >> item;
			cout << item << " appears " << countItem(&bag, item) << " times." << endl;
			break;
		case 6:
			if (!checkInitBag(hasInitBag)) break;
			cout << "Check EQUAL of both Multiset/Bag: " << endl;
			multipleBagActions(1);
			break;
		case 7:
			if (!checkInitBag(hasInitBag)) break;
			cout << "Check SUBSET OF Mutiset/Bag:"<<endl;
			multipleBagActions(2);
			break;
		case 8:
			if (!checkInitBag(hasInitBag)) break;
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