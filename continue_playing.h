/*continue_playing : this function ask the user to choose between continue or left the entire game.
it is linked to the main function
it have no argument and return nothing. this function is base on the protect_bug function.*/
void continue_playing(){
  printf("\033[H\033[2J");
  printf("________________________________________________\n");
  printf("        VOULEZ-VOUS CONTINUER A JOUER ?\n");
  printf("     |1|                                |2|\n");
  printf("     OUI                                NON\n");
  printf("________________________________________________\n");
  int choice = 0;
  while ((choice != 1) || (choice != 2)) {
    printf("CHOIX :");
    choice = protect_bug();
    if ((choice == 1) || (choice == 2)) {
      break;
    }
  }
  if(choice == 1){
    main();
  }
  if(choice == 0){
    exit(1);
  }
}