

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    if (!s1 || !s2)
    {
        return (0);
    }
    while (*s1 != '\0')
    {
        i = 0;
        while (s2[i] != '\0')
        {
            if (*s1 == s2[i])
                return ((char *)s1);
            else 
                i++;
        }
        s1++;
    }
    return (0);
}

#include <stdio.h>
int main()
{
    const char *s1 = "Hello";
    const char *s2 = "hi";
    printf("%s\n", ft_strpbrk(s1, s2));
}