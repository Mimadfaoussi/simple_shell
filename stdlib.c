#include "main.h"

size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        size_t                  i;
        unsigned char   nbs1;
        unsigned char   nbs2;

        i = 0;
        while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
        {
                nbs1 = (unsigned char)s1[i];
                nbs2 = (unsigned char)s2[i];
                if (nbs1 != nbs2)
                        return (nbs1 - nbs2);
                i++;
        }
        return (0);
}
