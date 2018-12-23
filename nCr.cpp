long long M=1000000007;
long long fac[100001];

long long power(long long x, long long y) 
{ 
    long long res = 1;
    x = x % M;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % M; 

        y = y>>1;
        x = (x*x) % M;   
    } 
    return res; 
} 
long long nCr(long long n,long long r){
    if(n<r || n<0 || r<0)return 0;
    long long num=fac[n];
    long long div = fac[r] * fac[n-r] % M;
    div = power(div,M-2);
    long long ret = num * div % M;
    return ret;
}

void f(){
    fac[0]=1;
    for(int i=1;i<=100000;i++){
        fac[i]=fac[i-1]*i%M;
    }
}