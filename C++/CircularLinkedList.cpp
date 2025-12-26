#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            this->data = d;
            this->next = NULL;
        }

        ~Node(){
            int val = this->data;
            if(next!=NULL){
                delete next;
                next = NULL;
            }
            cout<<"Memory freed for Node having value: "<<val<<endl;
        }
};

void insertNode(Node* &tail,int element,int d){
    //empty list
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    // assuming the element is present in the list
    //non-empty list
    else{
        Node* curr = tail;
        while(curr->data!=element){
            curr = curr->next;
        }

        //element found, and curr is representing that node having element
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }

}

void print(Node* tail){
    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail!=temp);

    cout<<endl;
}

void deleteNode(Node* &tail, int value){
    //empty list
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        // non-empty list

        //assuming the "value" is present in linked list
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data!=value){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        // if only 1 node in LL
        if(curr == prev){
            tail = NULL;
        }
        // if 2 or more nodes present in the LL
        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

bool isCircularList(Node* head){
    // empty list
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }
    if(temp == head) return true;

    return false;
}

//Detect Loop question code
//Approach 1

bool detectLoop(Node*head){
    if(head == NULL)
        return false;
    
    map<Node*,bool> visited;

    Node* temp = head; //node for list traversal

    while(temp!=NULL){
        //cycle is present
        if(visited[temp] ==true){
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;

}

Node* floydDetectLoop(Node* head){
    if(head == NULL) 
        return NULL;
    
    //Floyd Cycle Detection Algorithm Logic
    Node* slow = head;
    Node* fast = head;

    while(slow!= NULL && fast!= NULL){
        fast = fast->next;
        if(fast!=NULL)
            fast = fast->next;
        slow = slow->next;

        if(slow==fast){
            cout<<"Cycle present at "<<slow->data<<endl;
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNode(Node* head){
    if(head==NULL)
        return NULL;
    
    Node* intersect = floydDetectLoop(head);

    Node* slow = head;

    while(slow!=intersect){
        slow = slow->next;
        intersect = intersect->next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head == NULL)
        return;
    
    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next!=startOfLoop){
        temp = temp->next;
    }
    temp->next = NULL;
}

int main(){
    Node* tail = NULL;

    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    // insertNode(tail,5,6);
    // print(tail);

    // insertNode(tail,3,4);
    // print(tail);

    // insertNode(tail,7,8);
    // print(tail);

    // deleteNode(tail,3);
    // print(tail);

    if(floydDetectLoop(tail)){
        cout<<"The given linked list is Circular"<<endl;
    }else{
        cout<<"The given linked list is NOT Circular"<<endl;

    }
    // if(isCircularList(tail)){
    //     cout<<"The given linked list is Circular"<<endl;
    // }else{
    //     cout<<"The given linked list is NOT Circular"<<endl;

    // }
    Node* loop = getStartingNode(tail);
    cout<<"The loop in the linked list begins at node having data "<<loop->data<<endl;

    removeLoop(tail);
    print(tail);
    
    return 0;
}