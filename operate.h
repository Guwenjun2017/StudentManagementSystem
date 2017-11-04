#ifndef operate_h
#define operate_h

//定义学生结构体
typedef struct _node{
    int id;
    char name[20];
    int mathRecord;
    int englishRecord;
    int physicsRecord;
    int electricRecord;
    int c2Record;
    int average;
    struct _node *next;
}Student;

//学生成绩链表
extern Student *student_info_list;
//初始化学生成绩链表
void init_student_info_list();
//判断学生成绩链表是否为空
int student_list_empty();


//向学生成绩表中添加新的学生
void add_student_info();

//根据学号删除学生成绩
int delete_student_info();

//根据学号修改学生成绩
int modify_student_info();

//根据学号查找学生成绩
Student *search_student_id(int num);

//输出每个学生的平均成绩
void display_average();

//显示所有学生的信息
void display_student_info();

#endif 
