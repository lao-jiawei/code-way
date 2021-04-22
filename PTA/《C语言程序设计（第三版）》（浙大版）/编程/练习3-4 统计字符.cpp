#include<stdio.h>
#include<math.h>
int main()
{
	int letter,blank,digit,other;
	char word;
	letter=blank=digit=other=0;
	for(int i=0;i<10;i++)
	{
		word=getchar();//Öð¸öÈ¡×Ö·û
		if((word>='a'&&word<='z')||(word>='A'&&word<='Z'))
		{
			letter++;
		}else if(word==' '||word=='\n')
		{
			blank++;
		}else if(word>='0'&&word<='9'){
			digit++;
		}else{
			other++;
		}
	}//for
	printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
	return 0;
}