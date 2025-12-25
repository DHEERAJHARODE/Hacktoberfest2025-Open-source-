class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* last; 
        Node* init; 
        Node* prev;
        
        last = init = prev = head ;
        int count = 0;
        while(last->next != NULL)
        {
            if(count == k-1)
            {
                prev = last;
                head = prev->next;
               
            }
            count++;
            last = last->next;
        }
       
        if(count == k-1)
            return init;
         prev->next = NULL;
        last->next = init;
       
        return head;
    }
};
