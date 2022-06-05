#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
int return_case = 0;//initialisation of the global variable return_case.

//----------------INITIALISATION OF THE FUNCTION---------------
void continue_playing();
int protect_bug ();
int verification(int col, int lin, int COL, int LIN, char tab[COL][LIN]);
void displays_the_player_table(int lin, int col, char tab_player[col][lin]);
void initialisation_tab_player(int col, int lin, char tab_player[col][lin]); 
void initialisation_tab_player_2(int col, int lin,char tab_player[col][lin], char tab_player_2[col][lin]);
void initialisation(int nbmine, int col, int lin, char tab[col][lin]);
void initialisation_2(int nbmine, int nbmine_2, int col, int lin,char tab[col][lin], char tab_2[col][lin]);
void revelation_of_the_squares(int col, int lin, int COL, int LIN,char tab[COL][LIN], char tab_player[COL][LIN]); 
void victory_animation();
int play_2(int nbmine,int nbmine_2, int col, int lin, char tab[col][lin], char tab_2[col][lin],char tab_player[col][lin], char tab_player_2[col][lin], int cases, int counter_flag, int counter_flag_2, int turn, int chrono, int chrono_2, int p1_victory, int p2_victory);
int play(int nbmine, int col, int lin, char tab[col][lin],char tab_player[col][lin], int cases, int counter_flag);
int length_int(int number);
void display_best_score(char start_name[2][10], char inter_name[2][10], int start_score[3], int inter_score[3]);
int victory_verification(int nbmine, int col, int lin, char tab_player[col][lin]);
int main();

#include "continue_playing.h"
#include "protect_bug.h"
#include "verification.h"
#include "displays_the_player_table.h"
#include "initialisation_tab_player.h"
#include "initialisation_tab_player_2.h"
#include "initialisation.h"
#include "initialisation_2.h"
#include "revelation_of_the_squares.h"
#include "victory_animation.h"
#include "play_2.h"
#include "play.h"
#include "length_int.h"
#include "display_best_score.h"
#include "victory_verification.h"






/* main : this fonction is the main fonction which permit us to know which part of the game the player want to play. also this function manage the scoreboard.
this function has no argument.*/
int main() {
  time_t t1, t2;
  srand(time(NULL));
  int COL;
  int LIN;
  int nbmine = 0;
  int choice;
  int choice_column = 0;
  int choice_line;
  int choice_bomb;
  int score = 0;
  int cas = 0;
  int counter_flag;
  int start_score[3];
  int inter_score[3];
  int c = 0;
  float chrono;
  float best_score;
  double n = 0.1;
  char name[10];
  char start_name[4][10];
  char inter_name[4][10];
  char memory_name[10];
  char chain[82] = "";
  FILE *file = NULL;
  file = fopen("save_demineur.txt", "r+");   
  if (file != NULL) {
    fscanf(file, "%d %d %d %d %d %d", &start_score[0], &start_score[1], &start_score[2], &inter_score[0], &inter_score[1], &inter_score[2]);
    fscanf(file, "%s %s %s %s %s %s", &start_name[0][10], &start_name[1][10], &start_name[2][10], &inter_name[0][10], &inter_name[1][10], &inter_name[2][10]);
  }
  char tab[15][15];
  char tab_2[15][15];
  char tab_player[15][15];
  char tab_player_2[15][15];
  FILE *f_bomb = NULL;
  f_bomb = fopen("f_bomb.txt", "r+");
  if (f_bomb != NULL)
  {
    while (fgets(chain, 82, f_bomb) != NULL) 
    {
      printf("%s", chain); 
    }
    fclose(f_bomb);
  }
  sleep(10);
  printf("\033[H\033[2J");
  printf("__________________________________________________\n");
  printf("--------------BIENVENUE DANS LE DEMINEUR !--------\n");
  display_best_score(start_name, inter_name, start_score, inter_score);
  printf("CHOISISSEZ LA DIFFICULTEE : \n");
  printf("|DEBUTANT|     |INTERMEDIAIRE|     |PERSONALISE|     |MULTIPLAYER|\n");
  printf("    1                2                   3                 4\n");
  while ((choice != 1) || (choice != 2) || (choice != 3) || (choice != 4)) {
    printf("CHOIX :");
    choice = protect_bug();
    if ((choice == 1) || (choice == 2) || (choice == 3) || (choice == 4)) {
      break;
    }
  }
  t1 = time(NULL);  
  if (choice == 1) {
    COL = 9;
    LIN = 9;
    nbmine = 10;
    counter_flag = nbmine;
  }
  else if (choice == 2) {
    COL = 16;
    LIN = 16;
    nbmine = 40;
    counter_flag = nbmine;
  }
  else if (choice == 3){
    printf("choisir la taille du tableau\n");
    printf("Largeur : ");
    COL = protect_bug();
    printf("Hauteur : ");
    LIN = protect_bug();
    printf("Mines : ");
    while ((nbmine == 0) || (nbmine > (COL * LIN))){
      nbmine = protect_bug();
      counter_flag = nbmine;
    }
  }
  else{
    printf("choisir la taille des tableaux\n");
    printf("Largeur : ");
    COL = protect_bug();
    printf("Hauteur : ");
    LIN = protect_bug();
    printf("Mines : ");
    while ((nbmine == 0) || (nbmine > (COL * LIN))){
      nbmine = protect_bug();
    }
    int counter_flag = nbmine;
    printf("_____________________________\n");
    printf("PHASE DE PREPARATION\n");
    printf("_____________________________\n");
    initialisation_tab_player_2(COL, LIN, tab_player, tab_player_2); 
    initialisation_2(nbmine, nbmine, COL, LIN,tab, tab_2);
    printf("_____________________________\n");
    printf("PHASE DE JEU \n");  
    printf("_____________________________\n");
    cas = play_2(nbmine, nbmine, COL, LIN, tab, tab_2, tab_player, tab_player_2, cas, counter_flag, counter_flag, 0, chrono, chrono,  0, 0);
  }
  if (choice != 4){
     initialisation_tab_player(COL, LIN, tab_player);
     initialisation(nbmine, COL, LIN, tab);
     cas = play(nbmine, COL, LIN, tab, tab_player, cas, counter_flag);
  }
  t2 = time(NULL);
  if (return_case == 3){
    sleep(3);
    printf("\033[H\033[2J");
    printf("bravo à toi joueur 1 !!!!\n");
    sleep(3);
    continue_playing();
    return 0;
  }
  if (return_case == 4){
    sleep(3);
    printf("\033[H\033[2J");
    printf("bravo à toi joueur 2 !!!!\n");
    sleep(3);
    continue_playing();
    return 0;
  }
  if(return_case == 11 || return_case == 12 || return_case == 13){
    sleep(3);
    printf("\033[H\033[2J");
    char chain [40];
    FILE *looser = NULL;
    looser = fopen("looser.txt", "r+");
    if (looser != NULL)
    {
      while (fgets(chain, 40, looser) != NULL) 
      {
        printf("%s", chain);
      } 
     fclose(looser);
    }
    sleep(10);
    continue_playing();
    return 0;
  }
  fclose(file);
  if(choice == 3){
    printf("DESOLE MAIS VOTRE MODE DE JEU VOUS DECLASSIFIE !\n");
    //continue_playing();
  }
  chrono = t2 - t1;
  printf("CHRONO :  | %.0f | secondes\n", chrono);
  file = fopen("save_demineur.txt", "w+");
  int conversion;
  score = chrono * 1000;
  if (file != NULL) {
    if(choice == 1){
      if(score <= start_score[2]){
        printf("Veuillez marquer votre name (pas plus de 9 caracteres)\n");
        scanf("%9s", start_name[0]);
        for(int i = 0; i<3; i++){
	        if(score <= start_score[i]){
	          int memory = 0;
	          memory = start_score[i];
	          start_score[i] = score;
	          score = memory; 
	          c++;
	          strcpy(memory_name , start_name[i]);
	          strcpy(start_name[i], start_name[0]);
	          strcpy(start_name[0], memory_name);      
	        }
        }
        if(c == 3){
	        strcpy(start_name[3], start_name[0]);
        }
        if(c == 2){
	        strcpy(memory_name , start_name[1]);
	        strcpy(start_name[1], start_name[2]);
	        strcpy(start_name[2], memory_name); 
	        strcpy(start_name[3], start_name[0]);    
        }
        if(c == 1){
	        strcpy(memory_name , start_name[3]);
	        strcpy(start_name[3], start_name[2]);
	        strcpy(start_name[2], memory_name);
	        strcpy(start_name[2], start_name[0]);
        }
      }
    }
    else if(choice == 2){
      if(score <= inter_score[2]){
        printf("Veuillez marquer votre name (pas plus de 9 caracteres)\n");
        scanf("%s", inter_name[0]);
        for(int i = 0; i<3; i++){
          if(score <= inter_score[i]){
            int memory = 0;
            memory = inter_score[i];
            inter_score[i] = score;
            score = memory;
            c++;
            strcpy(memory_name , inter_name[i]);
            strcpy(inter_name[i], inter_name[0]);
            strcpy(inter_name[0], memory_name);      
          } 
        }
        if(c == 3){
          strcpy(inter_name[3], inter_name[0]);
        }
        if(c == 2){
          strcpy(memory_name , inter_name[1]);
          strcpy(inter_name[1], inter_name[2]);
          strcpy(inter_name[2], memory_name);
          strcpy(inter_name[3], inter_name[0]);
        }
        if(c == 1){
          strcpy(memory_name , inter_name[3]);
          strcpy(inter_name[3], inter_name[2]);
          strcpy(inter_name[2], memory_name);
          strcpy(inter_name[2], inter_name[0]);
        }
      }
    }  
    display_best_score(start_name, inter_name, start_score, inter_score);
    fprintf(file, "%d %d %d %d %d %d\n", start_score[0], start_score[1], start_score[2], inter_score[0], inter_score[1], inter_score[2]);
    fprintf(file, "%s %s %s %s %s %s", &start_name[0][10],&start_name[1][10],&start_name[2][10], &inter_name[0][10], &inter_name[1][10], &inter_name[2][10]);
    fclose(file);
    continue_playing();
    return 0;
  }
}
