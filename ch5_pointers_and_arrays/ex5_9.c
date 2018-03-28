/* day of year to month and day (and vice versa) converter
    now with pointers! */
#include <stdio.h>
#include <stdlib.h>


int day_of_year(int, int, int);
void month_day(int, int, int *, int *);


int main() {
    int res;
    int *pmonth, *pday;

    pmonth = malloc(sizeof(int));
    pday = malloc(sizeof(int));

    res = day_of_year(1989, 2, 25);
    printf("res: %d\n", res);

    month_day(1989, res, pmonth, pday);
    printf("month: %d, day: %d\n", *pmonth, *pday);

    month_day(2000, 366, pmonth, pday);
    printf("month: %d, day: %d\n", *pmonth, *pday);

    free(pmonth);
    free(pday);

    return 0;
}


static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


/* day_of_year: get day of year from month and day */
int day_of_year(int year, int month, int day) {
    int leap;
    char *p;

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return -1;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = daytab[leap];

    if (day > *(p+month))
        return -1;

    while (--month)
        day += *++p;

    return day;
}


/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    char *p;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    p = *(daytab + leap);

    if (year < 0 || yearday > (365 + leap)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    while (yearday > *++p) {
        yearday -= *p;
    }

    // difference between month it's pointing at and the beginning of the 
    // array of months
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}
