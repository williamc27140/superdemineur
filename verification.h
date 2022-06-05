/* this function return how many bombs are near the tab[col][lin] case
col : the coordinates chosen for the column
lin : the coordinates chosen for the line
COL :  the max number of columnes in the table.
LIN : the max number of lines in the table.
tab[col][lin] : the table which contains information of bomb and number of bombs around a case.*/
int verification(int col, int lin, int COL, int LIN, char tab[COL][LIN]) { 
  int counter_mine = 0;
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
      if (tab[col - 1 + i][lin - 1 + j] == 'M') {
        counter_mine++;
      }
    }
  }
  if (tab[col][lin] == 'M') {
    return 29;
  }
  else {
    return counter_mine;
  }
}