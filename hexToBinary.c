/*

Question	#5:
To	receive	a	2	digit	hexadecimal	number	and	print	its	binary representation.
/*
 Pseudo	Code
 Prompt	user	for	a	2	digit	Hex	Number
 Loop	from	the	first	digit	to	the	second	digit
 Find	the	equivalent	of	the	current	digit
 Write	the	equivalent	value	on	the	console
 Exit
 */
//Code
#include	<stdio.h>
int main	(void)
{
    int	i	=	0;
    char	input[2];
    printf("Insert	a	2	digit	Hex	number\n");
    scanf("%s",	input);
    printf("Binary	equivalent\n");
    for(i;	i	<	2;	i++)
    {
        if(input[i]	==	'0')
            printf("0000");
        else	if(input[i]	==	'1')
            printf("0001");
        else	if(input[i]	==	'2')
            printf("0010");
        else	if(input[i]	==	'3')
            printf("0011");
        else	if(input[i]	==	'4')
            printf("0100");
        else	if(input[i]	==	'5')
            printf("0101");
        else	if(input[i]	==	'6')
            printf("0110");
        else	if(input[i]	==	'7')
            printf("0111");
        else	if(input[i]	==	'8')printf("1000");
        else	if(input[i]	==	'9')
            printf("1001");
        else	if(input[i]	==	'A')
            printf("1010");
        else	if(input[i]	==	'B')
            printf("1011");
        else	if(input[i]	==	'C')
            printf("1100");
        else	if(input[i]	==	'D')
            printf("1101");
        else	if(input[i]	==	'E')
            printf("1110");
        else	if(input[i]	==	'F')
            printf("1111");
    }
    printf("\n");
    return	0;
}