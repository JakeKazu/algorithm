#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;
int main(void){
  int n;
  cin >> n;
  srand((unsigned)time(NULL));
  cout << n << endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) cout << 0 << ' ';
      else cout << rand()%30+1 << ' ';
    }
    cout << endl;
  }
  return 0;
}
