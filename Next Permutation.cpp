//approach

// very interesting soln i can say basically to make number a sequence up
//u need to make element great just by rightmost one element and rest after that less 
//that is what here we are doing from right we are looking to find a element who is great than just close
//element and then we swap with the element which is just close to the element which is right side
//then reverse to make it minimum


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        //first find the blue gola 
        int gola_index = -1;
        for(int i = n-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                gola_index = i-1;
                break;
            }
        }

        int swap_index = gola_index;

        if(gola_index != -1){

        for(int j=n-1; j>=gola_index+1; j--){
            if(nums[j] >nums[gola_index]){
                swap_index = j;
                break;
            }
        }

        swap(nums[gola_index], nums[swap_index]);

        }

        reverse(nums.begin()+gola_index +1 , nums.end());
    }
};