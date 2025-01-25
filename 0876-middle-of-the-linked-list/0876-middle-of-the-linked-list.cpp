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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr = head;
        ListNode* ptr2 = head;
        int length = 0;
        while(ptr!=NULL)
        {
            ptr = ptr->next;
            length++;
        }
        int mid = length/2;
        for(int i = 0;i<mid;i++)
        {
            ptr2 = ptr2->next;
        }
        return ptr2;
        
        
    }
};