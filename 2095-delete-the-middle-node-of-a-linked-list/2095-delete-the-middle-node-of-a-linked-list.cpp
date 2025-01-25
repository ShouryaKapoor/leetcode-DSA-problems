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
    ListNode* deleteMiddle(ListNode* head) {
      
       if(head == nullptr || head->next == nullptr)
       {
        return nullptr;
       }

        ListNode* ptr = head;
        int length = 0;
        while(ptr != nullptr)
        {
            ptr = ptr->next;
            length++;
        }

        int mid  = length/2;
        ListNode* ptr2 = head;
        for(int i = 0;i<mid-1;i++)
        {
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr2->next->next;

        return head;

    }
};