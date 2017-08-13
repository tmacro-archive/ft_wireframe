/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdict.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 11:34:09 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/11 12:57:08 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDICT_H
# define FDICT_H
# include <stdlib.h>

# define FDICT_GROWTH_FACTOR 2
# define FDICT_INITIAL_SIZE 1024
# define FDICT_MAX_LOAD 1

# define VDICT (dict_create(&hash_ptr))
# define SDICT (dict_create(&hash_str))
# define IDICT (dict_create(&hash_int))

# define DGET(dict, key) (dict_get(dict, (void*)key))
# define DSET(dict, key, value) (dict_set(dict, (void*)key, (void*)value))
# define DREM(dict, key) (dict_rem(dict, (void*)key))

# define ISET(dict, key, value) DSET(dict, &key, value)
# define IGET(dict, key) DGET(dict, &key)
# define IREM(dict, key) DREM(dict, &key)

typedef unsigned long	t_ulong;
typedef t_ulong			(*t_hasher)(void*);

typedef struct			s_fdict_el
{
	struct s_fdict_el	*next;
	void				*key;
	void				*value;
}						t_fdict_el;

struct					s_fdict
{
	size_t				size;
	size_t				stored;
	t_hasher			hasher;
	struct s_fdict_el	**buckets;
};

typedef struct s_fdict	*t_dict;

t_dict					dict_create(t_ulong (*hash)());
void					dict_grow(t_dict dict);
void					dict_destroy(t_dict dict);
void					*dict_get(t_dict dict, void *key);
void					dict_set(t_dict dict, void *key, void *value);
void					dict_rem(t_dict dict, void *key);
void					dict_iter(t_dict dict, int (*f)(void *k, void *v));
t_ulong					hash_ptr(void *value);
t_ulong					hash_str(void	*value);
t_ulong					hash_int(void	*value);
#endif
