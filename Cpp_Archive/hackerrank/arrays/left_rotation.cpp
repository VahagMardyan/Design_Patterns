#include <iostream>
#include <vector>

std::vector<int> rotate_left(std::vector<int> arr, int d) {
    int n = arr.size();
    std::vector<int>rotated(n);
    for(int i=0;i<n;i++) {
        rotated[i] = arr[(i+d)%n];
    }
    return rotated;
}

int main() {
    int n,d;
    std::cout<<"(n;d): ";std::cin>>n>>d;
    std::vector<int> arr(n);
    std::cout<<"Input array: "<<"\n";
    for(int i=0;i<n;i++) {
        std::cin>>arr[i];
    }
    std::vector<int> result = rotate_left(arr,d);
    for(int i=0;i<n;i++) {
        std::cout<<result[i]<<" ";
    }
    std::cout<<'\n';
    return 0;
}