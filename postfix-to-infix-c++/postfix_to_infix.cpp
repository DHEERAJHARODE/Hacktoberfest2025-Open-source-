#include<bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

// Function to convert Postfix to Infix
string postfixToInfix(const string& postfix) {
    stack<string> st;

    for(char c:postfix) {
        // If operand, push it to stack
        if(isalnum(c)) {
            st.push(string(1,c));
        }
        // If operator, pop two operands and combine
        else if(isOperator(c)) {
            if(st.size()<2) {
                cerr << "Invalid postfix expression!" << endl;
                return "";
            }
            string op2=st.top();st.pop();
            string op1=st.top();st.pop();
            
            // Form the new infix expression
            string infix="(" +op1+" "+c+" "+op2+ ")";
            st.push(infix);
        }
    }

    // Final expression should be the only element in the stack
    if(st.size()!=1){
        cerr<<"Invalid postfix expression!"<<endl;
        return "";
    }

    return st.top();
}

int main() {
    string postfix;
    cout<<"Enter a postfix expression: ";
    cin>>postfix;

    string infix=postfixToInfix(postfix);
    if(!infix.empty()) {
        cout<<"Infix Expression: "<<infix<<endl;
    }

    return 0;
}
