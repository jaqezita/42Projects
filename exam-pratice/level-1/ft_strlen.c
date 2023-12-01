int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	while(str[len] != '\0')
		len++;
	return (len);
}