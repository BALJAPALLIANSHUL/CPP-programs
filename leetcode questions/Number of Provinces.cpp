void DFS(vector<vector<int>> k,int i,vector<bool>& visited){
        visited[i] = true;
        int n = k.size();
        for(int j = 0;j<n;j++){
            if(k[i][j] == 1 && !visited[j]){
                DFS(k,j,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int count = 0;
        for(int i =0;i<n;i++){
            if(!visited[i]){
                DFS(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }