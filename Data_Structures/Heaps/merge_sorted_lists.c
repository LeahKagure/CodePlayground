// Given k sorted singly linked lists, merge them into a single sorted list

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode* mergeKLists(ListNode** lists, int k) {
    if (k == 0)
        return NULL;

    int interval = 1;
    while (interval < k) {
        for (int i = 0; i < k - interval; i += interval * 2)
            lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        interval *= 2;
    }

    return lists[0];
}

void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    ListNode* list1 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* list2 = (ListNode*)malloc(sizeof(ListNode));
    ListNode* list3 = (ListNode*)malloc(sizeof(ListNode));

    list1->val = 1;
    list1->next = (ListNode*)malloc(sizeof(ListNode));
    list1->next->val = 4;
    list1->next->next = (ListNode*)malloc(sizeof(ListNode));
    list1->next->next->val = 5;
    list1->next->next->next = NULL;

    list2->val = 1;
    list2->next = (ListNode*)malloc(sizeof(ListNode));
    list2->next->val = 3;
    list2->next->next = (ListNode*)malloc(sizeof(ListNode));
    list2->next->next->val = 4;
    list2->next->next->next = NULL;

    list3->val = 2;
    list3->next = (ListNode*)malloc(sizeof(ListNode));
    list3->next->val = 6;
    list3->next->next = NULL;

    ListNode** lists = (ListNode**)malloc(3 * sizeof(ListNode*));
    lists[0] = list1;
    lists[1] = list2;
    lists[2] = list3;

    ListNode* mergedList = mergeKLists(lists, 3);
    printList(mergedList);

    free(list1->next->next);
    free(list1->next);
    free(list1);
    free(list2->next->next);
    free(list2->next);
    free(list2);
    free(list3->next);
    free(list3);
    free(lists);

    return 0;
}
