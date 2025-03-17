#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Dijkstra, ShortestPathBasic) {
    Graph g;
    file_to_graph("/home/pthurgam/ICS46/HW9/src/medium.txt", g);
    g.push_back({1,5,0});
    g.push_back({5,0,6});
    g.push_back({2,6,2});
    g.push_back({1,6,1});

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(g, 0, previous);
    
    EXPECT_EQ(distances[0], 0);
    EXPECT_EQ(distances[1], 5);
    EXPECT_EQ(distances[2], 3);
}

TEST(Dijkstra, ExtractPath) {
    vector<int> previous = {-1, 0, 1, 2, 3};
    vector<int> distances = {0, 6, 4, 7, 5};

    vector<int> path = extract_shortest_path(distances, previous, 4);
    vector<int> expected = {0, 1, 2, 3, 4};

    EXPECT_EQ(path, expected);
}

TEST(WordLadder, BasicLadder) {
    set<string> word_list = {"code", "cade", "cate", "date", "data"};
    vector<string> ladder = generate_word_ladder("code", "data", word_list);
    vector<string> expected = {"code", "cade", "cate", "date", "data"};

    EXPECT_EQ(ladder, expected);
}

TEST(WordLadder, AllowsInsertDelete) {
    set<string> word_list = {"car", "cat", "chat", "cheat"};
    vector<string> ladder = generate_word_ladder("car", "cheat", word_list);
    vector<string> expected = {"car", "cat", "chat", "cheat"};

    EXPECT_EQ(ladder, expected);
}
