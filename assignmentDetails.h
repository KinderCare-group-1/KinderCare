void assignmentDetails(){

            printf("Enter assignment ID:");
        char assID[2];
        scanf("%s", assID);
        fflush(stdin);

         char query[255];
         strcpy(query, "SELECT * FROM assignments WHERE AssignmentID =");
         strcat(query,assID);

        mysql_query(conn,query);

        printf("\t\t\t\t\t\tTHESE ARE THE ASSIGNMENT DETAILS \n");
        printf("_________________________________________________________________________________________________________________________________________________\n");
        printf("|ASSIGNMENT NO.|\tSTART Date  |\tEND DATE \t  |ASSIGNMENT NAME|NUMBER OF CHARACTERS|   CHARACTER LIST            |      STATUS      |\n");
        printf("|______________|____________________|_____________________|_______________|____________________|___________________________|__________________|\n");

            res=mysql_use_result(conn);

            while((row=mysql_fetch_row(res))!=NULL ){

                printf("| \t%s\t%s   %s\t%s  \t    %s                 %s           %s    |", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
              printf("\n|_______________________________________________________________________________________________________________________________________|\n");
                 int r;
                 strcpy(character,row[5]);

            }

            char choice;

            printf("%s Would you like to attempt the assignment?\n", UserCode);
            printf("Enter \'Y\' to attempt assignment or any letter to exit: ");
            scanf("%c",&choice);
            fflush(stdin);


            if(choice == 'Y' || choice == 'y'){
                    if(strcmp(pupilStatus,"DEACTIVATED")==0){
                        printf("\nOops you can not attempt this assignment. You were deactivated by your teacher.\n");
                        printf("\nSend an Activation Request to be able to attempt the assignment\n");
                        viewCommands();
                    }else{
                        //CHECKING WHETHER THE ASSIGNMENT WAS ATTEMPTED OR NOT
                        char did[200];
                        strcpy(did,"SELECT AssignmentID from scores where user_code=\'");
                        strcat(did,UserCode);
                        strcat(did,"\' AND AssignmentID = \'");
                        strcat(did, assID);
                        strcat(did, "\'");
                        mysql_query(conn,did);
                        res=mysql_use_result(conn);


                      while((row=mysql_fetch_row(res)) != NULL){
                       printf("%s\n", *row);

                            if((strcmp(assID,*row)) == 0){
                              printf("\nYOU ALREADY ATTEMPTED THIS ASSIGNMENT.\n");
                              viewCommands();
                            }

                      }
                                 printf("YOU can attempt");
                                  doAssignment(character, assID);
                             viewCommands();


                }// end of else when the child is active
            }//end of the if when the pupil chooses not to attempt the assignment
            else{
               viewCommands();
            }



}
