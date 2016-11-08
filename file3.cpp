#include <stdio.h>
#include <ctype.h>

main(){
	FILE *fr, *fw;
	int upper=0, lower=0, digits=0, chars=0, rows=0, words=0, sent=0;
	fr=fopen("data.txt","r");
	if(fr==NULL){
		printf("ERROR, file issue!");
		return 1;
	}
	fw=fopen("result.txt", "w");
	if(fw==NULL){
		printf("ERROR, file issue!");
		return 1;
	}
	char c;
	while((c=fgetc(fr))!=EOF){
		putchar(c);
		if(isdigit(c))
			digits++;
		else if(isalpha(c)){
			if(isupper(c))
				upper++;
			else
				lower++;
		}
		if(c!='\n')
			chars++;
		if(c=='\n')
			rows++;
		if(c==' ' || c=='\n')
			words++;
		if(c=='.')
			sent++;
		fputc(~c, fw);
	}
	printf("\nDigits: %d \nUppercase letters: %d \nLowercase letters: %d \nRows: %d \nAll chars: %d \nWords: %d \nSentences: %d"
		, digits, upper, lower, rows, chars, words, sent);
	fclose(fw);
	fclose(fr);
}
