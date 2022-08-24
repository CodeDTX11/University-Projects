/* Psuedo
**main:
getline(input, string)
vector tree_vec

BST<int> bacon_tree

copy string to string stream

while (stringstream >> value)
  bacon_tree.Insert(value)

call bacon_tree.depthfinder(valueto serach, &tree vec) //psuedo for function in BST.h

cout the results
*/

#include "bst.h"
#include <iostream>
#include <vector>
#include <sstream>



int main( ) {

  std::string array_string;

  std::vector<int> tree_vec;

  int value, value_to_search;

  BST<int> bacon_tree;

  getline(std::cin, array_string);

  std::cin >> value_to_search;

  std::stringstream int_converter(array_string);

   while (int_converter >> value) {
    bacon_tree.Insert(value);
  }
  
  std::cout << "depth = " << bacon_tree.DepthFinder(value_to_search, tree_vec) << std::endl;

  std::cout << "path =";
  for(int i: tree_vec)
    std::cout << " " << i;
  
  return 0;
}
