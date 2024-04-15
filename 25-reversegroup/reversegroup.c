#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// 翻转链表的一部分，并返回新的头节点
ListNode* reverse(ListNode* start, ListNode* end) {
    ListNode *prev = end->next;
    ListNode *p = start;
    while (p != end) {
        ListNode *tmp = p->next;
        p->next = prev;
        prev = p;
        p = tmp;
    }
    p->next = prev; // Don't forget to link the last node
    return end; // 翻转后的头节点
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy = {0, head};
    ListNode *pre = &dummy, *end = &dummy;

    while (end->next != NULL) {
        for (int i = 0; i < k && end != NULL; i++) end = end->next;
        if (end == NULL) break;

        ListNode *start = pre->next;
        ListNode *next = end->next;

        pre->next = reverse(start, end);

        start->next = next;
        pre = start;
        end = pre;
    }

    return dummy.next;
}

// Function to create a list from an array
ListNode* createList(int* arr, int n) {
    ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; ++i) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to print the list
void printList(ListNode *node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int elements[] = {1, 2, 3, 4, 5};// 默认输入
    int k = 2; // 默认分组大小

    if (argc > 1) {
        // 例子中未处理命令行参数转换为链表，这里假设传入已经是整数数组和k的值
        // 例如，直接从命令行参数中获取k的值
        k = atoi(argv[1]);
    }

    ListNode *head = createList(elements, sizeof(elements) / sizeof(elements[0]));
    head = reverseKGroup(head, k);

    printf("Reversed list: ");
    printList(head);

    return 0;
}
