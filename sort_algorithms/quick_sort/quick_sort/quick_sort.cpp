#include <iostream>
#include <vector>
#include <random>

void quick_sort(const std::vector<int>&);
void output_array(const std::vector<int>&);
void gen_array(std::vector<int>&);

int main()
{
	const int array_size = 100;
	std::vector<int> array(array_size);
	gen_array(array);

	std::cout << "before:\t";
	output_array(array);

	//std::cout << "\nafter:\t";
	//output_array(array);
}

void quick_sort( std::vector<int>& array) {

}

void output_array(const std::vector<int>& array) {
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