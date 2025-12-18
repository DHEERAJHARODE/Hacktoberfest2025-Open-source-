// the following code will contain two methods of reversing a linked list recursively
// 1st
node *reverse(node*head){
  if(head->next || head){
    return head;
  }
  node*last = reverse(head->next);
  while(last=>next !=NULL){
    last = last->next;
  }
  last->next = head;
  head->next = NULL;
  return last;
 //time complexity : O(n^2)
 // 2nd
 node *recreverse(node*head){
   if(head->next|| head){
     return head;
   }
   node *last = recreverse(head->next);
   head->next->next = head;
   head->next = NULL:
   return last;
 }
 // time complexity : O(n)
