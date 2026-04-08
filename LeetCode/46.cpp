// Permutations

class Solution {
public:
    vector<int> used;
    vector<int> path;
    vector<vector<int>> answer;

    void per(int depth, vector<int>& nums) {
        if (depth == nums.size()) {
            answer.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = 1;
                per(depth + 1, nums);

                path.pop_back();
                used[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), 0);
        per(0, nums);
        return answer;
    }
};
