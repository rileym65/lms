[c]	Flying the LM
[=]
	This next group of tutorials will go over flying the LM.  These
	tutorials assume that you are in orbit around the Earth in a 
	300km circular orbit (as discussed in the tutorial on Orbital
	Maneuvers) and that you have brought a LM with you into orbit.
[=]
	Due to the amount of information needed for flying the LM, this
	tutorial series will be broken down into 4 separate tutorials.
	This tutorial will go over the instrument panel and the next
	4 you will take increasingly more complex flights in the LM.
[=]
[er]
	+-------------------------+
	|    LOOKING   -X         |
	| +========-Y|==========+ |
	| |          L          | |
	| |                     | |
	| |                     | |
	| |                     |+|
	| |                     |Z|
	|--          F         U--|
	|-|                     | |
	|Z|                     | |
	| |                     | |
	| |                     | |
	| |                     | |
	| +==========|+Y========+ |
	+-------------------------+
[ee]
	Before starting the tutorials on flying the LM, you should orient
	the CSM in absolute mode to this orientation.  Commands that I will
	show in the tutorials will assume this orientation.  Although it is
	not absolutely necessary for you to use this orientation, if you
	choose not to then you will need to adjust your keystrokes
	accordingly.
[e-]
[=]
	To begin you will need to transfer to the LM, you can do this
	by pressing <shift><m> to move to the LM.  It takes about 45
	minutes to transfer to and power up the LM, so use time
	compression to speed things up.
[=]
	Once you are in the LM, you will be presented with a new
	instrument panel.  You will find some familiar instruments here
	and many new ones.
[=]
[er]
	+-------------------------+
	|    LOOKING   DOWN       |
	| +---------------------+ |
	| |     E/W     N/S     | |
	| |F:  -17.96   -9.04  +| |
	| |                     | |
	| |U:  -26.42   63.26  -| |
	| |                     | |
	| |L:   55.83   24.94  +| |
	| +---------------------+ |
	+-------------------------+
[ee]
	We will start in the upper left corner of the panel, where we find
	the precision axis display.  This is very much like the precision
	prograde display that you have used on the CSM and this instrument
	works very similar to it.  But unlike the precision prograde
	display, the precision axis display can work in the same 4 modes
	as the multi-axis display.  It uses similar terminology for
	selecting the modes and generally you will want to set the same
	mode on this instrument as you do on the multi-axis display.
[e-]
[=]
[er]
	+---------------------+
	| u/r: 90.0 u/o: 90.0 |
	| f/r: 20.4 f/o: 69.6 |
	| l/s: 62.0 l/o:159.6 |
	+---------------------+
[ee]
	Right below the precision axis display is the angles panel.  This
	is identical to the same panel on the CSM and works exactly the
	same way.
[e-]
[=]
[er]
	+--------------------------+
	| ARM  ABO  JET  KIL  LIF  |
	+--------------------------+
[ee]
	In the top center is the sequencer panel.  This panel will show
	if any of the sequencer actions have been initiated.  This panel
	will also show if the Abort/Liftoff function is armed.  The
	following indicators can appear in this area:
[=]
[tb]
	| Ind | Meaning |
        | ARM | indicates that the ascent engine is armed and ready for
                either and abort or liftoff action.|
        | ABO | indicates that the abort sequencer has been activated. |
        | JET | shows that the descent stage jettison sequence has been started. |
        | KIL | indicates that the rotation kill function has begun.|
        | LIF | shows that the liftoff from lunar surface sequence has been started. |
[te]
[e-]
[=]
[er]
	+---------------+
	|     land      |
	|  +---w|----+  |
	|  |))uu^^~~~|  |
	|  | ))^u^^~^|n |
	| --O  )~~^^~-- |
	| s|    )uuu~|  |
	|  |    ))uuu|  |
	|  +----|e---+  |
	+---------------+
[ee]
	Below the sequencer panel and to the left is the landing radar.
	The landing radar shows you what is on the ground below the
	spacecraft.  The data shown operates either in high altitude or
	low altitude mode.  When the radar selector is set on LAN then
	the landing radar will show low altitude data, otherwise it shows
	hight altitude data.
[=]
	The spacecraft is considered to be in the center of the radar
	display and when landing the lurraign in the center of the display
	is what you are landing on.
[=]
	Around the edges of the radar display arrow indicators can appear.
	When any of these arrows appear they indicate that you are moving
	too fast in that direction for a safe landing.  The low altitude
	radar and the rate arrows will only show when the data feed is set
	for the LAN mode and the radar has clear view of the ground.  For
	the landing radar to have a clear view of the ground the spacecraft
	cannot being angled more than 60 degrees from vertical and must be
	below 20,000 meters.
[e-]
[=]
[er]
	+-------------+
	|    dock     |
	| +---f|----+ |
	| -    v    - |
	| |         |r|
	|--    *    --|
	|l|         | |
	| |    ^    | |
	| +----|b---+ |
	+-------------+
[ee]
	Next to the landing radar is the docking radar.  The docking
	radar only receives data when the data source selector is set
	to DOK.  Also, in order to receive docking data it is necessary
	for the LM to be oriented towards the CSM and within a few hundred
	meters of it.  I will go into more detail about the docking radar
	in the next tutorial where we do our first docking.
[e-]
[=]
[er]
	+------+
	|  LAN |
	| @DOK |
	|  DSN |
	+------+
[ee]
	Below the landing radar is the source data selector.  This shows
	which source is providing positioning data to both the landing
	and docking radars as well as the guidance computer.
[=]
	When set to LAN, then positioning data comes from the landing
	radar.  For the landing radar to provide positioning data the
	LM cannot be angled more than 60 degrees from vertical and must
	be below 20,000 meters altitude.
[=]
	When set to DOK, the positioning data comes from the docking radar.
	For the docking radar to provide good positioning data the LM must
	be pointed towards the CSM and must be within a few hundred meters
	of the CSM
[=]
	The final mode is DSN, or Deep Space Network.  The DSN provides the
	least accurate positioning data, but does not have restrictions on
	when it can be selected.  When you are in a position that neither
	the LAN or DOK modes can provide data, select the DSN mode.
[e-]
[=]
[er]
	+---------+
	| THR:  0 |
	+---------+
[ee]
	Below the docking radar is the throttle display.  During the Apollo
	era most rocket engines could not be throttled, they were either off
	or at 100% thrust.  The descent engine of the LM was the
	exception.  Since landing would require precise control of velocity
	the descent engine was designed to be throttled.  This indicator
	shows the throttle setting.  During descent this will show your
	throttle setting between 10% and 100%.  During ascent this will
	show 100% to show that the ascent engine is running.
[e-]
[=]
[er]
	+---------------+
	|----------:    |
	+---------------+
[ee]
	Below the throttle is the message display.  This is just like the
	message display on the CSM and can show various messages from
	time to time.
[e-]
[=]
[er]
	+-------------------------+
	|    LOOKING   DOWN       |
	| +======west|==========+ |
	| |      L              |n|
	| |                     |o|
	| |                     |r|
	| |                     |t|
	| |                     |h|
	|--                     --|
	|s|                     | |
	|o| u          F        | |
	|u|                     | |
	|t|                     | |
	|h|                     | |
	| +==========|east======+ |
	+-------------------------+
[ee]
	In the upper right corner is the multi-axis display.  This is the
	same instrument found on the CSM and functions in exactly the same
	way.
[e-]
[=]
[er]
	+--------------------+
	| F/B  PT: 0.0 RTH:^^|
	| L/R  RL: 0.0 TTH:vv|
	| U/D  YW: 0.0 PRP:99|
	+--------------------+
[ee]
	Now to the lower half of the instrument panel, again starting from
	the left, first we have the RCS panel.  This panel is identical
	to the RCS panel on the CSM and works in exactly the same way.
[e-]
[=]
[er]
	+--------------------+
	|ASC ALO ATT OXY BAT |
	|DSC DLO DCK EMG EMG |
	|RCS RLO LCT ELO ELO |
	+---------------------
[ee]
	The annunciator panel is found below the RCS panel.  This panel
	has various lights that indicate status conditions of the spacecraft.
	The following indicators that can appear here are:
[=]
[tb]
	| IND |   | Meaning |
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
        | EMG | - | This lamp below the OXY lamp indicates that emergency oxygen is currently being used.                                   |
        | ELO | - | This lamp below the OXY lamp indicates that emergency oxygen has fallen below 10%.                                      |
        | BAT | - | This indicates that battery power has fallen below 10%. |
        | EMG | - | This lamp below the BAT lamp indicates that emergency battery power is being used.                                        |
        | ELO | - | This lamp below the BAT lamp indicates that emergency battery power has fallen below 10%.                                 |
[te]
[e-]
[=]
[er]
	+-----------------------------+
	|   P 00      V 00      N 01  |
	|   0.0000    0.0000    0.0000|
	|   0.0000    0.0000    0.0000|
	|   0.0000    0.0000    0.0000|
	|          IDL                |
	|   0.0000    0.0000    0.0000|
	|   0.0000    0.0000    0.0000|
	+-----------------------------+
[ee]
	In the lower central section of the panel is the guidance computer
	output.  In this simulation the guidance computer of the LM is
	more sophisticated than that in the CSM.  Where the CSM guidance
	computer only showed 3 registers, the one in the LM shows 15.
	Control of the computer is pretty much the same, but does use
	different command codes to set its modes, although some are the
	same.
[=]
	The P, V, and N fields are just like on the CSM and show the
	current program and last verb and noun entered.
[=]
	The registers are numbered from 1 starting in the upper left
	corner, moving to the right and down.  So the first row has
	register 1 on the left, register 2 in the middle and register
	3 on the right.  Row 2 is then register 4 on the left, register
	5 in the middle and register 6 on the right. and so forth.
[=]
	What is displayed in the registers depends on what modes the
	computer is running in, but in most modes registers 1 through 9
	show specific data:
[=]
[tb]
	| reg 1 | Altitude                   |
	| reg 2 | Longitude                  |
	| reg 3 | Latitude                   |
	| reg 4 | Rate of Climb/Descent      |
	| reg 5 | East/West velocity         |
	| reg 6 | North/South velocity       |
	| reg 7 | Rate of Climb Acceleration |
	| reg 8 | East/West Acceleration     |
	| reg 9 | North/South Acceleration   |
[te]
[=]
	While this is generally what is display in these registers, the
	measurement scale can change between modes and the reference point
	can change between modes.  I will go over more specific data about
	specific modes as we use them in future tutorials.
[e-]
[=]
[er]
	+-------+
	|ASC: 99|
	|DSC: 99|
	|       |
	|OXY: 99|
	|BAT: 99|
	+-------+
[ee]
	To the right of the guidance computer is the consumables panel.
	ASC shows the percentage of ascent fuel remaining, DSC shows the
	percentage of descent fuel remaining.
[=]
	OXY shows the percentage of oxygen remaining and BAT shows the
	percentage of battery power remaining.  Note that most of the
	oxygen and batteries for a mission are located in the descent
	stage and this panel shows the total supply.  When separating
	from the descent stage it is normal to see these guages drop to
	between 8% and 10%, depending on the vehicle.
[e-]
[=]
[er]
	+------------+
	|UT: 12:38:11|
	|GE:  4:07:55|
	|ME:  0:00:00|
	|BU:  0:00:34|
	|DK:  0:00:00|
	+------------+
[ee]
	To the right of the consumables panel are the mission clocks.
	The UT, GE, and BU clocks work the same way as these clocks on
	the CSM.
[=]
	The ME clock is the mission elapsed clock and starts
	running when undocking from the CSM and will continue to run
	throughout the Lunar phase of the mission and will stop when
	docking with the CSM has been completed.
[=]
	The DK clock is the docking clock and begins operating when the
	ascent stage is separated from the descent stage.  After separation
	you only have 8 to 10 hours of oxygen/battery, this clock helps
	you to keep track of your time.
[e-]
[=]
[er]
	+--------------------+
	|PAK: 4   SS  PL @CB |
	+--------------------+
[ee]
	Below the consumables and clocks panels is the EVA status panel.
	This panel shows the following inforation:
[=]
[lb]
[li]	PAK - This shows how many charges you have left for your PLSS.
	Missions provide enough EVA consumabes for 4 EVAs.
[li]	SS - This shows whether or not you are wearing your EVA Space Suit.
	When there is a '@' indicator before this then your suit is on,
	otherwise it is off.  Your space suit must be worn before you can
	put on the PLSS.  It is not necessary to take off your space suit
	during rest periods, which can save you time and energy between
	EVAs.  Although you can keep your space suit on during rendevous
	and docking, it is not recommended since wearing your space suit
	increases you matabolism faster than not wearing it.
[li]	PL - This Shows wheter or not you are wearing your PLSS.  You
	must be wearing your PLSS to exit the spacecraft.  When you are
	wearing your PLSS all oxygen comes from the PLSS, even when inside
	the LM.  So remove it after your EVA.  Plus, in order to recharge
	the PLSS for the next EVA you must remove it.
[li]	CB - This indicator shows whether or not the LM cabin is preassurized.
	when there is a '@' symbol before this, then the cabin is
	preassurized.  The cabin must be depressurized before going out on
	an EVA and must be repressurized before taking off your PLSS.
[le]
[e-]
[=]
[er]
	+------+
	|MB: 55|
	|EF: 72|
	|IN:  0|
	|      |
	| LM   |
	|      |
	|RK:  0|
	+------+
[ee]
	The last panel, in the lower right of the instrument panel, shows
	a few pieces of information.  The top half shows metabolic information.
	Near the bottom is just an indicator that you are in the LM and the
	bottom entry shows how many Lunar samples are currently loaded onto
	the LM.
[=]
	The MB field shows your current metabolic rate.  Your metabolic rate
	is 30 at rest and will increase due to activity.  an increased
	metabolic rate has two effects, first a higher metabolic rate lowers
	your efficiency and second, a higher metabolic rate depletes your
	oxygen faster.  A metaboli rate below 60 does not increase oxygen
	use too drasticaly (about 15% at 60), but anything above 60 starts
	using more oxygen very quickly.  So in order not to cut your mission
	short due to dwindling oxygen supply, try to keep your metabolic
	rate down.  Remember it increases with activity, and decreases
	when idle.
[=]
	The EF field shows your current efficiency and is a guage on how
	well you can perform your duties.  The higher the efficiency the
	better.  Efficiency is lowered by a higher metabolic rate or due
	to injury.  How AMS (Apollo Mission Simulator) handled efficiency
	was my greatest gripe about that program and one of the reasons I
	really wanted to write my own.  In AMS a lower efficiency was handled
	by ignoring keystrokes, which due to the nature of RNGs, it could
	ignore too many keystrokes for too long and you would end up 
	crashing because you could not get the command that you needed in.
[=]
	LMS handles efficiency in an entirely different way that is less
	frustrating.  Instead of efficiency ignoring keystrokes, in LMS
	it can delay keystrokes.  At maximum efficiency you can probably
	enter several keystrokes in a single second that the simulator
	will handle in a timely fashion.  When efficiency is low, it will
	still handle all commands you give, but start introducing delays
	between executing your commands.  So for example at high efficency
	you may be able to enter 4 roll commands in a single 1 second update,
	but when your efficiency is low, you can still press those 4 roll
	commands but now instead of the simulator executing them all in a
	single 1 second update, it may now take 3, 4, or 5 seconds before
	they are all executed.  This way of handling efficiency still gives
	an incentive to keep your efficiency high, but removes the penalty
	of not knowing whether your command will be accepted at all.  In
	LMS, your commands will always be executed, they just may be slower
	due to lower efficiency.
[=]
	IN shows your current injury state.  This is actually an aggregate
	of both "soft" injuries and "hard" injuries.  Injury lowers
	effiency, so keeping your INjury value low is desirable.  There are
	two types of injury, "soft" injury is not actual injury, but rather
	a score for tracking other factors that affect efficiency.  One
	of these is the amount of time that you have been awake.  Soft
	injury is reset to zero when you sleep and when you are awake it will
	slowly climb.  The longer you are awake, the greater soft injury
	rises and the more efficency will be lowered.  Soft injury is not
	affected by activity, just the time you are awake and a more minor
	influence based upon circadian rhythm.  The influence of circadian
	rhythm is cyclic and does not change soft injury by more than about
	10 points but is there to reflect that at certain times of day
	humans are better off and at other times they are more dull.
	Rest periods will not allow soft injury to rise from being awake,
	but they also do not lower it.  Sleeping will completely reset
	soft injury that is a result of being awake.
[=]
	The other type of injury is "hard" injury, this is actual physical
	damage to your body.  Hard injury can result from too hard a landing,
	running too fast over rough lurrain, you can fall and hurt yourself!
	or driving too fast over rough lurrain.  So when you are in rough
	places on the surface, just slow down.  Hard injury does not reset
	and will continue to accumulate if you keep doing damaging activites.
[e-]
[=]
	Now that you know what is on your screen, in the next tutorial
	we will actually take the LM out for a quick flight.
[=]

