/*
Question	#7
To	find	and	print	the	sum	of	the	first	1000	odd	numbers.

 Pseudo	Code
 Loop	from	1	until	1000	(including	the	1000)
 If	the	current	number	is	odd	by	checking	the	residue	is	not	0	when	dividing
 by	2
 Add	the	current	odd	number	to	the	count
 Write	the	result	in	the	console
 Exit
 */
//Code
#include	<stdio.h>
int	main	(void)
{
    int	result	=	0,	i	=	1;
    for(i;	i	<=	1000;	i++)
    {
        if(i%2	!=	0)
            result	+=	i;
    }
    printf("Result	=	%d\n",	result);
    return	0;
}