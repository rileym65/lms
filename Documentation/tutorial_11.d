[c]	Liftoff and Rendevous
[=]
	You have had a successful landing, explored the Lunar surface and
	are now ready to go home.  This tutorial will teach you how to
	liftoff from the Lunar surface and redenvous and dock with the
	orbiting CSM.  This tutorial assumes that you performed an 
	in-plane landing and therefore a plane change maneuver will not
	be required.  If you had performed an out-of-plane landing then
	you will need a different tutorial.
[=]
	Some steps in this tutorial need to be done in fairly quick
	succession, so be sure to read through the entire tutorial before
	beginning the flight since there is no pause feature in the
	simulator to allow you to read the next step.  If you really
	need to pause to read the next step then just <q>uit out of the
	emulator, the state will be saved and when you reload the
	simulator it will be just as you left it.
[=]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 53  |
	| -99791.0   19.7058    0.7306|
	+-----------------------------+
[ee]
	1. In order to rendevous with the orbiting CSM it is important
	to launch at the correct time.  To do this we need to know where
	the CSM is in relation to us.  Execute V16N53 so the guidance
        computer will show the CSM position relative to us.  The number
	we are interested in is in register 2, the middle number of the
	top line below the PVN line.
[=]
	You should also prepare the LM for flight by setting the 
	translation throttle to high and the rotation throttle to
	medium.  Also press <shift></> to set the gudiance computer
	to accept data form the DSN radar.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 53  |
	| -99791.0  -10.0000    0.2146|
	+-----------------------------+
[ee]
	2. We need to launch when the CSM is 5 degrees east of us, or
	when the number in register 2 is -5.000.  When register 2 shows
	-10.000 then press the <tab> key to arm the ascent engine.  Also
	press <shift><?> to select the DSN radar.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 53  |
	| -99791.0   -5.0000    0.0746|
	+-----------------------------+
[ee]
	3. When register 2 shows -5.0 (or less) press <shift><l> to
	launch.  Immediately after launching execute N71 so that you
	can see all the information you need to launch.  Here is what
	each register of what V16N71 shows:
[=]
[lb]
[li]	reg 1 - Altitude in meters
[li]	reg 2 - Lunar longitude
[li]	reg 3 - Lunar latitude
[li]	reg 4 - Rate of Climb (Important!)
[li]	reg 5 - Longitudinal velocity in m/s
[li]	reg 6 - Latitudinal velocity in m/s
[li]	reg 7 - Rate of Climb acceleration (Important!)
[li]	reg 8 - Longitudinal acceleration
[li]	reg 9 - Latitudinal acceleration
[li]	reg 10 - Seconds remaining before running out of fuel
[li]	reg 11 - Kg of fuel burned in the last second
[li]	reg 12 - Kg of fuel remaining
[li]	reg 13 - Periapsis in km
[li]	reg 14 - Apoapsis in km (Important!)
[li]	reg 15 - Orbit time in seconds
[le]
[e-]
[=]
[=]
[er]
	+------------+
	|    P 00    |
	|   1016.93  |
	|   38.4564  |
	|   -0.0156  |
	+------------+
[ee]
	4.  When rate of climb (register 4) hits ten then press the
	up arrow quickly 4 times to begin a 2 degree per second pitch
	forward maneuver.  Keep an eye on the rate of climb and the
	roc acceleration (register 7).  You want to establish and
	maintain a rate of climb between 38m/s and 40m/s.  Once you
	have established this rate of climb, adjust your pitch using
	the up and down arrows to keep your rate of climb in this
	range.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 71  |
	|  16368.8   94.9477   12.5317|
	|  38.6940  -1562.56  -31.0824|
	|  -0.2003    0.0425   -0.3456|
	|          IDL                |
	|  61.0936    5.0000   305.468|
	| -377.972   20.0860   5524.94|
	+-----------------------------+
[ee]
	5. Keep an eye on register 14 during your ascent.  You are 
	shooting to get a periapsis right around 20km.  When register
	14 shows your periapsis at round 20km hit the <i> key to shut
	down the engine.  If you are a little off then just use the
	up/down translation thrusters to adjust the periapsis.  Anywhere
	between 20.0 km and 20.5km will be fine.  If you are also 
	keeping an eye on the burn clock (BU), apoapsis hitting 20km
	should occur at around 7:20.
[=]
	At this point our periapsis (register 13) is probably negative,
	which means we have not achieved orbit yet and will impact the
	moon without changing this situation.
[e-]
[=]
[=]
[er]
	+-------------------------+
	|   u/r: 87.5 u/o:  1.2   |
	|   f/r:177.5 f/o: 88.8   |
	|   l/s: 12.6 l/o: 90.0   |
	+-------------------------+
[ee]
	6. We are going to need to perform a circuliraztion burn when we
	reach apoapsis.  We can prepare for that now.  Using the 'u/r'
	angle, keep your u/r angle around 86-87 decrees.  When we reach
	apoapsis we will need to fire up the engine again and we want to
	make sure that during that burn we keep a rate of climb of zero.
	By starting this burn with a u/r angle between 86 and 87 we should
	not need to make too drastic an adjustment when we start the
	engine.
	
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 71  |
	|  20092.9   83.5374   12.0045|
	|   0.0588  -1666.16  -111.472|
	|   0.0001    0.0230   -0.3299|
	|          IDL                |
	|  41.3390    5.0000   206.695|
	|  20.0797   20.3833   6616.59|
	+-----------------------------+
[ee]
	7. Now keep an eye on your rate of climb (register 4).  When it
	drops to zero press <shift><i> to ignite the ascent engine.  The
	goal of this burn is to raise your periapsis (register 13) to 20km.
	Keep an eye on your rate of climb and do your best to keep it at
	0m/s.  The roc acceleration (register 7) should help you to see
	how you need to change your pitch angle.  The periapsis will change
	quickly, around 20km a second so you will need to stay on top of
	things.  When the periapsis hits around 20km press <i> to shut
	down the engine.  Use the up/down thrusters to adjust your orbit,
	Ideally you want your periapsis and apoapsis to be between 19.5km
	and 20.5km to make your rendevous easier.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 31      V 16      N 53  |
	| -79678.8    7.9950    1.0356|
	|  207.563  -84.4193   56.7477|
	|   0.0001    0.0251   -0.3262|
	|     RUN                     |
	|  260.376   -2.8107   -0.0396|
	|  20.0791   20.3826  -454.392|
	+-----------------------------+
[ee]
	8. Now we should be in a roughly 20km circular orbit.  The CSM
	is above us in a 100km circular orbit and somewhere in front of
	us.  Since we are in a lower orbit we will be catching up to it.
	We want to fire the engine to begin a hohmann transfer when we
	reach the correct distance from the CSM.  From now until the
	end of the hohmann transfer we want to keep the spacecraft
	oriented prograde, so execute V37N31 to start the prograde
	program.  Next execute V16N53 so that we can keep track of our
	position in relation to the CSM.
[=]
	The main number we are interested in watching is in register
	10, which is our distance to the CSM.  
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 31      V 16      N 53  |
	| -79592.3    5.6130    1.5879|
	|  80.0753  -156.466   18.4056|
	|   0.0352    0.0379   -0.2097|
	|     RUN                     |
	|  198.420   -2.8107   -0.0397|
	|  20.1501   100.045  -227.962|
	+-----------------------------+
[ee]
	9. When register 10 shows us 200.0km from the CSM press <shift>
	<i> to ignite the ascent engine.  Keep an eye on the apoapsis
	(register 14) and press <i> when the apoapsis exceeds 90km.
	This burn will be real short, about 3 seconds in length.
	Then use the up/down thrusters to adjust the apoapsis to 100.0km.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 31      V 16      N 81  |
	|  21968.9   31.6771    4.3642|
	|  11.1878  -1650.71  -344.493|
	|   0.0335    0.0353   -0.1204|
	|     RUN                     |
	|   0.0000   51.0000   38.0000|
	|  20.1466   100.016   6842.77|
	+-----------------------------+
[ee]
	10. Execute V16N81.  This will give us information that is most
	useful for the hohmann transfer we are currently in.  Registers
	1 through 9 are the same as V16N51, of which the most interesting
	to us as this point is register 1, our altitude, and register 4,
	our rate of climb.  Registers 10 through 14 give us the information
	we need to complete the hohmann transfer.  These registers are:
[=]
[lb]
[li]	reg 9 - Hours until apoapsis
[li]	reg 10 - Minutes until apoapsis
[li]	reg 11 - Seconds until apoapsis
[li]	reg 13 - Periapsis in km
[li]	reg 14 - Apoapsis in km
[le]
[=]
	As you can see, we have nearly an hour before we need to make a
	burn to complete the hohmann transfer, so feel free to use time
	compression to get close, just be careful not to exceed the time!
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 31      V 16      N 81  |
	|   100055  -131.327   -7.6602|
	|   0.0140  -1608.19   282.628|
	|   0.0000    0.0336    0.1934|
	|     RUN                     |
	|   0.0000   51.0000   27.0000|
	|  100.052   100.134   7072.40|
	+-----------------------------+
[ee]
	11. Keep an eye on the time to apoapsis (regs 10-12) and when
	down to 3 seconds to go press <shift><i> to engage the ascent
	engine to bring the periapsis up.  When register 13 shows the
	periapsis is above 90km press the <i> key to stop the ascent
	engine, then use the up/down thrusters to adjust the periapsis
	to 100.0km.  At this point the hohmann transfer is complete,
	and hopefully we are not too far away from the CSM.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 31      V 16      N 53  |
	|  146.067   -0.0618   -0.5264|
	|   1.1306    0.9884   -8.8316|
	|  -0.0002    0.0328    0.1848|
	|     RUN                     |
	|  17.0043   -2.8107   -0.0397|
	|   99.658   100.057    0.0682|
	+-----------------------------+
[ee]
	12. Now we need to see where we are in relation to the CSM.
	Execute V16N53 so that the guidance computer shows data
	relative to the CSM.  At this point the most useful number
	for us is the one in register 15, which shows the difference
	between our orbital velocity and that of the CSM.  Using the
	up/down thrusters adjust your orbital velocity so that the
	number in register 15 is as close to 0.000 as you can get it.
[=]
	Although there will still be relative motion to the CSM, by
	minimizing the orbit period difference we will limit how far
	we can end up from the CSM.
[e-]
[=]
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
	|--U         F          --|
	|-|                     | |
	|Z|                     | |
	| |                     | |
	| |                     | |
	| |                     | |
	| +==========|+Y========+ |
	+-------------------------+
[ee]
	13. Now using the <,> and <.> keys, change the visual axis
	display to the absolute mode.  If you had oriented the CSM
	as instructed in the landing tutorial, then orient the LM
	so that the axis display looks like it does here.  If you
	had oriented the CSM differently, then orient the LM to
	the same orientation you had used when undocking.
[=]
	Note, that if guidance computer is still running P31 then
	you will need to press <p> to stop the computer from keeping
	the LM oriented prograde.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 31      V 16      N 63  |
	|  2922.52   300.458  -18205.6|
	|   0.6647    1.0035   -6.2222|
	|  -0.0002    0.0270    0.1392|
	|          IDL                |
	|   9999.9    9999.9    9999.9|
	|   9999.9    9999.9    9999.9|
	+-----------------------------+
[ee]
	14. Now execute V16N63 to set the guidance computer to show
	us information important for rendevous and docking.  Registers
	1 through 3 show our distance from the CSM in meters, Register
	1 shows our distance in the X axis, Register 2 the Y axis and
	Register 3 the Z axis.  Registers 4 through 6 give us our
	relative velocities in each of these dimensions and registers
	7 through 9 gives us our acceleration in each dimension.
[=]
	The 6 lower numbers (all 9999.9 at present) are the position
	and velocity relative to the docking port on the CSM and will
	only show valid numbers when the docking radar is active and
	we are close enough to the CSM.
[=]
	In order to dock you will need to get the X and Y positions to
	0.0 and the Z position to +100.0, this will set you up for the
	docking.  If each position component (top row) has the same
	sign as the corresponding component in the second row then you
	are getting further away in that dimension, if the signs are
	oppostie then you are getting closer.
[=]
	Use the translation thrusters in order to get the postion row
	to 0.0 0.0 and 100.0.  If oriented as in this tutorial then
	thrusters F and B will change the X dimension, L and R will
	change the Y dimension and U and D will change the Z dimension.
[=]
	Be careful about using velocites that are too high, as velocities
	in one direction will affect the others due to orbital mechanics,
	so do things slow and easy to keep your motion under control.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 31      V 16      N 63  |
	|   0.3405    0.2736    99.679|
	|  -0.0029    0.0007    0.0004|
	|  -0.0001   -0.0343   -0.2060|
	|          IDL                |
	|  -0.1381    3.8958   94.4053|
	|  -0.0029    0.0007    0.0004|
	+-----------------------------+
[ee]
	15. After you have arrived at the position for the docking 
	approach, press the <shift><.> key to activate the docking
	radar and the bottom six numbers will now show you the
	information you need for docking.  Registers 10 through 12
	show you the X, Y, and Z offset to the docking port, while
	registers 13 through 15 show you the relative velocities
	to the docking port.
[e-]
[=]
[=]
	Before performing the docking lets take a quick review of
	the docking rader.
[=]
[=]
[er]
	+-------------+
	|    dock     |
	| +---f|----+ |
	| -    v    - |
	| |    X    |r|
	|--+        --|
	|l|         | |
	| |    ^    | |
	| +----|b---+ |
	+-------------+
[ee]
	The docking rader provides position, alignment and velocity
	information critical to docking.
[=]
	The 'v' and '^' on the radar show your roll angle, when these
	markers are centered (as in the sample) then your roll angle
	is correct for docking.  This should be the first item you
	attempt to center.
[=]
	The 'X' shows your yaw and pitch angle in relation to the
	docking port.  If the X is above center then you will need
	to pitch up and if the X is below the center then you will
	need to pitch down.  When the X is to the left then you must
	yaw left and when the X is to the right you must yaw right.
	This should be the second item that you get centered.
[=]
	The '+' symbol shows your lateral position to the docking
	port.  When the symbol is to the left (as in the sample) then
	the docking port is left of the spacecraft and you will need
	to activate the left thruster to move towards it.  The 'r',
	'l', 'f', and 'b' markers around the edge of the radar frame
	are reminders of which thruster you need to fire to move in
	that direction.  This marker should be the final one you center.
[=]
	You could also see a '*' marker, this occurs when both the 'X'
	and '+' markers are at the same location.  When you have a
	'*' in the center of the radar frame then you are both oriented
	and positioned properly for docking.
[=]
	On the left and right edges, near the top, you could see '-' or '+'
	flags (the sample is showing '-').  A '-' flag indicates that you
	are either moving away from the docking port or moving towards it
	too slowly for a successful docking.  When a '+' flag is present
	then you are moving towards the docking port too quickly for a
	successful docking.  If neither of these symbols are present
	then you are moving towards the docking port at a velocity that
	will produce a successful docking.
[=]
	You could also see '<', '>', 'v', and '^' symbols on the frame
	of the radar.  When any of these symbols appear that indicates
	that you are moving too fast in that particular lateral direction
	to dock.  If none of these symbols are present then your lateral
	velocities are good for docking.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 31      V 16      N 63  |
	|   0.3405    0.2736    99.679|
	|  -0.0029    0.0007    0.0004|
	|  -0.0001   -0.0343   -0.2060|
	|          IDL                |
	|  -0.1381    3.8958   94.4053|
	|  -0.0029    0.0007    0.0004|
	+-----------------------------+
[ee]
	Before we continue with the docking, lets take another look at
	the V16N63 mode of the computer, mainly the bottom 6 numbers.
	While registers 1 through 3 give our relative position to the
	CSM, these numbers do not take into account the orientation
	of the CSM or the position of the docking port.
[=]
	Registers 10 through 12 also show position information in the
	X, Y, and Z coordinates. They difer from the ones in registers
	1 through 3 since they are relative to the location of the docking
	port and more importantly are dependent on the orientation of
	the docking port.  If you were to draw a line from the docking
	port out into space in the direction the docking is facing, these
	numbers tell you how for away you are from this line.  When
	registers 10 and 11 have 0.0 in them, then you are perfectly
	aligned laterally from the docking port, and if you are also
	perfectly oriented then thrusting forwards will move you in
	exactly the correct direction to dock.
[e-]
[=]
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
	16. Now that you are in the rough position for docking, we now
	need to fine tune our position.  Using the information from the
	review above, use the roll, pitch, and yaw thrusters to center
	the 'X', 'v' and '^' symbols on the display.  Chances are the '+'
	symbol will not be centered, but if it is, great, in which case
	the 'X' will become '*' when also centered.
[=]
	Once you are correctly oriented then it is time to use the lateral
	thrusters to position us correctly.  Here you are aiming to center
	the '+' symbol on the radar.  You can also use registers 10 and 
	11 on the guidance computer display, in which case you want to
	get these two numbers as close to zero as you can.  When they
	are as close to zero as you can get them, also make sure that
	the numbers in registers 13 and 14 are also as close to zero
	as you can get them.
[e-]
[=]
[=]
	17. Once you are properly aligned and laterally positioned with
	as little lateral motion as you can get, it is time to thrust
	forward.  You want to set your closing velocity (number in
	register 15) to between -0.2 and -0.4 m/s, ideally -3.0 m/s.
[=]
	Once your approach speed is set, then just keep an eye on the
	docking radar and registers 10 and 11 to make sure you are
	not drifing away from the approach line, correct as needed.
	Do your best to keep the signs in registers 10 and 13 opposite
	each other, and the same for registers 11 and 14.  By keeping
	the signs opposite you should always be working on minimizing
	your distance to the approach line.
[=]
	Register 12 shows the distance in meters from the LM docking
	port to the CSM docking port and docking will occur when this
	number hits 0.0, assuming you maintained alignment and lateral
	position at the point of docking and that your lateral motion
	was not too high.
[=]
[=]
	18. Once the docking operation is complete, you can press <shift>
	<m> to move back to the CSM.  Congratulations the 2nd hardest part
	of a Lunar mission is done.
[=]

