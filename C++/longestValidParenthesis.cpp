#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    int len = i - st.top();
                    maxlen = max(len, maxlen);
                }
            }
        }

        return maxlen;
    }
};

int main()
{
    string s = ")()())";
    Solution st;
    int len = st.longestValidParentheses(s);
    cout << "Longest valid parenthesis length is :- " << len << endl;
}