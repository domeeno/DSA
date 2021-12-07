struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* newNode(int value) {
    struct ListNode *new_node;
    new_node = malloc(sizeof(struct ListNode));
    new_node->val = value;
    new_node->next = NULL;
    return new_node;
}

struct ListNode* computeSumNodes(struct ListNode* l1, struct ListNode* l2, 
                                 bool carry, struct ListNode* node) {

    int sum = l1->val + l2->val + carry;
    if(sum >= 10) {
        node->val = sum - 10;
        carry = true;
    } else {
        node->val = sum;
        carry = false;
    }
    
    if(l2->next != NULL && l1->next != NULL) {
        node->next = newNode(0);
        computeSumNodes(l1->next, l2->next, carry, node->next);
    } else if ((l2->next == NULL) != (l1->next == NULL)) {
        node->next = newNode(0);
        if(l1->next != NULL) {
            computeSumNodes(l1->next, newNode(0), carry, node->next);
        } else if(l2->next != NULL) {
            computeSumNodes(newNode(0), l2->next, carry, node->next);
        } 
    } else if (carry) {
        node->next = newNode(0);
        computeSumNodes(newNode(0), newNode(0), carry, node->next);
    }
    
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *node = newNode(0);
    struct ListNode* result = computeSumNodes(l1, l2, false, node);
    return result;
}
