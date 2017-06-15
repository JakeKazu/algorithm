#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define N 11
void push(int heap[],int *n,int x){
  heap[*n] = x;
  int top = *n;
  while(top/2>0&&heap[top]<heap[top/2]){
    int temp = heap[top];
    heap[top] = heap[top/2];
    heap[top/2] = temp;
    top /= 2;
  }
  *n=*n+1;
}
int pop(int heap[],int *n){
  int top = 1;
  int ans = heap[top];
  *n=*n-1;
  heap[top] = heap[*n];
  int index = (heap[top*2]<heap[top*2+1])?top*2:top*2+1;
  if(index==*n) index = top*2;
  while(index<*n&&heap[top]>heap[index]){
    int temp = heap[top];
    heap[top] = heap[index];
    heap[index] = temp;
    top = index;
    index = (heap[top*2]<heap[top*2+1])?top*2:top*2+1;
    if(index==*n) index = top*2;
  }
  return ans;
}
int main(){
  int heap[N]={0};
  int n = 1;
  srand((unsigned)time(NULL));
  for(int i=0;i<N-1;i++) push(heap,&n,rand()%100);
  for(int i=0;i<N-1;i++)
    cout << pop(heap,&n) << endl;
  return 0;
}
