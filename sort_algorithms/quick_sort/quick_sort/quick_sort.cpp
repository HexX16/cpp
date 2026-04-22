#include <iostream>
#include <vector>
#include <random>

void quick_sort(std::vector<int>&, int, int);
void output_array(const std::vector<int>&);
void gen_array(std::vector<int>&);
void swap(std::vector<int>&, int, int);

int main()
{
	const int array_size = 100;
	std::vector<int> array(array_size);
	gen_array(array);

	std::cout << "before:\t";
	output_array(array);
	quick_sort(array, 0, array_size-1);
	std::cout << "\nafter:\t";
	output_array(array);
}

void quick_sort(std::vector<int>& array, int l, int r) {
	if (l >= r) return;

	int pivot = array[(l + r) / 2];
	std::cout << "pivot = " << pivot << std::endl;

	int i = l;
	int j = r;

	while (i <= j) {
		while (array[i] < pivot) i++;
		while (array[j] > pivot) j--;

		if (i <= j) {
			swap(array, i, j);
			i++;
			j--;
		}
		std::cout << "l = " << l << "\tr = " << r << std::endl;
	}

	quick_sort(array, l, j);
	quick_sort(array, i, r);
}
	
void swap(std::vector<int>& array, int i, int j) {
	int ch = array[i];
	array[i] = array[j];
	array[j] = ch;
}

void output_array(const std::vector<int>& array) {
	for (int i = 0; i < array.size(); i++) {
		std::cout << array[i] << " ";
	}
	std::cout << "\n" << std::endl;
}

void gen_array(std::vector<int>& array) {
	std::random_device rd;              // источник энтропии
	std::mt19937 gen(rd());             // генератор
	std::uniform_int_distribution<> dist(1, 100); // диапазон
	for (int i = 0; i < array.size(); i++) {
		array[i] = dist(gen);
	}
}

