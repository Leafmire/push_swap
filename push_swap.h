#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define A 1
# define B 2
# define ALL 3

typedef struct s_node {
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_count
{
	int				ra;
	int				pb;
	int				pa;
	int				rb;
}					t_count;

typedef struct s_stack {
	t_node	*head;
	t_node	*tail;
	int		length;
	int		temp_len;
	int		median;
	t_node	*top;
}	t_stack;

int		ft_isdigit(int c);
int		ft_strlen(const char *s);
int		ft_lstsize(t_stack *stack);
int		Max(int a, int b, int c);
int		Min(int a, int b, int c);
int		check_input(int argc, char **argv, t_stack *stack_a);
int		check_sorted(t_stack *a);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	push(t_stack *stack, int num);
int		pop(t_stack *stack);
void	show(t_stack *stack);
void	show_all(t_stack *a, t_stack *b);
void	swap_stack(t_stack *stack);
void	push_stack(t_stack *out, t_stack *put);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *a);
void	set_mid(t_stack *a);
int		calc_range_ba(int range, t_stack *a, t_stack *b);
void	push_swap_ab(t_stack *a, t_stack *b, int range);
void	push_swap_ba(t_stack *a, t_stack *b, int range);
#endif
