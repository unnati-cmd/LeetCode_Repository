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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v1;
        vector<int> v2;
        ListNode* temp = head;
        while (temp != nullptr) {
            if (temp->val < x)
                v1.push_back(temp->val);
            else
                v2.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int i = 0, j = 0;
        while (temp != nullptr) {
            if (i < v1.size())
                temp->val = v1[i++];
            else 
                if (j < v2.size())
                    temp->val = v2[j++];
            temp = temp->next;
        }
        return head;
    }
};