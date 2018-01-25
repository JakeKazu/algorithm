#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100000
#define NO_CITY -1
#define N 4

/* スタックデータの定義 Stack,Cityに利用します。*/
struct Stack{
  int num;              /* スタックに存在する要素数 */
  int data[STACK_SIZE]; /* 要素の格納先 */
};
typedef struct Stack stack_t;

void Push(stack_t *stk, int push_data);
int Pop(stack_t *stk);
int Empty(stack_t stk);

int City_count(stack_t tour);
void Update_Best_tour(stack_t *curr_tour, stack_t *best_tour);
void Copy(stack_t *curr_tour, stack_t *best_tour);
int Feasible(stack_t stk, int nbr);
int Get_Cost(stack_t tour);

int Graph[N][N] = {{-1,1,3,8},{5,-1,2,6},{1,18,-1,10},{7,4,12,-1}}; // -1は通ることができない。

int main(){
  stack_t stack = {0};
  int city,nbr;
  stack_t best_tour = {0};
  stack_t curr_tour = {0};
  Push(&curr_tour,0);
  for(city = N-1; city >= 1; city--)
    Push(&stack, city);
  while (!Empty(stack)) {
    city = Pop(&stack);
    if(city == NO_CITY)
      Pop(&curr_tour);
    else {
      Push(&curr_tour, city);
      if(City_count(curr_tour) == N) {
        Update_Best_tour(&curr_tour, &best_tour);
        Pop(&curr_tour);
      } else {
        Push(&stack, NO_CITY);
        for(nbr = N-1;nbr >= 1; nbr--)
          if(Feasible(curr_tour, nbr))
            Push(&stack, nbr);
      }
    }
  }

  printf("cost=%d\n",Get_Cost(best_tour));
  int i=0;
  for(i=0;i<N;i++)
    printf("City%d = %d\n",i,best_tour.data[i]);
  return EXIT_SUCCESS;
}

// Stackやcurr_cityにデータを追加する。
void Push(stack_t *stk, int push_data)
{
  stk->data[stk->num] = push_data;
  stk->num++;
}

// curr_tourとbest_tourの比較を行い、更新する場合はbest_tourにcurr_tourをコピーする。
void Update_Best_tour(stack_t *curr_tour, stack_t *best_tour)
{
  if( best_tour->num == 0 ){
    Copy(curr_tour, best_tour);
    return;
  }

  if(Get_Cost(*curr_tour) < Get_Cost(*best_tour))
    Copy(curr_tour, best_tour);
}

// tourのcostを計算する。
int Get_Cost(stack_t tour){
  int cost = 0, i;
  for(i=0;i<N;i++){
    int index1 = i;
    int index2 = (i == N-1 ? 0 : i + 1);
    cost += Graph[tour.data[index1]][tour.data[index2]];
  }
  return cost;
}

// まだ訪問していないCityであるかを判定する。
int Feasible(stack_t curr_tour, int nbr)
{
  int i;
  for(i=0;i<curr_tour.num;i++)
    if(curr_tour.data[i] == nbr)
      return 0;
  return 1;
}

// Cityのデータをコピーする。
void Copy(stack_t *curr_tour, stack_t *best_tour)
{
  int i;
  for(i=0;i<curr_tour->num;i++)
    best_tour->data[i] = curr_tour->data[i];
  best_tour->num = curr_tour->num;
}

// 末尾のデータを取り出す。
int Pop(stack_t *stk)
{
  stk->num--;
  return stk->data[stk->num];
}

// Stackが空であるかを判定する。
int Empty(stack_t stk)
{
  if(stk.num < 1) return 1;
  return 0;
}

// 訪れているCityの個数を返す。
int City_count(stack_t tour)
{
  return tour.num;
}
