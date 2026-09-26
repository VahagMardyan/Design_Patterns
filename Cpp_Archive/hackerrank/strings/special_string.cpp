#include <iostream>
#include <string>

long substrCount(int n, std::string s) {
    int result = 0;
    int i = 0;

    // case 1: all characters are the same. Ex. aaaa
    while(i < n) {
        int char_count = 1;
        while (i + 1 < n && s[i] == s[i+1]) {
            i++;
            char_count ++;
        }
        result += char_count * (char_count + 1) / 2;
        i++;
    }

    // case 2: search between substrings
    for(int i = 1;i<n;i++) {
        int char_count = 1;
        while (i + char_count < n && i - char_count >= 0
            && s[i] != s[i-1] && s[i - char_count] == s[i + char_count]
            && s[i - 1] == s[i - char_count]) {
                char_count ++;
        }
        result += char_count - 1;
    }
    return result;
}