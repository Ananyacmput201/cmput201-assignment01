#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp = fopen(argv[1], "r");
  int coount;
  char line[100];
  
  coount = 0;
  while (fgets(line, 100, fp) != NULL){
    coount++ ;
  }  
  printf("Processing %d schedule files...\n",coount);
			
  fclose(fp);

  FILE *fopn = fopen(argv[1], "r");
  char linee[100];
  int j = 0;
  while (fgets(linee, 100, fopn) != NULL){
    j++;
    int i = 0;
    char lette = 'A';
    char direction;
    for (; linee[i] != '\0'; i++) {
      if (linee[i] == '\n'){
      linee[i] = '\0';
      }
      if (linee[i] == 'X'){
	lette = linee[i];
      }
      if (linee[i] == 'E' || linee[i] == 'W' || linee[i] == 'N' || linee[i] == 'S'){
	direction = linee[i];
	      }
    }
    
    FILE *fop = fopen(linee, "r");
    int stop_id;
    int num_stop;
    char stop[50];
    
    fscanf(fop, "%d %s %d",&stop_id, stop, &num_stop);
    
    if (lette =='X'){  
      printf("schedule #%d is route %d%c it has %d stops and is in the %c direction\n",j, stop_id,lette, num_stop, direction);
    }
    else{
      printf("schedule #%d is route %d it has %d stops and is in the %c direction\n",j, stop_id, num_stop, direction);
    }
    fclose(fop);
  }

      fclose(fopn);
      return 0;
}
