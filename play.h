/*play : this function is use to choose between plant a flag of dig a case.  it permit to know if the player have win or loose. this function manage the player table.
nbmine : the number of mines which are unknown to the playerin the table
col : the max number of columnes in the table.
lin : the max number of lines in the table.
tab[col][lin] : the table which contains information of bomb and number of bombs around a case.
tab_player[col][lin] : the table which is use by the player when he plant or dig in a case.
cases : the main variable which return to the main function if the player win, loose or not.
counter_flag : this variable permit to know how many flag is still available to be plant.
the recursivity of this function is the most complexe part which need the global variable return_case. whithout this one, we can't bring the information of a win or a loose to the main program.*/
int play(int nbmine, int col, int lin, char tab[col][lin],char tab_player[col][lin], int cases, int counter_flag) {
  int column_choice = col + 1;
  int line_choice= col + 1;
  int action_choice;
  int mines_total = nbmine;
  time_t t2;//initlisation of the time.

  displays_the_player_table(lin, col, tab_player);
  if (cases == 0){
    printf("____________________________________________________________________\n");
    printf("|poser un drapeau|                                         |creuser|\n");
    printf("|    1           |                                         |    2  |\n");
    printf("____________________________________________________________________\n");
    action_choice = 5;
    while ((action_choice != 1) || (action_choice != 2)) {
      printf("choix action (1 ou 2):");
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
    if (action_choice == 1){
      if (counter_flag >= 0){
        if (tab_player[column_choice][line_choice] != 'D'){
          counter_flag--;
          tab_player[column_choice][line_choice] = 'D';
          if (tab[column_choice][line_choice] == 'M'){
            nbmine--;
          }
        }
        if(nbmine == 0){
          t2 = time(NULL);
          victory_animation();
          return_case = 2;
          return 2;
        }
        else if(counter_flag == 0){
          return_case = 11;
          return 11; 
        }
        if (cases != 11 && cases != 2){
          cases = play(nbmine, col, lin, tab, tab_player, 0, counter_flag); 
        }      
      }
    }
    else { 
      if (tab[column_choice][line_choice] == 'M') {
        tab_player[column_choice][line_choice] = 'P';
        printf("\033[H\033[2J");
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
        printf("VOUS AVEZ PERDU CAR UNE BOMBE A ETE DECOUVERTE\n");
        return_case = 11;
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
        int f_victory = victory_verification(mines_total, col, lin, tab_player);
        if (f_victory == 1){
          t2 = time(NULL);
          victory_animation();
          return_case = 2;
          return 2;
        }
        cases = play(nbmine, col, lin, tab, tab_player, 0, counter_flag);
      }
    }
  }  
  return cases;
}