/*
    AUTHOR: Parth Dhall
    Github: DarkGamer7890
    https://github.com/DarkGamer7890
*/


#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* ptr): val(x), next(ptr) {}
};

class List{
    ListNode* head = nullptr;

public:

    void insert(int x){
        if(!head){
            head = new ListNode(x);
        }
        else{
            ListNode* temp = head;
            while(temp->next) temp = temp->next;

            temp->next = new ListNode(x);
        }
    }

    void reverse(){
        if(!head) return;
        else if(!head->next) return;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(curr){
            curr->next = prev;

            prev = curr;
            curr = next;
            if(next) next = next->next;
        }

        head = prev;
    }

    void display(){
        ListNode* temp = head;

        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};


int main(){
    List l;
    
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.display();

    l.reverse();
    l.display();

    return 0;
}
