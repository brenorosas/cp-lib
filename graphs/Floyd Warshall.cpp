int adj[n][n];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==j) adj[i][j]=0;
        else adj[i][j]=INF;
    }
}
for(int i=0;i<m;i++){
    int a,b, c;
    cin>>a>>b>>c;
    a--;
    b--;
    adj[a][b] = min(adj[a][b],c);
    adj[b][a] = min(adj[b][a],c);
}
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
        }
    }
}