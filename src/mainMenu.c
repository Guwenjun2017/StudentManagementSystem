#include "../inc/stu.h"
  
/*********************************************主模块****************************************************/
//English menu
int mainMenu()
{
    int choice;
    IO_ReadInfo();
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
	printf(GREEN_COLOR,"                |      2 ---- Score query                     |\n");
	printf(GREEN_COLOR,"                |      3 ---- Achievement statistics          |\n");
	printf(GREEN_COLOR,"                |      4 ---- Student status management       |\n");
	printf(GREEN_COLOR,"                |      0 ---- Exit                            |\n");
	printf(GREEN_COLOR,"                |---------------------------------------------|\n");
	printf(GREEN_COLOR,"                Please choose(1 ~ 3, 0: exit):\n");
	printf(YELLOW_COLOR,">>>>>>>>>>>>>>>:");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: GradeInput(); break;
	    case 2: GradeSearch(); break;
	    case 3: GradeTongJi(); break;
	    case 4: Student_status_management(); break;
	    case 0: printf(YELLOW_COLOR,"-----------------------THANK YOU FOR YOUR USING!---------------------------\n");
		    exit(0);
	    default: printf(RED_COLOR,"It is an illegal option, and press any key to choose again!\n");
	    getchar();
	    getchar();
	}
    }while(1);

    IO_WriteInfo();
    return 0;

}

//中文菜单
int mainMenu_C()
{
    int choice;
    IO_ReadInfo();
    do{
	//system("sl");
	//system("sh do.sh");
	system("clear");
	int a = 0;
	a++;
	if(a == 1){
	    printf(YELLOW_COLOR,"----------------------欢迎使用学生成绩与学籍管理系统-----------------------\n");
	}
	printf(GREEN_COLOR,"                |---------------------------------------------|\n");
	printf(GREEN_COLOR,"                |                  主菜单                     |\n");
	printf(GREEN_COLOR,"                |---------------------------------------------|\n");
	printf(GREEN_COLOR,"                |      1 ---- 成绩录入与删改                  |\n");
	printf(GREEN_COLOR,"                |      2 ---- 成绩查询                        |\n");
	printf(GREEN_COLOR,"                |      3 ---- 成绩统计                        |\n");
	printf(GREEN_COLOR,"                |      4 ---- 学籍管理                        |\n");
	printf(GREEN_COLOR,"                |      0 ---- 退出                            |\n");
	printf(GREEN_COLOR,"                |---------------------------------------------|\n");
	printf(GREEN_COLOR,"                请选择(1 ~ 3, 0: exit):\n");
	printf(YELLOW_COLOR,">>>>>>>>>>>>>>>:");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: GradeInput_C(); break;
	    case 2: GradeSearch_C(); break;
	    case 3: GradeTongJi_C(); break;
	    case 4: Student_status_management_C(); break;
	    case 0: printf(YELLOW_COLOR,"-----------------------感谢您的使用!---------------------------------------\n");
		    exit(0);
	    default: printf(RED_COLOR,"您输入的非法字符,请按任意键以再次选择.\n");
	    getchar();
	    getchar();
	}
    }while(1);

    IO_WriteInfo();
    return 0;
}
