#include <iostream>
#include <string>

int makeAnagram(std::string a, std::string b) {
    int freqA[26] = {0};
    int freqB[26] = {0};
    for(int i=0;i<a.size();i++) {
        char c = a[i];
        freqA[c - 'a'] ++;
    }
    for(int i=0;i<b.size();i++) {
        char c = b[i];
        freqB[c - 'a'] ++;
    }
    int deletions = 0;
    for(int i=0;i<26;i++) {
        deletions += std::abs(freqA[i] - freqB[i]);
    }
    return deletions;
}

int main() {
    std::string a = "cde";
    std::string b = "dcf";
    int x = makeAnagram(a,b);
    std::cout<<x<<std::endl;
    return 0;
}