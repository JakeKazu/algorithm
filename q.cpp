#include<iostream>
using namespace std;
#define N 10
//キューQの初期化の手続き
void InitQ(int *t,int *s);
//キューの大きさを返す関数
int sizeOf(int t,int s);
//キューに新しい要素を追加する関数
int push(int q[],int x,int *t,int *s);
//キューの先頭の要素を取り出す関数
int pop(int q[],int *t,int *s);


int main(){
  int s,t;
  int q[N]={0};
  InitQ(&s,&t);
  int in;
  do{
    cout << "0・・・push(x),1・・・pop()" << endl;
    cin >> in;
    if(in==0){
      cout << "追加する数字を入力してください:";
      int x = 0;
      cin >> x;
      if(push(q,x,&t,&s)==0)
	break;
    }
    if(in==1){
      if(pop(q,&t,&s)==0)
	break;
    }
  }while(in==0||in==1);
  return 0;
}

//キューQの初期化の手続き
void InitQ(int *t,int *s){
  *t = 0;
  *s = 0;
}
//キューの大きさを返す関数
int sizeOf(int t,int s){
  if(t-s>=0)
    return t-s;
  else
    return t-s+N;
}
//キューに新しい要素を追加する関数
int push(int q[],int x,int *t,int *s){
  if(sizeOf(*t,*s)==N-1){
    cout << "オーバーフロー" << endl;
    return 0;
  }
  else{
    q[*t]=x;
    *t += 1;
    if(*t==N) *t = 0;
  }
  return 1;
}
//キューの先頭の要素を取り出す関数
int pop(int q[],int *t,int *s){
  if(sizeOf(*t,*s)==0){
    cout << "空" << endl;
    return 0;
  }
  else{
    cout << q[*s] << endl;
    *s += 1;
    if(*s==N) *s = 0;
  }
  return 1;
}

