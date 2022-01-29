#include <stdio.h>
#include <stdlib.h>
//Function for letter Q
void Q(){
    int i, j;
    for(i = 0; i < 7; i++){

        for(j = 0; j< 4; j++){
            if((i==0 && j ==1) || (i==0 && j ==2) || (i == 1 && j == 0) || (i == 1 && j == 3) || (i == 2 && j == 0) || (i == 2 && j == 3) || (i == 3 && j == 0) || (i == 3 && j == 3) || (i == 4 && j == 0) || (i == 4 && j == 1) || (i == 4 && j == 3) || (i == 5 && j == 1) || (i == 5 && j == 2) || (i == 6 && j == 3) ){

            printf(" * ");
            }
            else{
            printf("   ");
            }

        }
        printf("\n");
    }
}
//End of Q function


//Function for letter J
void J(){
    int i, j;//E
    for(i = 0; i < 7; i++){

        for(j = 0; j< 4; j++){
            if((i ==0&& j==0) ||(i==0 && j==1) ||(i==0 && j==3) || j==2 || (i==6 && j==0)||(i==6 && j==1)){

        printf(" * ");
            }else{
            printf("   ");
            }

        }
        printf("\n");
    }
}
//End of J function

//Function for letter D
void D(){
    int i, j;
    for(i = 0; i < 7; i++){

        for(j = 0; j<4; j++){
            if((i==1 && j==1) || (i==2 && j==2) || (i==3 && j==3) || j ==0 || (i==5 && j==3) || (i==6 && j==1)||(i==6 && j==2) ||(i==4 && j==3)){

        printf(" * ");
            }else{
            printf("   ");
            }

        }
        printf("\n");
    }

}
//End of D function

//Function for A

void A(){
int i, j;
for(i = 0; i < 7; i++)
{
    for(j = 0 ; j < 4; j++){
        if((i==0 && j ==1) || (i==0 && j ==2) || (i == 1 && j == 0) || (i == 1 && j == 3) || (i == 2 && j == 0) || (i == 2 && j == 3) || (i == 3 && j== 0) || (i == 3 && j== 1) || (i == 3 && j== 2) || (i == 3 && j== 3) || (i == 4 && j == 0) || (i == 4 && j == 3) || (i == 5 && j == 0) || (i == 5 && j == 3) || (i == 6 && j == 0) || (i == 6 && j == 3) ){
            printf(" * ");
        }
        else{
            printf("   ");
        }
    }
    printf("\n");


}
}
//End of A function


//FFunction for letter R
void R(){
    int i, j;
    for(i=0; i < 7; i++)
    {
        for(j=0; j < 4; j++){
            if((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 0 && j == 2) || (i == 1 && j == 0) || (i == 1 && j == 3) || (i == 2 && j == 0) || (i == 2 && j == 3) || (i == 3 && j == 0) || (i == 3 && j == 1) || (i == 3 && j == 2) || (i == 4 && j == 0) || (i == 4 && j == 1) || (i == 5 && j == 0) || (i == 5 && j == 2) || (i == 6 && j == 0) || (i == 6 && j == 3)){
                printf(" * ");
            }else {
                printf("   ");
            }
        }
        printf("\n");
    }

}
//End of function R


//Function for B
void B(){
int i, j;

for(i=0; i<7; i++){
    for(j=0; j < 4; j++){
        if((i == 0 && j == 0) || (i == 0 && j == 1) || (i == 0 && j == 2) || (i == 1 && j == 0) || (i == 1 && j == 3) || (i == 2 && j == 0) || (i == 2 && j == 3) || (i == 3 && j == 0) || (i == 3 && j == 1) || (i == 3 && j == 2) || (i == 4 && j == 0) || (i == 4 && j == 3) || (i == 5 && j == 0) ||(i == 5 && j == 3) || (i == 6 && j == 0) || (i == 6 && j == 1) || (i == 6 && j == 2)){
            printf(" * ");
        }else{
            printf("   ");
        }
    }
    printf("\n");
}


}
//End of B function

//Code for s

void s(){
    int i,j;
    for(i = 0; i < 7; i++){
        for(j=0; j < 4; j++){
            if((i==0 && j == 1) || (i==0 && j == 2) || (i==0 && j == 3) || (i == 1 && j == 0) || (i == 2 && j == 0) || (i == 3 && j == 1) || (i == 3 && j == 2) || (i == 4 && j == 3) || (i == 5 && j == 3) || (i == 6 && j == 0) || (i == 6 && j == 1) || (i == 6 && j == 2)){
                printf(" * ");
            }else
            {
                printf("   ");
            }
        }
        printf("\n");
    }


}



int main()
{

    //R();
   // printf("\n");
   //D();
   // printf("\n");
    //J();
  // printf("\n");
    //Q();

    //printf("\n");
    //A();

    B();
    return 0;
}
