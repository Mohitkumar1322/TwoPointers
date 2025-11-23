class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); // Sort the input array
        int n=nums.size(); // Get the size of the array
        int min=INT_MAX; // Initialize min to maximum integer value
        for(int i=0;i<n-2;i++){ // Iterate through the array
            if(i>0 and nums[i]==nums[i-1]) continue; // Skip duplicate elements
            int left =i+1,right=n-1; // Initialize left and right pointers
            //if(sum ==target) return sum;
            while(left<right){ // Iterate while left < right
                int sum = nums[i]+nums[left]+nums[right]; // Calculate the sum of three numbers
                if(sum ==target) return sum; // If sum is equal to target, return sum
                if(abs(sum-target)<abs(min-target)){ // If the difference between sum and target is less than the difference between min and target
                    min=sum; // Update min
                }
                if(sum<target){ // If sum is less than target
                    left++; // Increment left
                }else{
                    right--; // Decrement right
                }
            }

        }
        return min; // Return the closest sum
    }
};