#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;
int main(){
  queue<int> qu;
  while(1){
    qu.push(10);
    qu.push(100);
    if(rand()%2==0) qu.push(1);
    cout << qu.back() << endl;
  }
  return 0;
}
