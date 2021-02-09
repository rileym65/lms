[c]	Landing a Planned Mission
[=]
	In the last tutorial we went through how to plan a mission to the
	Apollo XII landing site, now we are going to fly that mission.
[=]
	Note:  You should have at least gone through the tutorials on flying
	the LM before performing this tutorial.  It would also be helpful if
	you have gone through the Lunar Landing tutorial as well.  I will be
	going over all the steps of landing in this tutorial, but not in as
	great a depth as the prior landing tutorial.
[=]
	Remove any lms.sav file that you have in your LMS folder and then
	start the simulator.  When you get the starting menu, select option
	'3' to start from a mission profile.
[=]
	You will then be asked for the name of the mission profile to load,
	enter the name of the mission profile and press <ENTER>.
[=]
	You will then find yourself in the CSM orbiting the Moon.  When
	starting in Lunar orbit, the simulation provides a much simpler CSM.
	The CSM display will show a large map of the moon on the left side
	of the screen, and then the clock and guidance computer on the right
	side.
[=]
[er]
	+---------------------------+
	|   altitude    east   north|
	|POS:  99982: 113.12:   3.02|
	|VEL:  -0.00:-1633.12   0.00|
	|ACC:  -0.00:  -0.00:   0.00|
	|MOM: TAR   :-156.59:  93.02|
	|PER:  99.20                |
	|APO:  99.98    OR:   7070  |
	+---------------------------+
[ee]
	1. The guidance computer can operate in 6 different modes, but the only
	mode we really need is the Target mode, press the '2' key to select
	the target relative mode.
[=]
	The target relative mode shows our position relative to the target
	landing site.  The main line of interest will be the one labled as
	POS:, this is our position relative to the landing site.  At the
	start of the simulation we will about about 115 degrees east of the
	landing site.  Also notice that we are 3.02 degrees north of the
	landing site, this tells us that our landing site is in the
	southern hemisphere, and also informs us that we will need to make	
	a plane change maneuver of 3.02 degrees in order to arrive at the
	landing site.
[e-]
[=]
[er]
	+---------------------------+
	|   altitude    east   north|
	|POS:  99281: -60.02:   3.02|
	+---------------------------+
[ee]
	2. Our landing procedure begins when we are 60 degrees west of the
	landing site.  This will take a little time to get there, so go
	ahead and use time compression until you get close.
[=]
	When the guidance computer shows that you are 60 degrees west of the
	landing site, press the <M> key to move over to the LM and power it
	up.  This transfer and power up takes about 45 minutes, so use time
	compression to speed that up.  The simulator will automatically turn
	off the time compression when the move is complete.
[e-]
[=]
	3. Once the move is complete you will find yourself in the LM.  The
	guidance computer is currently in idle, lets set it to show our
	position relative to the landing site, Enter <V><1><6> <N><5><2>.
	You should find yourself somewhere areound 175 degrees east of the
	landing site.
[=]
[er]
	+------+
	|  LAN |
	| @DOK |
	|  DSN |
	+------+
[ee]
	4. Next select the docking radar as the data source by pressing the
	<shift><.> keys.  We will need our position relative to the CSM 
	during separation maneuvers, and will change over to DSN after our
	separation maneuvers are completed.
[e-]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 52  |
	|  99882.9   154.993    3.0179|
	+-----------------------------+
[ee]
	5. When the guidance computer shows that you are about 155 degrees
	east of the landing site it is time to undock, press the <shift><U>
	keys to undock.  Undocking will take about 60 seconds.  While waiting
	for the undocking to complete, change the guidance computer to show
	our position relative to the CSM by doing <V><1><6> <N><6><3>.
[e-]
[=]
	6. After the undocking is complete, you can watch register 12 of the
	guidance computer to see that we are now moving away from the CSM.
	We will make our first separation maneuver when register 12 shows
	that we are 30 meters away.  While waiting til you are the right
	distance away, just verify that your translation throttle (TTH:) is
	set in the low (vv) mode.  I also prefer the rotation throttle (RTH:)
	to be in the medium (--) mode.
[=]
[er]
	+--------+
	| 30.0318|
	|  0.0951|
	+--------+
[ee]
	7. When register 12 shows that you are 30 meters away from the CSM,
	press the <D> key to activate your down RCS thruster.  We want to
	increase our velocity (shown in register 15) to 0.3.
[e-]
[=]
[er]
	+--------+
	| 69.4182|
	|  0.3007|
	+--------+
[ee]
	8. When register 15 shows your velocity is 0.3, press the <d> key
	again to stop your down RCS thruster.  At this point we no longer
	need to know our position relative to the CSM, so lets change the
	guidance computer back to target relative mode, do this with
	<V><1><6> <N><5><2>.
[e-]
[=]
[er]
+-------------------------+
|    LOOKING   PROGRADE   |
| +===outside|==========+ |
| |          F          | |
| |                     |n|
| |                     |o|
| |                     |r|
| |                     |m|
|--          U         l--|
|a|                     | |
|n|                     | |
|o|                     | |
|r|                     | |
|m|                     | |
| +==========|inside====+ |
+-------------------------+
[ee]
	9. The guidance computer should show us about 125 degrees east of the
	landing site.  We need to prepare for the next maneuver, first set
	your axis and precision axis displays to the prograde mode.
[=]
	Next instruct the computer to place us into a retrograde orientation,
	this is done with <V><3><7> <N><3><2>.  After you have instructed the
	computer to orient retrograde, you will need to tell it to show
	target relative data again, so <V><1><6> <N><5><2>.
[=]
	While waiting for the computer to finish the orient retrograde
	maneuver, switch your translation throttle (TTH:) to the medium (--)
	mode.
[=]
	After the orientation to retrograde is complete , the U symbol is
	in the center of the display, use your roll controls to rotate
	the forwared (F) face to be facing the outside of the orbit.
[=]
	At this point you can also switch your data source to the DSN mode.
[e-]
[=]
[er]
	+-----------------------------+
	|  99976.1   105.007    3.0237|
	|  -0.0570  -1633.13    0.2568|
	+-----------------------------+
[ee]
	10. Our next maneuver begins when we are 105 degrees east of the
	landing site.  When you are at 105 degrees east, press the <F>
	key to activate your forward RCS thruster.  You want to change 
	your upward velocity by 1m/s.  In my sample here, My upward velocity
	is -0.0570, so I will need to keep my thruster on until 0.95.
[=]
	Leave your forward thruster on until you have added 1m/s to your
	upward velocity and then press the <F> key to turn off your forward
	thruster.
[e-]
[=]
[er]
	+-------------------------+
	|    LOOKING   PROGRADE   |
	| +===outside|==========+ |
	| |          F          | |
	| |                     |n|
	| |                     |o|
	| |                     |r|
	| |                     |m|
	|--U         L          --|
	|a|                     | |
	|n|                     | |
	|o|                     | |
	|r|                     | |
	|m|                     | |
	| +==========|inside====+ |
	+-------------------------+
[ee]
	11. At this point our separation maneuvers are complete and we can
	now prepare for the plane change maneuvers to come. Start by 
	instructing the guidance computer to orient the spacecraft towards
	the orbit anti-normal, this is done with <V><3><7> <N><3><4>.
	After entering this command, then do <V><1><6> <N><5><2> so that the
	guidance computer again shows our target relative position.
[=]
	When the computer is done orienting the spacecraft, the prograde
	display should appear similar to here.  The F and L faces will
	move as we orbit the Moon, and that is ok, these faces are not
	important to the plane change maneuvers, The U face should stay
	centered on the far left of the display.
[e-]
[=]
[er]
	+-----------------------------+
	|  99467.3    3.0254    3.0255|
	|  -0.2595  -1633.59   -0.2153|
	+-----------------------------+
[ee]
	12. The first plane change maneuver will begin when we are about
	3 degrees east of the landing site.  What we want to do here is to
	zero out any north/south movement.  In my sample here, I am currently
	moving south at -0.2153m/s, therefore I will need to thrust northwards
	to null this out.  With the spacecraft oriented anti-normal, the
	upward face of the spacecraft is facing north, so I will use my up
	RCS thruster to zero out the north/south velocity.  Use whatever
	throttle setting you need to zero this out.  If you are moving
	northwards then you will need to use your down RCS thruster.
[e-]
[=]
[er]
	+-----------------------------+
	|  99460.9    1.8031    3.0254|
	|  -0.2560  -1633.59   -0.0029|
	+-----------------------------+
[ee]
	Once your north/south velocity has been brought close to zero, then
	turn off your RCS thrusters.  This completes the first of the two
	plane change maneuvers needed to reach the landing site.
[e-]
[=]
[er]
	+-----------------------------+
	|  137.746  -179.957   93.0101|
	+-----------------------------+
[ee]
	While we wait for the next plane change maneuver, lets take a look
	at the guidance comptuer so that we can see what we need to 
	accomplish.  Registers 11 and 12 shows our relative angles between
	our current orbit and the oribital plane that the landing site is
	on.  Register 11 shows the angle difference between our current
	longitude of ascending node and that LAN of the target orbit plane.
	In this case we are about 0.05 degrees different, this is close
	enough to intersect the landing site.  Depending on where your 
	landing site is, this number either needs to be as close to zero, or
	as close to 180 (-180 = +180) as possible.  The plane change
	maneuver we did in the last step mostly affects register 11.  If you	
	keep your north/south velocity to zero as register 2 reaches 0,
	indicating that you are over the landing site, then register 11
	will be very close to what we need.
[=]
	Register 12 shows the difference between our current oribital
	inclination and the oribital inclination of the target orbit plane.
	In this case we are about 3 degrees too low, which makes sense since
	we are in an equitorial orbit and the landing site is at -3 degrees
	latitude.  Because we are in a retrograde orbit around the Moon,
	this angle is reference from 180 degrees instead of 0.  Basically
	the closer register 12 is to 90.0000 the closer our angle is to
	the target orbit plane, so our task is to get register 12 to 90.0000.
[=]
	3 degrees is a considerable change to make to our orbit and will
	require firing our descent engine at the correct time to make this
	change.
[e-]
[=]
	The next plane change maneuver occurs at about 87 degrees west of
	the landing site.  Since our target is in the southern hemisphere,
	we will need to thrust northwards and therefore require an 
	anti-normal orientation.  We should already be running program 34
	on the guidance computer from the last maneuver, so the guidance
	computer will keep us properly oriented for this next maneuver.
	As a quick note, if our landing site were in the northern hemisphere
	then we would need to thrust southward, which requires an orbit
	normal orientation.
[=]
[er]
	+-----------------------------+
	|  99298.9  -87.0316    3.0183|
	+-----------------------------+
[ee]
	13. When register 2 shows that you are 87 degrees west of the landing
	site, hit <shift><I> to engage your descent engine and then 
	immediately hit <F9> to increase to 90 % thrust.
[e-]
[=]
[er]
	+-----------------------------+
	|  2516.91    2.0453   89.9990|
	+-----------------------------+
[ee]
	Now watch the number in register 12, we need this number to be as
	close to 90.0000 as you can get it.  Take notice of how much it
	changes each screen update so that you can time when to throttle
	down.  When it starts getting close to 90.0000 then press <F3>
	to throttle down to 30% and then presst <I> to shut down the engine
	when you hit 90.0000.
[=]
	If all went well, register 12 should be fairly close to 90.0000 and
	register 11 should be within a couple degrees of 0.0000.
[=]
	Take a quick look at your descent fuel, you should now be down to
	about 94%, which means we now have less fuel for the actual landing.
	Also, with the burn off of fuel for this maneuver, the spacecraft
	is now lighter and we will have to account for that when it comes
	times to begin powered descent.  With the lighter spacecraft we
	will slow down quicker, and therefore need to start PDI a little
	bit later than when the LM is fully fueled.
[e-]
[=]
	14. With the plane change maneuvers complete, we should now be in
	an orbit that takes us over the landing site.  We can now prepare
	for the next maneuver, Descent Orbit Insertion (DOI), which occurs
	165 degrees west of the landing site.
[=]
	To prepare for DOI, you need to orient the spacecraft retrograde.
	Enter <V><3><7> <N><3><2> into the guidance computer to have it
	re-orient the spacecraft retrograde.
[=]
	While the computer is adjusting the alignment of the spacecraft,
	enter <V><1><6> <N><5><2> so that the computer will again show you
	positioning date relative to the landing site.
[=]
[er]
+-------------------------+
|    LOOKING   PROGRADE   |
| +===outside|==========+ |
| |          F          | |
| |                     |n|
| |                     |o|
| |                     |r|
| |                     |m|
|--          U         L--|
|a|                     | |
|n|                     | |
|o|                     | |
|r|                     | |
|m|                     | |
| +==========|inside====+ |
+-------------------------+
[ee]
	15. When the computer has finished orienting the spacecraft retrograde,
	U in the center of the prograde display, use the roll controls,
	<keypad><7> or <keypad><9> to roll the spacecraft so that the forward
	face is facing outside the orbit.  This is the orientation that we
	will want to maintain throughout the rest of the landing.
[=]
	Cross check your alignment using the precision axis display, set in
	prograde mode.  The F: face Norm should be as close to 0.00 as
	possible in order to limit any cross-track thurst during landing.
	Adjust your rotation throttle down so that you can get the forward
	face as close to 0.00 in the Norm colum as possible.  Afterwards
	return your rotation throttle to the medium mode.
[e-]
[=]
[er]
	+-----------------------------+
	|  99855.0  -165.041    5.9603|
	+-----------------------------+
[ee]
	16. When the guidance computers shows you at 165 degrees west of
	the landing site, press the <shift><I> key to engage the descent
	engine.  Leave the engine at 10% for this maneuver.
[e-]
[=]
[er]
	+-----------------------------+
	|  20.1119    99.871   6842.26|
	+-----------------------------+
[ee]
	17. Keep an eye on register 13, this is your periapsis altitude,
	when it gets to 20, press <I> to stop the descent engine.  If your
	periapsis altitude is between 20.0000 and 20.5000 then you are good
	to go, otherwise use your up and down thrusters to adjust your
	peripasis altitude to get it between 20.0 and 20.5.
[e-]
[=]
[er]
	+-----------------------------+
	|  494.698    2.0463   89.9993|
	+-----------------------------+
[ee]
	18. Now keep an eye on register 10, this is our distance to the
	landing site.  Between the plane change maneuvers and DOI, we are
	now down to about 93% descent fuel, this means our spacecraft is
	about 500 kilograms lighter than a fully fueled LM, as such, our
	engine thrust will be more effective and we will slow down quicker,
	which means we need to start powered descent a little bit later.
[=]
	When register 10 shows you are about 495km from the landing site it
	is time to begin powered descent.  First press <shift><I> to engage
	your descent engine and then immediately hit <F9> to throttle up
	to 90%.  Then switch the guidance computer to show data relavent to
	landing with <V><1><6> <N><7><2> <ENTER>
[e-]
[=]
[er]
	+-----------------------------+
	|   P 32      V 16      N 72  |
	|  20107.5    484806   2676.15|
	|  -2.2920  -1675.77  -21.0935|
	|   0.0124    2.4989    0.1125|
	|     RUN                     |
	|  637.137   12.9555   8254.45|
	|  486.423   1675.90   6687.09|
	+-----------------------------+
[ee]
	We have a moment before we will have to make any adjustments, so
	lets take a quick look at V16N72 display.  Registers 1 through 9
	are similar to other modes, the top row shows positions, second
	row shows velocities, and the third row shows accelerations, just
	like the mode 52 screen that we have been looking at up tils now.
	the main difference is registers 2 and 3 now show distances in
	meters instead of degrees.  So the sample display here shows that
	we are 484.8km east of the landing site, and 2.6km north of it.
[=]
	Registers 10 through 14 gives us additional data used for landing.
[=]
[lb]
[li]	Register 10 - This shows how many seconds of fuel remain at the
	current burn rate
[li]	Register 11 - This shows the current fuel consumpion in kg/second
[li]	Register 12 - This shows the remaining fuel in kilograms
[li]	Register 13 - This shows the distance to the landing site in km
[li]	Register 14 - This shows our velocity along the line of flight
[le]
[e-]
[=]
[er]
	+-----------------------------+
	| -38.2553  -1325.05   -8.9613|
	+-----------------------------+
[ee]
	19. We want to establish a descent rate of about 38m/s.  Register 2
	shows our descent rate, we will let the computer keep us in retrograde
	orientation until this register shows a descent rate of -38m/s.  This
	will occur at about 2 minutes 15 seconds into powered descent.
[=]
	When register 2 shows you are descending at 38m/s, you need to
	disengage the guidance computer by hitting the <p> key.  Next hit
	the <keypad><8> key 4 times to start pitching forward.  Watch 
	register 7, when it gets to zero then hit the <keypad><2> 4 times
	to stop the pitch movement.
[=]
	From this point until we reach pitch-over at high gate, you need to
	keep your descent rate at 38m/s.  If you are descending too quickly,
	then pitch forward (<keypad><8>) to slow your descent, if you are
	descending too slowly then pitch back (<keypad><2>) to increase
	your descent rate.  Remember to cancel out your pitch movement after
	changing your accelerateion.
[e-]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 72  |
	|  3834.94   3904.80    3.4726|
	| -38.1760  -130.194    0.0058|
	|   0.0057    3.9631   -0.0058|
	|          IDL                |
	|  131.137   12.9555   1698.95|
	|   5.4761   135.676   2318.04|
	+-----------------------------+
[ee]
	20. During the braking phase you want to be keeping an eye on
	register 14, which is your veloicty along the line of flight.
	The braking phase ends and high-gate/pitch-over begins when your
	velocity is at 100m/s.
[=]
	The sample here shows that I am approaching high-gate and I will
	need to perform my pitch-over maneuver soon.  There are a few things
	we can look at here, first my current altitude is about 3834 meters,
	I am about 3.9km east of the landing site and 3.4 meters south of it.
	Since I am near enough to the landing site on the north/south line,
	I have pretty much nulled out my movement north/south.  I currently
	have 131 seconds of fuel, left at the 90% I am currently at.
[=]
	Begin pitch-over when register 14 shows your velocity to be 100m/s.
	To perform pitch-over, hit the <keypad><8> key 4 times to begin a
	2 degree/second pitch forward movement.  Now, keep an eye on the 
	u/r: guage, you want to end pitch-over when this gets to 20.0.
	As you are pitching forward you will be directing more of your
	rocket thrust downward, so you will need to decrease your throttle
	as you pitch over in order to maintain your 38m/s descent.
[=]
	After picth-over your landing radar will be able to get a lock on
	the ground, so press <shift><,> to select your landing radar as
	the data source for the guidance computer and to activate your
	landing radar display.
[e-]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 72  |
	|  2409.84   1122.13    0.5395|
	| -39.5454  -48.0279   -0.1156|
	|  -0.0489    0.5845   -0.0004|
	|          IDL                |
	|  283.362    4.8943   1386.86|
	|   2.6586   62.2136   2306.22|
	+-----------------------------+
[ee]
	Here is what my guidance computer shows at the end of pitch-over.
	My altitude is now only 2409 meters, soon I will be at low-gate,
	1700 meters and beginning of the terminal phase of landing.  I
	am currently 1.1km east of the landing site, moving towards it at
	48m/s, my north/south position is still on target.  You can see
	in register 10 that my fuel is now 283 seconds, which is certainly
	more comfortable to see than the 131 seconds I had left before
	pitch-over.  Register 11 shows that I am now only burning 4.8
	kilograms of fuel per second vs the 12.0kg I was burning before.
	My throttle (not seen here) is now at 34%, my u/r: is 20.5.
[e-]
[=]
	21. At low-gate, 1700m, you need to begin slowing for landing.
	Increase the throttle so that you acceleration, in register 7 is
	+0.5.  Also keep an eye on your east/west velocity, register 5,
	and your north/south velocity, register 6, and be sure to null out
	your accelerations once these get withing tolerance for landing,
	less than 2m/s in each direction.  Note that pitch <keypad><8> and
	<keypad><2> will control your east/west acceleration, and <keypad><4>
	and <keypad><6> will control your north/south acceleration.
[=]
	22. When your altitude hits 500 meters, your descent should be at
	-20m/s.  If your descent is faster than this, you will need to 
	increase your throttle to get back on the descent curve.  If your
	descent hits 20m/s before you get to 500 meters then adjust your
	throttle to keep descent at 20m/s until you get to 500 meters and
	then readjust to decelerate at .5m/s when you hit 500 meters.
[=]
	23. When your altitude hits 200 meters, your descent should be at
	-10m/s. If your descent is faster than this, you will need to
	increase your throttle to get back on the descent curve.  If your
	descent his 10m/s before you get to 200 meters then adjust your
	throttle to keep descent at 10m/s until you get to 200 meters and
	then readjust to decelerate at .5m/s when you hit 200 meters.
[=]
	24. When your altitude hits 100 meters, your descent should be at
	-5m/s.  At this point you can slow your descent to about -3m/s
	until you get lower to the ground, once you get below about 30 meters
	then slow your descent a little more.  For a nice, soft landing, try
	to have your descent rate below -1m/s at touchdown.
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 72  |
	|  -0.0000   57.7334   39.4772|
	|   0.0000    0.0000    0.0000|
	|   0.0000    0.0000    0.0000|
	|          IDL                |
	|  137.377    4.6064   632.815|
	|   0.0699   1082.20   3259.20|
	+-----------------------------+
[ee]
	After landing, your velocities and acceleratiosn should all go
	to 0.0000.  You can check register 2 to find out how far east or
	west of the target landing site your touchdown was, and register
	3 will tell you how far north or south of your target you came
	down.
[=]
	In my sample here, I had 137 seconds of fuel remaining, so more than
	2 minutes, a nice comfortable margine, just in case I needed to
	maneuver a little bit in order to come down on a flat spot.
[=]
	After landing you should also do <shift><Z> to perform a damage 
	check to make sure you are good to stay on the surface for awhile.
[e-]
[=]
	This completes the planned landing tutorial.  In the next tutorial
	we will use our mission plan to explore the Moon, and in the final
	tutorial of this series we will take off and rendevous with the
	orbiting CSM.

