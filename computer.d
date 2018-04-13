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
	| DIV    | r1,r2    | Divide r1 by r2                          |
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
	| PROG   | pvn      | Set program identity at current location |
	| RET    |          | Return to caller                         |
	| SIN    | rs,rd    | Place sin of rs in degrees into rd       |
	| SQR    | rs,rd    | Place square of rs into rd               |
	| SQRT   | rs,rd    | Place square root of rs into rd          |
	| SUB    | r1,r2    | Subtract r2 from r1                      |
	| TAN    | rs,rd    | Place tan of rs in degrees into rd       |
	| WAIT   |          | Wait until next cycle                    |
[TE]
[I-4]
[=]
[h2]	Special Registers (Read only)
[I4]
[TB]
        | LOC   | Returns                                       |
	| AACC  | Altitude acceleration in m/s                  |
        | ALT   | Altitude in meters                            |
	| ANOD  | Longitude of ascending node                   |
	| APOL  | Apolune in meters                             |
	| AVEL  | Altitude velocity in m/s                      |
	| C1    | Contant value of 1                            |
	| C10   | Contant value of 10                           |
	| C100  | Contant value of 100                          |
	| C1000 | Contant value of 1000                         |
	| CKKBU | Current value of engine burn clock in seconds |
	| CLKMI | Current value of mission clock in seconds     |
	| EACC  | Longitudinal acceleration in m/s              |
	| EAST  | Longitude in degrees                          |
	| EVEL  | Longitudinal velocity in m/s                  |
	| GRND  | Ground radius in meters, 1738300              |
	| INCL  | Inclination of orbit                          |
	| MASS  | Current mass of the vehicle in kilograms      |
	| NACC  | Latitudinal acceleration in m/s               |
	| NRTH  | Latitude in degrees                           |
	| NVEL  | Latitudinal velocity in m/s                   |
	| PERL  | Perilune in meters                            |
	| PI    | Constant value of pi, 3.14159...              |
	| RALT  | Altitude difference to CSM in meters          |
	| RAVEL | Relative altitude velocity to CSM in m/s      |
	| REVEL | Relative longitudinal velocity to CSM in m/s  |
	| RLAT  | Latitudinal distance to CSM in degrees        |
	| RLNG  | Longitudinal distance to CSM in degrees       |
	| RNVEL | Relative latitudinal velocity to CSM in m/s   |
	| TALT  | Altitude different to target in meters        |
	| TLAT  | Latitudinal distance to target in degrees     |
	| TLNG  | Longitudinal distance to target in degrees    |
	| ZERO  | Constant value of 0                           |
[TE]
[I-4]
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
[TE]
