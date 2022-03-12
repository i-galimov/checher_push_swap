#include "../inc/push_swap.h"

int	checker_cmd(char *line, t_list **a, t_list **b)
{
	if (!(ft_strcmp(line, "ra")))
		ft_ra(a);
	else if (!(ft_strcmp(line, "rb")))
		ft_rb(b);
	else if (!(ft_strcmp(line, "rr")))
		ft_rr(a, b);
	else if (!(ft_strcmp(line, "sa")))
		ft_sa(a);
	else if (!(ft_strcmp(line, "sb")))
		ft_sb(b);
	else if (!(ft_strcmp(line, "ss")))
		ft_ss(a, b);
	else if (!(ft_strcmp(line, "rra")))
		ft_rra(a);
	else if (!(ft_strcmp(line, "rrb")))
		ft_rrb(b);
	else if (!(ft_strcmp(line, "rrr")))
		ft_rrr(a, b);
	else if (!(ft_strcmp(line, "pa")))
		ft_pa(a, b);
	else if (!(ft_strcmp(line, "pb")))
		ft_pb(a, b);
	else
		return (0);
	return (1);
}

int	checker_gnl(t_list **a, t_list **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!(checker_cmd(line, a, b)))
		{
			free(line);
			line = NULL;
			return (0);
		}
		free(line);
		line = NULL;
	}
	return (1);
}

int	clean_checher(t_list *a)
{
	free_list(a);
	write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	*s;
	t_list	*a;
	t_list	*b;

	if (argc < 2)
		ft_arg_error();
	s = malloc(sizeof(s));
	if (!s)
		return (0);
	ft_arg_conv(0, 0, argv, &s);
	save_value(&s.a, &s);
	if (!a)
		return (clean_checher(a));
	if (checker(&a, &b) == 0)
		return (clean_checher(a));
	if (a && ft_is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	if (b)
		free_list(b);
	free_all(a);
	free_list(s.a);
	free(s.arg);
	return (0);
}
