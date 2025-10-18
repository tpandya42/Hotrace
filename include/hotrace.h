#ifndef HOTRACE_H
#define HOTRACE_H

#define BUFFER_SIZE 1000

#include <unistd.h>
#include <stdlib.h>

typedef struct s_nodes {
	char	*key;
	char	*value;
	int	index;
	struct s_nodes	*next;
}	t_nodes;

int	hash[255][255];


#endif
