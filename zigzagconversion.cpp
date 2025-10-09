class Solution {
public:
    string convert(string s, int numRows) {

    if (numRows == 1 || numRows >= s.size())
        return s;

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;
        // change direction when you reach top or bottom
        if (curRow == 0 || curRow == numRows - 1)
            goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;
    }

    string result;
    for (string &row : rows)
        result += row;

    return result;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << convert(s, numRows) << endl; // Output: PAHNAPLSIIGYIR

    numRows = 4;
    cout << convert(s, numRows) << endl; // Output: PINALSIGYAHRPI

    return 0;

    }
};
