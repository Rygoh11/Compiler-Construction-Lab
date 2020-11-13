#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[]) {
	char keywords[32][10] = { "auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while" };
	int i, flag = 0;

	for (i = 0; i < 32; ++i) {
		if (strcmp(keywords[i], buffer) == 0) {
			flag = 1;
			break;
		}
	}

	return flag;
}

int main() {
	char character, buffer[15], operators[] = "+-*/%=";
	ifstream file("program.txt");
	int i, j = 0;

	//If statement for error when opening file
	if (!file.is_open()) {
		cout << "error while opening the file\n";
		exit(0);
	}

	while (!file.eof()) {
		character = file.get();

		for (i = 0; i < 6; ++i) {
			if (character == operators[i])
				cout << character << " is an operator\n";
		}

		if (isalnum(character)) {
			buffer[j++] = character;
		}
		else if ((character == ' ' || character == '\n') && (j != 0)) {
			buffer[j] = '\0';
			j = 0;

			if (isKeyword(buffer) == 1)
				cout << buffer << " is a keyword\n";
			else
				cout << buffer << " is an identifier\n";
		}

	}

	file.close();

	return 0;
}
