// XOR After Range Multiplication Queries I

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int idx;
        for(int i = 0; i < queries.size(); i++) {
            idx = queries[i][0];
            
            while(idx < nums.size() && idx <= queries[i][1]) {
                long long temp = nums[idx];
                nums[idx] = temp * queries[i][3] % (1000000000 + 7);
                idx += queries[i][2];
            }
        }

        int answer = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            answer ^= nums[i];
        }

        return answer;
    }
};
