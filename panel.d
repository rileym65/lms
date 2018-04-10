[h2]	Ams_Attitude
[er]
	+-------+
	|    att|
	|u/r: 56|
	|f/r: 34|
	|l/s:  0|
	+-------+
[ee]
	This guage displays more accurate attitude information than
	what can be seen from the axis displays. u/r shows the relation
	ship between the Up face and the lunar radial.  An indicator of
	0 would indicate that the Up face is pointing directly away from
	the lunar surface, while 180 would indicate the Up face is point
	ing directly at the lunar surface.  f/r shows the same type of
	relationship for the front face in relation to the ground.  l/s gives the
	angle between the left face and the lunar south pole.  An indicator of 0
	would indicate that the left face is pointing directly south, while an
	indicator of 180 would indicate that the left face was pointing north.
[e-]
[=]
[h2]	Ams_Clocks
[er]
	+------------+
	|      clocks|
	|UT: 10:41:36|
	|MI:  1:30:24|
	|BU:  0:01:03|
	|EV:  0:00:00|
	|DK:  0:00:00|
	|OR:  1:53:59|
	+------------+
[ee]
	This gauge displays important mission clocks.  UT shows
	current universal time.  MI shows the current Mission
	elapsed time.  BU shows either the current burn time of the
	ascent or descent engine if either of these is currently
	operating, otherwise it shows how long the last burn lasted.
	The BU clock is reset each time the ascent or descent engine
	is ignited.  EV shows the duration of the current EVA if an
	EVA is currently in progress, otherwise it shows how long
	the last EVA lasted.  The EV clock will reset at the beginning of each EVA.
	The DK clock shows how long it has been since lifting off from the lunar
	surface.  The OR clocks shows how long 1 orbit takes.  The INS must be set
	to any of the ORB modes for this clock to show an accurate time.
[e-]
[=]
[h2]	Ams_Consumables
[er]
	+-------+
	| consum|
	| ASC:99|
	| RCS:95|
	| DES:99|
	| THR: 0|
	| OXY:98|
	| BAT:98|
	+-------+
[ee]
	This gauge shows the levels of the various LM consumables.  ASC
	shows the percentage of remaining ascent fuel.  If the ascent
	engine is currently running than a ^ flag will be shown just to
	the left of ASC.  RCS shows the remaining percentage of RCS fuel.
	Just to the left the RCS label three possible flags could be
	shown.  A '^' flag indicates that the RCS throttle is currently
	set to high, a 'v' flag indicates that the RCS throttle is
	currently set to low, while a ' ' flag indicates that the RCS
	throttle is set to medium.  DES shows the remaining percentage
	of descent fuel.  If the descent stage has been jettisoned then this
	inidcator will show '**' for the remaining fuel.  If the descent engine is
	currently running then a '^' flag will be shown to the left of this 
	indicator.  THR shows the current descent engine throttle setting.  If the
	descent stage has been jettisoned then this indicator will show '**'.
	OXY shows the remaining percentage of oxygen and BAT shows the remaining
	percentage of the battery.
[e-]
[=]
[h2]	Ams_DockingRadar
[er]
	+-------------+
	|    dock     |
	| +---f|--^-+ |
	| +    v    + |
	| |         |l|
	|--    *    --|
	|r|         | |
	| <    ^    > |
	| +----|b-v-+ |
	+-------------+
[ee]
	The docking radar will show you your alignment to the
	docking port on the CSM.  This gauge will only show data
	when the LM is within 200m of the CSM and the docking
	radar is on.  The 'v' and '^' that appear towards the top
	and bottom of the gauge indicate your roll alignment.  When
	both of these indicators are centered then the LM is rolled
	to the correct angle.  The pitch/yaw angles are depicted
	on the guage with a 'X' symbol.  When the 'X' symbol is
	centered then the LM pitch and yaw are correctly aligned.
	The horizontal and vertial position of the LM to the CSM
	are depicted with a '+' symbol.  When the '+' symbol is centered then the
	LM is correctly positioned to dock.  If the '+' symbol and the 'X' occupy
	the same position on the radar display then a '*' will be shown.  When
	there is a '*' symbol in the center of display then the LM is correctly
	positioned and pitch/yaw aligned with the CSM.  There are also several
	symbols that can appear on the display frame.  Near the top on the left
	and right edges, if a '-' symbol appears then you are either moving away
	from the docking port or you are moving too slowly for a successful 
	docking.  If a '+' symbol appears in this area then your closing speed
	is too fast for a successful docking.  if in this area you see the usual
	'|' symbol for the frame then your closing speed is ideal for docking.
	At other places on the fram you could see '^', 'v', '<' or '>' symbols.
	These symbols indicate that your horizontal or vertical velocity is too
	high for a successful docking.
[e-]
[=]
[h2]	Ams_DownAxis
[er]
	+-------------------------+
	|    LOOKING   DOWN       |
	| +------west|----------+ |
	| |          f          |n|
	| |                     |o|
	| |                     |r|
	| |                     |t|
	| |                     |h|
	|--L         U          --|
	|s|                     | |
	|o|                     | |
	|u|                     | |
	|t|                     | |
	|h|                     | |
	| +----------|east------+ |
	+-------------------------+
[ee]
	This instrument provides a graphic depiction
	of the vehicle as if you were directly above
	it and looking directly through it to the
	ground.  The 'U' symbol shows the relative
	angle of the up face, the 'F' symbol shows the
	relative angle of the front face and the 'L'
	symbol shows the relative angle of the left
	face.  If any of these symbols are closer to
	the ground in relation to the local horizon
	plane then they will appear as lowercase,
	whereas if these faces are closer to the
	imaginary observer than the local horizon plane
	then they will appear in uppercase. The 'west',
	'east', 'north', and 'south' edges of the
	display depict the local lunar directions.
	The example display indicates that the front
	face is facing directly westward, the left face is facing directly south
	and the up face is pointing directly away from the lunar surface.
[e-]
[=]
[h2]	Ams_Ins
[er]
	+---------------------------+
	|   altitude    east   north|
	|POS:  26020:  44.17:  -0.01|
	|VEL:  -19.0:-1683.5:   -0.1|
	|ACC:    0.0:   -0.0:    0.0|
	|MOM:POS^ABS: -64.71:  90.99|
	|PER:   21.2                |
	|APO:   98.7                |
	+---------------------------+
[ee]
[e-]
[=]
[h2]	Ams_LandingRadar
[er]
	+-------------+
	|    land     |
	| +---w|----+ |
	| |         | |
	| |         |n|
	|--         --|
	|s|         | |
	| |         | |
	| +----|e---+ |
	+-------------+
[ee]
	The landing radar displays information pertinant to
	landing.  A graphics depiction of the lunar topography
	below the lander will show in the display.  Near the top
	left and right edge if there are '+' indicators this
	indicates that the downward velocity of the LM is too high
	for landing.  If on the top right edge of the display there
	is a '^' flag showing, this indicates that the LM is moving
	too quickly to the west for a safe landing.  On the bottom
	right edge if there is a 'v' flag showing, this indicates
	that the LM is moving too quickly eastwards for a safe
	landing.  On the right edge near the bottom if there is a '>' flag, this
	indicates that the LM is moving too quickly nortwards to land safely and
	on the left edge near the bottom if there is a '<' flag then the LM is
	moving too quickly southwards for a safe landing.  The various velocity
	warning flags will only show if the landing radar is on, the altitude of
	the LM is below 18,000 meters and the LM is upright enough for the 
	landing radar to be receiving a signal.
[e-]
[=]
[h2]	Ams_Lm
[er]
	+------+
	|    lm|
	|--:   |
	|--:   |
	|RK:  0|
	+------+
[ee]
	This instrument displays information about the LM.  The only
	data it displays is the amount of rock currently loaded onto the
	LM.  The RK display indicates how many kilograms of samples have
	been loaded.
[e-]
[=]
[h2]Ams_Lrv
[er]
	+------+
	|^  lrv|
	|BAT:99|
	|BOX: 8|
	|ROK: 0|
	+------+	
[ee]
	This group of displays shows information about the rover.  BAT
	shows what percentage of battery life remains.  BOX shows how many
	sample boxes are left and ROK indicates how many kilograms of
	samples are currently carried on the rover.  The rover carries
	one sample box at a time and each sample box can hold up to 30
	kilograms of samples.  A '^' flag will appear in the upper left
	corner of this gauge to indicate that the rover has been unpacked and setup
	ready for use.  If this '^' flag is absent then the rover is still packed
	away in the descent module.
[e-]
[=]
[h2]	Ams_Message
[er]
	+---------------+
	|----------:    |
	+---------------+
[ee]
	This is the message display area for the onboard
	sequencer.  When the sequencer is active performing a
	task the task and how many seconds left will be displayed
	on this instrument.
[e-]
[=]
[h2]	Ams_Pilot
[er]
	+-------------------+
	| CSM|*LM | LRV| EVA|
	+-------------------+
[ee]
	This shows where the pilot is current located.  An
	'*' symbol will be displayed next to the location
	where the pilot is located.  The possible locations
	are CSM=Command Service Module, LM=Lunar Module, LRV=Lunar Rover and 
	EVA=Outside any vehicle.
[e-]
[=]
[h2]Ams_Plss
[er]
	+------+
	|^ plss|
	|OXY:99|
	|BAT:99|
	|PAK: 4|
	+------+
[ee]
  This area displays information related to the PLSS, Portable
Life Support System.  OXY indicates what % of oxygen remains.
BAT shows what % of battery power remains and PAK indicates how
many PLSS recharge packs are left.  If there are no packs left
then you will no longer be able to equip the PLSS.
[e-]
[=]
[h2]	Ams_Sequencer
[er]
	+--------------+
	| ABO| KIL| PIL|
	| JET| LIF| ---|
	+--------------+
[ee]
[e-]
[=]
[h2]	Ams_Spin
[er]
	+------+
	|  spin|
	|PIT: 0|
	|ROL: 0|
	|YAW: 0|
	+------+
[ee]
[e-]
[=]
[h2]	Ams_Status
[er]
	+--------------+
	|        status|
	| F/B|vSS|MB:30|
	| L/R|vPL|EF:75|
	| U/D|^CB|IN: 1|
	| RAD| --|--:  |
	| DOK| DK|--:  |
	|^DSN| TD|--:  |
	+--------------+
[ee]
[e-]
[=]
[h2]	Ams_WestAxis
[er]
	+-------------------------+
	|    LOOKING   WEST       |
	| +--------up|----------+ |
	| |          U          |n|
	| |                     |o|
	| |                     |r|
	| |                     |t|
	| |                     |h|
	|--L         f          --|
	|s|                     | |
	|o|                     | |
	|u|                     | |
	|t|                     | |
	|h|                     | |
	| +----------|down------+ |
	+-------------------------+
[ee]
[e-]
[=]
[h2]	MapMedium
[er]
	+-------------------------+
	| +------west|----------+ |
	| |                     |n|
	| |       *    o    o  o|o|
	| |       .o            |r|
	| |  .       .          |t|
	| |       .     *  ^    |h|
	|--        O @       o  --|
	|s|.o       lm   . *    | |
	|o|                   * | |
	|u|  .o                 | |
	|t|.                  .o| |
	|h|              O *    | |
	| +----------|east------+ |
	+-------------------------+
[ee]
[e-]
[=]
[h2]	Rcs
[er]
	+--------------------+
	| F/B  PT: 0.0 RTH: ^|
	| L/R  RL: 0.0 TTH:  |
	| U/D  YW: 0.0 PRP:95|
	+--------------------+
[ee]
[e-]
[=]
[h2]	Attitude
[er]
	+-------------------+
	|u/r: 90.0 u/o: 90.0|
	|f/r: 22.9 f/o: 67.1|
	|l/s: 90.0 l/o: 22.7|
	+-------------------+
[ee]
[e-]
[=]
[h2]	LmFuel
[er]
	+-------+
	|ASC: 99|
	|DES: 99|
	+-------+
[ee]
[e-]
[=]

[h2]	OxygenBattery
[er]
	+-------+
	|OXY: 99|
	|BAT: 99|
	+-------+
[ee]
[e-]
[=]

[h2]	Pilot
[er]
	+------+
	|MB: 30|
	|EF: 75|
	|IN:  0|
	+------+
[ee]
[e-]
[=]

[h2]	PilotLocation
[er]
	+---+
	|LM |
	+---+
[ee]
[e-]
[=]

[h2]	LmRock
[er]
	+------+
	|RK:  0|
	+------+
[ee]
[e-]
[=]

[h2]	EvaPrep
[er]
	+-------------------+
	|PAK: 4  vSS vPL ^CB|
	+-------------------+
[ee]
[e-]
[=]

[h2]	Radars
[er]
	+----+
	| LAN|
	| DOK|
	|^DSN|
	+----+
[ee]
[e-]
[=]

[h2]	Landed
[er]
	+---+
	|^TD|
	+---+
[ee]
[e-]
[=]

[h2]	Docked
[er]
	+---+
	|^DK|
	+---+
[ee]
[e-]
[=]

[h2]	Throttle
[er]
	+-------+
	|THR:  0|
	+-------+
[ee]
[e-]
[=]

[h2]	Clocks
[er]
	+------------+
	|UT: 11:16:07|
	|MI:  1:16:21|
	|BU:  0:00:00|
	|BU:  0:00:00|
	|DK:  0:00:00|
	+------------+
[ee]
[e-]
[=]

[h2]	ClockUT
[er]
	+------------+
	|UT: 10:25:07|
	+------------+
[ee]
[e-]
[=]

[h2]	ClockMI
[er]
	+------------+
	|MI: 48:25:16|
	+------------+
[ee]
[e-]
[=]

[h2]	ClockEV
[er]
	+------------+
	|EV:  3:19:09|
	+------------+
[ee]
[e-]
[=]

[h2]	ClockTE
[er]
	+------------+
	|TE: 15:26:51|
	+------------+
[ee]
[e-]
[=]

[h2]	GroundIns
[er]
	+------------+
	|east:    -15|
	|nrth:     11|
	|mode: REL   |
	| thr:  0    |
	| spd:  0.0  |
	+------------+
[ee]
[e-]
[=]

[h2]	MapLarge
[er]
	+---------------------------------------------+
	| +----------------west|--------------------+ |
	| |  . o ^    o        .            o       | |
	| | O        . .    *       O      o .   .  | |
	| |   *          o.      .o                .| |
	| |oo  ^ . *     O                       ^ O| |
	| |*  o             .        o  .     .     |n|
	| |           O o         o          .  o   |o|
	| |       .           *       . o   O       |r|
	| |     o ^                   .      .      |t|
	| |       .^ o    .              ..O   * o  |h|
	|--           O       m@ *  *       o  .  * --|
	|s|  *              oo     .   *  .    O    | |
	|o| . ^           o            *        ^o  | |
	|u|                                        *| |
	|t|     ^O       o              O.         o| |
	|h|   *     o  .  .      o      o       ^   | |
	| |.       ^       O    *  ^       .        | |
	| |        *           *      * .          .| |
	| | ^            .           ^              | |
	| |O    o  ^  o.        *.          *  *    | |
	| +--------------------|east----------------+ |
	+---------------------------------------------+
[ee]
[e-]
[=]

[h2]	MultiAxis
[er]
	+-------------------------+
	|    LOOKING   PROGRADE   |
	| +===outside|==========+ |
	| |                     | |
	| |                     |n|
	| |                     |o|
	| |                     |r|
	| |                     |m|
	|--L         u          --|
	|a|                     | |
	|n|                     | |
	|o|                     | |
	|r|                     | |
	|m|          f          | |
	| +==========|inside====+ |
	+-------------------------+
[ee]
[e-]
[=]

[h2]	PrecisionAxis
[er]
	+-----------------------+
	|   LOOKING   PROGRADE  |
	|+---------------------+|
	||    Elev     Norm    ||
	||F:   75.94   -0.01  +||
	||                     ||
	||U:   -0.01  -89.99  -||
	||                     ||
	||L:   14.06   -0.00  -||
	|+---------------------+|
	+-----------------------+
[ee]
[e-]
[=]

[h2]	Lamps
[er]
	+--------------------+
	|ASC ALO ATT OXY BAT |
	|DSC DLO DCK EMG EMG |
	|RCS RLO LCT ELO ELO |
	+--------------------+
[ee]
[e-]
[=]

[h2]	OrbitLarge
[er]
	+---------------------------------------------+
	| +----------------west|--------------------+ |
	| |uuu~o^((   (~(   (  O   #  u~~   ^^^/^^^^| |
	| |~u.~^^^^( (~~(( ((^    O  ~~Ou ^^^^OO^^^O| |
	| |~^~~u^~~u(~~~o(((^~u  O  uu~~u^^^^^^^^^^^| |
	| |~~~~^^^u~^~u~u~~~~Ou^u~~~~u/^^^^^O^^^^^^^| |
	| |u~~u~u^~~~~~^u~~u^^~~u~^O^~uu^^O^^^^^^^^^|n|
	| |~uuou~Ouu^uu~uu~~uu~^O~^^~^^u^^^^^^^^^^^^|o|
	| |~~^~~~~^^~~~~~~^Ou~O~u~~^~~~^^^^^^^^^^^^^|r|
	| |^o^~~~~^u~~Ou~uuuO~~^~uu~~~~^#^^^^^^^^^^O|t|
	| |^~^~~~~(^^~^u^o~^^u^~~^~~u^^^^O^^^^^^^^^^|h|
	|--^^u^^~(((~^~^u~uo^^u~uu~~u~O^^^^^^^^^^^O^--|
	|s|^~~u~o~(~~^^u^~uuoOu~^u^~^/^^(o^^^^^^^^^^| |
	|o|~ou^O^~~^~~^^u~~~o^~O~O~^~~~(^(O^^^^O^^^^| |
	|u|~~^~~^u~~~~uu~~~~u~^~~~~^O~~u(^^^^^^^^^^^| |
	|t|~~^~^Ou~~^u~O~^~ouO~~O~~~     ^^^^^^^#^^^| |
	|h|~~~~u~u^~u^u~^~~~^^^o^   O O# ^^^^^^O^^^^| |
	| |~uuuo~~^~~~^^^~uOu^O           ^^^^^^^^^^| |
	| |~~~u~^o#~uOuuuu~^^~O          O  ^^^^^^^^| |
	| |~^uu~~~u~O^~^uOu~~             O   ^^^^^ | |
	| |~u(((~~~uu^~u~u~u  .#   O(          ~    | |
	| +--------------------|east----------------+ |
	+---------------------------------------------+
[ee]
[e-]
[=]

[h2]	Plss
[er]
	+------+
	|  plss|
	|OXY:99|
	|BAT:99|
	|EOX:99|
	|EBT:99|
	|CAR: R|
	+------+
[ee]
[e-]
[=]

[h2]	Seq
[er]
	+-----------------------+
	|ARM  ABO  JET  KIL  LIF|
	+-----------------------+
[ee]
[e-]
[=]
