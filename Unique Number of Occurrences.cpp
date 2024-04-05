class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        //store frequency of each numbers
        for(int &x : arr) {
            mp[x]++;
        }
        
        unordered_set<int> st;
        
        for(auto &it : mp) {
            int freq = it.second; //it.first = number
            
            if(st.find(freq) != st.end())
                return false;
            st.insert(freq);
        }
        
        return true;
    }
};


//Approach-2 (Making benefit of constraints)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> vec(2001, 0);
        
        for(int &x : arr) {
            vec[x + 1000]++;
        }
        
        sort(begin(vec), end(vec));
        
        for(int i = 1; i<2001; i++) {
            if(vec[i] != 0 && vec[i] == vec[i-1])
                return false;
        }
        
        
        return true;
    }
};
