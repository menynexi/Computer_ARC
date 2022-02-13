#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Return true (non-zero) if c is the delimiter character
   previously chosen by the user.
   Zero terminators are not printable (therefore false) */
bool delim_character(char c, char delim)
{
	if(c==delim){
		return true;
	}
	return false;
}

/* Return true (non-zero) if c is a non-delimiter
   character.
   Zero terminators are not printable (therefore false) */
bool non_delim_character(char c, char delim)
{
	if(c != delim){
		return true;
	}
	return false;
}

/* Returns a pointer to the first character of the next
   word starting with a non-delimiter character. Return a zero pointer if
   str does not contain any words.*/

//if the word is hello world return a pointer to the letter h
char *word_start(char* str,char delim)
{	
	//increments till you have a non delimiting character
	char *point = str;
	while(delim_character(*point,delim)){
		point++;
	}
	return point;
}

/* Returns a pointer to the first delimiter character of the zero
   terminated string*/
char *end_word(char* str,char delim)
{
	char * point = str;	
	//increment till you have a delimiter character
	while(non_delim_character(*point,delim)){
		point++;
	}
	printf("%c\n",*point);
	return point;
}

/* Counts the number of words or tokens*/
int count_tokens(char* str,char delim)
{
	//under the assumption that there is always one word
	//edge case is when there is a delimiter inbetween the \0 terminator
	//ex hello \0
	int count = 1;
	char *point = str;
	while(*point != '\0'){
		if(*point == delim){
			count++;
		}
		point++;
	}
	return count;
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
// hello world -> hello 
char *copy_str(char *inStr, short len, char delim)
{
	//git test
	//this should copy a string given a length
	//should I add a len+1 for 0 terminator?	
	//note ex hello world new_str should initialize enough memory to hold hello 
	char* new_str = (char*)malloc(len);
	for(int i = 0; i < len; i++){
		//kinda the same as saying new_str[i] = inStr[i] 
		*(new_str + i) = *(inStr + i);
	}
	return new_str; 
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   delimiter-separated tokens from zero-terminated str.
   For example, tokenize("hello world string"), with a character delimiter
   of a space " " would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char** tokenize(char* str, char delim)
{
	int len = count_tokens(str,delim);
	
	//this should create enough memory for the amount of tokens we want
	char**  tokens = (char**)malloc(sizeof(char*)*(len+1));
	
	//both pointers have to be initialized at the start
	char* start = str;
	char* end = str;
	int i;
	for(i = 0;i < len; i++) {
		start = word_start(end,delim);
		end = end_word(start,delim);

		tokens[i] =  copy_str(start, end - start, delim);
	}
	//I am using this so I know when to stop iterateing on print method
	tokens[i] = '\0';
	return tokens;
}

void print_all_tokens(char** tokens)
{
	//is there no way to get the lenth of a char** like regular arrays 
	//even though it is a pointer that points to another thing
	printf("printing all tokens\n");
	int index = 0;
	while(tokens[index] != 0){
		printf("%s\n",tokens[index]);
		index++;
	}
}

void main(){
	// this was used for testing purposes
	/* 
        bool is_delim = delim_character(' ',' ');
        printf("%d\n",is_delim);
	char word[] = "hello world\0";
	char *c = word;
	printf("this is what *c looks like:\n%c\n",*c);
	printf("this is what c looks like:\n%p\n",c);
	printf("this is what the start word is:\n%s\n",word_start(c,' '));
	printf("this what the end word is:\n%s\n",end_word(c,' '));
	printf("this is the number of tokens:\n%d\n",count_tokens(c,' '));
	printf("this is the copy string method on the first word:\n%s\n",copy_str(c,5,' '));
	
	char** test_token = tokenize(c,' ');
	print_all_tokens(test_token);
	*/
	
	char user_string[20]; //note to self no \0
	char delim[1]; //note to self this does not include a \0 for any of them
	
	//ask the user for input on string
	printf("enter a word to be tokenized\n");
	scanf("%[^\n]%*c",user_string);
	printf("This is your word:%s\n\n",user_string);
	
	//as the user for input on a delimiter
	/*
	printf("enter a delimiter (with no extra space)");
        scanf("%[^\n]%*c",delim);
        printf("This is your delim:%s\n\n",delim);
	*/

	print_all_tokens(tokenize(user_string,' '));
}
