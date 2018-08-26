[TB]
	| Verb | Noun | Function                            |
	|  02  |  01  | Enter value for register 1          |
	|  02  |  02  | Enter value for register 2          |
	|  02  |  03  | Enter value for register 3          |
[TE]
[=]
[TB]
	| Verb | Noun | Reg1      | Reg2      | Reg 3      |
	|  01  |  01  | Apoapsis  | Periapsis | Orbit time |
	|  01  |  02  | Longitude | Latitude  |            |
[TE]
[=]
[TB]
	| Prog | Function                                  |
	|  01  | Engine cutoff at end of boost phast       |
	|  02  | Engine cutoff for apoapsis x 1000km       |
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


