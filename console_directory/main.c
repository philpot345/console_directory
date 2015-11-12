#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 256

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv)
{
	FILE *fp;
	DIR* test;
	struct dirent* dp;
	char empty[MAXSIZE];
	char directory[MAXSIZE];
	char files[MAXSIZE][MAXSIZE];
	char file_data[MAXSIZE];
	char storage[MAXSIZE][MAXSIZE];
	int bits = 0, count = 0, found = 0, i_storage = 0;
	puts("Enter a directory:");
	scanf("%s", &directory);
	strcpy(file_data, directory);
	strcat(file_data, "\\test.txt");
	fp = fopen(file_data, "w+");
	test = opendir(directory);
	if (test == NULL)
		puts("Failure to find directory");
	if (fp == NULL)
		puts("Failure to find file");
	if (test != NULL && fp != NULL)
	{
		fprintf(fp, "Number  File\n");
		while ((dp = readdir(test)) != NULL)
		{
			strcpy(files[bits], dp->d_name);
			if (count < 10)
				fprintf(fp, "0%d\t%s\n", count, files[bits]);
			if (count >= 10)
				fprintf(fp, "%d\t%s\n", count, files[bits]);
			if (_strcmpi(files[bits], "Temp") == 0)
				found = count;
			if (bits == (MAXSIZE - 1))
				bits = 0;
			bits++;
			count++;
		}
		fp = freopen("c:\\temp\\test.txt", "r+", fp);
		while (fgets(storage, MAXSIZE, fp) != NULL)
			fputs(storage, stdout);
		if (found != 0)
			fprintf(fp, "Temp has been found at %d as %s\n", found, files[found]);
		if (found == 0)
			fprintf(fp, "Temp was not found\n");
	}
	closedir(test);
	fclose(fp);
	system("pause");
	return 0;
}