//
// Doubly Linked List in c++
//

#include<iostream>
#include <cassert>

using namespace std;

template<class T>
class Node{
public:
    T data;
    Node *prev , *next;
};

// Doubly Linked List
template<class T> class DLinkedList{
public:
    DLinkedList(void){
        head = nullptr;
        tail = nullptr;
    }

    // Push
    void Push(T data){
        Node<T>* newNode = new Node<T>{data , nullptr , nullptr};

        // null case
        if(head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    //Push Back
    void Push_Back(T data){
        Node<T>* newNode = new Node<T>{data , nullptr , nullptr};

        // null case
        if(head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // push's After a given Node
    void Push_After(Node<T>* node , T data){

        // case Node is Last Element
        if(node->next == nullptr){
            Push_Back(data);
            return;
        }
        cout<<"I have Control"<<endl;
        Node<T>* newNode = new Node<T>{data , nullptr , nullptr};

        newNode->next = node->next;
        newNode->prev = node;

        node->next->prev = newNode;
        node->next = newNode;
    }

    // Push's Before a given Node
    void Push_Before(Node<T>* node , T data){
        // case node is First Element
        if(node->prev == nullptr){
            Push(data);
            return;
        }

        Node<T>* newNode = new Node<T>{data , nullptr , nullptr};

        newNode->prev = node->prev;
        newNode->next = node;

        node->prev->next = newNode;
        node->prev = newNode;
    }

    /* Deletion From linkedList */

    // Deletes N Node
    void Remove(Node<T>* node){

        if(node == head) // Case first element
            head = head->next;
        if(node == tail) // Case last element
            tail = tail->prev;

        if(node->prev != nullptr)
            node->prev->next = node->next;
        if(node->next != nullptr)
            node->next->prev = node->prev;

        delete node;
    }

    // Delete's Top Node of LinkedList
    void Pop(void){
        if(IsEmpty()) return; // case no element's in linkedlist

        Node<T>* temp = head;

        head = head->next;
        head->prev = nullptr;

        delete temp;
    }

    // Delete's Last Node of LinkedList
    void RemoveFromLast(void){
        if(IsEmpty()) return;// case no element's in linkedlist

        Node<T>* temp = tail;

        tail = tail->prev;
        tail->prev = nullptr;

        delete temp;
    }

    // Search in Linked List
    Node<T>* IsContainNode(const T& matchData , bool startFromTail = false) const{
        if(IsEmpty())return nullptr; // Null Case

        // finds element in linked List starts from head
        if(!startFromTail){
            Node<T>* itr = head;
            while(itr != nullptr){
                if(itr->data == matchData) return itr;
                itr = itr->next;
            }
            return nullptr; // On Not Found
        }
            // finds element from the linkedlist starts from tail
        else{
            Node<T>* itr = head;
            while(itr != nullptr){
                if(itr->data == matchData) return itr;
                itr = itr->prev;
            }
            return nullptr;// On Not Found
        }
    }

    /* Utilities Functions */

    // returns linkedlist is empty
    bool IsEmpty() const{ return head == nullptr && tail == nullptr;}

    // returns linked List is contains element N
    bool Contains(const T& Data) const {return IsContainNode(Data);}

    // IO operator OverLoad Recommended
    void Display(void){
        if(IsEmpty())return;

        Node<T>* itr =head;
        while(itr!= nullptr){
            cout<<" "<<itr->data<<" "<<endl;
            itr = itr->next;
        }

        cout<<endl;
    }

    Node<T>* getHead() const {
        return head;
    }

    Node<T>* getTail() const {
        return tail;
    }


private:
    Node<T> *head , *tail;

};



void run_test () {
    DLinkedList<int> list;

    // Test Push and Pop
    list.Push(1);
    list.Push(2);
    list.Push(3);
    assert(!list.IsEmpty());
    assert(list.getHead()->data == 3);
    list.Pop();
    assert(list.getHead()->data == 2);

    // Test Push Back and Remove From Last
    list.Push_Back(4);
    list.Push_Back(5);
    list.Push_Back(6);
    list.RemoveFromLast();
    assert(list.getTail()->data == 5);

    // Test Push After and Push Before
    Node<int>* node = list.getHead();
    list.Push_After(node, 7);
    list.Push_Before(node->next, 8);
    assert(list.getHead()->next->data == 8);
    assert(list.getHead()->next->next->data == 7);
    assert(list.getTail()->data == 5);

    // Test IsContainNode
    assert(list.Contains(7));
    assert(!list.Contains(9));

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    run_test();
    return 0;
}
