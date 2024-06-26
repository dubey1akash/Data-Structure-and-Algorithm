//Approach-1 (Basic stack approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int operate(int &a, int &b, const string &s) {
        if(s == "+")
            return a+b;
        
        if(s == "-")
            return a-b;
        
        if(s == "*")
            return (long)a*(long)b;
        
        if(s == "/")
            return a/b;
        
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = operate(a, b, s);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};


/*
    Using fancy Lambda on unordered_map
    For my fancy STL collection with easy exlanation with examples, see the link below -
    https://github.com/MAZHARMIK/Cpp-STL-Quick-Help/blob/main/README.md
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        
        unordered_map<string, function<int (int, int)> > mp = {
            {"+", [](int a, int b) {return a + b; } },
            {"-", [](int a, int b) {return a - b; } },
            {"*", [](int a, int b) {return (long)a * (long)b; } },
            {"/", [](int a, int b) {return a / b; } },
        };
        
        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = mp[s](a, b);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
