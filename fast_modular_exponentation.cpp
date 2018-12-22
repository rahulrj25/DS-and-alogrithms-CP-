long long M = 1000000007;
long long power(long long x, long long y){
    long long res = 1;   
    x = x % M; 
    while (y > 0){     
        if (y & 1)res = (res*x) % M;
        y = y/2;
        x = (x*x) % M;  
    }
    return res;
}
