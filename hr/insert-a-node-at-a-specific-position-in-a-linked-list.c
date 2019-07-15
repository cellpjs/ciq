

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* p = head;
    if (position == 0) {
        printf("not implemented yet");
        exit(-1);
    }
    for (int i=0; i<position-1; i++){
        p = p->next;
    }
    //printf("now at %d\n", p->data);
    SinglyLinkedListNode *q = malloc(sizeof(SinglyLinkedListNode));
    q->data = data;
    q->next = p->next;
    p->next = q;
    return head;
}



