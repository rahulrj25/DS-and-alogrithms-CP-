int n;
long long mat[1000][1000];
long long dist[1000][1000];

void floydWarshall (){

    for(int i = 0; i < n; i++){
        for(int j = 0;j < n; j++)dist[i][j]=mat[i][j];
    } 

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    }
}