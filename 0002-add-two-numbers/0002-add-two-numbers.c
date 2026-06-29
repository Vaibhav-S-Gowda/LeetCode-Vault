struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum = 0;
    int carry = 0;
    struct ListNode* index1 = l1;
    struct ListNode* index2 = l2;
    struct ListNode* new_node = malloc(sizeof(struct ListNode));
    struct ListNode* base_node = new_node;

    new_node->next = NULL;

    do {
        sum = ((index1 == NULL) ? 0 : index1->val) + ((index2 == NULL) ? 0 : index2->val) + carry;
        carry = 0;

        if (sum >= 10) {
            sum -= 10;
            carry = 1;
        }

        new_node->val = sum;

        if (index1 != NULL) index1 = index1->next;
        if (index2 != NULL) index2 = index2->next;

        if (index1 != NULL || index2 != NULL || carry != 0) {
            new_node->next = malloc(sizeof(struct ListNode));
            new_node = new_node->next;
            new_node->next = NULL;
        }


    } while (index1 != NULL || index2 != NULL || carry != 0);

    return base_node;
}