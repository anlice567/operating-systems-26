#include <stdio.h>

int size = 3;

struct Node {
    int value;
    struct Node* next;
};

void swap(struct Node* node1, struct Node* node2) {
    struct Node temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

void insert_node(int value, struct Node arr[], int index) {
    arr[index].value = value;
    if (index > 0) {
        arr[index-1].next = &arr[index];
    }
    if (index == 2) {
        arr[index].next = NULL;
    }
}

void delete_node(struct Node arr[], int index) {
    arr[index-1].next = &arr[index+1];
}

void print_list(struct Node arr[]) {
    int i = 0;
    while (arr[i].next != NULL) {
        printf("%d ", arr[i].next->value);
        i++;
    }
}

int main() {
    struct Node arr[3];
    int val;
    for (int i = 0; i < size; i++) {
        scanf("%d",&val);
        insert_node(val,arr,i);
    }

    delete_node(arr,1);
    print_list(arr);
}
