//Illustration of local and global variable
# include <stdio.h>
int a = 100; //global, declared outside of all functions
void disp1(){
	int a = 200; //local to disp()
	printf("\nValue of a in disp() = %d",a);
}
void disp2(){
	//no redeclaration of a, hence takes the global
	printf("\nValue of a in disp2() = %d",a);
	{		
		printf("\nValue of a in disp2() {} block } = %d",a*100);
	}
}
int main(void){
	int a = 300; //local to main()
	disp1();
	printf("\nValue of a in main() = %d",a);
	{
		int a = 1000; //local to {} block
		printf("\nValue of a in {} block = %d",a);
	}	
	disp2();
}
