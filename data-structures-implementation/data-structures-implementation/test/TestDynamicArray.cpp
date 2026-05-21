#include <iostream>
#include <../linear-data-structures/DynamicArray.hpp>

int main() {
	std::cout << "--- DynamicArray Test ---\n\n";

	DynamicArray<int> arr;
	std::cout << "Initialized an empty array of int\n\n";

	for (int i = 0; i < 10; i++)
		arr.push_back(i);
	std::cout << "Initialized the array with 0, 1, 2, 3, 4, 5, 6, 7, 8, 9\n\n";

	std::cout << "Array printed with print method: ";
	arr.print();
	std::cout << '\n';

	std::cout << "Array after pop_back(): ";
	arr.pop_back();
	arr.print();
	std::cout << '\n';

	std::cout << "Array after removing index 3: ";
	arr.remove(3);
	arr.print();
	std::cout << '\n';

	std::cout << "Array after adding 49 at index 5: ";
	arr.push(49, 5);
	arr.print();
	std::cout << '\n';

	std::cout << "Array iterated: ";
	for (auto& el : arr)
		std::cout << el << ' ';
	std::cout << "\n\n";

	std::cout << "Array after clear: ";
	arr.clear();
	arr.print();

	return 0;
}