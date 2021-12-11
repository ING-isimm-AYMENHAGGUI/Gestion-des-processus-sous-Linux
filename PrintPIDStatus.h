void PrintPIDStatus (pid_t pid)
{
  FILE * fp;
  char   StatPath[20];
  char   StatMsg[20];
  sprintf(StatPath, "/proc/%ld/status", (long) pid);
  if ((fp = fopen(StatPath, "r")) == NULL) {
    printf("\t==>Processus(%d) inexistant", pid);
    return;
  }
  while (fgets(StatMsg, 20, fp) != NULL)
    if (strncmp(StatMsg, "State", 5) == 0) {
      printf("\t==>Etat process(%d) : %s",pid, &StatMsg[7]);
      break;
    }
  fclose(fp);
}
