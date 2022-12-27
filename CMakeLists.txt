cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME Queue)
project(${PROJECT_NAME})


set(LIBRARY "${PROJECT_NAME}")
set(TESTS  "test_${PROJECT_NAME}")


set(qulib QueueLib)
set(clib ClusterLib)
set(clst Cluster) 


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ClusterLib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)


add_subdirectory(QueueLib)
add_subdirectory(ClusterLib)
add_subdirectory(Cluster)
add_subdirectory(gtest)
add_subdirectory(test)


