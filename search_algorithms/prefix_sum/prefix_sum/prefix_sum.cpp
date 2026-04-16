#include <iostream>

void prefix_sum(int array[], int prefix_array[], int array_size) {
	prefix_array[0] = array[0];
	for (int i = 1; i < array_size; i++) {
		prefix_array[i] = prefix_array[i - 1] + array[i];
	}
}

void output(int array[], int prefix_array[], int array_size) {
	for (int i = 0; i < array_size; i++) {
		std::cout << "index: " << i << "\t" << "array = " << array[i] << "\t" << "prefix_array = " << prefix_array[i] << std::endl;
	}
}


int main()
{
	int array[6] = { 7, 9, 0, 2, 1, 5 };
	int array_size = sizeof(array) / sizeof(array[0]);
	int prefix_array[6];
	prefix_sum(array, prefix_array, array_size);
	output(array, prefix_array, array_size);

	//example
	int count_1_4 = prefix_array[4] - prefix_array[0];
	std::cout << count_1_4;	
}
