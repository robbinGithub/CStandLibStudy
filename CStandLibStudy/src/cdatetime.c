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
 * C/C++�еļ�ʱ������clock()����������ص�����������clock_t
 *
 * ����������شӿ������������̡����������е���clock()������ʱ֮���CPUʱ�Ӽ�ʱ��Ԫ��clock tick����
 */
void clock_test( void )
{
     long  i = 10000000L;
     clock_t start, finish;
     double    duration;
     /* ����һ���¼�������ʱ��*/
     printf( "Time to do %ld empty loops is ", i );
     start = clock();
     while( i-- )        ;
     finish = clock();
     duration = (double)(finish - start) / CLOCKS_PER_SEC;
     printf( "%f seconds\n", duration );
     system("pause");
}


/**
 * �������ʱ�� time()
 */
void time_test(){
    time_t lt;
    lt = time(NULL);
    printf("The Calendar Time now is %d\n",lt);
}

/**
 * ������ں�ʱ��
 * struct tm * gmtime(const time_t *timer);
 * struct tm * localtime(const time_t * timer);
 */
void gmtime_test(){

	// ��ȡ�����׼ʱ��
	time_t t;
	t = time(NULL);
	// ��ȡ����ʱ��
	struct tm * local = localtime(&t);
	printf("Local hour is: %d\n",local->tm_hour);
	// ��ȡ��׼ʱ��
	local=gmtime(&t);
	printf("UTC hour is: %d\n",local->tm_hour);
}

/**
 * 4.3 �̶���ʱ���ʽ
 *
 *  ���ǿ���ͨ��asctime()������ctime()������ʱ���Թ̶��ĸ�ʽ��ʾ���������ߵķ���ֵ����char*�͵��ַ��������ص�ʱ���ʽΪ��

	���ڼ� �·� ���� ʱ:��:�� ��\n\0
	���磺Wed Jan 02 02:03:55 1980\n\0

	����\n��һ�����з���\0��һ�����ַ�����ʾ�ַ�������������������������ԭ�ͣ�

	char * asctime(const struct tm * timeptr);
	char * ctime(const time_t *timer);

	����asctime()������ͨ��tm�ṹ�����ɾ��й̶���ʽ�ı���ʱ����Ϣ���ַ�������ctime()��ͨ������ʱ��������ʱ���ַ�����
	�����Ļ���asctime��������ֻ�ǰ�tm�ṹ�����еĸ������ʱ���ַ�������Ӧλ�þ����ˣ�
	��ctime����������Ҫ�ȡ����ձ��ص�ʱ�����á���������ʱ��ת��Ϊ����ʱ�䣬Ȼ�������ɸ�ʽ������ַ����������棬���lt��һ���ǿյ�time_t�����Ļ�����ô��

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
 * 4.4 �Զ���ʱ���ʽ
 * ���ǿ���ʹ��strftime����������ʱ���ʽ��Ϊ������Ҫ�ĸ�ʽ������ԭ�����£�

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


