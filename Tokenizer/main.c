#include <stdio.h>
#include "Token.h"

int main(int argc,char argv[]) {
	char exp[100];
	printf("Enter string: ");
	gets(exp);
	checkToken(exp);
	return 0;
}