/*protect_bug : this fonction is use to prevent every error of the user. we use a char instead of an integer because we must suppose that user can write some letters even if we ask for some diggits
this function has no argument but return an integer value (only 2 diggits) of the scanf %s*/
int protect_bug (){
  char size_board[12] = {0};
  int unit = 0;
  int result;
  while (unit == 0) {
    scanf("%11s", size_board);
    for (int i = 0 ; i < 9 ; i++){
      if ( (size_board[i] < 58) && (size_board[i] > 48) ){
        unit = 1;
        break;
      }
    }
  }
  sscanf(size_board, "%2d", &result);
  if (result < 0){
    result = result - 2 * result;
  }
  return result;
}