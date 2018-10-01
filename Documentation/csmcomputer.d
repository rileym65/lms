[TB]
	| Verb | Noun | Function                            |
	|  00  |  --  | Enter idle mode                     |
	|  21  |  --  | Enter value for register 1          |
	|  22  |  --  | Enter value for register 2          |
	|  23  |  --  | Enter value for register 3          |
	|  30  |  --  | Set gimbal angles to zero           |
	|  31  |  --  | Set gimbal angles to reg1,reg2,reg3 |
	|  37  |  --  | Run program specified by noun       |
[TE]
[=]
[TB]
	| Verb | Noun | Reg1        | Reg2         | Reg 3      |
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
[TE]
[=]
[TB]
	| Prog | Function                                  |
	|  01  | Engine cutoff at end of boost phase       |
	|  02  | Engine cutoff for apoapsis x 1000km       |
	|  03  | Engine cutoff for deltav in reg1          |
	|  04  | Distance to LM                            |
	|  20  | Compute circular orbit velocity           |
[TE]
[=]
[H2]	Programs
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

