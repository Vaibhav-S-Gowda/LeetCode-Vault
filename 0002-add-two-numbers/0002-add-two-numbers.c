struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode* curr = &dummy; // This pointer will move as we add nodes
    
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next; 
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next; 
        }
        
        carry = sum / 10; 
        
        // Create a new node for the single digit (e.g., 12 % 10 = 2)
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        curr->next = newNode;
        curr = curr->next;
    }
    
    // Return dummy.next because dummy itself was just a placeholder
    return dummy.next; 
}
