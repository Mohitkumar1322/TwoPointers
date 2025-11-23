class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; // Result vector to store triplets
        vector<tuple<int,int,int>> pairs; // Unused variable, can be removed
        sort(nums.begin(),nums.end()); // Sort the input array
        int n = nums.size(); // Get the size of the input array
        for(int i=0;i<n-2;i++){ // Iterate through the array
            if(i>0 && nums[i]==nums[i-1]) continue; // Skip duplicate elements for the first number
            int target=-nums[i]; // Calculate the target sum
            int left=i+1,right=n-1; // Initialize left and right pointers
            while(left<right){ // Iterate while left pointer is less than right pointer
                int totalSum=nums[left]+nums[right]; // Calculate the sum of the two numbers
                if(totalSum==target){ // If the sum is equal to the target
                    ans.push_back({nums[i],nums[left],nums[right]}); // Add the triplet to the result
                    while(left<right && nums[left]==nums[left+1]) left++; // Skip duplicate elements for the second number
                    while(right>left && nums[right]==nums[right-1]) right--; // Skip duplicate elements for the third number
                    left++; // Move the left pointer
                    right--; // Move the right pointer
                    

                }
                else if(totalSum>target){ // If the sum is greater than the target
                    right--; // Move the right pointer
                }else{ // If the sum is less than the target
                    left++; // Move the left pointer
                }
            }
        }
        return ans; // Return the result
        
    }
};