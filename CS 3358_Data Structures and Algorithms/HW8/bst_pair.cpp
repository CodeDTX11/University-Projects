/* Psuedo
**main:
getline(input, string)
cin value to search

vector tree_vec
bool flag = false
copy string to string stream

while (stringstream >> value)
  vectortree.Insert(value)

for (vec[i])
  for (vec[i +1])
    if value_to_search == vec[i] + vec[i+1]
    flag = true
    break;

if (flag)
  cout true
else
  cout false


*/


#include "bst.h"
#include <iostream>
#include <vector>
#include <sstream>


int main( ) {
  //10 5 15 2 7 11 25 1

  std::string array_string;

  int value, value_to_search;
  bool flag = false;
  
  std::vector<int> tree_vector;

  BST<int> pair_tree;

//=================================================================//

  getline(std::cin, array_string);

  std::cin >> value_to_search;

  std::stringstream int_converter(array_string);

  /*
  while (int_converter >> value) {
    pair_tree.Insert(value);
  }
  */

  while (int_converter >> value) {
    tree_vector.push_back(value);
  }

  for (int i=0; i < tree_vector.size(); i++){
    for (int j=i+1; j < tree_vector.size(); j++){
      value = tree_vector[i] + tree_vector[j];
      if (value_to_search == value) {
        flag = true;
        break;
      }
    }
  }

  if (flag)
    std::cout << "True";
  else 
    std::cout << "False";

  return 0;
}