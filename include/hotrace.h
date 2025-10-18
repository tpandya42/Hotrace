#ifndef HOTRACE_H
#define HOTRACE_H

#define BUFFER_SIZE 1000

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_nodes {
	char	*key;
	char	*value;
	int		index;
	struct s_nodes	*next;
}	t_nodes;

typedef struct s_hashtable {
	t_nodes	**buckets;
	int		size;
}	t_hashtable;


// UTILS
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);

// HASHING 
t_hashtable	*init_hashes(int size);
unsigned long long hashing(char	*str);
void	insert_into_table(t_hashtable *ht, char *key, char *value);

// READING
int	read_next_buffer(char *buf, int fd);
int	read_next_line(char *line);
int	read_key_value(char *key, char *value);

// CLEANUP
void	clean_buckets(t_nodes *nodes);
void	clean_table(t_hashtable *ht);

#endif
