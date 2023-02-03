#include<iostream>
using namespace std;
void merge(int arr[], int left, int m, int right)
{
	int i, s,m;
	int n1 = m - left + 1;
	int n2 = right - m;
	int* L = new int[n1], * R = new int[n2];
	for (i = 0; i < n1; i++) L[i] = arr[left + i];
	for (s = 0; s < n2; s++) R[s] = arr[m + 1 + s];
	i = s = 0; m = left;

	while (i < n1 && s < n2) {
		if (L[i] <= R[s]) {
			arr[m] = L[i];
			i++;
		}
		else {
			arr[m] = R[s];
			s++;
		}
		m++;
	}

	while (i < n1) {
		arr[m] = L[i]; i++;
		m++;
	}
	while (s < n2) {
		arr[m] = R[s]; s++;
		m++;

	}
}
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int m = left + (right - left) / 2;
		mergeSort(arr, left, m); mergeSort(arr, m + 1, right);

		merge(arr, left, m, right);
	}
}
void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}
int main() {
	int arr[] = { 8,200,1,50,10 }; int n = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, n - 1); print(arr, n);
	return 0;
}