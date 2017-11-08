#include "stu.h"

/*******************************************子菜单模块***************************************************/  
//成绩录入模块
void GradeInput()  
{  
    system("clear");
    int choice;  
  
    IO_ReadInfo();  
    while(1)  
    {  
        printf("\e[32m\e[1m%s\e[0m","\n------ Student store manage------\n");  
        printf("\e[32m\e[1m%s\e[0m","1. Add student Grade\n");  
        printf("\e[32m\e[1m%s\e[0m","2. Modify student Grade\n");  
        printf("\e[32m\e[1m%s\e[0m","3. Delete student Grade\n");  
        printf("\e[32m\e[1m%s\e[0m","4. Searh_by_name\n");  
        printf("\e[32m\e[1m%s\e[0m","0. Return to main\n");  
        printf("\e[32m\e[1m%s\e[0m","Please choose(1 ~ 4), 0 to main:\n");  
        scanf("%d",&choice);  
        getchar();  
        switch(choice){  
	    case 1: Student_Insert(); break;  
	    case 2: Student_Modify(); break;  
	    case 3: Student_Delete(); break;  
	    case 4: Student_Select(); break;  
	    case 0: return; break;  
	    default: printf("\e[31m\e[1m%s\e[0m","It is an illegal option, and press any key to choose again!\n");
	    getchar();
	    getchar();
        }  
        IO_WriteInfo();  
    }  

    return;
}  

//成绩统计模块
void GradeTongJi(){
    system("clear");
    int choice;

    //IO_ReadInfo();
    while(1){
	printf("\e[32m\e[1m%s\e[0m","\n|---------Achievement_Statistics-------------|\n");
	printf("\e[32m\e[1m%s\e[0m","|      1 ---- Sort_by_ID                     |\n");
	printf("\e[32m\e[1m%s\e[0m","|      2 ---- Sort_by_Average                |\n");
	printf("\e[32m\e[1m%s\e[0m","|      3 ---- Statistical_franction_segment  |\n");
	printf("\e[32m\e[1m%s\e[0m","|      0 ---- return to main                 |\n");
	printf("\e[32m\e[1m%s\e[0m","|--------------------------------------------|\n");
	printf("\e[32m\e[1m%s\e[0m","Please choose(1 ~ 3, 0 to main):\n");
	scanf("%d", &choice);
	getchar();
	switch(choice){
	    case 1: Student_SortByID(); break;
	    case 2: Student_SortByAverage(); break;
	    case 3: Student_Sort_EachSubject(); break;
	    case 0: return; break;
	    default: printf("\e[31m\e[1m%s\e[0m","It is an illegal option, and press any key to choose again!\n");
	    getchar();
	    getchar();
	}
	IO_WriteInfo();
    }

    return;
}

//学籍处理
void Student_status_management(){
    system("clear");
    int choice;
    do{
	printf("\e[32m\e[1m%s\e[0m","|---------------------------------------------------|\n");
	printf("\e[32m\e[1m%s\e[0m","|      Student_status_management                    |\n");
	printf("\e[32m\e[1m%s\e[0m","|---------------------------------------------------|\n");
	printf("\e[32m\e[1m%s\e[0m","|      1 --- Generate and print notice of make-up   |\n");
	printf("\e[32m\e[1m%s\e[0m","|      2 --- Generate and print withdrawal notice   |\n");
	printf("\e[32m\e[1m%s\e[0m","|      3 --- Generate and print entry lists         |\n");
	printf("\e[32m\e[1m%s\e[0m","|      0 --- return to main                         |\n");
	printf("\e[32m\e[1m%s\e[0m","|---------------------------------------------------|\n");
	printf("\e[32m\e[1m%s\e[0m","Please choose(1 ~ 3, 0 to main):\n");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: print_information_bukao(); break;
	    case 2: print_information_tuixue(); break;
	    case 3: print_information_up(); break;
	    case 0: return; break;
	    default: printf("\e[31m\e[1m%s\e[0m","It is an illegal option, and press any key to choose again!\n");
	    getchar();
	    getchar();
	}
    }while(1);
}

