[TB]
	| Verb | Noun | Function                            |
	|  00  |  --  | Enter idle mode                     |
	|  21  |  --  | Enter value for register 1          |
	|  22  |  --  | Enter value for register 2          |
	|  23  |  --  | Enter value for register 3          |
	|  37  |  --  | Run program specified by noun       |
[TE]
[=]
[TB]
	| Verb | Noun | Reg1      | Reg2      | Reg 3      |
	|  16  |  01  | Apoapsis  | Periapsis | Orbit time |
	|  16  |  02  | Longitude | Latitude  |            |
	|  16  |  03  | Mass      | Fuel kg   | RCS Fuel kg|
[TE]
[=]
[TB]
	| Prog | Function                                  |
	|  01  | Engine cutoff at end of boost phast       |
	|  02  | Engine cutoff for apoapsis x 1000km       |
	|  03  | Engine cutoff for deltav in reg1          |
	|  04  | Distance to LM                            |
	|  10  | Compute circular orbit velocity           |
[TE]
[=]
[H2]	Programs
[H1]	10
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


