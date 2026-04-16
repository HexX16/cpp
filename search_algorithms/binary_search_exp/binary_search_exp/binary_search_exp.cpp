#include <iostream>
#include <vector>
#include <algorithm>


int bin_search_exp(const std::vector<int>&, int);

int main()
{
    const int array_size = 10'000;
    std::vector<int> array(array_size);
    for (int i = 0; i < array_size; i++) {
        array[i] = i;
    }

    int index = bin_search_exp(array, 10);
    std::cout << array[index];
}

int bin_search_exp(const std::vector<int>& array, int goal) {
    if (array.empty()) {
        std::cout << "array is empty";
        return -1;
    }
    if (array[0] == goal) {
        return 0;
    }

    int r = 1;
    while (r < array.size() && array[r] < goal) {
        r *= 2;
    }

    r = std::min(r, (int)array.size()-1);
    int l = r / 2;
    int mid = 0;
    std::cout << "l = " << l << "\t" << "r = " << r << std::endl;

    while (l <= r) {
        mid = l + (r - l) / 2;
        std::cout << "l = " << l << "\t" << "r = " << r << "\t" << "mid = " << mid << std::endl;
        if (array[mid] == goal) {
            std::cout << "index = " << mid << " : " << "value = " << array[mid] << std::endl;
            return mid;
        }
        else if (array[mid] > goal) {
            r = mid - 1;
        }
        else if (array[mid] < goal) {
            l = mid + 1;
        }
        
    }
    std::cout << "Not goal" << std::endl;
    return -1;
}