/*initialisation_tab_player_2 : this function generates the graphical user interface of the 2 players. It use the tab_player_2[col][lin] to create his default graphical configuration
col : the max number of columnes in the table.
lin : the max number of lines in the table.
tab_player[col][lin] and tab_player_2[col][lin] : the table which contain after this function the "-" usefull for a good presentation.*/
void initialisation_tab_player_2(int col, int lin,char tab_player[col][lin], char tab_player_2[col][lin]){
  int line = 0;
  int column = 0;
  for (int line = 0; line < lin; line++) {
    for (column; column < col; column++) {
      tab_player[column][line] = '-';
      tab_player_2[column][line] = '-';
    }
    printf("\n");
    column = 0;
  }
}