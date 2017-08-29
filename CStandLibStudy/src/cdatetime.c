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
	strftime(str, 100,"It is now %I %p",ptr);
	printf(str);
}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
//	clock_test();
//	time_test();
//	gmtime_test();
//	time_format();
	test_formt_byself();
	return EXIT_SUCCESS;
}


