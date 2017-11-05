#include <stdio.h>
#include <stdlib.h>
#include "stu.h"
  
/*********************************************主模块****************************************************/
int main(int argc, char **argv)
{
    int choice;
    IO_ReadInfo();
    do{
	printf("|---------------------------------------------|\n");
	printf("|                 main                        |\n");
	printf("|---------------------------------------------|\n");
	printf("|      1 ---- Result input                    |\n");
	printf("|      2 ---- Achievement statistics          |\n");
	printf("|      3 ---- Student status management       |\n");
	printf("|      0 ---- Exit                            |\n");
	printf("|---------------------------------------------|\n");
	printf("Please choose(1 ~ 3, 0 exit):\n");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: GradeInput(); break;
	    case 2: GradeTongJi(); break;
	    case 3: Student_status_management(); break;
	    case 0: exit(0);
	    default: printf("%d is an illegal option, and press any key to choose again!\n", choice);
	    getchar();
	    getchar();
	}
    }while(1);

    return 0;
}
