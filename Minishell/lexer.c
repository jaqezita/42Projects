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
	check_quotes(prompt, mini);
	check_space(prompt);
}

int	check_operator(const char *input, t_minishell *mini)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '>' && input[i + 1] == '>')
		{
			add_token(">>", DOUBLE_GREAT, mini);
			i++;
		}
		else if (input[i] == '<' && input[i + 1] == '<')
		{
			add_token("<<", DOUBLE_LESS, mini);
			i++;
		}
		else if (input[i] == '>' && input[i + 1] != '>')
			add_token(">", GREAT, mini);
		else if (input[i] == '<' && input[i + 1] != '<')
			add_token("<", LESS, mini);
		else if (input[i] == '|')
			add_token("|", PIPE, mini);
		i++;
	}
	return (1);
}

void	check_quotes(const char *prompt, t_minishell *mini)
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
	int		start;
	char	*arg;

	i = 0;
	if (!input)
		return ;
	while (input[i] != '\0')
	{
		if (ft_isalpha(input[i]) == 1 || ft_isalpha(input[i]) == '-')
		{
			start = i;
			while (input[i] != ' ' && check_operator(input[i]) != 1)
				i++;
			arg = ft_substr(input, start, i-start);
			add_token(arg, UNDEF, mini);
		}
		if (input[i] == ' ')
			i++;
	}
}


void	print_tokens(t_minishell *mini)
{
    t_token *current_token = mini->token;
    while (current_token != NULL)
    {
        printf("Content: %s, Type: %d\n", current_token->content, current_token->type);
        current_token = current_token->next;
    }
}

int main()
{
    t_minishell mini = {NULL};

    add_token("token1", 1, &mini);
    add_token("token2", 2, &mini);
    add_token("token3", 3, &mini);

    print_tokens(&mini);

    return 0;
}