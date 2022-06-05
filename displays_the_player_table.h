/* displays_the_player_table : this function permit to display the player table.
col : the max number of columnes in the table.
lin : the max number of lines in the table.
tab_player[col][lin] : the table which contain the actual state of the game in the POV of the player.*/
void displays_the_player_table(int lin, int col, char tab_player[col][lin]) {
  int line = 0;
  int column = 0;
  for (int column = 0; column < col; column++){
      if (column < 9){
        printf("    %d", column+1);
      }
      else {
        printf("   %d", column+1);
      }
  }
  printf("\n");
  for (int line = 0; line < lin; line++) {
    if (line < 9) {
      printf("%d ", line + 1);
    }
    else {
      printf("%d", line + 1);
    }
    for (column; column < col; column++) {
      if (tab_player[column][line] != 'M') {
        if (tab_player[column][line] == '1') {
          printf(" |\033[32;01m%c\033[00m| ", tab_player[column][line]);
        }
        else if (tab_player[column][line] == '2') {
          printf(" |\033[34;01m%c\033[00m| ", tab_player[column][line]);
        }
        else if (tab_player[column][line] == '3') {
          printf(" |\033[33;01m%c\033[00m| ", tab_player[column][line]);
        }
        else if (tab_player[column][line] == '4') {
          printf(" |\033[33;01m%c\033[00m| ", tab_player[column][line]);
        }
        else {
          printf(" |\033[31;01m%c\033[00m| ", tab_player[column][line]);
        }
      }
      if (tab_player[column][line] == 'M') {
        printf(" |\033[41;01m%c\033[00m| ", tab_player[column][line]);
      }
    }
    printf("\n");
    column = 0;
  }
}
