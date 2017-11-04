#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort1();
/*******************************************成绩录入模块************************************************/
//定义学生结构体
typedef struct _studentr{
    int id;
    char name[20];
    int mathRecord;
    int englishRecord;
    int physicsRecord;
    int electricRecord;
    int c2Record;
    struct _student *next;
}Student;

//extern Student *guwenjun;

void addRecord(Student *guwenjun){
    FILE *record;
    //guwenjun = (Student *)malloc(sizeof(Student));

    //打开学生成绩单
    record = fopen("record.txt", "a");
    if(record == NULL){
       printf("\n 文件打开失败! \n"); return;
    }

    //输入学生成绩
    printf("请输入学生学号:"); scanf("%d", &guwenjun->id);
    printf("请输入学生姓名:"); scanf("%s", &guwenjun->name);
    printf("请输入数学成绩:"); scanf("%d", &guwenjun->mathRecord);
    printf("请输入英语成绩:"); scanf("%d", &guwenjun->englishRecord);
    printf("请输入物理成绩:"); scanf("%d", &guwenjun->physicsRecord);
    printf("请输入电路成绩:"); scanf("%d", &guwenjun->electricRecord);
    printf("请输入CII成绩:"); scanf("%d", &guwenjun->c2Record);

    //将学生学号与成绩写进成绩库
    fprintf(record, "\n%d\t%s\t%d\t%d\t%d\t%d\t%d", guwenjun->id, guwenjun->name, guwenjun->mathRecord, guwenjun->englishRecord, guwenjun->physicsRecord, guwenjun->electricRecord, guwenjun->c2Record);
    printf("\n成功添加学生%s的成绩,按任意建继续......", guwenjun->name);
    getchar();
    getchar();

    fclose(record);
    return;	
}

/*******************************************成绩统计模块************************************************/
void Achievement_statistics(Student *guwenjun){
    guwenjun = (Student *)malloc(sizeof(Student));
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
	    case 1: sort1(); break;
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

void sort1(Student *guwenjun){
    FILE *fp;
    guwenjun = (Student *)malloc(sizeof(Student));

    fp = fopen("record.txt", "r");
    //printf("成绩单:\n");
    //printf("学号\t姓名\tmath\tenglish\tphysics\telec\tCII\n");
    while(!feof(fp)){
	printf("%d\t", guwenjun->id);
	printf("%s\t", guwenjun->name);
	printf("%d\t", guwenjun->mathRecord);
	printf("%d\t", guwenjun->englishRecord);
	printf("%d\t", guwenjun->physicsRecord);
	printf("%d\t", guwenjun->electricRecord);
	printf("%d\t", guwenjun->c2Record);
	getchar();
	getchar();
    }

    fclose(fp);
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
    Student *guwenjun = (Student *)malloc(sizeof(Student));
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
	    case 1: addRecord(guwenjun); break;
	    case 2: Achievement_statistics(guwenjun); break;
	    case 3: School(); break;
	    case 0: exit(0);
	    default: printf("%d是非法选项,按任意建后重新选择!\n", choice);
	    getchar();
	    getchar();
	}
    }while(1);

    return 0;
}
