#include <iostream>
#include <vector>
#include <unordered_map>

// 两数之和函数
std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap; // 哈希表存储值和索引
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {}; // 理论上不会到达这里，因为题目保证有解
}

// 测试代码
int main() {
    std::vector<int> nums = {0, 4, 3, 0};
    int target = 0;
    std::vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]\n";
    } else {
        std::cout << "No solution found.\n";
    }

    return 0;
}

