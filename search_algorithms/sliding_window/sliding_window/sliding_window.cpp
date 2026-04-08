#include <iostream>

int default_On2(int array[], int array_size, int goal, int k) {
    //default O(n^2)
    for (int i = 0; i < array_size - k  + 1; i++) {
        int sum = array[i];
        for (int j = i + 1; j < i + k; j++) {
            sum += array[j];
        }
        if (sum == goal) {
            std::cout << "Start window = " << i << std::endl;
            return 0;
        }
    }
    std::cout << "Not goal" << std::endl;
    return -1;
}

int sliding_window(int array[], int array_size, int goal, int k) {
    //sliding_window O(n)
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += array[i];
    }
    
    for (int l = 0, r = k - 1; r < array_size; l++, r++) {
        if (sum == goal) {
            std::cout << "Start window = " << l;
            return 0;
        }
        else {
            sum = sum - array[l] + array[r + 1];
        }
        std::cout << sum << std::endl;
    }

    std::cout << "Not goal" << std::endl;
    return -1;
}

int main()
{
    int array[7]{ 1, 3, 5, 6, 8, 9, 11 };
    int array_size = sizeof(array) / sizeof(array[0]);
    int k = 3;
    int goal = 28;

    default_On2(array, array_size, goal, k);
    sliding_window(array, array_size, goal, k);
}
