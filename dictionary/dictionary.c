/* dictionary.c  - main, initw, nextin, insertw, deletew, lookupw  */

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

#define	MAXWORD  50			/* maximun length of a command or word */
#define	DICTSIZ 100			/* number of entries in dictionary */
char	dict[DICTSIZ][MAXWORD+1]; 	/* storage for a dictionary of words  */
char	dictm[DICTSIZ][MAXWORD+1]; 	/* storage for a dictionary of words - meaning part  */
int	nwords = 0;			/* number of word in the dictionary


/*---------------------------------------------------------
 * main - insert, delete, or lookup words in a dictionary as specified
 *---------------------------------------------------------
 */

int
main(argc, argv)
int	argc;
char	argv[];
{
	char word[MAXWORD+1];	/* space to hold word from input line*/
	char meaning[MAXWORD+1];	/* space to hold meaning from input line*/
	char cmd;
	int wrdlen;		/* length of input word		*/
	int index;
	printf("Commands\n---------\n");
	printf("Initialize the dictionary \t-- S\n");
	printf("Insert words dictionary \t-- i <word> <meaning>\n");
	printf("Lookup the words in dictionary \t-- l <word>\n");
	printf("Delete words from dictionary \t-- d <word>\n");
	printf("Quit the application \t\t-- q\n");
	printf("-----------------------------\n");

	while (1) {
	printf("\nCommand:");
		wrdlen = nextin(&cmd, word, meaning);
		if (wrdlen<0)
			exit(0);
		switch (cmd) {
		case 'S':	/* "initialize"  */
		case 's':
			initw();
			printf("Dictionary initialized with empty.\n");
			break;
		case 'i':	/* "insert"  */
		case 'I':
			insertw(word, meaning);
			printf("%s inserted successfully.\n",word);
			break;
		case 'd':	/* "delete"  */
			if ( deletew(word) )
				printf("%s deleted successfully.\n",word);
			else
				printf("%s not found.\n",word);
			break;
		case 'l':	/* "lookup"  */
		case 'L':
   			index = lookupw(word);
			if ( index >=0 ) {
				printf("%s was found.\n",word);
				printf("And its meaning is: %s.\n",dictm[index]);
			} else
				printf("%s was not found.\n",word);
			break;
		case 'q':	/* "quit"  */
		case 'Q':
			printf("program quits.\n");
			exit(0);
		default:		/* illegal input*/
			printf("Your command %c is invalid .\nPlease input valid command from given set.", cmd);
			break;
		}
	}
}
	
/*---------------------------------------------------------
 * nextin - read a command and (possibly) a word from the next input line
 *---------------------------------------------------------
 */
int
nextin(cmd, word, meaning)
char	*cmd, *word, *meaning;
{
	int i, ch, tempChar;

	ch = getc(stdin);
	while (ch== ' ')
		ch = getc(stdin);
	if (ch == EOF)
		return -1;
	*cmd = (char) ch;
	tempChar = ch;

	ch = getc(stdin);
	while (ch == ' ')
		ch = getc(stdin);
	if (ch == EOF)
		return -1;
	if (ch == '\n')
		return 0;
	i=0;
	while(ch != '\n') {
		if (++i > MAXWORD) {
			printf("error: word too long.\n");
			exit(1);
		}
		*word++ = ch;
		ch = getc(stdin);
		if(ch == ' ') {
			break;
		}
	}
	*word = '\0';

	i=0;
	if(tempChar == 'i') {
		while(ch != '\n') {
			if (++i > MAXWORD) {
				printf("error: meaning too long.\n");
				exit(1);
			}
			*meaning++ = ch;
			ch = getc(stdin);
		}
	}
	*meaning = '\0';

	return i;
}


/* -------------------------------------------------------------------
 *	initw - initialize the dictionary to contain no words at all
 * -------------------------------------------------------------------
 */
int
initw()
{
	nwords = 0;
	return 1;
}

/* -------------------------------------------------------------
 *	insertw - insert a word in the dictionary
 * ------------------------------------------------------------- 
 */
int
insertw(word, meaning)
char  *word, *meaning;
{
	int ret = lookupw(word);
	if(ret >= 0) {
		deletew(word);
	}

	strcpy(dict[nwords], word);
	strcpy(dictm[nwords], meaning);
	nwords++;
	return nwords;
}

/* ------------------------------------------------------------
 *	deletew - delete a word from the dictionary
 * -------------------------------------------------------------
 */
int
deletew(word)
char  *word;
{
	int i;

	for (i=0; i<nwords; i++)
		if ( strcmp(word, dict[i]) == 0) {
			nwords--;
			strcpy(dict[i], dict[nwords]);
			strcpy(dictm[i], dictm[nwords]);
			return 1;
		}
	return -1;
}


/* ------------------------------------------------------------------------- 
 *	lookupw - look up a word in the dictionary
 * -------------------------------------------------------------------------
 */
int
lookupw(word)
char  *word;
{
	int i;

	for (i=0; i<nwords; i++)
		if ( strcmp(word, dict[i]) == 0) 
			return i;
	return -1;
}


