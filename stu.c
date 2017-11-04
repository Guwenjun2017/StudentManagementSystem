#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stu.h"

//初始学生数为0
int num = 0;

/*求平均值*/  
float Avg(student stu){  
    return (stu.math + stu.engl + stu.phys + stu.elec + stu.CII) / 5;  
}  
  
/*通过学号返回数组下标*/  
int Student_SearchByIndex(char id[]){  
    int i;  
    for(i=0;i<num;i++){  
	if (strcmp(students[i].ID, id)==0)  
        {  
	    return i;  
        }  
    }  
    return -1;  
}  
  
/*通过姓名返回数组下标*/  
int Student_SearchByName(char name[]){  
    int i;  
    for(i=0;i<num;i++){  
        if (strcmp(students[i].Name, name) == 0){  
	    return i;  
        }  
    }  
    return -1;  
}  
  
/*显示单条学生记录*/  
void Student_DisplaySingle(int index){  
    printf("%10s %10s %10s %10s %10s %10s %10s\t%10s \n","学号","姓名","math","engl","phys","elec","CII","平均成绩");  
    printf("------------------------------------------------------------------------------------------\n");  
    printf("%7s %10s %10.2f %10.2f %9.2f %9.2f %12.2f %13.2f\n",students[index].ID,students[index].Name,  
              students[index].math, students[index].engl, students[index].phys, students[index].elec, students[index].CII, students[index].Average);  

    return;
}  
  
/*插入学生信息*/  
void Student_Insert(){  
    while(1){  
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
  
        if (getchar()=='n'){  
             break;  
        } 
    }  

    return;
}  
  
/*修改学生信息*/  
void Student_Modify(){  
    while(1){  
	char id[20];  
        int index;  
  
        printf("请输入要修改的学生的学号:");  
        scanf("%s",&id);  
        getchar();  
        index=Student_SearchByIndex(id);  
        if(index==-1){  
            printf("学生不存在!\n");  
        }  
        else{  
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
        if(getchar()=='n'){  
	    break;  
        }  
    }  

    return;
}  
  
   
  
/*删除学生信息*/  
void Student_Delete(){  
    int i;  
    while(1){  
	char id[20];  
        int index;  
        printf("请输入要删除的学生的学号:");  
        scanf("%s",&id);  
        getchar();  
        index=Student_SearchByIndex(id);  

        if(index==-1){  
             printf("学生不存在!\n");  
        }  
        else{  
            printf("你要删除的学生信息为:\n");  
            Student_DisplaySingle(index);  
            printf("是否真的要删除?(y/n)");  
            if(getchar()=='y'){  
                for(i=index;i<num-1;i++){  
		    //把后边的对象都向前移动  
		    students[i]=students[i+1];
                }  
                num--;  
            }  
            getchar();  
        }  

        printf("是否继续?(y/n)");  
        if(getchar()=='n'){  
             break;  
        }  
    } 

    return;
}  
  
/*按姓名查询*/  
void Student_Select(){  
    while(1){  
        char name[20];  
        int index;  
        printf("请输入要查询的学生的姓名:");  
        scanf("%s",&name);  
        getchar();  
        index=Student_SearchByName(name);  

        if (index==-1){  
             printf("学生不存在!\n");  
        }else{  
             printf("你要查询的学生信息为:\n");  
             Student_DisplaySingle(index);  
        }  

        printf("是否继续?(y/n)");  
        if (getchar()=='n'){  
             break;  
        }  
    }  

    return;
}  
  
/********************************************成绩统计模块**************************************************/
/*按平均值排序*/  
void Student_SortByAverage(){  
    int i, j;  
    student tmp;  

    for(i=0;i<num;i++){  
	for (j=1;j<num-i;j++){  
	    if(students[j-1].Average<students[j].Average){  
		tmp=students[j-1];  
                students[j-1]=students[j];  
                students[j]=tmp;  
             }  
        }  
    }  
    Student_Display();

    return;
}  
   
/*按学号排序*/
void Student_SortByID(){
    int i, j;
    student tmp;

    for(i = 0; i < num; i++){
	for(j = 1; j < num - i; j++){
	    if(students[j - 1].ID < students[j].ID){
		tmp = students[j - 1];
		students[j - 1] = students[j];
		students[j] = tmp;
	    }
	}
    }
    Student_Display();

    return;
}

//各门课各分数段学生人数统计并打印
void Student_Sort_EachSubject(){
    //IO_ReadInfo();
    int math1 = 0, math2 = 0, math3 = 0, math4 = 0, math5 = 0;
    int engl1 = 0, engl2 = 0, engl3 = 0, engl4 = 0, engl5 = 0;
    int phys1 = 0, phys2 = 0, phys3 = 0, phys4 = 0, phys5 = 0;
    int elec1 = 0, elec2 = 0, elec3 = 0, elec4 = 0, elec5 = 0;
    int CII1 = 0, CII2 = 0, CII3 = 0, CII4 = 0, CII5 = 0;

    //math
    for(int i = 0; i < num; i++){
	if(students[i].math >= 90)
	    math1++;
	else if(students[i].math >= 80)
	    math2++;
	else if(students[i].math >= 70)
	    math3++;
	else if(students[i].math >= 60)
	    math4++;
	else 
	    math5++;
    }

    //engl
    for(int i = 0; i < num; i++){
	if(students[i].engl >= 90)
	    engl1++;
	else if(students[i].engl >= 80)
	    engl2++;
	else if(students[i].engl >= 70)
	    engl3++;
	else if(students[i].engl >= 60)
	    engl4++;
	else 
	    engl5++;
    }

    //phys
    for(int i = 0; i < num; i++){
	if(students[i].phys >= 90)
	    phys1++;
	else if(students[i].phys >= 80)
	    phys2++;
	else if(students[i].phys >= 70)
	    phys3++;
	else if(students[i].phys >= 60)
	    phys4++;
	else 
	    phys5++;
    }

    //elec
    for(int i = 0; i < num; i++){
	if(students[i].elec >= 90)
	    elec1++;
	else if(students[i].elec >= 80)
	    elec2++;
	else if(students[i].elec >= 70)
	    elec3++;
	else if(students[i].elec >= 60)
	    elec4++;
	else 
	    elec5++;
    }

    //CII
    for(int i = 0; i < num; i++){
	if(students[i].CII >= 90)
	    CII1++;
	else if(students[i].CII >= 80)
	    CII2++;
	else if(students[i].CII >= 70)
	    CII3++;
	else if(students[i].CII >= 60)
	    CII4++;
	else 
	    CII5++;
    }

    printf("\t\t90分以上\t80 ~ 89\t\t70~79\t\t60~69\t\t60以下\t\n");
    printf("--------------------------------------------------------------------------------------\n");  
    printf("math:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",math1, math2, math3, math4, math5);
    printf("engl:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",engl1, engl2, engl3, engl4, engl5);
    printf("phys:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",phys1, phys2, phys3, phys4, phys5);
    printf("elec:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",elec1, elec2, elec3, elec4, elec5);
    printf("CII: \t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",CII1, CII2, CII3, CII4, CII5);
    printf("--------------------------------------------------------------------------------------\n");  

    return;
}
/*显示学生信息*/  
void Student_Display()  
{  
    int i;  

    printf("%10s %10s %10s %10s %10s %10s %10s\t%10s \n","学号","姓名","math","engl","phys","elec","CII","平均成绩");  
    printf("------------------------------------------------------------------------------------------\n");  
    for (i=0;i<num;i++){  
        printf("%7s %10s %10.2f %10.2f %9.2f %9.2f %12.2f %13.2f\n", students[i].ID, students[i].Name,  
             students[i].math, students[i].engl, students[i].phys, students[i].elec, students[i].CII, students[i].Average);  
    }  

    return;
}  
  
/*********************************************文件读写模块*************************************************/
/*将学生信息从文件读出*/  
void IO_ReadInfo()  
{  
    FILE *fp;  
    int i;  

    if((fp=fopen("record.txt","rb"))==NULL){  
        printf("不能打开文件!\n");  
        return;  
    }  
    if(fread(&num,sizeof(int),1,fp)!=1){  
        num=-1;  
    }else{  
        for(i=0;i<num;i++){  
	    fread(&students[i],sizeof(student),1,fp);  
        }  
    }  
  
    fclose(fp);  
    return;
}  
  
/*将学生信息写入文件*/  
void IO_WriteInfo()  
{  
    FILE *fp;  
    int i;  
  
    if((fp=fopen("record.txt","wb"))==NULL){  
        printf("不能打开文件!\n");  
        return;  
    }  
    if(fwrite(&num,sizeof(int),1,fp)!=1){  
        printf("写入文件错误!\n");  
    }  
    for (i=0;i<num;i++){  
        if(fwrite(&students[i],sizeof(student),1,fp)!=1){  
	    printf("写入文件错误!\n");  
        }  
    }      
  
    fclose(fp);  
    return;
}  
  
/*******************************************子菜单模块***************************************************/  
//成绩录入模块
void GradeInput()  
{  
    int choice;  
  
    IO_ReadInfo();  
    while(1)  
    {  
        printf("\n------ 学生成绩管理------\n");  
        printf("1. 增加学生记录\n");  
        printf("2. 修改学生记录\n");  
        printf("3. 删除学生记录\n");  
        printf("4. 按姓名查询学生记录\n");  
        printf("0. 返回主菜单\n");  
        printf("请选择(1 ~ 4), 0返回主菜单:\n");  
        scanf("%d",&choice);  
        getchar();  
        switch(choice){  
        case 1: Student_Insert(); break;  
        case 2: Student_Modify(); break;  
        case 3: Student_Delete(); break;  
        case 4: Student_Select(); break;  
        case 0: return; break;  
        }  
        IO_WriteInfo();  
    }  

    return;
}  

//成绩统计模块
void GradeTongJi(){
    int choice;

    //IO_ReadInfo();
    while(1){
	printf("\n|----------------成绩统计-----------------|\n");
	printf("|      1 ---- 按学号排序                  |\n");
	printf("|      2 ---- 按平均分排序                |\n");
	printf("|      3 ---- 统计分数段                  |\n");
	printf("|      0 ---- 返回主菜单                  |\n");
	printf("|-----------------------------------------|\n");
	printf("请输入选项编号(1 ~ 3, 0返回主菜单):\n");
	scanf("%d", &choice);
	getchar();
	switch(choice){
	    case 1: Student_SortByID(); break;
	    case 2: Student_SortByAverage(); break;
	    case 3: Student_Sort_EachSubject(); break;
	    case 0: return; break;
	}
	IO_WriteInfo();
    }

    return;
}

//学籍处理
void Student_status_management(){
    int choice;
    do{
	printf("|-----------------------------------------|\n");
	printf("|          请输入选项编号(0 ~ 3)          |\n");
	printf("|-----------------------------------------|\n");
	printf("|      1 ---- 生成并打印补考通知单        |\n");
	printf("|      2 ---- 生成并打印退学通知单        |\n");
	printf("|      3 ---- 生成并打印新名册            |\n");
	printf("|      0 ---- 返回主菜单                  |\n");
	printf("|-----------------------------------------|\n");
	printf("请输入选项编号(1 ~ 3, 0 返回):\n");
	scanf("%d", &choice);
	switch(choice)
	{
	    //case 1: print_information_bukao(); break;
	    case 2: print_information_tuixue(); break;
	    case 3: print_information_up(); break;
	    case 0: return; break;
	    default: printf("%d是非法选项,按任意建后重新选择!\n", choice);
	    getchar();
	    getchar();
	}
    }while(1);
}

//补考通知
void print_information_tuixue(){
    //初始挂科数为0
    int num_of_fail = 0;
    //初始补考人数设为-1,因计数从0开始
    int num_of_studentfail = -1; 
    for(int i = 0; i < num; i++){
	if(students[i].math < 60)
	    num_of_fail++;
	if(students[i].engl < 60)
	    num_of_fail++;
	if(students[i].phys < 60)
	    num_of_fail++;
	if(students[i].elec < 60)
	    num_of_fail++;
	if(students[i].CII < 60)
	    num_of_fail++;
	if(num_of_fail >= 3){
	    num_of_studentfail++;
	    students_fail[num_of_studentfail] = students[i];
	}
    }
    printf("\n---------------退学通知-----------------\n");  
    printf("学号\t\t姓名\t挂科科目与挂科科目的对应成绩\n");
    for(int j = 0; j < num_of_studentfail; j++){
	printf("%d\t", students_fail[j].ID);
	printf("%s\t", students_fail[j].Name);
	if(students_fail[j].math < 60){
	    printf("math:  %5.2f|", students_fail[j].math);
	}
	if(students_fail[j].engl < 60){
	    printf("engl:  %5.2f|", students_fail[j].engl);
	}
	if(students_fail[j].phys < 60){
	    printf("phys:  %5.2f|", students_fail[j].phys);
	}
	if(students_fail[j].elec < 60){
	    printf("elec:  %5.2f|", students_fail[j].elec);
	}
	if(students_fail[j].CII < 60){
	    printf("CII:  %5.2f|", students_fail[j].CII);
	}
	printf("\n");
    }  

    return;
} 

//升学学生
void print_information_up() {
    //初始挂科数为0
    int num_of_fail = 0;
    //初始升学人数设为-1,因计数从0开始
    int num_of_up = -1; 
    for(int i = 0; i < num; i++){
	if(students[i].math < 60)
	    num_of_fail++;
	if(students[i].engl < 60)
	    num_of_fail++;
	if(students[i].phys < 60)
	    num_of_fail++;
	if(students[i].elec < 60)
	    num_of_fail++;
	if(students[i].CII < 60)
	    num_of_fail++;
	if(num_of_fail <= 2){
	    num_of_up++;
	    next[num_of_up] = students[i];
	}
    }
    printf("\n升入高年级学生的学号与姓名:\n");
    for(int j = 0; j < num_of_up; j++){
	printf("ID: %d\t", next[j].ID);
	printf("姓名: %s\n", next[j].Name);
    }

    return;
}

