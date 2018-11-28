//
// Created by jose on 11/25/18.
//

#ifndef PATRICIA_TRIE_TRIE_H
#define PATRICIA_TRIE_TRIE_H

#include <iostream>
#include <map>
#include <vector>
#include "Node.h"

class Trie {
 private:
  std::map<char, std::vector<Node *>> roots;
  int globalIndex = 0;
  bool globalSwitch;
 public:

  Trie() = default;
  std::pair<Node *, std::string> fetch(std::string nodeContent) {
    std::pair<Node *, std::string> result;
    std::string testLeft;
    std::string testRight;
    for (auto &root : roots[nodeContent[0]]) {
      auto ptr = root;

      testLeft += ptr->get_content();
      testRight += ptr->get_content();
      while (ptr != nullptr) {
        if (inside(testLeft, nodeContent)) {
          if (ptr->get_left() == nullptr) {
            if (inside(testLeft += ptr->get_left()->get_content(), nodeContent)) {
              ptr = ptr->get_left();
              testRight = testLeft;
            } else if (ptr->get_right() != nullptr) {
              if (inside(testRight += ptr->get_right()->get_content(), nodeContent)) {
                ptr = ptr->get_right();
                testLeft = testRight;
              } else {
                result.first = ptr;
                result.second = testRight;
                return result;
              }
            } else {
              if (this->globalIndex == 0) {
                break;
              } else {
                result.first = ptr;
                if (testLeft.size() < testRight.size()) {
                  result.second = testRight;
                } else if (testLeft.size() > testRight.size()) {
                  result.second = testLeft;
                } else {
                  result.second = testLeft;
                }
                return result;
              }
            }
          } else {
            result.first = ptr;
            result.second = testLeft;
            return result;
          }
        } /*else if (inside(testRight, nodeContent)) {
          ptr = ptr->get_right();
        } else {
          if (this->globalIndex == 0) {
            break;
          } else {
            result.first=ptr;
            if(testLeft.size()<testRight.size()){
              result.second=testRight;
            }
            else if(testLeft.size()>testRight.size()){
              result.second=testLeft;
            }
            else{
              result.second=testLeft;
            }
            return result;
          }
        }*/


      }
      return nullptr;
    }
  }
  void insert(std::string nodeContent) {
    if (roots[nodeContent[0]].empty()) {
      Node *newnode = new Node(nodeContent);
      roots[nodeContent[0]].push_back(newnode);
    } else {
      Node *newnode = fetch(nodeContent).first;

      if (newnode != nullptr) {
        std::string extra1;
        std::string extra2;
        std::string extra3;
        for (int character = 0; newnode->get_content().size(); character++) {
          if (character < this->globalIndex) {
            extra1.push_back(newnode->get_content()[character]);
          } else {
            extra2.push_back(newnode->get_content()[character]);
          }
        }

        Node *derivateNode = new Node(extra2);
        derivateNode->setLeft(newnode->get_left());
        derivateNode->setRight(newnode->get_right());
        newnode->setContent(extra1);
        newnode->setLeft(derivateNode);

        for (int character = globalIndex; character < nodeContent.size(); character++) {
          extra3.push_back(nodeContent[character]);
        }
        auto *createdNode = new Node(extra3);
        newnode->setRight(createdNode);
      } else {
        auto *newroot = new Node(nodeContent);
        roots[nodeContent[0]].push_back(newroot);
      }
    }
  }

  void errase(std::string nodeContent) {}
  void show_words(std::string testString) {}

  bool inside(std::string subject, std::string wordToCompare) {
    if (subject.size() < wordToCompare.size()) {
      for (int index = 0; index < subject.size(); index++) {
        if (subject[index] != wordToCompare[index]) {
          this->globalIndex = index;
          return false;
        }
      }
      return true;
    } else {
      return false;
    }
  }

};

#endif //PATRICIA_TRIE_TRIE_H
