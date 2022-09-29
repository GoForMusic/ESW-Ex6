#include "gtest/gtest.h"


extern "C"{
    //add external libs
#include "../LinkedList/LinkedList.h"

}

LinkedList _list;

class LinkedListTest : public ::testing::Test
{
protected:
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
    uint16_t value = LinkedList_length(_list);
    ASSERT_EQ(value,0);
}
