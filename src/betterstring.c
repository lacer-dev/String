#include <betterstring.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const size_t STRING_DEFAULT_CAPACITY = 4;

String STR_new() {
    String new_s = {
        .size = 0,
        .capacity = STRING_DEFAULT_CAPACITY
    };
   
    new_s.ptr = malloc(new_s.capacity);
    new_s.ptr[0] = '\0';
    return new_s;
}

String STR_new_from_s(const char * str) {
    size_t size = strlen(str);
    String new_s = {
        .size = size,
        .capacity = size + 1
    };
   
    new_s.ptr = malloc(new_s.capacity);
    memcpy(new_s.ptr, str, new_s.size + 1);
    
    return new_s;
}

String STR_new_fill(size_t count, char c) {
    String new_s = {
        .size = count,
        .capacity = count + 1
    };

    new_s.ptr = malloc(new_s.capacity);
    memset(new_s.ptr, c, count);

    return new_s;
}

String STR_copy(const String* from) {
    String new_s = {
        .size = from->size,
        .capacity = from->capacity
    };

    new_s.ptr = malloc(new_s.capacity);
    memcpy(new_s.ptr, from->ptr, new_s.size + 1);

    return new_s;
}

String STR_move(String* from) {
    String new_s = *from;
    from->ptr = NULL;
    return new_s;
}

void STR_destroy(String* this) {
    free(this->ptr);
}

size_t STR_size(const String* this) {
    return this->size;
}

size_t STR_capacity(const String* this) {
    return this->capacity;
}

char* STR_at(const String* this, size_t index) {
    return this->ptr + index;
}

const char* STR_c_str(String* this) {
    return this->ptr;
}

char* STR_data(String* this) {
    return this->ptr;
}

static void _STR_append_c_str_to_String(String* str, const char* c_str, size_t c_str_size) {
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

void STR_append(String* this, const String* other) {
    _STR_append_c_str_to_String(this, other->ptr, other->size);  
}

void STR_append_s(String* this, const char* other) {
    _STR_append_c_str_to_String(this, other, strlen(other));  
}

/**
 * Join two c-strings together and create a String from them.
 */
static String _STR_add_c_strs(const char* left, size_t len_left, const char* right, size_t len_right) {
    size_t size = len_left + len_right;
    String new_s = {
        .size = size,
        .capacity = size + 1
    };

    new_s.ptr = malloc(new_s.capacity);
   
    memcpy(new_s.ptr, left, len_left);
    memcpy(new_s.ptr + len_left, right, len_right + 1);

    return new_s;
}

String STR_add(const String* left, const String* right) {
    return _STR_add_c_strs(left->ptr, left->size, right->ptr, right->size);
}

String STR_add_sr(const String* left, const char* right) {
    return _STR_add_c_strs(left->ptr, left->size, right, strlen(right));
}

String STR_add_sl(const char* left, const String* right) {
    return _STR_add_c_strs(left, strlen(left), right->ptr, right->size);
}

String STR_add_s(const char* left, const char* right) {
    return _STR_add_c_strs(left, strlen(left), right, strlen(right));
}