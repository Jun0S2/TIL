#include <iostream>

using namespace std;

int N,cnt;
int *quick;

void quickSort(int i, int j)
{
	if(i>=j) return;
	int pivot = quick[(i+j)/2];
	int start = i; //왼쪽
	int end = j;  //오른쪽
	
	while(start<=end)
	{
		while(quick[start]<pivot) start++;
		while(quick[end]>pivot) end--;
		if(start<=end)
		{
			swap(quick[start],quick[end]);
			start++; end--;
		}
	}
	quickSort(i,end);
	quickSort(start,j);
}

int main() 
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	
	cin>>N;
	quick = new int[N+1];
	for(int i = 0; i < N; i++) cin>>quick[i];

	quickSort(0,N-1);

	for(int i = 0; i < N; i++) cout<<quick[i]<<" ";
}
