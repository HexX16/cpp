#include <iostream>

int binary_search(int array[], int array_size, int goal) {
	//binary_search O(log(n))
	int l = 0;
	int r = array_size - 1;
	int mid = 0;
	while (l <= r) {
		std::cout << "mid = " << mid << "\t" << "l = " << l << "\t" << "r = " << r << std::endl;
		mid = (l + r) / 2;
		if (array[mid] == goal) {
			std::cout << "Goal = " << "array["<<mid<<"] = "<< array[mid]<<std::endl;
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

int main()
{
	int array[8]{ 1, 3, 6, 10, 11, 20, 22, 23 };
	int array_size = sizeof(array) / sizeof(array[0]);
	int goal = 21;
	binary_search(array, array_size, goal);
}

