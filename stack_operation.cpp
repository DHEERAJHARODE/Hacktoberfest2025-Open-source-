// Stack operation using menu driven program
// Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added at one end (top) and an element is removed from that end only.  Stack uses an encapsulated object of either vector or deque (by default) or list (sequential container class) as its underlying container, providing a specific set of member functions to access its elements.
#include <iostream>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
#define N 100
int stack[N];
class corestack
{
private:
    int top = -1; //initialization of top .Time complexity-O(1) 

public:
    void push(int item) // push function is used to insert an element into the stack.Time complexity-O(1) 
    {
        if (top == N - 1)
        {
            cout << "Overflow";
        }
        else
        {
            top++;
            stack[top] = item;
        }
    }

    void pop() // pop function is used to remove the topmost element from stack.Time complexity-O(1) 
    {

        if (top == -1)
        {
            cout << "underflow";
        }
        else
        {
            top--;
        }
    }

    void display() // this function is used to display the elements of stack.Time complexity-O(n) 
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
    }

    void peek() // peek function is used to view the top element.Time complexity-O(1) 
    {
        int v;
        if (top >= 0)
        {
            v = stack[top];
            cout << v;
        }
        else
        {
            cout << "no value has been entered!";
        }
    }
};

int main()
{
    corestack q;
    int n;
    int item;
    cout<<"Operation on stack :"<<endl; //menu driven program.
    cout<<"--------------------"<<endl;
    cout << "0 for EXIT"
         <<" "
         << "1.push"
         << " "
         << "2.pop"
         << " "
         << "3.peek"
         << " "
         << "4.display" << endl;
    while(1)
    {
        cout << "enter your choice = ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "enter the element to be stored:";
            cin >> item;
            q.push(item);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        default :
          exit(404);
        }
    } 
    return 0;
}