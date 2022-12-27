#include "cluster.h"
#include "cluster.cpp"
#include <gtest.h>

TEST(Cluster, can_create_cluster_with_correct_values)
{
	ASSERT_NO_THROW(Cluster cl(1, 1, 5, 0.5));
}

TEST(Cluster, throws_when_create_cluster_with_too_small_k)
{
	ASSERT_ANY_THROW(Cluster cl(min_k - 1, 1, 5, 0.5));
}

TEST(Cluster, throws_when_create_cluster_with_too_large_k)
{
	ASSERT_ANY_THROW(Cluster cl(max_k + 1, 1, 5, 0.5));
}

TEST(Cluster, throws_when_create_cluster_with_too_small_tacts)
{
	ASSERT_ANY_THROW(Cluster cl(1, min_tacts - 1, 5, 0.5));
}

TEST(Cluster, throws_when_create_cluster_with_too_large_tacts)
{
	ASSERT_ANY_THROW(Cluster cl(1, max_tacts + 1, 5, 0.5));
}

TEST(Cluster, throws_when_create_cluster_with_too_small_queueSize)
{
	ASSERT_ANY_THROW(Cluster cl(1, 1, min_queueSize - 1, 0.5));
}

TEST(Cluster, throws_when_create_cluster_with_too_large_queueSize)
{
	ASSERT_ANY_THROW(Cluster cl(1, 1, max_queueSize + 1, 0.5));
}

TEST(Cluster, throws_when_create_cluster_with_negative_frequency)
{
	ASSERT_ANY_THROW(Cluster cl(1, 1, 5, -0.1));
}

TEST(Cluster, throws_when_create_cluster_with_zero_frequency)
{
	ASSERT_ANY_THROW(Cluster cl(1, 1, 5, 0));
}

TEST(Cluster, throws_when_create_cluster_with_too_large_frequency)
{
	ASSERT_ANY_THROW(Cluster cl(1, 1, 5, 1.2));
}
