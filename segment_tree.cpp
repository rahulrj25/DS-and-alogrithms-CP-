int tr[4*100001];

void build(int node, int start, int end)
{
    if(start == end)
    {
        tr[node]=arr[start];   
    }
    else
    {
        int mid = (start + end) / 2;
        
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        
        tr[node] = tr[2*node+1] + tr[2*node+2];
        
    }
}

void update(int node, int start, int end, int ind)
{
    if(start == end)
    {
        tr[node]=arr[start];   
    }
    else
    {
        int mid = (start + end) / 2;
        
        if(start<=ind && ind<=mid) update(2*node+1, start, mid, ind);
        else update(2*node+2, mid+1, end);
        
        tr[node] = tr[2*node+1] + tr[2*node+2];

    }
}

void query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return 0;
    }
    if(l <= start and end <= r)
    {
        return tr[node];
    }
    
    int mid = (start + end) / 2;
    return query(2*node+1, start, mid, l, r) + query(2*node+2, mid+1, end, l, r);
    
}
