#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "PrintPIDStatus.h"
int status;
void PrintPIDStatus(pid_t pid);
int main(void)
{
  pid_t pid,wpid;
  char chaine[5];
  printf("PID = %ld", (long)getpid());
  PrintPIDStatus(getpid());

 if ((pid = fork()) == -1)
  {
    perror("fork () problem !!!");
    exit(EXIT_FAILURE);
  }if  ( pid !=0 ) { //père
        sleep(5);
	printf("\nPére : consultation de l'etat de mon fils...");
	printf("\nPére : avant wait()...");
        PrintPIDStatus(pid);
        printf("\nP  re : apres wait(...)");
	wpid = waitpid(pid,&status,0);
        PrintPIDStatus(pid);
	printf("\nPére : attente de saisie de chaine :");
	scanf("%s", chaine);
  } 
 

else { //fils
        printf("\nFils : consultation de l'etat du pere...");
	PrintPIDStatus(getppid());
	printf("\nFils : je me termine");    


 }
  exit(EXIT_SUCCESS);
}
