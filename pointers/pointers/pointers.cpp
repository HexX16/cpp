#include <iostream>

void square(int* x) {
	*x *= *x;
}

void change_elem(int* array) {
	*array = *(array + 1);
}

int main()
{
	/*int n = 5;
	int* ptr_n = &n;
	std::cout << ptr_n << " = " << *ptr_n << std::endl;
	ptr_n++;
	std::cout << ptr_n << " = " << *ptr_n << "\n" << std::endl;

	std::cout << "array_1" << std::endl;
	int array_1[2]{ 1,2 };
	std::cout << array_1 << " = " << *array_1 << "\n" << array_1 + 1 << " = " << *(array_1 + 1) << "\n" << std::endl;

	std::cout << "Input n = ";
	std::cin >> n;
	square(&n);
	std::cout << "Square n = " << n << "\n" << std::endl;*/

	std::cout << "array_2" << std::endl;
	int array_2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << *array_2 << "\n";
	change_elem(array_2);
	std::cout << *array_2;
}
