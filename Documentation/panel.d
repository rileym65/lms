[h2]	Accel
[er]
	+------------+
	|Acc:       0|
	+------------+
[ee]
	This instrument shows the amount of acceleration in meters/second
	that the vehicle is currently experiencing.
[e-]

[=]
[--]
[=]

[h2]	Altitude
[er]
	+------------+
	|Alt:       0|
	+------------+
[ee]
	This guage shows the current altitude above the primary body.
	Altitude is measured above the average radius of the body being
	orbited.  If there is no decimal point in the value then the
	value is in meters, otherwise when a decimal point is present
	then the value is in kilometers.
[e-]

[=]
[--]
[=]

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
[--]
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
[--]
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
[--]
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
[--]
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
[--]
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
	This panel shows information from the vehicle's Inertial
	Navigation System, or INS.
[=]
	POS - This line shows the position of the vehicle in relation
	to the reference point.  Altitude is always displayed in meters.
	East and north could be displayed as degress or meters.  If the
	number contains 2 decimal digits then the value is in degrees,
	otherwise the value displayed is in meters.
[=]
	VEL - This line shows the velocities in relation to the reference
	point.  Velocity values are always shown in meters per second.
[=]
	ACC - This line shows the absolute acceleartions for each 
	direction.  Accelerations are always displayed as meters per
	second per second.
[=]
	MOM - The first field of this line shows which mode the INS
	display is running in.  The second field shows the relative
	angle between the vehicle's longitude of ascending node in
	relation to the ascending node of the reference point.  The
	third field shows the relative angle in degrees of the vehicle's
	inclination in relation to the inclination of the reference
	point.
[=]
	PER - This line shows the perilune of the current orbit, or
	in other words the lowest point in the orbit.  This value is
	in kilometers.
[=]
	APO - This line shows the apolune or highest point of the
	current orbit.  This value is shown in kilometers.
[=]
	The INS display operates in 6 modes which can be accessed with
	the <1> through <6> keys.  It is important to note that not
	all information on the INS display is updated depening on which
	mode the INS is running in.  The mode name will have a '^' or 'v'
	symbol in the middle of its name.  If the symbol is '^' then
	only the POS, VEL, and ACC lines are updated.  If the symbol is
	a 'v' then only the MOM, PER, and APO lines are updated.
[=]
[lb12]
[LI]	POS^ABS.  In this mode position and velocity information
	is relative to absolute Lunar coordintes.  North is in
	relation to the Lunar equator and East is in relation to the
	mid-Earth terminator.  Altitude is in reference to the ground.
[LI]	POS^TAR. In this mode position and velocity information is
	in relation to the targeted landing site.
[LI]	POS^REL. In this mode position and velocity information is
	in relation to the oribiting CSM.
[LI]	ORB^ABS. In this mode asending node is in relation to the
	mid-Earth terminator and inclination is referenced to the 
	equator.  An inclination of 90 is an equitoral orbit, while
	0 would inidcate a polar orbit.
[LI]	ORB^TAR. This mode changes the ascending node and inclination
	displays to be relative to the landing site.  You will pass
	directly over the landing site if the ascending node and inclination
	are both 0.
[LI]	ORB^REL. In this mode the ascending node and inclination are
	displayed relative to the ascending node and inclination of the
	CSM.  Your orbit is aligned with the CSM if both the ascending
	node and inclination are both zero.
[LE]
[e-]

[=]
[--]
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
[--]
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
[--]
[=]

[h2]	Ams_Lrv
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
[--]
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
[--]
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
[--]
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
[--]
[=]

[h2]	Ams_Sequencer
[er]
	+--------------+
	| ABO| KIL| PIL|
	| JET| LIF| ---|
	+--------------+
[ee]
	This gauge shows when certain sequencer functions are active.
	A '^' mark will be displayed next to any sequencer function that
	is currently active.  ABO indicates that the Abort sequencer has
	been engaged.  JET indicates that the descent stage jettison
	sequencer has been started.  KIL indicates that the sequencer kill
	all rotation has been activated.  LIF indicates that the lunar
	liftoff sequencer has been activated.  PIL does not function in
	this simulator, but in AMS it indicated when the sequencer auto
	pilot had been engaged.
[e-]

[=]
[--]
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
	This gauge shows current rotational rates around the three 
	vehicle axis.  PIT shows spin around the Pitch axis.  ROL
	shows the rotation rate around the Roll axis and YAW shows
	the rotation rate around the Yaw axis.
[e-]

[=]
[--]
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
	This group of gauges shows various status information about
	the vehicle and pilot.  F/B shows the status of the Forward and
	Backward RCS thrusters.  If an '^' appears before this indicator
	then the Forwrard thruster is currently on.  If a 'v' flag appears
	before this indicator then the Backwards thruster is currently on.
[=]
	L/R shows the status of the Left and Right RCS thrusters.  A flag
	will appear before this guage, similar to the F/B guage, indicating
	if either thruster is active.
[=]
	U/D shows the status of the Up and Down RCS thrusters.  A flag
	will appear before this guage, similar to the F/B guage to indicate
	if either thruster is on.
[=]
	RAD indicates the status of the landing radar.  A '^' flag will show
	before this guage if the landing radar is on and a signal is being 
	received.  A 'v' flag will appear if the landing radar is on but no
	signal is being received.
[=]
	DOK shows the status of the docking radar.  A '^' flag will show
	before this guage if the docking radar is on and it is receiving
	information from the CSM.  A 'v' flag will be displayed if the
	docking radar is on but no signal is being received.
[=]
	DSN shows the status of the DSN transponder.  A '^' flag will
	appear before this guage if the DSN transponder is on.
[=]
	SS indicates if the pilot is currently wearing the spacesuit.  A
	'^' flag will be displayed if the spacesuit is currently being 
	worn and a 'v' flag will be displayed if the pilot is not wearing
	the spacesuit.
[=]
	PL indicates if the pilot currently has the PLSS equipped.  A '^'
	flag will be shown if the pilot has the PLSS equipped and a 'v'
	flag will be shown if the PLSS is not currently equipped.
[=]
	CB shows the status of the cabin pressurization.  If a '^' flag
	is displayed then then the cabin is currently pressuriezed.  If 
	a 'v' flag is shown then the cabin is depressurized.
[=]
	DK indicates whether or not the LM is docked with the CSM.  A
	'^' flag will be displayed if the LM is currently docked.
[=]
	TD shows whether or not the LM is in contact with the lunar 
	surface.  A '^' will be shown if the LM is currently sitting on
	the lunar surface.
[=]
	MB shows the current metabolic rate of the pilot.
[=]
	EF shows the current efficiency rating of the pilot.
[=]
	IN shows the current injury state of the pilot.  Note that this
	shows both soft and hard injuries in a combined value.  Hard
	injuries are those injuries sustained from a hard landing or
	while moving too fast over rough lurrain.  Soft injury is a value
	that tracks how long the pilot has been awake, which has a negative
	effect on efficiency.
[e-]

[=]
[--]
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
	This instrument provides a graphics depiction of the orientation
	of the vehicle as if the observer was directly east of the vehicle
	and looking directly west through the vehicle.  'U' indicates the
	relative angle of the Up face, 'L' indicates the relative angle
	of the Left face and 'F' indicates the Front face.
[=]
	The vertical depiction of the guage shows the face in relation to
	the local ground.  Towards the bottom of the guage is pointing 
	towards teh ground, while the top of the guage is pointing 
	directly away from the ground.
[=]
	The horizontal depiction of the guage shows the face in relation
	to the local north/south directions.  Towards the left side of 
	the guage indicates the face is facing south while towards the
	right side of the guage the face is towards the north.
[=]
	If any of the face indicators are displayed in lowercase, this
	indicates that the face is further from the imaginary viewer than
	the center line of the vehicle.  In other words the face is
	facing away from the viewer towards the west.
[=]
	In the example display.  The Up face is facing directly away
	from the lunar surface, the Left face is facing the south and the
	Front face is facing directly west.
[e-]

[=]
[--]
[=]

[h2]	Attitude
[er]
	+-------------------+
	|u/r: 90.0 u/o: 90.0|
	|f/r: 22.9 f/o: 67.1|
	|l/s: 90.0 l/o: 22.7|
	+-------------------+
[ee]
	This panel shows a number of useful orientation angles.
[=]
	u/r - This shows the angle between the up face of the vehicle
	and the ground.  A value of 0 would indicate that the up face
	is facing away from the ground, while a value of 180 would 
	indicate the up face is directly facing the ground.
[=]
	f/r - This shows the angle between the forward face of the
	vehicle and the ground.  A value of 0 would indicate that the
	forward face is facing directly away from the ground, while a
	value of 180 would indicate that the forward face is directly
	facing the ground.
[=]
	l/s - This shows the angle between the left face and absolute
	south.  A value of 0 would indicate that the left face is pointing
	directly south, while a value of 180 would indicate that the left
	face is facing directly north.
[=]
	u/o - This shows the angle of the up face in relation to the
	direction of travel, or prograde direction.  A value of 0
	would indicate that the up face is pointing directly in the
	direction of travel, while a value of 180 would indicate that
	the up face is pointing directly retrograde.
[=]
	f/o - This shows the angle between the forward face in relation
	to the direction of travel.  A value of 0 would indicate that
	the forward face is facing directly prograde, while a value of
	180 would indicate that the forward face is facing directly
	retrograde.
[=]
	l/o - This shows the angle between the left face in relation
	to the direction of travel.  A value of 0 would indicate
	that the left face is facing directly prograde, while a value
	of 180 would indicate that the left face is facing directly
	retrograde.
[e-]

[=]
[--]
[=]

[h2]	Battery
[er]
	+-------+
	|Bat: 99|
	+-------+
[ee]
	This instrument shows the percentage of battery remaining in
	the current vehicle.
[e-]

[=]
[--]
[=]

[h2]	ClockBu
[er]
	+------------+
	|BU:  0:00:00|
	+------------+
[ee]
	This clock shows the duration of the current/last main engine burn.
[e-]

[=]
[--]
[=]

[h2]	ClockEV
[er]
	+------------+
	|EV:  3:19:09|
	+------------+
[ee]
	This clock shows the duration of the current/last EVA.
[e-]

[=]
[--]
[=]

[h2]	ClockGE
[er]
	+------------+
	|GE:102:25:31|
	+------------+
[ee]
	This clock shows the current ground elapsed time for the entire
	mission.  This clock starts with launch from earth and stops at
	splashdown.
[e-]

[=]
[--]
[=]

[h2]	ClockMI
[er]
	+------------+
	|ME: 48:25:16|
	+------------+
[ee]
	This clock shows the current time for the Lunar mission phase of a
	mission.  It starts when the LM is undocked from the CSM and stops
	when the LM redocks with the CSM.
[e-]

[=]
[--]
[=]

[h2]	ClockOT
[er]
	+------------+
	|OT:  1:28:22|
	+------------+
[ee]
	This clock shows the amount of time to complete 1 orbit of the 
	primary body.
[e-]

[=]
[--]
[=]

[h2]	Clocks
[er]
	+------------+
	|UT: 11:16:07|
	|ME:  1:16:21|
	|BU:  0:00:00|
	|EV:  0:00:00|
	|DK:  0:00:00|
	+------------+
[ee]
	This guage shows a collection of clocks all in a single instrument.
[=]
[lb]
[li]	UT - The current UTC time.
[li]	ME - The current Mission Elapsed time.
[li]	BU - The time of the current/last main engine burn.
[li]	EV - The time of the current/last EVA.
[li]	DK - The time since lifting off from the Lunar surface.
[le]
[e-]

[=]
[--]
[=]

[h2]	ClockTB
[er]
	+------------+
	|TB:  0:11:21|
	+------------+
[ee]
	This clock shows the total time that main engines have been operating.
[e-]

[=]
[--]
[=]

[h2]	ClockTE
[er]
	+------------+
	|TE: 15:26:51|
	+------------+
[ee]
	This clock shows the total time spend on EVAs.
[e-]

[=]
[--]
[=]

[h2]	ClockUT
[er]
	+------------+
	|UT: 10:25:07|
	+------------+
[ee]
	This clock shows the current UTC time.
[e-]

[=]
[--]
[=]

[h2]	Computer
[er]
	+-----------------------------+
	|   P 00      V 00      N 00  |
	| -0000000  -0000000  -0000000|
	| -0000000  -0000000  -0000000|
	| -0000000  -0000000  -0000000|
	|     RUN  IDL  INP  ERR      |
	| -0000000  -0000000  -0000000|
	| -0000000  -0000000  -0000000|
	+-----------------------------+
[ee]
	This guage shows the UI of the guidance computer.  The 'P', 'V',
	and 'N' fields show what the current Program, Verb and Noun are.
	There are 15 register displays shown below the PVN line.  These
	register displays show information from the currently running
	program and their contents will vary by program.  Refer to the
	guidance computer manual for more information about what is 
	displayed.  the 'RUN' flag will be shown if the computer is
	currently running a program.  'IDL' will be shown if the computer
	is not running a program and is in the idle state.  The 'INP'
	flag will be shown anytime the computer is expecting input from
	the user.  'ERR' is displayd if the computer encounters any
	errors during a program run.  Usually an error code will be
	displayed in register 13 (lowest left register), refer to the
	guidance computer manual for the meanings of error codes.
[e-]

[=]
[--]
[=]

[h2]	CsmComputer
[er]
	+------+
	|R    P|
	|    02|
	|  V  N|
	| 16 09|
	|+00000|
	|+00045|
	|+00037|
	+------+
[ee]
	This is the main interface for the CSM computer.  The number 
	below P specifies which program number is running.  The number
	below V specifies what the current verb is, while the number
	below N specifies what the current noun is.  The three five
	digit numbers below these are registers 1, 2, and 3 of the
	computer.  Refer to the CSM Computer Operators Guide for
	details on how to use the CSM guidance computer.
[e-]

[=]
[--]
[=]

[h2]	CsmDock
[er]
	+-------------------------+
	|      v      Align       |
	| +----|----+ pX:  +0.0231|
	| |         | dX:  +0.0012|
	| |         |             |
	|>-    +    - pY:  +0.1073|
	| |         | dX:  -0.0102|
	| |         |             |
	| +----|----+ pZ:  +7.8240|
	|      ^      dZ:  -0.1260|
	+-------------------------+
[ee]
	This panel contains the docking radar.  The arrow above the
	targetting display indicates the relative roll angle to the
	target.  When the roll is aligned with the target the arrow
	will be centered.
[=]
	The arrow along the left edge shows the relative pitch angle
	to the target.  When the arrow is centered then the pitch angle
	is aligned with the target.
[=]
	The arrow under the target display indicates the current yaw
	angle in relation to the target.  When the yaw angle is aligned
	with the target the arrow will be centered.
[=]
	When the docking port of the current vehicle is pointing away
	from the docking point of the target then all the angle arrows
	will point away from the target display.
[=]
	The '+' in the target display indicates your lateral alignment
	to the docking port of the target.  When it is centered then
	your are lateraly aligned with docking port, otherwise the '+'
	symbol indicates the direction you need to go in order to become
	aligned.
[=]
	The pX and pY indicate your current position in meters from the
	center of the target docking port.  These give you a more precise
	location than the '+' in the docking display.
[=]
	The dX and dY values indicates your velocity in relation to the
	target docking port.  dX indicates your left/right movement while
	the dY indicates your forward/backward movement.
[=]
	When you are properly aligned with the docking port, both in angles
	and position the the 'Align' lamp will be lit and it is safe to dock.
	If the 'Align' lamp is not lit then you are not aligned and docking
	cannot be performed.
[e-]

[=]
[--]
[=]

[h2]	CsmLamps
[er]
	+-------------------+
	|BSP PAR     DCK RCS|
	|SMJ SPS     BST ATT|
	|RMJ RTR         ARM|
	+-------------------+
[ee]
	This panel contains annunciator lamps to indicate various status
	conditions relevant to the CSM.
[=]
	The following indicators could appear on this panel:
[=]
[TB]
	| BSP | - | The spacecraft has been separated from the booster.     |
	| SMJ | - | The service module has been jettisoned.                 |
	| RMJ | - | The retro module has been jettisoned.                   |
	| PAR | - | The main parachutes have been deployed.                 |
	| SPS | - | The service module engine is currently running.         |
	| RTR | - | The retro module engine is currently running.           |
	| DCK | - | The CSM is currently docked with the LM                 |
	| BST | - | The CSM is docked with the LM and still attached to the booster |
	| RCS | - | An RCS translation thruster is currently running        |
	| ATT | - | The spacecraft is spinning on at least one axis         |
	| ARM | - | The ARM switch is currently set                         |
[TE]
[e-]
	
[=]
[--]
[=]

[h2]	Days
[er]
	+------------+
	|DY:        0|
	+------------+
[ee]
	This indicates how many days have elapsed since the simulation first
	started.
[e-]
	
[=]
[--]
[=]

[h2]	Declination
[er]
	+------------+
	|Dec:   21.99|
	+------------+
[ee]
	This gauge shows the spacecraft's current declination (or celestial
	latitude) in relation to the equator of the primary body the craft
	is in orbit of.
[e-]
	
[=]
[--]
[=]

[h2]	Docked
[er]
	+---+
	|^DK|
	+---+
[ee]
	This guage shows whether or not the LM is docked with the CSM.
[e-]

[=]
[--]
[=]

[h2]	Engines
[er]
	+---+
	|O O|
	| O |
	|O O|
	+---+
[ee]
	This instrument shows the status of the engines on the launch
	vehicle.  There will be as many symbols as the most engines used
	on any stage of the launch vehicle.  An 'O' indicates that engine
	is not currently running.  A '*' symbol indicates an engine that
	is running.
[e-]

[=]
[--]
[=]

[h2]	EvaPrep
[er]
	+-------------------+
	|PAK: 4  @SS @PL  CB|
	+-------------------+
[ee]
	This panel shows the current readiness for EVA.
[=]
	PAK - This shows how many PLSS charges are remaining.
[=]
	SS - This indicates whether or not the pilot is wearing
	their space suit.  If the pilot is wearing their spacesuit
	then a '@' will appear to the left of this indicator.
[=]
	PL - This indicates whether or not the pilot is wearing
	their PLSS.  If the pilot is wearing their PLSS then a
	'@' will appear to the left of this indicator.
[=]
	CB - This indicates whether or not the LM cabin is pressurized.
	If the cabin is pressurized then a '@' will appear to the left
	of this indicator.
[e-]

[=]
[--]
[=]

[h2]	Fuel
[er]
	+-------+
	|Fs1: 99|
	|Fs2: 99|
	|Fs3: 99|
	+-------+
[ee]
	This instrument show what percentage of fuel remains in each
	stage of the launch vehicle.  There will be as many entries
	showing on the gauge as their are stages in the launch vehicle.
	If the spacecraft has been separated from the launch vehicle
	then all values on the gauge will display as '--'.
[e-]

[=]
[--]
[=]

[h2]	Ground
[er]
	+------------+
	|Gnd:  -73.52|
	+------------+
[ee]
	This instrument shows what the current gound longitude is that
	is immediately below the spacecraft.
[e-]

[=]
[--]
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
	The ground INS instrument gives navigational information for the
	LRV or PLSS and is meant for moving around on the Lunar surface.
	The ground INS operates in 8 modes, the keys <1> through <8>
	select which mode the instrument is operating in:
[=]
[i4]
[lb1]
[li]	ABS - The coordinates are the absolute latitude and longitude.
[li]	REL - The coordinates are relative to the targetted landing site.
[li]	LM  - The coordinates are relative to the LM.
[li]	PRI - The coordinates are relative to the primary sampling site.
[li]	SEC1 - The coordinates are relative to secondary site 1.
[li]	SEC2 - The coordinates are relative to secondary site 2.
[li]	SEC3 - The coordinates are relative to secondary site 3.
[li]	LRV  - The coordinates are relative to the LRV.
[le]
[i-4]
[=]
	In addition to the coordinates this instrument also provides you
	with the throttle setting and speed at which you are currently
	moving in meters/second.
[e-]

[=]
[--]
[=]

[h2]	Inclination
[er]
	+------------+
	|Inc:   28.50|
	+------------+
[ee]
	This gauge shows what the inclination of the spacecraft's current
	orbit is around the primary body.
[e-]

[=]
[--]
[=]

[h2]	Lamps
[er]
	+--------------------+
	|ASC ALO ATT OXY BAT |
	|DSC DLO DCK EMG EMG |
	|RCS RLO LCT ELO ELO |
	+--------------------+
[ee]
	This panel contains various indicator lights to alert
	the pilot to various conditions.  The indicator for a condition
	will only show if that condition is currently occuring, otherwise
	the indicator will remain dark.
[=]
	The following indicators could appear on this panel:
[=]
[TB]
	| ASC | - | The ascent engine is currently running.          |
	| DSC | - | The descent engine is currently running.         |
	| RCS | - | An RCS translation thruster is on.               |
	| ALO | - | Ascent fuel has fallen below 10%.                |
	| DLO | - | Descent fuel has fallen below 10%.               |
	| RLO | - | RCS propellant has fallen below 10%.             |
	| ATT | - | The spacecraft is spinning on at least one axis. |
	| DCK | - | The spacecraft is currently docked.              |
	| LCT | - | The spacecraft is in contact with the lunar surface.  |
	| OXY | - | The available oxygen has fallen below 10%.            |
	| EMG | - | This lamp below the OXY lamp indicates that emergency
	oxygen is currently being used.                                   |
	| ELO | - | This lamp below the OXY lamp indicates that emergency
	oxygen has fallen below 10%.                                      |
	| BAT | - | This indicates that battery power has fallen below 10%. |
	| EMG | - | This lamp below the BAT lamp indicates that emergency
	battery power is being used.                                        |
	| ELO | - | This lamp below the BAT lamp indicates that emergency
	battery power has fallen below 10%.                                 |
[TE]
[e-]

[=]
[--]
[=]

[h2]	Lan
[er]
	+------------+
	|Lan: -165.47|
	+------------+
[ee]
	This instrument shows the longitude of ascending node of the spacecraft's
	current orbit.  This longitude is the celestial longitude and not
	the ground longitude.
[e-]

[=]
[--]
[=]

[h2]	Landed
[er]
	+---+
	|^TD|
	+---+
[ee]
	This guage shows whether or not the LM is in contact with the
	Lunar surface.
[e-]

[=]
[--]
[=]

[h2]	LmFuel
[er]
	+-------+
	|ASC: 99|
	|DSC: 99|
	+-------+
[ee]
	This instrument displays the amount of fuel and is only
	valid for the LM.  ASC shows the percentage of ascent fuel
	remaining while DSC shows the remaining percentage of 
	descent fuel.  If the descent stage has been jettisoned then
	the DSC value will appear as "**".
[e-]

[=]
[--]
[=]

[h2]	LmRock
[er]
	+------+
	|RK:  0|
	+------+
[ee]
	This guage shows how many kilograms of samples have been loaded
	onto the LM.
[e-]

[=]
[--]
[=]

[h2]	Lrv
[er]
	+------+
	|^  lrv|
	|OXY:--|
	|BAT:47|
	|BOX: 6|
	|ROK:20|
	+------+
[ee]
	This guage provides information about the LRV.  If the lrv has
	been setup then a '^' flag will appear in the upper left corner
	of this guage.
[=]
	OXY gives the percentage of oxygen remaining in the LRV oxygen tank.
	If a particular LRV model does not carry additional oxygen then a
	'--' flag will be shown here.
[=]
	BAT gives the percentagle of battery remaining.  Once the battery
	run out then the LRV will no longer be able to move.
[=]
	BOX specifies how many sample boxes remain.  The sample box 
	currently carried on the rover is included in this count.  When
	this number shows zero then you can no longer store samples on
	the rover.
[=]
	ROK indicates how many of kilograms of samples are currently
	stored on the rover.
[e-]

[=]
[--]
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
	This instrument gives a large detailed map of the lunar surface.  It is
	primarily used for the LRV or PLSS panels for surface exploration.
[e-]

[=]
[--]
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
	This shows the current lunar surface.  The pilot is always in the
	middle of the display and represented by an '@' symbol.  Each cell
	of the map represents 10m x 10m of the lunar surface.  the various
	symbols on the map represent features on the lunar suface.
[e-]

[=]
[--]
[=]

[h2]	Moon
[er]
	+--------------------------+
	| Moon           G:   0.00 |
	| Dst: 370400  Ang:  89.99 |
	| Ra:   90.00  Dec:  28.58 |
	+--------------------------+
[ee]
	This panel gives information on the location of the Moon and can be
	used to determine when to initiate TLI or TEI.
[=]
 	The panel contains the following data:
[=]
[tb]
	| Dst: | - | This is the current distance in km between the center
	             of the Moon and the center of the earth.|
	| Ra:  | - | This is the current Right Ascension (celestial longitude)
	             of the Moon in relation to the Earth. |
	| Dec: | - | This is the current declination (celestial latitude)
	             of the Moon in relation to the Earth. |
	| G:   | - | This indicates the current gravitation effect the Moon
	             has on the spacecraft.|
	| Ang: | - | This indicates the angle difference between the Moon
	             and the spacecraft.  A positive number indicates how
	             many degrees the Moon is ahead of the spacecraft, while
	             a negative number indicates how many degress the Moon
	             is behind the spacecraft. |
[te]
[e-]

[=]
[--]
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
	The Multi-Axis display gives you a graphic depiction of the
	orientation of the vehicle.  The best way to visualize what
	this guage is doing is to imagine yourself outside the
	vehicle looking through the vehicle in the indicated direction.
	For example, if the guage is set to 'LOOKING DOWN' mode, you
	would be located above the vehicle looking through it to the
	ground.
[=]
        Inside the guage itself you will find three letters:
[=]
[lb2]
[liU]	This represents the up face of the lander.  This is the face
	that would be above the pilot's head.
[liF]	This represents the front face of the lander.  This is the face
	the pilot is looking out.
[liL]	This represents the left face of the lander.  This is the face
	on the left side of the pilot.
[LE]
[=]
	Any letter that is in lowercase indicates that the corresponding
	face is directed away from the hypothetical viewer.  A letter
	showing in uppercase indicates that the face is directed towards
	the hypothetical viewer.
[=]
	This instrument has 4 operating modes: Down, West, Prograde, and
	Absolute.  The modes may be cycled through with the '[' and ']'
	keys.
[=]
[LB2]
[LI]	DOWN
[-]	This mode operates the same as the Ams_DownAxis guage.
[LI]	WEST
[-]	This mode operates the same as the Ams_WestAxis guage.
[LI]	PROGRADE
[-]	In this mode the viewer is directly behind the vehicle and
	looking through it directly in the direction of travel.
[=]
	The horizontal axis of this modes shows the relationship of the
	face to the orbit normal.  Orbit normal is a vector that is 90
	degrees to the plane of the orbit.  Orbit normal will be towards
	the north pole of the moon, while the orbit anti-normal will be
	towards the south pole.  Orbit normal and anti-normal are 
	important for plane change burns.
[=]
	The vertical axis of this mode shows whether the face is directed
	inside or outside the orbit on the same plane as the orbit.  If
	the face is above center then the face is pointing outside the
	orbit, away from the orbit center.  If the face is below center
	then the face is pointing inside the orbit, in the direction of
	the orbit center.  for most maneuvers, burning inside or outside
	the orbit is a waste of fuel.
[LI]	Absolute (LOOKING -X)
[-]	In this mode the orientation of the vehicle is shown in absolute
	coordinates irregardless of location of the vehicle around the
	moon.  In this mode the viewer is located in the +X direction
	from the vehicle and looking directly through the vehicle in the
	-X direction.
[=]
	The horizontal axis of this modes shows the face in relationship
	to the absolute Z coordinate.  The vertical axis of this mode
	shows the relationship of the face to the Y coordinate.
[=]
	This mode is most useful during docking operations since it allows
	you to see the absolute orientation of the vehicle before you are
	close enough to the CSM for the docking radar to give you alignment
	data.
[LE]
[e-]

[=]
[--]
[=]

[h2]	Orbit
[er]
	+----------+
	|u/o:   0.0|
	|f/o:  90.0|
	|l/o:  90.0|
	+----------+
[ee]
	This panel shows the relative angles of the spacecraft primary
	faces in relation to the direction of orbit.  u/o shows the
	angle for the upward face, f/o shows the angle for the forward
	face, and l/o shows the angle for the left face.
[e-]

[=]
[--]
[=]

[h2]	Orbiting
[er]
	+------+
	|EARTH |
	+------+
[ee]
	This gauge indicates what the primary body is that the navigation
	instruments are using as the origin.
[e-]

[=]
[--]
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
	This shows a low resolution map of the lunar surface.  It
	is primarily used to show the moon from orbit.
[e-]

[=]
[--]
[=]

[h2]	Oxygen
[er]
	+-------+
	|Oxy: 99|
	+-------+
[ee]
	This instrument shows the percentage of oxygen remaining in
	the current vehicle.
[e-]

[=]
[--]
[=]

[h2]	OxygenBattery
[er]
	+-------+
	|OXY: 99|
	|BAT: 99|
	+-------+
[ee]
	This guage shows what percentgage of oxygen and battery power
	remain in the vehicle.
[e-]

[=]
[--]
[=]

[h2]	Periapsis
[er]
	+------------+
	|Per:   100.0|
	+------------+
[ee]
	This instrument shows the periapsis for the spacecraft's current
	orbit, measured in kilometers.
[e-]

[=]
[--]
[=]

[h2]	Pilot
[er]
	+------+
	|MB: 30|
	|EF: 75|
	|IN:  0|
	+------+
[ee]
	This instrument shows information about the pilot's physical
	status.
[=]
	MB - This shows the current metabolic rate.  The higher this
	number the more the pilot's heart is beating.
[=]
	EF - This shows pilot efficiency.  The higher this number the
	more efficient the pilot is at doing their job.  This number
	is decreased by higher metabolic activity or injury.
[=]
	IN - This shows a combined value for hard and soft injury.
	The higher this number is the more injured the pilot.  Injury
	has a direct negative effect on efficiency.  Soft injury is due
	to pilot fatigue, the longer a pilot is awake, the more their
	soft injury goes up.  Sleeping will reduce soft injury.  Hard
	injury are physical injuries sustained by the pilot as a result
	of a hard landing or moving too quickly over rough ground.  Hard
	injury cannot be reduced.
[e-]

[=]
[--]
[=]

[h2]	PilotLocation
[er]
	+---+
	|LM |
	+---+
[ee]
	This instrument shows the current location of the pilot:
[=]
[i4]
[lb]
[li]	LM - The pilot is in the Lunar Module.
[li]	CSM - The pilot is in the Command/Serive Module.
[li]	EVA - The pilot is currently on EVA.
[li]	LRV - The pilot is currently riding the rover.
[le]
[i-4]
[e-]

[=]
[--]
[=]

[h2]	PitchRate
[er]
	+--------+
	|PT:  0.0|
	+--------+
[ee]
	This gauge indicates how quickly the spacecraft is rotating around
	its pitch axis, measured in degrees/second.
[e-]

[=]
[--]
[=]

[h2]	Plss
[er]
	+------+
	|  plss|
	|OXY:99|
	|BAT:99|
	|      |
	|CRT: 4|
	|CAR: R|
	+------+
[ee]
	This guage shows information related to the PLSS.  OXY
	shows what percentage of oxygen remains.  BAT shows what
	percentage of battery power remains.  CRT shows how many
	kilograms of samples have been stored in the sample cart
	and CAR shows what the astronaut is currently carrying and
	may be any of these symbols: 'S' - Sample, 'B' - Sample box,
	'F' - Flag, 'L' - Laser reflector, 'A' - ALSEP package, or
	'-' - nothing.
[e-]

[=]
[--]
[=]

[h2]	Position
[er]
	+------------+
	|Lat:  +18.71|
	|Lng: -121.45|
	|Gnd:  -80.12|
	+------------+
[ee]
	This panel shows the current celestial latitude, celestial
	longitude, and ground longitude of the spacecraft in relation
	to the primary body.
[e-]

[=]
[--]
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
[--]
[=]

[h2]	Prograde
[er]
	+----------------------+
	|    Elev     Norm     |
	|U:    0.94    -0.10  -|
	|F:  -88.86     0.64  -|
	|L:    -0.64  -89.35  +|
	+----------------------+
[ee]
	This panel shows precision data on the angle relationships
	between the spacecraft primary faces and the spacecraft's
	direction of travel.  'U' shows the angles for the upward
	face, 'F' shows the angles for the forward face, and 'L'
	shows the angles for the left face.
[=]
	The 'Elev' numbers show the angles relative to elevation.  If
	the number is positive then the face is pointing in a direction
	that is higher in altitude than the current flight path, or is pointing
	away from the orbit's center point.  A negative number would 
	indicate that the face is facing a lower altitude, or pointing
	inside the orbit toward the orbit's center.
[=]
	The 'Norm' numbers show the angles in relation to the orbit's
	normal vector.  Positive numbers indicate that the face is angled
	towards the orbit normal, while negative numbers indicate that
	the face is angled away from the orbit normal.
[=]
	The final column of the panel will contain either '+' or '-'
	symbols.  A '+' symbol indicates that the face is angled within
	90 degrees of the direction of flight, while a '-' symbol
	indicates the face is angled greater then 90 degrees from the
	angle for flight.
[e-]

[=]
[--]
[=]

[h2]	Propellant
[er]
	+-------+
	|Prp: 99|
	+-------+
[ee]
	This gauge shows the percentagle of propellant for the current main
	engine.  If the spacecraft is still attached to the launch vehicle
	this will be the fuel percentage of the current stage, otherwise
	it will be the fuel available for the service module engine or
	retro engine.
[e-]

[=]
[--]
[=]

[h2]	Radars
[er]
	+----+
	| LAN|
	| DOK|
	|@DSN|
	+----+
[ee]
	This instrument shows which radar the INS is getting its
	navigational information from:
[=]
[i4]
[lb]
[li]	LAN - Landing radar, which provides high resolution signals.
[li]	DOK - Docking radar, which provides high resolution signals.
[li]	DSN - Deep Space Network, which provides low resolution signals.
[le]
[i-4]
[=]
	An '@' symbol appears before the currently active radar.
[e-]

[=]
[--]
[=]

[h2]	Radial
[er]
	+----------+
	|u/r:   0.0|
	|f/r:  90.0|
	|l/r:  90.0|
	+----------+
[ee]
	This panel shows the relative angles of the spacecraft primary
	faces in relation to the local ground.  u/r shows the
	angle for the upward face, f/r shows the angle for the forward
	face, and l/r shows the angle for the left face.
[e-]

[=]
[--]
[=]

[h2]	Rcs
[er]
	+--------------------+
	| F/B  PT: 0.0 RTH: ^|
	| L/R  RL: 0.0 TTH:  |
	| U/D  YW: 0.0 PRP:95|
	+--------------------+
[ee]
	This is the RCS control panel which shows everything related to
	the Reaction Control System.
[=]
	F/B - This shows the status of the Forward and Backwards RCS jets.
	if the forward RCS jet is on then a '<' will appear just to the left of
	the F.  If the backwards RCS jet is on then a '>' will appear just
	to the right of the B.
[=]
	L/R - This shows the status of the Left and Right RCS jets.
	if the left RCS jet is on then a '<' will appear just to the left of
	the L.  If the right RCS jet is on then a '>' will appear just
	to the right of the R.
[=]
	U/D - This shows the status of the Up and Down RCS jets.
	if the up RCS jet is on then a '<' will appear just to the left of
	the U.  If the down RCS jet is on then a '>' will appear just
	to the right of the D.
[=]
	PT - This shows the current pitch rate in degrees per second.
[=]
	RL - This shows the current roll rate in degrees per second.
[=]
	YW - This shows the current yaw rate in degress per second.
[=]
	RTH - This shows the current rotational RCS throttle.  When a
	'^^' symbol is shown then the rotation throttle is set to high.
	When a '--' symbol is shown then the rotation throttle is set to
	medium and when a 'vv' symbol is shown then the rotation throttle
	is set to low.
[=]
	TTH - This shows the current setting of the translation RCS
	throttle.  When a '^^' symbol is shown the translation throttle
	is set to high, when a '--' is shown then the throttle is set
	to medium, and when a 'vv' is shown the throttle is set to low.
[=]
	PRP - This shows what percentage of RCS propellant remains.
[e-]

[=]
[--]
[=]

[h2]	RightAscension
[er]
	+------------+
	|RtA:  145.32|
	+------------+
[ee]
	This gauge shows the spacecraft's current Right Ascension, or
	celestial longitude in relation to the primary body.
[e-]

[=]
[--]
[=]

[h2]	Roc
[er]
	+------------+
	|Roc:    1200|
	+------------+
[ee]
	This instrument shows the current rate of climb, this is the amount
	that altitude is increasing/decreasing, which may be a different
	value than the spacecraft's velocity, depending on the current trajectory.
	A positive number indicates a climb, while a negative number indicates
	a descent.
[e-]

[=]
[--]
[=]

[h2]	RollRate
[er]
	+--------+
	|RL:  0.0|
	+--------+
[ee]
	This gauge indicates how quickly the spacecraft is rotating around
	its roll axis, measured in degrees/second.
[e-]

[=]
[--]
[=]

[h2]	Seq
[er]
	+-----------------------+
	|ARM  ABO  JET  KIL  LIF|
	+-----------------------+
[ee]
	This instrument shows the status of any sequencer actions.
[=]
[TB]
	| ARM | indicates that the ascent engine is armed and ready for
	        either and abort or liftoff action.|
	| ABO | indicates that the abort sequencer has been activated. |
	| JET | shows that the descent stage jettison sequence has been
	        started. |
	| KIL | indicates that the rotation kill function has begun.|
	| LIF | shows that the liftoff from lunar surface sequence has
	        been started. |
[TE]
[e-]

[=]
[--]
[=]

[h2]	Throttle
[er]
	+-------+
	|THR:  0|
	+-------+
[ee]
	This guage shows the throttle setting of the main engine.
[e-]

[=]
[--]
[=]

[h2]	Velocity
[er]
	+------------+
	|Vel:  7809.4|
	+------------+
[ee]
	This indicates the vehicle's current velocity in meters/second.
	The velocity shown is relative to the center of the primary body,
	rotation of the primary body does not effect the value shown.
[e-]

[=]
[--]
[=]

[h2]	YawRate
[er]
	+--------+
	|YW:  0.0|
	+--------+
[ee]
	This gauge indicates how quickly the spacecraft is rotating around
	its yaw axis, measured in degrees/second.
[e-]

[=]
[--]
[=]
