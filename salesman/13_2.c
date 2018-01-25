#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100000
#define NO_CITY 100000
#define N 4

struct City{
  int num;
  int data[STACK_SIZE];
};
typedef struct City city_t;

/* スタックデータの定義 */
struct Stack{
  int num;              /* スタックに存在する要素数 */
  city_t data[N*N/2]; /* 要素の格納先 */
};
typedef struct Stack stack_t;

int Empty(stack_t stk);
void Push_copy(stack_t *stack, city_t curr_tour);
city_t Pop(stack_t *stack);

void AddCity(city_t *stk, int push_data);
int Remove_last_City(city_t *stk);
int City_count(city_t tour);
void Update_Best_tour(city_t *curr_tour, city_t *best_tour);
void Copy(city_t *curr_tour, city_t *best_tour);
int Feasible(city_t stk, int nbr);
int Get_Cost(city_t tour);
void Free_tour(city_t *tour);

int Graph[N][N] = {{-1,1,3,8},{5,-1,2,6},{1,18,-1,10},{7,4,12,-1}}; // -1は通ることができない。

int main(){
  stack_t stack = {0};
  int nbr,i;
  city_t best_tour = {0};
  city_t curr_tour = {0};

  AddCity(&curr_tour,0);
  Push_copy(&stack, curr_tour);
  Remove_last_City(&curr_tour);
  while (!Empty(stack)) {
    curr_tour = Pop(&stack);
    if(City_count(curr_tour) == N) {
      Update_Best_tour(&curr_tour, &best_tour);
    } else {
      for(nbr = N-1;nbr >= 1; nbr--)
        if(Feasible(curr_tour, nbr)){
          AddCity(&curr_tour, nbr);
          Push_copy(&stack, curr_tour);
          Remove_last_City(&curr_tour);
        }
    }
    Free_tour(&curr_tour);
  }

  printf("cost=%d\n",Get_Cost(best_tour));
  for(i=0;i<N;i++)
    printf("City%d = %d\n",i,best_tour.data[i]);
  return EXIT_SUCCESS;
}

city_t Pop(stack_t *stack)
{
  stack->num --;
  return stack->data[stack->num];
}

int Empty(stack_t stk)
{
  if(stk.num < 1) return 1;
  return 0;
}


void AddCity(city_t *stk, int push_data)
{
    stk->data[stk->num] = push_data;
    stk->num++;
}

void Push_copy(stack_t *stack, city_t curr_tour)
{
  stack->data[stack->num].num = curr_tour.num;
  int i;
  for(i=0;i<curr_tour.num;i++)
    stack->data[stack->num].data[i] = curr_tour.data[i];
  stack->num++;
}

void Update_Best_tour(city_t *curr_tour, city_t *best_tour)
{
  if( best_tour->num == 0 ){
    Copy(curr_tour, best_tour);
    return;
  }

  if(Get_Cost(*curr_tour) < Get_Cost(*best_tour))
    Copy(curr_tour, best_tour);
}

int Get_Cost(city_t tour){
  int cost = 0, i;
  for(i=0;i<N;i++){
    int index1 = i;
    int index2 = (i == N-1 ? 0 : i + 1);
    cost += Graph[tour.data[index1]][tour.data[index2]];
  }
  return cost;
}

int Feasible(city_t curr_tour, int nbr)
{
  int i;
  for(i=0;i<curr_tour.num;i++)
    if(curr_tour.data[i] == nbr)
      return 0;
  return 1;
}

void Copy(city_t *curr_tour, city_t *best_tour)
{
  int i;
  for(i=0;i<curr_tour->num;i++)
    best_tour->data[i] = curr_tour->data[i];
  best_tour->num = curr_tour->num;
}

int Remove_last_City(city_t *stk)
{
    stk->num--;
    return stk->data[stk->num];
}

int City_count(city_t tour)
{
  return tour.num;
}

void Free_tour(city_t *tour)
{
  tour->num = 0;
}
