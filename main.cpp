#define _CRT_SECURE_NO_WARNINGS
#include <stdint.h>
#include <stdio.h>
int main(int argc, char*argv[])
{
	uint8_t buffer1[4], buffer2[4];
	size_t ret, ret2;
	if (argc < 3) return 0;
	FILE* pFile1 = fopen(argv[1], "r");
	FILE* pFile2 = fopen(argv[2], "r");
	ret = fread(buffer1, 1, 4, pFile1);
	ret2 = fread(buffer2, 1, 4, pFile2);

	uint32_t a = 0, b = 0, result = 0;

	a = buffer1[0];
	a = a << 8;
	a = a | buffer1[1];
	a = a << 8;
	a = a | buffer1[2];
	a = a << 8;
	a = a | buffer1[3];

	b = buffer2[0];
	b = b << 8;
	b = b | buffer2[1];
	b = b << 8;
	b = b | buffer2[2];
	b = b << 8;
	b = b | buffer2[3];

	result = a + b;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, result, result);
	return 0;
}

