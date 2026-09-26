#include <iostream>
#include <string>

int alternatingCharacters(std::string s) {
    int deletions = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i] == s[i+1]) {
            deletions ++;
        }
    }
    return deletions;
}