struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution24 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* n1 = dummyHead;
        ListNode* n2 = head;
        if(n2 == nullptr || head->next == nullptr) return head;
        while(n1 != nullptr && n2 != nullptr) {
          ListNode* tmp = n2->next;
          n1->next = tmp;
          if(tmp == nullptr) break;
          n2->next = tmp->next;
          tmp->next = n2;
          n1 = n2;
          n2 = n2->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        dummyHead = nullptr;
        return head;
    }
};