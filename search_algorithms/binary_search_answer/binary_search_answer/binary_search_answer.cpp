#include <iostream>

bool can(int x, int array[], int array_size, int k) {
	int sum = 0;
	int count = 1;
	for (int i = 0; i < array_size; i++) {
		sum += array[i];
		if (sum > x) {
			count += 1;
			sum = array[i];
		}
		if (count > k) {
			std::cout << "Wrong x = " << x << std::endl;
			return false;
		}
	}
	return true;
}

int binary_search_answer(int array[], int array_size, int k) {
	int min_sum = -9999;
	int max_sum = 0;
	for (int i = 0; i < array_size; i++) {
		if (array[i] > min_sum) min_sum = array[i];
		max_sum += array[i];
	}
	std::cout << "min = " << min_sum << "\t" << "max = " << max_sum << std::endl;

	int mid = 0;
	int l = min_sum;
	int r = max_sum;
	while (l < r){
		mid = (l + r) / 2;
		if (can(mid, array, array_size, k)) {
			std::cout << "Correct x = " << mid << std::endl;
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return l;
}

int main()
{
	int array[9]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int array_size = sizeof(array) / sizeof(array[0]);
	int k = 3;
	binary_search_answer(array, array_size, k);
}

