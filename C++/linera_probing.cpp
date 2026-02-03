#include <iostream>
using namespace std;
int hashfunction(int key)
{
    return key % 101;
}
int main()
{
    int a[] = {26, 28, 31, 34};
    int h[101];
    int r[] = {2, 5, 8};
    for (int i = 0; i < 101; i++)
        h[i] = -999;
    for (int i = 0; i < 4; i++)
    {
        if (h[hashfunction(a[i])] != -999)
        {
            int j = 0;
            while (j < 3 && h[hashfunction(a[i] + r[j])] != -999)
            {
                j++;
            }
            if (h[hashfunction(a[i] + j)] == -999)
                h[hashfunction(a[i] + j)] = a[i];
        }
        else
            h[hashfunction(a[i])] = a[i];
    }
    for (int i = 0; i < 101; i++)
        cout << h[i] << " ";
}
