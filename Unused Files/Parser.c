/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Summer, 2024
* Author: BY Santiago Ugarte(041090461) & Isha Gadani(041085940)
* Professors: Paulo Sousa
************************************************************
						"\t=------------------------------------------------------=\n"
						"\t|  ISH LANGUAGE - BY Santiago Ugarte & Isha Gadani     |\n"
						"\t=------------------------------------------------------=\n"

		"::::::::::::::::::::::::::::::'####:'######:'##::::'##:::::::::::::::::::::::::::::::::::::\n"
		"::::::::::::::::::::::::::::::. ##:'##... ##:##:::: ##:::::::::::::::::::::::::::::::::::::\n"
		"::::::::::::::::::::::::::::::: ##::##:::..::##:::: ##:::::::::::::::::::::::::::::::::::::\n"
		"::::::::::::::::::::::::::::::: ##:. ######::#########:::::::::::::::::::::::::::::::::::::\n"
		"::::::::::::::::::::::::::::::: ##::..... ##:##.... ##:::::::::::::::::::::::::::::::::::::\n"
		"::::::::::::::::::::::::::::::: ##:'##::: ##:##:::: ##:::::::::::::::::::::::::::::::::::::\n"
		"::::::::::::::::::::::::::::::'####. ######::##:::: ##:::::::::::::::::::::::::::::::::::::\n"
		"::::::::::::::::::::::::::::::....::......::..:::::..::::::::::::::::::::::::::::::::::::::\n"
		"'########'##::::'##'########::'########:'########:::'##:::::::::'###:::'##::: ##:'######:::\n"
		"... ##..::##:::: ##:##.....::::##.... ##:##.... ##:::##::::::::'## ##:::###:: ##'##... ##::\n"
		"::: ##::::##:::: ##:##:::::::::##:::: ##:##:::: ##:::##:::::::'##:. ##::####: ##:##:::..:::\n"
		"::: ##::::#########:######:::::##:::: ##:########::::##::::::'##:::. ##:## ## ##:##::'####:\n"
		"::: ##::::##.... ##:##...::::::##:::: ##:##.... ##:::##:::::::#########:##. ####:##::: ##::\n"
		"::: ##::::##:::: ##:##:::::::::##:::: ##:##:::: ##:::##:::::::##.... ##:##:. ###:##::: ##::\n"
		"::: ##::::##:::: ##:########:::########::########::::########:##:::: ##:##::. ##. ######:::\n"
		":::..::::..:::::..:........:::........::........::::........:..:::::..:..::::..::......::::\n"
*/

/*
************************************************************
* File name: Parser.c
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: [011, 012]
* Assignment: A12, A22, A32.
* Date: May 01 2024
* Professor: Paulo Sousa
* Purpose: This file implements the functions called by Parser.
* Function list:
*************************************************************/

#include "Parser.h"
#include <stdlib.h>

/* Function to create a parser */
ish_intg parserCreate() {
	/* Perform parser initialization */
	return 0; /* 0 indicates success */
}

/* Function to parse the token stream and generate an abstract syntax tree */
ASTNodePointer parserParse(TokenPointer tokenStream) {
	ASTNodePointer root = NULL;

	/* Parse the token stream and generate the AST */
	/* Example: */
	root = (ASTNodePointer)malloc(sizeof(ASTNode));
	if (root == NULL) {
		/* Error handling */
		return NULL;
	}

	root->type = PROGRAM_NODE;
	root->tokenType = TOKEN_UNDEFINED;
	root->numChildren = 0;
	root->children = NULL;

	/* Dummy implementation, can be expanded */
	return root;
}

/* Function to free memory allocated for the AST */
ish_void parserFree(ASTNodePointer root) {
	if (root == NULL) {
		return;
	}

	/* Free memory allocated for the AST nodes */
	if (root->children != NULL) {
		for (int i = 0; i < root->numChildren; i++) {
			parserFree(root->children[i]);
		}
		free(root->children);
	}

	free(root);
}
