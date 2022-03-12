# include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_is_sorted(t_all *s)
{
	int	i;

	i = 0;
	while (i < s->len - 1)
	{
		if (s->arg[i] > s->arg[i + 1])
			return (1);
		i++;
	}
	return (0);
}
