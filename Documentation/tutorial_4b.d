[c]	Orbital Maneuvers
[=]
	In this tutorial we will go over the various orbital maneuvers
	you will need to know in order to successfully complete a Moon
	mission.  This tutorial assumes that you have previously gone
	through the tutorial on Spacecraft Orientation and that you are
	currently in orbit with an Apollo spacecraft.  If you are not
	yet in orbit, follow the tutorial on Launch to Orbit.  Ideally
	for this tutorial you want to be in a 166km circular orbit, as
	described in the Launch to Orbit tutorial
[=]
[h2]	Hohmann Transfer
[=]
	We will start by doing a Hohmann transfer to a higher orbit.  A
	Hohmann transfer is a minimum energy maneuver that allows you to
	change the alitude of your orbit.
[=]
[er]
	+-------------------------+
	|    LOOKING   PROGRADE   |
	| +===outside|==========+ |
	| |                     | |
	| |                     |n|
	| |                     |o|
	| |                     |r|
	| |                     |m|
	|--l         u          --|
	|a|                     | |
	|n|                     | |
	|o|                     | |
	|r|                     | |
	|m|          F          | |
	| +==========|inside====+ |
	+-------------------------+
[ee]
	In order to go from a lower altitude orbit to a higher altitude
	orbit we will need to make 2 burns, both prograde.  In a Hohmann
	transfer the first burn occurs at the periapsis of your current
	orbit and the second burn will occur at the apoapsis of the 
	transfer orbit, which will leave you in a circular orbit at the
	new altitude.
[=]
	If you are in a circlular orbit already then you will be able
	to make the first burn at any time.  If your orbit is out of round
	by more than a few kilometers then you will want to make the
	first burn at your current orbit periapsis, or when your altitude
	matches the value shown on the 'Per:' display.
[=]
	A few minutes before you reach the point you will make your burn
	you will need to orient the spacecraft prograde and keep it oriented
	prograde up to and throughout the burn.
[=]
	To help with timing, you can use the guidance computer to tell you
	how much time there is before periapsis.  To set this mode press
	these keys: <v><1><16> <n><1><0> <enter>.  The computer will now
	show you a countdown to peripais.  Register 1 has the hours
	remaining, register 2 has the minutes, and register 3 the seconds.
[e-]
[=]
[er]
	+-----------------------------+
	| Apo:   300.0   Lan:  -89.93 |
	| Per:   166.0   Inc:   28.50 |
	| OT:  1:29:09   Gnd:  +54.18 |
	+-----------------------------+
[ee]
	When you are about 30 seconds from the burn press the <tab> key	
	to arm the SPS engine.  If you are going from 166km to 300km, the
	burn itself will last about 28 seconds, so you will want to begin
	your burn 14 seconds before periapis.  If you do not have the LM
	with you then your spacecraft will be lighter and the burn will
	be shorter say wait until about 8 seconds before periapsis to begin
	the burn.
[=]
	When you reach the point to begin your burn, press <shift><i> to
	ignite your SPS engine.  Now keep a good eye on the Apo: display
	on the orbit information panel, when it approaches 300.0 press
	the <i> key to turn off the SPS engine.  You will likely not be
	right at 300.0km, so just use the <u>p or <d>own thrusters to
	adjust the apoapsis to 300.0.  Do not forget during the burn
	to keep the spacecraft oriented prograde the entire time, as
	well as during the fine tuning with the thrusters.
[e-]
[=]
	Once your Apoapsis has been adjusted to 300.0km, the first part of
	the Hohmann transfer is complete and now all you need to do is wait
	until you get to apoapsis, where you will make your next burn.
	The guidance computer can show you how long it is to apoapsis by
	keying <v><1><6> <n><0><9> <enter>.  This will then give you a 
	countdown clock to apoapsis, which should be about 45 minutes away.
[=]
[er]
	+-----------------------------+
	| Apo:   300.0   Lan:  -89.93 |
	| Per:   300.0   Inc:   28.50 |
	| OT:  1:30:31   Gnd: -138.17 |
	+-----------------------------+
[ee]
	When you are just a couple minutes away from apoapsis you will
	again need to orient the spacecraft prograde and keep it oriented
	prograde up to and throughout the upcoming burn.
[=]
	At about the 30 seconds to go mark press the <tab> key to arm the
	SPS engine and when you are about 10 seconds from apogee press
	<shift><i> to ignite the SPS engine.  Remember to keep the spacecraft
	oriented prograde throughout the burn.  Keep a close eye on the Per:
	display of the orbit information panel, when it approaches 300.0
	press the <i> key to stop the SPS engine.  With the LM attached,
	this burn will take about 20 seconds, which is why we started it
	10 seconds early.  If you do not have the LM with you, then start
	your burn about 7 seconds early instead of 10.
[=]
	Once you have shutdown the SPS, use the <u>p and <d>own thrusters
	to fine tune your periapsis.  If both your Apo and Per are reading
	between 299.5 and 300.5 then you did an excellent job on this 
	transfer.
[e-]
[=]
	Now that this tranfer is complete, lets talk about a couple things.
	First, the first burn is called an "injection burn", this is a burn
	that injects the spacecraft into a different orbit, in this case it
	was a Hohmann transfer orbit.  The original orbit was a 166km x 166km
	circular orbit.  After the injection burn the spacecraft was in a
	300km x 166km elliptical orbit.
[=]
	The second burn that we made at apoapsis is called a "circularization
	burn," A burn that takes an elliptical orbit and converts it into
	a circular orbit.  In this case we were in a 300km x 166km elliptical
	orbit and after the circularization burn we were in a 300km x 300km
	circular orbit.  Note that the circularization burn is technically
	also an injection burn, in that it injects you into the circular
	orbit from the elliptical one.
[=]
	Something very important to note during this maneuver, whenever
	we burned the SPS engine, we ended up adjusting the opposite side
	of the orbit than where we were.  We burned at periapsis, which
	changed the apoapsis.  We burned at apoapsis which changed the
	periapsis.  So just remember, whenever you are making burns that
	affect orbit altitude, the altitude you are affecting is on the
	opposite side of the orbit than where you are making the burn.
	As an example of how to apply this, suppose after your Hohmann
	transfer you ended up in a 300km x 295km orbit, how do you fix
	this to be 300km x 300km?  The answer would be to burn prograde
	at apoapsis, since it is the periapsis that you want to change.
[=]
	Next thing to note, when you burn prograde you will be increasing
	the altitude of the orbit.  In our transfer here we increased our
	orbit from 166km to 300km.  If you want to lower the altitude of
	your orbit then you will burn retrograde.  So the main takeaway
	here is that if you want to increase either Per or Apo then you
	need to perform a prograde burn at the opposite node.  If you want
	to lower Per or Apo then you will need to burn retrograde at the
	opposite node.
[=]
	Be sure you understand the Hohmann transfer as well as how to
	adjust periapsis and apoapsis.  Most burns that you will make in
	relation to Lunar missions are going to be Hohmann transfers, 
	injection burns, or circularization burns.
[=]
[h2]	Plane Change Maneuver
[=]
	Plane change maneuvers are required anytime that you wish to
	adjust the plane of your orbit.  Through plane change maneuvers
	you can adjust the longitude of ascending node or the inclination
	of your orbit.  Plane change maneuvers are more complicated than
	altitude changes and require more work on your part.  Because
	plane change maneuvers are not needed for a basic Lunar mission, I
	am only going to go over a basic inlination change here and reserve
	the more complex discussion of plane change maneuvers as they
	relate to Lunar missions in a later tutorial.
[=]
	For making a change to the inclination of an orbit you must make
	the burn at the correct time.  When an orbit intersects with another
	orbit, it crosses that orbit at 2 and only 2 points, each on
	opposite sides of the orbit.  When your current orbit crosses the
	target orbit from a south to north direction, that is the ascending
	node, when your orbit crosses the destination orbit going from
	north to south, this is the descending node.  An inclination change
	can only occur at one of these two nodes.  In the case of an
	inclination change, we use the equator of the body we are orbiting
	to represent the target orbit, so the ascending node is when we
	cross the equater going northward and the descending node is when
	we cross the equater while travelling southward.
[=]
[er]
	+-----------------------------+
	| Alt:  299938   Vel:  7725.6 |
	| Roc:      -0   Acc:     0.0 |
	| RtA:   15.65   Dec:   27.61 |
	+-----------------------------+
	| Apo:   300.0   Lan:  -89.93 |
	| Per:   299.9   Inc:   28.50 |
	| OT:  1:30:31   Gnd:  -89.44 |
	+-----------------------------+
[ee]
	For changing inclination it does not really matter at which node
	we make our burn, but it is important that we burn the correct
	direction for the node we will be burning at.  To increase 
	inclination we must either burn "normal" at the ascending node,
	or burn "anti-normal" at the descending node.  To lower our
	inclination we must do the oppostie, burn "anti-normal" at the
	ascending node, or burn "normal" at the descending node.
[=]
	For this tutorial we are going to lower our inclination.  Here
	on my spacecraft I have a declination of 27.61, which means I am
	north of the equator, which means the next node that I am going
	to cross will be the descending node.  I will need to burn
	"normal" in order to lower my inclination at the descending node.
[=]
	If your declination is negative, then you are south of the equator
	and your next node will be the ascending node.  You have two choices
	about what you can do:  Either time compress until you are north
	of the equator and then you can follow this tutorial with the
	same orientations that I will be using, or you can make your burn
	at the ascending node, in which case you will need to orient
	backwards from what I will be doing, the choice is yours.
[e-]
[=]
[er]
	+-------------------------+
	|    LOOKING   PROGRADE   |
	| +===outside|==========+ |
	| |                     | |
	| |                     |n|
	| |                     |o|
	| |                     |r|
	| |                     |m|
	|--          l         u--|
	|a|                     | |
	|n|                     | |
	|o|                     | |
	|r|                     | |
	|m|          F          | |
	| +==========|inside====+ |
	+-------------------------+
[ee]
	The first thing we need to do is to orient the spacecraft correctly
	for the burn.  Since I will need to perform a "normal" burn, I must
	orient my spacecraft so that the Up face is fully towards the "norm"
	side of the multi-axis display.  
[=]
	Next, since during the plane change maneuver we are going to have
	to adjust the spacecraft on two axis, not just one, we will need
	one face to use as our reference face, in my case I choose the Left
	face to be my reference face, this face we want to be centered on
	the multi-axis display.
[=]
	In this orientation, I will need to adjust both roll and yaw to
	keep the spacecraft correctly oriented.  It is important that during
	a plane change maneuver that the Up face is always pointed the 
	correct direction, just like we had to maintain prograde during our
	earlier Hohmann transfer.  Since during the plane change maneuver
	the "normal" for the orbit will be moving, we will need to make
	constant adjustments to keep the Up face oriented correctly.
[e-]
[=]
[er]
	+-------------------------+
	|     Elev     Norm       |
	| U:    0.00    90.00  +  |
	| F:  -89.91    -0.00  +  |
	| L:   -0.09    -0.00  +  |
	+-------------------------+
[ee]
	The multi-axis display will help you to quickly orient the spacecraft
	to the correct orientation, be we will use the precision prograde
	panel to actually monitor our angles up to and throughout the plane
	change.  Since I chose the Left face to be my reference face, that
	is the only face we need to watch, both the Elev and Norm on
	the reference (Left) face need to stay as close to zero as we can
	keep them.  
[=]
	The elevation of the Left face will be controlled using roll controls,
	while the normal of the Left face will be controlled using yaw
	controls.  Just like you observed during the orientation tutorial,
	the elevation of the Left face will be constantly changing as we
	orbit around the Earth, and the normal component will remain steady.
	During the plane change, both the elevation and normal will be
	changine and so you will need to be making adjustments to keep
	the Left face centered.
[e-]
[=]
[er]
	+-----------------------------+
	| Alt:  299959   Vel:  7725.6 |
	| Roc:       0   Acc:    -0.0 |
	| RtA:   86.92   Dec:    1.71 |
	+-----------------------------+
[ee]
	Keep an eye on your declination, when it gets below 2 degrees, press
	the <tab> key to arm the SPS.  When it gets to about 0.5, press
	<shift><i> to ignite your SPS engine.
[=]
	Now keep a very good eye on the Left face in the precision prograde
	panel, use roll controls to keep the Left face elevation as close
	to zero as you can keep it and yaw controls to keep the Left face
	normal as close to zero as you can keep it.  Also keep an eye on
	the Inc display in the orbit panel, you want to end your burn by
	pressing the <i> key when the inclination shows 28.00 degrees.
[e-]
[=]
[er]
	+-----------------------------+
	| Apo:   300.2   Lan:  -89.94 |
	| Per:   299.7   Inc:   28.00 |
	| OT:  1:30:31   Gnd:  -41.45 |
	+-----------------------------+
[ee]
	When the burn is complete, take a look at the orbit panel.  Your
	new Inclination should be 28.00 degrees.  If all went well then
	your Lan, Apo, and Per should all be pretty close to what they
	were when you started.  You should expect a little bit of change
	in these displays, but the changes should be minimal.
[e-]
[=]

