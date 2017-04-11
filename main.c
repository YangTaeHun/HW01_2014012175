#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100

typedef struct teamates                 // 팀 정보를 구조체로 정의한다.
{
   char *teamname;
   int id;
   int weapon;
   int life;
} teamate;

void teamMaker(teamate player[], char name[], int num)       // 팀 구성원들의 정보                                                                      를 입력한다.
{                       
    int i ;
   for (i = 0; i < num; i++)
   {
      player[i].teamname = name;
      player[i].id = i+1;
      player[i].weapon = (rand() % 3) + 1;
      player[i].life = 1;
   }
}

int main()
{
   char team1[MAX_SIZE], team2[MAX_SIZE];
   teamate *team_1, *team_2;
   int team_num, team1_life, team2_life, weaponExchange;
   int i, k;
   srand(time(NULL));

   printf("please enter player1's team name : ");     
   scanf("%s", &team1);                              // 첫 번째 팀의 이름을 입력한다. 
   printf("please enter player2's team name : ");
   scanf("%s", &team2);                              // 두 번째 팀의 이름을 입력한다.
   printf("please enter number of players in each team : ");
   scanf("%d", &team_num);                         // 각 팀의 팀원 수를 입력한다.

   team1_life = team_num;               // 첫 번째 팀의 생명 변수를 지정한다.
   team2_life = team_num;               // 두 번째 팀의 생명 변수를 지정한다.

    team_1 = (int *)malloc(team_num * sizeof(teamate));      // 팀 1의 팀원 수 만큼                                                                    의 정보를 할당한다.
    team_2 = (int *)malloc(team_num * sizeof(teamate));       // 팀 2의 팀원 수 만큼                                                                    의 정보를 할당한다.

   for ( i = 0; i < team_num; i++)                  // 팀원 수 만큼의 정보를 입력한다.
   {
      teamMaker(team_1, team1, team_num);
      teamMaker(team_2, team2, team_num);
   }

   printf("내가 보는 것");               // 팀1의 정보를 나만 볼 수 있게 따로 출력한다.
   printf("\n");
   for (i = 0; i < team_num; i++){
      printf("%s %d %d %d\n", team_1[i].teamname, team_1[i].id, team_1[i].weapon, 	team_1[i].life);
   }
   printf("\n");
   printf("\n");

   printf("Master 만 볼 수 있는 것"); // 팀1과 팀2의 정보를 모두 볼 수 있게 따로 출력한                                           다.
   printf("\n");
   for (i = 0; i < team_num; i++){            
      printf("%s %d %d %d\n", team_1[i].teamname, team_1[i].id, team_1[i].weapon, 	team_1[i].life);
   }
   printf("\n");
   for (k = 0; k < team_num; k++){
      printf("%s %d %d %d\n", team_2[k].teamname, team_2[k].id, team_2[k].weapon, team_2[k].life);
   }
   printf("\n");


   // 가위바위보 게임은 team1과 team2가 각각 순차적으로 진행한다.

   for(i=0,k=0;(i<team_num),(k<team_num);){
        if((team_1[i].weapon == 1) && (team_2[k].weapon == 1)){
        team_1[i].weapon = (rand()%3)+1 ;
        team_2[k].weapon = (rand()%3)+1 ;

       }
      else if ((team_1[i].weapon == 1) && (team_2[k].weapon == 2))
      {
         team_1[i].life = 0;
         weaponExchange = (rand() % 2);
         if (weaponExchange == 0)
            team_2[k].weapon = team_1[i].weapon;

         i = i + 1;
         team1_life = team1_life - 1;
      }
      else if ((team_1[i].weapon == 1) && (team_2[k].weapon == 3))
      {
         team_2[k].life = 0;
         weaponExchange = (rand() % 2);
         if (weaponExchange == 0)
            team_1[i].weapon = team_2[k].weapon;

         k = k + 1;
         team2_life = team2_life - 1;
      }
      else if ((team_1[i].weapon == 2) && (team_2[k].weapon == 1)){
         team_2[k].life = 0;
         weaponExchange = (rand() % 2);
         if (weaponExchange == 0)
            team_1[i].weapon = team_2[k].weapon;

         k = k + 1;
         team2_life = team2_life - 1;
      }
      else if ((team_1[i].weapon == 2) && (team_2[k].weapon == 2)){
          team_1[i].weapon = (rand()%3)+1 ;
          team_2[k].weapon = (rand()%3)+1 ;

      }
      else if ((team_1[i].weapon == 2) && (team_2[k].weapon == 3)){
          team_1[i].life = 0;
         weaponExchange = (rand() % 2);
         if (weaponExchange == 0)
            team_2[k].weapon = team_1[i].weapon;

         i = i + 1;
         team1_life = team1_life - 1;
      }
      else if ((team_1[i].weapon == 3) && (team_2[k].weapon == 1)){
          team_1[i].life = 0;
         weaponExchange = (rand() % 2);
         if (weaponExchange == 0)
            team_2[k].weapon = team_1[i].weapon;

         i = i + 1;
         team1_life = team1_life - 1;
      }
      else if((team_1[i].weapon == 3) && (team_2[k].weapon == 2)){
           team_2[k].life = 0;
         weaponExchange = (rand() % 2);
         if (weaponExchange == 0)
            team_1[i].weapon = team_2[k].weapon;

         k = k + 1;
         team2_life = team2_life - 1;
      }
      else if((team_1[i].weapon == 3) && (team_2[k].weapon == 3)){
          team_1[i].weapon = (rand()%3)+1 ;
          team_2[k].weapon = (rand()%3)+1 ;
          }
   }

   printf(" 게임 결과 ");
   printf("\n");
                
   for ( i = 0; i < team_num; i++){         // 게임이 끝난 후 게임 결과를 출력한다.
      printf("%s %d %d %d\n", team_1[i].teamname, team_1[i].id, team_1[i].weapon, team_1[i].life);
   }
   printf("\n");
   for ( k = 0; k < team_num; k++){
      printf("%s %d %d %d\n", team_2[k].teamname, team_2[k].id, team_2[k].weapon, team_1[k].life);
   }

   printf("\n");

   if (team1_life == team2_life){
      printf("Draws!\n");
   }
   else if (team1_life > team2_life){
    printf("%s is winner!!! ", team1);
   }
   else if (team1_life < team2_life){
    printf("%s is winner!!!", team2);
   }

  free(team_1);            // 메모리를 반환한다.              
  free(team_2);            // 메모리를 반환한다.
}

