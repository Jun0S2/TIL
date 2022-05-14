#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> heapSort(vector<int> vec){
    make_heap(vec.begin(), vec.end());
    for(auto end =  vec.end() ; end != vec.begin() ; end--)
    {
        pop_heap(vec.begin(), end);
    }
    return vec;
}

int main(){
    int N;
    cin>>N;
    
    
    vector<int> vec(N);
    for(int i  = 0 ; i<N ; i++) cin>>vec[i];
    
    vector<int> sorted = heapSort(vec);
    for(int i = 0 ; i<N ; i++)printf("%d\n",sorted[i]);
    
    return 0;
}
