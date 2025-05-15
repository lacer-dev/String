#ifndef BETTERSTRING_H
#define BETTERSTRING_H

#include <stddef.h>
#include <stdbool.h>

/**
 * A convenience wrapper for dynamically allocated string.
 * 
 * Manages memory allocation and provides string operations 
 * that allow for easy string manipulation.
 */
typedef struct Str {
    char*   ptr;
    size_t  size;
    size_t  capacity;
} Str;

// Constructors
Str Str_new(); // Construct empty Str object
Str Str_from(const char * str); // Construct from c-string
Str Str_new_fill(size_t count, char c); // Construct from c-string
Str Str_copy(const Str* from); // Copy constructor
Str Str_move(Str* from); // Move constructor

// Destructor
void Str_destroy(Str* this);

// Access
size_t Str_size(const Str* this);
size_t Str_capacity(const Str* this);
bool Str_empty(const Str* this);
char* Str_at(const Str* this, size_t index);
const char* Str_c_str(const Str* this);
char* Str_data(Str* this);

// String Manipulation
void Str_append(Str* this, const Str* other);
void Str_appends(Str* this, const char* other);
Str Str_add(const Str* left, const Str* right);
Str Str_addsr(const Str* left, const char* right);
Str Str_addsl(const char* left, const Str* right);
Str Str_adds(const char* left, const char* right);
bool Str_equals(const Str* left, const Str* right);
bool Str_equalss(const)
#endif