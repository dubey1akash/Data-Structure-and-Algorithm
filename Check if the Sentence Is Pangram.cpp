class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>comp(26,0);
        for(auto &ch: sentence){
            comp[ch-'a']++;
        }

        for(int i =0; i<comp.size(); i++){
            if(comp[i] == 0){
                return false;
            }
        }
        return true;
    }
};