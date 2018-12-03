#include "libft.h"

size_t  ft_strcspn(const char *s1, const char *s2)
{
	const char *sc1;

	sc1 = s1;
	while (*sc1)
	{
		if (ft_strchr(s2, *sc1))
			return (sc1 - s1);
		sc1++;
	}
	return (sc1 - s1);            /* terminating nulls match */
}