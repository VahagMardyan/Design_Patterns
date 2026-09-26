#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 1, 2, 3, 4, 511, 4, 511, 19, 31, 6, 6, 0, 0};
    int result = 0;
    const int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < arr_size; i++) {
        result ^= arr[i];
    }

    int u_num1 = 0;
    int u_num2 = 0;
    int mask = result & -result;
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] & mask) {
            u_num1 ^= arr[i];
        } else {
            u_num2 ^= arr[i];
        }
    }
    std::cout << "num1: " << u_num1 << std::endl << "num2: " << u_num2 << std::endl; 
    return 0;
}