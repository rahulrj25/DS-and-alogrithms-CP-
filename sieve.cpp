int si[1000001];

void fun(){
    for(int i=2;i<=1000)+1;i++){
        if(si[i]==0){
            for(int j=i*i;j<=1000000;j+=i){
                if(si[j]==0)si[j]=i;
            }
        }
    }

    for(int i=1;i<=100000;i++){
        int temp=i;
        while(si[temp]!=0){
            factor[i].pb(si[temp]);
            temp=temp/si[temp];
        }
        factor[i].pb(temp);
    }
}