#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<unordered_map>
#include<time.h>
#include<algorithm>
using namespace std;

//https://www.cnblogs.com/ayqy/p/4052646.html 堆排序
void Swap(vector<int>&a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition(vector<int>& nums, int left, int right) {//快速排序的分块
	if (left > right) return -1;
	int key = nums[left];
	int i = left;
	int j = right + 1;
	while (true) {
		while (nums[++i] <= key)
			if (i == right)
				break;
		while (nums[--j] >= key)
			if (j == left)
				break;
		if (i >= j) break;
		Swap(nums, i, j);
	}
	Swap(nums, j, left);
	return j;
}

void quicksort(vector<int>& nums, int left, int right) {//快速排序
	if (left > right) return;
	srand(unsigned(time(NULL)));
	int randomIndex = rand() % (right - left + 1) + left;
	Swap(nums, left, randomIndex);
	int pivot = partition(nums, left, right);
	quicksort(nums, left, pivot - 1);
	quicksort(nums, pivot + 1, right);
}

void bubbleSort(vector<int>& nums) {//冒泡排序，先排序后方
	int len = nums.size();
	bool flag = false;
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		flag = false;
		for (int j = 0; j < len - 1 - i; ++j) {
			if (nums[j] > nums[j + 1]) {
				Swap(nums, j, j + 1);
				flag = true;
			}
		}
		if (flag == false)
			break;
	}
}

void bubbleSort1(vector<int>& a) {//冒泡排序，先排序前方
	int length = a.size();
	bool flag;//没有发生过交换
	for (int i = 0; i < length - 1; i++)
	{
		flag = false;
		for (int j = length - 2; j >= i; --j)//注意这里的j值
		{
			if (a[j] > a[j + 1])
			{
				Swap(a, j, j + 1);
				flag = true;
			}
		}
		if (flag == false)
			break;//交换完毕
	}
}
void shellSort(vector<int>& nums) {//希尔排序-插入排序的变化形式
	int len = nums.size();
	int i, j, key;
	for (int inc = len / 2; inc > 0; inc /= 2) {//注意这里是inc > 0  inc表示增量increment
		for (i = inc; i < len; ++i) {
			key = nums[i];
			for (j = i - inc; j >= 0 && nums[j] > key; j -= inc) {//所有与j相关的加减的另一元操作数都是inc
				nums[j + inc] = nums[j];
			}
			nums[j + inc] = key;
		}
	}
}
void insertSort(vector<int>& nums) {//插入排序
	int len = nums.size();
	int i, j, key;
	for (i = 1; i < len; ++i) {
		key = nums[i];
		for (j = i - 1; j >= 0 && nums[j] > key; --j) {
			nums[j + 1] = nums[j];
		}
		nums[j + 1] = key;
	}
}

void mergeOne(vector<int>& nums, int start, int mid, int end) {//归并排序的合并
	if (start >= end) {
		return;
	}
	int k(0), i(start), j(mid + 1);
	int* tmp = new int[end - start + 1];
	while (i <= mid && j <= end) {
		if (nums[i] <= nums[j])
			tmp[k++] = nums[i++];
		else
			tmp[k++] = nums[j++];
	}
	while (i <= mid)
		tmp[k++] = nums[i++];
	while (j <= end)
		tmp[k++] = nums[j++];
	for (int i = 0; i < k; ++i) {
		nums[start + i] = tmp[i];
	}
}
void mergeSort(vector<int>& nums, int start, int end) {//归并排序
	if (start >= end) {
		return;
	}
	int mid = (end + start) >> 1;
	mergeSort(nums, start, mid);
	mergeSort(nums, mid + 1, end);
	mergeOne(nums, start, mid, end);
}

void selectSort(vector<int>& nums) {
	int len = nums.size();
	for(int i = 0; i < len - 1; ++ i)
		for (int j = i + 1; j < len; ++j) {
			if (nums[i] > nums[j])
				Swap(nums, i, j);
		}
}
int main() {
	vector<int> nums{ 1,6,5,4,3,2,10,15,2 };
	//bubbleSort(nums);
	//quicksort(nums, 0, nums.size() - 1);
	//shellSort(nums);
	//insertSort(nums);
	//mergeSort(nums, 0, nums.size() - 1);
	selectSort(nums);
	for (auto& i : nums) {
		cout << i << endl;
	}
}
