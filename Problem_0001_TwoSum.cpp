#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twosum(std::vector<int> nums, int target){
	// key 某个之前的数   value 这个数出现的位置
	std::unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i) {
        if (m.count(target - nums[i])) {
            return {i, m[target - nums[i]]};
        }
        m[nums[i]] = i;
    }
    return {};
}
int main(){
	// std::vector<int> nums{2,7,11,15};
	std::vector<int> nums{3, 2, 4};
	int target = 6;
	std::vector<int> res = twosum(nums, target);
	for(auto ans : res){
		std::cout << ans << std::endl;
	}
	
}
