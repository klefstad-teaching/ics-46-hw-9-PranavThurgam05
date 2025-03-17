#include "ladder.h"


void error(string word1, string word2, string msg) {
    cerr << "Word 1: " << word1 << "Word 2: " << word2 << "Message: " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int differences = 0;
    int i = 0;
    int j = 0;
    int str1_iter = str1.length();
    int str2_iter = str2.length();
    if (abs(str1_iter - str2_iter) > d) return false;
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

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    if (begin_word == end_word) {
        error(begin_word, end_word, "invalid input, start and end the same");
        return vector<string>();
    }
    std::queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    std::set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for (auto word: word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word) return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return vector<string>();
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    word_list.clear();
    string word;
    while (in >> word) {
        word_list.insert(word);
    }
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout << "No word ladder found." << endl;
        return;
    }
    cout << "Word ladder found: "
    for (auto word: ladder) {
        cout << word << " ";
    }
    cout << endl;
}

void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}