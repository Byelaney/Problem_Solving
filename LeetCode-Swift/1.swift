// dict[num] = index
func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
    var dict = [Int: Int]()

    for (index, num) in nums.enumerated() {
        if let v = dict[target - num] {
            return [v, index]
        }

        dict[num] = index
    }

    return []
}
