#include <libc.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int		ft_len_nb(int nb)
{
	int i;

	i = 1;
	while(nb >= 9)
	{
		nb = nb / 10;
		i++;
	}
	return i;
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

char	*ft_itoa_base(int nb, char *base)
{
	int long new;
	int len;
	char *tab_itoa;
	int base_to;
	int sign;

	sign = 1;
	new = nb;
	len = ft_len_nb(new);
	base_to = ft_strlen(base);
	tab_itoa = malloc(sizeof(char) * (len + 1));
	if (tab_itoa == NULL)
		return NULL;
	if (new < 0)
	{
		new *= -1;
		sign *= -1;
		len++;
	}
	else
		len--;
	tab_itoa[len] = '\0';
	len = 0;
	while (new > base_to)
	{
		tab_itoa[len] = base[new % base_to];
		new = new / base_to;
		len++;
	}
	tab_itoa[len] = base[new % base_to];
	if (sign == -1)
		tab_itoa[0] = '-';
	return (tab_itoa);
}

/*int    ft_check_base(char *base)
{
    int    i;
    int    j;

    i = 0;
    while (base[i])
    {
        while (base[i] == '' || base[i] == '	' || base[i] == '
'
        || base[i] == '' || base[i] == '
' || base[i] == ' '
        || base[i] == '+' || base[i] == '-')
        return (1);
        j = i + 1;
        while (base[j])
        {
            if (base[i] == base[j])
                return (1);
            j++;
        }
        i++;
    }
    if (ft_strlen(base) <= 1)
        return (1);
    return (0);
}
*/
int    ft_base_position(char c, char *base)
{
    int    i;

    i = 0;
    while (base[i])
    {
        if (c == base[i])
            return (i);
        i++;
    }
    return (-1);
}

int    ft_atoi_base(char *str, char *base)
{
	int    i;
	int    res;
	int    sign;

	i = 0;
	res = 0;
	sign = 1;
	//if (ft_check_base(base) == 0)
	//    return (0);
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

char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int i;
	char *nb_final;
	int tmp;
	char *noushka;
	int lol;

	i = 0;
	lol = 0;
	nb_final = nbr;
	tmp  = ft_atoi_base(nb_final, base_from);

	noushka = ft_itoa_base(tmp, base_to);
	rev_tab(noushka);

	//printf("6) noushka avant d'etre retournee : %s\n", noushka);
	//exit(125);
	return (noushka);
}

int main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));

	return 0;
}

/*int main()
{
    char *nbr = "2a";
    char *base_from = "0123456789abcdef";
    char *base_to = "0123456789";
    printf("resultat final : %s\n", ft_convert_base(nbr, base_from, base_to));
    return 0;
}*/
