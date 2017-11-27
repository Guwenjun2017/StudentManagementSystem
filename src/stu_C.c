#include "../inc/stu.h"

//初始学生数为0
int num_of_students_C = 0;

/*求平均值*/  
float Average_C(student stu){  
    return (stu.math + stu.engl + stu.phys + stu.elec + stu.CII) / 5;  
}  
  
/*通过学号返回数组下标*/  
int Student_SearchByID_C(int id){  
    int i;  
    for(i=0;i<num_of_students_C;i++){  
	if (students[i].ID == id)  
        {  
	    return i;  
        }  
    }  
    return -1;  
}  
  
/*通过姓名返回数组下标*/  
int Student_SearchByName_C(char name[]){  
    int i;  
    for(i=0;i<num_of_students_C;i++){  
        if (strcmp(students[i].Name, name) == 0){  
	    return i;  
        }  
    }  
    return -1;  
}  
  
/*显示单条学生记录*/  
void Student_DisplaySingle_C(int index){  
    printf("%5s %9s %9s %9s %9s %9s %9s \t%9s  \n","学号","姓名","数学","英语","物理","电路","C指针","平均成绩");
    printf("------------------------------------------------------------------------------------------\n");
    printf("%7d %7s %10.2f %9.2f %9.2f %9.2f %10.2f %10.2f\n",students[index].ID,students[index].Name,  
              students[index].math, students[index].engl, students[index].phys, students[index].elec, \
	      students[index].CII, students[index].Average);  

    return;
}  
  
/*插入学生信息*/  
void Student_Insert_C(){  
    int a = 0;
    while(1){  
	system("clear");
	printf("请输入学号:");  
        scanf("%d",&students[num_of_students_C].ID);  
        getchar();  
	for(int i = 0; i < num_of_students_C - 1; i++){
	    if(students[num_of_students_C].ID == students[i].ID){
		printf("\e[31m\e[1m%s\e[0m","添加错误,该学生已存在!");
		a = 1;
	    }
	}
	if(a == 1){
	    break;
	}
	
        printf("请输入姓名:");  
        scanf("%s",&students[num_of_students_C].Name);  
        getchar();  

        printf("请输入数学成绩:");  
	do{
	    scanf("%f",&students[num_of_students_C].math);  
	    if(students[num_of_students_C].math >= 0 && students[num_of_students_C].math <= 100){
		break;
	    }else
		printf(RED_COLOR,"输入的成绩不合规范(0 ~ 100),请再次输入.\n");
	        printf(">>>>>>:");

	}while(1);
        getchar();  

        printf("请输入英语成绩:");  
	do{
	    scanf("%f",&students[num_of_students_C].engl);  
	    if(students[num_of_students_C].engl >= 0 && students[num_of_students_C].engl <= 100){
		break;
	    }else
		printf(RED_COLOR,"输入的成绩不合规范(0 ~ 100),请再次输入.\n");
	        printf(">>>>>>:");

	}while(1);
        getchar();  

        printf("请输入物理成绩:");  
	do{
	    scanf("%f",&students[num_of_students_C].phys);  
	    if(students[num_of_students_C].phys >= 0 && students[num_of_students_C].phys <= 100){
		break;
	    }else
		printf(RED_COLOR,"输入的成绩不合规范(0 ~ 100),请再次输入.\n");
	        printf(">>>>>>:");

	}while(1);
        getchar();  

        printf("请输入电路成绩:");  
	do{
	    scanf("%f",&students[num_of_students_C].elec);  
	    if(students[num_of_students_C].elec >= 0 && students[num_of_students_C].elec <= 100){
		break;
	    }else
		printf(RED_COLOR,"输入的成绩不合规范(0 ~ 100),请再次输入.\n");
	        printf(">>>>>>:");

	}while(1);
        getchar();  

        printf("请输入C指针成绩:");  
	do{
	    scanf("%f",&students[num_of_students_C].CII);  
	    if(students[num_of_students_C].CII >= 0 && students[num_of_students_C].CII <= 100){
		break;
	    }else
		printf(RED_COLOR,"输入的成绩不合规范(0 ~ 100),请再次输入.\n");
	        printf(">>>>>>:");

	}while(1);
        getchar();  
  
        students[num_of_students_C].Average=Average_C(students[num_of_students_C]);  
        num_of_students_C++;  
  
        printf("\e[31m\e[1m%s\e[0m","继续?(Enter键继续/n退出)");  
  
        if (getchar()=='n'){  
             break;  
        } 
    }  

    //IO_WriteInfo();
    return;
}  
  
/*修改学生信息*/  
void Student_Modify_C(){  
    while(1){  
	int id;  
        int index;  
  
        printf("请输入您想要修改的学生的学号:");  
        scanf("%d",&id);  
        getchar();  
        index=Student_SearchByID_C(id);  
        if(index==-1){  
            printf(GREEN_COLOR,"抱歉,无该生信息!\n");  
        }  
        else{  
            printf("您想要修改的学生的当前信息为:\n");  
            Student_DisplaySingle_C(index);  
	    int choice;
		printf("请选择您想要修改的具体信息:\n");
		printf("-1.数学\n");
		printf("-2.英语\n");
		printf("-3.物理\n");
		printf("-4.电路\n");
		printf("-5.C指针\n");
		printf("-6.全部信息\n");
		printf("-0.退出\n");
		printf(">>>>:");
		scanf("%d", &choice);
		if(1 == choice){
		    printf("请输入新的数学成绩:");
		    scanf("%f",&students[index].math);  
		    students[index].Average=Average(students[index]);  
		}
		if(2 == choice){
		    printf("请输入新的英语成绩:");
		    scanf("%f",&students[index].engl);  
		    students[index].Average=Average(students[index]);  
		}
		if(3 == choice){
		    printf("请输入新的物理成绩:");
		    scanf("%f",&students[index].phys);  
		    students[index].Average=Average(students[index]);  
		}
		if(4 == choice){
		    printf("请输入新的电路成绩:");
		    scanf("%f",&students[index].elec);  
		    students[index].Average=Average(students[index]);  
		}
		if(5 == choice){
		    printf("请输入新的C指针成绩:");
		    scanf("%f",&students[index].CII);  
		    students[index].Average=Average(students[index]);  
		}
		if(6 == choice){
		    printf("-- 请输入新的全部信息--\n");  
		    printf("请输入学号:");  
		    scanf("%d",&students[index].ID);  
		    getchar();  

		    printf("请输入姓名:");  
		    scanf("%s",&students[index].Name);  
		    getchar();  

		    printf("请输入数学成绩:");  
		    scanf("%f",&students[index].math);  
		    getchar();  

		    printf("请输入英语成绩:");  
		    scanf("%f",&students[index].engl);  
		    getchar();  

		    printf("请输入物理成绩:");  
		    scanf("%f",&students[index].phys);  
		    getchar();  

		    printf("请输入电路成绩:");  
		    scanf("%f",&students[index].elec);  
		    getchar();  

		    printf("请输入C指针成绩:");  
		    scanf("%f",&students[index].CII);  
		    getchar();  

		    students[index].Average=Average_C(students[index]);  
		}
} 
	getchar();
        printf(GREEN_COLOR,"继续?(Enter键继续/n退出)");  
        if(getchar()=='n'){  
	    break;  
        }  
    }  

    return;
}  

/*删除学生信息*/  
void Student_Delete_C(){  
    int i;  
    while(1){  
	int id;  
        int index;  
        printf("请输入您想要删除的学生的学号:");  
        scanf("%d",&id);  
        getchar();  
        index=Student_SearchByID_C(id);  

        if(index==-1){  
             printf("抱歉,无该生信息!\n");  
        }  
        else{  
            printf("您想要删除的学生的当前信息为:\n");  
            Student_DisplaySingle_C(index);  
            printf(GREEN_COLOR,"确定删除吗?(y/n)");  
            if(getchar()=='y'){  
                for(i=index;i<num_of_students_C-1;i++){  
		    //把后边的对象都向前移动  
		    students[i]=students[i+1];
                }  
                num_of_students_C--;  
            }  
            getchar();  
        }  

        printf(GREEN_COLOR,"继续?(Enter键继续/n退出)");  
        if(getchar()=='n'){  
             break;  
        }  
    } 

    //IO_WriteInfo();
    return;
}  
  
/*按学号查询*/  
void Student_SelectByID_C(){  
    while(1){  
	int a;
        int index;  
        printf("请输入您想要查询的学生的学号:");  
        scanf("%d",&a);  
        getchar();  
        index=Student_SearchByID_C(a);  

        if (index==-1){  
             printf(GREEN_COLOR,"抱歉,无该生信息!\n");  
        }else{  
             printf("您查询的学生的信息为:\n");  
             Student_DisplaySingle_C(index);  
        }  

        printf(GREEN_COLOR,"继续?(Enter键继续/n退出)");  
        if (getchar()=='n'){  
             break;  
        }  
    }  

    return;
}  

/*按姓名查询*/  
void Student_SelectByName_C(){  
    while(1){  
        char name[20];  
        int index;  
        printf("请输入您想要查询的学生的姓名:");  
        scanf("%s",&name);  
        getchar();  
        index=Student_SearchByName_C(name);  

        if (index==-1){  
             printf(GREEN_COLOR,"抱歉,无该生信息!\n");  
        }else{  
             printf("您查询的学生的信息为:\n");  
             Student_DisplaySingle_C(index);  
        }  

        printf(GREEN_COLOR,"继续?(Enter键继续/n退出)");  
        if (getchar()=='n'){  
             break;  
        }  
    }  

    return;
}  
  
/********************************************成绩统计模块**************************************************/
/*按平均值排序*/  
void Student_SortByAverage_C(){  
    //IO_ReadInfo();
    system("clear");
    int i, j;  
    student tmp;  

    for(i = 0; i < num_of_students_C; i++){  
	for (j = 1; j < num_of_students_C - i; j++){  
	    if(students[j - 1].Average < students[j].Average){  
		tmp = students[j - 1];  
                students[j - 1] = students[j];  
                students[j] = tmp;  
             }  
        }  
    }  
    Student_Display_C();

    return;
}  
   
/*按学号排序*/
void Student_SortByID_C(){
    //IO_ReadInfo();
    system("clear");
    int i, j;
    student tmp;

    for(j = 0; j < num_of_students_C - 1; j++){
	for(i = 0; i < num_of_students_C - 1; i++){
	    if(students[i].ID > students[i + 1].ID){
		tmp = students[i];
		students[i] = students[i + 1];
		students[i + 1] = tmp;
	    }
        }
    }
    Student_Display_C();

    return;
}

//各门课各分数段学生人数统计并打印
void Student_Sort_EachSubject_C(){
//    IO_ReadInfo();
    system("clear");
    //IO_ReadInfo();
    int math1 = 0, math2 = 0, math3 = 0, math4 = 0, math5 = 0;
    int engl1 = 0, engl2 = 0, engl3 = 0, engl4 = 0, engl5 = 0;
    int phys1 = 0, phys2 = 0, phys3 = 0, phys4 = 0, phys5 = 0;
    int elec1 = 0, elec2 = 0, elec3 = 0, elec4 = 0, elec5 = 0;
    int CII1 = 0, CII2 = 0, CII3 = 0, CII4 = 0, CII5 = 0;

    //math
    for(int i = 0; i < num_of_students_C; i++){
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
    for(int i = 0; i < num_of_students_C; i++){
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
    for(int i = 0; i < num_of_students_C; i++){
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
    for(int i = 0; i < num_of_students_C; i++){
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
    for(int i = 0; i < num_of_students_C; i++){
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
 
    printf(GREEN_COLOR,"\t\t90分以上\t80 ~ 89\t\t70~79\t\t60~69\t\t60以下\t(单位:人)\n");
    printf("--------------------------------------------------------------------------------------\n");  
    printf("数学:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",math1, math2, math3, math4, math5);
    printf("英语:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",engl1, engl2, engl3, engl4, engl5);
    printf("物理:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",phys1, phys2, phys3, phys4, phys5);
    printf("电路:\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",elec1, elec2, elec3, elec4, elec5);
    printf("C指针: \t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",CII1, CII2, CII3, CII4, CII5);
    printf("--------------------------------------------------------------------------------------\n");  

    return;
}
/*显示学生信息*/  
void Student_Display_C()  
{  
    int i;  
    int Ranking = 0;

    printf("%10s| %10s| %10s| %10s| %10s| %10s| %10s| %10s| %10s| \n","学号","姓名","数学","英语","物理","电路","C指针","平均成绩","排名");  
    printf("-----------------------------------------------------------------------------------------------------------------\n");  
    for (i=0;i<num_of_students_C;i++){  
	Ranking++;
        printf("   %7d| %10s| %10.2f| %10.2f| %10.2f| %10.2f| %10.2f| %10.2f| %10d|\n", students[i].ID, students[i].Name,  
             students[i].math, students[i].engl, students[i].phys, students[i].elec, students[i].CII, students[i].Average, Ranking);  
    }  

    return;
}  
  
/******************************************学籍处理模块****************************************************/
//补考通知
void print_information_bukao_C(){
    system("clear");
    //初始挂科数为0
    int num_of_students_C_of_fail = 0;
    //初始补考人数设为-1,因计数从0开始
    int num_of_students_C_of_studentbukao = -1;
    for(int i = 0; i < num_of_students_C; i++){
	if(students[i].math < 60)
	    num_of_students_C_of_fail++;
	if(students[i].engl < 60)
	    num_of_students_C_of_fail++;
	if(students[i].phys < 60)
	    num_of_students_C_of_fail++;
	if(students[i].elec < 60)
	    num_of_students_C_of_fail++; 
	if(students[i].CII < 60)
	    num_of_students_C_of_fail++;
	if(num_of_students_C_of_fail > 0){
	    num_of_students_C_of_studentbukao++;
	}
	if(num_of_students_C_of_studentbukao != -1){
	    students_bukao[num_of_students_C_of_studentbukao] = students[i];
	}
    } 

    if(num_of_students_C_of_studentbukao == -1){
	printf(GREEN_COLOR,"没有学生需要补考\n");
    }

    printf(GREEN_COLOR,"\n-----------补考通知(学生ID Name和挂科科目成绩)-------------\n");  
    for(int j = 0; j < num_of_students_C_of_studentbukao; j++){
        printf("%d\t", students_bukao[j].ID);
        printf("%s\t", students_bukao[j].Name);
        if(students_bukao[j].math < 60){
            printf("数学:  %5.2f|", students_bukao[j].math);
        }
        if(students_bukao[j].engl < 60){
            printf("英语:  %5.2f|", students_bukao[j].engl);
        }
        if(students_bukao[j].phys < 60){
            printf("物理:  %5.2f|", students_bukao[j].phys);
        }
        if(students_bukao[j].elec < 60){
            printf("电路:  %5.2f|", students_bukao[j].elec);
        }
        if(students_bukao[j].CII < 60){
            printf("C指针:  %5.2f|", students_bukao[j].CII);
        }
        printf("\n");
    }  

    return;
}
//退学通知
void print_information_tuixue_C(){
    system("clear");
    //初始挂科数为0
    int num_of_students_C_of_fail = 0;
    //初始退学人数设为-1,因计数从0开始
    int num_of_students_C_of_studentfail = -1; 
    for(int i = 0; i < num_of_students_C; i++){
	if(students[i].math < 60)
	    num_of_students_C_of_fail++;
	if(students[i].engl < 60)
	    num_of_students_C_of_fail++;
	if(students[i].phys < 60)
	    num_of_students_C_of_fail++;
	if(students[i].elec < 60)
	    num_of_students_C_of_fail++;
	if(students[i].CII < 60)
	    num_of_students_C_of_fail++;
	if(num_of_students_C_of_fail >= 3){
	    num_of_students_C_of_studentfail++;
	    students_fail[num_of_students_C_of_studentfail] = students[i];
	}
    }
    if(num_of_students_C_of_studentfail == -1){
	printf("没有学生退学.\n");
    }
    printf(GREEN_COLOR,"\n-----------退学通知(学生ID Name和挂科科目成绩)-------------\n");  
    for(int j = 0; j < num_of_students_C_of_studentfail; j++){
        printf("%d\t", students_fail[j].ID);
        printf("%s\t", students_fail[j].Name);
        if(students_fail[j].math < 60){
            printf("数学:  %5.2f|", students_fail[j].math);
        }
        if(students_fail[j].engl < 60){
            printf("英语:  %5.2f|", students_fail[j].engl);
        }
        if(students_fail[j].phys < 60){
            printf("物理:  %5.2f|", students_fail[j].phys);
        }
        if(students_fail[j].elec < 60){
            printf("电路:  %5.2f|", students_fail[j].elec);
        }
        if(students_fail[j].CII < 60){
            printf("C指针: %5.2f|", students_fail[j].CII);
        }
        printf("\n");
    }  

    return;
} 

//升学学生
void print_information_up_C() {
   system("clear");
    //初始挂科数为0
    int num_of_students_C_of_fail = 0;
    //初始升学人数设为-1,因计数从0开始
    int num_of_students_C_of_up = -1; 
    for(int i = 0; i < num_of_students_C; i++){
	if(students[i].math < 60)
	    num_of_students_C_of_fail++;
	if(students[i].engl < 60)
	    num_of_students_C_of_fail++;
	if(students[i].phys < 60)
	    num_of_students_C_of_fail++;
	if(students[i].elec < 60)
	    num_of_students_C_of_fail++;
	if(students[i].CII < 60)
	    num_of_students_C_of_fail++;
	if(num_of_students_C_of_fail <= 2){
	    num_of_students_C_of_up++;
	    next[num_of_students_C_of_up] = students[i];
	}
    }
    printf(GREEN_COLOR,"\n成功进入下一年级的学生的学号与姓名:\n");
    for(int j = 0; j < num_of_students_C_of_up; j++){
	printf("学号: %d\t", next[j].ID);
	printf("姓名: %s\n", next[j].Name);
    }

    return;
}

///*********************************************文件读写模块*************************************************/
//void IO_WriteInfo(){
//    FILE *fp = fopen("record.txt","a"); //追加写入
//    for(int i = 0; i < num_of_students_C; i++){
//	fprintf(fp,"%s %s %f %f %f %f %f %f", students[i].ID, students[i].Name, students[i].math,
//		students[i].engl, students[i].phys, students[i].elec, students[i].CII, students[i].Average);
//    }
//    printf("Done!\n");
//    fclose(fp);
//
//    return;
//}
//void IO_ReadInfo(){
//    FILE *fp = fopen("record.txt", "r");
//    if(fp == NULL){
//	IO_WriteInfo();
//	fp = fopen("record.txt", "r");
//    }
//    for(int i = 0; i < num_of_students_C; i++){
//	fscanf(fp, "%s %s %f %f %f %f %f %f", &students[i].ID, &students[i].Name, &students[i].math,
//		&students[i].engl, &students[i].phys, &students[i].elec, &students[i].CII, &students[i].Average);
//    }
//    fclose(fp);
//
//    return;
//}
