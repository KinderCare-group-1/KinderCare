
void assignmentlist(){

    mysql_query(conn, "SELECT * FROM assignments where status = \'ACTIVE\'");
    res=mysql_store_result(conn);
    //int cols = mysql_num_fields(res);

        printf("\n\t\t\t\t\tASSIGNMENT LIST\n");
        printf("\t_________________________________________________________________________________________\n");
        printf("\t|ASSIGNMENT NO.\t\t|\tSTART Date\t\t|\t\tSTATUS\t\t|\n");
        printf("\t|_______________________|_______________________________|_______________________________|\n");
MYSQL_RES *ras;
       while ( (row=mysql_fetch_row(res))!= NULL){

                char *status;
               char *assID = row[0];
                char *StartDate = row[1];
                char did[200];
                        strcpy(did,"SELECT AssignmentID from scores where user_code=\'");
                        strcat(did,UserCode);
                        strcat(did, "\' AND AssignmentID = \'");
                        strcat(did,assID);
                        strcat(did,"\'");
                        mysql_query(conn,did);
                        ras=mysql_store_result(conn);

                       if( (rows=mysql_fetch_row(ras)) != NULL){
                        printf("\t\t%s \t\t\t%s\t\t ATTEMPTED \t\t\n", assID, StartDate);

                       }else{
                        printf("\t\t%s \t\t\t%s\t\t NOT ATTEMPTED \t\t\n", assID, StartDate);
                       }




   }
     printf("\t|_______________________________________________________________________________________|\n");
    viewCommands();
}
