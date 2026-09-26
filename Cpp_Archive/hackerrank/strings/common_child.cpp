#include <iostream>
#include <vector>
#include <string>

int get_max(int a, int b) {
    return a > b ? a : b;
}

int commonChild(std::string s1, std::string s2) {
    int n = s1.size();

    // (n+1) * (n+1) table filled with 0
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1, 0));

    // fill the table
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            
            // if characters match then extend LCS (Longest Common Subsequence)
            if(s1[i-1] == s2[j - 1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else { 
                dp[i][j] = get_max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}