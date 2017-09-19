#include "rtv.h"
#include "libft.h"

float		ft_atof(const char *s)
{
	float rez = 0;
	float fact = 1;

	while ((ft_isspace(*s) !=0 || *s == '+') && *s != '\0')
		s++;
	if (*s == '-')
	{
		s++;
		fact = -1;
	}
	for (int point_seen = 0; *s; s++)
	{
		if (*s == '.')
		{
			point_seen = 1;
			continue;
		}
		int d = *s - '0';
		if (d >= 0 && d <= 9)
		{
			if (point_seen) fact /= 10.0f;
			rez = rez * 10.0f + (float)d;
		}
	}
	return rez * fact;
}