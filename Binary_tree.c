#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *tree;
void create(struct node *);
struct node *insertElement(struct node *,int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *deleteElement(struct node *,int);

void main()
{
    int ch,val;
    struct node *ptr;
    create(tree);
    do{
        printf("\n1. Insert Element\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Delete Element\n6. Quit\n");
        printf("Enter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter value of new node: ");
            scanf("%d",&val);
            tree=insertElement(tree,val);
            break;
            case 2:
            printf("Elements of tree are: ");
            preorderTraversal(tree);
            break;
            case 3:
            printf("Elements of tree are: ");
            inorderTraversal(tree);
            break;
            case 4:
            printf("Elements of tree are: ");
            postorderTraversal(tree);
            break;
            case 5:
            printf("Elements number to be deleted: ");
            scanf("%d",&val);
            tree=deleteElement(tree,val);
            break;
            case 6:
            break;
            default:
            printf("Invalid choice\n");
        }
    }while(ch!=6);
}

void create(struct node *tree)
{
    tree=NULL;
}

struct node *insertElement(struct node *tree,int val)
{
    struct node *ptr,*nodeptr,*parentptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->left=NULL;
    ptr->right=NULL;
    if(tree==NULL)
    {
        tree=ptr;
        tree->left=NULL;
        tree->right=NULL;
    }
    else
    {
        parentptr=NULL;
        nodeptr=tree;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(val<nodeptr->data)
            nodeptr=nodeptr->left;
            else
            nodeptr=nodeptr->right;
        }
        if(val<parentptr->data)
        parentptr->left=ptr;
        else
        parentptr->right=ptr;
    }
    return tree;
}

void preorderTraversal(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t",tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree)
{
    if(tree!=NULL)
    {
        inorderTraversal(tree->left);
        printf("%d\t",tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node *tree)
{
    if(tree!=NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t",tree->data);
    }
}

struct node *deleteElement(struct node *tree,int val)
{
    struct node *cur,*parent,*suc,*psuc,*ptr;
    if(tree->left==NULL)
    {
        printf("\n Tree is Empty");
        return(tree);
    }
    parent=tree;
    cur=tree->left;
    while(cur!=NULL && val!=cur->data)
    {
        parent=cur;
        cur=(val<cur->data)?cur->left:cur->right;
    }
    if(cur==NULL)
    {
        printf("\nThe value to be deleted is not present in Tree");
        return(tree);
    }
    if(cur->left==NULL)
    ptr=cur->right;
    else if(cur->right==NULL)
    ptr=cur->left;
    else
    {
        //find inorder successor and its parent
        psuc=cur;
        cur=cur->left;
        while(suc->left!=NULL)
        {
            psuc=suc;
            suc=suc->left;
        }
        if(cur==psuc)
        {
            suc->left=cur->right;
        }
        else
        {
            suc->left=cur->left;
            psuc->left=suc->right;
            suc->right=cur->right;
        }
        ptr=suc;
    }
    //attacg ptr to parent node
    if(parent->left==cur)
    parent->left=ptr;
    else
    parent->right=ptr;
    free(cur);
    return tree;
}
