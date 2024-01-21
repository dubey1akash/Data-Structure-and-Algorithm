//problem link  https://leetcode.com/problems/valid-parentheses/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty())return false;
                if(s[i]=='(' && st.top() !=')')return false;
                if(s[i]==']' && st.top() !='[')return false;
                if(s[i]=='{' && st.top() !='}') return false;
                st.pop();

            }
        }
        return st.empty();
    }
};




int main(){
   Solution obj;
   string s = "()[]{}";
   bool res=obj.isValid(s);
   cout<<res;
   return 0;
}