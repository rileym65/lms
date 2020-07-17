[c]	Lateral Movement
[=]
	In this flight we will explore lateral movement of the LM and how
	the docking radar reflects our lateral position.  This tutorial
	assumes that you are starting at station-keeping 100 meters away
	from the CSM and on the approach vector.  Refer to the last 
	tutorial if you need help getting to this starting location.
[=]
	For a good portion of this tutorial we are not going to worry too
	much about exect positioning so we will be using the translation
	throttle at medium.  Use the <=> or <-> keys as needed to set the
	translation throttle to medium (TTH:--).  Although for this tutorial
	you should maintain your Z distance (register 12) between 100.0 and
	105.0 meters.
[=]
[er]
	+-----------------------------+
	|   0.0344   -1.9536   100.889|
	|  -0.0006   -0.2055   -0.0047|
	+-----------------------------+
[ee]
	Lets start by moving to the left.  Press the <l> key to activate
	the left thruster.  Keep an eye on register 14 and when it shows
	a velocity of about -0.2 press the <l> key again to shutdown the
	left thruster.
[e-]
[=]
[er]
	+-------------+
	|    dock     |
	| +---f|----+ |
	| -    v    - |
	| |         |r|
	|--    X  + --|
	|l|         | |
	| <    ^    | |
	| +----|b---+ |
	+-------------+
[ee]
	Now take a look at the radar display, you should see a '+' symbol
	moving to the right side of the display.  The '+' represents the
	lateral alignment to the docking port.  Since we are moving to the
	left, the docking port is now to our right.
[=]
	Also notice on the lower left corner of the radar frame there is 
	a '<' symbol.  This is telling us that we are moving leftwards
	at a velocity that is too high for docking.  Since we are not
	trying to dock right now, it does not matter.  During a docking
	approach tho, seeing this symbol would indicate that you are
	moving laterally too fast to dock.
[e-]
[=]
[er]
	+-----------------------------+
	|  -0.0822  -25.8453   100.879|
	|  -0.0021    0.0041   -0.0051|
	+-----------------------------+
[ee]
	When register 11 shows that you are about 25 meters left of the
	docking port, press the <r> key to activate the right thruster and
	bring your velocity in register 14 back down to 0.
[e-]
[=]
[er]
	+-----------------------------+
	|   2.0317  -25.7518   100.742|
	|   0.2034    0.0048   -0.0080|
	+-----------------------------+
[ee]
	Now press the <f> key to activate your forward thruster.  Keep an
	eye on register 13 and then press <f> again to turn off the forward
	thruster when your velocity gets to 0.2.
[e-]
[=]
[er]
	+-------------+
	|    dock     |
	| +---f|---^+ |
	| -    v    - |
	| |         |r|
	|--    X    --|
	|l|         | |
	| |    ^   +| |
	| +----|b---+ |
	+-------------+
[ee]
	Now lets take another look at the docking radar.  Since the forward
	thruster moves us upwards in relation to the docking port we now see
	that the '+' symbol has moved down the radar display, indicating
	that the docking port is now below us.  So just like the 'X' symbol
	indicated where the docking port was in relation to the way we
	were pointing, the '+' symbol shows where the docking port is in
	relation to where the spacecraft is.  currently below and to the
	right of us.
[=]
	Also notice on the upper right frame there is a '^' symbol.  This
	like the '<' we saw while moving to the left, indicates that we are
	moving too quickly upwards.  Again since we are not trying to dock
	right now that indicator is irrelevant, but I wanted to point it
	out as another example of how the docking radar shows you when
	you have a lateral velocity that is too high to allow docking.
[e-]
[=]
[er]
	+-----------------------------+
	|  25.4067  -25.0443   100.088|
	|  -0.0068   -0.0002    0.0014|
	+-----------------------------+
[ee]
	When register 10 shows you approaching 25 meters above the CSM,
	press the <b> key to activate the back thruster and leave it on
	until register 13 shows your velocity at near zero, when it gets
	there, press the <b> key again to stop the back thruster.
[=]
	Do not worry about exact distances, but at this point your should
	be about 25 meters above the CSM, 25 meters to the left of it, and
	100 meters north of it.
[e-]
[=]
	Although we are closer to the CSM than a typical rendevous would
	leave you, this will give you an idea of what you need to do to
	setup of for a docking approach when you are not on the approach
	vector.
[=]
[er]
	+-----------------------------+
	|  21.9966  -21.8905  100.5938|
	|  -0.2141    0.2071   -0.0024|
	+-----------------------------+
[ee]
	Since we are above and to the left of the CSM, we will need to
	thrust down (back) and right to get back to it.  So press the
	<b> key to activate the back thruster and the <r> key to activate
	the right thruster.
[=]
	Geep an eye on registers 13 and 14.  When 13 gets to about -0.2
	press the <b> key to stop the back thruster.  When register 14
	gets to about +0.2, press the <r> key to stop the right thruster.
[=]
	Now just keep an eye registers 10 and 11.  Also keep an eye on 
	register 12, remember you need to be keeping your distance between
	100 and 105 meters for this flight, do not forget about that!
[e-]
[=]
[er]
	+-----------------------------+
	|   0.2080   -0.0209  100.6511|
	|  -0.0085   -0.0028    0.0087|
	+-----------------------------+
[ee]
	When registers 10 and 11 show you getting back into that range of
	-0.5 to +0.5, you will need to slow your velocities.  When register
	10 is in range, press the <f> key to activate the forward thruster
	to start slowing down, when register 13 shows you velocity near
	zero press the <f> key again to stop the forward thruster.  When
	register 11 is in range, then press the <l> key to activate the left
	thruster to slow down, when register 14 nears zero, press the <l>
	key again to stop the left thruster.
[=]
	When you have slowed your velocities, press the <-> key to set
	your translation throttle to low (TTH:vv) and then you can fine
	tune your velocities.  If both registers 10 and 11 show you in the
	range of -0.5 to +0.5 then you are on the approach vector and now
	it is just a matter of station keeping like you learned in the last
	tutorial.  If you are still out of range, then just add a little
	thrust in the direction you need to go, look at the radar display
	to see where the '+' is, remember, you always need to move towards
	the '+'.  Also remember that when the signs of your position and
	velocity are opposite, you will be moving your position towards
	zero.
[e-]
[=]
	That concludes this tutorial.  If you want to practice approach
	and docking, you can certainly do that at this point as outlined
	in the last tutorial.  Or, the next tutorial will also be starting
	from this position, so you could stay here and go on to the next
	tutorial.
[=]
