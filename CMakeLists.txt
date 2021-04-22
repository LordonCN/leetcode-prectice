cmake_minimum_required(VERSION 3.17)
project(cpp_code)

set(CMAKE_CXX_STANDARD 14)


include_directories(heads)

add_executable(cpp_code

#        code_learning/leetcode/leetcode_75m_sort_sortColors.cpp
        code_learning/hduACM/ali_2021_1.cpp

        heads/listNode.h
        heads/treeNode.h
        heads/queue.h
        heads/structs.h
        heads/sort.h
        code_learning/cudaLearning/Device.cu)
