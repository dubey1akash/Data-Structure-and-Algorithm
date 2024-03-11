class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int>um;;

        for(auto &v: words){
            um[v]++;
        }


        vector<pair<string,int>> vec;

        for(auto &it: um){
            vec.push_back({it.first, it.second});
        }

        auto lambda = [](pair<string, int>&p1 , pair<string, int>p2){
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }

            return p1.second > p2.second;
        };

        sort(vec.begin(), vec.end(), lambda);
        
        int i = 0;
        vector<string>result(k);

        while(i<k){
            result[i] = vec[i].first;
            i++;
        }

        return result;
    }
};