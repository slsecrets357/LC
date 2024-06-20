struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    //s1
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* tmp;
    //     ListNode* cur1 = head;
    //     ListNode* pre = nullptr;
    //     while(cur1) {
    //         tmp = cur1->next;
    //         cur1->next = pre;
    //         pre = cur1;
    //         cur1 = tmp;
    //     }
    //     return pre;
    // }

    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == nullptr) return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};