// Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;

        // 기존 nums복사 근데 인덱스를 곁들인
        vector<pair<int, int>> sortNums;
        for (int i = 0; i < nums.size(); i++) {
            sortNums.push_back({nums[i], i});
        }
        
        sort(sortNums.begin(), sortNums.end());
        
        // 투포인터
        int left = 0, right = nums.size() - 1;

        while(true) {
            if (sortNums[left].first + sortNums[right].first == target) break;
            else if (sortNums[left].first + sortNums[right].first < target) left++;
            else if (sortNums[left].first + sortNums[right].first > target) right--;
        }

        answer.push_back(sortNums[left].second);
        answer.push_back(sortNums[right].second);

        return answer;
    }
};
