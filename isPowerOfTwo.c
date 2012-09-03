/*
Question	#3:
To	receive	a	number	and	determine	if	it	is	a	power	of	2	or	not.

 Pseudo	Code
 Prompt	user	for	input
 Loop	dividing	by	2	until	the	decimal	division	and	the	integer	division	are	the	same
 If	the	decimal	division	and	the	integer	division	are	both	1
 The	number	is	a	power	of	2
 Exit
 Is	not	a	power	of	2
 Exit
 */

//Code
#include	<stdio.h>
#include	<math.h>
int	main	(void)
{
    int	m,	result;
    float	fresult;
    printf("Insert	value	to	be	tested\n");
    scanf("%d",&m);
    do{result =	m/2.0;
        fresult	=	m/2.0;
        m	/=	2;
        //printf("%d	- %f\n",	result,	fresult);
        if(fresult	==	1	&&	result	==	1)
        {
            printf("It's	a	power	of	2\n");
            return	0;
        }
    }while(fresult	==	result);
    printf("Not	a	power	of	2\n");
    return	0;
}