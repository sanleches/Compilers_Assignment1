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
* File name: Reader.h
* Compiler: MS Visual Studio 2022
* Course: CST 8152 – Compilers, Lab Section: [011, 012]
* Assignment: A12.
* Date: May 01 2024
* Professor: Paulo Sousa
* Purpose: This file is the main header for Reader (.h)
************************************************************
*/

/*
 *.............................................................................
 * MAIN ADVICE:
 * Please check the "TODO" labels to develop your activity.
 *.............................................................................
 */
#ifndef READER_H_
#define READER_H_

#include "Compilers.h"

 /* standard header files */
#include <stdio.h>
#include <malloc.h>
#include <limits.h>

/* Modes (used to create buffer reader) */
enum READER_MODE {
	MODE_FIXED = 'f',
	MODE_ADDIT = 'a',
	MODE_MULTI = 'm'
};

/* Constants about controls */
#define READER_ERROR        (-1)
#define READER_TERMINATOR   '\0'
#define READER_MAX_SIZE     INT_MAX-1
#define READER_DEFAULT_SIZE 250
#define READER_DEFAULT_INCREMENT 10

/* Bit-masks constant definitions */
#define READER_DEFAULT_FLAG 0x00
#define FLAG_EMP 0x01
#define FLAG_FUL 0x02
#define FLAG_REL 0x04
#define FLAG_END 0x08

#define NCHAR               128
#define CHARSEOF            (-1)

/* Offset declaration */
typedef struct position {
	ish_intg mark;
	ish_intg read;
	ish_intg wrte;
} Position;

/* Buffer structure */
typedef struct bufferReader {
	ish_thread	content;
	ish_intg		size;
	ish_intg		increment;
	ish_intg		mode;
	ish_byte		flags;
	Position		position;
	ish_intg		histogram[NCHAR];
	ish_intg		numReaderErrors;
} Buffer, * BufferPointer;

/* FUNCTIONS DECLARATION:  .................................. */
/* General Operations */
BufferPointer  readerCreate(ish_intg, ish_intg, ish_intg);
BufferPointer  readerAddChar(BufferPointer const, ish_cha);
ish_bool       readerClear(BufferPointer const);
ish_bool       readerFree(BufferPointer const);
ish_bool       readerIsFull(BufferPointer const);
ish_bool       readerIsEmpty(BufferPointer const);
ish_bool       readerSetMark(BufferPointer const, ish_intg);
ish_intg       readerPrint(BufferPointer const);
ish_intg       readerLoad(BufferPointer const, FILE* const);
ish_bool       readerRecover(BufferPointer const);
ish_bool       readerRetract(BufferPointer const);
ish_bool       readerRestore(BufferPointer const);
ish_void       readerChecksum(BufferPointer const);  // Corrected
/* Getters */
ish_cha        readerGetChar(BufferPointer const);  // Corrected
ish_thread     readerGetContent(BufferPointer const, ish_intg);  // Corrected
ish_intg       readerGetPosRead(BufferPointer const);
ish_intg       readerGetPosWrte(BufferPointer const);
ish_intg       readerGetPosMark(BufferPointer const);
ish_intg       readerGetSize(BufferPointer const);
ish_intg       readerGetInc(BufferPointer const);
ish_intg       readerGetMode(BufferPointer const);
ish_byte       readerGetFlags(BufferPointer const);
ish_bool       readerPrintStat(BufferPointer const);
ish_intg       readerNumErrors(BufferPointer const);

#endif