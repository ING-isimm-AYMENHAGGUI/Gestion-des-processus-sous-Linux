#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MaxJ 100000000

int status;
pid_t pidPere, pidFils, wpid;

int process_fils();
int process_pere();
int main() {

  printf("Main : Mon pid est %d\n", getpid());
  switch (pidFils=fork()) {
  case -1:
    perror("fork problem !!");
    exit(2);
    break;
  case 0: //pidFils == 0
    printf("Fils :\n\tMon pid est %d,\n\tle pid de mon pere est %d.\n",getpid(), getppid());
    process_fils();
    break;
  default: //pidFils > 0
    printf("Père :\n\tMon pid est %d,\n\tle pid de mon père est %d,\n \t le pid de mon fils est %d.\n",getppid(), getpid(), pidFils);
    process_pere();
    break;
  }
  return 0;
}

int process_fils() {
  //sleep(3);
  int i,j;
  for(i=0;i<13;i++){
    printf("\tFils \n");
    /* sleep(1); */
    for(j=0;j<MaxJ;j++){;}
  }
  exit(0);
}

int process_pere() {
  int i,j;
  for(i=0;i<10;i++){
    printf("Père \n");
    /* sleep(1); */
    for(j=0;j<MaxJ;j++){;}
  }
printf("Père : Synchronization sur la fin du processus fils \n");
wpid = waitpid(pidFils,&status,0);
printf("Père : Fin du processus fils de pid %d\n", wpid);
 
exit(0);
}
