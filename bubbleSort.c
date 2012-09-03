/*
Question	#9
To	receive	10	numbers	from	the	console,	sort	them	in	non-ascending	order,	and
print	the	result.

 Pseudo-code
 Allocate	memory	for	10	inputs
 Prompt	user	for	10	inputs
 Read	10	inputs	from	user/console
 Loop	until	m	remains	the	same	(No	swap	happened)
 Loop	from	the	second	input	up	to	the	tenth
 If	the	first	input	is	second	than	the	second	input
 Perform	a	swap	in	value	of	inputs	and	change	value	of	m
 Loop	from	the	first	input	up	to	the	tenth
 Write	value	in	console
 Exit
 */
//Code
#include	<stdio.h>
int	main	(void)
{
    int	array[10];
    int	i;
    printf("Insert	10	numbers	to	be	sorted\n");
    for(i	=	0;	i	<	10;	i++)
    {
        scanf("%d",&array[i]);
    }
    int	m	=	10;
    do{
        int	n	=	0;
        for(i	=	1;	i	<=	m	- 1;	i++)
        {
            if(array[i-1]	<	array[i])
            {
                int	temp	=	array[i-1];
                array[i-1]	=	array[i];
                array[i]	=	temp;
                n	=	i;
            }
        }
        m	=	n;
    }while(m!=0);
    printf("\nSorted	list\n");
    for(i=0;	i<10;i++)
        printf("%d\n",array[i]);
    return	0;
}