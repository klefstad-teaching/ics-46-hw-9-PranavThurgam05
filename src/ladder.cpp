#include "ladder.h"


void error(string word1, string word2, string msg) {
    cerr << "Word 1: " << word1 << "Word 2: " << word2 << "Message: " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    if (abs(str1.length() - str2.length()) > d) return false;
    int differences = 0;
    int i = 0;
    int j = 0;
    int str1_iter = str1.length();
    int str2_iter = str2.length();
    while (i < str1_iter && j < str2_iter) {
        if (str1[i] == str2[j]) {
            ++i;
            ++j;
            continue;
        }
        else {
            ++differences;
            if (differences > d) return false;
            if (str1_iter < str2_iter) ++j;
            else if (str1_iter > str2_iter) ++i;
            else {
                ++i;
                ++j;
            }
        }
    }
    if (i < str1_iter || j < str2_iter) {
        int add_char = max(str1_iter - i, str2_iter - j);
        differences += add_char;
    }
    return differences <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}