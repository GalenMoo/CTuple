/* all the macros */
#define tuple(T, U)\
    struct { T a; U b;}

#define tuple_init(p)\
    calloc(1, sizeof(*p))

#define tuple_a(p, T)\
    ((T *)(p))[0]
#define tuple_b(p, T)\
    ((T *)(p))[1]

/* all the different types */
typedef tuple(char *, char *) tuple_str_str;
typedef tuple(char *, int) tuple_str_int;
typedef tuple(int, char *) tuple_int_str;
typedef tuple(int, int) tuple_int_int;