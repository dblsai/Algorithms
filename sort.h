
class Sorting{
	public:
	std::vector<int> merge(std::vector<int> s1, std::vector<int> s2){
		int i = 0, j = 0;
		std::vector<int> merged;
		while(i<s1.size() && j<s2.size()){
			if(s1[i] < s2[j]){
				merged.push_back(s1[i]);
			//	std::cout<<"merged push_back s1 = "<<s1[i]<<std::endl;
				i++;
			}else{
				merged.push_back(s2[j]);
			//	std::cout<<"merged push_back s2 = "<<s2[j]<<std::endl;
				j++;
			}
		}
		while(i<s1.size()){
			merged.push_back(s1[i]);
			i++;
		}
		while(j<s2.size()){
			merged.push_back(s2[j]);
			j++;
		}
		return merged;
	}
	
	std::vector<int> mergesort(std::vector<int> nums, int start, int end){
		if(nums.size() <= 1) return nums;
		if(end == start) {
			std::vector<int> res(nums.begin()+start, nums.begin() + end + 1);
		//	 for(int i=0; i<res.size(); i++)
    	//		std::cout<<res[i]<<'.';
			return res;
		}
		int mid = start + (end - start)/2;
	//	std::cout<<"mid = "<<mid<<std::endl;
		std::vector<int> sorted1 = mergesort(nums, start, mid);
		std::vector<int> sorted2 = mergesort(nums, mid+1, end);
		return merge(sorted1, sorted2);
	}
	
	void partition(std::vector<int> nums, std::vector<int>& left, std::vector<int>& right, std::vector<int>& equal, int pivot){
		for(int i=0; i<nums.size(); i++){
			if(nums[i] < pivot)
				left.push_back(nums[i]);
			else if(nums[i] > pivot)
				right.push_back(nums[i]);
			else
				equal.push_back(nums[i]);
		}
	}
	std::vector<int> quicksort(std::vector<int> nums){
		if(nums.size() <= 1) return nums;
		
		int mid = nums.size()/2;
		std::vector<int> left, right, equal, sorted, sorted1, sorted2;
		partition(nums, left, right, equal, nums[mid]);
		
//		std::cout<<"partitioned left: "; print_vector(left);
//		std::cout<<"partitioned right: "; print_vector(right);
		
		if(left.size() > 0)
			sorted1 = quicksort(left);
		if(right.size() > 0)
			sorted2 = quicksort(right);
		
		sorted.insert(sorted.begin(), sorted1.begin(), sorted1.end());
		sorted.insert(sorted.begin() + sorted1.size(), equal.begin(), equal.end());
		sorted.insert(sorted.begin() + sorted1.size() + equal.size(), sorted2.begin(), sorted2.end());
//		std::cout<<"sorted: "; print_vector(sorted);
		return sorted;
	}
	
};
