class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankSet(bank.begin(), bank.end());
        unordered_set<string> visited;

        queue<string>q;
        q.push(startGene);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();
                if(curr == endGene){
                    return level;
                }
                for(char ch : "ACGT"){
                    for(int i = 0; i<curr.length(); i++){
                        string neighbour = curr;
                        neighbour[i] = ch;
                        if(bankSet.find(neighbour) != bankSet.end() && visited.find(neighbour) == visited.end()){
                            q.push(neighbour);
                            visited.insert(neighbour);
                        }
                    }
                }
            
            }
            level++;
        }
        return -1;
      
    }
};