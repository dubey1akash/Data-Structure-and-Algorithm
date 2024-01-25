//approach

//transpose nikalna which is mirror image opposite of diagnal
//reverse is simple for a row that jo row lena h begin sey end krna h bs

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m;

        //tranpose nikalo bro 
        for(int i = 0; i<m; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse rows of matrix nikalo 
        for(int i=0; i<m; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};