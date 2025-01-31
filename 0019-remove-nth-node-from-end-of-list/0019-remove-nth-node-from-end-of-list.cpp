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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(!head) // If list is empty, return null
       {
        return nullptr;
       }
         ListNode* ptr = head;
         int length = 0;
         
         while(ptr)  // Calculate length of linked list
         {
            ptr = ptr->next;
            length++;
         }
            if (n == length)   // If removing the first node (head)
            
        {
        ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ptr = head; // Reset pointer to head

        // Traverse to the (length - n - 1)th node
        for (int i = 1; i < length - n; i++) {
            ptr = ptr->next;
        }

        // Remove nth node
        ListNode* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;

        return head;


    }
};