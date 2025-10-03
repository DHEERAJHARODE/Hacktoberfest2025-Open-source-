#include <iostream>
using namespace std;
#include <conio.h>
int main()
{
    int m, n, p, q;
    cout << "Matrix addition and subtraction" << endl;
    cout << "Enter the order of first matrix";
    cin >> m >> n;
    int A[m][n];//creation of forst matrix

    cout << "Enter order of second matrix";
    cin >> p >> q;
    int B[p][q];//creation of second matrix
    if ((m != p) || (n != q)){
        cout << "Matrix operation not possible";
    }
    else{
        // Read elements of first matrix
        cout << "Enter the elements of first matrix:" << endl;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                cin >> A[i][j];
            }
        }
        // Read elements of second matrix
        cout << "Enter the elements of second matrix:" << endl;
        for (int i = 0; i < p; i++){
            for (int j = 0; j < q; j++){
                cin >> B[i][j];
            }
        }
        int S[m][n],D[m][n];//creation of sum(S) and difference(D) matrices
        /*Store sum in matrix C and store difference in matrix D*/
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                S[i][j] = A[i][j] + B[i][j];
                D[i][j] = A[i][j] - B[i][j];
            }

        //displaying addition
        cout<<"result of addition is"<<endl;
        for (int i = 0; i < m; i++)
        {
            cout << endl;

            for (int j = 0; j < n; j++)
            {
                cout << S[i][j] << " ";
            }
        }
        cout<<"\nresult of subtraction is"<<endl;
        //displaying subtraction
        for (int i = 0; i < m; i++)
        {
            cout << endl;

            for (int j = 0; j < n; j++)
            {
                cout << D[i][j] << " ";
            }
        }
    }
}
