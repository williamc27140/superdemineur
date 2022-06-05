/*display_best_score : this function is use to display all best score and pseudos from level beginner and intermediate.
start_name and start_score : use to manage beginner part of this function.
inter_name and inter_score : use to manage intermediate part of this function.
the most difficult part of this function is to adapt the number of space to match the presentation we made this with the second "for" loop.*/
void display_best_score(char start_name[2][10], char inter_name[2][10], int start_score[3], int inter_score[3]){
  printf("__________________MEILLEUR SCORE_______________\n");
  printf("|debutant|                           |intermediaire|\n");
  for (int i = 0; i < 3; i++){
    printf("%s : %.3f                    ", &start_name[i][10], ((float)start_score[i]) / 1000);
    for (int j = 0 ; j < ((9-strlen(start_name[i+1]))+ (4-length_int(start_score[i])))-1 ; j++){
      printf(" ");
    }
    printf("%s : %.3f\n", &inter_name[i][10], ((float)inter_score[i]) / 1000);
  }
  printf("________________________________________________\n");
}