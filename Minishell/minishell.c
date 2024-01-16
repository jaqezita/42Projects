#include "minishell.h"

int main(int argc, char* argv[], char **envp)
{
	while (1)
	{
		char	*prompt;
		char	**tokens;

		printf("Minishell $> ");
		prompt = readline(*prompt);
		tokens = split_input_into_tokens(prompt);

		execute_command(tokens);

		free(prompt);
		free(tokens);
	}

	return EXIT_SUCCESS;
}
/* int	main(int argc, char **argv, char **envp)
{
	t_minishell	*mini;
	const char	*prompt;
	char		**tokens;

	mini = ft_calloc(1, sizeof(t_minishell));
	mini->token = ft_calloc(1, sizeof(t_token));
	while (1)
	{
		prompt = readline("Minishell $> ");
		lexer(prompt, mini);
	}
} */
