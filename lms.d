[C]	Lunar Mission Simulator
[C]	by
[C]	Mike Riley
[=]
	Back in my early days of computers I really enjoyed playing lunar
        landing games.  There were many of these around in the early days
        of home computers, mostly written in BASIC.
[=]
	One example of the simplicity of these early games was a game 
	called ROCKET, which was part of the BASIC computer games collection
	from Creative Computing.  This game was very typical of the lunar
	landing games of the time.  It was turn based and one-dimensional,
	meaning you only had to control the vertical descent.  Each turn
	you would specify how much fuel to burn for the next turn and then
	the simulator would work out the new stats and display them.  You
	continued playing turns until you either successfully landed, or
	crashed.
[=]
	The next level up from ROCKET was another early Creative Computing
	game called LEM.  Like ROCKET, LEM was turned based, but where the
	added complexity came in was that now the game was in two dimensions.
	Now you not only had to control your descent speed but you also had
	to control your horizontal velocity and land as close as possible to
	the landing site.  Unlike ROCKET, LEM was not as easily mastered, 
	but even then, it did not take long before you understood it well
	enough to have a successful landing every time, close to the landing
	site.
[=]
	These early games and others like them were a lot of fun to play in
	the early BASIC days of home computers and I spent many days of my
	youth playing these early games.
[=]
	In the late 80s I found on a PC-SIG disk the ultimate in text based
	lunar landing games.  It was called Apollo Mission Simulator or AMS
	for short.  It was written by Albert H. Reynolds III.  Unlike the
	earlier text based lunar landers, this simulator offered a huge step
	up.
[=]
	Earlier lunar lander games were turn based, giving you lots of time
	between turns to decide what to do for the next turn.  AMS operated
	in real-time, giving a more realistic emersion.  Now you had to 
	react immediately to the situation and think ahead of what was
	happening.  You no longer had the luxury of time to think about what
	to do next.
[=]
	Most of the early games were one-dimensional, you had only to control
	your vertical descent.  There were a few games, like LEM, that 
	extended the simulation into two dimensions, but these were rare in
	text based games.  Graphical lunar lander games often had both
	vertical and horizontal motion, but these tended to be more of an
	arcade experience than actual simulations.  AMS took the next step
	and moved the simulation realm into three dimensions, now you had
	to worry about descent velocity, east/west velocity and now
	north/south velocity.
[=]
	The early games pretty much presented you with the same landing 
	scenario each time.  You started from the same height, same 
	distance, with the same starting conditions.  The main issue with
	this was that it was pretty easy to bracket in landing solutions
	that rendered these games too easy.  AMS gave you the whole moon
	as a potential landing site, well sort of.  At the start of a new
	game you would specify the longitude and latitude of the landing
	site, thereby giving you an endless supply of landing scenarios.
	Although you could specify any latitude/longitude for a landing
	site, the whole moon was not actually within reach since a plane
	change maneuver was required to reach the desired latitude.  The
	plane change maneuver required descent fuel, the further north
	or south from the lunar equator you wanted to land, the less
	fuel you would have after the plane change to actually land.  This
	in effect limited the available landing latitudes, much in the
	same way the actual Apollo program had limits on where they could
	land.
[=]
	The next major leap forward was what happened after you had
	successfully landed.  In all prior lunar landing games once you
	had landed, or crashed, the game was over.  AMS on the other hand
	gave you a whole mission simulation experience.  After you land
	you can get out of the LM, drive around the lunar surface on a 
	rover, and collect samples.  And if that was not enough, once your
	lunar surface operations were complete, you had to lift off from
	the lunar surface and rendevous and dock with the orbiting CSM.
	the game ended once you had redocked with the CSM.
[=]
	At the time that AMS was released, there was nothing really like
	it at all.  Text based games fell way short of what AMS presented,
	graphic games were in the realm of arcade games rather than 
	simulations.  The only other game that could be considered a good
	simulator was a game called "Lunar Explorer."  It was released
	for DOS around 1986 and it gave you a graphics presentation of
	landing on the moon, exploring the moon, and even lift off and
	rendevous with the orbiter.  It was a good game but even it did
	not compare to the extensive realism brought to you by the text
	based AMS.
[=]
	Fast forward to modern times.  Recently I have been converting some
	of the old Creative Computing BASIC games to C so that I could play
	some of my teen favorite games.  Of course I converted ROCKET and
	LEM as being some of my early favorite games.  After playing LEM
	again for the first time in decades I decided to dig out my copy
	of AMS and play it again.  AMS does not run on modern systems, but
	does run well using DosBox.  Playing AMS again reminded me of my
	biggest complaint about the game, the metabolic rate/efficiency
	system it used.  Essentially as your heart rate went up your
	efficiency went down and the way the simulator handed less effiency
	was to ignore keystrokes.  So for instance if your efficiency was
	at 60, only 60% of the keys you press would be recognized by the
	simulator.  Given the nature of RNGs, it could ignore key after
	key after key and if that happens at a crucial point, CRASH!
	Back when I was playing AMS a lot, this was my biggest gripe.
	I crashed far more often because the simulator ignored important
	keys for too long, rather than me misjudging the situation.
[=]
	I tried to see if I could find the author of AMS to see if it
	would be possible to obtain source code, now that it has been
	so long since AMS was first released.  Sending mail to the 
	address listed in the program was returned since the person no
	longer lived at that address, no surprise from a program released
	30 years ago.  Internet searches allowed me to find the game 
	easily enough but not its author.
[=]
	With the inability to find the author and the desire to play
	AMS again, I decided to write a modern version of the game.  One
	that could be run easily on modern systems and one where the 
	source code would be readily available so that others could adapt
	the game to their liking.  Lunar Mission Simulator, or LMS for
	short, was born.  My goal with this project is to provide an
	experience similar to AMS, staying text based, but removing
	the parts of AMS that I found frustrating, as well as extending
	the game beyond what AMS originally provided.
[=]
[H2]	Goals:
	I have the following goals for this project:
[-]
[I4]
[LB]
[LI]	All code will be simple c++, no external dependencies, even my
	own libraries.
[LI]	At minimum, match the functionality of AMS.
[LI]	Any equipment left on the moon will be findable by future missions.
[LI]	Crash debris will also be findable by future missions.
[LI]	Configurable instrument panels.
[LI]	Core game to remain text based.
[LI]	More extensive mission planning.
[LI]	More sample/experiment types.
[LI]	Possibly add launch from earth/return to earth.
[LI]	Possibly multi-vehicle missions.
[LI]	Possibly extended missions.
[LE]
[I-4]
[=]
[H2]	Files:
[I4]
[TB]
	|ams.pnl     |Generic panel based on AMS.|
	|csm.pnl     |Panel definition for the CSM.|
	|lrv.pnl     |Panel definition of the LRV.|
	|lm.pnl      |Panel definition for the LM.|
	|lm.comp     |LM panel definition using guidance computer.|
	|lm.ins      |LM panel definition using INS.|
	|plss.pnl    |Panel definition for EVA.|
	|lms.doc     |Simulator documentation.  This file.|
	|panel.doc   |Documentation for the instrument panels.|
	|records.dat |This file holds the current mission records.|
	|records.txt |This file shows the current mission records in a more
                        human friendly form.|
	|lms         |Lunar Mission Simulator executable.|
	|mapgen      |Program for generating maps.|
	|planner     |Program for making mission profiles.|
	|template.txt|Template for helping with panel designs.|
	|lunarref.txt|Lunar feature reference.|
	|userref.txt |File containing objects left on the moon.|
[TE]
[I-4]
[=]
[H2]	Keys:
[=]
[H1]	Available in all modes:
[I4]
[TB]
	|!     |-|Normal time|
	|@     |-|10x time|
	|#     |-|100x time|
	|$     |-|1000x time|
	|Q     |-|Quit.  Current simulation will be saved in lms.sav|
	|1     |-|Select POS^ABS mode for the INS|
	|2     |-|Select POS^TAR mode for the INS|
	|3     |-|Select POS^REL mode for the INS|
	|4     |-|Select ORB^ABS mode for the INS|
[TE]
[I-4]
[=]
[H1]	Throttle commands, available in LM, EVA, or LRV:
[I4]
[TB]
	|<PGDN>  |-|Increase throttle 2%|
	|<END>   |-|Decrease throttle 2%|
	|<F1>    |-|Set throttle to 10%|
	|<F2>    |-|Set throttle to 20%|
	|<F3>    |-|Set throttle to 30%|
	|<F4>    |-|Set throttle to 40%|
	|<F5>    |-|Set throttle to 50%|
	|<F6>    |-|Set throttle to 60%|
	|<F7>    |-|Set throttle to 70%|
	|<F8>    |-|Set throttle to 80%|
	|<F9>    |-|Set throttle to 90%|
	|<F10>   |-|Set throttle to 100%|
	|0       |-|Set throttle to 0%|
	|<INSERT>|-|Set throttle to 0%|
[TE]
[I-4]
[=]
[H1]	Available while in CSM:
[I4]
[TB]
	|M     |-|Move to and check out LM|
[TE]
[I-4]
[=]
[H1]	Available while in LM:
[I4]
[TB]
	|M      |-|Move to CSM if docked.  This will end the simulation|
	|U      |-|Undock if docked|
	|<      |-|Turn on/off the landing radar|
	|>      |-|Turn on/off the docking radar|
	|?      |-|Turn on/off the dsn transponder|
	|=      |-|Increase rcs translation thrust (1->10->100)|
	|-      |-|Decrease rcs trnaslation thrust (100->10->1)|
	|+      |-|Increase rcs rotation thrust (10->50->100)|
	|_      |-|Decrease rcs rotation thrust (100->50->10)|
	|f      |-|Toggle face RCS thruster|
	|b      |-|Toggle back RCS thruster|
	|l      |-|Toggle left RCS thruster|
	|r      |-|Toggle right RCS thruster|
	|u      |-|Toggle up RCS thruster|
	|d      |-|Toggle down RCS thruster|
	|<SPACE>|-|Turn off all RCS translation thrusters|
	|I      |-|Ignite main engine|
	|i      |-|Shutdown main engine|
	|<HOME> |-|Roll counter clockwise around up|
	|<PgUp> |-|Roll clockwise around up|
	|<up>   |-|Pitch counter clockwise around left|
	|<down> |-|Pitch clockwise around left|
	|<left> |-|Yaw counter clockwise around front|
	|<right>|-|Yaw clockwise around front|
	|S      |-|Put on/take off space suit|
	|P      |-|Put on/take off PLSS|
	|C      |-|Evacuate/Pressurize cabin|
	|*      |-|Rest for 2 hours|
	|)      |-|Sleep for 8 hours|
	|]      |-|Increment mode of multi-axis display|
	|[      |-|Decrement mode of multi-axis display|
	|.      |-|Increment mode of precision axis display|
	|,      |-|Decrement mode of precision axis display|
	|p      |-|Request entry of Prog parameter on guidance computer |
	|v      |-|Request entry of Verb parameter on guidance computer |
	|n      |-|Request entry of Noun parameter on guidance computer |
	|g      |-|Start program execution on guidance computer         |
[TE]
[I-4]
[=]
[H1]	Available while in EVA:
[I4]
[TB]
	|M       |-|Move into LRV|
	|m       |-|Move into LM|
	|B       |-|Drop rock, Get box from LRV, put box in LM|
	|V       |-|Setup LRV|
	|F       |-|Get flag from LM, plant flag|
	|f       |-|Put flag back into LM|
	|<left>  |-|Begin left turn/End right turn|
	|<right> |-|Begin right turn/End left turn|
	|<PgDn>  |-|Throttle up 10%|
	|<End>   |-|Throttle down 10%|
	|C       |-|Collect sample|
	|S       |-|Store sample in lrv box or Box into LM|
	|D       |-|Drop sample|
	|E       |-|End EVA|
	|R       |-|Return sample box to rover|
	|B       |-|Get sample Box from rover|
	|L       |-|Get laser reflector from LM, setup laser reflector|
	|l       |-|Put laser reflector back into LM|
[TE]
[I-4]
[=]
[H1]	Available while in LRV:
[I4]
[TB]
	|M      |-|Exit LRV|
	|<left> |-|Begin left turn/End right turn|
	|<right>|-|Begin right turn/End left turn|
	|<PgDn> |-|Throttle up 10%|
	|<End>  |-|Throttle down 10%|
[TE]
[I-4]
[=]
[H2]	Typical Mission Profile
[H1]	Undocking and separation maneuvers
	1. Set the guidance computer to P00 V00 N02, or POS^TAR on the INS
	display.  When the CSM is 60 degrees west of the landing site,
	transfer to the Lunar Module.
[=]
	2. After transfer and check out of the LM, wait until the GC or
	INS indicates that you are 155 degrees east of the landing site and
	then undock.
[=]
	3. Set the RCS Translation throttle to low.  Set the GC to P00 V00 N03,
	or the INS to POS^REL.  Be sure the Docking Radar is selected so that
	you are receiving a high resolution signal from the CSM.
[=]
	4. When the LM is 50 meters north of the CSM, activate the Down RCS
	thruster and leave it on until your North separation velocity is 0.3.
	When your separation velocity is 0.3, turn off the RCS thruster.
[=]
	5. Set the GC to P00 V00 N02, or the INS to POS^TAR and set the RCS
	translation throttle to medium.  At 105 degrees east of the landing
	site you want to activate your Forward RCS thruster and increase
	your altitude velocity by 1.0.  In preparation for this maneuver, at
	about 115 degrees east of the landing site roll the LM so that the
	F axis is pointing up, Once it is pointing up, periodically check
	the axis indicator and keep the F axis pointed up until this 
	maneuver is completed.
[=]
[H1]	Plane change maneuvers
	The next phase of the mission is to place the LM into an orbit
	that passes over the landing site.  The CSM was in an orbit over
	the equator of the moon.  Open completion of the separation 
	maneuvers the LM will still be in a a near equitoral oribt.  Two
	plane change maneuvers will be needed in order to change the orbit
	of the LM.
[=]
	6. Be sure the GC is set to P00 V00 N02, or the INS is set to
	POS^TAR.  When the LM is 3 degrees east of the landing site use
	the Up or Down RCS thruster to cancel your relative north/south
	velocity.  If the velocity is showing negative then you will need
	to use the Down thruster to cancel it.  If the north velocity is
	positive then you will need to use the Up thruster to cancel it.
[=]
	At the completion of this maneuver the LM will still be in a near
	equitoral orbit, but the ascending node of the orbit will now be
	near the ascending node of the orbital plane the landing site is on.
[=]
	7. The last maneuver aligned the phase of our orbit with the orbital
	plane of the landing site, now we need to match the inclination of
	the landing site.  Set the GC to P00 V00 N02, or the INS to POS^TAR.
	At about 77 degrees west of the landing site you need to align the Up
	face of the LM to point towards the hemisphere that does not contain
	the landing site.  For example, if the landing site is at +3 degrees
	then the Up face needs to point south.  If the landing site is at -3
	degrees then the Up face needs to point north.
[=]
	8. Roll the LM so that the F face is facing upwards.  If the landing
	site is in the northern hemisphere then the Left face should be
	facing west, which is the orbit prograde, if the landing site is in
	the southern hemisphere then the Left face will be towards the east,
	which is the orbit retrograde.  During this next maneuver is is
	important that you keep the L face facing either prograde, for northern
	landing sites, or retrograde, for southern landing sites.  If you
	are using the advanced instrument panel, then set the precision axis
	display to the prograde mode.  You will want to keep both of the numbers
	associtated with the L line as close to zero as possible throughout
	the plane change maneuver.
[=]
	9. At 87 degrees west of the landing site Ignite the Descent engine
	to start the plane change maneuver.  If you only have a degree or two
	to change, you can use a lower throttle setting, the higher the 
	latitude you are trying to reach, the higher engine throttle you will
	need.  You want to complete the maneuver about the time you are on
	the same longitude as the landing site.  If you are using the GC, you
	should already be in the P00 V00 N02 mode, Register 12 contains the 
	relative angle in degrees, when this value reaches zero, cut the
	engine.  If you are using the INS then you will need to set the INS
	to ORB^TAR mode for the north MOM value to update, again you want
	this value to be zero.
[=]
	During this maneuver you need to yaw the LM to keep the L face facing
	along the orbital path.  This is easiest to accomplish when using the
	advanced panel, as described in step 8.  If you are using the AMS
	panel then this becomes a little bit tricker, for every degree that
	the North MOM value goes down you need to yaw the LM so that the L/S
	changes by the same amount.  For example, if you need to change 2 degrees
	at the start of the manuever the L/S will be 90, the distance to go
	shown in MOM North will be 2.  When the MOM North is at 1, then the 
	L/S whould be showing 91.  When the MOM North is showing 0, then the
	L/S should be showing 92.  Note this example is if the landing site
	is in the northern hemisphere, if it is in the southern then you need
	to yaw the other way, so instead of 91 you should be at 89 and
	instead of 92 you should be at 88.
[=]

[H2]	Key points during landing
[I4]
[TB]
	|  |Pos   |Relative to | Action                                      |
        |  |------|------------|-------                                      |
	|1.|60.0W |landing site| transfer to LM                              |
	|2.|155.0E|landing site| undock                                      |
	|3.|50m   |CSM         | increase north velocity to .3               |
	|5.|105E  |landing site| increase altitude velocity by 1.0           |
	|6.|3E    |landing site| cancel relative N/S veloicty                |
	|7.|87W   |landing site| plane change to match landing site latitude |
	|8.|165W  |landing site| change perilune to 20km (10% throttle)      |
	|9.|16E   |landing site| powered descent                             |
[TE]
[I-4]
[=]


