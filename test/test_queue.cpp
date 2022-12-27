#include "queue.h"
#include <gtest.h>


TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> q);
}

TEST(TQueue, new_queue_is_empty)
{
	TQueue<int> q;
	EXPECT_EQ(q.empty(), true);
}

TEST(TQueue, can_get_size_of_an_empty_queue)
{
	TQueue<int> q;
	EXPECT_EQ(q.get_size(), 0);
}



TEST(TQueue, can_get_size_of_filled_queue)
{
	TQueue<int> q;
	q.push_back(5);
	q.push_back(7);
	EXPECT_EQ(q.get_size(), 2);
}

TEST(TQueue, added_elem_in_queue_changes_size)
{
	TQueue<int> q;
	EXPECT_EQ(q.get_size(), 0);
	q.push_back(5);
	EXPECT_EQ(q.get_size(), 1);
	q.push_back(7);
	EXPECT_EQ(q.get_size(), 2);
}

TEST(TQueue, cant_get_elem_from_empty_queue)
{
	TQueue<int> q;
	ASSERT_ANY_THROW(q.get_front());
}

TEST(TQueue, can_get_elem_from_filled_queue)
{
	TQueue<int> q;
	q.push_back(5);
	EXPECT_EQ(q.get_front(), 5);
}

TEST(TQueue, get_elem_from_queue_cant_change_size)
{
	TQueue<int> q;
	q.push_back(7);
	q.push_back(9);
	EXPECT_EQ(q.get_size(), 2);
	q.get_front();
	EXPECT_EQ(q.get_size(), 2);
}

TEST(TQueue, cant_remove_elem_from_empty_queue)
{
	TQueue<int> q;
	ASSERT_ANY_THROW(q.pop_front());
}

TEST(TQueue, can_remove_elem_from_filled_queue)
{
	TQueue<int> q;
	q.push_back(7);
	EXPECT_EQ(q.pop_front(), 7);
}

TEST(TQueue, remove_elem_from_queue_changes_size)
{
	TQueue<int> q;
	q.push_back(7);
	q.push_back(9);
	EXPECT_EQ(q.get_size(), 2);
	q.pop_front();
	EXPECT_EQ(q.get_size(), 1);
	q.pop_front();
	EXPECT_EQ(q.get_size(), 0);
}

TEST(TQueue, first_in_first_out_in_queue)
{
	TQueue<int> q;
	q.push_back(7);
	q.push_back(9);
	q.push_back(13);
	EXPECT_EQ(q.pop_front(), 7);
	EXPECT_EQ(q.pop_front(), 9);
	EXPECT_EQ(q.pop_front(), 13);
}
