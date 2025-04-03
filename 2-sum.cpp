class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seennumbers;
        int size = nums.size();

        for(int i=0;i<size;i++){
            int needednumber = target - nums[i];

            if(seennumbers.find(needednumber)!=seennumbers.end())
            return {seennumbers[needednumber],i};

            seennumbers[nums[i]] = i;
        }

        return {};
    }
};
