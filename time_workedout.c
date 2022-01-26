#include<stdio.h>
#include<time.h>

int main(){
char letter[7][4];
char attempted_letter;
int number;

void funct(){
time_t t;
t = clock();
   printf("please enter the letter you are attempting:");
        scanf(" %c", &attempted_letter);


  for(int r = 0; r<7; r++)
  {

      for(int p = 0; p<4; p++){
            printf("please enter a 1 for a * or 0 for space for index[%d][%d]:", r,p);
            scanf("%d", &number);
            if(number == 1){
                letter[r][p] = '*';
            }else if(number == 0){
            letter[r][p]=' ';
            }else{
            printf("you entered a wrong number");
            }
      }

  }
  for(int t =0; t<7; t++){
    for(int y = 0; y<4; y++){
        printf("%c",letter[t][y]);
        printf(" ");
    }
    printf("\n");
  }

  t = clock() - t;

double time_taken = ((double)t)/CLOCKS_PER_SEC;

printf("The function took %f seconds to execute", time_taken);
}


funct();


return 0;

}
