long long V,E;
struct Edge{
    int src, dest;
	long long w;
}edge[1000000];

bool cmp(Edge a,Edge b){
    return a.w<b.w;
}


long long kruskal( )
{
    vector<int> g[V];
    long long cmp[V];
	
    for(int i=0;i<V;i++){
		g[i].pb(i);
		cmp[i]=i;
	}

    long long ans=0,count=0;
    for(int i = 0; i < E && count!=V-1; i++)
    {
        int x=edge[i].src;
        int y=edge[i].dest;
        if (cmp[x] == cmp[y])
            continue;

        ans+=edge[i].w;
        count++;
        
		if(g[cmp[x]].size()<g[cmp[y]].size()){
            for(int z:g[cmp[x]]){
                g[cmp[y]].pb(z);
                cmp[z]=cmp[y];
            }
        }
        else{
            for(int z:g[cmp[y]]){
                g[cmp[x]].pb(z);
                cmp[z]=cmp[x];
            }
        }
    }
    return ans;
}