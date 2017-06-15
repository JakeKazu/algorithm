#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define N 10
void sarch(int a[],int min,int max,int x,int count){
  count++;
  int n = (min + max)/2;
  if(a[n]==x){
    cout << count << "回" << endl;
    cout << n << endl;
  }
  else if(min==max){
    cout << "見つかりませんでした" << endl;
  }
  else if(a[n]<x)
    sarch(a,n+1,max,x,count);
  else if(a[n]>x)
    sarch(a,min,n,x,count);
}
int main(){
  int a[N];
  for(int i=0;i<N;i++) a[i] = rand()%10;
  sort(a,a+N);
  cout << "探す数字を入力してください（０〜９）:";
  int x;
  cin >> x;
  sarch(a,0,N,x,0);
  return 0;
}
