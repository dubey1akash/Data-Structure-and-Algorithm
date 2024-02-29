//here opposite side you are taking best value or best steps to get best soln
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue >= target){
            return startValue-target;
        }
        if(target%2 == 0){
            return 1 + brokenCalc(startValue , target/2);
        }
        
        return 1+brokenCalc(startValue, target+1);
    }
};