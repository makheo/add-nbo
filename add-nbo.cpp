#include <stddef.h> 
#include <stdint.h> 
#include <stdio.h> 
#include <string.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	FILE *fp1 = fopen(argv[1], "rb");
	FILE *fp2 = fopen(argv[2], "rb");
	
	uint32_t input1, input2, add;

	fread(&input1, sizeof(uint32_t), 1, fp1);
	fread(&input2, sizeof(uint32_t), 1, fp2);

	add = ntohl(input1) + ntohl(input2);

        printf("%d(0x%03x) + %d(0x%03x) = %d(0x%03x) \n", ntohl(input1), ntohl(input1), ntohl(input2), ntohl(input2), add, add);

	fclose(fp2);
	fclose(fp1);
        return 0;
}

