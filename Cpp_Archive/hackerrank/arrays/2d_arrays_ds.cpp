#include <iostream>
#include <vector>

int hourglass_sum(std::vector<std::vector<int>> arr) {
    int n = arr.size();
    int size = (n-2) * (n-2);
    int *hourglass = new int[size];
    int k = 0;
    for(int i=0;i<=n-3;i++) {
        for(int j=0;j<=n-3;j++) {
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] +
                arr[i+1][j+1] + 
                arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            hourglass[k++] = sum;
        }
    }
    int max = hourglass[0];
    for(int i=1;i<k;i++) {
        if(hourglass[i] > max) max = hourglass[i];
    }
    return max;
}

int main() {
    const int n = 6;
    std::vector<std::vector<int>> arr(6, std::vector<int>(6));
    std::cout<<"Input matrix: "<<'\n';
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            std::cin>>arr[i][j];
        }
    }
    int s = hourglass_sum(arr);
    std::cout<<"Max hourglass: "<<s<<'\n';
    return 0;
}