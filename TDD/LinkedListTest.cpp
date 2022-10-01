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
        //LinkedList_destroy(_list);
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


TEST_F(LinkedListTest, TestRemoveTheSecondItemPushedAndAfterFirst)
{
    char* sendItem = "Test";
    char* sendItem2 = "Test2";
    LinkedList_push(_list,sendItem);
    LinkedList_push(_list,sendItem2);
    char* returnItem = (char*)LinkedList_pull(_list);
    EXPECT_STREQ("Test2",returnItem);
    returnItem = (char*)LinkedList_pull(_list);
    EXPECT_STREQ("Test",returnItem);
}

TEST_F(LinkedListTest, TestGetItemOnSpecificIndex)
{
    for(int i=1;i<=100;i++)
    {
        char* toSend=(char*)calloc(sizeof(8),1);
        std::sprintf(toSend,"Test%d",i);
        LinkedList_push(_list,toSend);
    }
    
    char* returnItem = (char*)LinkedList_peekItemByIndex(_list,98);
    EXPECT_STREQ("Test2",returnItem);
    returnItem = (char*)LinkedList_peekItemByIndex(_list,2);
    EXPECT_STREQ("Test98",returnItem);
}

TEST_F(LinkedListTest, TestAnItemOnDifferentLocation)
{
    for(int i=1;i<=100;i++)
    {
        char* toSend=(char*)calloc(sizeof(8),1);
        std::sprintf(toSend,"Test%d",i);
        LinkedList_push(_list,toSend);
    }

    LinkedList_removeItem(_list,"Test2");
    char* returnItem = (char*)LinkedList_peekItemByIndex(_list,98);
    EXPECT_STREQ("Test2",returnItem);
    
}