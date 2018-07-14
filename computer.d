[h2]	Instructions
[I4]
[TB]
	| opcode | args     | description                              |
	| ACOS   | rs,rd    | Place arccos of rs into rd (degrees)     |
	| ADD    | r1,r2    | Add r2 to r1                             |
	| ASIN   | rs,rd    | Place arcsin of rs into rd (degrees)     |
	| ATAN   | rs,rd    | Place arctan of rs into rd (degrees)     |
	| CALP   | pvn      | Call another program as subroutine       |
	| COS    | rs,rd    | Place cos of rs in degrees into rd       |
	| CRS    | v1,v2    | Vector cross product, Result in VRES     |
	| DIV    | r1,r2    | Divide r1 by r2                          |
	| DOT    | v1,v2    | Dot product of two vectors, result in R0 |
	| END    |          | End program execution                    |
	| INV    | rs,rd    | Place 1/rs into rd                       |
	| JEQ    | r1,r2,ad | Jump to ad if r1 equals r2               |
	| JG     | r1,r2,ad | Jump to ad if r1 greater than r2         |
	| JGE    | r1,r2,ad | Jump to ad if r1 greater or equal to r2  |
	| JL     | r1,r2,ad | Jump to ad if r1 less than r2            |
	| JLE    | r1,r2,ad | Jump to ad if r1 less or equal to r2     |
	| JMP    | ad       | Jump to specified address                |
	| JNE    | r1,r2,ad | Jump to ad if r1 does not equal r2       |
	| LDI    | r1,im    | Load immediate value to r1               |
	| MOV    | r1,r2    | Move value from r1 to r2                 |
	| MUL    | r1,r2    | Multiply r1 by r2                        |
	| NEG    | rs,rd    | Negate rs and place into rd              |
	| NORM   | vs,vd    | Normalize a vector                       |
	| PROG   | pvn      | Set program identity at current location |
	| RET    |          | Return to caller                         |
	| SIN    | rs,rd    | Place sin of rs in degrees into rd       |
	| SQR    | rs,rd    | Place square of rs into rd               |
	| SQRT   | rs,rd    | Place square root of rs into rd          |
	| SUB    | r1,r2    | Subtract r2 from r1                      |
	| TAN    | rs,rd    | Place tan of rs in degrees into rd       |
	| VADD   | v1,v2    | Add vector v2 to v1                      |
	| VLEN   | vs,rd    | Write length of vector vs to Rd          |
	| VMOV   | vs,vd    | Move a vector                            |
	| VNEG   | vs,vd    | Negate a vector                          |
	| VSCL   | v1,r1    | Scale vector v1 by r1, result in VRES    |
	| VSUB   | v1,v2    | Subtract vector v2 from v1               |
	| WAIT   |          | Wait until next cycle                    |
[TE]
[I-4]
[=]
[h2]	Special Registers (Read only)
[I4]
[TB]
	| LOC    | Returns                                          |
	| AACC   | Altitude acceleration in m/s                     |
	| ALT    | Altitude in meters                               |
	| ANOD   | Longitude of ascending node                      |
	| APOL   | Apolune in meters                                |
	| AVEL   | Altitude velocity in m/s                         |
	| C1     | Contant value of 1                               |
	| C10    | Contant value of 10                              |
	| C100   | Contant value of 100                             |
	| C1000  | Contant value of 1000                            |
	| CKKBU  | Current value of engine burn clock in seconds    |
	| CLKMI  | Current value of mission clock in seconds        |
	| CLKOR  | Orbit time in seconds                            |
	| EACC   | Longitudinal acceleration in m/s                 |
	| EAST   | Longitude in degrees                             |
	| EVEL   | Longitudinal velocity in m/s                     |
	| GRND   | Ground radius in meters, 1738300                 |
	| INCL   | Inclination of orbit                             |
	| LATACC | Latitude acceleration in m/s                     |
	| LATVEL | Latitude velocity in m/s                         |
	| MASS   | Current mass of the vehicle in kilograms         |
	| METR   | Constant, number of meters per degree at equater |
	| NACC   | Latitudinal acceleration in m/s                  |
	| NOUN   | Current value of Noun                            |
	| NRTH   | Latitude in degrees                              |
	| NVEL   | Latitudinal velocity in m/s                      |
	| PERL   | Perilune in meters                               |
	| PI     | Constant value of pi, 3.14159...                 |
	| PITCH  | Current pitch angle                              |
	| RALT   | Altitude difference to CSM in meters             |
	| RAVEL  | Relative altitude velocity to CSM in m/s         |
	| REVEL  | Relative longitudinal velocity to CSM in m/s     |
	| RLAT   | Latitudinal distance to CSM in degrees           |
	| RLNG   | Longitudinal distance to CSM in degrees          |
	| RNVEL  | Relative latitudinal velocity to CSM in m/s      |
	| ROLL   | Current roll angle                               |
	| TALT   | Altitude different to target in meters           |
	| TANOD  | Relative target Longitude of ascending node      |
	| TINCL  | Relative target Inclination                      |
	| TLAT   | Latitudinal distance to target in degrees        |
	| TLNG   | Longitudinal distance to target in degrees       |
	| VERB   | Current value of verb                            |
	| VRES   | Holds vector results                             |
	| YAW    | Current yaw angle                                |
	| ZERO   | Constant value of 0                              |
[TE]
[I-4]
[=]
[h2]	Special Vector Registers (Read only)
[I4]
[tb]
	| BACK  | Orientation of Back face                        |
	| DOWN  | Orientation of Down face                        |
	| FRONT | Orientation of Front face                       |
	| LEFT  | Orientation of Left face                        |
	| POS   | Current absolute position                       |
	| RIGHT | Orientation of Right face                       |
	| RPOS  | Relative position to CSM                        |
	| RVEL  | Relative velocity to CSM                        |
	| UP    | Orientation of Up face                          |
	| VEL   | Current velocity                                |
	| VRES  | Result of last vector function                  |
[te]
[i-4]
[=]
[h2]	Special Registers (Read/Write)
[I4]
[TB]
        | LOC    | Description                                   |
	| PTRAT  | Pitch rate                                    |
	| RCSRTH | RCS rotation throttle                         |
	| RCSTH  | RCS translation throttle                      |
	| RLRAT  | Roll rate                                     |
	| THRTL  | Main engine throttle                          |
	| YWRAT  | Yaw rate                                      |
	| RCSF   | Rcs Face thruster on/off                      |
	| RCSB   | Rcs Back thruster on/off                      |
	| RCSU   | Rcs Up thruster on/off                        |
	| RCSD   | Rcs Down thruster on/off                      |
	| RCSL   | Rcs Left thruster on/off                      |
	| RCSR   | Rcs Right thruster on/off                     |
[TE]
[I-4]
[=]
[h2]	Core Programs
[I4]
[TB]
	| P  | V  | N  | Program                                |
	| 00 | 00 | 01 | Display POS^ABS and ORB^ABS data       |
	| 00 | 00 | 02 | Display POS^TAR and ORB^TAR data       |
	| 00 | 00 | 03 | Display POS^REL and ORB^REL data       |
	| 00 | 00 | 12 | Display POS^TAR data in meters         |
	| 00 | 00 | 13 | Display POS^REL data in meters         |
	| 00 | 01 | 01 | Display POS^ABS and ascent fuel usage  |
	| 00 | 01 | 02 | Display POS^TAR and descent fuel usage |
[TE]
[I-4]
[=]
[h2]	Core Subroutines
[I4]
[TB]
	| P  | V  | N  | Program                                 |
	| 10 | 00 | 01 | Displays POS^ABS data in R1-R9          |
	| 10 | 00 | 02 | Displays POS^TAR data in R1-R9          |
	| 10 | 00 | 03 | Displays POS^REL data in R1-R9          |
	| 10 | 00 | 12 | POS^TAR data in meters in R1-R9         |
	| 10 | 00 | 13 | POS^REL data in meters in R1-R9         |
	| 11 | 00 | 00 | Absolute velocitys in R4-R6             |
	| 11 | 00 | 01 | Absolute accelerations in R7-R9         |
	| 11 | 00 | 02 | Orbital inclination and A.N. in R11,R12 |
	| 11 | 00 | 03 | Perilune and Apolune in R13,R14         |
	| 11 | 00 | 04 | Target incl and A.N. in R11,R12         |
	| 11 | 00 | 05 | Relative incl and a.n. in R11,R12       |
[TE]
[I-4]
[=]

