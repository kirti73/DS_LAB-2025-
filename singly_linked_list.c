#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL, *new_node, *temp, *last;

void create(int value)
{
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
}

void insert_at_beg(int value)
{
    create(value);
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int value)
{
    create(value);
    if (head == NULL) {
        head = new_node;
        return;
    }
    last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void insert_at_pos(int value, int pos)
{
    if (pos <= 1 || head == NULL) {
        insert_at_beg(value);
        return;
    }

    create(value);
    temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void display()
{
    temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int c, v, p;
    do {
        printf("\n1. Insert at start\n2. Insert at end\n3. Insert at position\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &v);
                insert_at_beg(v);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &v);
                insert_at_end(v);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &v);
                printf("Enter position: ");
                scanf("%d", &p);
                insert_at_pos(v, p);
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (c != 5);

    return 0;
}

