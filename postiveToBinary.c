/*
Question	#4
To	receive	a	non- negative	integer	number	and	print	its	binary	
 Pseudo	Code
 Prompt	user	for	input
 Loop	until	the	input	is	a	positive	number
 Allocate	space	to	store	binary	number
 Loop	dividing	the	input	by	2	until	the	value	of	the	input	is	no	longer	bigger	than	0
 Store	the	recidual	of	the	divison	by	2	of	the	current	input
 Loop	from	the	first	stored	value	to	the	last	one
 Write	the	current	stored	value
 Exit
 *///Code
#include	<stdio.h>
int	main	(void) {
    int	m;
    printf("Insert	a	non	negative	integer\n");
    do{
        scanf("%d",&m);
    }while(m	<	0);
    int	a[10]
	int i	=	0;
    while(m	>	0) {
        a[i]	=	m%2;
        m=m/2;
        i++;
    }
    i	=	i-1;
    printf("\nBinary	number\n");
    for(i;	i	>=	0;	i--)
        printf("%d",a[i]);
    printf("\n");
    return	0;
}