/*
 ============================================================================
 Name        : CStandLibStudy.c
 Author      : robbin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @see http://blog.csdn.net/xiaoshengqdlg/article/details/38293435
 */

/**
 * C/C++中的计时函数是clock()，而与其相关的数据类型是clock_t
 *
 * 这个函数返回从开启这个程序进程”到“程序中调用clock()函数”时之间的CPU时钟计时单元（clock tick）数
 */
void clock_test( void )
{
     long  i = 10000000L;
     clock_t start, finish;
     double    duration;
     /* 测量一个事件持续的时间*/
     printf( "Time to do %ld empty loops is ", i );
     start = clock();
     while( i-- )        ;
     finish = clock();
     duration = (double)(finish - start) / CLOCKS_PER_SEC;
     printf( "%f seconds\n", duration );
     system("pause");
}


/**
 * 获得日历时间 time()
 */
void time_test(){
    time_t lt;
    lt = time(NULL);
    printf("The Calendar Time now is %d\n",lt);
}

/**
 * 获得日期和时间
 * struct tm * gmtime(const time_t *timer);
 * struct tm * localtime(const time_t * timer);
 */
void gmtime_test(){

	// 获取世界标准时间
	time_t t;
	t = time(NULL);
	// 获取本地时间
	struct tm * local = localtime(&t);
	printf("Local hour is: %d\n",local->tm_hour);
	// 获取标准时间
	local=gmtime(&t);
	printf("UTC hour is: %d\n",local->tm_hour);
}

/**
 * 4.3 固定的时间格式
 *
 *  我们可以通过asctime()函数和ctime()函数将时间以固定的格式显示出来，两者的返回值都是char*型的字符串。返回的时间格式为：

	星期几 月份 日期 时:分:秒 年\n\0
	例如：Wed Jan 02 02:03:55 1980\n\0

	其中\n是一个换行符，\0是一个空字符，表示字符串结束。下面是两个函数的原型：

	char * asctime(const struct tm * timeptr);
	char * ctime(const time_t *timer);

	其中asctime()函数是通过tm结构来生成具有固定格式的保存时间信息的字符串，而ctime()是通过日历时间来生成时间字符串。
	这样的话，asctime（）函数只是把tm结构对象中的各个域填到时间字符串的相应位置就行了，
	而ctime（）函数需要先【参照本地的时间设置】，把日历时间转化为本地时间，然后再生成格式化后的字符串。在下面，如果lt是一个非空的time_t变量的话，那么：

 */
void time_format(){
	struct tm *ptr;
	time_t lt;
	lt =time(NULL);
	ptr=gmtime(&lt);
	printf(asctime(ptr)); // Tue Aug 29 15:25:14 2017
	printf(ctime(&lt));   // Tue Aug 29 23:25:14 2017
}

/**
 * 4.4 自定义时间格式
 * 我们可以使用strftime（）函数将时间格式化为我们想要的格式。它的原型如下：

size_t strftime(
     char *strDest,
     size_t maxsize,
     const char *format,
     const struct tm *timeptr
);
 */
void test_formt_byself(){
	struct tm *ptr;
	time_t t;
	char str[80];
	t = time(NULL);
	ptr=localtime(&t);
	strftime(str, 100,"It is now %I %p\n",ptr);
	printf(str);

	struct tm *newtime;
	char tmpbuf[128];
	t=time( NULL );
	newtime=localtime(&t);
	strftime( tmpbuf, 128, "Today is %A, day %d of %B in the year %Y.\n", newtime);
	// Today is Tuesday, day 29 of August in the year 2017.
	printf(tmpbuf);
}

/**
 * 4.5 计算持续的时间长度
 *
 * 有时候在实际应用中要计算一个事件持续的时间长度，比如计算打字速度。在第1节计时部分中，我已经用clock函数举了一个例子。Clock()函数可以精确到毫秒级。
 * 同时，我们也可以使用difftime()函数，但它只能精确到秒。该函数的定义如下：

   double difftime(time_t time1, time_t time0);
 *
 */

void time_compute_test(){
	time_t start,end;
	start = time(NULL);
	system("pause");
	end = time(NULL);
	printf("The pause used %f seconds.\n",difftime(end,start));//<-
	system("pause");
}

/**
 * 4.6 分解时间转化为日历时间
 *
 * 这里说的分解时间就是以年、月、日、时、分、秒等分量保存的时间结构，在C/C++中是tm结构。我们可以使用mktime（）函数将用tm结构表示的时间转化为日历时间。其函数原型如下：

   time_t mktime(struct tm * timeptr);

       其返回值就是转化后的日历时间。这样我们就可以先制定一个分解时间，然后对这个时间进行操作了，下面的例子可以计算出1997年7月1日是星期几：
 */
void time_parse_test(){
	struct tm t;
	time_t t_of_day;
	t.tm_year=1997-1900;
	t.tm_mon=6;
	t.tm_mday=1;
	t.tm_hour=0;
	t.tm_min=0;
	t.tm_sec=1;
	t.tm_isdst=0;
	t_of_day=mktime(&t);
	printf(ctime(&t_of_day));
	// Tue Jul 01 00:00:01 1997
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//	clock_test();
//	time_test();
//	gmtime_test();
//	time_format();
//	test_formt_byself();
//	time_compute_test();
	time_parse_test();
	return EXIT_SUCCESS;
}


