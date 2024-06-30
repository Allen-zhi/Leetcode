from typing import List, Optional

def two_sum(nums: List[int], target: int) -> Optional[List[int]]:
    num_map = {}  # 哈希表存储值和索引
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_map:
            return [num_map[complement], i]
        num_map[num] = i
    return None  # 理论上不会到达这里，因为题目保证有解

# 测试代码
if __name__ == "__main__":
    nums = [0, 4, 3, 0]
    target = 0
    result = two_sum(nums, target)
    
    if result:
        print(f"Indices: {result}")
    else:
        print("No solution found.")

