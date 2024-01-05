/*
LICENSE

Copyright (c) 2023 Felipe Markson dos Santos Monteiro

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef inner_assert
#define inner_assert(expr, cstr_msg_err)                                         \
    do {                                                                         \
        if (!(expr)) {                                                           \
            fprintf(stderr, "FATAL ERROR!\n   %s:%d\n   %s\n   Caused by: %s\n", \
                    __FILE__, __LINE__, (cstr_msg_err), #expr);                  \
            exit(1);                                                             \
        }                                                                        \
    } while (0)
#endif

typedef struct {
    char* items;
    size_t length;
    size_t capacity;
} str;

typedef struct {
    const char* items;
    size_t length;
} view_str;

str readfile(const char* path) {
    FILE* file = fopen(path, "r");
    long file_size = 0;
    char* data = 0;
    long ret = 0;

    inner_assert(file, "Could not open the file");
    ret = fseek(file, 0, SEEK_END) == 0;
    inner_assert(ret >= 0, strerror(errno));
    file_size = ftell(file);
    inner_assert((file_size) > 0, strerror(errno));
    ret = fseek(file, 0, SEEK_SET);
    inner_assert(ret >= 0, strerror(errno));
    data = malloc(file_size + 1);
    inner_assert(data, strerror(errno));
    ret = fread(data, file_size, 1, file);
    inner_assert(ret == 1, "fread fail");
    fclose(file);
    data[file_size] = '\0';
    return (str){.items = data, .length = file_size, .capacity = file_size};
}

view_str pop_until(view_str* data, char delim) {
    view_str str = {0};
    if (data->length == 0)
        return str;
    if (data->length == 1) {
        if (data->items[0] == delim)
            return str;
        str = *data;
        data->items = 0;
        data->length = 0;
        return str;
    }
    str.items = data->items;
    for (size_t i = 0; i < data->length; i++) {
        if (data->items[i] == delim) {
            data->items = (data->items + i + 1);
            data->length -= i + 1;
            return str;
        } else {
            str.length += 1;
        }
    }
    str.length = data->length;
    data->items = NULL;
    data->length = 0;
    return str;
}
