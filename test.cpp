//
// Created by sean on 10/3/16.
//

#include "gtest/gtest.h"
#include "linkedlist.h"
#include <map>

class LinkedListTest : public  ::testing::Test {
protected:
    void SetUp() {
        ilist = {0, 1, 2, 5};
    }

    LinkedList<int> ilist;
};

TEST_F(LinkedListTest, testInitListSize) {
    ASSERT_EQ(ilist.size(), 4);
}

TEST_F(LinkedListTest, testForRangeCompletes) {
    // Makes sure the range for iterator exhausts the whole list
    // i should be equal to the list size after loop
    int i = 0;
    for (auto x: ilist) {
        ++i;
    }
    ASSERT_EQ(i, ilist.size());

}

TEST_F(LinkedListTest, testForRangeValues) {
    std::map<int, int> expected{{0, 0},
                                {1, 1},
                                {2, 2},
                                {3, 5}};

    int i = 0;
    for (auto x: ilist) {
        // value matches expected
        ASSERT_EQ(x, expected[i++]);
        x++;  // increment to ensure the original list is not modified
    }

    i = 0;
    for (auto x: ilist) {
        // values should still match
        ASSERT_EQ(x, expected[i++]);
    }
}

TEST_F(LinkedListTest, testRefForRange) {
    std::map<int, int> expected2{{0, 1},
                                {1, 2},
                                {2, 3},
                                {3, 6}};

    // increment the value using ref iterator
    for (auto &x: ilist) {
        x++;
    }

    int i = 0;
    for (auto x: ilist) {
        // original should be incremented
        ASSERT_EQ(x, expected2[i++]);
    }

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

