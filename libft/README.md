# Libft

## Description

Libft is my first 42 project. A C static library (`libft.a`). It contains:

- **libc functions** rewritten from scratch: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`, `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_atoi`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- **extra functions**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- **linked list functions** (`t_list`): `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

All prototypes are in `libft.h`. The code follows the 42 Norm and compiles with `-Wall -Wextra -Werror`.

## Instructions

```sh
make          # build libft.a
make clean    # remove object files
make fclean   # remove object files and libft.a
make re       # rebuild everything
```

To use it in a project, include the header and link the library:

```c
#include "libft.h"
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

## Resources

- `man 3` pages of the reimplemented functions
- [GNU C Library manual](https://www.gnu.org/software/libc/manual/)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)
