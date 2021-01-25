cmake_minimum_required(VERSION 3.17)
project(cpp_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(heads)

add_executable(cpp_code

        code_learning/leetcode/leetcode_179m_stl-sort-essentially_largestNumber.cpp

        heads/listNode.h
        heads/treeNode.h
        heads/queue.h
        heads/structs.h
        )
