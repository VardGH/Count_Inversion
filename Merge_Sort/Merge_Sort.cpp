#include <iostream>
#include <vector>
#include <ctime>

int count = 0;

 void Merge(std::vector<int>& vec,int left,int right)
{
	int mid = (left + right) / 2;
	int i=left;
	int j = mid + 1;
	int k = 0;
	
	std::vector<int> arr(right - left + 1);

	while (i <= mid && j <= right) {
		//arr[k++] = (vec[i] <= vec[j]) ? vec[i++] : vec[j++];
		if (vec[i] > vec[j]) {
			arr[k++] = vec[j++];
			count += mid - i + 1;
		}
		else {
			arr[k++] = vec[i++];
		}
	}

	while (i <= mid) {
		arr[k++] = vec[i++];
	}

	while (j<=right){
		arr[k++] = vec[j++];
	}
	
	for (int ch = left; ch <= right; ++ch) {
		vec[ch] = arr[right - (left - 1 + k)];
		k--;
	}
}

void Merge_sort(std::vector<int>& vec, int left, int right)
{
	int count = 0;
	if (left >= right) return;

	int mid=(left + right) / 2;

	Merge_sort(vec, left, mid);
	Merge_sort(vec, mid+1, right);
	Merge(vec, left, right);

}

void Print(std::vector<int>& vec)
{
	for (auto& elem : vec) {
		std::cout << elem << " ";
	}
	std::cout << "\n";
}

int main()
{
	std::vector<int> myvector{7,8,1,9,4,3};

	/*srand(time(NULL));
	for (auto& elem : myvector) {
		elem = rand() % 45-15;
	}*/

	std::cout << "Unsorted vector: ";
	Print(myvector);

	Merge_sort(myvector, 0, myvector.size() - 1);

	std::cout << "Merge Sort: ";
	Print(myvector);

	std::cout<<"count="<<count;

	return 0;
}
