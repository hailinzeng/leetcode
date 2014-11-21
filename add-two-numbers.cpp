/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode* result = new ListNode(0);
        ListNode* presult = result;
        
        int carry = 0;
        int sum = 0;
        
        while(l1 != NULL || l2 != NULL || carry != 0){
            
            if(l1 != NULL && l2 != NULL){
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1 != NULL){
                sum = l1->val + carry;
                l1 = l1->next;
            }else if(l2 != NULL){
                sum = l2->val + carry;
                l2 = l2->next;
            }else{
                sum = carry;
            }
            
            carry = sum / 10;
            presult->val = sum % 10;
            
            if(l1 != NULL || l2 != NULL || carry != 0){
                presult->next = new ListNode(0);
                presult = presult->next;
            }
        }
        
        return result;
    }
};
