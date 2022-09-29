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

TEST_F(LinkedListTest, Test_LinkedList_size_0)
{
    uint16_t x = LinkedList_length(_list);
    ASSERT_EQ(x,0);
}

TEST_F(LinkedListTest, Test_Clear_LinkedList)
{
    LinkedList_push(_list,"Test");
    uint16_t x = LinkedList_length(_list);
    ASSERT_EQ(x,1);
}
    
    
