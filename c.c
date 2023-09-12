#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    char *ptr = str;
    int strlen = 0;
    while (*ptr)
    {
        strlen++;
        ptr++;
    }
    return strlen;
}

void ft_putstr(char *ptr)
{
    char *str = ptr;
    while (*str)
        write(1, str++, 1);
    write(1, "\n", 1);
}

int isNullTerminated(const char *str, int length) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (str[i] == '\0' && i == length);
}

int main()
{
    char error[] = "Realloc failed";
    char prompt[] = "Please enter your name";
    char result[] = "Your name is:";
    char ch;
    char *res = NULL;
    int length = 0;
    ft_putstr(prompt);
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        res = (char *)realloc(res, length * sizeof(char));
        if(res == NULL)
        {
            ft_putstr(error);
            return 1;
        }
        res[length] = ch;
        length++;
    }
    res[length] = '\0';
     if(res == NULL)
        {
            ft_putstr(error);
            return 1;
        }
        int size = ft_strlen(res);
        if(isNullTerminated(res, size))
            ft_putstr("string is null terminated");
        else
            ft_putstr("string is not null terminated");
        ft_putstr(result);
        ft_putstr(res);
        free(res);
    return 0;
}
