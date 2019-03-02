[TB]
	| Verb | Noun | Function                            |
	|  00  |  --  | Enter idle mode                     |
	|  06  |  ??  | Show data                           |
	|  16  |  ??  | Monitor data                        |
	|  21  |  --  | Enter value for register 1          |
	|  22  |  --  | Enter value for register 2          |
	|  23  |  --  | Enter value for register 3          |
	|  24  |  --  | Enter value for reg1, reg2          |
	|  25  |  --  | Enter value for reg1, reg2, reg3    |
	|  30  |  --  | Set gimbal angles to zero           |
	|  31  |  --  | Set gimbal angles to reg1,reg2,reg3 |
	|  37  |  --  | Run program specified by noun       |
	|  41  |  --  | Clear event clock                   |
	|  42  |  --  | Set event clock to Reg1,Reg2,Reg3   |
	|  43  |  --  | Start event clock in up mode        |
	|  44  |  --  | Start event clock in down mode      |
	|  45  |  --  | Stop event clock                    |
	|  50  |  --  | Set target. reg1=long*100, reg2=lat*100 |
	|  60  |  --  | reg1 = reg1 + reg2                      |
	|  61  |  --  | reg1 = reg1 - reg2                      |
	|  62  |  --  | reg1 = reg1 * reg2                      |
	|  63  |  --  | reg1 = reg1 / reg2                      |
[TE]
[=]
[TB]
	| Verb | Noun | Reg1        | Reg2         | Reg 3      |
	|  16  |  00  | preg1       | preg2        | preg3      |
	|  16  |  01  | Apoapsis    | Periapsis    | Orbit time |
	|  16  |  02  | Longitude   | Latitude     |            |
	|  16  |  03  | Mass        | Fuel kg      | RCS Fuel kg|
	|  16  |  04  | Roll Gimbal | Pitch Gimbal | Yaw Gimbal |
	|  16  |  05  | true anom.  | mean anom.   | ecc. anom. |
	|  16  |  06  | Asc. Node   | Arg. Peri.   | Peri. Long.|
	|  16  |  07  | GET HH      | GET MM       | GET SS     |
	|  16  |  08  | UTC HH      | UTC MM       | UTC SS     |
	|  16  |  09  | Apo HH      | Apo MM       | Apo SS     |
	|  16  |  10  | Per HH      | Per MM       | Per SS     |
	|  16  |  12  | tarAlt      | TarLong      | TarLat     |
	|  16  |  14  | Main DeltaV | Rcs DeltaV   | Fuel flow  |
	|  16  |  16  | Event HH    | Event MM     | Event SS   |
[TE]
[=]
[TB]
	| Prog | Function                                  |
	|  01  | Engine cutoff at end of boost phase       |
	|  02  | Engine cutoff for apoapsis x 1000km       |
	|  03  | Engine cutoff for deltav in reg1          |
	|  04  | Distance to LM                            |
	|  11  | Automated launch to orbit                 |
	|  15  | Automated TLI                             |
	|  16  | Automated LOI                             |
	|  17  | Automated TEI                             |
	|  20  | Compute circular orbit velocity           |
	|  30  | Hohmann Transfer                          |
	|  31  | Hold prograde attitude                    |
	|  32  | Hold retrograde attitude                  |
[TE]
[=]
[H2]	Programs
[h1]	11
	Input:
[=]
[tb]
	| Reg1 | Orbit altitude in kilometers * 10         |
	| Reg2 | Launch azimuth * 10. 900=east, 0=north    |
[te]

[--]

[h1]	15
	Input:
[=]
[tb]
	| Reg1 | Altitude in Kilometers * 1000             |
	| Reg2 | Angle to Moon * 100                       |
[te]

[--]

[h1]	16
[=]
[tb]
	| Reg1 | Desired orbit altitude                    |
[te]

[--]

[h1]	17
	Input:
[=]
[tb]
	| Reg1 | DeltaV                                    |
[te]

[--]

[H1]	20
	Input:
[=]
[TB]
	| Reg1 | Altitude in kilometers                    |
[TE]
[=]
	Output:
[=]
[TB]
	| Reg2 | Velocity in m/s * 10                      |
[TE]
[=]

[h1]	30
	Input:
[=]
[tb]
	| Reg1 | Destination orbit altitude in km  |
[te]
[=]


