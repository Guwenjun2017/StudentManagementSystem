#include "stu.h"
  
/*********************************************主模块****************************************************/
int mainMenu()
{
    int choice;
    do{
	//system("sl");
	//system("sh do.sh");
	system("clear");
	int a = 0;
	a++;
	if(a == 1){
	    printf(YELLOW_COLOR,"----------------------WELCOME TO StudentManagementSystem-------------------\n");
	}
	printf(GREEN_COLOR,"                |---------------------------------------------|\n");
	printf(GREEN_COLOR,"                |                 main                        |\n");
	printf(GREEN_COLOR,"                |---------------------------------------------|\n");
	printf(GREEN_COLOR,"                |      1 ---- Result input                    |\n");
	printf(GREEN_COLOR,"                |      2 ---- Achievement statistics          |\n");
	printf(GREEN_COLOR,"                |      3 ---- Student status management       |\n");
	printf(GREEN_COLOR,"                |      0 ---- Exit                            |\n");
	printf(GREEN_COLOR,"                |---------------------------------------------|\n");
	printf(GREEN_COLOR,"                Please choose(1 ~ 3, 0: exit):\n");
	printf(YELLOW_COLOR,">>>>>>>>>>>>>>>:");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: GradeInput(); break;
	    case 2: GradeTongJi(); break;
	    case 3: Student_status_management(); break;
	    case 0: printf(YELLOW_COLOR,"-----------------------THANK YOU FOR YOUR USING!---------------------------\n");
		    exit(0);
	    default: printf(RED_COLOR,"It is an illegal option, and press any key to choose again!\n");
	    getchar();
	    getchar();
	}
    }while(1);

    return 0;

}
