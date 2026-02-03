class fastestPrime { 
    
    public int primes(int n){
        if(n == 0 || n == 1 || n==2)
            return 0;
        int count = 1;
        boolean arr[] = new boolean[n+1];
        int i = 3;
        for(i=3; i*i<n;i+=2){
            if(arr[i] == false){
                count ++;
                for(int j=i+i;j<n;j=j+i){
                    arr[j] = true;
                }
            }
        }
        if(i%2 == 0){
            for(int k = i+1;k<n;k+=2){
                if(arr[k] == false)
                    count++;
            }
        }
        else{
            for(int k = i;k<n;k+=2){
                if(arr[k] == false)
                    count++;
            }
        }
        return count;
    }
    
    public int countPrimes(int n) {
        int count = primes(n);
        return count;
    }
}