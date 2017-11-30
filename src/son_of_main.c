#include "../inc/stu.h"
int passward = 201711;

//英文子菜单
/*******************************************子菜单模块***************************************************/  
//成绩录入模块
void GradeInput()  
{  
    //IO_ReadInfo();
    int choice;  
    int key;
  
    printf("please input your passward:");
    system("/bin/stty -echo");
    scanf("%d", &key);
    system("/bin/stty echo");
    if(key != passward){
	printf("Password error!");
	return;
    }
    while(1)  
    {  
	system("clear");
	printf(GREEN_COLOR,"\n------ Student store manage--------------\n");  
	printf(GREEN_COLOR,"-------1. Add student Grade----------------\n");  
	printf(GREEN_COLOR,"-------2. Modify student Grade-------------\n");  
	printf(GREEN_COLOR,"-------3. Delete student Grade-------------\n");  
	printf(GREEN_COLOR,"-------0. Return to main-------------------\n");  
	printf(GREEN_COLOR,"-------Please choose(1 ~ 4), 0 to main:\n");  
	printf(">>>>>>>:");
	scanf("%d",&choice);  
	getchar();  
	switch(choice){  
	    case 1: Student_Insert(); break;  
	    case 2: Student_Modify(); break;  
	    case 3: Student_Delete(); break;  
	    case 0: return;   
	    default: printf(GREEN_COLOR,"It is an illegal option, and press Enter to choose again!\n");
	    getchar();
        }  
    }  

    //IO_WriteInfo();
    return;
}  

//成绩查询
void GradeSearch(){
    int choice;     

    while(1){
	system("clear");
	printf(GREEN_COLOR,"\n------ Student Score Query--------------\n");  
	printf(GREEN_COLOR,"-------1. Searh_by_ID--------------------\n");  
	printf(GREEN_COLOR,"-------2. Searh_by_name--------------------\n");  
	printf(GREEN_COLOR,"-------0. Return to main-------------------\n");  
	printf(">>>>>>>:");
	scanf("%d", &choice);
	getchar();
	switch(choice){
	    case 1: Student_SelectByID(); break;  
	    case 2: Student_SelectByName(); break;  
	    case 0: return;   
	    default: printf(GREEN_COLOR,"It is an illegal option, and press Enter to choose again!\n");
	    getchar();
	}
    }
    return;
}
//成绩统计模块
void GradeTongJi(){
    //IO_ReadInfo();
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
    //IO_ReadInfo();
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

    return;
}


//中文子菜单
//成绩录入模块
void GradeInput_C()  
{  
    //IO_ReadInfo();
    int choice;  
    int key;
  
    printf("请输入您的密码:");
    system("/bin/stty -echo");
    scanf("%d", &key);
    system("/bin/stty echo");
    if(key != passward){
	printf(RED_COLOR,"密码错误!");
	return;
    }
    while(1)  
    {  
	system("clear");
	printf(GREEN_COLOR,"\n-----------学生成绩管理--------------\n");  
	printf(GREEN_COLOR,"-------1. 添加学生成绩\n");  
	printf(GREEN_COLOR,"-------2. 修改学生成绩\n");  
	printf(GREEN_COLOR,"-------3. 删除学生成绩\n");  
	printf(GREEN_COLOR,"-------0. 返回主菜单\n");  
	printf(GREEN_COLOR,"-------请选择(1 ~ 4), 0 返回主菜单:\n");  
	printf(">>>>>>>:");
	scanf("%d",&choice);  
	getchar();  
	switch(choice){  
	    case 1: Student_Insert_C(); break;  
	    case 2: Student_Modify_C(); break;  
	    case 3: Student_Delete_C(); break;  
	    case 0: return;   
	    default: printf(GREEN_COLOR,"您输入的是非法字符,请按任意键以重新输入.\n");
	    getchar();
        }  
    }  

    //IO_WriteInfo();
    return;
}  

//成绩查询
void GradeSearch_C(){
    int choice;     

    while(1){
	system("clear");
	printf(GREEN_COLOR,"\n-------- 学生成绩查询 ---------------\n");  
	printf(GREEN_COLOR,"-------1. 按学号查询-----------------\n");  
	printf(GREEN_COLOR,"-------2. 按姓名查询-----------------\n");  
	printf(GREEN_COLOR,"-------0. 返回主菜单-----------------\n");  
	printf(">>>>>>>:");
	scanf("%d", &choice);
	getchar();
	switch(choice){
	    case 1: Student_SelectByID_C(); break;  
	    case 2: Student_SelectByName_C(); break;  
	    case 0: return;   
	    default: printf(GREEN_COLOR,"您输入的是非法字符,请按任意键以重新输入.\n");
	    getchar();
	}
    }
    return;
}
//成绩统计模块
void GradeTongJi_C(){
    //IO_ReadInfo();
    int choice;
    system("clear");

    while(1){
	printf(GREEN_COLOR,"\n|----------------成绩统计--------------------|\n");
	printf(GREEN_COLOR,"|      1 ---- 按学号排序                     |\n");
	printf(GREEN_COLOR,"|      2 ---- 按平均分排序                   |\n");
	printf(GREEN_COLOR,"|      3 ---- 各科成绩段统计                 |\n");
	printf(GREEN_COLOR,"|      0 ---- 返回主菜单                     |\n");
	printf(GREEN_COLOR,"|--------------------------------------------|\n");
	printf(GREEN_COLOR,"请选择(1 ~ 3, 0 返回主菜单):\n");
	printf(">>>>>>>:");
	scanf("%d", &choice);
	getchar();
	switch(choice){
	    case 1: Student_SortByID_C(); break;
	    case 2: Student_SortByAverage_C(); break;
	    case 3: Student_Sort_EachSubject_C(); break;
	    case 0: return; break;
	    default: printf(GREEN_COLOR,"您输入的是非法字符,请按任意键以重新输入.\n");
	    getchar();
	}
    }

    return;
}

//学籍处理
void Student_status_management_C(){
    //IO_ReadInfo();
    int choice;
    system("clear");
    do{
	printf(GREEN_COLOR,"|---------------------------------------------------|\n");
	printf(GREEN_COLOR,"|                   学生学籍管理                    |\n");
	printf(GREEN_COLOR,"|---------------------------------------------------|\n");
	printf(GREEN_COLOR,"|      1 --- 统计并打印出补考学生信息               |\n");
	printf(GREEN_COLOR,"|      2 --- 统计并打印出退出学生信息               |\n");
	printf(GREEN_COLOR,"|      3 --- 统计并打印出升学学生名单               |\n");
	printf(GREEN_COLOR,"|      0 --- 返回主菜单                             |\n");
	printf(GREEN_COLOR,"|---------------------------------------------------|\n");
	printf(GREEN_COLOR,"请选择(1 ~ 3, 0 返回主菜单):\n");
	printf(YELLOW_COLOR,">>>>>>>:");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: print_information_bukao_C(); break;
	    case 2: print_information_tuixue_C(); break;
	    case 3: print_information_up_C(); break;
	    case 0: return; break;
	    default: printf(GREEN_COLOR,"您输入的是非法字符,请按任意键以重新输入.\n");
	    getchar();
	}
    }while(1);

    return;
}

