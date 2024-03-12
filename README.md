# ft_printf

Welcome to ft_printf! This project aims to recreate the functionality of the standard C library function `printf`. By implementing your version of `printf`, you'll deepen your understanding of string formatting and improve your skills in handling variable arguments in C programming.

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Format Specifiers](#format-specifiers)
4. [Building](#building)
5. [Contributing](#contributing)
6. [Credits](#credits)

## Introduction

In this project, you'll implement your version of the `printf` function, which formats and prints data to the standard output according to a format string. The format string may contain format specifiers that control the output format for each argument passed to `printf`. By completing this project, you'll gain a deeper understanding of string manipulation, variable argument lists, and parsing techniques in C programming.

## Usage

To use your `printf` function in your projects, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/ft_printf.git
    ```

2. Include the `ft_printf.h` header file in your source code:

    ```c
    #include "ft_printf.h"
    ```

3. Call the `ft_printf` function with the desired format string and arguments:

    ```c
    ft_printf("Formatted string with arguments: %s, %d, %f\n", str, num, fnum);
    ```

## Format Specifiers

Below is a list of format specifiers supported by your `printf` function:

- `%c`: Character
- `%s`: String
- `%d` or `%i`: Signed decimal integer
- `%u`: Unsigned decimal integer
- `%x` or `%X`: Unsigned hexadecimal integer (lowercase or uppercase)
- `%p`: Pointer address
- `%f`: Decimal floating point (float)

Note: Additional format specifiers and flags may be implemented according to your project requirements.

## Building

To build the `printf` function, simply run:

```bash
make
```

## Contributing
Contributions are welcome! If you find any bugs or have suggestions for improvement, please open an issue or submit a pull request on GitHub.

## Credits
This project was created by adrgonza for the ft_printf project at 42Madrid.
