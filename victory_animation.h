/*victory_animation : this function show a little animation of "victory"*/
void victory_animation(){
  srand(time(NULL));
  int color;
  int random_color = rand()%5+1;  
  if(random_color == 5){
    color = 7;
  }
  else{
    color = random_color;
  }
  for (int i = 0; i < 77; i++){
    printf("\033[3%d;01m_\033[00m", color);
  }
  printf("\n");
  char chain [78];
  FILE *f_victory = NULL;
  f_victory = fopen("f_victory.txt", "r+");
  if (f_victory != NULL){
    while (fgets(chain, 78, f_victory) != NULL) {
      printf("\033[3%d;01m%s\033[00m", color, chain); 
    }
    fclose(f_victory);
  }
  for (int j = 0; j < 77; j++){
    printf("\033[3%d;01m_\033[00m", color);
  
  }
  printf("\n"); 
}