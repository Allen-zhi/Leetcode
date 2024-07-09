use std::collections::HashMap;

fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut map = HashMap::new();
    for (i, &num) in nums.iter().enumerate() {
        let complement = target - num;
        if let Some(&j) = map.get(&complement) {
            return vec![j as i32, i as i32];
        }
        map.insert(num, i);
    }
    vec![]
}

fn main() {
    let nums1 = vec![2, 7, 11, 15];
    let target1 = 9;
    let result1 = two_sum(nums1, target1);
    println!("Result for example 1: {:?}", result1);

    let nums2 = vec![3, 2, 4];
    let target2 = 6;
    let result2 = two_sum(nums2, target2);
    println!("Result for example 2: {:?}", result2);

    let nums3 = vec![3, 3];
    let target3 = 6;
    let result3 = two_sum(nums3, target3);
    println!("Result for example 3: {:?}", result3);
}
