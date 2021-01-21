/* Group Members:
Section: D and H
19K-0301 Ali Nayab Nathani
19K-0305 Ashmal Anis Vayani
19K-0204 Hasnain Somani
*/

/*
Program will ask for username and password first, Enter the following username and password only:
Username: admin
Password: 75950 
*/

/*
Entering correct username and password at first place will proceed the program.
In multiple attempts the program might not allow you to continue even after correct name and pass. Try exiting the program and reopening it again
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

struct team {
  char players[15], baller[15];
  int runs, bruns, wickets, bwickets;
  char method[10];
}
team1[11], team2[11];

int front1();
void front2();
int overs();
void menu();
void show();
int error(int,int *);

int main() {

  char press, any, name1[10], name2[10], bl[10], bt[10];
  int over, i, c, toss, counte, ii;
  boolean check = false;

//    do{
//    	c=front1();
//    } while(c==1);					// To check password and user name

  front2(); // credits

  while (1) {
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Press \n\t\t\t\t\t\t 1. START THE MATCH \n\t\t\t\t\t\t 2. READ USER MANUAL \n\t\t\t\t\t\t 3. TO EXIT");
    printf("\n\n\t\t\t\t\t\t Enter Your Choice\t");
    press = getche();
    switch (press) {
    case '1':
      {
        /* To check if the 2 two teams have same name. */
        do {
          system("cls");
          printf("\n Enter name of team 1 \t:\t");
          scanf("%s", name1);

          printf(" Enter name of team 2 \t:\t");
          fflush(stdin);
          scanf("%s", name2);

          strcmp(name1, name2) == 0 ? check = false : (check = true);
          if (check == false) {
            printf("\n Can't have same name for 2 teams!!!");
            printf("\n Press any key to enter again ...");
            getch();
          }
        } while (!check); // 2 teams cant have same names

        do {
          over = overs(); // overs cant be negative.
        } while (over < 0);

        system("cls");

        srand(time(NULL)); // random function

        printf("\t\t********* %s VS %s *********\n", name1, name2);
        printf("\t\t********* %d Over Match *******\n", over);
        printf("\n\n\t\t  ******* TOSS ********\n");

        toss = rand() % 4; // random toss
        if (toss == 0) {
          printf("%s won the toss and have elected to bat first!", name1);
          strcpy(bl, name2);
          strcpy(bt, name1);
        }
        if (toss == 1) {
          printf("%s won the toss and have decided to bowl first!", name1);
          strcpy(bl, name1);
          strcpy(bt, name2);
        }
        if (toss == 2) {
          printf("%s won the toss and have elected to bat first!", name2);
          strcpy(bl, name1);
          strcpy(bt, name2);
        }
        if (toss == 3) {
          printf("%s won the toss and have decided to bowl first!", name2);
          strcpy(bl, name2);
          strcpy(bt, name1);
        }

        if (toss == 0 || toss == 1) {
          printf("\n\n Enter 11 players for team#1 : %s\n", name1); // input for 11 players who won toss.
          for (i = 0; i < 11; i++) {
            printf("\n %d.\t", i + 1);
            fflush(stdin);
            scanf("%s", & team1[i].players);
          }
          system("cls");
          printf("\n Enter 11 players for team#2 : %s\n", name2); // input for 11 players who lost toss.
          for (i = 0; i < 11; i++) {
            printf("\n %d.\t", i + 1);
            fflush(stdin);
            scanf("%s", & team2[i].players);
          }
        } 
		else if (toss == 2 || toss == 3) {
          printf("\n\n Enter 11 players for team#1 : %s\n", name2);
          for (i = 0; i < 11; i++) {
            printf("\n %d.\t", i + 1);
            fflush(stdin);
            scanf("%s", & team2[i].players);
          }
          system("cls");
          printf("\n Enter 11 players for team#2 : %s\n", name1);
          for (i = 0; i < 11; i++) {
            printf("\n %d.\t", i + 1);
            fflush(stdin);
            scanf("%s", & team1[i].players);
          }
        }

        int z = 0, j, score, total = 0, k = 0;
        int temp1 = 0, temp2 = 1, w1 = 0;
        char nob;

        system("cls");
        printf("\n**************%dst Innings*****************\n", 1);

        for (i = 0, k = 0; i < over; i++) {
          printf("\n Enter Name Of Bowler From Team %s :\t", bl);
          fflush(stdin);
          gets(team1[z].baller);

          for (j = 0; j <= 5; j++) {
            printf("%d.%d: ", i, j + 1); // input for runs
            scanf("%d", & score);
            error(score, & j); // calling function to check error

            if (score < -1 || score > 6 || score == -1) // no changes in total
              total = total;

            if (score > 0 && score<=6)
              total += score;

            if (score == 1) {
              team1[k].runs += score; // rotating strikes
              team1[z].bruns += score;

              if (k == temp1)
                k = temp2;
              else if (k == temp2) // rotating strikes
                k = temp1;
            }
            if (score == 2) {
              team1[k].runs += score;
              team1[z].bruns += score;
            }
            if (score == 3) //strike rotate
            {
              team1[k].runs += score;
              team1[z].bruns += score;

              if (k == temp1)
                k = temp2;
              else if (k == temp2)
                k = temp1;
            }
            if (score == 4) {
              team1[k].runs += score;
              team1[z].bruns += score;
            }
            if (score == 5) {
              team1[k].runs += score;
              team1[z].bruns += score;
              if (k == temp1)
                k = temp2;
              else if (k == temp2)
                k = temp1;
            }
            if (score == 6) {
              team1[k].runs += score;
              team1[z].bruns += score;
            }
            if (score == -1) // for checking batsmen is out or not
            {
              printf("O- Out?\nN-No ball?\nW-Wide?\nD-Dead ball\n");
              scanf("%s", & nob);
              if (nob == 'O' || nob == 'o') {
                puts("Way Of Getting Out? (Caught, Bowled, Runout, Stumped)");
                fflush(stdin);
                scanf("%s",team1[k].method);
                if (strcmp(team1[k].method, "Runout") == 0 || strcmp(team1[k].method, "runout") == 0)
                  w1++; 	//w1 = total wickets of team
                else {
                  w1++;
                  team1[z].bwickets += 1; //assigning wickets to bowler if not runout
                }
                if (w1 == 1) {
                  if (k == temp1) {
                    temp1 = 2;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 2;
                    k = temp2;
                  }
                } 
				else if (w1 == 2) {
                  if (k == temp1) {
                    k = temp1;
                    temp1 = 3;
                  } 
				  else if (k == temp2) {
                    temp2 = 3;
                    k = temp2;
                  }
                } 
				else if (w1 == 3) {
                  if (k == temp1) {
                    temp1 = 4;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 4;
                    k = temp2;
                  }
                } 
				else if (w1 == 4) {
                  if (k == temp1) {
                    temp1 = 5;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 5;
                    k = temp2;
                  }
                } 
				else if (w1 == 5) {
                  if (k == temp1) {
                    temp1 = 6;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 6;
                    k = temp2;
                  }
                } 
				else if (w1 == 6) {
                  if (k == temp1) {
                    temp1 = 7;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 7;
                    k = temp2;
                  }
                } 
				else if (w1 == 7) {
                  if (k == temp1) {
                    temp1 = 8;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 8;
                    k = temp2;
                  }
                } else if (w1 == 8) {
                  if (k == temp1) {
                    temp1 = 9;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 9;
                    k = temp2;
                  }
                } 
				else if (w1 == 9) {
                  if (k == temp1) {
                    temp1 = 10;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 10;
                    k = temp2;
                  }
                } 
				else if (w1 == 10) {
                  break;
                }
              } 
			  else if (nob == 'N' || nob == 'W' || nob == 'w' || nob == 'n') {
                j--;
                total = total + 1;
              } 
			  else if (nob == 'D' || nob == 'd') {
                j--;
              }
            }
          }
          if (k == temp1) {
            k = temp2;
          } 
		  else if (k == temp2) {
            k = temp1;
          }
          printf("\n");
          printf("\t\t\t ****End of %d Over******\n", i + 1);
          printf("===================================================\n");
          printf("\t\t\t%s||%d / %d \n\n", name1, total, w1);
          printf("Batsman: %s :%d Not Out \t\t Bowler: %s : %d/%d\n", team1[temp1].players, team1[temp1].runs, team1[z].baller, team1[z].bruns, team1[z].bwickets);
          printf("         %s :%d Not Out \n", team1[temp2].players, team1[temp2].runs);
          z++;
          printf("=====================================================\n");
        }

        printf("\n\t\t\t\t|||Target:%d|||\n", total + 1);
        printf("=======================================================\n\n\n\n\n\n\n");
        puts("Press any key to proceed to 2nd Innings.");
        getch();

        /* for second innings*/
        system("cls");
        printf("\n\t\t\t**************2nd Innings*****************\n");

        temp1 = 0, temp2 = 1;
        int total2 = 0, w2 = 0;

        system("cls");
        printf("\n**************%dnd Innings*****************\n", 2);
        for (i = 0, k = 0, z = 0; i < over; i++) {
          printf("\n Enter Name Of Bowler From Team %s :\t", bt);
          fflush(stdin);
          gets(team2[z].baller);

          for (j = 0; j <= 5; j++) {
            printf("%d.%d: ", i, j + 1); // input for runs
            scanf("%d", & score);
            error(score, & j); // calling function to check error

            if (score < -1 || score > 6 || score == -1) // no changes in total
              total2 = total2;

            if (score > 0 && score<=6)
              total2 += score;

            if (score == 1) {
              team2[k].runs += score; // rotating strikes
              team2[z].bruns += score;

              if (k == temp1)
                k = temp2;
              else if (k == temp2) // rotating strikes
                k = temp1;
            }
            if (score == 2) {
              team2[k].runs += score;
              team2[z].bruns += score;
            }
            if (score == 3) {
              team2[k].runs += score;
              team2[z].bruns += score;

              if (k == temp1)
                k = temp2;
              else if (k == temp2)
                k = temp1;
            }
            if (score == 4) {
              team2[k].runs += score;
              team2[z].bruns += score;
            }
            if (score == 5) {
              team2[k].runs += score;
              team2[z].bruns += score;
              if (k == temp1)
                k = temp2;
              else if (k == temp2)
                k = temp1;
            }
            if (score == 6) {
              team2[k].runs += score;
              team2[z].bruns += score;
            }

            //////////////////////////////////////////
            if (score == -1) // for checking batsmen is out or not
            {
              printf("O- Out?\nN-No ball?\nW-Wide?\nD-Dead ball\n");
              scanf("%s", & nob);
              if (nob == 'O' || nob == 'o') {
                puts("Way Of Getting Out? (Caught, Bowled, Runout, Stumped)");
                fflush(stdin);
                scanf("%s",team2[k].method);
                if (strcmp(team2[k].method, "Runout") == 0 || strcmp(team2[k].method, "runout") == 0)
                  w2++;
                else {
                  w2++;
                  team2[z].bwickets += 1;
                }
                if (w2 == 1) {
                  if (k == temp1) {
                    temp1 = 2;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 2;
                    k = temp2;
                  }
                } 
				else if (w2 == 2) {
                  if (k == temp1) {
                    k = temp1;
                    temp1 = 3;
                  } 
				  else if (k == temp2) {
                    temp2 = 3;
                    k = temp2;
                  }
                } 
				else if (w2 == 3) {
                  if (k == temp1) {
                    temp1 = 4;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 4;
                    k = temp2;
                  }
                } 
				else if (w2 == 4) {
                  if (k == temp1) {
                    temp1 = 5;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 5;
                    k = temp2;
                  }
                } 
				else if (w2 == 5) {
                  if (k == temp1) {
                    temp1 = 6;
                    k = temp1;
                  } else if (k == temp2) {
                    temp2 = 6;
                    k = temp2;
                  }
                } 
				else if (w2 == 6) {
                  if (k == temp1) {
                    temp1 = 7;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 7;
                    k = temp2;
                  }
                } 
				else if (w2 == 7) {
                  if (k == temp1) {
                    temp1 = 8;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 8;
                    k = temp2;
                  }
                } 
				else if (w2 == 8) {
                  if (k == temp1) {
                    temp1 = 9;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 9;
                    k = temp2;
                  }
                } 
				else if (w2 == 9) {
                  if (k == temp1) {
                    temp1 = 10;
                    k = temp1;
                  } 
				  else if (k == temp2) {
                    temp2 = 10;
                    k = temp2;
                  }
                } 
				else if (w2 == 9) {
                  break;
                }
              } 
			  else if (nob == 'N' || nob == 'W' || nob == 'w' || nob == 'n') {
                j--;
                total2 = total2 + 1;
              } 
			  else if (nob == 'D' || nob == 'd') {
                j--;
              }
              //////////////////////////////////////////
            }
            if (total2 > total)
              break;
          }
          if (k == temp1) {
            k = temp2;
          } 
		  else if (k == temp2) {
            k = temp1;
          }
          printf("\n");
          printf("\t\t\t ****End of %d Over******\n", i + 1);
          printf("===================================================\n");
          printf("\t\t\t%s||%d / %d \n\n", name2, total2, w2);
          printf("Batsman: %s :%d Not Out \t\t Bowler: %s : %d/%d\n", team2[temp1].players, team2[temp1].runs, team2[z].baller, team2[z].bruns, team2[z].bwickets);
          printf("         %s :%d Not Out \n", team2[temp2].players, team2[temp2].runs);
          z++;
          printf("=====================================================\n");
          
		}
          system("cls");
          FILE * f, * f2;
          f = fopen("first.txt", "w");
          f2 = fopen("second.txt", "w");
          if (f == NULL || f2 == NULL)
            printf("\nCant open file.");
          else {
            for (i = 0; i < 10; i++) {
              fprintf(f, "%s\t\t%d\t%d\n", team1[i].players, team1[i].runs, team1[i].wickets);
              fprintf(f2, "%s\t\t%d\t%d\n", team2[i].players, team2[i].runs, team2[i].wickets);
            }
            fclose(f);
            fclose(f2);
          }

          printf("\n\n\t\t\t\t******End Of Match****\n\n");
          printf("=============================================================\n");
          printf("=============================================================\n");
          printf("\t\t\t\t******Match Summary****\n");
          printf("\n\t\t\t\t  ***1st Innings***\n");

          printf("=========================================================\n");
          printf("PLAYER'S NAME        METHOD             RUNS\n");
          printf("=========================================================\n");
          for (i = 0; i <= 10; i++) {
            printf("%-20s %-20s%d\n", team1[i].players, team1[i].method, team1[i].runs);
          }

          printf("=========================================================\n");
          printf("BOWLER'S NAME        RUNS CONCEDED           WICKETS\n");
          printf("=========================================================\n");
          for (i = 0; i < over; i++) {
            printf("%-20s %-20d %d\n", team1[i].baller, team1[i].bruns, team1[i].bwickets);
          }
          printf("\n            ***TOTAL-%d / %d***              \n", total, w1);
          puts("---------------------------------------------");

          printf("\n\n\n\t\t\t\t******2nd Innings******\n");
          printf("=========================================================\n");
          printf("PLAYER'S NAME        METHOD             RUNS\n");
          printf("=========================================================\n");

          for (i = 0; i <= 10; i++) {
            printf("%-20s %-20s %d\n", team2[i].players, team2[i].method, team2[i].runs);
          }
          printf("=========================================================\n");
          printf("BOWLER'S NAME        RUNS CONCEDED           WICKETS\n");
          printf("=========================================================\n");
          for (i = 0; i < over; i++) {
            printf("%-20s %-20d %d\n", team2[i].baller, team2[i].bruns, team2[i].bwickets);
          }
          printf("\n            ***TOTAL-%d / %d***              \n", total2, w2);
          puts("----------------------------------------------------");

          if (total > total2 && (toss == 0 || toss == 3)) {
            printf("\nTeam %s won by %d Runs \n", name1, total - total2);
          } 
		  else if (total > total2 && (toss == 1 || toss == 2)) {
            printf("\nTeam %s won by %d Runs\n", name2, total - total2);
          } 
		  else if (total2 > total && (toss == 1 || toss == 2)) {
            printf("\nTeam %s won the game by %d Wickets!\n", name1, 10 - w1);
          } 
		  else if (total2 > total && (toss == 0 || toss == 3)) {
            printf("\nTeam %s won the game by %d Wickets!\n", name2, 10 - w2);
          } 
		  else if (total2 == total) {
            printf("\nIt,s a TIE!!\n");
          }
          show();
      }
      break;

    case '2':
      system("cls");
      menu();
      any = getch();
      break;
    case '3':
      exit(0);
    default:
      break;

    }
  }

  getch();
  return 0;
}

// Now defining functions. 

void gotoxy(int x, int y) {
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int front1() {
  char name[10], pass[5], ch;
  int i = 0;
  system("cls");
  system("COLOR 3E");
  gotoxy(60, 20);
  printf("**********************************\n");
  gotoxy(60, 21);
  printf("WELCOME TO CRICKET SCORING SYSTEM");
  gotoxy(60, 22);
  printf("**********************************\n");
  gotoxy(60, 24);
  printf("Username : ");
  gets(name);
  gotoxy(60, 25);
  printf("Password : ");
  while (1) {
    ch = getch();
    if (ch == 13)
      break;
    else if (ch == 9 || ch == 32)
      continue;
    else if (ch == 8) {
      if (i > 0) {
        i--;
        printf("\b \b");
      }
    } 
	else {
      pass[i] = ch;
      i++;
      printf("*");
    }
  }
	
  if ((strcmp(name, "admin") != 0) || (strcmp(pass, "75950") != 0)) {
    Beep(1200, 300);
    system("cls");
    return (1);
  }
}
void front2() {
  system("cls");
  gotoxy(66, 16);
  printf(" -------------------------\n");
  gotoxy(66, 17);
  printf("|   ALL RIGHTS RESERVED   |");
  gotoxy(66, 18);
  printf(" -------------------------\n");
  gotoxy(66, 20);
  printf("| Made By: Ashmal Vayani  |");
  gotoxy(66, 21);
  printf("| \t     Nayab Nathani  |");
  gotoxy(66, 22);
  printf("| \t     Hasnain Somani |");
  gotoxy(66, 23);
  printf(" -------------------------\n");
  gotoxy(70, 27);

  printf("Loading  ");
  int j, a;
  for (a = 0; a <= 5; a++) {
    printf(".");
    for (j = 0; j <= 38000000; j++);
  }
  system("cls");

}

void menu() {

  printf("\t\t\t\t**** CRICKET SCORING PROGRAM ****\n");
  printf("\t\t\t\t******** USER MANUAL ********\n");

  printf("\n1. First enter the name of two playing teams\n");
  printf("2. Enter the number of overs to be played in each innings\n");
  printf("3. Donot enter no. of overs or score in character form\n");
  printf("4. Enter the name of players according to correct batting order\n");
  printf("5. Enter the player name in same case as declared.\n");
  printf("6. Enter -1 in the runs, if the ball is dead, white or no ball or the batsman is out.\n");
  printf("7. Enter the way batsman has been out, if the batsman has been out through runout, bowler won't get a wicket.\n");
  printf("8. Be careful with the case 'Runout','Stumped','Bowled','Caught'\n");
  printf("9. Avoid entering runs other else then '1,2,3,4,5,6,-1', or else error will be shown.\n");
  printf("10. Enter the name of the new bowler after every over and start of the inning.\n\n");
  
  

  printf("\n\n\t\tPress any key to go back ...\t ");
}
int overs() {
  int over;

  printf(" Enter total overs of innings :\t");
  while (1) {
    scanf("%d", & over);
    if (over <= 0){
    	printf("\n ERROR!\n Over can't be negative.\n");
	}
    else
    	break;
  }
  return over;
}
int error(int score, int * j) {
  if (score >= -1 && score <= 6)
    return score;
  else {
  	printf("ERROR!\n");
 	printf("Avoid entering anything other then -1,1,2,3,4,5,6\n");
	}

    *j -= 1;
    return *j;
  }


void show(void) {
  int i;
  FILE *f;
  f = fopen("first.txt", "r");

  FILE * f2;
  f2 = fopen("second.txt", "r");

  printf("\n\n*********************************************************\n");
  printf("\t\t\t\tINNING ONE \n");

  printf("\nPlayer\t\tRuns\tWickets\n");
  for (i = 0; i <= 10; i++) {
    fscanf(f, "%s%d%d", team1[i].players, & team1[i].runs, & team1[i].wickets);
    printf("%s\t\t%d\t%d\n", team1[i].players, team1[i].runs, team1[i].wickets);
  }

  printf("\n\n*********************************************************\n");
  printf("\t\t\t\tINNING TWO \n");

  printf("\nPlayer\t\tRuns\tWickets\n");
  for (i = 0; i <= 10; i++) {
    fscanf(f, "%s%d%d", team2[i].players, & team2[i].runs, & team2[i].wickets);
    printf("%s\t\t%d\t%d\n", team2[i].players, team2[i].runs, team2[i].wickets);
  }
  printf("\n----------- END --------");
  printf("\n\n\t\tPress any key to go back ...\t ");
  getch();
  fclose(f);
  fclose(f2);
}
