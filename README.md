*This activity has been created as part of the 42 curriculum by arngomes.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the C standard library function `printf()`.
The goal of the project is to learn how **variadic functions** work in C
(`va_start`, `va_arg`, `va_end`) and to build a small, reusable formatted-output
function that can be added to my `libft` and used in future 42 projects.

The project is delivered as a static library, `libftprintf.a`, which also
contains all the functions of `libft`.

`ft_printf` writes to the standard output and returns the number of characters
printed, just like the original `printf`.

### Supported conversions

| Conversion | Output                                              |
|------------|-----------------------------------------------------|
| `%c`       | A single character                                  |
| `%s`       | A string (`(null)` if the pointer is `NULL`)        |
| `%p`       | A pointer address in hexadecimal, prefixed by `0x` (`(nil)` if `NULL`) |
| `%d`       | A signed decimal integer                            |
| `%i`       | A signed decimal integer                            |
| `%u`       | An unsigned decimal integer                         |
| `%x`       | An unsigned integer in lowercase hexadecimal        |
| `%X`       | An unsigned integer in uppercase hexadecimal        |
| `%%`       | A literal percent sign                              |

Flags, field width and precision (`-0.# +`) are not handled (bonus part not implemented).

## Instructions

### Compilation

```bash
make        # builds libft, then libftprintf.a
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + all
```

The code is compiled with `cc -Wall -Wextra -Werror`.

### Usage

Include the header and link the library:

```c
#include "ft_printf.h"

int	main(void)
{
	int	len;

	len = ft_printf("Hello %s! %d in hex is %x, at %p%%\n", "42", 255, 255, &len);
	ft_printf("%d characters printed\n", len);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

### Project structure

```
.
├── Makefile
├── ft_printf.h       # prototypes, includes libft.h
├── ft_printf.c       # ft_printf (main loop) and ft_format (dispatcher)
├── ft_print_char.c   # %c, %s
├── ft_print_nbr.c    # %d, %i, %u
├── ft_print_hex.c    # %x, %X, %p
└── libft/            # my libft, compiled and merged into libftprintf.a
```

## Algorithm and data structure

### Overall algorithm

`ft_printf` performs a **single linear pass** over the format string:

1. Initialise a `va_list` with `va_start`.
2. For each character of the format string:
   - if it is a `%` followed by another character, pass that next character
     (the conversion specifier) to `ft_format`, then skip it;
   - otherwise, print the character as-is.
3. Each printing function returns the number of characters it wrote; these are
   added to a running total `len`.
4. Close the list with `va_end` and return `len`.

`ft_format` is a **dispatcher**: it reads the next argument with `va_arg` using
the type matching the specifier (`int`, `char *`, `void *`, `unsigned int`) and
calls the corresponding helper.

**Why this design?**

- One pass, no buffer: the output is written immediately, so the complexity is
  `O(n)` in the length of the format string plus the length of the output, and
  memory usage is constant (no `malloc`, so no leaks and no allocation failures
  to handle).
- Separating parsing (`ft_printf`) from conversion (`ft_format` + helpers) keeps
  each function short (Norm-compliant) and makes adding a new conversion as
  simple as adding one `else if` and one helper.
- Every helper returns its own printed length, so counting characters is
  handled locally instead of by recomputing lengths afterwards.

### Number conversion

- **`%d` / `%i`**: printed with `ft_putnbr_fd` from libft; the length is
  computed separately by `ft_nbrlen`, which counts digits (plus one for the `-`
  sign). The value is promoted to `long` so that `INT_MIN` can be negated safely.
- **`%u`, `%x`, `%X`, `%p`**: printed with a **recursive base conversion**.
  The function first recurses on `n / base`, then prints the digit `n % base`.
  Because the recursive call happens *before* printing, the most significant
  digit is printed first — no temporary array is needed to reverse the digits.
  Each recursion level returns `1 + length of the deeper levels`, which gives
  the total number of digits printed. Recursion depth is at most 16 levels
  (for a 64-bit pointer in base 16), so there is no risk of stack overflow.
- **Hexadecimal digits** are taken from a base string, `"0123456789abcdef"` or
  `"0123456789ABCDEF"`, selected by the `upper` flag. Indexing the string with
  `n % 16` is simpler and faster than computing ASCII offsets.
- **`%p`** reuses the same hex function, but with an `unsigned long` parameter
  so that a full 64-bit address fits, prefixed by `0x`.

### Data structures

The project deliberately uses no complex data structure:

- a `va_list` to walk through the variadic arguments;
- a constant base string (lookup table) for hexadecimal digits;
- an `int` counter for the return value.

Since `printf` output is a direct stream to file descriptor 1, a buffer or a
parsed list of format tokens would add complexity (allocation, freeing,
error handling) without any benefit for the mandatory part.

### Edge cases handled

- `NULL` string → `(null)`
- `NULL` pointer → `(nil)` (Linux `printf` behaviour)
- `INT_MIN` for `%d` / `%i`
- `0` for every numeric conversion
- `%%` prints a single `%`

## Resources

- `man 3 printf` — reference behaviour of the original function
- `man 3 stdarg` — `va_start`, `va_arg`, `va_copy`, `va_end`
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf)
- [cppreference — Variadic functions](https://en.cppreference.com/w/c/variadic)
- [GNU C Library — Variadic Functions](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- 42 subject `ft_printf` and the 42 Norm

### Use of AI

AI (Claude) was used to:

- write and structure this README (description, algorithm explanation, usage example).

The source code of `ft_printf` (parsing, conversions, Makefile) was written by me.
