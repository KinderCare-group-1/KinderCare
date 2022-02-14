#include <stdio.h>
#include <stdlib.h>
#include<winsock2.h>
#include<mysql.h>
#include<time.h>
#include<string.h>
#include "realletters.h"
#include "attemptAssignment.h"



MYSQL_RES *res;
MYSQL_RES *result;
MYSQL_ROW row;
MYSQL_ROW rows;
MYSQL *conn;


//MYSQL_FIELD col;

//#include "doAssignment.h"
char pupilStatus[50];
char lastName[50];
char firstName[50];
char UserCode[20];
char character[28];
char Real[5][5];
char Zero[5][5];

//#include "doAssignment.h"
////////FUNCTIONS!!!!!!!!////////

//FUNCTION TO CHECK FOR DATES WITHIN A SPECIFIED RANGE
 char from[50];
    char to[69];
void checkdates(){


    printf("Enter the date in this format YYYY-MM-DD eg.2022-02-02");
    printf("\nEnter the date from: ");
    scanf("%s",from);
    printf("\nEnter the date to: ");
    scanf("%s",to);
    fflush(stdin);
    char query[200];
    strcpy(query, "SELECT * FROM assignments WHERE Start_time BETWEEN \'");
    strcat(query,from);
    strcat(query, "\' AND \'");
    strcat(query,to);
    strcat(query, "\'");



    mysql_query(conn, query);
    printf("======================================================================================");
    printf("\nAssignment ID\t|\tStart Time\t|\tAssignment Name\t|\tStatus       |");
    printf("\n=====================================================================================\n");
    res = mysql_store_result(conn);
    while((row = mysql_fetch_row(res)) != NULL){
        printf("%s \t\t %s\t\t %s\t              %s\t\n", row[0],row[1],row[3], row[6]);
    }
     printf("\n=====================================================================================\n");



  viewCommands();


}


//END OF FUNCTION



//FUNCTION TO DO ASSIGNMENT
#include "doAssignment.h"

//END FUNCTION.....

//FUNCTION THAT CALLS COMMANDS
void viewCommands(){

   char command[100];
    if(strcmp(pupilStatus,"DEACTIVATED")==0){// deactivated pupil
    printf("\n\n");
   printf("*************This is the list of commands you can input at the prompt:************* \n");
   printf("1=> Viewall\n");
   printf("2=> Checkstatus\n");
   printf("3=> Viewassignment assignmentid\n");
   printf("4=> Checkdates datefrom dateto\n");
   printf("5=> RequestActivation\n");
   printf("\n\nEnter command here: ");
   gets(command);
   //scanf("%s", command);
   fflush(stdin);
   //COMMANDS
   if(strcmp(command, "Viewall" )==0){
      assignmentlist();
      printf("\n\n");
   }
     else if (strcmp(command, "Checkstatus" )==0){
      checkStatus();
      printf("\n\n");
   }

    else if(strcmp(command, "Viewassignment assignmentid" )==0) {
            assignmentDetails(UserCode);
            printf("\n\n");
    }
    else if(strcmp(command, "Checkdates datefrom dateto" )==0){
        checkdates();
        printf("\n\n");

    }
    else if(strcmp(command, "RequestActivation" )==0){
        activation(UserCode);
        printf("\n\n");
        //exit(1);
    }
   else {
   printf("Invalid command entered");
   }
    }else{// an active pupil
            printf("\n\n");
   printf("*************This is the list of commands you can input at the prompt:************* \n");
   printf("1=> Viewall\n");
   printf("2=> Checkstatus\n");
   printf("3=> Viewassignment assignmentid\n");
   printf("4=> Checkdates datefrom dateto\n");
   printf("\n\nEnter command here: ");
   gets(command);
   //scanf("%s", command);
   fflush(stdin);
   //COMMANDS
   if(strcmp(command, "Viewall" )==0){
      assignmentlist();
      printf("\n\n");
   }
     else if (strcmp(command, "Checkstatus" )==0){
      checkStatus();
      printf("\n\n");
   }

    else if(strcmp(command, "Viewassignment assignmentid" )==0) {
            assignmentDetails(UserCode);
            printf("\n\n");
    }
    else if(strcmp(command, "Checkdates datefrom dateto" )==0){
        checkdates();
        printf("\n\n");

    }
   else {
   printf("Invalid command entered");
   viewCommands();
   }
    }
}
//....END OF FUNCTION...



//FUNCTION TO VIEW ASSIGNMENTS..

#include "assignmentlist.h"


//END OF FUNCTION.....

//FUNCTION TO REQUEST FOR ACTIVATION..

#include "activation.h"
//END OF FUNCTION.......


//FUNCTION TO VIEW DETAILS OF AN ASSIGNMENT WHOSE ASSIGNMENT ID WAS ENTERED BY PUPIL ..
#include "assignmentDetails.h"
//END OF FUNCTION.......

//CHECK STATUS FUNCTION

#include "checkstatus.h"
//.....END OF FUNCTION.....




//LOGIN FUNCTION
void login(){
char user_code[20];
char password[20];
char querryy[2000];
printf("Enter your usercode: ");
scanf("%s", user_code);
fflush(stdin);
strcpy(querryy,"SELECT * FROM pupils WHERE user_code =\'");
        strcat(querryy, user_code);
         strcat(querryy,"\'");
    mysql_query(conn,querryy);


 res=mysql_store_result(conn);

 if(mysql_num_rows(res) > 0) {
        row = mysql_fetch_row(res);
        printf("Hello %s %s you have successfully logged in\n\n", row[1], row[2]);
        strcpy(UserCode, row[0]);

       strcpy(pupilStatus, row[4]);
        strcpy(UserCode, row[0]);
        strcpy(firstName, row[1]);
        strcpy(lastName, row[2]);


        viewCommands();



 }else {
     printf(" you have entered an invalid user code.\nPlease try again....\n\n\n\n");
     login();
 }



   mysql_free_result(res);

}


//END OF FUNCTION...............

int main()
{





conn = mysql_init(NULL);
conn = mysql_real_connect(conn,"localhost","root","","kinder_care",0,NULL,0);
    if(conn){
        login();
    }else{
        printf(" ! ERROR 567: FAILED TO CONNECT TO THE DATABASE.");
    }


    return 0;
}
