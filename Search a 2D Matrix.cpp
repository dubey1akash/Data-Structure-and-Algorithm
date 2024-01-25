// approach 


//how to do simple things like you want to check from the end of column and then go left of column from
//right or going next row depending of target 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0] .size();

        int i=0 , j = n-1;

        while(i<m && j>=0){
            if(matrix[i][j] > target ){
                j--;
            }
            else if(matrix[i][j] < target){
                i++;
            }else{
                return true;
            }
        }
        return false;
    }
};


///using binary search now 

//how to convert 2d array as 1d using taking strt as 0 and end m*n
//then taking modulo using column and dividing with mid will give you 2d array points

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int strt = 0; 
        int end = m*n-1;

        while(strt < end ){
            int mid = strt+(end-strt)/2;

            if(matrix[mid/n][mid%n] > target){
                end = mid-1;
            }else if(matrix[mid/n][mid%n] < target){
                strt = mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};