#include <stdio.h>
#include <stdlib.h>
#include "stu.h"
  
/*********************************************主模块****************************************************/
int main(int argc, char **argv)
{
    int choice;
    IO_ReadInfo();
    do{
	printf("|-----------------------------------------|\n");
	printf("|                 主菜单                  |\n");
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
