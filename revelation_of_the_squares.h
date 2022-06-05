/*revelation_of_the_squares : this function is used to show to the player the cases he want to reveal
col : the coordinates chosen for the column
lin : the coordinates chosen for the line
COL :  the max number of columnes in the table.
LIN : the max number of lines in the table.
tab[col][lin] : the table which contains information of bomb and number of bombs around a case.
tab_player[col][lin] : the table which is use by the player when he plant or dig in a case.
*/
void revelation_of_the_squares(int col, int lin, int COL, int LIN,char tab[COL][LIN], char tab_player[COL][LIN]) {
  tab_player[col][lin] = ' ';
  tab[col][lin] = ' ';
  int imin = 0;
  int jmin = 0;
  int imax = 3;
  int jmax = 3;
  if (lin <= 0) {
    jmin = 1;
  }
  else if (lin >= LIN - 1) {
    jmax = 2;
  }
  if (col <= 0) {
    imin = 1;
  }
  else if (col >= COL - 1) {
    imax = 2;
  }
  for (int i = imin; i < imax; i++) {  
    for (int j = jmin; j < jmax; j++) {
      tab_player[col - 1 + i][lin - 1 + j] = tab[col - 1 + i][lin - 1 + j];
      if (tab[col - 1 + i][lin - 1 + j] == 48) {
        revelation_of_the_squares(col - 1 + i, lin - 1 + j, COL, LIN, tab,tab_player);
      }
    }
  }
}