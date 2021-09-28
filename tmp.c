#include <libc.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_len_nb(int long nb, int len_base)
{
	int	i;

	i = 1;
	if (nb < 0)
		nb *= -1;
	while (nb >= len_base)
	{
		nb = nb / len_base;
		i++;
	}
	return (i);
}

void	rev_tab(char *tab)
{
	char	temp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (tab[j + 1] != '\0')
	{
		j++;
	}
	if (tab[0] == '-')
		i++;
	while (j >= i)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		j--;
		i++;
	}
}

char	*ft_neg(int long new, char *base, char *tab_itoa, int base_to)
{
	int	sign;
	int	len;

	sign = 1;
	len = ft_len_nb(new, ft_strlen(base));
	if (new < 0)
	{
		new *= -1;
		sign *= -1;
		len++;
	}
	else
		len--;
	len = 0;
	while (new >= base_to)
	{
		tab_itoa[len] = base[new % base_to];
		new = new / base_to;
		len++;
	}
	tab_itoa[len] = base[new % base_to];
	return (tab_itoa);
}

char	*ft_itoa_base(int nb, char *base)
{
	long int	new;
	int			len;
	char		*tab_itoa;
	int			base_to;
	int			neg;

	neg = 0;
	new = nb;
	len = ft_len_nb(new, ft_strlen(base));
	if (nb < 0)
		neg = 1;
	base_to = ft_strlen(base);
	tab_itoa = malloc(sizeof(char) * (len + 1 + neg));
	if (tab_itoa == NULL)
		return NULL;
	tab_itoa = (ft_neg(new, base, tab_itoa, base_to));
	if (neg)
		tab_itoa[len] = '-';
	tab_itoa[++len] = '\0';
	return (tab_itoa);
}

int	ft_base_position(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
	i++;
	}
	while (ft_base_position(str[i], base) >= 0)
	{
		res = (res * ft_strlen(base)) + (ft_base_position(str[i], base));
		i++;
	}
	return (res * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int tmp;
	char *noushka;

	tmp  = ft_atoi_base(nbr, base_from);
	noushka = ft_itoa_base(tmp, base_to);
	rev_tab(noushka);
	return (noushka);
}

int main(int argc, char **argv)
{
	(void)argc;
	printf("try %s | %s | %s\n", "-345", "0123456789", "0123456789ABCDEF");
	printf("%s\n", ft_convert_base("-345", "0123456789", "0123456789ABCDEF"));
	printf("-----------\n");
	printf("try %s | %s | %s\n", "-345", "0123456789ABCDEF", "0123456789");
	printf("%s\n", ft_convert_base("-345", "0123456789ABCDEF", "0123456789"));
	printf("-----------\n");
	printf("try %s | %s | %s\n", "-48", "0123456789", "0123456789ABCDEF");
	printf("%s\n", ft_convert_base("-48", "0123456789", "0123456789ABCDEF"));
	printf("-----------\n");
	printf("try %s | %s | %s\n", "1001010", "01", "0123456789");
	printf("%s\n", ft_convert_base("1001010", "01", "0123456789"));
	printf("-----------\n");
	printf("try %s | %s | %s\n", "-2a", "0123465789abcdef", "01");
	printf("%s\n", ft_convert_base("-2a", "0123465789abcdef", "01"));
	printf("-----------\n");
	printf("try %s | %s | %s\n", "789", "0123456789", "01");
	printf("%s\n", ft_convert_base("789", "0123456789", "01"));
	//printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));

	return 0;
}
