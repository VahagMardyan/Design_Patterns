#include <iostream>
#include <vector>

long array_manipulation(int n, std::vector<std::vector<int>>& queries) {
    std::vector<long> arr(n+2,0);
    for(auto& q: queries) {
        int a = q[0];
        int b = q[1];
        int k = q[2];
        arr[a] += k;
        arr[b+1] -= k;
    }
    long max_val = 0;
    long current = 0;
    for(int i=1;i<=n;i++) {
        current += arr[i];
        if (current > max_val) max_val = current;
    }
    return max_val;
}

int main() {
    int n, m;
    std::cout << "Enter the size of the array and number of operations: ";
    std::cin >> n >> m;

    std::vector<std::vector<int>> queries(m, std::vector<int>(3));
    std::cout << "Enter the operations (a b k) each:\n";
    for (int i = 0; i < m; i++) {
        std::cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    long result = array_manipulation(n, queries);
    std::cout << "Maximum value after all operations: " << result << std::endl;

    return 0;
}