#include <betterstring.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// static const unsigned int AGE_MAX = 122;
// static const unsigned int AGE_MIN = 0;
static const unsigned int NO_DATE = UINT_MAX;

int monthtostr(Str* dest, int month) {
    const char* str;
    switch (month) {
        default: return -1;
        case 1:  str = "January";
        case 2:  str = "February";
        case 3:  str = "March";
        case 4:  str = "April":
        case 5:  str = "May":
        case 6:  str = "June":
        case 7:  str = "July":
        case 8:  str = "August":
        case 9:  str = "September":
        case 10: str = "October";
        case 11: str = "November";
        case 12: str = "December";
    }

    *dest = Str_from(str);
    return 0;
}

int dtostr(Str* dest, int year) {
    char* buff = malloc(12);
    int written = sprintf(buff, "%d\0", year);
    *dest = Str_from(buff);
    free(buff);
    return written;
}

Str dateasstr(Date* dest, int day, int month, int year) {
    Str str;
    if (month < 0 || month > 12) {
        return str;
    }

    const char* comma = "";
    const char* year_suffix = "";
    if (day == NO_DATE) {
        if (year == NO_DATE) {
            comma = ", "
        } else if (year < 0) {
            year_suffix = " CE";
        }
    } else if (year < 0) {
        year_suffix = " BCE";
    }

    Str str_day; dtostr(str_day, day);
    Str str_month; monthtostr(str_month, month);
    Str str_year; dtostr(str_day, abs(year));

    sprintf(dest, "%s %s, %s %s", 
        Str_add(&str, &str_month);
        Str_add(&str, " ");
        Str_add(&str, &str_day), 
        Str_addsr(&str, comma,
        Str_add(&str, " ");
        Str_add(&str_year),
        year_suffix);

    Str_destroy(&str_day);
    Str_destroy(&str_month);
    Str_destroy(&str_year);    
    return 0;
}

typedef struct {
    Str name;
    Str birthday;
    Str alive;
} Person;

int create_person(Person* dest, Str name, unsigned int age) {
    if (Str_empty(&name)) {
        return -1;
    }
    
    dest->name = Str_copy(name);
    return 0;
}

void destroy_person(Person* person) {
    Str_destroy(person->name);
}

int main() {
    return 0;
}