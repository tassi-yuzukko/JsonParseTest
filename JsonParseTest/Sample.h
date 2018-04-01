#pragma once
#include <stdio.h>
#include <string.h>

typedef unsigned char byte;

typedef struct {
	double testDouble;
	int testInt;
	int testBool;
} Inner;

typedef struct {
	char* testString;
	char** testArrayString;
	byte* testArrayBytes;
	Inner inner;
	Inner* innerList;
}Sample;