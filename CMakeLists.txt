cmake_minimum_required(VERSION 3.9)
project(patriciaTrie)

set(CMAKE_CXX_STANDARD 11)

add_executable(patriciaTrie
        patricia_trie/main.cpp
        patricia_trie/Node.h
        patricia_trie/Trie.h)
