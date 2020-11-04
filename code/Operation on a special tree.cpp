//
//  Operation on a special tree.cpp
//  
//
#include <iostream>
using namespace std;
typedef struct tnode* treeptr;
typedef struct tnode {
    int element;
    treeptr leftMostChild;
    treeptr rightSibling;
} TreeNode;

class Tree {
  private:
    treeptr root;
    void printTreeHelper(treeptr ptr,int val);
    treeptr makeTreeHelper(treeptr ptr,int val);
    int max(int x, int y);
  public:
     void createNode (int E, Tree L, Tree R);
     void makeTree(int *array, int n);
     treeptr getRoot();
     void printTree();
     
     //Implement the following
     int height(treeptr ptr);
     int numLeaves(treeptr ptr);


     Tree(){root = NULL;}
  ~Tree () { delete root;}
};


void Tree::createNode(int E, Tree leftMostChild, Tree rightSibling) {
   root = new TreeNode;
   root->leftMostChild = leftMostChild.getRoot();
   root->rightSibling = rightSibling.getRoot();
   root->element = E;
}

/*-------------------------------------------------------------------------
 *  getRoot -- Returns the root of a given node
 *    Args:
 *    Returns:  treeptr
 *    Throws:
 *    See:
 *    Bugs:
 -------------------------------------------------------------------------*/
treeptr Tree::getRoot()
{
  return(root);
} /*  End of getRoot    End of getRoot   */


/*-------------------------------------------------------------------------
 *  max -- max of two integer variables
 *    Args:int, int
 *    Returns:  returns the maximum of two numbers
 *    Throws:
 *    See:
 *    Bugs:
 -------------------------------------------------------------------------*/
int Tree::max(int x, int y) {
  if (x > y)
    return(x);
  else
    return(y);
}


/*-------------------------------------------------------------------------
 *   -- makeTreeHelper a private function
 *    Args:
 *    Returns: tree
 *    Throws:
 *    See:
 *    Bugs:
 -------------------------------------------------------------------------*/

treeptr Tree::makeTreeHelper(treeptr ptr,int i) {
  if (ptr == NULL) {
    ptr = new TreeNode;
    ptr->element = i;
    ptr->leftMostChild = NULL;
    ptr->rightSibling = NULL;
  }
   else if (i < ptr->element)
     ptr->leftMostChild = (treeptr) makeTreeHelper(ptr->leftMostChild,i);
   else if (i > ptr->element)
     ptr->rightSibling = (treeptr) makeTreeHelper(ptr->rightSibling,i);
 return(ptr);
}

/*-------------------------------------------------------------------------
 *   -- printTreeHelper a private function recursively prints elements in the tree
 *    Args:
 *    Returns: tree
 *    Throws:
 *    See:
 *    Bugs:
 -------------------------------------------------------------------------*/


void Tree::printTreeHelper(treeptr ptr,int val) {
  if (ptr != NULL) {
    printTreeHelper(ptr->leftMostChild,0);
    cout << " " << ptr->element << " value " << val << endl ;
    printTreeHelper(ptr->rightSibling,1);
  }
}


/*-------------------------------------------------------------------------
 *  printTree -- public interface function to printTree
 *    Args:
 *    Returns:  Nothing
 *    Throws:
 *    See:
 *    Bugs:
 -------------------------------------------------------------------------*/
void Tree::printTree() {
  if (root != NULL)
    printTreeHelper(root,0);
  else
    cout << "root is NULL\n";
}

/*-------------------------------------------------------------------------
 *  makeTree -- create a tree with leftMostChild, rightSibling
 *    Args:
 *    Returns:  makes the tree
 *    Throws:
 *    See:
 *    Bugs:
 -------------------------------------------------------------------------*/


void Tree::makeTree(int *array, int n) {
  int i = 0;
  root = new TreeNode;
  root->leftMostChild = NULL;
  root->rightSibling = NULL;
  root->element = 0;
 
  while (i < n) {
      root->leftMostChild = (treeptr) makeTreeHelper(root->leftMostChild,array[i]);
      i++;
   }
}


/*-------------------------------------------------------------------------
 *  height -- returns the height of a tree
 *    Args:
 *    Returns:  int
 *    Throws:
 *    See:
 *    Bugs:
 -------------------------------------------------------------------------*/
int Tree::height(treeptr ptr) {
    if (!ptr)
        return 0;
    int temp=0;
    if(ptr->rightSibling)
        temp=height(ptr->rightSibling);
    if(ptr->leftMostChild)
        temp=max(temp,height(ptr->leftMostChild)+1);
                             return temp;
}


/*-------------------------------------------------------------------------
 *  numLeaves -- returns the number of leaves in the tree
 *    Args:
 *    Returns:  int
 *    Throws:
 *    See:
 *    Bugs:
 -------------------------------------------------------------------------*/

int Tree::numLeaves(treeptr ptr) {
    if(!ptr)
        return 0;
    int temp=0;
    if(ptr->rightSibling)
        temp+=numLeaves(ptr->rightSibling);
    if(ptr->leftMostChild)
        temp+=numLeaves(ptr->leftMostChild);
    else
        temp++;
    return temp;
}


/*-------------------------------------------------------------------------
 *  main -- Main program
 *    Args:
 *    Returns:  int
 *    Throws:
 *    See:
 *    Bugs:
 -------------------------------------------------------------------------*/
int main() {
  Tree T1;
  int i, n;
  int *array;
  cin >> n;
  array = new int [n];
  for (i = 0; i < n; i++)
    cin >> array[i];
  
  T1.makeTree(array, n);

  cout << "Height of the tree is: " << T1.height(T1.getRoot())<< endl;
  cout << "Number of Leaves: "<< T1.numLeaves(T1.getRoot()) << endl;
  
  return 0;
}
