
/* 
 * File:   bistromathique.h
 * Author: tmugadza
 *
 * Created on April 29, 2016, 12:24 AM
 */



#ifndef BISTROMATHIQUE_H
# define BISTROMATHIQUE_H

# define SYNTAXE_ERROR_MSG "syntax error\n"
#include "exp.h"
#include "t_list.h"
#include "mbase.h"
#include "vector.h"

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
char	*ft_int_to_str(int nb);
int		ft_strlen(char *str);
int		ft_nb_to_str_len(int nb);
int		eval_expr_deep(char *str);
int		get_total(int *tab_nbr, int *tab_op, int count[]);
int		rank(int c);
int		calcul(int a, int b, int c);
int		*get_op(char *str, int count[]);
int		get_str_in_parenthesis(char *str, int *beg, int *end);
char	*get_string(char *str, int beg, int end);
char	*update_formula(char *str, int beg, int end, int total);
int		ctoop(char c);
void	count_nb_and_op(char *str, int count[]);
int		*get_nbr(char *str, int count[]);
int eval_expr(char *base, char *ops, char *expr);
void	dstryM(mbase* m);
exp	getEx(char *av,int *ac);
int f_sl(char *c);
#endif

