//Maintain count of numbers between 0 and 99
// Bucket can be filled while taking input itself
long long buc[325][100];    // 325 Buckets each of size 100
long long SQ=320;           // Bucket size
long long str[325];         // Values valid for entire bucket
long long arr[100001];
long long ans[100];         // Stores final answer from query

void update(int l,int r, int val){

    int bl=l/SQ,br=r/SQ;

    if(bl==br){
        for(int i=l;i<=r;i++){
            if(arr[i]+str[bl]<100){
                buc[bl][arr[i]+str[bl]]--;
                arr[i]+=val;
                if(arr[i]+str[bl]<100) buc[bl][arr[i]+str[bl]]++;
            }
        }
    }
    else{
        
        for(int i = l; i < min((bl + 1) * SQ, n); ++i){
            if(arr[i]+str[bl]<40){
                buc[bl][arr[i]+str[bl]]--;
                arr[i]+=val;
                if(arr[i]+str[bl]<100) buc[bl][arr[i]+str[bl]]++;
            }
        }

        for(int i = bl + 1; i < br; ++i){ 
            str[i] += val;
            for(int j=99; j>=0; j--){
                if(j-val >= 0) buc[i][j]=buc[i][j-val]; 
                else buc[i][j]=0;
            }
        }

        for(int i = br * SQ; i <= r; ++i){
            if(arr[i]+str[br]<100){
                buc[br][arr[i]+str[br]]--;
                arr[i]+=val;
                buc[br][arr[i]+str[br]]++;
            }
        }
    }
}

void query(int l,int r){
    
    int bl=l/SQ,br=r/SQ;
   
    if(bl==br){
      
        for(int i=l;i<=r;i++){
            if((arr[i]+str[bl])<100)ans[arr[i]+str[bl]]++;
        }

    }
    else{
       
        for(int i = l; i < min((bl + 1) * SQ, n); i++){

            if((arr[i]+str[bl])<40)ans[arr[i]+str[bl]]++;
        }

        for(int i = bl + 1; i < br; i++){
            for(int j=0;j<100;j++)ans[j]+=buc[i][j];
        }

        for(int i = br * SQ; i <= r; i++){
            if((arr[i]+str[br])<100)ans[arr[i]+str[br]]++;
        }
    }
 
}