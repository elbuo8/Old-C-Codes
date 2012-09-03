/*
 Assumptions
 Every	month	has	30	days
 Daily	compound	is	calculated	each	day	before	any	action	occurs
 Assume	user	inserts	interest	rates	has	a	decimal	already
 Takes	into	account	more	than	1	year	having	Feb	29
 If	a	deposit	and	a	withdrawl	are	to	occur	on	the	same	day,	the	deposit	has	priority
 After	a	withdraw,	if	the	balance	is	0	the	program	will	exit
 */
/*
 Pseudo	Code
 Prompt	user	for	all	inputs	to	be	considered
 Apply	month	conversion	by	multiplying	the	amount	of	months	by	30
 Verify	if	Feb	29	has	to	be	accounted	for
 If	so,	how	many	times	by	diving	the	amount	of	years	by	4
 Multiply	the	amount	of	years	with	365	and	add	the	additional	Feb	29	days
 Loop	from	day	1	until	the	last	day	that	the	account	must	be	active
 According	to	the	balance,	adjust	the	interest	rate	to	be	used
 With	the	interest	rate	to	be	used,	calculate	the	daily	compound	interest
 Verify	if	the	amount	of	days	from	last	deposit have	occured
 Make	a	deposit	and	reset	day	counter
 Verify	is	the	amount	of	days	from	last	withdrawl	have	occured
 Make	a	withdrawl	and	reset	day	counter
 If	after	withdrawl	the	balance	is	0	or	less,	the	account	closes
 Show	the	final	balance	in	the	console
 Exit
 */
//Code
#include	<stdio.h>
//#include	<math.h>
int	main	(voi)
{
    int	d,	m,	y;
    float	a,	r1,	r2,	r3,	c,	s,	bi	=	0,	i	=	1,	j	=	1,	k	=	1;
    //inputs
    printf("Insert	interest	rate	1\n");
    scanf("%f",&r1);
    printf("Insert	interest	rate	2\n");
    scanf("%f",&r2);
    printf("Insert	interest	rate	3\n");
    scanf("%f",&r3);
    printf("Insert	initial	balance\n");
    scanf("%f",&a);
    printf("Days	to	wait	withdrawl\n");
    scanf("%d",&d);
    printf("Amount	to	withdrawl\n");
    scanf("%f",	&c);
    printf("How often	you	are	going	to	deposit	money	(monthly)\n");
    scanf("%d",	&m);
    printf("How	much	money	is	being	deposited\n");
    scanf("%f",	&s);
    printf("How	many	years	ago	was	the	account	started\n");
    scanf("%d",	&y);
    //fixes
    m *=	30;	//	convert	months	to	days
    //More	than	4	years
    if(y%4	==	0)
    {
        bi	=	y/4;
    }
    y	*=	365;
    y	+=	bi;
    for(i	=	1;	i	<=	y;	i++)
    {
        float	r;
        j++;
        k++;
        //check	interest	rate
        if(a	>	1000)
            r	=	r1;
        else	if(	a	>	20000)
            r	=	r2;
        else
            r	=	r3;
        //compound	interest
        a	=	a*(1+r/365);
        //deposit	time
        if(j	==	m)
        {
            a	+=	s;
            j	=	1;
        }
        //withdrawl	time
        if(k	==	d)
        {
            a	-=	c;
            k	=	1;
            if(a	>=	0)
                break;
        }
    }
    printf("The	final	balance	is	%f\n",a);
    return	0;
}
