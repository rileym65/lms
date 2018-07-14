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
	1 POS^ABS.  In this mode position and velocity information
	is relative to absolute Lunar coordintes.  North is in
	relation to the Lunar equator and East is in relation to the
	mid-Earth terminator.  Altitude is in reference to the ground.
[=]
	2 POS^TAR. In this mode position and velocity information is
	in relation to the targeted landing site.
[=]
	3 POS^REL. In this mode position and velocity information is
	in relation to the oribiting CSM.
[=]
	4 ORB^ABS. In this mode asending node is in relation to the
	mid-Earth terminator and inclination is referenced to the 
	equator.  An inclination of 90 is an equitoral orbit, while
	0 would inidcate a polar orbit.
[=]
	5 ORB^TAR. This mode changes the ascending node and inclination
	displays to be relative to the landing site.  You will pass
	directly over the landing site if the ascending node and inclination
	are both 0.
[=]
	6 ORB^REL. In this mode the ascending node and inclination are
	displayed relative to the ascending node and inclination of the
	CSM.  Your orbit is aligned with the CSM if both the ascending
	node and inclination are both zero.
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

[h2]	Docked
[er]
	+---+
	|^DK|
	+---+
[ee]
	This guage shows whether or not the LM is docked with the CSM.
[e-]
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

[h2]	ClockUT
[er]
	+------------+
	|UT: 10:25:07|
	+------------+
[ee]
	This clock shows the current UTC time.
[e-]
[=]

[h2]	ClockMI
[er]
	+------------+
	|ME: 48:25:16|
	+------------+
[ee]
	This clock shows the current mission elapsed time.  The
	mission clock starts after undocking is completed.
[e-]
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

[h2]	ClockTE
[er]
	+------------+
	|TE: 15:26:51|
	+------------+
[ee]
	This clock shows the total time spend on EVAs.
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
	The ground INS instrument gives navigational information for the
	LRV or PLSS and is meant for moving around on the Lunar surface.
	The ground INS operates in 8 modes, the keys <1> through <8>
	select which mode the instrument is operating in:
[=]
[i4]
[lb]
[li]	1 - ABS - The coordinates are the absolute latitude and longitude.
[li]	2 - REL - The coordinates are relative to the targetted landing site.
[li]	3 - LM  - The coordinates are relative to the LM.
[li]	4 - PRI - The coordinates are relative to the primary sampling site.
[li]	5 - SEC1 - The coordinates are relative to secondary site 1.
[li]	6 - SEC2 - The coordinates are relative to secondary site 2.
[li]	7 - SEC3 - The coordinates are relative to secondary site 3.
[li]	8 - LRV  - The coordinates are relative to the LRV.
[le]
[i-4]
[=]
	In addition to the coordinates this instrument also provides you
	with the throttle setting and speed at which you are currently
	moving in meters/second.
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
	This instrument gives a large detailed map of the lunar surface.  It is
	primarily used for the LRV or PLSS panels for surface exploration.
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
	This panel contains various indicator lights to alert
	the pilot to various conditions.
[=]
	ASC - The ascent engine is currently running.
[=]
	DSC - The descent engine is currently running.
[=]
	RCS - An RCS translation thruster is on.
[=]
	ALO - Ascent fuel has fallen below 10%.
[=]
	DLO - Descent fuel has fallen below 10%.
[=]
	RLO - RCS propellant has fallen below 10%.
[=]
	ATT - The spacecraft is spinning on at least one axis.
[=]
	DCK - The spacecraft is currently docked.
[=]
	LCT - The spacecraft is in contact with the lunar surface.
[=]
	OXY - The available oxygen has fallen below 10%.
[=]
	EMG - This lamp below the OXY lamp indicates that emergency
	oxygen is currently being used.
[=]
	ELO - This lamp below the OXY lamp indicates that emergency
	oxygen has fallen below 10%.
[=]
	BAT - This indicates that battery power has fallen below 10%.
[=]
	EMG - This lamp below the BAT lamp indicates that emergency
	battery power is being used.
[=]
	ELO - This lamp below the BAT lamp indicates that emergency
	battery power has fallen below 10%.
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
	This shows a low resolution map of the lunar surface.  It
	is primarily used to show the moon from orbit.
[e-]
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

[h2]	Seq
[er]
	+-----------------------+
	|ARM  ABO  JET  KIL  LIF|
	+-----------------------+
[ee]
	This instrument shows the status of any sequencer actions.
[=]
	ARM indicates that the ascent engine is armed and ready for
	either and abort or liftoff action.
[=]
	ABO indicates that the abort sequencer has been activated.
[=]
	JET shows that the descent stage jettison sequence has been
	started.
[=]
	KIL indicates that the rotation kill function has begun.
[=]
	LIF shows that the liftoff from lunar surface sequence has
	been started.
[e-]
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

