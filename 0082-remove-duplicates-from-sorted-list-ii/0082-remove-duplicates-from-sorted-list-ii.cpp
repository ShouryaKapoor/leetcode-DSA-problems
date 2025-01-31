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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head; // Edge cases: empty list or single node

        ListNode* dummy = new ListNode(0); // Dummy node to handle edge cases
        dummy->next = head;
        ListNode* prev = dummy; // Points to the last node with no duplicates
        ListNode* current = head;

        while (current) {
            // Check if the current node's value is duplicated
            bool isDuplicate = false;
            while (current->next && current->val == current->next->val) {
                isDuplicate = true;
                ListNode* temp = current;
                current = current->next;
                delete temp; // Free memory of the duplicate node
            }

            if (isDuplicate) {
                // Skip all nodes with the duplicate value
                ListNode* temp = current;
                current = current->next;
                delete temp; // Free memory of the last duplicate node
                prev->next = current; // Update prev->next to skip duplicates
            } else {
                // No duplicates, move prev forward
                prev = current;
                current = current->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Free memory of the dummy node
        return newHead;
    }
};