#include <iostream>

void square(int* x) {
	*x *= *x;
}

int main()
{
	int n = 5;
	int* ptr_n = &n;
	std::cout << ptr_n << std::endl;
	ptr_n++;
	std::cout << ptr_n <<"\n" << std::endl;

	int array[2]{ 1,2 };
	std::cout << array << " = " << *array << "\n" << array + 1 << " = " << *(array + 1) << "\n" << std::endl;

	std::cout << "Input n = ";
	std::cin >> n;
	square(&n);
	std::cout << "Square n = " << n << std::endl;
}
