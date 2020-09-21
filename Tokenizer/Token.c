#include <stdio.h>
#include "Token.h"

void checkToken(char exp[]) {
	const char op[] = "Operator", num[] = "Integer", ch[] = "Identifier";
	int n = 0, i = 0, i2;
	const char OPERATORS[] = "+-*/<>=";
	const char OPEQUIVALENT[][20] = { "Plus","Minus","Times","Divide","Less Than", "Greater Than","Equals" };
	const char SEPARATOR[] = "{}[]();";
	const char SEQUIVALENT[][20] = { "Open Curly Bracket","Close Curly Bracket","Open Bracket","Close Bracket","Open Parenthesis","Close Parenthesis","Semicolon" };
	for (n = 0;exp[n] != '\0';n++) {
		if (isdigit(exp[n])) {
			printf("\n");
			while (isdigit(exp[n])) {
				printf("%c", exp[n]);
				n++;
			}
			printf("\tLiteral");
		}
		if (isalpha(exp[n]) || exp[n] == '_') {
			printf("\n");
			while (isalpha(exp[n]) || isdigit(exp[n]) || exp[n] == '_') {
				printf("%c", exp[n]);
				n++;
			}
			printf("\tIdentifier");
		}
		if (exp[n] == '+' && exp[n + 1] == '+') {
			n += 2;
			printf("\n++ \t Increment");
		}
		if (exp[n] == '-' && exp[n + 1] == '-') {
			n += 2;
			printf("\n-- \t Decrement");
		}
		for (i = 0;OPERATORS[i] != '\0';i++) {
			if (exp[n] == OPERATORS[i]) {
				printf("\n%c\t%s", exp[n], OPEQUIVALENT[i]);
			}
		}
		for (i = 0;SEPARATOR[i] != '\0';i++) {
			if (exp[n] == SEPARATOR[i]) {
				printf("\n%c\t%s", exp[n], SEQUIVALENT[i]);
			}
		}
		if (exp[n] == '\0') {
			break;
		}
	}
	return;
}