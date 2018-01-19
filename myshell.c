#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


void printtime(void);


int main(){

char buf[50];
int i;
char *p;
char *array[10];

while(1){
    printtime();  //print the prompt
    fgets(buf, 200, stdin); //get user input
    size_t length = strlen(buf);
    if (buf[length-1] == '\n'){
        buf[length-1] = '\0'; //remove trailing newline
    }

    //break up the tokens and store pointers to them in "array"
    i=0;
    p=strtok(buf, " ");
    while(p!=NULL){
        array[i++] = p;
        p=strtok(NULL, " ");
    }

    //if the input is "exit", break the loop
    array[i] = NULL;
    if(strcmp(array[0], "exit")==0) break;

    //time to fork
    pid_t pid;   //used for child process
    pid_t w_pid; //used for waitpid
    int status;  //also used for waitpid
    pid = fork();
    if (pid==0){ //child process
        if (execvp(array[0],array)==-1){
       	    perror("Error");
            }
	exit(EXIT_FAILURE);
        }
    else if (pid<0){
        perror("Error forking");
        }
    else{
        //parent process
        w_pid=waitpid(pid, &status, WUNTRACED); //WUNTRACED waits until process is done or killed
        }
    }



return 0;
}


//function for printing the time 
void printtime(void){
   time_t traw;
   char time_string[15];
   struct tm *tlocal;
   time(&traw); //get raw time
   tlocal = localtime(&traw); //convert raw time into local time
   strftime(time_string,15,"%H:%M:%S# ",tlocal); //convert local time to a string
   printf("%s", time_string);
}

