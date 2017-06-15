#include<iostream>
using namespace std;
#define N 10
//キューQの初期化の手続き
void InitQ(int *t);
//キューの大きさを返す関数
int sizeOf(int t);
//キューに新しい要素を追加する関数
int push(int q[],int x,int *t);
//キューの先頭の要素を取り出す関数
int pop(int q[],int *t);


int main(){
  int t;
  int q[N]={0};
  InitQ(&t);
  int in;
  do{
    cout << "0・・・push(x),1・・・pop()" << endl;
    cin >> in;
    if(in==0){
      cout << "追加する数字を入力してください:";
      int x = 0;
      cin >> x;
      if(push(q,x,&t)==0)
	break;
    }
    if(in==1){
      if(pop(q,&t)==0)
	break;
    }
  }while(in==0||in==1);
  return 0;
}

//キューQの初期化の手続き
void InitQ(int *t){
  *t = 0;
}
//キューの大きさを返す関数
int sizeOf(int t){
  return t;
}
//キューに新しい要素を追加する関数
int push(int q[],int x,int *t){
  if(sizeOf(*t)==N-1){
    cout << "オーバーフロー" << endl;
    return 0;
  }
  else{
    q[*t]=x;
    *t += 1;
  }
  return 1;
}
//キューの先頭の要素を取り出す関数
int pop(int q[],int *t){
  if(sizeOf(*t)==0){
    cout << "空" << endl;
    return 0;
  }
  else{
    *t -= 1;
    cout << q[*t] << endl;
  }
  return 1;
}
