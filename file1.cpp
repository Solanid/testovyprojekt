#include <stdio.h>
#include <ctype.h>

main(){
	int size=50, max, c;
	int max2=0, x;
	FILE *fr, *fw;
	int i;
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
	size=0;max=0;
	while(fscanf(fr,"%d", &max)!=EOF){
		if(max2<max)
			max2=max;
		size++;
	}
	printf("maximum je :%d\n", max2);
	if(size==0){
		printf("File dont have any numbers.");
		return 0;
	}
	int numbers[size];
	printf("size is: %d", size);
	rewind(fr);
	for(i=0;i<size;i++){
		fscanf(fr,"%d", &numbers[i]);
		printf("\n%d ", numbers[i]);
	}
	i=0;
	int sizepola=0;
	while(numbers[i]!='\0'){
		i++;
		sizepola++;
	}
	max=numbers[0];
	for(i=1;i<sizepola-2;i++){
		if(max<numbers[i]){
			max=numbers[i];
		}
	}
	printf("\nMaximum is: %d", max);
	fclose(fw);
	fclose(fr);
}
