#include "ladder.h"

int main() {
    set<string> word_list;
    load_words(word_list, "/home/pthurgam/ICS46/HW9/src/words.txt");
    string start_word = "Aarhus";
    string end_word = "slippage";
    vector<string> res = generate_word_ladder(start_word, end_word, word_list);
    print_word_ladder(res);
    return 0;
}