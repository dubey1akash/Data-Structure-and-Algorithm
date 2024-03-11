class Solution {
public:
    bool checkBipartiteDFS(unordered_map<int, vector<int>>&adj, int curr, vector<int>& color, int currColor) {
        color[curr] = currColor; //color kardiya curr node ko
        
        //ab jaate hain adjacent nodes par
        for(int &v : adj[curr]) {
            
            if(color[v] == color[curr])
                return false;
            
            if(color[v] == -1) { //never colored (never visited)
                
                int colorOfV = 1 - currColor;
                
                if(checkBipartiteDFS(adj, v, color, colorOfV) == false)
                    return false;
            }
            
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        unordered_map<int, vector<int>>adj;
        vector<int> color(V, -1); 

        for(auto &v : graph){
            int a = v[0];
            int b = v[1];
            adj[a].push_back(b);
        }


        for(int i = 0; i<V; i++) {
	        if(color[i] == -1) {
	            if(checkBipartiteDFS(adj, i, color, 1) == false)
	                return false;
	        }
	    }
	    
	    return true;
    }
};