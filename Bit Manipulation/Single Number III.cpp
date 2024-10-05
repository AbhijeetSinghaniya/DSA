class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long int allXor = 0;
        for(int num : nums) allXor ^= num;

        // Gives the set right-most bit of a number (here, allXor)
        int rightMostSetBit = (allXor & (allXor-1)) ^ allXor;
        // int rightMostSetBit = allXor & (-allXor);
        
        int x = 0, y = 0;
        for (int num : nums) {
            if (num & rightMostSetBit) {
                x ^= num;
            } else {
                y ^= num;
            }
        }
        return {x, y};
    }
};
