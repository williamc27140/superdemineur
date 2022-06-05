/*intitialisation_tab_player : this function generates the graphical user interface of the player. It use the tab_player[col][lin] to create his default graphical configuration
col : the max number of columnes in the table.
lin : the max number of lines in the table.
tab_player[col][lin] : the table which contain after this function the "-" usefull for a good presentation.*/
void initialisation_tab_player(int col, int lin, char tab_player[col][lin]) {
  int line = 0;
  int column = 0;
  for (int line = 0; line < lin; line++) {
    for (column; column < col; column++) {
      tab_player[column][line] = '-';
    }
    printf("\n");
    column = 0;
  }
}