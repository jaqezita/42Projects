#include "minishell.h"

void	add_token(char *str, int type, t_minishell *mini)
{
	t_token	*new_token;
	t_token	*last_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
		exit(EXIT_FAILURE);
	if (ft_strlen(str) == 2)
		new_token->content = ft_strdup(str);
	else
		new_token->content = str;
	new_token->type = type;
	new_token->next = NULL;
	if (mini->token)
	{
		last_token = mini->token;
		while (last_token->next != NULL)
			last_token = last_token->next;
		last_token->next = new_token;
	}
	else
		mini->token = new_token;
}

void	lexer(const char *prompt, t_minishell *mini)
{
	check_operator(prompt, mini);
	check_quotes(prompt);
	check_space(prompt);
}

int	check_operator(const char *input, t_minishell *mini)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '>' && input[i + 1] == '>')
			return (APPEND);
		else if (input[i] == '<' && input[i + 1] == '<')
			return (HEREDOC);
		else if (input[i] == '>' && input[i + 1] != '>')
			return (REDIRECT_OUT);
		else if (input[i] == '<' && input[i + 1] != '<')
			return (REDIRECT_IN);
		else if (input[i] == '|')
			return (PIPE);
		i++;
	}
	return (1);
}

void	check_quotes(const char *prompt)
{
	int	quote;
	int	double_quote;

	quote = 0;
	double_quote = 0;
	while (*prompt)
	{
		if (*prompt == '"')
			double_quote++;
		if(*prompt == '\'')
			quote++;
		prompt++;
		
	}
}

int	check_space(const char *prompt)
{
	int	i;

	i = 0;
	if (prompt[i] == ' ' || prompt[i] == '\t' || prompt[i] == '\v'
		|| prompt[i] == '\f' || prompt[i] == '\r')
		return (1);
	return (0);
}


void	get_words(const char *input, t_minishell *mini)
{
	int		i;
	int		j;
	int		start;
	char	*arg;

	i = 0;
	j = 0;
	if (!input)
		return ;
	while (input[i] != '\0')
	{
		if (ft_isalpha(input[i]) == 1 || ft_isalpha(input[i]) == '-')
		{
			start = i;
			while (input[i] != ' ' && check_operator(&input[i], mini) != 1)
				i++;
			arg = ft_substr(input, start, i-start);
			mini->args[j] = arg;
		}
		if (input[i] == ' ')
			i++;
	}
}



// #include "../include/minishell.h"

// int	check_operator(char *input, t_minishell *mini)
// {
// 	int	i;

// 	i = 0;
// 	if (!input)
// 		return (0);
// 	while (input[i])
// 	{
// 		if (input[i] == '>' && input[i + 1] == '>')
// 			return (DOUBLE_GREAT);
// 		else if (input[i] == '<' && input[i + 1] == '<')
// 			return (DOUBLE_LESS);
// 		else if (input[i] == '>' && input[i + 1] != '>')
// 			return (GREAT);
// 		else if (input[i] == '<' && input[i + 1] != '<')
// 			return (LESS);
// 		else if (input[i] == '|')
// 			return (PIPE);
// 		i++;
// 	}
// 	return (1);
// }

// int	is_word(const char *input, t_minishell *mini)
// {
// 	int		i;
// 	// int		start;
// 	// char	*word;

// 	i = 0;
// 	if (!input)
// 		return (0);
// 	while (input[i] != '\0')
// 	{
// 		if (ft_isalpha(input[i]) == 1 || input[i] == '-')
// 		{
// 			// start = i;
// 			while (input[i] != ' ' && input[i] != '\0')
// 				i++;
// 			// word = ft_substr(input, start, i-start);
// 			return (WORD);
// 		}
// 	}
// 	return (1);
// }

// int	is_arg(const char *input, t_minishell *mini)
// {
// 	int		i;
// 	// int		start;
// 	// char	*arg;

// 	i = 0;
// 	if (!input)
// 		return (0);
// 	while (input[i] != '\0')
// 	{
// 		if (input[i] == '-' && ft_isalpha(input[i + 1]) == 1 )
// 		{
// 			// start = i;
// 			while (input[i] != ' ' && input[i] != '\0')
// 				i++;
// 			// arg = ft_substr(input, start, i-start);
// 			return (ARG);
// 		}
// 	}
// 	return (1);
// }