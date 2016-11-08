#include <stdio.h>
#include <ctype.h>

main(){
	FILE *fr, *fw;
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
		if(islower(c))
			c=toupper(c);
		else
			c=tolower(c);
		fputc(c, fw);
	}
	fclose(fw);
	fclose(fr);
}
