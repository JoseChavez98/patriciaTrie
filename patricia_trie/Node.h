//
// Created by jose on 11/25/18.
//

#ifndef PATRICIA_TRIE_NODE_H
#define PATRICIA_TRIE_NODE_H

#include <iostream>

class Node{
 private:
  std::string content;
  Node *right= nullptr;
  Node *left= nullptr;
  bool extra_child_end=false;

 public:

  explicit Node(std::string content){this->content=content;}
  ~Node(){
    delete content;
    delete right;
    delete left;
    delete extra_child_end;
  }

  void setRight(Node *node){
    this->right=node;
  }
  void setLeft(Node *node){
    this->left=node;
  }
  std::string get_content(){
    return this->content;
  }
  Node *get_right(){
    return this->right;
  }
  Node *get_left(){
    return this->left;
  }

  void describe_path(){

  }
};

#endif //PATRICIA_TRIE_NODE_H
