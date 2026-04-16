#include <iostream>

int sliding_window_var_size(int array[], int array_size, int k) {
	int l = 0;
	int r = 0;
	int sum = 0;
	while (l<r){
		sum += array[r];
		if (sum >= k) {
			l--;
		}
		else{
			r++;
		}
	}
	std::cout << (r - l);
	return (r - l);
}

int main()
{
	// Найти минимальную длину непрерывного подмассивa, сумма которого ≥ k
	int array[6]{ 2, 3, 1, 2, 4, 3 };
	int array_size = sizeof(array) / sizeof(array[0]);
	int k = 7;
	sliding_window_var_size(array, array_size, k);
}
