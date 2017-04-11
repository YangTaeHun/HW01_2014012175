#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100

typedef struct teamates                 // �� ������ ����ü�� �����Ѵ�.
{
   char *teamname;
   int id;
   int weapon;
   int life;
} teamate;

void teamMaker(teamate player[], char name[], int num)       // �� ���������� ����                                                                      �� �Է��Ѵ�.
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
   scanf("%s", &team1);                              // ù ��° ���� �̸��� �Է��Ѵ�. 
   printf("please enter player2's team name : ");
   scanf("%s", &team2);                              // �� ��° ���� �̸��� �Է��Ѵ�.
   printf("please enter number of players in each team : ");
   scanf("%d", &team_num);                         // �� ���� ���� ���� �Է��Ѵ�.

   team1_life = team_num;               // ù ��° ���� ���� ������ �����Ѵ�.
   team2_life = team_num;               // �� ��° ���� ���� ������ �����Ѵ�.

    team_1 = (int *)malloc(team_num * sizeof(teamate));      // �� 1�� ���� �� ��ŭ                                                                    �� ������ �Ҵ��Ѵ�.
    team_2 = (int *)malloc(team_num * sizeof(teamate));       // �� 2�� ���� �� ��ŭ                                                                    �� ������ �Ҵ��Ѵ�.

   for ( i = 0; i < team_num; i++)                  // ���� �� ��ŭ�� ������ �Է��Ѵ�.
   {
      teamMaker(team_1, team1, team_num);
      teamMaker(team_2, team2, team_num);
   }

   printf("���� ���� ��");               // ��1�� ������ ���� �� �� �ְ� ���� ����Ѵ�.
   printf("\n");
   for (i = 0; i < team_num; i++){
      printf("%s %d %d %d\n", team_1[i].teamname, team_1[i].id, team_1[i].weapon, 	team_1[i].life);
   }
   printf("\n");
   printf("\n");

   printf("Master �� �� �� �ִ� ��"); // ��1�� ��2�� ������ ��� �� �� �ְ� ���� �����                                           ��.
   printf("\n");
   for (i = 0; i < team_num; i++){            
      printf("%s %d %d %d\n", team_1[i].teamname, team_1[i].id, team_1[i].weapon, 	team_1[i].life);
   }
   printf("\n");
   for (k = 0; k < team_num; k++){
      printf("%s %d %d %d\n", team_2[k].teamname, team_2[k].id, team_2[k].weapon, team_2[k].life);
   }
   printf("\n");


   // ���������� ������ team1�� team2�� ���� ���������� �����Ѵ�.

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

   printf(" ���� ��� ");
   printf("\n");
                
   for ( i = 0; i < team_num; i++){         // ������ ���� �� ���� ����� ����Ѵ�.
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

  free(team_1);            // �޸𸮸� ��ȯ�Ѵ�.              
  free(team_2);            // �޸𸮸� ��ȯ�Ѵ�.
}

