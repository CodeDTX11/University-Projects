/* Psuedo code
**Insert:
  Receives root pointer to pointer, value
  if node is empty
  initializes new node
  sets value to new node
  tree size ++ // used for average
  total += value // used for average
  else 
  if value > node->value
  recursive call insert with node->right pointer
  else call recursive insert node->left pointer

**Average():
  return (type cast double) total/treesize;

**MinValue(node*)
  if(node->left == null)
    return node->value
  else
    return recusrive minvalue(node->left)

**MaxValue(node*):
  if(node->right == null)
    return node->value
  else
    return recusrive maxvalue(node->right)


**DepthFinder(val, vector<int> &path_vec) 
  depth = 0
	return DepthFinder(this->root, val, depth, path_vec)

**DepthFinder( node* node, val, depth, vector<int> &path_vec) 
  path_vec.push_back(node->value)
  if (val == node->value)
    return depth
  if (node->left == nullptr and node->right == nullptr)
    return -1
  if (val > node->value) 
    depth++
    return DepthFinder(node->right, val, depth, path_vec) 
  else 
    depth++
    return recursive DepthFinder(node->left, val, depth, path_vec)
  
**LowestComAncestor(val1,val2)
  vector<T> path_vec1
  vector<T> path_vec2
  lca = 0

  PathFinder(this->root, val1, path_vec1)

  PathFinder(this->root, val2, path_vec2)

  for (int i = 0; i < path_vec1.size and i < path_vec2.size; i++) {
    if (path_vec1[i] != path_vec2[i]) {
      lca = i-1;
      break;
    }
  lca = i;
  }
  return path_vec1[lca]
}

**PathFinder(node* node, val, vector<int> &path_vec) 
  path_vec.push_back(node->value);
  if (val == node->value)
    return
  if (node->left == nullptr and node->right == nullptr)
    return
  if (val > node->value) 
    return recursive PathFinder(node->right, val, path_vec)
  else 
    return recursive PathFinder(node->left, val, path_vec)
   
*/

#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <vector>
#include <queue>
template <class T>

class BST
{
	struct node{
		T value;
		struct node* right;
		struct node* left;
	};

public:
	BST();
	void Insert(T val);

  double Average();

	int Size();
  int Min();
  int Max();

	T DepthFinder(T val, std::vector<int> &path_vec);

  int LowestComAncestor(T val, T val2);

private:
	struct node* root;
	int treeSize;
  int total;

	T DepthFinder(struct node* node, T val, int depth, std::vector<int> &path_vec);

  void PathFinder(struct node* node, T val, std::vector<T> &path_vec);

  void Insert(struct node** node, T val);

  int MinValue(struct node* node);
  int MaxValue(struct node* node);
};

template <class T>
BST<T>::BST(){
	this->root = NULL;
	this->treeSize = 0;
  this->total = 0;
}

template <class T>
int BST<T>::Size(){
	return this->treeSize;
}

template <class T>
void BST<T>::Insert(T val){
	Insert(&(this->root), val);
}

template <class T>
void BST<T>::Insert(struct node** node, T val){

	if (*node == NULL) {
		struct node* new_node = new struct node;
		new_node->value = val;
		new_node->left = new_node->right = NULL;
		*node = new_node;
		this->treeSize++;
    this->total += val;
	} else {
		if (val > (*node)->value){
			Insert(&(*node)->right, val);
		} else {
			Insert(&(*node)->left, val);
		}
	}
}

template <class T>
double BST<T>::Average() {
  return (double)total/treeSize;
}

template <class T>
int BST<T>::Min(){
	return MinValue(this->root);
}

template <class T>
int BST<T>::MinValue(struct node* node) {
  if(node->left==nullptr){
    return node->value;
  }
  return MinValue(node->left);
}

template <class T>
int BST<T>::Max(){
	return MaxValue(this->root);
}

template <class T>
int BST<T>::MaxValue(struct node* node)
{
  if(node->right==nullptr){
    return node->value;
  }
  return MaxValue(node->right);
}

template <class T>
T BST<T>::DepthFinder(T val, std::vector<int> &path_vec) {

  int depth = 0;

	return DepthFinder(this->root, val, depth, path_vec);
}

template <class T>
T BST<T>::DepthFinder(struct node* node, T val, int depth, std::vector<int> &path_vec) {

  path_vec.push_back(node->value);

  if (val == node->value)
    return depth;

  if (node->left == nullptr && node->right == nullptr)
    return -1;
  
  if (val > node->value) {
    depth++;
    return DepthFinder(node->right, val, depth, path_vec);
    
  } else { 
    depth++;
    return DepthFinder(node->left, val, depth, path_vec);
  }  
}

template <class T>
int BST<T>::LowestComAncestor(T val1, T val2) {

  std::vector<T> path_vec1;
  std::vector<T> path_vec2;
  int lca = 0;

  PathFinder(this->root, val1, path_vec1);

  PathFinder(this->root, val2, path_vec2);

  for (int i = 0; i < path_vec1.size() && i < path_vec2.size(); i++) {
    if (path_vec1[i] != path_vec2[i]) {
      lca = i-1;
      break;
    }
  lca = i;
  }
  return path_vec1[lca];
}

template <class T>
void BST<T>::PathFinder(struct node* node, T val, std::vector<T> &path_vec) {

  path_vec.push_back(node->value);

  if (val == node->value)
    return;

  if (node->left == nullptr && node->right == nullptr)
    return;
  
  if (val > node->value) {
    return PathFinder(node->right, val, path_vec);
    
  } else { 
    return PathFinder(node->left, val, path_vec);
  } 
}

 // end

#endif