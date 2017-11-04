#include <stdio.h>
#include <stdio.h>
#include <string.h>

typedef struct _studentr{
    int id;
    char name[20];
    int mathRecord;
    int englishRecord;
    int physicsRecord;
    int electricRecord;
    int c2Record;
}StudentR;

void addRecord{
    StudentR *guwenjun;
    FILE *record;

    //打开学生成绩单
    studentF = fopen("d:\\成绩录入\\record.txt", "a");
    if(studentF == NULL){
       printf("\n 文件打开失败! \n"); return;
    }

    //输入学生成绩
    guwenjun = (StudentR *)malloc(sizeof(StudentR));
    printf("请输入学生学号:"); scanf("%d", &guwenjun->id);
    printf("请输入学生姓名:"); scanf("%s", &guwenjun->name);
    printf(""); scanf("%d", &guwenjun->mathRecord);
    printf(""); scanf("%d", &guwenjun->englishRecord);
    printf(""); scanf("%d", &guwenjun->physicsRecord);
    printf(""); scanf("%d", &guwenjun->electricRecord);
    printf(""); scanf("%d", &guwenjun->c2Record);

    //将学生学号与成绩写进成绩库
    fprintf(record, "\n%d%s%d%d%d%d%d", guwenjun->id, guwenjun->name, guwenjun->mathRecord, guwenjun->englishRecord, guwenjun->physicsRecord, guwenjun->electricRecord, guwenjun->c2Record);
    printf("\n成功添加学生%s的成绩,按任意建继续......", guwenjun->name);
    getchar();
    getchar();

    fclose(record);
    return;	
}
