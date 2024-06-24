#include "ListNode.h"
#include <vector>

using namespace std;
class Solution142 {
public:
    //s1
    // ListNode *detectCycle(ListNode *head) {
    //     if(head == nullptr) return head;
    //     ListNode* cur = head;
    //     vector<ListNode*> list;
    //     while(cur->next != nullptr) {
    //         printf("cur: %d, cur->next: %d, size: %d,\n", cur->val, cur->next->val, list.size());
    //         for(auto& listNode: list) {
    //             if (cur->next == listNode) {
    //                 printf("listNode: %d, cur->next: %d\n", listNode->val, cur->next->val);
    //                 return listNode;
    //             }
    //         }
    //         list.push_back(cur);
    //         cur = cur->next;
    //     }
    //     return nullptr;
    // }

    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return head;
        ListNode* fast = head;
        ListNode* slow = head; 
        while(slow!=nullptr && fast!=nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast) {
                fast = head;
                while (fast!=slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};