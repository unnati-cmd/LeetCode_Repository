/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string num = "";
        while(temp!=nullptr){
            num += (temp->val);
            temp = temp->next;
        } 
        int i = num.size() - 1, j = 0;
        long long number = 0;
        while(j<num.size()){
            number += ((int)num[j++] * pow(2,i--));
        }
        return number;
    }
};