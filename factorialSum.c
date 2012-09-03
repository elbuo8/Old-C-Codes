/*
Question	#8
To	find	and	print	the	sum	of	factorials	of	integers	from	1	to	10.

 Pseudo	Code
 Loop	from	1	until	10
 Loop	from	1	until	the	index	number	from	the	main	loop
 Multiply	the	current	number	with	the	past	result	starting	on	1
 Add	the	result	from	the	second	loop
 Write	the	result	in	the	console
 Exit
 */
//Code
#include	<stdio.h>
int	main (void)
{
    int	j	=	1,	i	=	1,	factorial	=	1;
    long	result	=	0;
    for(i;	i	<=	10;	i++)
    {
        factorial	=	1;
        for(j	=	1;	j	<=	i;	j++)
            factorial	*=	j;
        result	+=	factorial;
    }
    printf("Result	is	%ld\n",result);
    return	0;
}