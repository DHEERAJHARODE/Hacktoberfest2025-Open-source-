#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *create_node(int v) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = v;
    p->next = NULL;
    return p;
}

void insert_end(Node **rear, int v) {
    Node *newn = create_node(v);
    if (!*rear) {
        *rear = newn;
        newn->next = newn;
        return;
    }
    newn->next = (*rear)->next;
    (*rear)->next = newn;
    *rear = newn;
}

void delete_node(Node **rear, int val) {
    if (!*rear) {
        printf("List is empty.\n");
        return;
    }

    Node *cur = (*rear)->next;
    Node *prev = *rear;
    do {
        if (cur->data == val) {
            if (cur == *rear && cur->next == *rear) {
                free(cur);
                *rear = NULL;
            } else {
                prev->next = cur->next;
                if (cur == *rear)
                    *rear = prev;
                free(cur);
            }
            printf("Deleted %d\n", val);
            return;
        }
        prev = cur;
        cur = cur->next;
    } while (cur != (*rear)->next);

    printf("Value not found.\n");
}

void update_node(Node *rear, int old, int new) {
    if (!rear) {
        printf("List is empty.\n");
        return;
    }
    Node *cur = rear->next;
    do {
        if (cur->data == old) {
            cur->data = new;
            printf("Updated %d to %d\n", old, new);
            return;
        }
        cur = cur->next;
    } while (cur != rear->next);
    printf("Value not found.\n");
}

void display(Node *rear) {
    if (!rear) {
        printf("List is empty.\n");
        return;
    }
    Node *cur = rear->next;
    do {
        printf("%d ", cur->data);
        cur = cur->next;
    } while (cur != rear->next);
    printf("\n");
}

int main() {
    Node *rear = NULL;
    int choice, val, old, new;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Update\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert_end(&rear, val);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            delete_node(&rear, val);
            break;
        case 3:
            printf("Enter value to update: ");
            scanf("%d", &old);
            printf("Enter new value: ");
            scanf("%d", &new);
            update_node(rear, old, new);
            break;
        case 4:
            display(rear);
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}