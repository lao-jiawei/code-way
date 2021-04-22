#include <stdio.h>

int CountDigit( int number, int digit );

int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

    return 0;
}

int CountDigit( int number, int digit ){
    int count=0,remainder;

    if(number<0){
        number*=-1;              //去负号
    }
    while(number>10){             
        remainder=number%10;         //通过求余数将一长串的数，拆分成一个一个的数来比较
        number=number/10;            //每拆分一个数，就减少一个数。
        if(remainder==digit){        //如果拆分出的数等于想要求的数，则计数加一。
            count=count+1;
        }
    }
    if(number==digit){              //最后一位如果等于所求的数，计数加一。
        count=count+1;
    }

    return count;
}
