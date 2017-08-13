/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clct.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 14:42:02 by tmckinno          #+#    #+#             */
/*   Updated: 2017/08/13 13:16:47 by tmckinno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLCT_H
# define CLCT_H

# include <stdlib.h>

# define RM_ALLC 1
# define RM_FREE 2
# define RM_RINC 3
# define RM_RDEC 4
# define RM_RLOG 5
# define RM_RSWP 6
# define RM_RCLN 7
# define REF_INC(addr) region_manip(addr, RM_RINC, 0)
# define REF_DEC(addr) region_manip(addr, RM_RDEC, 0)
# define REF_LOG region_manip(NULL, RM_RLOG, 0)
# define REF_SWP region_manip(NULL, RM_RSWP, 0)
# define REF_CLN region_manip(NULL, RM_RCLN, 0)

# include "fdict.h"

typedef struct		s_region
{
	void			*address;
	size_t			size;
	int				ref_count;
	struct s_region	*next;
}					t_region;

void				*memalloc(size_t len);
int					memfree(void **addr);
int					region_manip(void *addr, int mode, size_t len);
int					region_add(t_dict regions, void *addr, size_t len);
int					region_rem(t_dict region, void *addr);
int					region_log(t_dict regions);
int					ref_inc(t_dict region, void *addr);
int					ref_dec(t_dict region, void *addr);
int					ref_sweep(t_dict region);
int					ref_clean(t_dict region);
#endif
