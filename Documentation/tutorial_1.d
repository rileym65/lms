[c]	Sub-orbital Flight
[=]
	In this tutorial we are going to fly a simple sub-orbital flight,
	which will be a good introduction to space flight.  Since this
	flight is rather short and many events occur close together, be
	sure to read the entire tutorial first as you will not have a lot
	of opportunity to read the next step.  There is no pause function
	in the simulator, but if you do find a need to pause the simulation
	to re-read this tutorial, you can always <shift><Q> out of the
	simulator, it will save your current state and reload it when you
	start the simulator again.
[=]
	1. Erase any lms.sav file that may already be present in the
	directory, otherwise the simulator will start with this file rather
	than allowing you to create a new flight.
[=]
	2. Start up lms and select option: "1. Mercury/Redstone" as the
	vehicle to fly.
[=]
	3. This will bring you to the main simulation screen, sitting in
	the command module, ready for liftoff.  You will be presented with
	an awful lot of information, much of which you will not need for
	this flight.  Throughout this series of tutorials I will introduce
	new instruments ad they are needed.
[=]
[er]
	+-----------------------------+
	| Alt:      28  Vel:     0.0  |
	| Roc:       0  Acc:     0.0  |
	| RtA:    0.01  Dec:   28.50  |
	+-----------------------------+
[ee]
	Lets start by looking at the panel in the upper middle of the
	screen.  This panel shows the current position and velocity
	of the spacecraft.  Lets look at each of these in detail:
[=]
[lb2]
[li]	Alt:
[-]	This shows the spacecraft's current alitutde above the mean
	radius of the Earth.  You may be wondering why it is showing 28
	when we are still sitting on the ground.  This is because the 
	altitude is measured at the command module, which is sitting on
	top of the Redstone rocket, as such we are currently 28 meters
	above the ground.
[li]	Roc:
[-]	This shows the rate of climb.  For now it is showing zero since
	we are sitting on the ground.  Once we lift off this number will
	indicate how quickly we are gaining or losing altitude.
[li]	Vel:
[-]	This shows the current velocity of the spacecraft.  Since we are
	still on the ground this shows that we are not moving.
[li]	Acc:
[-]	This shows how much acceleration the spacecraft is experiencing.
	For now it is showing 0.0, indicating that our velocity is not
	chaning.  After we launch this number will indicate how many
	meters per second our velocity is changing.
[li]	RtA:
[-]	This shows our current Right Ascension, or celestial longitude.
	The celestial longitude is more or less fixed in space and does
	not change due to the Earth's rotation.  When you first start
	the simulator it will show 0.0, indicating that we are currently
	aligned with the origin of the coordinate system.  If you sit
	and watch the simulator for a bit you will see this number 
	slowly increasing, this is because the Earth is rotating and
	carrying us along with it.  Over the course of a 24 hour day
	this will count up to 180, then change to -180 as we pass into
	western coordinates, and count towards 0 where it will begin
	counting up again.  For a Lunar mission this number is very
	important to when you launch, for this mission it is not really
	relavent.
[li]	Dec:
[-]	This shows us our current declination, or celestial latitude. At
	the moment this is showing 28.50, which is how many degrees
	Kennedy Space Center is north of the equator. This number will not
	change a whole lot during this flight since we will not be moving
	very far and so will not progress too far along our orbital plane,
	but you will notice that during the flight this number will
	decrease, indicating that our orbital path is bending southwards.
[le]
[e-]
[=]
[er]
	+------------+
	| u/r:   0.0 |
	+------------+
[ee]
	Now look towards the left side of the screen, a little bit below
	the halfway point and you will see the 'u/r' guage. This belongs
	to a whole panel of gauges that provide angle measurements between
	various faces of the spacecraft and other vectors. The 'u/r' guage
	is important to our flight as it measures the relative angle of
	where our spacecraft is pointing in relation to the ground. The
	'0.0' that is showing there right now indicates that we are
	currently pointing directly away from the ground, or straight up
	at the sky. For this flight this is one of our most important
	gauges since at certain points during the flight we will need to
	be at certain angles in relation to the ground.
[e-]
[=]
[er]
	+---------------------------+
	|     LOOKING   DOWN        |
	|  +======west|==========+  |
	|  |                     |n |
	|  |                     |o |
	|  |                     |r |
	|  |                     |t |
	|  |                     |h |
	| --l         U          -- |
	| s|                     |  |
	| o|                     |  |
	| u|                     |  |
	| t|                     |  |
	| h|          F          |  |
	|  +----------|east======+  |
	+---------------------------+
[ee]
	The next instrument to look at is the Multi-Axis display, it is
	the large instrument that dominates the lower center of the
	screen. This instrument gives you a graphic depiction of the
	orientation of the spacecraft, it can operate in 4 different
	modes, for now we will stick to the "Looking Down" mode. The way
	to visualize what this guage is doing, think of drawing a line
	starting at the ground directly under the spacecraft, going
	through the spacecraft and up to the sky, picture yourself on
	that line above the spacecraft looking down through it to the
	ground.
[=]
	On the guage itself you can see three letters, 'U', 'L', and 'F'.
	the L and F may be in lower case, the U will definitely be in
	uppercase. These three letters are associated with the three
	primary faces of the spacecraft. 'U' represents the upward face,
	which when considering the entire vehicle is the face directly
	opposite of the engine on the Redstone rocket. Seated in the
	spacecraft you are actually looking towards the 'U'p face.
[=]
	The 'F' represents the forward face of the spacecraft, which if
	you are sitting in the spacecraft, looking in the up direction,
	the forward face would be directly over your head.
[=]
	The 'L' represents the left face of the spacecraft, which if you
	are sitting in the spacecraft, looking in the up direction, the
	left face would be where your left arm is.
[=]
	The Up and Forward faces may seem a little confusing to visualize,
	so here is another way to look at it. Imagine you are sitting in
	your car, driving. You are looking and moving in the up direction.
	The engine of the car propels it in a given direction, just like
	the rocket propels the spacecraft in a given direction, the
	direction that the primary movement force makes you go is
	considered up. Now still sitting in your car, the forward face
	is actually the roof of your car, and the left face is the left
	side door. So just remember that the direction the vehicle moves
	as a result of the primary power source is up, not forward, and
	whatever is directly above your head is forward.
[=]
	Now that you can visualize where the spacecraft faces are, look
	back at the multi-axis guage. A letter that is uppercase is angled
	towards you while a letter in lowercase is angled away from you.
	So, the 'U' that is currently in the center of the guage, this is
	telling us that the up face is not pointing in any of the cardinal
	directions, since it is in the middle. Because the 'U' is in
	uppercase, this indicates that the up face is closer to our
	imaginary viewpoint and away from the ground, in other words, the
	up face is pointing straight up towards the sky.
[=]
	Next, the 'F' is towards the bottom, or "east" side of the guage,
	indicating that the forward face is directed to the east, so
	directly above our head, as we are seated in the spacecraft is
	to the east.
[=]
	And lastly the 'L' is pointing to the south, indicating that the
	left side of the spacecraft, where our left arm is, is pointed
	to the south.
[=]
	At this point the L and F may be in either lowercase or uppercase.
	They are both on the plane that separates the nearside of the
	spacecraft towards our imaginary viewpoint from the far side. As
	the Earth is rotating, the vectors associated with these faces
	could have small mathematical errors that make them float between
	nearer to us or father to us, but in reality these two faces are
	exactly on the line that separates nearer and farther.
[=]
	After we launch we will take occaisonal glances at this instrument
	and you will be able to see the changes that occur during the flight.
[e-]
[=]
[er]
	+-----+
	|     |
	|     |
	|  O  |
	|     |
	|     |
	+-----+
[ee]
	Moving to the left the Multi-Axis display and along the bottom of
	the screen is the Launch Vehicle Engine Status display. This panel
	shows the running state of the launch vehicle engines. Since the
	Redstone rocket only has a single engine, there is only a single
	'O' in the center of the panel. The 'O' indicates that the engine
	is currently not running. For vehicles that have more engines, more
	'O' symbols will be displayed, one for each engine of the stage that
	has the most engines. For example, the Saturn V has 5 engines on
	the first stage, 5 engines on the second stage, and a single engine
	on the third stage, so this guage would show 5 'O' symbols.
[e-]
[=]
[er]
	+-------+
	|Fs1: 99|
	|       |
	|       |
	|       |
	|       |
	+-------+
[ee]
	Just to the left of the Launch Vehicle Status display is the
	Launch Vehicle Fuel guage. This shows the remaining fuel in each
	stage of the launch vehicle. Since the Redstone rocket has only
	a single stage, there is only one value. In a multi-stage launch
	vehicle there will be one value for each stage of the launch vehicle.
[e-]
[=]
	Now that we have gone over all the various instruments that we will
	need to keep an eye on for this flight, we are ready to launch.
[=]
	4. In this step we are going to have a few things to do in a short
	time, so be sure to fully understand this step before actually
	launching. To launch the mission press the <shift><L> keys. You
	should immediately notice a few changes to the instruments:
[=]
[i4]
[lb*]
[li]	The 'O' symbol on the Engine Status panel should have changed to
	a '*' indicating that the engine is now running.
[li]	The Rate of Climb gauge will start increasing, showing that we
	are now gaining altitude.
[li]	Probably the most confusing thing you will see is that the Velocity
	guage instantly jumps to 408m/s. Here is why. The Earth is rotating
	and carrying us eastward as it does so. At the latitude of KSC,
	this eastward motion is 408m/s. The Velocity guage shows space
	velocity, in other words the velocity in relation to the center of
	the Earth, but until we launch the INS (Inertial Navigation System)
	does not provide any positional data to the guidance computer, so
	sitting on the pad it showed a velocity of zero, which makes sense
	sitting on the ground, but in reality, sitting on the ground we were
	already moving 408m/s eastward. Once we lifted off the INS started
	giving position data to the guidance computer and now that 408m/s
	shows up in the velocity. If you really care about velocity in
	relation to the ground, for the first couple minutes of the flight
	just use the Rate of Climb as your indicator of acceleration.
[li]	The Acceleration guage should now show that we are accelerating.
	Throughoutt the launch this number will keep going up, as we burn
	fuel the whole vehicle gets lighter and the thrust of the engine
	more effective.
[le]
[i-4]
[=]
	Keep an eye on the altitude and once you are over 200 meters press
	the <keypad><2> once. This will start a 1 degree backward pitch
	motion. Watch the 'u/r' value and when it gets above 9.5 press the
	<keypad><8> key once to stop the pitch rotation. We are now on our
	desired flight angle and we can sit back and relax for a little bit.
[=]
	5. For the next couple minutes we really do not need to do much.
	In an orbital mission we would need to make adjustments during
	ascent, but for this mission we have already set us up on a
	ballistic flight and during powered ascent we will not need to do
	anything else.
[=]
	During this phase of the flight just keep an eye on the instruments.
	Start with the Multi-Axis display, notice that now the U is now down
	a little bit from center, this is because of that 10 degree pitch
	back maneuver we did in the last step, the up face of the spacecraft
	is now slightly east, which is what the Multi-Axis display is
	showing us.
[=]
	Keep an eye on the Altitude, Velocity, Rate of Climb, and
	acceleration guages. It is also a good idea to keep an eye on
	the Launch Vehicle Engine Status display to be sure it stays as
	a '*'. Technically it is not really necessary since the simulator
	currently does not simulate random failures, but a future version
	will, so it is a good idea to just make it part of your instrument
	scan. Also periodically check the Launch Vehicle Fuel guage, when
	this gauge falls below 10% it is time to move to the next step.
	Also watch the 'u/r' guage, you should see it slowly decrease, that
	is ok for this flight, but for orbital flights you would need to
	keep adjusting your flight angle to keep the 'u/r' guage within
	the range for your ascent profile, for this flight just watch it,
	do not make any adjustments to your flight path.
[=]
[er]
	+-----------------------+
	|                       |
	|                       |
	|                 ARM   |
	+-----------------------+
[ee]
	6. Once your launch vehicle fuel drops below 10% it is time to
	prepare for the end of powered ascent. At this point keep a close
	eye on the remaining fuel. When it goes to zero you should also
	see the engine stop on the Launch Vehicle Engine Status display.
	If you had performed your pitch maneuver correctly before then
	engine burnout will occur around 60,000 meters altitude. We are
	going to remain attached to the launch vehicle until we exit the
	atmosphere, but we will prepare for separation now. Press the <tab>
	key to arm the separation pyrotechnics. In the upper left corner
	of the screen is an annunciator panel which should now be showing
	that the ARM mode has been set.
[e-]
[=]
[er]
	+-----------------------+
	| BSP                   |
	|                       |
	|                       |
	+-----------------------+
[ee]
	7. Keep an eye on the altitude meter and when you are over 100,000
	meters it is time to separate from the launch vehicle. Press the
	<shift><J> key to jettison the launch vehicle. The annunciator
	panel in the upper left will now show that the ARM mode is no
	longer set and that booster separation has occured.
[e-]
[=]
	8. Now we need to prepare for retro fire and do not have a whole
	lot of time to do it. In reality retro fire is not necessary on
	this flight since it is sub-oribtal, but NASA did fire the retro
	rockets on both Alan Shepard's and Gus Grissom's suborbital flights
	for the purpose of testing the retro system. We will do that as well.
[=]
	After booster separation immediately hit the <keypad><8> four
	times, this will start a 4 degree per second pitch down maneuver.
	Keep an eye on the 'u/r' guage, you will first see it count down
	to zero and then start increasing again, we want this to increase
	until it reads 135. When it gets close you can press the <keypad><2>
	three times to slow your rotation to 1 degree per second and then
	1 final time when you are around 135 degrees. During this maneuver
	keep an eye on the Multi-Axis display as well, you will notice the
	U Move up to the top of the guage and then turn to lower case,
	which indicates that the up face is now angled towards the ground,
	and start moving down again. When you get to the correct
	orientation the 'u' will be obscured by the 'F' face.
[=]
	9. Keep an eye on the Altitude and Rate of Climb meters. When the
	Rate of Climb is less than 200, press the <tab> key to ARM the
	retro rockets.  You should see the ARM light on the annunciator
	panel.
[=]
[er]
	+-----------------------+
	| BSP                   |
	|                       |
	|     RTR               |
	+-----------------------+
[ee]
	10. When the rate of climb drops to zero and drops into the
	negative, press the <shift><I> key to ignite the retro rockets.
	Look at the annunciator panel to verify that the retro rockets
	are firing. Retro fire will last about 30 seconds.
[e-]
[=]
	11. Keep watching the annunciator panel and wait for the RTR lamp
	to go out, indicating that retro fire is complete.
[=]
[er]
	+-----------------------+
	| BSP                   |
	|                       |
	| RMJ                   |
	+-----------------------+
[ee]
	12. Once the retro fire is completed, press the <tab> key to arm
	the pryos for retro module jettison and then press <shift><J> key
	to jettison the retro package. The annunciator panel should now
	have the RMJ lamp lit indicating that the retro package has been
	jettisoned.
[e-]
[=]
	13. After retro module jettison immediately press the <keypad><2>
	key four times to begin a pitch up maneuver of 4 degrees per
	second. Keep an eye on the 'u/r' guage, when it gets close to 20
	degrees, press the <keypad><8> key 3 times to slow your rotation
	to 1 degree per second, when the 'u/r' guage gets to 20 degrees
	press <keypad><8> one more time to stop your rotation. You want
	this maneuver to be complete before your altitude drops below
	100,000 meters.
[=]
	14. Now we can just relax for awhile. Athmosphereic re-entry
	occurs at 100,000 meters. Since we are not at orbital speed we
	will not see any deceleartion until below about 50,000 meters
	where the air rapidly thickens. Just keep an eye on the Altitude,
	Rate of Climb and Acceleration guages. You know you are
	decelerating when the acceleration guage starts showing negative
	numbers, at which point you should see the Velocity and Rate of
	Climb numbers decreasing.
[=]
[er]
	+-----------------------+
	| BSP PAR               |
	|                       |
	| RMJ                   |
	+-----------------------+
[ee]
	15. Keep watching the Alitude. When the altitude drops below
	3,000 meters, press the <shift><P> key to deploy the parachutes.
	The PAR lamp of the annunciator panel will light to indicate that
	the parachutes have been deployed. You should also see that your
	Rate of Climb will rapidly decrease to 9 or 10 meters/second.
[e-]
[=]
	16. At this point all your work is done. All you need to do is
	wait to float down to splashdown. Once you splash down the program
	will exit and give you a mission report. Congratulations for
	completing your first space flight.
[=]

