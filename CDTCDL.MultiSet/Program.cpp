#include <iostream>
#include <map>
using namespace std;

map<int, int> Dictionary;

void initDictionary() {
	Dictionary = {};
}

void insert(int key) {
	
}

int main() {
	Dictionary =
	{
		{1, 3},
		{2, 2},
		{3, 1}
	};

	// Get an iterator pointing to the first element in the map
	map<int, int>::iterator it = Dictionary.begin();

	// Iterate through the map and print the elements
	while (it != Dictionary.end())
	{
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
		++it;
	}
	cout << endl;

	return EXIT_SUCCESS;
}