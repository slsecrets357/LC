
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution19 {
public:
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode* cur = head;
    //     int size = 0;
    //     while(cur != nullptr) {
    //       printf("hi\n");
    //       size++;
    //       cur = cur->next;
    //     }
    //     printf("size:%d\n", size);
    //     if (size == 1) return nullptr;
    //     if (size < n) return head;
    //     if (size == n) {
    //       cur = head;
    //       head = head->next;
    //       delete cur;
    //       cur = nullptr;
    //       return head;
    //     }
    //     cur = head;
    //     for (int i = 0; i<size-n-1; i++) {
    //       cur = cur->next;
    //     }
    //     printf("cur val: %d\n", cur->val);
    //     ListNode* tmp = cur->next;
    //     if (tmp->next == nullptr) {
    //       cur->next = nullptr;
    //     } else {
    //       cur->next = tmp->next;
    //     }
    //     delete tmp;
    //     tmp = nullptr;
    //     return head;
    // }

    //s2
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummyHead = new ListNode(0, head);
      ListNode* fast = dummyHead;
      ListNode* slow = dummyHead;
      for(int i = 0; i<n+1; i++) {
        if (fast == nullptr) {
          return head;
        }
        fast = fast->next;
      }
      while (fast!=nullptr) {
        fast = fast->next;
        slow = slow->next;
      }
      fast = slow->next;
      slow->next = fast->next;
      delete fast;
      fast = nullptr;
      head = dummyHead->next;
      delete dummyHead;
      dummyHead = nullptr;
      return head;
    }

};