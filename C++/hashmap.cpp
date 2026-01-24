#include <iostream.h>
#include <unordered_map>;
#include <string>;

using namespace std;

int main()
{
    unordered_map<char, int> charCount;
    string input;

    // Input a string
    cout << "Enter a string: ";
    cin >> input;

    // Count the frequency of each character
    for (char c : input)
    {
        charCount[c]++;
    }

    // Output the character frequencies
    cout << "Character frequencies:" << endl;
    for (const auto &entry : charCount)
    {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}