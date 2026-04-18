#include <iostream>
#include <vector>
#include <random>

void gen_vector(std::vector<int>&);
void output_array(const std::vector<int>&);
int binary_search(const std::vector<int>&, int);
std::random_device rd; // Недетерминированный источник семян

int main()
{
	int array_size = 10'000;
	std::vector<int> array(array_size);
	int goal = 12023;

	gen_vector(array);
	binary_search(array, goal);
}

int binary_search(const std::vector<int>& array, int goal) {
	//binary_search O(log(n))
	int l = 0;
	int r = array.size() - 1;
	int mid = 0;
	while (l <= r) {
		//std::cout << "mid = " << mid << "\t" << "l = " << l << "\t" << "r = " << r << std::endl;
		mid = (l + r) / 2;
		if (array[mid] == goal) {
			std::cout << "Goal = " << "array[" << mid << "] = " << array[mid] << std::endl;
			return 0;
		}
		else if (array[mid] < goal) {
			l = mid + 1;
		}
		else if (array[mid] > goal) {
			r = mid - 1;
		}
	}
	std::cout << "Not goal" << std::endl;
	return -1;
}

void gen_vector(std::vector<int>& array) {
	array[0] = 1;
	static std::mt19937 gen(rd()); // Генератор Mersenne Twister
	std::uniform_int_distribution<int> dist(1, 10); // Распределение чисел
	int dg = 0;
	for (int i = 1; i < array.size(); i++) {	
		dg = dist(gen);
		if (dg <= 5) {
			array[i] = array[i - 1] + 1;
		}
		else{
			array[i] = array[i - 1] + 3;
		}
	}
}

void output_array(const std::vector<int>& array) {
	for (int i = 0; i < array.size(); i++) {
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n";
}

