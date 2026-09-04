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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        vector<int> v;
        vector<int> v1;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0, j = v.size()-1;
        while(i<=j){
            if(i==j){
                v1.push_back(v[i]);
                break;
            }
            v1.push_back(v[i++]);
            v1.push_back(v[j--]);
            
        }
        temp = head;
        int k = 0;
        while(temp!=nullptr){
            temp->val = v1[k++];
            temp = temp->next;
        }
    }
};