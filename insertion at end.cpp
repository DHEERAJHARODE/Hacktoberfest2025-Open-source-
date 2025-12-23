void insertEnd(struct Node** head, int data) {
   
    struct Node* newNode = new Node;

    newNode->data = data;

   
    newNode->next = NULL;

   
    struct Node* temp = *head;

   
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }


    while (temp->next != NULL)
        temp = temp->next;
   
    temp->next = newNode;

    newNode->prev = temp;
}
