#include "gtest/gtest.h"

extern "C"{
    //add external libs
    #include <LinkedList.h>
}

class LinkedListTest : public ::testing::Test
{

protected:
    LinkedList _list;
    void SetUp() override
    {
       _list = LinkedList_create();
    };
    void TearDown() override
    {
        LinkedList_destroy(_list);
    };
};

TEST_F(LinkedListTest, TestLinkedListSize0)
{
    EXPECT_EQ(0,LinkedList_length(_list));
}

TEST_F(LinkedListTest, TestLengthAfterAddingOneItem)
{
    int x = 1;
    int* p = &x;
    LinkedList_push(_list,p);
    EXPECT_EQ(1,LinkedList_length(_list));
}

TEST_F(LinkedListTest, TestRemoveOneItem)
{
    char* sendItem = "Test";
    LinkedList_push(_list,sendItem);
    char* returnItem = (char*)LinkedList_pull(_list);
    EXPECT_STREQ("Test",returnItem);
}
    
