/* Psuedo
**main:
getline(input, string)

BST<int> calc_tree

copy string to string stream

while (stringstream >> value)
  calc_tree.Insert(value)

call calc_tree.min() //psuedo for function in BST.h
call calc_tree.Max() //psuedo for function in bst.h
call calc_tree.average() //psuedo for function in bst.h

cout the results
*/

#include "bst.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>


int main( ) {

  std::string array_string;

  int value;

  BST<int> calc_tree;

  getline(std::cin, array_string);

  std::stringstream int_converter(array_string);
  
   while (int_converter >> value) {
    calc_tree.Insert(value);
  }
  
  std::cout << "min = " << calc_tree.Min();
  std::cout << std::endl;
  std::cout << "max = " << calc_tree.Max();
  std::cout << std::endl;

  std::cout << "avg = " << std::fixed << std::setprecision(2) << calc_tree.Average();

  return 0;
}
