/*
 * main.cpp
 *
 *  Created on: Sep 2, 2023
 *      Author: LEGION
 */

#include <iostream>
#include <vector>

using namespace std;

long long mergeAndSplitInv(int start, int end, int mid, vector<int> & arr){
	int i = start, j = mid + 1;
	long long count = 0;
	vector<int> result;
	while (i <= mid && j <= end){
		if (arr[i] <= arr[j]){
			result.push_back(arr[i]);
			i++;
		}
		else {
			result.push_back(arr[j]);
			j++;
			count += mid - i + 1;
		}
	}

	for (;j <= end; j++)
		result.push_back(arr[j]);
	for (;i <= mid; i++)
		result.push_back(arr[i]);

	for (int t1 = 0, t2 = start; t2 <= end; t1++, t2++)
		arr[t2] = result[t1];

	return count;
}

long long sortAndCountInv(int start, int end, vector<int> & arr){
	if (end - start == 0) return 0;

	int mid = (end + start) / 2;
	long long x = sortAndCountInv(start, mid, arr);
	long long y = sortAndCountInv(mid + 1, end, arr);
	long long z = mergeAndSplitInv(start, end, mid, arr);

	return x + y + z;
}

void printVector(vector<int> v){
	for (int x : v)
		cout << x << ' ';
	cout << endl;
}

int main(){
	vector<int> test1;
	for (int i = 0; i < 100000; i++){
		int tmp;
		cin >> tmp;
		test1.push_back(tmp);
	}
	cout << sortAndCountInv(0, test1.size() - 1, test1) << endl;
}
