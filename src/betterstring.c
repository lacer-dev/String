#include <betterstring.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const size_t STRING_DEFAULT_CAPACITY = 4;

Str Str_new() {
    Str new_s = {
        .size = 0,
        .capacity = STRING_DEFAULT_CAPACITY
    };
   
    new_s.ptr = malloc(new_s.capacity);
    new_s.ptr[0] = '\0';
    return new_s;
}

Str Str_from(const char * str) {
    size_t size = strlen(str);
    Str new_s = {
        .size = size,
        .capacity = size + 1
    };
   
    new_s.ptr = malloc(new_s.capacity);
    memcpy(new_s.ptr, str, new_s.size + 1);
    
    return new_s;
}

Str Str_new_fill(size_t count, char c) {
    Str new_s = {
        .size = count,
        .capacity = count + 1
    };

    new_s.ptr = malloc(new_s.capacity);
    memset(new_s.ptr, c, count);

    return new_s;
}

Str Str_copy(const Str* from) {
    Str new_s = {
        .size = from->size,
        .capacity = from->capacity
    };

    new_s.ptr = malloc(new_s.capacity);
    memcpy(new_s.ptr, from->ptr, new_s.size + 1);

    return new_s;
}

Str Str_move(Str* from) {
    Str new_s = *from;
    from->ptr = NULL;
    return new_s;
}

void Str_destroy(Str* this) {
    free(this->ptr);
}

size_t Str_size(const Str* this) {
    return this->size;
}

size_t Str_capacity(const Str* this) {
    return this->capacity;
}

bool Str_empty(const Str* this) {
    return this->size == 0;
}

char* Str_at(const Str* this, size_t index) {
    return this->ptr + index;
}

const char* Str_c_str(const Str* this) {
    return this->ptr;
}

char* Str_data(Str* this) {
    return this->ptr;
}

static void _Str_append_c_str_to_Str(Str* str, const char* c_str, size_t c_str_size) {
    size_t new_size = str->size + c_str_size;
    if (new_size > str->capacity) {
        if (str->capacity <= 1) {
            str->capacity = STRING_DEFAULT_CAPACITY;
        }

        str->capacity = (str->capacity * 1.5) + 1;
        char* new_ptr = malloc(str->capacity);
        memcpy(new_ptr, str->ptr, str->size);
        free(str->ptr);
        str->ptr = new_ptr;
    }

    memcpy(str->ptr + str->size, c_str, c_str_size + 1);   
}

void Str_append(Str* this, const Str* other) {
    _Str_append_c_str_to_Str(this, other->ptr, other->size);  
}

void Str_appends(Str* this, const char* other) {
    _Str_append_c_str_to_Str(this, other, strlen(other));  
}

/**
 * Join two c-strings together and create a Str from them.
 */
static Str _Str_add_c_strs(const char* left, size_t len_left, const char* right, size_t len_right) {
    size_t size = len_left + len_right;
    Str new_s = {
        .size = size,
        .capacity = size + 1
    };

    new_s.ptr = malloc(new_s.capacity);
   
    memcpy(new_s.ptr, left, len_left);
    memcpy(new_s.ptr + len_left, right, len_right + 1);

    return new_s;
}

Str Str_add(const Str* left, const Str* right) {
    return _Str_add_c_strs(left->ptr, left->size, right->ptr, right->size);
}

Str Str_addsr(const Str* left, const char* right) {
    return _Str_add_c_strs(left->ptr, left->size, right, strlen(right));
}

Str Str_addsl(const char* left, const Str* right) {
    return _Str_add_c_strs(left, strlen(left), right->ptr, right->size);
}

Str Str_adds(const char* left, const char* right) {
    return _Str_add_c_strs(left, strlen(left), right, strlen(right));
}