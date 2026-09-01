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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        ListNode* temp1;
        for(ListNode* i : lists){
            temp1 = i;
            while(temp1!=nullptr){
                v.push_back(temp1->val);
                temp1=temp1->next;
            }
        }
        if(v.empty()) return nullptr;
        sort(v.begin(),v.end());
        int n = v.size()-1;
        ListNode* temp=new ListNode(v[0]);
        ListNode* head = temp;
        int i = 1;
        while(n--){
            ListNode* temp1 = new ListNode(v[i++]);
            temp->next = temp1;
            temp = temp->next;
        }
        return head;
    }
};