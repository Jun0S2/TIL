#include<iostream>

using namespace std;

int N,arr[1000001];
int *arr2; //사이즈 모르는 배열 이런식으로 선언 가능..ㅇ0ㅇ...

void merge(int start, int end)
{
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;
	
	while (i <= mid && j <= end)
	{
		if (arr[i] <= arr[j]) 
		{
		  arr2[k++] = arr[i++];
		}
		else
		{
		  arr2[k++] = arr[j++];
		}
	}

	int temp = i>mid ? j : i;
	
	while(k<=end) 
	{
	  arr2[k++] = arr[temp++];
	}
	
	for (int i=start;i<=end;i++) 
	{
	  arr[i] = arr2[i];
	}
}

void mergeSort(int start,int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2; 
		mergeSort(start, mid); //왼쪽 정렬
		mergeSort(mid + 1, end); //오른쪽 정렬
		merge(start, end); //합병
	}
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin>>N;
	arr2 = new int[N];
	for (int i=0;i<N;i++) cin>>arr[i];

	mergeSort(0, N - 1);

	for (int i=0;i<N;i++) cout<<arr[i]<<" ";
}
