# ft_printf — `printf` re-implemented in C

A from-scratch re-implementation of the C standard library's `printf`. It uses variadic arguments (`stdarg.h`), a format-string parser and a dispatch table with one handler per conversion. It was built at 1337 (42 Network). The only allowed functions are `write`, `malloc`, `free` and the `stdarg` macros.

## Supported format

`%[flags][width][.precision]conversion`

| | Supported |
|---|---|
| Conversions | `c` `s` `p` `d` `i` `u` `x` `X` `%` |
| Flags | `-` (left-justify), `0` (zero-pad) |
| Width / precision | numeric or `*` (taken from the arguments) |

## How it works

1. `ft_printf` walks the format string and writes literal text straight to stdout.
2. On `%`, a parser fills a spec struct with the flags, width, precision and conversion.
3. The spec is dispatched to a handler: `traitc.c`, `traits.c`, `traitp.c`, `traitd.c`, `traitu.c`, `traitx.c` or `traitpourcentage.c`.
4. Each handler formats and pads its argument and returns the number of bytes written. The total is the return value, just like `printf`.

## Build & use

```bash
git clone https://github.com/Alcheemiist/ft_printf_42_cursus.git
cd ft_printf_42_cursus/ft_printf
make                     # → libftprintf.a
```

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("%-8s|%05d|%.3x|%p\n", "hello", 42, 255, (void *)main);
}
```

```bash
cc main.c -L. -lftprintf -I. && ./a.out
```

---

Built by [Elmahdi Elaazmi](https://elaazmielmahdi.com) · 1337 / 42 Network core curriculum.
