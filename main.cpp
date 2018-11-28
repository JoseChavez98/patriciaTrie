#include <iostream>
#include "Trie.h"

int main() {
  Trie a = Trie();
  a.insert("rico");
  a.insert("risa");
  a.insert("ricota");
  a.insert("ricola");


//  a.insert("romantes");
  a.level_print();
  return 0;
}