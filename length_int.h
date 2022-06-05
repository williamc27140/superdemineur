/*length_int : this function is use to know how many number are present in a number.
number : the number we want to know the lengh(it comes from the display_best_score fonction.
it return res, res is the number of diggits in number.*/
int length_int(int number){
  int res = 0;
  while (number / 10 !=0){
    res++;
    number = number / 10;
  }
  return res;
}