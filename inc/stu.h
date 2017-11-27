#ifndef stu_h
#define stu_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED_COLOR        "\e[31m\e[1m%s\e[0m"
#define GREEN_COLOR      "\e[32m\e[1m%s\e[0m"
#define YELLOW_COLOR     "\e[33m\e[1m%s\e[0m"

void IO_ReadInfo();
void Student_Display();

/*定义学生结构体*/  
typedef struct Student  
{  
    //ID类型为char数组,谨记!!! 
    int ID;  
    char Name[20];  
    float math;  
    float engl;  
    float phys;  
    float elec;  
    float CII;  
    float Average;  
}student;  

/*声明学生数组及学生数量*/  
student students[1000];  

//有挂科的学生的数组
student students_bukao[1000];
//退学学生数组
student students_fail[1000];
//升学学生数组
student next[1000];
   
/*****************************成绩录入模块**************************************/
/*求平均值*/  
float Average(student stu);
float Average_C(student stu);

/*通过学号返回数组下标*/  
int Student_SearchByID(int id);
int Student_SearchByID_C(int id);

/*通过姓名返回数组下标*/  
int Student_SearchByName(char name[]);  
int Student_SearchByName_C(char name[]);  

/*显示单条学生记录*/  
void Student_DisplaySingle(int);
void Student_DisplaySingle_C(int);

/*插入学生信息*/  
void Student_Insert();
void Student_Insert_C();

/*修改学生信息*/  
void Student_Modify();
void Student_Modify_C();

/*删除学生信息*/  
void Student_Delete();
void Student_Delete_C();

/*按学号查询*/  
void Student_SelectByID(); 
void Student_SelectByID_C(); 

/*按姓名查询*/  
void Student_SelectByName(); 
void Student_SelectByName_C(); 

/*****************************成绩统计模块**************************************/
/*按平均值排序*/  
void Student_SortByAverage();
void Student_SortByAverage_C();

/*按学号排序*/
void Student_SortByID();
void Student_SortByID_C();

//各门课各分数段学生人数统计并打印
void Student_Sort_EachSubject();
void Student_Sort_EachSubject_C();

/*显示学生信息*/  
void Student_Display();
void Student_Display_C();

/*****************************学籍处理模块**************************************/
//补考通知
void print_information_bukao();
void print_information_bukao_C();

//退学通知
void print_information_tuixue();
void print_information_tuixue_C();

//升学学生
void print_information_up();
void print_information_up_C();

/*****************************文件读写模块**************************************/
/*将学生信息从文件读出*/  
void IO_ReadInfo();

/*将学生信息写入文件*/  
void IO_WriteInfo();

/*******************************子菜单*****************************************/  
//成绩录入
void GradeInput();
void GradeInput_C();

//成绩查询
void GradeSearch();
void GradeSearch_C();

//成绩统计
void GradeTongJi();
void GradeTongJi_C();

//学籍处理
void Student_status_management();
void Student_status_management_C();

/******主菜单*******/
int mainMenu();
int mainMenu_C();
#endif
