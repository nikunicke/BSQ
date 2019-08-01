/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 09:55:03 by npimenof          #+#    #+#             */
/*   Updated: 2019/07/31 23:01:08 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUF_SIZE 32768

typedef struct		s_list
{
	struct s_list	*next;
	char			*data;
}					t_list;

typedef struct		s_vars
{
	int				length;
	int				errors;
	int				xx;
	int				yy;
	int				x;
	int				y;
	int				row_len;
	int				fd;
	int				ret;
	int				max;
	int				max_x;
	int				max_y;
}					t_vars;

void				ft_putchar(char c);
void				ft_putstr(char *str);
char				*ft_strdup(char *src, unsigned int n);
char				*ft_strcat(char *dest, char *src, int *last);
int					ft_strcmp(char *s1, char *s2);
void				dimensions(char *str, int height, int i, t_vars *vars);
void				ft_list_push_back(t_list **node, char *data);
char				*ft_listcat(t_list *list, int len);
t_list				*ft_create_elem(char *data);
char				*elems_to_string(t_list *node, int size);
void				ft_putnbr(int nb);
int					**create_grid(char *str, t_vars *vars, int i, char *marks);
void				bsq_solver(int **grid, t_vars *vars);
char				**split_rows(char *str, t_vars *vars, int i);
void				output(char **map, char *marks, t_vars *vars);
int					ft_atoi(char *str);
int					error_output(void);
int					variable_handler(int ac, char **av, t_vars *vars);
int					read_loop(int ac, char **av, int i, t_vars *vars);
t_vars				*var_init(t_vars *vars);
t_vars				*var_reset(t_vars *vars);
int					headercheck(char *grid);

#endif
