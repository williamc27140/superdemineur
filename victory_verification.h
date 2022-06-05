/*victory_verification : this variable tel if all the case (except flags) of a table  is discovery. it's a specificely winning condition
nbmine : the number of mines which are unknown to the playerin the table
col : the max number of columnes in the table.
lin : the max number of lines in the table.
tab_player[col][lin] : the table which is use by the player when he plant or dig in a case.*/
int victory_verification(int nbmine, int col, int lin, char tab_player[col][lin]){
  int size_board = col * lin;
  int number_of_squares_without_mines = size_board - nbmine;
  int verification_square = 0;
  for ( int i = 0; i < lin; i++){
    for (int j = 0; j < col; j++){
      if (tab_player[i][j]  != '-'){
        verification_square ++;
      }
    }
  }
  if (number_of_squares_without_mines <= verification_square){
    return 1;
  }
  else{
    return 0;
  }
}