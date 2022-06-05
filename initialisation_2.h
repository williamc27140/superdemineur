/*this function initialise table of each player by placing bombs at the position wanted by the other player. each player chose the position in turn. it also put the number of bombs next to a case in the end of the function by the verification function
nbmine and nbmine_2 : the number of mines which are suppose to be in 
col : the max number of columnes in the table.
lin : the max number of lines in the table.
tab[col][lin] tab_2[col][lin]: the table which contains information of bomb and number of bombs around a case.*/
void initialisation_2(int nbmine, int nbmine_2, int col, int lin,char tab[col][lin], char tab_2[col][lin]) {
  int line = 0;
  int column = 0;
  for (int line = 0; line < lin; line++) {
    for (column; column < col; column++) {
      tab[column][line] = '-';
      tab_2[column][line] = '-';
    }
    printf("\n");
    column = 0;
  }
  column = 0;
  while (nbmine > 0 && nbmine_2 > 0) { // tant que le number de mines n'a pas ete depense...
      for (int i = 0; i < 2; i++){
          if (i == 0){
            printf("joueur 1 :\n");
            displays_the_player_table(lin, col, tab);
          }
          if (i == 1){
            printf("joueur 2 :\n");
            displays_the_player_table(lin, col, tab_2);
          }
          int choice_column = col + 1;
          int choice_line = lin + 1;
          while (choice_column >= col){
            printf("veuillez choisir une colonne : ");
            choice_column = protect_bug()-1;
          }
          while (choice_line >= lin){
              printf("veuillez choisir une line : ");
              choice_line = protect_bug()-1;
          }
          if (i == 0){
            if (tab[choice_column][choice_line] != 'M') {
            tab[choice_column][choice_line] = 'M';
            nbmine--;
            }
          }
          else if (i == 1){
            if (tab_2[choice_column][choice_line] != 'M') {
            tab_2[choice_column][choice_line] = 'M';
            nbmine_2--;
            }
          }
        printf("\033[H\033[2J");
      }
      
  }
  for (int line = 0; line < lin; line++) {
    for (column; column < col; column++) {
      tab[column][line] = verification(column, line, col, lin, tab) + 48;
      tab_2[column][line] = verification(column, line, col, lin, tab_2) + 48;
    }
    column = 0;
  }
}