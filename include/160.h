struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = listLength(headA);
        int sizeB = listLength(headB);
        ListNode* a = headA;
        ListNode* b = headB;
        if(sizeA > sizeB) {
          int diff = sizeA-sizeB;
          for(int i = 0; i<diff; i++) {
            a = a->next;
          }
        } else {
          int diff = sizeB-sizeA;
          for(int i = 0; i<diff; i++) {
            b = b->next;
          }
        }
        while(a!=nullptr) {
          if(a == b) return a;
          a = a->next;
          b = b->next;
        }
        return nullptr;
    }

    int listLength(ListNode *head) {
      int size = 0;
      while (head!=nullptr) {
        head = head->next;
        size++;
      }
      return size;
    }
};