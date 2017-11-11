#include "stu.h"
  
/*********************************************主模块****************************************************/
int mainMenu()
{
    int choice;
    IO_ReadInfo();
    do{
	//system("sl");
	//system("sh do.sh");
	system("clear");
	printf("\e[32m\e[1m%s\e[0m","|---------------------------------------------|\n");
	printf("\e[32m\e[1m%s\e[0m","|                 main                        |\n");
	printf("\e[32m\e[1m%s\e[0m","|---------------------------------------------|\n");
	printf("\e[32m\e[1m%s\e[0m","|      1 ---- Result input                    |\n");
	printf("\e[32m\e[1m%s\e[0m","|      2 ---- Achievement statistics          |\n");
	printf("\e[32m\e[1m%s\e[0m","|      3 ---- Student status management       |\n");
	printf("\e[32m\e[1m%s\e[0m","|      0 ---- Exit                            |\n");
	printf("\e[32m\e[1m%s\e[0m","|---------------------------------------------|\n");
	printf("\e[32m\e[1m%s\e[0m","Please choose(1 ~ 3, 0 exit):\n");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: GradeInput(); break;
	    case 2: GradeTongJi(); break;
	    case 3: Student_status_management(); break;
	    case 0: exit(0);
	    default: printf("\e[31m\e[1m%s\e[0m","It is an illegal option, and press any key to choose again!\n");
	    getchar();
	    getchar();
	}
    }while(1);

    return 0;
}
