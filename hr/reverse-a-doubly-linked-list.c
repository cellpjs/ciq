

// Complete the reverse function below.

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
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* p = head;
    DoublyLinkedListNode* temp;
    if (p == NULL) {
        return p;
    }
    while (p->next !=NULL) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = temp;
    }
    /* last node */
    p->next = p->prev;
    p->prev = NULL;
    return p;
}



