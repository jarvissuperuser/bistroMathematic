
/* 
 * File:   main.c
 * Author: tmugadza
 *
 * Created on April 28, 2016, 8:26 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "bistromathique.h"
#include "exp.h"
#include "t_list.h"
#include "mbase.h"
#include "vector.h"

/** string length of the first argument */
int	f_sl(char *c)
{
	int x;

	x = 0;
	while(c[x])
	{
		x++;
	}
	return x;
}

/** initialize vectors*/
void	initV(vector *v)
{
	v->a = 0;
	v->x = 0;
	v->y = 0;
	v->z = 0;
}

/** initialize rules*/
void	initM(mbase *m, char **argv)
{
	vector v;
	
	initV(&v);
	m->base = f_sl(argv[1]);
	m->dig = malloc(sizeof(char) * m->base);
	while (argv[1][v.z])
	{
		m->dig[v.z] = argv[1][v.z];
		v.z++;
	}
	v.a = f_sl(argv[1]);
	m->rules = malloc(sizeof(char) * (v.a));
	while (argv[2][v.y])
	{
		m->rules[v.y] = argv[2][v.y];
		v.y++;
	}
}


/**free up memory*/
void	dstryM(mbase *m)
{
	free(m->dig);
	free(m->rules);
}

exp	getEx(char *av,int *ac)
{
	exp e;
	char *c;
	int a;

	c = malloc(sizeof(char) * 4096);
	a = 0;
	if (av[*ac] == '(')
	while(av[++*ac] != '\0')
	{
		if (av[*ac] >= '0' && av[*ac]<= '9')
			c[a] = av[*ac];
		else 
		{
			if (e.res != 1)
			{
				e.val1 = atoi(c);
				e.res = 1;
				a = 0;
				while (c[a] > '\0')
				{
					c[a] = '\0';
					a++;
				}
				a = 0;
			}
			else
			{
				e.val2 = atoi(c);
			}
			e.op = av[*ac];
		}
		a++;
	}
	e.res = 0;
	return e;	
}
int		get_str_in_parenthesis(char *str, int *beg, int *end)
{
	int	i;
	int	flag_par;

	i = 0;
	*beg = 0;
	*end = 0;
	flag_par = 0;
	while (str[i])
	{
		if (str[i] == '(')
		{
			*beg = i + 1;
			flag_par = 1;
		}
		if (str[i] == ')')
		{
			*end = i - 1;
			break ;
		}
		i++;
	}
	return (flag_par);
}

/** find the expression */
t_list	loadExp(t_list lst, char **argv)
{
	vector v;
	
	initV(&v);
	while (argv[3][v.x])
	{
		if (argv[3][v.x] == '(')
			v.a = v.x;
		while (1)
		{
			if (argv[3][v.x] >= '0' && argv[3][v.x] <='9')
			{
				lst.ex = getEx(argv[3],&v.x);
				lst.nexp = "\0";
			}
			else
				break;
		}
		v.x++;
	}
	return lst;
}

int	main(int argc, char** argv) 
{
	mbase t_new;
	t_list lst;
	if (argc >= 3)
	{
		initM(&t_new,argv);
		if (argc > 3)
			lst = loadExp(lst,argv);
		eval_expr((char *)&t_new.base,t_new.rules,argv[3]);
		printf(" ?? %i\n",lst.ex.val1);
		dstryM(&t_new);
	}
	printf("end\n");
	return (EXIT_SUCCESS);
}
