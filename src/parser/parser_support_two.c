#include "rtv.h"
#include "string.h"
#include "rtv_defines.h"

double ft_atof(char *num)
{
	if (!num || !*num)
		return 0;

	char *tmp;
	int dot;

	dot = 0;
	while (*num)
	{
		if (ft_isspace(*num))
			num++;
		if ((isdigit(*num) || *num == '.') && isdigit(*num + 1) && dot == 0)
		{
			*tmp = *num;
			dot = 1;
		}
		else if ((isdigit(*num) && (*num + 1) == '.'))
		{

		}
	}

	double integerPart = 0;
	double fractionPart = 0;
	int divisorForFraction = 1;
	int sign = 1;
	t_bool inFraction = false;
	/*Take care of +/- sign*/
	if (*num == '-')
	{
		++num;
		sign = -1;
	}
	else if (*num == '+')
	{
		++num;
	}
	while (*num != '\0')
	{
		if (*num >= '0' && *num <= '9')
		{
			if (inFraction)
			{
				/*See how are we converting a character to integer*/
				fractionPart = fractionPart*10 + (*num - '0');
				divisorForFraction *= 10;
			}
			else
			{
				integerPart = integerPart*10 + (*num - '0');
			}
		}
		else if (*num == '.')
		{
			if (inFraction)
				return sign * (integerPart + fractionPart/divisorForFraction);
			else
				inFraction = true;
		}
		else
		{
			return sign * (integerPart + fractionPart/divisorForFraction);
		}
		++num;
	}
	return sign * (integerPart + fractionPart/divisorForFraction);
}

t_bool parse_float_number(t_rtv *r, float *n, float min, float max)
{
	float tmp;
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		tmp = (float)ft_atof(r->pars->line);
		if (tmp >= min && tmp <= max)
		{
			*n = tmp;
			free(r->pars->line);
			return (true);
		}
	}
	return (false);
}

/*
** Parses line by line vector values.
*/
t_bool parse_color(t_rtv *r, t_rgbap *c, float min, float max)
{
	if (!(parse_float_number(r, &c->red, min, max)))
		return (false);
	if (!(parse_float_number(r, &c->green, min, max)))
		return (false);
	if (!(parse_float_number(r, &c->blue, min, max)))
		return (false);
	if (!(parse_float_number(r, &c->alpha, min, max)))
		return (false);
	return (true);
}