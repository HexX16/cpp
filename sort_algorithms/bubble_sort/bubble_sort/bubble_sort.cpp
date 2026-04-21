#include <iostream>
#include <vector>
#include <random>

void bubble_sort(std::vector<int>&);
void swap(std::vector<int>&, int, int);
void output_array(const std::vector<int>&);
void gen_array(std::vector<int>&);

int main()
{
	
	const int array_size = 100;
	std::vector<int> array(100);
	gen_array(array);

	std::cout << "before:\t";
	output_array(array);
	bubble_sort(array);
	std::cout << "\nafter:\t";
	output_array(array);
}

void bubble_sort(std::vector<int>& array) {
	bool flag = true;
	int size = array.size();
	while (flag) {
		flag = false;
		for (int i = 0; i < size - 1; i++) {
			if (array[i] > array[i + 1]) {
				swap(array, i, i + 1);
				flag = true;
			}
		}
		size--;
	}
}

void swap(std::vector<int>& array, int l, int r) {
	int ch = array[r];
	array[r] = array[l];
	array[l] = ch;
}

void output_array(const std::vector<int> &array) {
	for (int i = 0; i < array.size(); i++) {
		std::cout << array[i] << " ";
	}
}

void gen_array(std::vector<int>& array) {
	std::random_device rd;              // источник энтропии
	std::mt19937 gen(rd());             // генератор
	std::uniform_int_distribution<> dist(1, 100); // диапазон
	for (int i = 0; i < array.size(); i++) {
		array[i] = dist(gen);
	}
}