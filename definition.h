#include <iostream>

using namespace std;

#define MAX_STACK_SIZE 1024

typedef struct LinkNode
{
  int value;
  struct LinkNode* next;
}LNode, *PtrLNode;

typedef struct _TreeNode
{
    int value;
    struct _TreeNode* left;
    struct _TreeNode* right;
}TreeNode, *PtrTreeNode;

typedef struct _MyStack
{
    int top;
    int* a;
}MyStack;

template<typename T>
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
  //  a = a^b;
   // b = a^b;
   // a = a^b;
}