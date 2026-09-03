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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 or head == nullptr) return head;
        ListNode* temp = head;
        ListNode* temp1 = head;
        int size = 0;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        if(size == 1) return head;
        k %= size;
        if(k == 0) return head;
        int move = size - k - 1;
        temp = head;
        while (move--) {
            temp = temp->next;
        }
        ListNode* newNode = temp->next;
        head = newNode;
        temp->next = nullptr;
        while (newNode->next != nullptr) {
            newNode = newNode->next;
        }
        newNode->next = temp1;
        return head;
    }
};