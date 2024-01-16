#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "./libft/libft.h"
# include <sys/wait.h>

# define GREAT 1
# define LESS 2
# define PIPE 3
# define QUOTE 4
# define DOUBLE_QUOTE 5
# define DOUBLE_GREAT 6
# define DOUBLE_LESS 7
# define COMMAND 8
# define TOKEN 9
# define UNDEF -1

typedef struct s_minishell
{
	char			**path;
	char			*execute_path;
	struct s_token	*token;
}					t_minishell;

typedef struct s_token
{
	char			*content;
	int				type;
	struct s_token	*next;
	struct s_token	*previous;
}					t_token;

void	check_space(const char *prompt);
void	get_words(const char *input, t_minishell *mini);
void	check_quotes(const char *prompt, t_minishell *mini);
int		check_operator(const char *input, t_minishell *mini);
void	print_tokens(t_minishell *mini);
void	lexer(const char *prompt, t_minishell *mini);



#endif