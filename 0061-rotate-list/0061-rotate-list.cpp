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
        // Handle edge cases: empty list or single node
        if (!head || !head->next) {
            return head;
        }
      
        // Calculate the length of the linked list
        ListNode* current = head;
        int length = 0;
        while (current) {
            ++length;
            current = current->next;
        }
      
        // Optimize k by taking modulo with length to avoid unnecessary rotations
        k %= length;
      
        // If k is 0, no rotation needed
        if (k == 0) {
            return head;
        }
      
        // Use two-pointer technique to find the rotation point
        // Fast pointer moves k steps ahead
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;
      
        // Move fast pointer k steps ahead
        while (k--) {
            fastPointer = fastPointer->next;
        }
      
        // Move both pointers until fast reaches the last node
        // Slow will point to the node before the new head
        while (fastPointer->next) {
            fastPointer = fastPointer->next;
            slowPointer = slowPointer->next;
        }
      
        // Perform the rotation:
        // 1. New head is the node after slow pointer
        ListNode* newHead = slowPointer->next;
      
        // 2. Break the link at rotation point
        slowPointer->next = nullptr;
      
        // 3. Connect the last node to the original head
        fastPointer->next = head;
      
        return newHead;
    }
};
