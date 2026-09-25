#include <stdio.h>
#include <stdlib.h>
/* CMPUT 201 Student Submission License
Version 2.0

Copyright 2026 Ananya Tiwari

Unauthorized redistribution is forbidden under all circumstances. Use of this
software without explicit authorization from the author **and** the CMPUT 201
Instructor is prohibited.

This software was produced as a solution for an assignment or lab in the course
CMPUT 201 - Practical Programming Methodology at the University of
Alberta, Canada. This solution is confidential and remains confidential 
after it is submitted for grading. The course staff has the right to 
run plagiarism-detection tools on any code developed under this license, 
even beyond the duration of the course.

Copying any part of this solution without including this copyright notice
is illegal.

If any portion of this software is included in a solution submitted for
grading at an educational institution, the submitter will be subject to
the plagiarism sanctions at that institution.

This software cannot be publicly posted under any circumstances, whether by
the original student or by a third party.
If this software is found in any public website or public repository, the
person finding it is kindly requested to immediately report, including 
the URL or other repository locating information, to the following email
addresses:

          hktang@ualberta.ca
*/

/* Name: Ananya Tiwari
   CCID: atiwari5
   lecture section: CMPUT 201 - LEC A2 - 51541
   Instructor's name: Henry TAng
   Lab section: CMPUT 201 - LAB D01 - 52381*/
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
