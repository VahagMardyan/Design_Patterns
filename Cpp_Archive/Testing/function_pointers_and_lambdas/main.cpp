#include <iostream>
#include <vector>
#include <algorithm>

void print(int v) {
        std::cout<< "Value: " <<v<<std::endl;
}

template <typename T, typename F>
void ForEach(std::vector<T>& values, F function) {
    for (T& value : values) {
        function(value);
    }
}

int main() {
    std::vector<int> values = {1, 2, 4 ,5};
    int sum = 0;
    int product = 1;
    int k = 4;
    
    // ForEach(values, print); // function pointer-ով

    ForEach(values, [&](int& x){
        sum += x; // հաշվում է գումարը
        product *= x; // հաշվում է արտադրյալը
        x *= k; // ամեն անդամը k անգամ մեծացնում է
    }); // lambda-ով

    for(int i=0;i<values.size(); i++) {
        std::cout<<values[i]<<" ";
    }
    // 4 8 16 20
    std::cout << std::endl;
    std::cout << "Sum: " << sum << std::endl; // 12
    std::cout << "Product: " << product << std::endl; // 40
    return 0;
}