#ifndef stu_h
#define stu_h

void IO_ReadInfo();
void Student_Display();

/*定义学生结构体*/  
typedef struct Student  
{  
     char ID[20];  
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
  
//初始学生数量为0
//int num = 0;  
   
/*求平均值*/  
float Avg(student stu);

/*通过学号返回数组下标*/  
int Student_SearchByIndex(char id[]);

/*通过姓名返回数组下标*/  
int Student_SearchByName(char name[]);  

/*显示单条学生记录*/  
void Student_DisplaySingle(int index);

/*插入学生信息*/  
void Student_Insert();

/*修改学生信息*/  
void Student_Modify();

/*删除学生信息*/  
void Student_Delete();

/*按姓名查询*/  
void Student_Select(); 

/********************************************成绩统计模块**************************************************/
/*按平均值排序*/  
void Student_SortByAverage();

/*按学号排序*/
void Student_SortByID();

//各门课各分数段学生人数统计并打印
void Student_Sort_EachSubject();

/*显示学生信息*/  
void Student_Display();

/*********************************************文件读写模块*************************************************/
/*将学生信息从文件读出*/  
void IO_ReadInfo();

/*将学生信息写入文件*/  
void IO_WriteInfo();

/*******************************************子菜单模块***************************************************/  
//成绩录入模块
void GradeInput();

//成绩统计模块
void TongJi();


#endif
