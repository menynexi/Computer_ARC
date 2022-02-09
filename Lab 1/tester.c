#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tokenizerSke.c"

void main(){
	bool is_delim = delim_character(' ',' ');
	printf("%d\n",is_delim);
}
