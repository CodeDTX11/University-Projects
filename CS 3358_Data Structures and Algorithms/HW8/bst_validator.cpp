/*
Pseudo Code:

**main:
getline(input, string)

copy string to string stream

while (stringstream >> value)
  vector.push_back(value)

call inorder(vec, first, last, inorder vector);

bool not_bst = false;

for (int i = 0)
  if in_order_vec[i] < in_order_vec[i-1]
    not_bst = true

if (not_bst)
  cout << False
else
  cout << True

**inorder:
receives user input vector, start index, end index, in_order vector
if first index > last index
  return

inorder(input_vector, first*2 + 1, last, in_order_vec)

in_order_vec.push_back(input_vector[first])

inorder(input_vector, first*2 + 2, last, in_order_vec)
*/

#include "bst.h"
#include <iostream>
#include <vector>
#include <sstream>


void inOrder(std::vector<int> input_vector, int first, int last, std::vector<int> &in_order_vec);



int main() {
//10 5 15 2 7 11 25 1

  std::string array_string;
  std::vector<int> tree_vec;
  int value;

//=================================================================//

  getline(std::cin, array_string);

  std::stringstream int_converter(array_string);

  while (int_converter >> value) {
    tree_vec.push_back(value);
  }

  int size = tree_vec.size();

  std::vector<int> in_order_vec;

  inOrder(tree_vec, 0, size-1, in_order_vec);

  bool not_bst = false;

  for (int i = 1;i < size; i++) {
    if ( in_order_vec[i] < in_order_vec[i-1]) {
      not_bst = true;
      break;
    }
  }

  if(not_bst)
    std::cout << "False";
  else
    std::cout << "True";

  return 0;
} //end main


void inOrder(std::vector<int> input_vector, int first, int last, std::vector<int> &in_order_vec) {
  if(first > last) 
    return; 

  inOrder(input_vector, first*2 + 1, last, in_order_vec); 
      
  in_order_vec.push_back(input_vector[first]);

  inOrder(input_vector, first*2 + 2, last, in_order_vec);  
} 
