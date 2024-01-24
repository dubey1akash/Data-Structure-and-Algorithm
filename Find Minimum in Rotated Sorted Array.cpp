//approach 

// well for this one you really need to be smart when you take the value of minimum 
//to be minimum or when you don't so this case should clear when mid is greater that right one
//so clearly that would not be minimum so move l = mid +1 and but if that is not that case then
//it could be minimum so right should be take from that point

class Solution {
public:
    int findPivot(vector<int>& nums) {
        int mid;
        int l = 0, r = nums.size()-1;
        while(l < r) {
            mid = l + (r-l)/2;
          
            if(nums[mid] > nums[r]) { //something wrong on right side. Possibly my answer lies in right side.
                l = mid+1;            //move right (Discarding mid, because it's greater than nums[r], so it can't be the minimum element)
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
    
    int findMin(vector<int>& nums) {
        return findPivot(nums);
    }
};