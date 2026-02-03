void insertAfter(struct Node* prev_node, int data) {

  
    if (prev_node == NULL) {
        cout << "previous node cannot be NULL";
        return;
    }

    struct Node* newNode = new Node;

 
    newNode->data = data;

    
    newNode->next = prev_node->next;


    prev_node->next = newNode;

  
    newNode->prev = prev_node;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}
