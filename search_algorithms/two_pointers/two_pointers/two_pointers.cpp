#include <iostream>

int default_On2(int array[], int array_size, int goal) {
	//default O(n^2)
	for (int i = 0; i < array_size - 1; i++) {
		for (int j = i + 1; j < array_size; j++) {
			if (array[i] + array[j] == goal) {
				std::cout << array[i] << "\t" << array[j] << std::endl;
				return 0;
			}
		}
	}
	std::cout << "Not goal" << std::endl;
}

int two_pointers(int array[], int array_size, int goal) {
	//two pointer O(n)
	int l = 0;
	int r = array_size - 1;
	while (l < r) {
		if (array[l] + array[r] == goal) {
			std::cout << array[l] << "\t" << array[r] << std::endl;
			return 0;
		}
		else if (array[l] + array[r] > goal) {
			r--;
		}
		else if ((array[l] + array[r] < goal)) {
			l++;
		}
	}
}

int main()
{
	int array[8] { 1, 3, 4, 5, 6, 7, 9, 10 };
	int array_size = sizeof(array) / sizeof(array[0]);
	int goal = 5;

	default_On2(array, array_size, goal);
	two_pointers(array, array_size, goal);

}

