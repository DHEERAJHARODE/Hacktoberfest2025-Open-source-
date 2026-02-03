#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

int calcSize (struct Node *node)
{
  int size = 0;

  while (node != NULL)
    {
      node = node->next;
      size++;
    }
  return size;
}

void insertPosition (int pos, int data, struct Node **head)
{
  int size = calcSize (*head);

  //If pos is 0 then should use insertStart method
  //If pos is less than 0 then can't enter at all
  //If pos is greater than size then bufferbound issue
  if (pos < 1 || size < pos)
    {
      printf ("Can't insert, %d is not a valid position\n", pos);

    }
  else
    {
      struct Node *temp = *head;
      struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
      newNode->data = data;
      newNode->next = NULL;

      while (--pos)
	{
	  temp = temp->next;
	}
      //(25)->next = 10 as 12->next is 10 
      newNode->next = temp->next;
      // (12)->next = 25
      temp->next = newNode;
      //new node added in b/w 12 and 10
    }
}

void insertStart (struct Node **head, int data)
{

  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));

  newNode->data = data;
  newNode->next = *head;

  //changing the new head to this freshly entered node
  *head = newNode;
}

void insertLast (struct Node **head, int data)
{

  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));

  newNode->data = data;
  newNode->next = NULL;

  //need this if there is no node present in linked list at all
  if (*head == NULL)
    {
      *head = newNode;
      return;
    }

  struct Node *temp = *head;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;
}

void display (struct Node *node)
{

  //as linked list will end when Node is Null
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf ("\n");
}

int main ()
{
  struct Node *head = NULL;

  // Need '&' i.e. address as we need to change head
  insertStart (&head, 12);
  insertStart (&head, 16);
  insertStart (&head, 20);

  insertLast (&head, 10);
  insertLast (&head, 14);
  insertLast (&head, 18);
  insertLast (&head, 11);

  //Inserts after 3rd position
  insertPosition (3, 25, &head);

  // no need for '&' as head need not be changed
  // only doing traversal
  display (head);
  return 0;
}
