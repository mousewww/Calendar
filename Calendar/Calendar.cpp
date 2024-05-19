
#include <stdio.h>

int getyears();
int getmonth();
void printCalendar(int year,int month);
int isLeapYear(int year);

unsigned int year = 0;

int main()
{
	printf("感谢您使用万年历服务，我们的业务允许您查询1924年以后的日历\n");
	year=getyears();
	int month=getmonth();//获取年和月
	//输出当年当月的日历
	printCalendar(year,month);
	printf("   感谢您的使用!\n");
	return 0;
}
int getyears() {
	int year;
	printf("请输入你要查询的年份\n");
	while (1) {
		if(scanf_s("%d", &year) != 1){
				while (getchar() != '\n');
				printf("请输入正确的年份\n");
		}
		else
		{
			while (getchar() != '\n');
			break;
		}
		
	} 
		return year;
}
int getmonth() {
	int i = 0;
		printf("请输入你要查询的月份\n");
	while (scanf_s("%d",&i) != 1||i>12||i<0)
{
		while (getchar() != '\n');
		printf("请输入合适的月份\n");
}
	return i;
}
int isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
void printCalendar(int resyear, int month) {
	
		//求出该月的第一天是星期几
		// 1924年1月1日是星期2，即2（星期日为0，星期一为1，以此类推）  
		int firstDay = 2;
		// 从1924年到给定年份的天数累加  
		for (int year = 1924; year < resyear; year++) {
			
			firstDay = (firstDay + (isLeapYear(year) ? 2 : 1)) % 7;//366%7=2;
			//printf("%d.%d",year+1,firstDay);调试代码
		}
		// 累加给定年份中前几个月的天数（注意考虑闰年2月的影响）  
		int monthDays[] = { 0, 31,isLeapYear(resyear) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		for (int m = 1; m < month; m++) {
			firstDay = (firstDay + monthDays[m]) % 7;
		}

	printf("%d年%d月-----万年历-----\n",resyear,month);
	printf("  SUN MON TUE WED THU FRI SAT\n");
	//printf(".%d", firstDay);调试代码
	for (int i = 0; i < firstDay; i++)
	{
		printf("%*s", 4, "");
	}
	int day;
	for ( day = 1; day <= monthDays[month]; day++)
	{
		printf(" %3d",day);
		if ((day+firstDay-1)%7==6)
		{
			printf(".\n");
		}
		
	}
	if ((day + firstDay - 1) % 7 != 0) {
		printf("\n");
		
	}
	
}