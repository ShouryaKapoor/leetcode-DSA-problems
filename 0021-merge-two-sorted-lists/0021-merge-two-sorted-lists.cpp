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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        list1* ptr1 = head;
        list2* ptr2 = head;
        ListNode* list3;
        list3* ptr3 = head;
        while(ptr1->next->val<ptr2->next->val)
        {
            ptr3->next == ptr1->next
            ptr3->next->val == ptr1->next->val;
        }
        return ptr3;
    }
};