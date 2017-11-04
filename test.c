#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operate.h"

void addRecord(){
    Student *list;
    int choice;
    do{
	init_student_info_list();
	printf("1.添加学生信息.\n");
	printf("2.输出平均成绩.\n");
	printf("3.输出学生信息.\n");
	printf("0.退出系统操作.\n");
        printf("请选择操作: ");
        scanf("%d",&choice);
	init_student_info_list();
        switch(choice)
        {
	    case 1: add_student_info(); break;
	    case 2: display_average(); break;
	    case 3: display_student_info(); break;
	    case 0: return;
	    default: printf("请重新选择.\n");
	    getchar();
	    getchar();
	}
    }while(1);

    return;
}

/*******************************************成绩统计模块************************************************/
void Achievement_statistics(){
    int choice;
    do{
	printf("|-----------------------------------------|\n");
	printf("|       请输入选项编号(0 ~ 3):            |\n");
	printf("|-----------------------------------------|\n");
	printf("|     1 ---- 按学号排序                   |\n");
	printf("|     2 ---- 计算平均分并排序             |\n");
	printf("|     3 ---- 统计分数段                   |\n");
	printf("|     0 ---- 返回主菜单                   |\n");
	printf("|-----------------------------------------|\n");
	scanf("%d", &choice);
	switch(choice)
	{
	    //case 1: sort(); break;
	    //case 2: sort(); break;
	    //case 3: sort(); break;
	    case 0: return;
	    default: printf("%d是非法选项,按任意建后重新选择!\n", choice);
	    getchar();
	    getchar();
	}
    }while(1);

    return;
}

/*******************************************学籍管理模块************************************************/
void School(){
    int choice;
    do{
	printf("|-----------------------------------------|\n");
	printf("|       请输入选项编号(0 ~ 3):            |\n");
	printf("|-----------------------------------------|\n");
	printf("|      1 ---- 生成并打印补考通知单        |\n");
	printf("|      2 ---- 生成并打印退学通知单        |\n");
	printf("|      3 ---- 生成并打印新名册            |\n");
	printf("|      0 ---- 返回主菜单                  |\n");
	printf("|-----------------------------------------|\n");
	scanf("%d", &choice);
	switch(choice)
	{
	    //case 1: dispBukao(); break;
	    //case 2: dispTuixue(); break;
	    //case 3: dispNew(); break;
	    case 0: return;
	    default: printf("%d是非法选项,按任意建后重新选择!\n", choice);
	    getchar();
	    getchar();
	}
    }while(1);

}

/*********************************************主模块****************************************************/
int main(int argc, char **argv)
{
    int choice;
    do{
	//system("cls");
	printf("|-----------------------------------------|\n");
	printf("|       请输入选项编号(0 ~ 3):            |\n");
	printf("|-----------------------------------------|\n");
	printf("|      1 ---- 成绩录入                    |\n");
	printf("|      2 ---- 成绩统计                    |\n");
	printf("|      3 ---- 学籍处理                    |\n");
	printf("|      0 ---- 退出                        |\n");
	printf("|-----------------------------------------|\n");
	printf("请输入选项编号(1 ~ 3, 0 退出):\n");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1: addRecord(); break;
	    case 2: Achievement_statistics(); break;
	    case 3: School(); break;
	    case 0: exit(0);
	    default: printf("%d是非法选项,按任意建后重新选择!\n", choice);
	    getchar();
	    getchar();
	}
    }while(1);

    return 0;
}
