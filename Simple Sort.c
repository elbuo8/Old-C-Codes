/*
 Question	#1:
 To	receive	3	numbers	from	the	console,	sort	them	in	ascending	order,	and	print	the
 result.
 
 Pseudo-code
 Allocate	memory	for	3	inputs
 Prompt	user	for	3	inputs
 Read	3	inputs	from	user/console
 Loop	until	m	remains	the	same	(No	swap	happened)
 Loop	from	the	second	input	up	to	the	third
 If	the	first	input	is	bigger	than	the	second	input
 Perform	a swap	in	value	of	inputs	and	change	value	of	m
 Loop	from	the	first	input	up	to	the	third
 Write	value	in	console
 Exit
 */
//Code

#include	<stdio.h>

int	main	(void) {
	int	array[3];
	int	i;
	printf("Insert	3	inputs\n");
	
	for(i	=	0;	i	<	3;	i++)
		scanf("%d",&array[i]);
	
	//	bubble	sort
	int	n	=	3;
	do {
        int	m	=	0;
        
        for(i	=	1;	i	<=	n-1;	i++) {
            if(array[i-1]	>	array[i]) {
                int	temp	=	array[i-1];
                array[i-1]	=	array[i];
                array[i]	=	temp;
                m	=	i;
            }
        }
        n	=	m;
	}while(n	!=	0);
	
    printf("\nSorted	list\n");
	
    for(i	=	0;	i	<	3;	i++)
        printf("%d\n",array[i]);
	
    return	0;
}