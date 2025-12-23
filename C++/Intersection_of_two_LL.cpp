class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(headA==NULL||headB==NULL){
          return NULL;
      }
      ListNode* d=headA;
      ListNode* c=headB;

      while(d!=c){
          if(d==NULL){
              d=headB;
          }
          else {
              d=d->next;
          }
          if(c==NULL){
              c=headA;
          }
          else{
              c=c->next;
          }
      }
return d;}
};
