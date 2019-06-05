#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int count = 0;
	while (1){
		FILE* fp = fopen("test.txt", "r");
		if (fp == NULL){
			perror("fopen failed");
			printf("%d",count);
			return 0;
		}
		count++;
	}

	return 0;
}