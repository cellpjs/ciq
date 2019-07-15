

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* p = head;
    DoublyLinkedListNode* q = malloc(sizeof(DoublyLinkedListNode));
    DoublyLinkedListNode* temp;
    q->data = data;
    q->next = NULL;
    q->prev = NULL;
    if (data < head->data) {
        /* q becomes head */
        head->prev = q;
        q->next = head;
        head = q;
        return head;
    }
    while (data > p->data && p->next != NULL) {
        p = p->next;
    }
    if (data > p->data) {
        /* q becomes tail */
        p->next = q;
        q->prev = p;
        return head;
    } else {
        // p->data >= data so insert q between p->prev and p
        q->next = p;
        q->prev = p->prev;
        p->prev->next = q;
        p->prev = q;
        return head;
    }
}



