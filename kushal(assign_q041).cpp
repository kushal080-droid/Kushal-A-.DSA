#include <stdio.h>
#include <stdlib.h>

struct Task {
    int id;
    int status; // 0 = incomplete, 1 = complete
    struct Task* next;
};

struct Task* createNode(int id, int status) {
    struct Task* newNode = (struct Task*)malloc(sizeof(struct Task));
    newNode->id = id;
    newNode->status = status;
    newNode->next = NULL;
    return newNode;
}

int countCompleted(struct Task* head) {
    int count = 0;
    struct Task* temp = head;

    while (temp != NULL) {
        if (temp->status == 1)
            count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    // Sample linked list: ID, Status
    struct Task* head = createNode(1, 0);
    head->next = createNode(2, 1);
    head->next->next = createNode(3, 1);
    head->next->next->next = createNode(4, 0);

    printf("Number of completed tasks: %d\n", countCompleted(head));

    return 0;
}

