#include <iostream>
#include <vector>
#include <random>

void bubble_sort(std::vector<int>&, int);
void swap(std::vector<int>&, int, int);
void output_array(std::vector<int>&);

int main()
{
	std::random_device rd;              // источник энтропии
	std::mt19937 gen(rd());             // генератор
	std::uniform_int_distribution<> dist(1, 100); // диапазон
	const int array_size = 100;
	std::vector<int> array(array_size);
	for (int i = 0; i < array_size; i++) {
		array[i] = dist(gen);
	}
	output_array(array);
	bubble_sort(array, array_size);
	output_array(array);
}

void bubble_sort(std::vector<int>& array, int array_size) {
	for (int i = 0; i < array_size - 2; i++) {
		if (array[i] > array[i + 1]) {
			swap(array, i, i + 1);
		}
	}
}

void swap(std::vector<int>& array, int l, int r) {
	int ch = array[r];
	array[r] = array[l];
	array[l] = ch;
}

void output_array(const std::vector<int> &array) {
	for (int i = 0; i < array.size(); i++) {
		std::cout << array[i];
	}
}