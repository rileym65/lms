[c]	First Flight in the LM
[=]
	In this tutorial we are going to take our first flight in the LM.
	For this flight we will undock, move out to about 100 meters away
	and station keep there and explore the effects of rotation on the
	docking radar display, and then approach and dock with the CM.
[=]
	This tutorial assumes that you are in orbit and currently located
	in the LM.  If you are still in the CSM, then press <shift><m>
	to move over to the LM
[=]
[er]
	+------+
	|  LAN |
	| @DOK |
	|  DSN |
	+------+
[ee]
	Start by pressing <shift><.> to select the docking radar as the
	source for positional data.  Without being in this mode the 
	docking radar display will not show anything and the guidance
	computer will not receive position data related to the CM
	docking port.
[e-]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 63  |
	|   0.0732    0.1834    5.2713|
	|   0.0000    0.0000    0.0000|
	|   0.6740    0.0000    0.0000|
	|          IDL                |
	|   0.0000    0.0000    0.0000|
	|   0.0000    0.0000    0.0000|
	+-----------------------------+
[ee]
	Next we want to set the guidance computer to show us data that
	is relevant to rendevous/docking.  Do this by entering the
	following keystrokes: <v><1><6> <n><6><3> <enter>.  I am going
	to go over this mode now in detail.
[=]
	Like most other modes, registers 1 through 9 give position,
	velocity, and acceleration.  The difference tho is in the 
	coordinate system that this mode uses.  Most modes register 1
	is the altitude, register 2 is the longitude, and register 3
	is the latitude.  In this mode the coordinate system is no 
	longer centered on the body being orbited, but instead uses an
	absolute coordinate system centered on the command module.
	Register 1 now has the X offset in meters, register 2 has the Y
	offset in meters, and register 3 has the Z offset in meters.
	Registers 4 through 6 show the velocities in each of these 3
	dimensions and registers 7 through 9 show the accelerations in
	each of these 3 dimensions. 
[=]
	If you are oriented in the reference orientation I recommeneded
	then your guidance computer display should be very similar to the
	one I show here.  The X and Y offsets should be pretty small and
	the Z offset around 5.25 meters.  The reason the Z offset is 
	larger is because registers 1 through 3 are showing the offset
	between the center of the CM and the center of the ascent stage
	of the LM, which is about 5.25 meters apart
[=]
	The upper nine registers are mainly used during rendevous and not
	used during docking, so for now you can ignore the top 9
	registers for the rest of this flight.
[=]
	The bottom six registers, registers 10 through 15 are also
	position and velocity values.  The difference between these 
	registers and registers 1 through 6 is that these bottome registers
	show position and velocity information relative to the docking
	port on the command module.  The values shown are the distances
	between the docking port of the LM and the docking port of the CM,
	as such, while docked they are all going to be 0.
[=]
	The other main difference with these bottom six registers is that
	the coordinate system they use is based upon the angle of the CM
	docking port.  It does not matter where the CM docking port is 
	pointing, these registers will always show your relative positions
	to the port angled in the same direction as the docking port.
	The way to visualize this, if you are in the reference orientation
	then the docking port is facing north.  If you are in the LM
	alligned with the docking port, but 100 meters away, register 3
	will show you +100 meters away, and register 12 will also show
	+100 meters away.  Now if you were to reverse the CM orientation
	so that the docking port is facing south, again you are aligned
	with the docking port 100 meters south of it, register 3 will show
	you -100 meters, because you are 100 meters south of the CM, but
	register 12 is still going to show you at +100 meters, because
	even tho you are 100 meters south of the docking port, relatively
	speaking in relation to the docking port, you are still 100 meters
	away from it in the direction it is facing.
[e-]
[=]
	Next thing to talk about is the docking approach vector.  This is
	a line that starts at the center of the docking port and extends
	out into space in the direction the docking port is facing.  This
	approach vector is the line you want the LM on during approach and
	docking.  Successful docking requires the LM to be within 0.5 meters
	of the center of the docking port, therefore you never want to be
	more then 0.5 meters from the docking approach vector.  Now this is
	where registers 10 and 11 come in.  Register 10 is how far forward
	or backward (in other words the local X coordinate) you are from
	the approach vector.  Register 11 is how far left or right you are
	from the approach vector, so by keeping registers 10 and 11 between
	-0.5 and +0.5 you will be on an approach that can dock successfully.
	If register 10 or register 11 is outside of this range then docking
	cannot be done.
[=]
	Now with that being said, one task that you must perform throughout
	this entire tutorial is to keep the LM on the approach vector, so
	registers 10 and 11 need to stay between -0.5 and +0.5 meters.
	After undocking you will notice that the LM will drift off of this
	line, this is normal and you will need to correct for it.  you only
	need to keep the numbers in range, so you will not need constant
	attention to this, just make adjustments when the numbers are getting
	close to the edge.  In general, if the position and the velocity
	have opposite signs then you will be getting closer to zero, and when
	the signs are the same you are getting further from zero, so the
	easy thing to remember is to keep the velocity and the position at
	opposite signs, but only worry about it when you are getting close
	to the edge, otherwise you will be constantly making changes.
[=]
	If register 10 is getting close to -0.5, then use the <f>orward
	thruster to change your velocity in register 13 to be positive,
	and if register 10 is getting close to +0.5, then use the <b>ack
	thruster to change your velocity in register 13 to be negative.
[=]
	If register 11 is getting close to -0.5, then use the <r>ight
	thruster to change your velocity in register 14 to be positive,
	and if register 11 is getting close to +0.5, then use the <l>eft
	thruster to change your velocity in register 14 to be negative.
[=]
	When making these approach vector adjustments, always use the
	thrusters at the minimum throttle setting (TTH:vv).  And remember,
	you need to keep your eyes on this through the entire flight in
	this tutorial.
[=]
[er]
	+-----------------------------+
	|  -0.0090   -0.0136    5.7907|
	|  -0.0004   -0.0005    0.0996|
	+-----------------------------+
[ee]
	Now lets go ahead and press <shift><u> to undock.  From this
	point forward in this tutorial when I show the guidance computer
	I am only going to show the bottom six registers, as these are the
	only relevant registers for this flight.  We want to watch the
	value in register 12, which is our distance from the docking port,
	we will want to make a small change when our distance gets to 30
	meters.  Notice also that registers 10 and 11 are showing that
	drift I was mentioning, so keep an eye on those two and remember
	to keep them inside the tolerance band of -0.5 to +0.5.
[e-]
[=]
[er]
	+-----------------------------+
	|  -0.3501   -0.4129   30.0096|
	|   0.0009    0.0010    0.0959|
	+-----------------------------+
[ee]
	When register 12 shows that you are 30 meters away, press the <d>
	key to activate the down thruster, we want to increase our
	separation velocity (register 15) to 0.3 m/s.  Be sure your 
	translation thruster is at minimum (TTH:vv) before doing this.
	When register 15 shows your velocity at 0.3 press <d> again to
	stop the down thruster.
[=]
	By this point I had to make my first correction to my approach
	vector distances.  Notice how now my position (regs 10 and 11)
	now have opposite signs than my velocity (regs 13 and 14).
[e-]
[=]
[er]
	+-----------------------------+
	|  -0.0222   -0.1421   100.431|
	|   0.0028    0.0003   -0.0004|
	+-----------------------------+
[ee]
	When register 12 shows you about 95 meters away it is time to slow
	down so that we can come to a stop at around 100 meters.  We will
	want to perform this maneuver with the translation throttle at
	medium (TTH:--).  Since we do not want to make approach vector
	adjustments at this throttle setting, make sure your drift adjustments
	are good for a little while, before this slowing down maneuver.
[=]
	To slow down make sure your thranslation throttle is at medium
	(TTH:--) and then press the <u> key to activate the up thruster,
	keep an eye on register 15 and then press the <u> key again to
	stop the thruster when register 15 approaches 0.0.
[=]
	If all went well you should be between 100 and 105 meters away.
	Switch the translation throttle back to low (TTH:vv).  Check
	registers 10 and 11 for drift and make sure to make any corrections
	you need.  If you are less than 100 meters away, then use the <d>own
	thruster to change your velocity in register 15 to be positive, if
	it is already positive then just leave it be and you will get to the
	100 meters we are looking for.  If you are further than 105 meters,
	then use the <u>p thruster to set your velocity in register 15 to
	be negative.
[=]
	From now until we make our docking approach, add register 12 to
	your drift adjustment maneuvers.  For the next few minutes just
	work to keeping regs 10 and 11 within 0.5 meters of center and 
	keeping register 12 between 100 and 105 meters.  When you are
	comfortable with this station keeping, we will go on to the next
	portion of this flight.
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
	While we are out here station-keeping, lets take a look at the
	docking radar display.  This display gives 3 basic types of
	information: 1. our orientation to the docking port, 2. our
	lateral alignment with the docking port, and 3. our relative
	velocity to the docking port.  The sample I show here is the
	display you want to see, this shows that I am correctly oriented
	and laterally positioned for docking.
[=]
	Lets start with orientation.  The 'v' and '^' that are at the
	top and bottom of the display indicate our roll angle, when these
	arrows are centered on the display then the spacecraft is rolled
	correctly for docking, if these arrows are off-center then the
	spacecraft is not properly rolled in position and will not be able
	to dock.
[=]
	The pitch and yaw angles are shown by an 'X' symbol that can appear
	on this display.  If you see an '*' symbol, that is where the 'X'
	actually is.  There is also a '+' symbol that can appear that is
	used for lateral alighment, when both the '+' and 'X' share the 
	same spot on the display you get the '*' symbol.  When the 'X'
	or '*' symbol is in the center of the display then the pitch and
	yaw angles of the spacecraft are correct for docking, if the 'X'
	or '*' symbol is off-center then docking is not possible.
[=]
	The X and Y lateral alignment is shown with a '+' symbol on this
	display.  As discussed above, you could have a '*' symbol instead
	of a '+', if so then the '+' is in the same space as the '*'.
	when the '+' or '*' symbol is centered then you are laterally aligned
	with the docking port and docking is possible, othewise you are too
	far off-center from the docking port to be able to dock.
[=]
	On the left and right edges of the display, you could have '-'
	symbols (as in the sample) or '+' symbols.  If a '-' symbol
	appears in this area that means your closing velocity is either
	too low for the docking latches to connect, or your are moving
	away from the docking port.  If a '+' symbol appears here then 
	you are moving towards the docking port, but at too high a velocity
	for docking to be successful.  Closing velocity must be between
	-0.2 and -0.4 for docking to succeed.
[=]
	You can also see arrow symbols '^','v','>','<' around the edges
	of the display.  If these symbols appear then your lateral
	velocity in that direction is too high.  For a docking to be
	successful you cannot have too high a lateral velocity.
[e-]
[=]
[er]
	+-------------+
	|    dock     |
	| +---f|----+ |
	| -    v    - |
	| |         |r|
	|--    +  X --|
	|l|         | |
	| |    ^    | |
	| +----|b---+ |
	+-------------+
[ee]
	For the next few maneuvers we will be changing the orientation
	of the spacecraft.  You do not want to make approach vector
	adjustments when no longer oriented correctly to the docking
	port, so if you are approaching any edges, clean them up before
	doing the maneuvers that have you oriented away from the docking
	port.
[=]
	For the first maneuver, lets yaw left by pressing <keypad><4> once.
	you will see the radar display change, an X starts moving towards
	the right edge.  When the X gets to the edge press the <keypad><6>
	key to stop the yaw motion.  That X remember represents the angle
	orientation to the docking port, we yawed left and so the docking
	port is now to our right, as indicated by the radar display.
[=]
	So to orient ourselves to the docking port again, you need to yaw
	in the direction of the X, or to the right, so press <keypad><6>
	to start a right yaw.  You will see the X move back to the center.
	When it joins the '+' already in the center it will change back to
	the '*' symbol, when this happens press <keypad><4> to stop the
	right yaw.
[e-]
[=]
[er]
	+-------------+
	|    dock     |
	| +---f|----+ |
	| -    X    - |
	| |         |r|
	|--    +    --|
	|l|         | |
	| |    ^    | |
	| +----|b---+ |
	+-------------+
[ee]
	After returning to center, check on your approach vector alignment
	and make sure you are not approaching any edges.  Now lets pitch
	down by pressing <keypad><8>.  Watch the radar display and now you
	will see the X move to the top of the radar display.  When it
	reaches the edge, press <keypad><2> to stop the pitch down movement.
	Since we pitched down, the docking port is now above us, as shown
	in the radar display.  In order to center the X again we must move
	towards it, or pitch up, so press <keypad><2> to being a pitch up
	movement, watch the X move back to center, when it gets there press
	<keypad><8> to stop the pitch up movement.
[=]
	From these last two maneuvers you can see that the center of the
	radar display indicates where the spacecraft itself is pointing and
	the X represents where the docking port is in relation to where the
	spacecraft is pointing.  So in order to setup the pitch and yaw
	orientation, all you have to do is move towards the X and stop all
	movement once it is centered.
[e-]
[=]
[er]
	+-------------+
	|    dock     |
	| +---f|----+ |
	| -v        - |
	| |         |r|
	|--    *    --|
	|l|         | |
	| |^        | |
	| +----|b---+ |
	+-------------+
[ee]
	After returning to center, again check on your approach vector
	alignment and make any changes necessary.  Now that we have seen
	the effects of picth and yaw on the radar display, the last one
	to look at is roll.  Press the <keypad><9> key to start a right
	a right roll.  You will now see the roll arrows move towards the
	left side of the radar display.  Press <keypad><7> when they
	reach the left edge.
[=]
	Just like the X for the pitch and yaw orientation, the roll arrows
	tell you which way to go in order be oriented correctly, since they
	are to the left of the radar display, we need to roll left to move
	them back to center, so press <keypad><7> to begin a left roll.
	When the roll arrows are once again in the center press <keypad><9>
	to stop the left roll.
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
	That is enough maneuvers for this flight, except for docking with
	the CSM.  Before executing your docking approach, first verify that
	your docking radar looks like this one, this indicates that your
	spacecraft is properly oriented and that you are on the approach
	vector.  Hopefully you have been keeping registers 10 and 11 between
	-0.5 and +0.5, if not, first get those back into alignment.
[=]
	To start our approach, press <=> to set the translation thrusters
	to medium (TTH:--) and then press the <u> key to activate the up
	thruster.  Watch register 15, when it shows -0.3, press the <u>
	key again to stop the up thruster.  Then set your translation throttle
	back to low by pressing <->.
[=]
	Now all you have to do is stay within the approach corridor.  Keep
	registers 10 and 11 between -0.5 and +0.5.  Keep an eye on register
	12, which shows your distance to remaining.  When this gets to zero
	the docking process with begin, assuming you approached at the correct
	speed and were withing the approach corridor.
[e-]
[=]
	Congratulations, you have completed your first excursion in the LM.
	In the next tutorial we will go over achieving lateral alignment
	with the docking corridor and in the final tutorial on flying the
	LM we will fly away from the LM and learn how to rendevous from a
	distance.
[=]

