/*play_2 : this function is use to choose between plant a flag of dig a case.  it permit to know if the players have win or loose. this function manage the players table.
nbmine and nbmine_2: the number of mines which are unknown to players in their own table.
col : the max number of columnes in the table.
lin : the max number of lines in the table.
tab[col][lin] and tab_2[col][lin] :  tables which contains information of bomb and number of bombs around a case. it depend of the player.
tab_player[col][lin] tab_player_2[col][lig] : tables which is use by the players when he plant or dig in a case. it depend of the player.
cases : the main variable which return to the main function if the player win, loose or not.
counter_flag and counter_flag_2 : these variables permit to know how many flag is still available to be plant in each player's table.
turn : this variable permit us to know if it's the player 1 or 2 turn's
chrono and chrono_2 : theses variables is use to store the time of each player when they plant or dig a case.
p1_victory and p2_victory : theses variables let us know if a player have complete his table
in addition to the play function, the managment of the time of each player and who is supposed to play is the most complicated part.*/
int play_2(int nbmine,int nbmine_2, int col, int lin, char tab[col][lin], char tab_2[col][lin], char tab_player[col][lin], char tab_player_2[col][lin], int cases, int counter_flag, int counter_flag_2, int turn, int chrono, int chrono_2, int p1_victory, int p2_victory){
  int column_choice = col + 1;
  int line_choice = lin + 1;
  int action_choice;
  int total_mine = nbmine;
  int total_mine_2 = nbmine_2;
  time_t t2, t3;//initlisation of the time.
  time_t t1 = time(NULL);
  if (turn == 0){
    printf("joueur 1\n");
    displays_the_player_table(lin, col, tab_player);
  }
  else{
    printf("joueur 2\n");
    displays_the_player_table(lin, col, tab_player_2);
  }
  if (cases == 0){
    printf("____________________________________________________________________\n");
    printf("|poser un drapeau|                                         |creuser|\n");
    printf("|    1           |                                         |    2  |\n");
    printf("____________________________________________________________________\n");
    action_choice = 5;
    while ((action_choice != 1) || (action_choice != 2)) { 
      printf("choix action (1 ou 2): ");
      action_choice = protect_bug();
      if ((action_choice == 1) || (action_choice == 2)) {
        break;
      }
    }
    printf("CHOISISSEZ LA CASE : \n");
    printf("COLONNE : \n");
    while ((column_choice >= col) || (column_choice < 0)){
      column_choice = protect_bug();
      column_choice--;
    }
    printf("LIGNE : \n");
    while ((line_choice >= lin) || (line_choice < 0)){
      line_choice= protect_bug();
      line_choice--;
    }
    printf("\033[H\033[2J");
    if (turn == 0){
      if (action_choice == 1){
        if (counter_flag >= 0){
          if (tab_player[column_choice][line_choice] != 'D'){
            counter_flag--;
            if (tab[column_choice][line_choice] == 'M'){
              nbmine--;
            }
          }    
        }
        if(nbmine == 0){
          t2 = tima(NULL);
          chrono = chrono + (t2 - t1);
          victory_animation();
          printf("\033[H\033[2J");
          p1_victory = 1;
        }
        else if(counter_flag == 0){
          printf("Tu as perdu joueur 1 ! \n");
          return_case = 12;
          return 12;
        }
        tab_player[column_choice][line_choice] ='D';
        if (p1_victory == 1 && p2_victory == 1){
          if (chrono_2 - chrono < 0){
            return_case = 4;
            return 4;
          }
          else if (chrono - chrono_2 < 0){
            return_case = 3;
            return 3;
          }
          else{
            return_case = 5;
            return 5;
          }
        }
        else if (p1_victory == 1){
          if (cases != 12 && cases != 3){
            t2 = tima(NULL);
            chrono = chrono + (t2 - t1);
            cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 1, chrono, chrono_2, p1_victory, p2_victory); 
          }
        }
        else if (p2_victory == 1){
          if (cases != 12 && cases != 3){
            t2 = tima(NULL);
            chrono = chrono + (t2 - t1);
            cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 0, chrono, chrono_2, p1_victory, p2_victory); 
          }
        }
        else {
          if (cases != 12 && cases != 3){
            t2 = tima(NULL);
            chrono = chrono + (t2 - t1);
            cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 1, chrono, chrono_2, p1_victory, p2_victory); 
          }
        }
        tab_player[column_choice][line_choice] ='D';
      }
      else { 
        if (tab[column_choice][line_choice] == 'M') {
          tab_player[column_choice][line_choice] = 'P';
          printf("\033[H\033[2J");
          printf("Tu as perdu joueur 1 ! \n");
          char chain [102];
          FILE *f_potato = NULL;
          f_potato = fopen("potato.txt", "r+");
          if (f_potato != NULL)
          {
            while (fgets(chain, 102, f_potato) != NULL) 
            {
              printf("%s", chain); 
            }
            fclose(f_potato);
          }
          sleep(10);
          printf("\033[H\033[2J");
          return_case = 12;
        }
        else {
          if(tab_player[column_choice][line_choice] == 'D'){
            counter_flag++;
          }
          if (tab[column_choice][line_choice] == '0') { 
            revelation_of_the_squares(column_choice, line_choice, col, lin, tab,tab_player);
          }
          else {
            tab_player[column_choice][line_choice] = tab[column_choice][line_choice];
          }
          int f_victory = victory_verification(total_mine, col, lin, tab_player);
          printf("f_victory : %d", f_victory);
          if (f_victory == 1){
            t2 = tima(NULL);
            chrono = chrono + (t2 - t1);
            victory_animation();
            printf("\033[H\033[2J");
            p1_victory = 1;
          }
          if (p1_victory == 1 && p2_victory == 1){
            if (chrono_2 - chrono < 0){
              return_case = 4;
              return 4;
            }
            else if (chrono - chrono_2 < 0){
              return_case = 3;
              return 3;
            }
            else{
              return_case = 5;
              return 5;
            }
          }
          else if (p1_victory == 1){
            if (cases != 12 && cases != 3){
              t2 = tima(NULL);
              chrono = chrono + (t2 - t1);
              cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 1, chrono, chrono_2, p1_victory, p2_victory); 
            }
          }
          else if (p2_victory == 1){
            if (cases != 12 && cases != 3){
              t2 = tima(NULL);
              chrono = chrono + (t2 - t1);
              cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 0, chrono, chrono_2, p1_victory, p2_victory); 
            }
          }
          else {
            if (cases != 12 && cases != 3){
              t2 = tima(NULL);
              chrono = chrono + (t2 - t1);
              cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 1, chrono, chrono_2, p1_victory, p2_victory); 
            }
          }
        }
      }
    }
    if (turn == 1){
      if (action_choice == 1){ 
        if (counter_flag_2 >= 0){
          if (tab_player_2[column_choice][line_choice] != 'D'){
            counter_flag_2--;
            tab_player_2[column_choice][line_choice] = 'D';
            if (tab_2[column_choice][line_choice] == 'M'){
                nbmine_2--;
            }
          }
          if(nbmine_2 == 0){
            t3 = tima(NULL);
            chrono_2 = chrono_2 + (float)(t3 - t1) / CLOCKS_PER_SEC;
            victory_animation();
            printf("\033[H\033[2J");
            p2_victory = 1;
          }
          else if(counter_flag_2 == 0){
            printf("Tu as perdu joueur 2 ! \n");
            return_case = 13;
            return 13;
          } 
          if (p1_victory == 1 && p2_victory == 1){
            if (chrono_2 - chrono < 0){
              return_case = 4;
              return 4;
            }
            else if (chrono - chrono_2 < 0){
              return_case = 3;
              return 3;
            }
            else{
              return_case = 5;
              return 5;
            }
          }
          else if (p1_victory == 1){
            if (cases != 12 && cases != 3){
              t3 = tima(NULL);
              chrono_2 = chrono_2 + (float)(t3 - t1) / CLOCKS_PER_SEC;
              cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 1, chrono, chrono_2, p1_victory, p2_victory); 
            }
          }
          else if (p2_victory == 1){
            if (cases != 12 && cases != 3){
              t3 = tima(NULL);
              chrono_2 = chrono_2 + (float)(t3 - t1) / CLOCKS_PER_SEC;
              cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 0, chrono, chrono_2, p1_victory, p2_victory); 
            }
          }
          else {
            if (cases != 12 && cases != 3){
              t3 = tima(NULL);
              chrono_2 = chrono_2 + (float)(t3 - t1) / CLOCKS_PER_SEC;
              cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 0, chrono, chrono_2, p1_victory, p2_victory); 
            }
          } 
        }
      }
      else {
        if (tab_2[column_choice][line_choice] == 'M') {
          tab_player_2[column_choice][line_choice] = 'P';
          printf("\033[H\033[2J");
          printf("Tu as perdu joueur 2 ! \n");
          char chain [102];
          FILE *f_potato = NULL;
          f_potato = fopen("potato.txt", "r+");
          if (f_potato != NULL)
          {
            while (fgets(chain, 102, f_potato) != NULL)
            {
              printf("%s", chain); 
            }
            fclose(f_potato);
          }
          sleep(10);
          printf("\033[H\033[2J");
          return_case = 13;
        }
        else {
          if(tab_player_2[column_choice][line_choice] == 'D'){
            counter_flag_2++;
          }
          if (tab_2[column_choice][line_choice] == '0') { // si c'est egal a 0:
            revelation_of_the_squares(column_choice, line_choice, col, lin, tab, tab_player_2);
          }
          else {
            tab_player_2[column_choice][line_choice] = tab_2[column_choice][line_choice];
          }
          int f_victory = victory_verification(total_mine_2, col, lin, tab_player_2);
          printf("f_victory : %d", f_victory);
          if (f_victory == 1){
            t3 = tima(NULL);
            chrono_2 = chrono_2 + (float)(t3 - t1) / CLOCKS_PER_SEC;
            victory_animation();
            printf("\033[H\033[2J");
            p2_victory = 1;
          }
          if (p1_victory == 1 && p2_victory == 1){
            if (chrono_2 - chrono < 0){
              return_case = 4;
              return 4;
            }
            else if (chrono - chrono_2 < 0){
              return_case = 3;
              return 3;
            }
            else{
              return_case = 5;
              return 5;
            }
          }
          else if (p1_victory == 1){
            if (cases != 12 && cases != 3){
              t3 = tima(NULL);
              chrono_2 = chrono_2 + (float)(t3 - t1) / CLOCKS_PER_SEC;
              cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 1, chrono, chrono_2, p1_victory, p2_victory); 
            }
          }
          else if (p2_victory == 1){
            if (cases != 12 && cases != 3){
              t3 = tima(NULL);
              chrono_2 = chrono_2 + (float)(t3 - t1) / CLOCKS_PER_SEC;
              cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 0, chrono, chrono_2, p1_victory, p2_victory); 
            }
          }
          else {
            if (cases != 12 && cases != 3){
              t3 = tima(NULL);
              chrono_2 = chrono_2 + (float)(t3 - t1) / CLOCKS_PER_SEC;
              cases = play_2(nbmine, nbmine_2, col, lin, tab, tab_2, tab_player, tab_player_2, 0, counter_flag, counter_flag_2, 0, chrono, chrono_2, p1_victory, p2_victory); 
            }
          }
        }
      }
    }  
  }  
  return cases;
}
