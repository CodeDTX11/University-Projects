#include <iostream>
#include <string>
#include <stdio.h>
#include "dlist.h"

double IsValidNumber(std::string input) {
  int count_dot = 0;
  for (int i = 0; i<input.length();i++) {
    if (input.at(i) <= '9' && input.at(i) >= '0' ) {
      continue;
    } else if (i > 0 && input.at(i) == '.' && (input.at(i+1) <= '9'
               && input.at(i+1) >= '0' ) && count_dot == 0)
    {
      count_dot++;
    } else {
      return -1;
    }
  }
  return stod(input);
}

template <class T>
int StackLength(Dlist<T> list) {
  int count = 0;
  try {
    while (list.RemoveFront()) {
      count++;
    }
  }
  catch (emptyList) {
    return count;
  }
  return count;
}

void GetInput (Dlist<std::string> &input_string) {
  std::string input;
  getline(std::cin,input);
  while (input != "\0") {
    input_string.InsertBack(input);
    getline(std::cin,input);
  }
}

void Calculate (Dlist<std::string> input_string) {
  try {
    std::string input = input_string.RemoveFront();
    Dlist<double> my_stack;
    double a;
    double b;
    while (input != "\0") {
      a = -1;
      b = -1;
      if (input == "+"||input == "-"||input == "*"||input == "/"||input == "n"||
          input == "d"||input == "r"||input == "p"||input == "c"||input == "a")
      {
        char opt = input.at(0);
        switch (opt) {
          case '+': {
            try {
            a = my_stack.RemoveFront();
            b = my_stack.RemoveFront();
            my_stack.InsertFront(a+b);
            }
            catch (emptyList) {
              if (a != -1) {
                my_stack.InsertFront(a);
              }
              std::cout << "Not enough operands\n";
            }
            break;
          }
          case '-': {
            try {
              a = my_stack.RemoveFront();
              b = my_stack.RemoveFront();
              my_stack.InsertFront(b-a);
            }
            catch (emptyList) {
              if (a != -1) {
                my_stack.InsertFront(a);
              }
              std::cout << "Not enough operands\n";
            }
            break;
          }
          case '*': {
            try {
              a = my_stack.RemoveFront();
              b = my_stack.RemoveFront();
              my_stack.InsertFront(a*b);
              break;
            }
            catch (emptyList) {
              if (a != -1) {
                my_stack.InsertFront(a);
              }
              std::cout << "Not enough operands\n";
            }
            break;
          }
          case '/': {
            try {
              a = my_stack.RemoveFront();
              b = my_stack.RemoveFront();
              if (a == 0) {
                std::cout<< "Divide by zero\n";
                my_stack.InsertFront(b);
                my_stack.InsertFront(a);

              } else {
                my_stack.InsertFront(b/a);
              }
            }
            catch (emptyList) {
              if (a != -1) {
                my_stack.InsertFront(a);
              }
              std::cout << "Not enough operands\n";
            }
            break;
          }
          case 'n': {
            try {
              a = my_stack.RemoveFront();
              my_stack.InsertFront((-1)*a);
            }
            catch (emptyList) {
              std::cout << "Not enough operands\n";
            }
            break;
          }
          case 'd': {
            try {
              a = my_stack.RemoveFront();
              my_stack.InsertFront(a);
              my_stack.InsertFront(a);
            }
            catch (emptyList) {
              std::cout << "Not enough operands\n";
            }
            break;
          }
          case 'r': {
            try {
              a = my_stack.RemoveFront();
              b = my_stack.RemoveFront();
              my_stack.InsertFront(a);
              my_stack.InsertFront(b);
            }
            catch (emptyList) {
              if (a != -1) {
                my_stack.InsertFront(a);
              }
              std::cout << "Not enough operands\n";
            }
            break;
          }
          case 'p': {
            try {
              a = my_stack.RemoveFront();
              my_stack.InsertFront(a);
              std::cout << a << std::endl;
            }
            catch (emptyList) {
              std::cout << "Not enough operands\n";
            }
            break;
          }
          case 'c': {
            my_stack.~Dlist();
            break;
          }
          case 'a': {
            for (int i = 1; i <= StackLength(my_stack); i++) {
              a = my_stack.RemoveFront();
              my_stack.InsertBack(a);
              if (i == StackLength(my_stack)) {
                std::cout << a <<std::endl ;
              } else {
                std::cout << a <<" ";
              }
            }
            break;
          }
        }
      } else if (input == "q") {
        return ;
      } else if (IsValidNumber(input) != -1){
        my_stack.InsertFront(IsValidNumber(input));
      } else if (IsValidNumber(input) == -1){
      std::cout<< "Bad input\n";
      }
      input = input_string.RemoveFront();
    }
  }
  catch (emptyList) {
    return;
  }
}

int main() {

    Dlist<std::string> input_string;
    GetInput(input_string);
    Calculate(input_string);

  return 0;
}

