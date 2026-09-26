#include <iostream>
#include <vector>

int minimum_swaps(std::vector<int>& arr) {
    int n = arr.size();
    int swaps = 0;

    for(int i=0;i<n;i++) {
        while(arr[i] != i+1) {
            int correct_index = arr[i] - 1;
            int temp = arr[i];
            arr[i] = arr[correct_index];
            arr[correct_index] = temp;
            swaps++;
        }
    }
    return swaps;
}

int main() {
    int n;
    std::cout<<"n=";std::cin>>n;
    std::vector<int>a(n);
    for(int i=0;i<n;i++) {
        std::cin>>a[i];
    }
    int min_s = minimum_swaps(a);
    std::cout<<"The amount of minimum swaps: "<<min_s<<'\n';
    return 0;
}