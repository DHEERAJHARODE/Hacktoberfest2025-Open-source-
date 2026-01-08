// Z ALGORITHM -----------------------------------------------------------------------------------------------

// This algorithm efficiently locates all instances of a specific pattern within a text in linear time.
// If the length of the text is “n” and the length of the pattern is “m,” then the total time taken is O(m + n),
// with a linear auxiliary space. It is worth noting that the time and auxiliary space of this algorithm is the
// same as the KMP algorithm, but this particular algorithm is simpler to comprehend. In this approach, we create
// a Z array as part of the process.

//-------------------------------------------------------------------------------------------------------------


#include<iostream>
using namespace std;

void getZarr(string str, int Z[]);

// prints all occurrences of pattern in text using Z algo
void search(string text, string pattern)
{
    // Create concatenated string "P$T"
    string concat = pattern + "$" + text;
    int l = concat.length();

    // Construct Z array
    int Z[l];
    getZarr(concat, Z);

    // now looping through Z array for matching condition
    for (int i = 0; i < l; ++i)
    {
        // if Z[i] (matched region) is equal to pattern
        // length we got the pattern
        if (Z[i] == pattern.length())
            cout << "Pattern found at index "
                << i - pattern.length() -1 << endl;
    }
}

// Fills Z array for given string str[]
void getZarr(string str, int Z[])
{
    int n = str.length();
    int L, R, k;

    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        // if i>R nothing matches so we will calculate.
        // Z[i] using naive way.
        if (i > R)
        {
            L = R = i;

            // R-L = 0 in starting, so it will start
            // checking from 0'th index.
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i-L;

            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            if (Z[k] < R-i+1)
                Z[i] = Z[k];

            else
            {
                // else start from R and check manually
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

int main()
{
    string text = "TIT FOR TAT";
    string pattern = "TAT";
    search(text, pattern);
    return 0;
}




// Time Complexity: O(m+n),
//  where m is length of pattern and n is length of text.

// Auxiliary Space: O(n)