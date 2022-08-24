/* Psuedo
**main:
getline(input, string)
cin value_to_search1
cin value_to_search2
BST<int> lca_tree

copy string to string stream

while (stringstream >> value)
  lca_tree.Insert(value)

make call to LowestComAncestor(psuedo for LowestComAncestor in BST.h)

cout the results
*/

#include "bst.h"
#include <iostream>
#include <vector>
#include <sstream>



int main( ) {
  //test 10 5 15 2 7 11 25 1 (7,2)
  std::string array_string;

  int value, value_to_search1, value_to_search2;

  BST<int> lca_tree;

  getline(std::cin, array_string);

  std::cin >> value_to_search1;
  std::cin >> value_to_search2;

  std::stringstream int_converter(array_string);

   while (int_converter >> value) {
    lca_tree.Insert(value);
  }

  std::cout<< "lca = " << lca_tree.LowestComAncestor(value_to_search1, value_to_search2);

  return 0;
} // end main

