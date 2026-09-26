#include <iostream>

// // It's assumed that the transmitted array is sorted
int find(int *arr, size_t size, int value) {
    int i = size / 2;
    while(i > 0 && i < size) {
        if(value < arr[i]) {
            i -= i/2;
        } else if(value > arr[i]) {
            i += i/2;
        } else {
            return i;
        }
    }
    return -1;
}

// // Binary search algorithm
int binary_search(int *arr, size_t size, int value) {
    if(size == 0) {
        return -1;
    }
    
    if(arr[size/2] == value) {
        return size/2;
    } else if(arr[size/2] > value) {
        return binary_search(arr, size/2, value);
    } else {
        int result = binary_search(arr + size/2 + 1, size - size/2 - 1, value);
        if(result == -1) return -1;
        return result + size/2 + 1;
    }
}

int main() {
    int x[] = {1,2,4,8,6,7,9};
    int len = sizeof(x) / sizeof(x[0]);
    int v1 = 8;
    int f1 = binary_search(x,len,v1); // -1
    std::cout<<f1<<'\n';
    int v2 = 6;
    // int f2 = find(x,len,v2); // 3
    int f2 = binary_search(x,len,8);
    std::cout<<f2<<'\n';
    return 0;
}