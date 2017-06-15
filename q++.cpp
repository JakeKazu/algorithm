#include<iostream>
#include<queue>
using namespace std;
int main(){
  queue<int> qu;
  qu.push(10);
  qu.push(100);
  cout << qu.pop() << endl;
  cout << qu.pop() << endl;
  cout << qu.pop() << endl;
}
