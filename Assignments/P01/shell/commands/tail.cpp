#include <bits/stdc++.h> 
using namespace std; 

#define SIZE 100 

void sleep(unsigned int n) 
{ 
	clock_t goal = n * 1000 + clock(); 
	while (goal > clock()); 
} 

void tail(FILE* in, int n) 
{ 
	int count = 0; 

	unsigned long long pos; 
	char str[2*SIZE]; 

	if (fseek(in, 0, SEEK_END)) 
		perror("fseek() failed"); 
	else
	{ 
 
		pos = ftell(in); 
		while (pos) 
		{ 
			if (!fseek(in, --pos, SEEK_SET)) 
			{ 
				if (fgetc(in) == '\n') 
					if (count++ == n) 
						break; 
			} 
			else
				perror("fseek() failed"); 
		} 
		printf("Printing last %d lines -\n", n); 
		while (fgets(str, sizeof(str), in)) 
			printf("%s", str); 
	} 
	printf("\n\n"); 
} 

int main() 
{ 
	FILE* fp; 
	char buffer[SIZE]; 
	fp = fopen("input.txt", "wb+"); 
	if (fp == NULL) 
	{ 
		printf("Error while opening file"); 
		exit(EXIT_FAILURE); 
	} 
	srand(time(NULL)); 
	for (int index = 1; index <= 10; index++) 
	{ 
		for (int i = 0; i < SIZE - 1; i++) 
			buffer[i] = rand() % 26 + 65; // A-Z 
		buffer[SIZE] = '\0'; 
		time_t ltime = time(NULL); 
		char* date = asctime(localtime(<ime)); 
		date[strlen(date)-1] = '\0'; 
		fprintf(fp, "\nLine #%d [%s] - %s", index, 
									date, buffer); 
		fflush(fp); 
		tail(fp, index); 
		sleep(3); 
	} 
	fclose(fp); 

	return 0; 
} 
