#include "tqueue.h"
#include <gtest.h>
#include <vector>

TEST(TQueue, can_create_queue) {
	ASSERT_NO_THROW(TQueue<int> q);
}

TEST(TQueue, can_push_element_and_pop_it_in_order) {
	TQueue<int> q;
	bool flag = true;

	for (int i = 0; i < 10; i++)
		q.push(i);

	for (int i = 0; i < 10; i++)
		if (q.pop() != i) flag = false;

	EXPECT_TRUE(flag);
}

TEST(TQueue, can_push_element_and_pop_it_out_of_order) {
	TQueue<int> q;
	bool flag = true;
	std::vector<int> v = {1,1,1,1,1,2,2,2,2,2,2,2,2,2,2};

	for (int i = 0; i < 10; i++)
		q.push(1);

	for (int i = 0; i < 5; i++)
		q.pop();

	for (int i = 0; i < 10; i++)
		q.push(2);

	for (int i = 0; i < 15; i++)
		if (v[i] != q.pop()) flag = false;
		

	EXPECT_TRUE(flag);
}

TEST(TQueue, empty_correct_if_queue_is_empty) {
	TQueue<int> q;

	EXPECT_TRUE(q.empty());
}

TEST(TQueue, empty_correct_if_queue_is_not_empty) {
	TQueue<int> q;

	q.push(1);

	EXPECT_FALSE(q.empty());
}

TEST(TQueue, empty_correct_after_removing_elements) {
	TQueue<int> q;

	q.push(1); q.push(1); q.push(1);
	q.pop(); q.pop(); q.pop();

	EXPECT_TRUE(q.empty());
}


TEST(TQueue, count_is_correct) {
	TQueue<int> q;

	q.push(1); q.push(2);

	EXPECT_EQ(2, q.count());
}

TEST(TQueue, throw_after_pop_if_queue_is_empty) {
	TQueue<int> q;

	ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, can_copy_queue) {
	bool equality = true;
	TQueue<int> q1;
	for (int i = 0; i < 20; i++)
		q1.push(i);

	TQueue<int> q2(q1);

	if (q1.count() != q2.count()) equality = false;
	while (!q1.empty())
		if (q1.pop() != q2.pop()) equality = false;

	EXPECT_TRUE(equality);
}

TEST(TQueue, can_assign_queue) {
	bool equality = true;
	TQueue<int> q1, q2;
	for (int i = 0; i < 20; i++)
		q1.push(i);

	q2 = q1;

	if (q1.count() != q2.count()) equality = false;
	while (!q1.empty())
		if (q1.pop() != q2.pop()) equality = false;

	EXPECT_TRUE(equality);
}

