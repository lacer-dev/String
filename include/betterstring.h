#ifndef BETTERSTRING_H
#define BETTERSTRING_H

#include <stddef.h>

/**
 * A convenience wrapper for dynamically allocated string.
 * 
 * Manages memory allocation and provides string operations 
 * that allow for easy string manipulation.
 */
struct String {
    char*   ptr;
    size_t  size;
    size_t  capacity;
};

typedef struct String String;

// Constructors
String STR_new(); // Construct empty String object
String STR_new_from_s(const char * str); // Construct from c-string
String STR_new_fill(size_t count, char c); // Construct from c-string
String STR_copy(const String* from); // Copy constructor
String STR_move(String* from); // Move constructor

// Destructor
void STR_destroy(String* this);

// Access
size_t STR_size(const String* this);
size_t STR_capacity(const String* this);
char* STR_at(const String* this, size_t index);
const char* STR_c_str(String* this);
char* STR_data(String* this);

// String Manipulation
void STR_append(String* this, const String* other);
void STR_append_s(String* this, const char* other);
String STR_add(const String* left, const String* right);
String STR_add_sr(const String* left, const char* right);
String STR_add_sl(const char* left, const String* right);
String STR_add_s(const char* left, const char* right);

#endif