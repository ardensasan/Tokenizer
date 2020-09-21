#include <stdio.h>
#include "Token.h"

void checkToken(char exp[]) {
const char op[] = "Operator", num[] = "Integer", ch[] = "Identifier";
int n = 0, i = 0, i2;
const char increment[] = "++";
const char decrement[] = "--";
const char operators[] = "+-*/<>=";
const char opEquivalent[][20] = { "Plus","Minus","Times","Divide","Less Than", "Greater Than","Equals" };
const char separator[] = "{}[]();";
const char sEquivalent[][20] = { "Open Curly Bracket","Close Curly Bracket","Open Bracket","Close Bracket","Open Parenthesis","Close Parenthesis","Semicolon" };
for (n = 0;exp[n] != '\0';n++) {
		if (isdigit(exp[n])) {
			printf("\n");
			while (isdigit(exp[n])) {
				printf("%c", exp[n]);
				n++;
			}
			printf("\tLiteral");
		}
		if (isalpha(exp[n])) {
			printf("\n");
			while (isalpha(exp[n]) || isdigit(exp[n])) {
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
		for (i = 0;operators[i] != '\0';i++) {
			if (exp[n] == operators[i]) {
				printf("\n%c\t%s", exp[n], opEquivalent[i]);
			}
		}
		for (i = 0;separator[i] != '\0';i++) {
			if (exp[n] == separator[i]) {
				printf("\n%c\t%s", exp[n], sEquivalent[i]);
			}
		}
		if (exp[n] == '\0') {
			break;
		}
	}
	return;
}