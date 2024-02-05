/*
check if one of the char from *reject is in *s
if it is -> return index of the first occer char
if not -> return length of the *s
*/

#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j;

    while (s[i] != '\0')
    {
        j = 0;
        while (reject[j] != '\0')
        {
            if (s[i] == reject[j])
                return (i);
            else if (s[i] != reject[j])
                j++;
        }
        i++;
    }
    return (i);
}

int main()
{
    const char *s = "Hello";
    const char *reject = "es"; // it returns 1

    printf("%zu\n", ft_strcspn(s, reject));
}