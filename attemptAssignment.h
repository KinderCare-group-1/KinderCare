
char One[5][5];
char Zero[5][5];
float sum = 0.0;
float Attempt_Assignment(){

int m, n;
time_t t;

    t=clock();
       for(m=0; m<5; m++){

            for(n=0; n<5; n++){

                printf("\nEnter either zero(0) or one (1) at row %d column %d:", (m+1), (n+1));
                scanf("%d", &One[m][n]);
            }
        }
        //PRINTNG THE PUPIL'S ATTEMPT.

         printf("\nYOUR ATTEMPT:\n");
        for(m=0; m<5; m++){

            for(n=0; n<5; n++){

               if(One[m][n]==1){
                    Zero[m][n]='*';
                printf(" %c ",Zero[m][n]);
               }else {
                  Zero[m][n]=' ';
               printf(" %c ", Zero[m][n]);
               }

            }
            printf("\n");
        }
          t=clock()-t;
    double time_taken=((double)t)/CLOCKS_PER_SEC;
    printf("\n\tTIME TAKEN TO ATTEMPT CHARACTER = %.3f seconds\n",time_taken);

   sum += time_taken;
   return sum;

}
//END OF FUNCTION.....
