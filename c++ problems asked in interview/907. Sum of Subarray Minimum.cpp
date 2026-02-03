#define mod 1000000007
class Solution {
  public: int sumSubarrayMins(vector < int > & arr) {
    // find prev less ele of each
    // find next less ele of each
    int n = arr.size();
    stack < int > st;
    st.push(0);
    vector < int > prevL(n, -1);
    vector < int > nextL(n, -1);

    for (int i = 1; i < n; i++) {
      if (arr[i] > arr[st.top()]) {
        prevL[i] = st.top();
      } else {
        while (!st.empty() and arr[i] < arr[st.top()]) {
          st.pop();
        }
        if (st.empty()) prevL[i] = -1;
        else prevL[i] = st.top();
      }
      st.push(i);
    }
    while (!st.empty()) st.pop();
    st.push(n - 1);

    for (int i = n - 2; i >= 0; i--) {
      if (arr[i] > arr[st.top()]) {
        nextL[i] = st.top();
      } else {
        while (!st.empty() and arr[i] <= arr[st.top()]) {
          st.pop();
        }
        if (st.empty()) nextL[i] = -1;
        else nextL[i] = st.top();
      }
      st.push(i);
    }

    for (int i = 0; i < n; i++) cout << nextL[i] << " ";

    long long sum = 0;
    for (int i = 0; i < n; i++) {
      int a = nextL[i] - i;
      if (nextL[i] == -1) a = n - i;
      int b = i - prevL[i];
      if (prevL[i] == -1) b = i + 1;
      sum = (sum + (static_cast < long long > (arr[i]) * a * b) % mod) % mod;
    }
    return sum;

  }
};