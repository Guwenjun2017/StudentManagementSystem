#include "stu.h"

/*******************************************子菜单模块***************************************************/  
//成绩录入模块
void GradeInput()  
{  
    int choice;  
  
    while(1)  
    {  
	system("clear");
	printf(GREEN_COLOR,"\n------ Student store manage--------------\n");  
	printf(GREEN_COLOR,"-------1. Add student Grade----------------\n");  
	printf(GREEN_COLOR,"-------2. Modify student Grade-------------\n");  
	printf(GREEN_COLOR,"-------3. Delete student Grade-------------\n");  
	printf(GREEN_COLOR,"-------4. Searh_by_name--------------------\n");  
	printf(GREEN_COLOR,"-------0. Return to main-------------------\n");  
	printf(GREEN_COLOR,"-------Please choose(1 ~ 4), 0 to main:\n");  
	printf(">>>>>>>:");
	scanf("%d",&choice);  
	getchar();  
	switch(choice){  
	    case 1: Student_Insert(); break;  
	    case 2: Student_Modify(); break;  
	    case 3: Student_Delete(); break;  
	    case 4: Student_SelectByName(); break;  
	    case 0: return; break;  
	    default: printf(GREEN_COLOR,"It is an illegal option, and press Enter to choose again!\n");
	    getchar();
        }  
    }  

    return;
}  

//成绩统计模块
void GradeTongJi(){
    int choice;
    system("clear");

    while(1){
	printf(GREEN_COLOR,"\n|---------Achievement_Statistics-------------|\n");
	printf(GREEN_COLOR,"|      1 ---- Sort_by_ID                     |\n");
	printf(GREEN_COLOR,"|      2 ---- Sort_by_Average                |\n");
	printf(GREEN_COLOR,"|      3 ---- Statistical_franction_segment  |\n");
	printf(GREEN_COLOR,"|      0 ---- return to main                 |\n");
	printf(GREEN_COLOR,"|--------------------------------------------|\n");
	printf(GREEN_COLOR,"Please choose(1 ~ 3, 0 to main):\n");
	printf(">>>>>>>:");
	scanf("%d", &choice);
	getchar();
	switch(choice){
	    case 1: Student_SortByID(); break;
	    case 2: Student_SortByAverage(); break;
	    case 3: Student_Sort_EachSubject(); break;
	    case 0: return; break;
	    default: printf(GREEN_COLOR,"It is an illegal option, and press Enter to choose again!\n");
	    getchar();
	}
    }

    return;
}

//学籍处理
void Student_status_management(){
    int choice;
    system("clear");
    do{
	printf(GREEN_COLOR,"|---------------------------------------------------|\n");
	printf(GREEN_COLOR,"|      Student_status_management                    |\n");
	printf(GREEN_COLOR,"|---------------------------------------------------|\n");
	printf(GREEN_COLOR,"|      1 --- Generate and print notice of make-up   |\n");
	printf(GREEN_COLOR,"|      2 --- Generate and print withdrawal notice   |\n");
	printf(GREEN_COLOR,"|      3 --- Generate and print entry lists         |\n");
	printf(GREEN_COLOR,"|      0 --- return to main                         |\n");
	printf(GREEN_COLOR,"|---------------------------------------------------|\n");
	printf(GREEN_COLOR,"Please choose(1 ~ 3, 0 to main):\n");
	printf(YELLOW_COLOR,">>>>>>>:");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: print_information_bukao(); break;
	    case 2: print_information_tuixue(); break;
	    case 3: print_information_up(); break;
	    case 0: return; break;
	    default: printf(GREEN_COLOR,"It is an illegal option, and press Enter to choose again!\n");
	    getchar();
	}
    }while(1);
}

