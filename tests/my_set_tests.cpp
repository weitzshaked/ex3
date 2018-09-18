#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../my_set.h"
#include <vector>

/////////////////////////////////////////////////////////////////////////
//          Tree used throughout the tests should look like:           //
//                                 10                                  //
//                                 / \                                 //
//                                5   15                               //
//                               / \  / \                              //
//                              2  8 12  17                            //
//                             /  / \  \                               //
//                            1  7   9  13                             //
/////////////////////////////////////////////////////////////////////////

TEST_CASE("Initialization tests")
{
    SECTION("Simple constructor")
    {
        my_set<int> mySet;
        std::set<int> stdSet;

        CHECK(mySet.empty() == stdSet.empty());
        CHECK(mySet.size() == stdSet.size());
    }

    SECTION("Range constructor")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        CHECK(mySet.empty() == stdSet.empty());
        CHECK(mySet.size() == stdSet.size());

        auto stdIt = stdSet.cbegin();
        auto myIt = mySet.cbegin();
        for (; myIt != mySet.cend(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Copy constructor")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        my_set<int> myOtherSet(mySet);
        std::set<int> stdSet(values.begin(), values.end());
        std::set<int> stdOtherSet(stdSet);

        CHECK(mySet.empty() == myOtherSet.empty());
        CHECK(stdSet.empty() == myOtherSet.empty());
        CHECK(mySet.size() == myOtherSet.size());
        CHECK(stdSet.size() == myOtherSet.size());

        auto stdIt = stdOtherSet.begin();
        for (auto myIt = myOtherSet.cbegin(); myIt != mySet.cend() && stdIt != stdOtherSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Move constructor")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        my_set<int> myOtherSet(std::move(mySet));
        std::set<int> stdSet(values.begin(), values.end());
        std::set<int> stdOtherSet(std::move(stdSet));

        CHECK(mySet.empty() == stdSet.empty());
        CHECK(mySet.size() == stdSet.size());
        CHECK(myOtherSet.empty() == stdOtherSet.empty());
        CHECK(myOtherSet.size() == stdOtherSet.size());

        auto stdIt = stdOtherSet.begin();
        for (auto myIt = myOtherSet.cbegin(); myIt != myOtherSet.cend() && stdIt != stdOtherSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Copy assignment")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        my_set<int> myOtherSet = mySet;
        std::set<int> stdSet(values.begin(), values.end());
        std::set<int> stdOtherSet = stdSet;

        CHECK(mySet.empty() == myOtherSet.empty());
        CHECK(stdSet.empty() == myOtherSet.empty());
        CHECK(mySet.size() == myOtherSet.size());
        CHECK(stdSet.size() == myOtherSet.size());

        auto stdIt = stdOtherSet.begin();
        for (auto myIt = myOtherSet.cbegin(); myIt != mySet.cend() && stdIt != stdOtherSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Move assignment")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        my_set<int> myOtherSet = std::move(mySet);
        std::set<int> stdSet(values.begin(), values.end());
        std::set<int> stdOtherSet = std::move(stdSet);

        CHECK(mySet.empty() == stdSet.empty());
        CHECK(mySet.size() == stdSet.size());
        CHECK(myOtherSet.empty() == stdOtherSet.empty());
        CHECK(myOtherSet.size() == stdOtherSet.size());

        auto stdIt = stdOtherSet.begin();
        for (auto myIt = myOtherSet.cbegin(); myIt != myOtherSet.cend() && stdIt != stdOtherSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Swap")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        my_set<int> myOtherSet;
        std::set<int> stdSet(values.begin(), values.end());
        std::set<int> stdOtherSet;

        std::swap(mySet, myOtherSet);
        std::swap(stdSet, stdOtherSet);

        CHECK(mySet.empty() == stdSet.empty());
        CHECK(mySet.size() == stdSet.size());
        CHECK(myOtherSet.empty() == stdOtherSet.empty());
        CHECK(myOtherSet.size() == stdOtherSet.size());

        auto stdIt = stdOtherSet.begin();
        for (auto myIt = myOtherSet.cbegin(); myIt != myOtherSet.cend() && stdIt != stdOtherSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }
}

TEST_CASE("Finding tests")
{
    std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
    my_set<int> mySet(values.begin(), values.end());
    std::set<int> stdSet(values.begin(), values.end());

    SECTION("Simple find works")
    {
        for (auto i : values)
        {
            CHECK(*mySet.find(i) == *stdSet.find(i));
        }
    }

    SECTION("Find nonexists item")
    {
        CHECK(mySet.find(25) == mySet.cend());
    }

    SECTION("Find item in empty set")
    {
        mySet.clear();
        CHECK(mySet.find(2) == mySet.cend());
    }
}

TEST_CASE("Insertion tests")
{
    SECTION("Simple insertion works")
    {
        my_set<int> mySet;
        std::set<int> stdSet;

        auto myRes = mySet.insert(2);
        auto stdRes = stdSet.insert(2);
        CHECK(*myRes.first == *stdRes.first);
        CHECK(myRes.second == stdRes.second);
    }

    SECTION("Inserting item twice")
    {
        my_set<int> mySet;
        std::set<int> stdSet;

        auto myFst = mySet.insert(2);
        auto myScn = mySet.insert(2);
        auto stdFst = stdSet.insert(2);
        auto stdScn = stdSet.insert(2);

        CHECK(*myFst.first == *stdFst.first);
        CHECK(myFst.second == stdFst.second);
        CHECK(*myScn.first == *stdScn.first);
        CHECK(myScn.second == stdScn.second);
    }

    SECTION("Inserting item to nonempty set")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myRes = mySet.insert(4);
        auto stdRes = stdSet.insert(4);
        CHECK(*myRes.first == *stdRes.first);
        CHECK(myRes.second == stdRes.second);
    }

    SECTION("Inserting item with hint - beginning")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myRes = mySet.insert(mySet.cbegin(), 0);
        auto stdRes = stdSet.insert(stdSet.cbegin(), 0);

        CHECK(*myRes == *stdRes);

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting item with hint - end")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myRes = mySet.insert(mySet.cend(), 20);
        auto stdRes = stdSet.insert(stdSet.cend(), 20);

        CHECK(*myRes == *stdRes);

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting item with hint - before hint")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myRes = mySet.insert(mySet.find(5), 3);
        auto stdRes = stdSet.insert(stdSet.find(5), 3);

        CHECK(*myRes == *stdRes);

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting item with hint - before first")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myRes = mySet.insert(mySet.find(1), 0);
        auto stdRes = stdSet.insert(stdSet.find(1), 0);

        CHECK(*myRes == *stdRes);

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting item with hint - after hint")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myRes = mySet.insert(mySet.find(5), 6);
        auto stdRes = stdSet.insert(stdSet.find(5), 6);

        CHECK(*myRes == *stdRes);

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting item with hint - after last")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myRes = mySet.insert(mySet.find(17), 20);
        auto stdRes = stdSet.insert(stdSet.find(17), 20);

        CHECK(*myRes == *stdRes);

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting item with hint - unhelpful")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myRes = mySet.insert(mySet.find(8), 20);
        auto stdRes = stdSet.insert(stdSet.find(8), 20);

        CHECK(*myRes == *stdRes);

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting item with hint - same as iterator")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myRes = mySet.insert(mySet.find(7), 7);
        auto stdRes = stdSet.insert(stdSet.find(7), 7);

        CHECK(*myRes == *stdRes);

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting item with hint - already in set")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myRes = mySet.insert(mySet.find(7), 17);
        auto stdRes = stdSet.insert(stdSet.find(7), 17);

        CHECK(*myRes == *stdRes);

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting item with hint - empty set")
    {
        my_set<int> mySet;
        std::set<int> stdSet;

        auto myRes = mySet.insert(mySet.cbegin(), 17);
        auto stdRes = stdSet.insert(stdSet.cbegin(), 17);

        CHECK(*myRes == *stdRes);

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting range")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet;
        std::set<int> stdSet;

        mySet.insert(values.begin(), values.end());
        stdSet.insert(values.begin(), values.end());

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Inserting range with duplicates")
    {
        std::vector<int> values({10, 5, 1, 2, 1, 10, 2, 1, 5, 5, 10});
        my_set<int> mySet;
        std::set<int> stdSet;

        mySet.insert(values.begin(), values.end());
        stdSet.insert(values.begin(), values.end());

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }
}

TEST_CASE("Erasure tests")
{
    std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
    my_set<int> mySet(values.begin(), values.end());
    std::set<int> stdSet(values.begin(), values.end());

    SECTION("Erasure by iterator - leaf")
    {
        CHECK(*mySet.erase(mySet.find(7)) == *stdSet.erase(stdSet.find(7)));
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by iterator - only right child")
    {
        CHECK(*mySet.erase(mySet.find(12)) == *stdSet.erase(stdSet.find(12)));
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by iterator - only left child")
    {
        CHECK(*mySet.erase(mySet.find(2)) == *stdSet.erase(stdSet.find(2)));
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by iterator - both childs, successor is child")
    {
        CHECK(*mySet.erase(mySet.find(15)) == *stdSet.erase(stdSet.find(15)));
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by iterator - both childs, successor is not child")
    {
        CHECK(*mySet.erase(mySet.find(5)) == *stdSet.erase(stdSet.find(5)));
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by iterator - root")
    {
        CHECK(*mySet.erase(mySet.find(10)) == *stdSet.erase(stdSet.find(10)));
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by value")
    {
        CHECK(mySet.erase(10) == stdSet.erase(10));
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by value - nonexists item")
    {
        CHECK(mySet.erase(20) == stdSet.erase(20));
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by vector")
    {
        CHECK(*mySet.erase(mySet.find(9), mySet.find(15)) == *stdSet.erase(stdSet.find(9), stdSet.find(15)));
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by vector - until set end")
    {
        stdSet.erase(stdSet.find(7), stdSet.cend());

        CHECK(mySet.erase(mySet.find(7), mySet.cend()) == mySet.cend());
        CHECK(mySet.empty() == stdSet.empty());
        CHECK(mySet.size() == stdSet.size());

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by vector - from set beginning")
    {
        CHECK(*mySet.erase(mySet.cbegin(), mySet.find(7)) == *stdSet.erase(stdSet.cbegin(), stdSet.find(7)));
        CHECK(mySet.empty() == stdSet.empty());
        CHECK(mySet.size() == stdSet.size());

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erasure by vector - full set")
    {
        stdSet.erase(stdSet.cbegin(), stdSet.cend());

        CHECK(mySet.erase(mySet.cbegin(), mySet.cend()) == mySet.cend());
        CHECK(mySet.empty() == stdSet.empty());
        CHECK(mySet.size() == stdSet.size());

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Clear")
    {
        mySet.clear();
        stdSet.clear();

        CHECK(mySet.empty() == stdSet.empty());
        CHECK(mySet.size() == stdSet.size());
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Erase from empty set - by value")
    {
        mySet.clear();
        stdSet.clear();

        CHECK(mySet.erase(12) == stdSet.erase(12));
        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }
}

TEST_CASE("Iterators test")
{
    SECTION("Iterators dereference works")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        for (auto i : values)
        {
            CHECK(*mySet.find(i) == i);
        }
    }

    SECTION("Iterators pointing works")
    {
        std::vector<std::string> values({"hello", "how", "are", "you"});
        my_set<std::string> mySet(values.begin(), values.end());
        for (auto i : values)
        {
            CHECK(mySet.find(i)->size() == i.size());
        }
    }

    SECTION("Forward iteration works")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto stdIt = stdSet.begin();
        for (auto myIt = mySet.cbegin(); myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Backward iteration works")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto stdIt = --stdSet.cend();
        auto myIt = --mySet.cend();
        for (; myIt != mySet.cbegin() && stdIt != stdSet.cbegin(); --myIt, --stdIt)
        {
            CHECK(*myIt == *stdIt);
        }

        CHECK(*myIt == *stdIt);
    }

    SECTION("Reverse iteration works")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto stdIt = stdSet.crbegin();
        for (auto myIt = mySet.crbegin(); myIt != mySet.crend() && stdIt != stdSet.crend(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Reverse backward iteration works")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto stdIt = --stdSet.crend();
        auto myIt = --mySet.crend();
        for (; myIt != mySet.crbegin() && stdIt != stdSet.crbegin(); --myIt, --stdIt)
        {
            CHECK(*myIt == *stdIt);
        }

        CHECK(*myIt == *stdIt);
    }

    SECTION("Bidirectional iteration works")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto stdIt = stdSet.begin();
        auto myIt = mySet.cbegin();
        for (; myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }

        --myIt;
        --stdIt;

        for (; myIt != mySet.cbegin() && stdIt != stdSet.cbegin(); --myIt, --stdIt)
        {
            CHECK(*myIt == *stdIt);
        }

        CHECK(*myIt == *stdIt);
    }

    SECTION("Equality operator")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());

        CHECK(mySet.find(5) == mySet.find(5));
        CHECK_FALSE(mySet.find(5) == mySet.find(15));
    }

    SECTION("Inequality operator - same set")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());

        CHECK(mySet.find(5) != mySet.find(15));
        CHECK_FALSE(mySet.find(5) != mySet.find(5));
    }

    SECTION("Inequality operator - different sets")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        my_set<int> myOtherSet(values.begin(), values.end());

        CHECK(mySet.find(5) != myOtherSet.find(15));
        CHECK(mySet.find(5) != myOtherSet.find(5));
    }

    SECTION("Copying iterators")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());

        auto myIt = mySet.find(5);
        auto myOtherIt(myIt);

        CHECK(myIt == myOtherIt);
    }

    SECTION("Assigning iterators")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());

        auto myIt = mySet.find(5);
        auto myOtherIt = myIt;

        CHECK(myIt == myOtherIt);
    }

    SECTION("Swapping iterators")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());

        auto myIt = mySet.find(5);
        auto myOtherIt = mySet.find(15);

        std::swap(myIt, myOtherIt);

        CHECK(myIt == mySet.find(15));
        CHECK(myOtherIt == mySet.find(5));
    }

    SECTION("Iterators is unaffected by insert")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myIt = mySet.find(5);
        auto stdIt = stdSet.find(5);

        mySet.insert(6);
        stdSet.insert(6);

        for (; myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }

    SECTION("Iterators is unaffected by erasure of other item")
    {
        std::vector<int> values({10, 5, 15, 2, 8, 12, 17, 1, 7, 9, 13});
        my_set<int> mySet(values.begin(), values.end());
        std::set<int> stdSet(values.begin(), values.end());

        auto myIt = mySet.find(5);
        auto stdIt = stdSet.find(5);

        mySet.insert(7);
        stdSet.insert(7);

        for (; myIt != mySet.cend() && stdIt != stdSet.end(); ++myIt, ++stdIt)
        {
            CHECK(*myIt == *stdIt);
        }
    }
}
