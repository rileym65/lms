[c]	Starting at the Moon
[=]
	This short tutorial will show you how to setup the simulator for a
	Lunar landing starting from Earth.  This is to prepare you for
	tutorial 9, which shows how to land on the Moon from Lunar orbit.
[=]
	To begin make sure you do not currently have a lms.sav file.  If this
	file exists then the simulator will load it rather than allowing you
	to create a new simulation.
[=]
	1. Start the simulator and you will be presented with a short menu
	of options for starting the simulation.  Select option '1' to start
	from the Earth.
[=]
	2. Next you will be given a list of spacecraft to fly.  Select option
	'7', the Apollo-J.  The landing tutorial assumes the thrust and weight
	specifications of this spacecraft.
[=]
	3. At this point you will be on the launch pad.  Follow either tutorial
	7 or tutorial 8 to launch into orbit.
[=]
	4. Continue with tutorial 7 or 8 until after you have completed the
	Trans Lunar Injection (TLI) burn.  In those two tutorials you go to
	the Moon without bringing a LM with you, but for tutorial 9 you will
	need one.  So once your TLI burn is complete, follow tutorial 3 on
	how to pick up the LM.
[=]
	5. After you have picked up the LM continue to follow tutorial 7 or 8
	until you are in Lunar Orbit.  A very important note, with the LM your
	spacecraft is some 16,000kg heavier, meaning it will take considerably
	more fuel for the Lunar Orbit Insertion (LOI) burn.  This means you will
	have less leeway for correction burns at the Moon.  You will need about
	28% SPS propellant remaining for a safe return to Earth.  If during the
	LOI burn your remaining SPS propellant hits 28%, immediately stop your
	burn and at this point you will have to abort the landing attempt, 
	undock from the LM and try to get back home to Earth.
[=]
[er]
	+-----------------------------+
	| Apo:    99.9   Lan:  170.66 |
	| Per:    99.7   Inc:  151.55 |
	| OT:  1:57:50   Gnd:  -44.61 |
	+-----------------------------+
[ee]
	6. After entering Lunar Orbit, you need to set a landing site.
	We can use our Lunar orbit
	information to set the target.  For the simplest in-plane landing we
	want to have the target landing site at our furthest North (or South)
	point of our orbit, therefore the inclination.  For the CSM to be over
	the target at the correct latitude then the Longitude of Ascending node
	needs to be 90 degrees East for a Northern landing site, or 90
	degrees West for a Southern landing site.  Here is a sample of one
	of my Lunar orbits, I will use these numbers to show how to set the
	landing site.  You will need to make the proper calculations for whatever
	numbers show on your Lunar Orbit panel.
[e-]
[=]
[er]
	+--------+
	|      P |
	|     16 |
	|   V  N |
	|  24 12 |
	| +08066 |
	| +02845 |
	| -00010 |
	+--------+
[ee]
	7. We set our target landing site by using the Guidance computer.  We must
	first enter our landing coordinates by executing V24.
[=]
	This will now ask for a value in register 1, which is the longitude of the
	target landing site.  For the simplest in-plane landing we want our landing
	site at our maximum Northern latitude, therefore 90 degrees East of our
	orbit's ascending node.  In my example my ascending node is 170.66 degrees
	East, so to get my optimum landing site I need to subtract 90, so 170.66 -
	90.0 gives me a target longitude of 80.66 decrees East, which I enter into
	register 1.
[=]
	Next we have to enter our landing site latitude into register 2.  Our orbit
	inclination tells us the maximum latitude we will be North of the Lunar
	equaator and therefore we can compute our landing latitude based upon our
	orbit inclination.  Since we are in a retrograde orbit the inclination
	guage on the instrument panel does not give our direct inclination, we must
	compute it, to do this subtract the number on the Inc: guage from 180, so
	180.0 - 151.55 = 28.45.  So for my example orbit my inclination is 28.45 
	degrees and therefore my landing site latitude is 28.45 degrees which
	I enter into register 2.
[e-]
[=]
[er]
	+--------+
	|      P |
	|     16 |
	|   V  N |
	|  50 12 |
	| +08066 |
	| +02845 |
	| -00010 |
	+--------+
[ee]
	Now that register 1 holds our landing site longitude and register 2 holds
	our landing site latitude all we need to do now is execute V50 to instruct
	the guidance computer to set our landing site target.
[e-]

[=]
	At this point go back to tutorial 9 and good luck on your landing!
[=]



