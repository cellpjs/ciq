

// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* p = head1;
    SinglyLinkedListNode* q = head2;
    int dp = 0;
    int dq = 0;
    int i;
    while (p->next !=NULL) {
        p = p->next;
        dp++;
    }
    while (q->next !=NULL) {
        q = q->next;
        dq++;
    }
    p = head1;
    q = head2;
    if (dp>dq) {
        for (i=0; i<dp-dq; i++) {
            p = p->next;
        }
    } else {
        for (i=0; i<dq-dp; i++) {
            q = q->next;
        }
    }
    while (p!=q) {
        p = p->next;
        q = q->next;
    }
    return p->data;
}



