#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
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
  
int num=0;  
   
/*求平均值*/  
float Avg(student stu)  
{  
     return (stu.math + stu.engl + stu.phys + stu.elec + stu.CII) / 5;  
}  
  
/*通过学号返回数组下标*/  
int Student_SearchByIndex(char id[])  
{  
     int i;  
     for (i=0;i<num;i++)  
     {  
         if (strcmp(students[i].ID,id)==0)  
         {  
              return i;  
         }  
     }  
     return -1;  
}  
  
/*通过姓名返回数组下标*/  
int Student_SearchByName(char name[])  
{  
     int i;  
     for (i=0;i<num;i++)  
     {  
         if (strcmp(students[i].Name,name)==0)  
         {  
              return i;  
         }  
     }  
     return -1;  
}  
  
/*显示单条学生记录*/  
void Student_DisplaySingle(int index)  
{  
    printf("%10s %10s %10s %10s %10s %10s %10s\t%10s \n","学号","姓名","math","engl","phys","elec","CII","平均成绩");  
    printf("------------------------------------------------------------------------------------------\n");  
    printf("%7s %10s %10.2f %10.2f %9.2f %9.2f %12.2f %13.2f\n",students[index].ID,students[index].Name,  
              students[index].math, students[index].engl, students[index].phys, students[index].elec, students[index].CII, students[index].Average);  
}  
  
/*插入学生信息*/  
void Student_Insert()  
{  
     while(1)  
     {  
         printf("请输入学号:");  
         scanf("%s",&students[num].ID);  
         getchar();  
         printf("请输入姓名:");  
         scanf("%s",&students[num].Name);  
         getchar();  
         printf("请输入math:");  
         scanf("%f",&students[num].math);  
         getchar();  
         printf("请输入engl:");  
         scanf("%f",&students[num].engl);  
         getchar();  
         printf("请输入phys:");  
         scanf("%f",&students[num].phys);  
         getchar();  
         printf("请输入elec:");  
         scanf("%f",&students[num].elec);  
         getchar();  
         printf("请输入CII:");  
         scanf("%f",&students[num].CII);  
         getchar();  
  
         students[num].Average=Avg(students[num]);  
         num++;  
  
         printf("是否继续?(y/n)");  
  
         if (getchar()=='n')  
         {  
              break;  
         }  
     }  
}  
  
/*修改学生信息*/  
void Student_Modify()  
{  
     //float mark1,mark2,mark3;  
     while(1)  
     {  
         char id[20];  
         int index;  
  
         printf("请输入要修改的学生的学号:");  
         scanf("%s",&id);  
         getchar();  
         index=Student_SearchByIndex(id);  
         if (index==-1)  
         {  
              printf("学生不存在!\n");  
         }  
         else  
         {  
              printf("你要修改的学生信息为:\n");  
              Student_DisplaySingle(index);  
              printf("-- 请输入新值--\n");  
              printf("请输入学号:");  
              scanf("%s",&students[index].ID);  
              getchar();  
              printf("请输入姓名:");  
              scanf("%s",&students[index].Name);  
              getchar();  
              printf("请输入math:");  
              scanf("%f",&students[index].math);  
              getchar();  
              printf("请输入engl:");  
              scanf("%f",&students[index].engl);  
              getchar();  
              printf("请输入phys:");  
              scanf("%f",&students[index].phys);  
              getchar();  
              printf("请输入elec:");  
              scanf("%f",&students[index].elec);  
              getchar();  
              printf("请输入CII:");  
              scanf("%f",&students[index].CII);  
              getchar();  
              students[index].Average=Avg(students[index]);  
         }  
  
         printf("是否继续?(y/n)");  
         if (getchar()=='n')  
         {  
              break;  
         }  
     }  
  
}  
  
   
  
/*删除学生信息*/  
  
void Student_Delete()  
{  
    int i;  
    while(1)  
    {  
        char id[20];  
        int index;  
        printf("请输入要删除的学生的学号:");  
        scanf("%s",&id);  
        getchar();  
        index=Student_SearchByIndex(id);  
        if (index==-1)  
        {  
             printf("学生不存在!\n");  
        }  
        else  
        {  
             printf("你要删除的学生信息为:\n");  
             Student_DisplaySingle(index);  
             printf("是否真的要删除?(y/n)");  
             if (getchar()=='y')  
             {  
                  for (i=index;i<num-1;i++)  
                  {  
                      students[i]=students[i+1];//把后边的对象都向前移动  
                  }  
                  num--;  
             }  
             getchar();  
        }  
        printf("是否继续?(y/n)");  
        if (getchar()=='n')  
        {  
             break;  
        }  
    }  
}  
  
/*按姓名查询*/  
void Student_Select()  
{  
    while(1)  
    {  
        char name[20];  
        int index;  
        printf("请输入要查询的学生的姓名:");  
        scanf("%s",&name);  
        getchar();  
        index=Student_SearchByName(name);  
        if (index==-1)  
        {  
             printf("学生不存在!\n");  
        }  
        else  
        {  
             printf("你要查询的学生信息为:\n");  
             Student_DisplaySingle(index);  
        }  
        printf("是否继续?(y/n)");  
        if (getchar()=='n')  
        {  
             break;  
        }  
    }  
}  
  
/*按平均值排序*/  
void Student_SortByAverage(){  
    IO_ReadInfo();
    int i, j;  
    student tmp;  
    for(i=0;i<num;i++)  
    {  
        for (j=1;j<num-i;j++)  
        {  
             if (students[j-1].Average<students[j].Average)  
             {  
                  tmp=students[j-1];  
                  students[j-1]=students[j];  
                  students[j]=tmp;  
             }  
        }  
    }  
    Student_Display();
}  
   
/*按学号排序*/
void Student_SortByID(){
    IO_ReadInfo();
    int i, j;
    student tmp;
    for(i = 0; i < num-i; i++){
	for(j = 1; j < num - i; j++){
	    if(students[j-1].ID < students[j].ID){
		tmp = students[j -1];
		students[j - 1] = students[j];
		students[j] = tmp;
	    }
	}
    }
    Student_Display();
}

/*显示学生信息*/  
void Student_Display()  
{  
    int i;  
    printf("%10s %10s %10s %10s %10s %10s %10s\t%10s \n","学号","姓名","math","engl","phys","elec","CII","平均成绩");  
    printf("------------------------------------------------------------------------------------------\n");  
    for (i=0;i<num;i++)  
    {  
        printf("%7s %10s %10.2f %10.2f %9.2f %9.2f %12.2f %13.2f\n",students[i].ID,students[i].Name,  
             students[i].math, students[i].engl, students[i].phys, students[i].elec, students[i].CII, students[i].Average);  
    }  
}  
  
/*将学生信息从文件读出*/  
void IO_ReadInfo()  
{  
     FILE *fp;  
     int i;  
     if ((fp=fopen("record.txt","rb"))==NULL)  
     {  
         printf("不能打开文件!\n");  
         return;  
     }  
     if (fread(&num,sizeof(int),1,fp)!=1)  
     {  
         num=-1;  
     }  
     else  
     {  
         for(i=0;i<num;i++)  
         {  
              fread(&students[i],sizeof(struct Student),1,fp);  
         }  
     }  
  
     fclose(fp);  
}  
  
/*将学生信息写入文件*/  
void IO_WriteInfo()  
{  
     FILE *fp;  
     int i;  
  
     if ((fp=fopen("record.txt","wb"))==NULL)  
     {  
         printf("不能打开文件!\n");  
         return;  
     }  
     if (fwrite(&num,sizeof(int),1,fp)!=1)  
     {  
         printf("写入文件错误!\n");  
     }  
     for (i=0;i<num;i++)  
     {  
         if (fwrite(&students[i],sizeof(struct Student),1,fp)!=1)  
         {  
              printf("写入文件错误!\n");  
         }  
     }      
  
     fclose(fp);  
}  
  
/*******************************************子菜单模块***************************************************/  
//成绩录入模块
void GradeInput()  
{  
     int choice;  
  
     IO_ReadInfo();  
     while(1)  
     {  
         /*主菜单*/  
         printf("\n------ 学生成绩管理系统------\n");  
         printf("1. 增加学生记录\n");  
         printf("2. 修改学生记录\n");  
         printf("3. 删除学生记录\n");  
         printf("4. 按姓名查询学生记录\n");  
         //printf("5. 按平均成绩排序\n");  
         printf("0. 返回主菜单\n");  
         printf("请选择(1 ~ 4), 0返回主菜单:");  
         scanf("%d",&choice);  
         getchar();  
         switch(choice)  
         {  
         case 1: Student_Insert(); break;  
  
         case 2: Student_Modify(); break;  
  
         case 3: Student_Delete(); break;  
  
         case 4: Student_Select(); break;  
  
         //case 5: Student_SortByAverage(); Student_Display(); break;  
  
         case 0: return; break;  
  
         }  
         IO_WriteInfo();  
     }  
}  

//成绩统计模块
void TongJi(){
    int choice;

    IO_ReadInfo();
    while(1){
	printf("\n---------成绩统计---------\n");
	printf("--1.  按学号排序\n");
	printf("--2.  按平均分排序\n");
	printf("--0.  返回主菜单\n");
	printf("--请输入(1 ~ 2), 0返回主菜单:");
	scanf("%d", &choice);
	getchar();
	switch(choice){
	    case 1: Student_SortByID(); break;
	    case 2: Student_SortByAverage(); break;
	    case 0: return; break;
	}
	IO_WriteInfo();
    }
}
/*********************************************主模块****************************************************/
int main(int argc, char **argv)
{
    int choice;
    IO_ReadInfo();
    do{
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
	    case 1: GradeInput(); break;
	    case 2: TongJi(); break;
	    //case 3: ; break;
	    case 0: exit(0);
	    default: printf("%d是非法选项,按任意建后重新选择!\n", choice);
	    getchar();
	    getchar();
	}
    }while(1);

    return 0;
}
