#include <iostream>

int main() {
    int arr[] = {1,2,3,1,2,3,4,5,4,5,99,7,7,6,6,0,0};
    int unique_el = 0;
    
    const int arr_size = sizeof(arr) / sizeof(arr[0]);

    for(int i=0;i<arr_size;i++) {
        unique_el = unique_el ^ arr[i];
    }

    std::cout<<unique_el<<std::endl;

    return 0;
}