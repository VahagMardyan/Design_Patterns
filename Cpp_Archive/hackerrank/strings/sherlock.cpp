#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string isValid(std::string s) {
    int freq[26] = {0};
    for(char c : s) {
        freq[c - 'a'] ++;
    }

    std::vector<int> freq_list;
    for(int i=0;i<26;i++) {
        if(freq[i] > 0) {
            freq_list.push_back(freq[i]);
        }
    }

    std::sort(freq_list.begin(), freq_list.end());

    // // case 1: all the same frequency
    if(freq_list.front() == freq_list.back()) {
        return "YES";
    } 
    
    // // case 2: remove one from the largest freq
    if(freq_list[freq_list.size() - 1] - freq_list[0] == 1 && 
        freq_list[freq_list.size() - 1] !=  freq_list[freq_list.size() - 2]) {
            return "YES";
    }

    // // case 3: remove the only one 1-frequency character
    if(freq_list[0] == 1 && freq_list[1] == freq_list.back()) {
        return "YES";
    }

    return "NO";
}

int main() {
    std::string s = "abcdefghhgfedecba";
    std::string res = isValid(s);
    // std::string res = makeUnique(s);
    std::cout<<res<<std::endl;
    return 0;
}