//Sorting queries
int block = 400;
bool cmp(query x, query y){
    if (x.l/block != y.l/block)
        return x.l/block < y.l/block;
    return x.r < y.r;
}

// Traversing queries
int currL = 0, currR = 0; 
    int currSum = 0; 

for (int i=0; i<m; i++) { 
    
    int L = q[i].L, R = q[i].R; 
    while (currL < L) 
    { 
        currSum -= a[currL]; 
        currL++; 
    } 

    while (currL > L) 
    { 
        currSum += a[currL-1]; 
        currL--; 
    } 

    while (currR <= R) 
    { 
        currSum += a[currR]; 
        currR++; 
    }

    while (currR > R+1) 
    { 
        currSum -= a[currR-1]; 
        currR--; 
    } 

}