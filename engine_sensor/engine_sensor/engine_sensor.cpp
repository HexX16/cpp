#include <iostream>
#include <conio.h>
#include <windows.h>

int main()
{
	std::cout << "Up arrow - gas" << std::endl;
	
	const double MAX_TEMP_COOL_LIQUID {170};
	const double NORM_TEMP_COOL_LIQUID{ 95 };
	double temp_cool_liquid{ 140 };

	while (true) {
		while (temp_cool_liquid < NORM_TEMP_COOL_LIQUID - 5) {
			temp_cool_liquid += 0.2;
			std::cout << "Temperature cool liquid = " << temp_cool_liquid << std::endl;
			Sleep(20);
		}

		if (_kbhit()) {
			int key{ _getch() };
			if (key == 72) {
				temp_cool_liquid += 0.2;
				std::cout << "Temperature cool liquid = " << temp_cool_liquid << std::endl;
				Sleep(10);
			}
		} else {
			if (temp_cool_liquid > NORM_TEMP_COOL_LIQUID + 5) {
				temp_cool_liquid -= 0.1;
				std::cout << "Temperature cool liquid = " << temp_cool_liquid << std::endl;
				Sleep(20);
			}
		}

		if (temp_cool_liquid > MAX_TEMP_COOL_LIQUID - 20) {
			std::cout << "WARNING: Temperature cool liquid = " << temp_cool_liquid << std::endl;
			Sleep(10);
		}

		if (temp_cool_liquid >= MAX_TEMP_COOL_LIQUID) {
			std::cout << "BOOOOM BOOOOM BOOOOM";
			std::cin.get();
			return 0;
		}
	}
}
