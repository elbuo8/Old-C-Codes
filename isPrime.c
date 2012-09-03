/*
Question	#2:
To	receive	an	integer	number	and	determine	if	it	is	a	prime	number	or	not.

 Pseudo	Code
 Prompt	user	for	input	to	be	verified
 Loop	from	2	up	to	the	input	minus	1
 Divide	the	input	by	2
 If	the	decimal	division	is	the	same	as	the	integer	division
 The	number	is	not	prime
 The	number	is	prime
 Exit
 */
//Code
#include	<stdio.h>
int	main	(void)
{
    int	m;
    float	i	=	2;
    float	fresult;
    int	result;
    printf("Insert	number	to	check	if	it's	prime\n");
    scanf("%d",&m);
    for(i	=	2;	i	<	m-1;	i++)
    {
        result	=	m/i;
        fresult	=	m/i;
        //printf("%d\n",	result);
        //printf("%f\n",	fresult);
        if(result	==	fresult)
        {
            printf("Number	is	not	prime\n");
            return	0;
        }
    }
    printf("Number	is	prime\n");
    return	0;
}
