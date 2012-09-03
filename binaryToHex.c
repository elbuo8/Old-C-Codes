/*
Question	#6:
To	receive	an	8-bit	binary	number	and	print	its	hexadecimal	representation.

 Pseudo	Code
 Designate	memory	for	the	input	and	the	output
 Prompt	user	for	input
 Create	2	slots	to	store	numbers
 Loop	from	slot	1	until	2
 Loop	4 times
 Verify	if	it's	a	0	or	a	1	and	save	the	value
 Multiply	the	value	with	the	according	power	of	10
 (1000,100,10,1)
 Add	it	up	to	the	current	slot
 Loop	through	the	2	slots
 Find	the	equivalent	HEX
 Store	it	in	the	output	space
 Write	the	output	in	the	console
 Exit
 */
//Code
#include	<stdio.h>
int	main	(void)
{
    char	input[8],	output[2];
    printf("Insert	8-bit	binary	number\n");
    scanf("%s",input);
    int	a[2],	i	=	0,	k	=	0,	z	=	0;
    for(i;	i	<	2;	i++)
    {
        a[i]	=	0;
        int	j	=	1000;
        for(	z	=	0;	z	<	4;	z++	)
        {
            int	v;
            if(input[k]	==	'0')
                v	=	0;
            else	if(input[k]	==	'1')
                v	=	1;
            v	*=	j;
            a[i]	+=	v;
            j	/=	10;
            k++;
        }
    }
    for(	i	=	0;	i	<	2;	i++)
    {
        if(a[i]	==	0000)
            output[i]	=	'0';
        else	if(a[i]	==	0001)
            output[i]	=	'1';
        else	if(a[i]	==	0010)
            output[i]	=	'2';
        else	if(a[i]	==	0011)
            output[i]	=	'3';
        else	if(a[i]	==	0100)
            output[i]	=	'4';
        else	if(a[i]	==	0101)
            output[i]	=	'5';
        else	if(a[i]	==	0110)
            output[i]	=	'6';
        else	if(a[i]	==	0111)
            output[i]	=	'7';
        else	if(a[i]	==	1000)
            output[i]	=	'8';
        else	if(a[i]	==	1001)
            output[i]	=	'9';
        else	if(a[i]	==	1010)
            output[i]	=	'A';
        else	if(a[i]	==	1011)
            output[i]	=	'B';
        else	if(a[i]	==	1100)
            output[i]	=	'C';
        else if(a[i]	==	1101)
            output[i]	=	'D';
        else	if(a[i]	==	1110)
            output[i]	=	'E';
        else	if(a[i]	==	1111)
            output[i]	=	'F';
        printf("%c",output[i]);
    }
    printf("\n");
    return	0;
}