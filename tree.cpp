#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct tree
{
  int dato;
  tree *sx, *dx;
} tree;

int main()
{
  // Tree
  // cerca(tree)
}

int cercaBST(tree *root)
{
  if (root->dx != NULL)
  {
    cercaBST(root->dx);
  }
  else
  {
    return root->dato;
  }
}

int maxDato;
int cercaNonBST(tree *root)
{
  if (root->sx != NULL)
  {
  }
}
