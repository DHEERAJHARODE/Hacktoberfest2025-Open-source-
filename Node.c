#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next; // Pointer to the next node in the list
};

// Main function to handle the menu
int main() {
    struct Node* head = NULL; // Initialize an empty list (head points to NULL)
    int choice, data, pos;

    while (1) {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Traverse the List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insert_at_beg(&head, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insert_at_end(&head, data);
                break;
            case 3:
                printf("Enter the position and data to insert: ");
                scanf("%d %d", &pos, &data);
                insert_at_pos(&head, data, pos);
                break;
            case 4:
                del_from_beg(&head);
                break;
            case 5:
                del_from_end(&head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                del_at_pos(&head, pos);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Insert a node at the beginning of the list
void insert_at_beg(struct Node** head, int data) {
    // Allocate memory for a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;  // Set the data field
    new_node->next = *head; // New node points to the current head
    *head = new_node;       // Update head to the new node
    printf("Node inserted at the beginning.\n");
}

// Insert a node at the end of the list
void insert_at_end(struct Node** head, int data) {
    // Allocate memory for a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;  // Set the data field
    new_node->next = NULL;  // End node's next should be NULL

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = new_node;
    } else {
        // Traverse to the last node
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node; // Last node's next points to the new node
    }
    printf("Node inserted at the end.\n");
}

// Insert a node at a specific position in the list
void insert_at_pos(struct Node** head, int data, int pos) {
	int i;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data; // Set the data field

    if (pos == 1) {
        // Inserting at the first position (beginning)
        new_node->next = *head;
        *head = new_node;
        printf("Node inserted at position %d.\n", pos);
        return;
    }

    struct Node* temp = *head;
    // Traverse to the node before the desired position
    for (i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
    } else {
        new_node->next = temp->next;
        temp->next = new_node;
        printf("Node inserted at position %d.\n", pos);
    }
}

// Delete a node from the beginning of the list
void del_from_beg(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *head; // Store the head node
    *head = (*head)->next;     // Move the head pointer to the next node
    free(temp);                // Free the memory of the old head
    printf("Node deleted from the beginning.\n");
}

// Delete a node from the end of the list
void del_from_end(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;

    if (temp->next == NULL) {
        // Only one node in the list
        free(temp);
        *head = NULL;
    } else {
        // Traverse to the second last node
        struct Node* prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL; // Second last node's next should be NULL
        free(temp);        // Free the last node
    }
    printf("Node deleted from the end.\n");
}

// Delete a node at a specific position in the list
void del_at_pos(struct Node** head, int pos) {
	int i;
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;

    if (pos == 1) {
        // Deleting the first node
        *head = (*head)->next;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
        return;
    }

    struct Node* prev = NULL;
    // Traverse to the node before the desired position
    for (i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
    }
}

// Traverse and print the data of all nodes in the list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("The list is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data); // Print the data of the current node
        temp = temp->next;            // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
  }
