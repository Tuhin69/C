# C
//Program to convert decimal numbers (max 9 lakhs) in words
# include <stdio.h>
# include <string.h>
# include <malloc.h>
char *units[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
char *tens[] = {"","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char *multiples[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
char *powers[] = {"","","","hundred","thousand","","lakhs","","crores"};
char *zero_eliminator(char *num){
	while(*num =='0')
		num++;	
	return num;
}
void one_digit_(char *num){
	printf("%s ", units[*num - '0']);
	return;
}
void two_digits_(char *num){	
	if (*num == '1') {
        int sum = *num - '0' + *(num + 1) - '0';
        printf("%s ", tens[sum]);    
    }else if (*num == '2' && *(num + 1) == '0'){	
        printf("twenty ");    
    }else{
        int i = *num - '0';
        printf("%s ", i ? multiples[i] : "");
        ++num;
        if (*num != '0')
            printf("%s ",units[*num - '0']);
    }
    return;
}
void three_digits_(char *num){
	num = zero_eliminator(num);	
	int len = strlen(num);
	if(len==3){	
		one_digit_(num);
		printf("%s ",powers[len]);	
		num++;
		two_digits_(num);
	}else if(len==2)
		two_digits_(num);
	else if(len==1)
		one_digit_(num);			
    return;
}
char *next_two_(char *num){
	char *n = (char*)malloc(sizeof(char)*2);
	int i=0;
	for(;i<2;i++){				
		*(n+i) = *num;
		num++;
	}
	two_digits_(n);
	return num;
}
void word_converter(char *num){	
	num = zero_eliminator(num);
	int len = strlen(num);
	switch(len){
		case 1: one_digit_(num); break;
		case 2: two_digits_(num); break;
		case 3: three_digits_(num); break;
		case 4: one_digit_(num);
				printf("%s ",powers[len]);
				num++;
				three_digits_(num);						
				break;
		case 5: num = next_two_(num);
				printf("%s ",powers[len-1]);
				three_digits_(num);						
				break;				
		case 6: one_digit_(num);
				printf("%s ",powers[len]);
				num++;
				num = next_two_(num);
				printf("%s ",powers[len-2]);
				three_digits_(num);						
				break;				
	} 
	return;
}
int main(){
	char dec[10];
	char cont;
	do{
		printf("Enter a decimal number (0 - 9,99,999) : ");
		scanf("%[^\n]%*c",&dec);
		fflush(stdin);
		if (strlen(dec)==0){
			fprintf(stderr,"empty string\n");
			continue;
		}
		if(strlen(dec)>6){
			fprintf(stderr,"To long to convert\n");
			continue;
		}
		word_converter(dec);
		printf("\nCheck any more? (y/n) : ");
		scanf("%c",&cont);
		fflush(stdin);		
	}while(cont == 'y' || cont =='Y');
	return 0;
}       

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
