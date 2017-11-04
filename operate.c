#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operate.h"

typedef Student* a;
a student_info_list;
//初始化学生成绩链表
void init_student_info_list(){
    student_info_list = (Student *)malloc(sizeof(Student));
    student_info_list->next = NULL;
}

//判断学生成绩链表是否为空
int student_list_empty(){
    return student_info_list == NULL;
}


//根据学号查找学生信息
Student *search_student_id(int num)
{
    Student *pstu;
    pstu = student_info_list->next;
    while(pstu  && pstu->id != num)
    {

        pstu = pstu->next;
    }
    return pstu;
}

//向学生成绩表中添加新的学生
void add_student_info(){
    Student *pstu = (Student *)malloc(sizeof(Student));
    FILE *fl;

    fl = fopen("record.txt", "a");
    if(pstu == NULL){
	printf("malloc error.\n");
	return;
    }
    if(fl == NULL){
	printf("\nerror.\n");
	return;
    }
    printf("请依次输入学生的成绩或信息:\n");
    printf("请输入学号: "); scanf("%d", &pstu->id);
    //判断该学号是否存在
    if(search_student_id(pstu->id) != NULL){
	printf("该学号已存在.\n");
	return;
    }
    printf("请输入姓名: "); scanf("%s", pstu->name);
    printf("请输入数学成绩: "); scanf("%d", &pstu->mathRecord);
    printf("请输入英语成绩: "); scanf("%d", &pstu->englishRecord);
    printf("请输入物理成绩: "); scanf("%d", &pstu->physicsRecord);
    printf("请输入电路成绩: "); scanf("%d", &pstu->electricRecord);
    printf("请输入CII成绩: ");  scanf("%d", &pstu->c2Record);
    pstu->average = (pstu->mathRecord + pstu->englishRecord + pstu->physicsRecord + pstu->electricRecord + pstu->c2Record) / 5;
    fprintf(fl, "\n%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d", pstu->id, pstu->name, pstu->mathRecord, pstu->englishRecord, pstu->physicsRecord, pstu->electricRecord, pstu->c2Record, pstu->average);
    printf("succeed.\n");
    getchar();
    //getchar();
    //每次从学生成绩链表的头部插入
    pstu->next = student_info_list->next;
    student_info_list->next = pstu;

    fclose(fl);
    return;
}

//输出每个学生的平均成绩
void display_average(){
    Student *pstu;
    pstu = student_info_list->next;
    while(pstu){
	printf("%s的学生的平均成绩为:%d\n", pstu->average);
	pstu = pstu->next;
    }
}
//
//显示所有学生的信息
void display_student_info(){
    Student *pstu;
    pstu = student_info_list->next;
    printf("所有学生的成绩为:\n");
    printf("学号\t姓名\tmath\tenglish\tphysics\telec\tCII\n");
    while(pstu){
	printf("%d\t", pstu->id);
	printf("%s\t", pstu->name);
	printf("%d\t", pstu->mathRecord);
	printf("%d\t", pstu->englishRecord);
	printf("%d\t", pstu->physicsRecord);
	printf("%d\t", pstu->electricRecord);
	printf("%d\t", pstu->c2Record);
	pstu = pstu->next;
    }
}

//根据学号删除学生成绩
//int delete_student_info(int num){
//    Student *pstu;
//    Student *qstu;
//    if(search_student_id(num) == NULL){
//	printf("不存在学号为%d的学生.\n", num);
//	return 0;
//    }
//    pstu = student_info_list->next;
//    qstu = student_list;
//    while(pstu->num != num){
//	qstu = pstu;
//	pstu = pstu->next;
//    }
//    qstu->next = pstu->next;
//    free(pstu);
//    return 1;
//}
//
////根据学号修改学生成绩
//int modify_student_info();
//
//    int choice;
//    Student *pstu = search_student_id(num);
//    if(pstu == NULL)
//    {
//        printf("不存在学号为%d的学生信息.\n",num);
//        return 0;
//    }
//    printf("1.姓名 2.math 3.english 4.physics 5.elec 6.CII.\n");
//    printf("请选择修改的信息: ");
//    scanf("%d",&choice);
//    switch(choice)
//    {
//    case 1:
//        printf("请输入新的姓名: ");
//        getchar();
//        gets(pstu->name);
//        break;
//    case 2:
//        printf("请输入新的math: ");
//        scanf("%s",pstu->mathRecord);
//        break;
//    case 3:
//        printf("请输入新的english: ");
//        scanf("%d",&pstu->englishRecord);
//        break;
//    case 4:
//        printf("请输入新的physics: ");
//        scanf("%d",&pstu->physicsRecord);
//        break;
//    case 5:
//        printf("请输入新的elec: ");
//        scanf("%d",&pstu->electricRecord);
//        break;
//    case 6:
//        printf("请输入新的CII: ");
//        scanf("%d",&pstu->c2Record);
//        break;
//    default:
//        printf("请按提示要求操作.\n");
//    }
//    return 1;
//}
//
////将学生信息保存到文件
//int save_file()
//{
//    FILE *pfile;
//    Student *pstu;
//    pfile = fopen("student.txt","w");
//    if(pfile == NULL)
//    {
//        printf("打开文件失败.\n");
//        return 0;
//    }
//    pstu = student_info_list->next;
//    while(pstu)
//    {
//        fprintf(pfile,"%5d%15s%9s%3d%4d%4d%4d%4d", pstu->id, pstu->name, pstu->mathRecord, pstu->englishRecord,
//            pstu->physicsRecord, pstu->electricRecord, pstu->c2Record, pstu->average);
//        pstu = pstu->next;
//    }
//    fclose(pfile);
//    return 1;
//}
//
////从文件中读取学生信息
//int read_file()
//{
//    SILE *pfile;
//    student *pstu;
//    pfile = fopen("student.txt","r");
//    if(pfile == NULL)
//    {
//        printf("打开文件失败.\n");
//        return 0;
//    }
//    while(!feof(pfile))
//    {
//        pstu = (student_info*)malloc(sizeof(student_info));
//        fscanf(pfile,"%5d%15s%9s%3d%4d%4d%4d%4d", pstu->id, pstu->name, pstu->mathRecord, pstu->englishRecord,
//            pstu->physicsRecord, pstu->electricRecord, pstu->c2Record, pstu->average);
//        pstu->average = (pstu->english + pstu->math + pstu->computer)/3;
//        //每次从学生信息链表的头部插入;
//        pstu->next = student_info_list->next;
//        student_info_list->next = pstu;
//    }
//    fclose(pfile);
//    return 1;
//}
