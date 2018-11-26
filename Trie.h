//
// Created by jose on 11/25/18.
//

#ifndef PATRICIA_TRIE_TRIE_H
#define PATRICIA_TRIE_TRIE_H

#include <iostream>
#include <map>
#include <vector>
#include "Node.h"

class Trie{
 private:
  std::map<char,std::vector<Node>> roots;

 public:
  Trie()=default;
  Node fetch(std::string nodeContent){
    for(auto &root : roots[nodeContent[0]]){
      while()
    }
  }
  void insert(std::string nodeContent){

  }
  void errase(std::string nodeContent){}
  void show_words(std::string testString){}

};

#endif //PATRICIA_TRIE_TRIE_H
