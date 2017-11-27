/* *========* *** *============================================== 
  * 联络信箱: *** :guwenjun2017@gmail.com
  * 文档用途: *** :CII实验报告
  * 文档信息: *** :~/workspace/StudentManagementSystem/test.c
  * 修订时间: *** *2017年第47周 11月26日 星期日 下午03:20 (330天)
 * *========* *** *============================================== */
#include "../inc/stu.h"

int main(int argc, char **argv)
{
    char language;
    printf("Please choose your language, English please input E/e, Chinese please input C/c, After input, press the Enter key.\n");
    printf("[请选择您的地区语言,英文请输入E,中文请输入C,输入后Enter键结束].\n");
    scanf("%c", &language);
    if( language == 'E' || language == 'e')
	mainMenu();
    if( language == 'C' || language == 'c')
	mainMenu_C();

    return 0;
}
