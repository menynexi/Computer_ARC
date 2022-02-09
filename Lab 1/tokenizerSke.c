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
	//test statement
	printf("hello I am in word_start\n");
	
	//increments till you have a non delimiting character
	char *point = str;
	while(delim_character(*point,delim)){
		point++;
	}
	printf("%c\n",*point);
	return point;
}

/* Returns a pointer to the first delimiter character of the zero
   terminated string*/
char *end_word(char* str,char delim)
{
	//test statements 
	printf("hello I am in end_word\n");	
	char *point = str;
	printf("%c",*point);
	
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
	printf("%d\n",count);
	return count;
}

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
// hello world -> hello 
char *copy_str(char *inStr, short len, char delim)
{
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
	//this should create enough memory for the amount of tokens we want
	//note to self (does not incude 0 terminator)
	char**  tokens = (char**)malloc(count_tokens(*str,delim));
	char* start = *str;
	//you get the end of the current start word
	char* end =  end_word(*start,delim);


}

void print_all_tokens(char** tokens)
{

}

void main(){
        bool is_delim = delim_character(' ',' ');
        printf("%d\n",is_delim);
	char word[] = "hello world\0";
	char *c = word;
	printf("%c\n",*c);
	printf("%p\n",c);
	printf("%s\n",word_start(c,' '));
	printf("%s\n",end_word(c,' '));
	printf("%d\n",count_tokens(c,' '));
	printf("%s\n",copy_str(c,5,' '));
}
