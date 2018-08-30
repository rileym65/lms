#define GRAN          100.0
#define G             6.67408e-11
#define VT_NONE       0
#define VT_SPACECRAFT 1
#define VT_ROCKET     2
#define VT_GROUND     4
#define VT_COMMAND    8
#define VT_LANDER     16

#define VEHICLE_APOLLO          1
#define VEHICLE_APOLLO_J        2
#define VEHICLE_APOLLO_MKII     3
#define VEHICLE_APOLLO_MKIII    4

#ifdef MINGW
#define LE   "\r\n"
#else
#define LE   "\n"
#endif

