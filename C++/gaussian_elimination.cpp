//Gaussian Elimination mod 2

int gauss(vector<bitset<MAXN>> a, int m) {
    int n = (int) a.size();
    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        for (int i = row; i < n; ++i){
            if(a[i][col]) {
                swap(a[i], a[row]);
                break;
            }
        }

        if(!a[row][col]) continue;
        where[col] = row;

        for(int i = 0; i < n; ++i){
            if(i != row && a[i][col])
                a[i] ^= a[row];
        }
        ++row;
    }
    
    bitset<MAXN> ans;
    for (int i = 0; i < m; ++i){
        if(where[i] != -1) ans[i] = a[where[i]][m];
    }
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j)
            sum ^= ans[j] & a[i][j];
        if(sum != a[i][m]) return 0;    //has no solution
    }   
    for(int i = 0; i < m; ++i){
        if(where[i] == -1) return 2;    //has infinity solutions
    }
    return 1;   //has one solution
}
