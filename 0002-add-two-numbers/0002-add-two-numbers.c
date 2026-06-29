struct ListNode* addWithCarry(struct ListNode* l1, struct ListNode* l2, int carry);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // We would need a helper function to pass the carry along, like:
    return addWithCarry(l1, l2, 0);
}

struct ListNode* addWithCarry(struct ListNode* l1, struct ListNode* l2, int carry) {
    // Base case: if everything is empty and no carry, stop
    if (l1 == NULL && l2 == NULL && carry == 0) return NULL;
    
    int sum = carry;
    if (l1 != NULL) { sum += l1->val; l1 = l1->next; }
    if (l2 != NULL) { sum += l2->val; l2 = l2->next; }
    
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->val = sum % 10;
    
    // RECURSIVE CALL: The function calls itself to handle the next nodes
    result->next = addWithCarry(l1, l2, sum / 10); 
    
    return result;
}