#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_digits_int(int input) {
    int count = 1;
    for(;(input/=10) > 0; count++) {}
    return count;
}

int count_digits_float(float input) {
    int count = 1;
    for(;(input/=10) > 0; count++) {}
    return count;
}

void print_padding(int width, int arg_width) {
    if (arg_width < width) {
        for (int i = width - arg_width; i > 0; i--) {
            putchar(' ');
        }
    }
}

void minprintf(char *fmt, ...) {
    va_list ap; /* points to each unnamed arg in turn */
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt); /* make ap point to 1st unnamed arg*/
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        p++;

        // if it's a `-` set left-aligned flag for padding
        int left_pad = 1;
        if (*p == '-') {
            left_pad = 0;
            p++;
        }

        // if it's an int, do padding
        int int_count = 0;
        for(;*p >= 49 && *p <= 57; p++, int_count++) {}

        // parse width
        int width = 0;
        if (int_count > 0) {
            char pad_str[int_count];
            for (int i = 0; i < int_count; i++) {
                pad_str[i] = *(p-int_count+i);
            }
            width = atoi(pad_str);
        }

        int arg_width;

        switch (*p) {
            case 'd':
                ival = va_arg(ap, int);

                // calculate size and add padding if necessary
                arg_width = count_digits_int(ival);

                if (left_pad) {
                    print_padding(width, arg_width);
                }

                printf("%d", ival);

                if (!left_pad) {
                    print_padding(width, arg_width);
                }

                break;
            case 'f':
                dval = va_arg(ap, double);

                // calculate size and add padding if necessary
                arg_width = count_digits_float(dval);
                if (left_pad) {
                    print_padding(width, arg_width);
                }

                printf("%f", dval);

                if (!left_pad) {
                    print_padding(width, arg_width);
                }

                break;
            case 's':
                // store this in a variable instead of printing first off
                sval = va_arg(ap, char *);
                arg_width = strlen(sval);

                if (left_pad) {
                    print_padding(width, arg_width);
                }

                for (; *sval; sval++) {
                    putchar(*sval);
                }

                if (!left_pad) {
                    print_padding(width, arg_width);
                }

                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean up when done */
}

int main(int argc, char *argv[]) {
    minprintf("hi %s you are %d years old\n", "steve", 31);
    minprintf("hi '%-9s' you are '%5d' years old\n", "steve", 31);
}

