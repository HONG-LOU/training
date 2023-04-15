/**
 *    author:  HONG-LOU
 *    created: 2022-09-28 21:41:26
**/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	//排序方法
	static void selectSort(vector<int>& nums);	//选择排序
	static void insertSort(vector<int>& nums);	//插入排序
	static void bubbleSort(vector<int>& nums);	//冒泡排序
	static void shellSort(vector<int>& nums);	//希尔排序
	static void mergeSort(vector<int>& nums);	//归并排序
	static void heapSort(vector<int>& nums);	//堆排序
	static void quickSort(vector<int>& nums);	//快速排序
	static void countingSort(vector<int>& nums);	//计数排序
	static void bucketSort(vector<int>& nums);	//桶排序
	static void radixSort(vector<int>& nums);	//基数排序
	//辅助方法
	static void merge(vector<int>& nums, int left, int mid, int right);
	static void mergeRecursion(vector<int>& nums, int left, int right);
	static void mergeIteration(vector<int>& nums);
	static void heapAdjust(vector<int>& nums, int parent, int len);
	static void quickRecursion(vector<int>& nums, int left, int right);
	
};
void Solution::selectSort(vector<int>& nums) {
	//选择排序
	int len = nums.size();
	for (int i = 0; i < len - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < len; ++j) {
			if (nums[j] < nums[minIndex])
				minIndex = j;
		}
		swap(nums[i], nums[minIndex]);
	}
}
void Solution::insertSort(vector<int>& nums) {
	//插入排序
	int len = nums.size();
	for (int i = 1; i < len; ++i) {
		int temp = nums[i], j = i - 1;
		while (j >= 0 && nums[j] > temp) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = temp;
	}
}
void Solution::bubbleSort(vector<int>& nums) {
	//冒泡排序
	int len = nums.size();
	for (int i = len - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
		}
	}
}

void Solution::shellSort(vector<int>& nums) {
	//希尔排序
	int len = nums.size();
	auto insert = [&len](vector<int>& nums, int interval, int i) {
		int temp = nums[i];
		int k = i - interval;
		while (k >= 0 && temp < nums[k]) {
			nums[k + interval] = nums[k];
			k -= interval;
		}
		nums[k + interval] = temp;
	};
	for(int interval = len / 2; interval > 0; interval /= 2){
		for (int i = interval; i < len; ++i) {
			//这里指的是从第2个interval到数组最后都要与前面的分组进行比较并执行插入。
			insert(nums, interval, i);
		}
	}
}

void Solution::mergeSort(vector<int>& nums) {
	//归并排序
	Solution::mergeRecursion(nums, 0, nums.size() - 1); //递归法
	//Solution::mergeIteration(nums); //递归法
}

void Solution::mergeIteration(vector<int>& nums) {
	//归并排序，迭代法
	int len = nums.size();
	for (int interval = 1; interval < len; interval <<= 1) {
		int left = 0;
		int mid = left + interval - 1;
		int right = mid + interval;
		while (right < len) {
			Solution::merge(nums, left, mid, right);
			left = right + 1;
			mid = left + interval - 1;
			right = mid + interval;
		}
		// 合并遗留的数组
		if (left < len && mid < len) {
			Solution::merge(nums, left, mid, len - 1);
		}
	}
}

void Solution::mergeRecursion(vector<int>& nums, int left, int right) {
	//归并排序，递归法
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	Solution::mergeRecursion(nums, left, mid);
	Solution::mergeRecursion(nums, mid+1, right);
	Solution::merge(nums, left, mid, right);
}

void Solution::merge(vector<int>& nums, int left, int mid, int right) {
	//归并排序融合
	if (left >= right)
		return;
	vector<int> helper;
	helper.assign(nums.begin() + mid + 1, nums.begin() + right + 1);
	int ln = mid - left + 1;
	int rn = right - mid;
	int k = right, i = mid, j = rn - 1;
	while (i >= left && j >= 0) {
		nums[k--] = nums[i] > helper[j] ? nums[i--] : helper[j--];
	}
	while (i >= left)
		nums[k--] = nums[i--];
	while (j >= 0)
		nums[k--] = helper[j--];
}

void Solution::heapSort(vector<int>& nums) {
	//堆排序
	//首先构造大根堆
	int len = nums.size();
	for (int i = len / 2 - 1; i >= 0; --i)
		Solution::heapAdjust(nums, i, len);
	for (int k = len - 1; k > 0; --k) {
		//构造好大根堆后，将大根堆顶与末尾节点swap，修正len，同时以新的堆顶开始进行新一轮的下沉操作
		swap(nums[0], nums[k]);
		Solution::heapAdjust(nums, 0, --len);
	}
}
void Solution::heapAdjust(vector<int>& nums, int parent, int len) {
	//堆调整，其目的是使得当前较小的父节点下沉到子节点，优先下沉到右子节点
	int leftChild = 2 * parent + 1;
	int rightChild = 2 * parent + 2;
	int largerOne = parent;
	if (leftChild < len && nums[largerOne] < nums[leftChild])
		largerOne = leftChild;
	if (rightChild < len && nums[largerOne] < nums[rightChild])
		largerOne = rightChild;
	if (largerOne != parent) {
		//此时发现父节点相比于子节点值更小，则进行下沉操作
		//即交换父子节点，同时对交换后节点进行递归
		swap(nums[parent], nums[largerOne]);
		Solution::heapAdjust(nums, largerOne, len);
	}
}

void Solution::quickSort(vector<int>& nums) {
	//快速排序
	quickRecursion(nums, 0, nums.size() - 1);
}

void Solution::quickRecursion(vector<int>& nums, int left, int right) {
	//快速排序递归形式
	if (left >= right)
		return;
	int pivot = nums[left];
	int i = left, j = right;
	while (i < j) {
		//先从右向左寻找一个小于pivot的值，将其赋值给i所在位置
		while (i < j && nums[j] >= pivot)
			j--;
		if (i < j)
			nums[i] = nums[j];
		//赋值后，j所在位置空闲出来了，那么再从左向右寻找一个大于pivot的值，将其赋值给j所在位置
		while (i < j && nums[i] <= pivot)
			i++;
		if (i < j)
			nums[j] = nums[i];
	}
	//在相遇时，将pivot放置在相遇位置
	nums[i] = pivot;
	quickRecursion(nums, left, i - 1);
	quickRecursion(nums, i + 1, right);
}

void Solution::countingSort(vector<int>& nums) {
	//计数排序
	auto minmax = minmax_element(nums.begin(), nums.end());
	int maxVal = *minmax.second;
	int minVal = *minmax.first;
	vector<int> coutingArr(maxVal - minVal + 1);
	for (auto& num : nums)
		++coutingArr[num - minVal];
	size_t i = 0, j = 0;
	while (i < nums.size()) {
		while (coutingArr[j] > 0) {
			nums[i++] = j + minVal;
			--coutingArr[j];
		}
		j++;
	}
}

void Solution::bucketSort(vector<int>& nums) {
	//桶排序
	auto minmax = minmax_element(nums.begin(), nums.end());
	int bucketNum = 10;
	if(*minmax.second - *minmax.first < 10)
		bucketNum = *minmax.second - *minmax.first + 1;
	int interval = (*minmax.second - *minmax.first + 1) / bucketNum;
	vector<vector<int>> buckets(bucketNum);
	for (auto& num : nums) {
		int bucket = (num - *minmax.first) / interval;
		bucket = bucket > bucketNum - 1 ? bucketNum - 1 : bucket;
		buckets[bucket].emplace_back(num);
	}
	vector<int> res;
	for (auto& bucket:buckets)
	{
		Solution::quickSort(bucket);
		res.insert(res.end(), bucket.begin(), bucket.end());
	}
	nums = res;
}

void Solution::radixSort(vector<int>& nums) {
	//基数排序
	auto minmax = minmax_element(nums.begin(), nums.end());
	int minNum = *minmax.first;
	for (auto& num : nums)
		num = num - minNum;
	int maxNum = *minmax.second;
	int digitNum = 1;
	while (maxNum) {
		digitNum *= 10;
		maxNum /= 10;
	}
	vector<int> temps = nums;
	for (int digit = 1; digit < digitNum; digit *= 10) {
		vector<vector<int>> buckets(10);
		for (auto& num : temps) {
			buckets[(num / digit) % 10].emplace_back(num);
		}
		temps.clear();
		for (auto& bucket : buckets)
			temps.insert(temps.end(), bucket.begin(), bucket.end());
	}
	for (auto& num : temps)
		num += minNum;
	nums = temps;
}

void sortPrint(vector<int> nums, function<void(vector<int>& )> sortMethod, string name) {
	auto start = chrono::steady_clock::now();
	sortMethod(nums);
	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout << "Sort method: " << name << "   ";
	string tmp;
	// for (auto& num : nums)
	// 	tmp += (to_string(num) + ' ');
	cout << tmp << "   ";
	cout << "Execution time: " << chrono::duration<double, milli>(diff).count() << "ms" << endl;
}

int main() {
  std::vector<int> input;
  for (int i = 2020; i >= 1; i--) {
    input.push_back(i);
  }
	sortPrint(input, Solution::selectSort, "selectSort");
	sortPrint(input, Solution::insertSort, "insertSort");
	sortPrint(input, Solution::bubbleSort, "bubbleSort");
	sortPrint(input, Solution::shellSort, "shellSort");
	sortPrint(input, Solution::mergeSort, "mergeSort");
	sortPrint(input, Solution::heapSort, "heapSort");
	sortPrint(input, Solution::quickSort, "quickSort");
	sortPrint(input, Solution::countingSort, "countingSort");
	sortPrint(input, Solution::bucketSort, "bucketSort");
	sortPrint(input, Solution::radixSort, "radixSort");
	return 0;
}


/* 1 - 2 - 3 - ... - n;
Sort method: selectSort      Execution time: 5.227ms
Sort method: insertSort      Execution time: 0.008ms
Sort method: bubbleSort      Execution time: 5.236ms
Sort method: shellSort      Execution time: 0.096ms
Sort method: mergeSort      Execution time: 0.412ms
Sort method: heapSort      Execution time: 0.333ms
Sort method: quickSort      Execution time: 3.843ms
Sort method: countingSort      Execution time: 0.046ms
Sort method: bucketSort      Execution time: 0.436ms
Sort method: radixSort      Execution time: 0.253ms
*/

/* n - (n - 1) - (n - 2) - ... - 1;
Sort method: selectSort      Execution time: 5.813ms
Sort method: insertSort      Execution time: 10.251ms
Sort method: bubbleSort      Execution time: 16.655ms
Sort method: shellSort      Execution time: 0.172ms
Sort method: mergeSort      Execution time: 0.424ms
Sort method: heapSort      Execution time: 0.361ms
Sort method: quickSort      Execution time: 3.842ms
Sort method: countingSort      Execution time: 0.047ms
Sort method: bucketSort      Execution time: 0.461ms
Sort method: radixSort      Execution time: 0.27ms
*/