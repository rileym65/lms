[c]	Launch to Orbit
[=]
	In this tutorial we are going to launch to orbit. Be sure to read
	the tutorial fully before starting. Since there is no pause function
	within the simulator, in many cases you will not have time to read
	ahead to the next step. If you feel you do need time to review the
	next step of the flight, you can always <shift><Q> out of the
	simulator, it will save your current state and reload it when you
	restart the simulator.
[=]
	If you did not fly the flight in the sub-orbital tutorial, you may
	want to fly that mission first, or at the very least read the
	beginning section that describes instrument panel gauges.
[=]
	Remove or rename any lms.sav file that may be present in the
	simulation directory, we want to start a new flight. One the
	simulator starts, select option 7 "Apollo/LM-J/Saturn V" as the
	vehicle to fly. Although there are numerous choices for vehicles
	that can be used for an orbital flight, we are going to fly a fully
	loaded Saturn V. The main reason for flying this vehicle is that for
	later Lunar flights, a clean parking orbit is necessary and so you
	may as well start practicing the skills needed to get a clean
	parking orbit with the vehicle that we will eventually use to go
	to the Moon.
[=]
	Before we start the flight, lets take a look at a few more
	instrument panel gauges that we will be using on this flight.
[=]
[er]
	+-----------------------------+
	| Apo:     0.0   Lan:    0.00 |
	| Per: -6378.1   Inc:     nan |
	| OT:  0:29:52   Gnd:  -80.61 |
	+-----------------------------+
[ee]
	Start by looking in the upper middle of the screen, right below
	the position panel. This is the orbit panel and provides
	information that describes your current orbit. The values found
	on this panel are:
[=]
[lb2]
[li]	Apo:
[-]	This gauge shows the current apoapsis of your orbit. The apoapsis
	is the point in your orbit that you are farthest from your primary
	body. This gauge shows your apoapsis in kilometers altitude, in
	other words, distance above mean ground level. Right now this is
	showing zero, since sitting on the ground without moving,
	0 kilometers above the ground is our current highest point.
[li]	Per:
[-]	This gauge shows the periapsis, or lowest point of orbit. Like the
	apoapsis gauge, this shows the distance in kilometers above the
	mean surface level. Right now this is showing a negative number
	since if the ground was not holding us up we would be falling
	towards the center of the Earth, our lowest point orbit would be
	well below the surface of the Earth.
[li]	Lan:
[-]	This shows your current Longitude of Ascending Node. This shows
	at which celestial longitude our orbit crosses the equater moving
	from south to north. At the moment this is showing zero since until
	we launch the guidance computer is not receiving position data to
	compute this number. After launch when we have an actual trajectory,
	the computer will show where our ascending node is.
[li]	Inc:
[-]	This gauge shows the inclination of our orbit, or how far is our
	orbit inclined to the equator. Like the Lan guage, since we are
	sitting on the ground we do not yet have a valid inclination and
	so the gauge shows zero. After we launch this gauge will show us
	our proper orbital inclination.
[li]	OT:
[-]	This is the orbital clock and shows how long it takes to complete
	one orbit around the primary body.
[li]	Gnd:
[-]	This shows what our ground longitude is. This is useful when you
	need to know what the longitude of the ground is underneath your
	spacecraft as oppsed to the celestial longitude. This is mainly
	useful when planning retro fire for re-entry so that you can target
	a specific landing area. Right now this gauge shows -80.61 which is
	the ground longitude of Kennedy Space Center.
[le]
[e-]
[=]
[er]
	+---------------+
	| UT:  8:30:09  |
	| GE:  0:00:00  |
	| BU:  0:00:00  |
	| TB:  0:00:00  |
	| DY:        0  |
	+---------------+
[ee]
	In the upper right of the screen is the clocks panel. This panel
	shows several mission related clocks:
[=]
[lb2]
[li]	UT:
[-]	This clock shows the current UTC time. Note that the simulator uses
	its own concept of time and the UTC is not related to the real time.
[li]	GE:
[-]	This is the Ground Elapsed time. This clock starts at liftoff and
	continues to run throughout the mission. All mission events are
	usually referenced to this clock.
[li]	BU:
[-]	This clock shows the time of the current or last main engine burn.
	This clock resets to zero when any main engine is started and
	continues to run until all main engines are no longer running.
	Additional burns always reset this clock to zero when they are
	started.
[li]	TB:
[-]	This is the total burn clock and shows the cumulative time that
	main engine burns have occurred. This clock starts at zero at the
	beginning of the mission and will run any time that the burn (BU)
	clock is running.
[le]
[e-]
[=]
[er]
	+--------+
	|      P |
	|     00 |
	|   V  N |
	|  00 00 |
	| +00000 |
	| +00000 |
	| +00000 |
	+--------+
[ee]
	Just to the left of the clocks panel is the main panel for the
	guidance computer. The computer used in FMS is modeled after the
	Apollo Guidance Computer (AGC) used by NASA for the Apollo missions.
	However, the computer in FMS does not use the same flight software
	nor the same commands as the AGC did. But the way in which the
	computer is used is similar to the AGC. Commands were given to
	the AGC as Verb/Noun pairs and the guidance computer in FMS follows
	this model.
[=]
	The number below the "P" is the program that is currently loaded
	into the computer. If that program is actually running then an "R"
	symbol will appear in the upper left corner of the panel.
[=]
	The number below the "V" is the current Verb and the number below
	the "N" is the current Noun. During numeric entry into these are
	any of the numeric fields, a "_" symbol is shown for each digit
	that the computer is waiting for you to enter.
[=]
	The three 5-digit numbers represent the values of Register 1 (top),
	Register 2 (middle) and Register 3 (bottom). The numbers that appear
	here will vary depending on which modes the computer is currently
	running.
[=]
	The guidance computer can run in several modes, only a couple will
	we touch on in this tutorial. For more information on the guidance
	computer, refer to the CSM Guidance Computer manual.
[e-]
[=]
	1. In all the NASA missions the astronauts did not pilot the
	rockets, they were all controlled by computer. But what fun is that
	in a simulation program, so here you will be piloting the rocket.
	The only real thing we need the computer to do is cut off the
	engines at the right time. The simulator only updates the screen
	once per second, which is not good enough when you need precise
	orbits, for this reason we will use the computer to stop the engines.
[=]
	To start the needed computer program, type the following keys in
	order: <v><3><7><n><0><1> <enter>. If you then look at the computer
	panel, you should now see the number 37 below "V" and the number
	"01" below "N". The number below "P" should be 01, indicating that
	the computer now has prgram 01 loaded. In the upper left corner of
	the computer panel there should be an "R" flag indicating that the
	program is running. Here is what we actually did, the "v" key told
	the computer we wanted to enter a new verb, essentially a new
	command for the computer. We then entered "37" as the command we
	want the computer to do. Command "37" is the command to load a new
	program. We needed to tell the computer which program to load,
	which is what the "n01" was for, we wanted to load program 01.
	Then lastly we hit "enter" to tell the computer to process the
	command we just gave it.
[=]
	Program 01 is a launch monitor. In register 1 it will show the
	current altitude in kilometers times 10, in register 2 it will
	show the rate of climb and in register 3 it will show the current
	velocity.
[=]
	The other major function of program 1, and the reason why we are
	using it, is to monitor for a specific condition and then shut
	down the engines when that occurs. Here is what it is looking for,
	when the periapsis is above the surface of the earth, it takes the
	current apoapsis and computes what the circular orbit velocity is
	for that altitude, it then monitors the vehicle velocity and shuts
	down the engines when that velocity is reached. If we do our part
	correctly then we will be in a nice near-circular orbit when the
	computer shuts the engines down.
[=]
	Since the output from program 01 is not really interesting for
	us since this information is already displayed on the position
	panel, lets demonstrate another function of the computer. Type
	these keys in sequence: <v><1><6><n> <1><4><enter>. Verb 16 is
	the command to monitor data. The 16 command uses the noun to
	determine what is going to be monitored. In this case, noun 14
	says that we want to monitor deltaV and fuel flow. With V16N14
	register 1 will show the remaining amount of deltaV available to
	the main engines. Register 2 will show the amount of deltaV
	available to the RCS engines and register 3 will show fuel flow
	of the main engines in kilograms per second. Right now these
	numbers are all going to show zero, but once we launch they will
	show valid numbers.
[=]
[er]
	+------------+
	| u/r:  19.9 |
	+------------+
[ee]
	2. Time to launch. Press <shift><L> to launch. Check your
	instruments to verify launch. The engine status display should show
	all 5 engines are running. Rate of climb should be increasing as
	well as altitude and velocity. Watch your altitude and when it
	exceeds 200 meters press <keypad><2> to start a 1 degree per second
	pitch back maneuver. You want to continue this pitch back maneuver
	until you get to about 20 degrees on your u/r meter. When the u/r
	meter shows an angle greater than 19.5 then press the <keypad><8>
	key to stop the pitch back maneuver.
[=]
	At this point you can sit back and relax for about a minute and just
	monitor the instruments. In register 1 of the guidance computer you
	can see how much delta V the current stage has remaining and in
	register 3 you can see just how much fuel those thirsty F1 engines
	are, consuming over 13,000 kg per second! Just keep an eye on the
	instruments until your altitude hits 8,000 meters, which should
	occur about 00:01:14 into the flight.
[e-]
[=]
[er]
	+------------+
	| u/r:  64.8 |
	+------------+
[ee]
	3. When your altitude gets to 8,000 meters press <keypad><2> to
	begin a one degree per second pitch back maneuver. Keep an eye on
	your u/r angle, when this angle gets between 64.0 and 65.0 press
	the <keypad><8> key to stop the pitch back maneuver. This maneuver
	should be complete about 00:02:00 into the flight. From this point
	until further notice you need to keep your u/r angle between 64.0
	and 65.0. Normally this number will slowly get smaller, when it
	hits 64.0 then hit the <keypad><2> key, allow 1 screen update, you
	will see u/r at 65.0 and then hit <keypad><8> to stop the pitch.
[e-]
[=]
[er]
	+-----+
	| * * |
	|  O  |
	| * * |
	+-----+
[ee]
	4. At about 00:02:19 into the flight you will notice that the center engine will shutoff. This is normal. Remember to keep monitoring your instruments and maintaining u/r between 64.0 and 65.0 degrees.
[e-]
[=]
	5. At about 00:02:52 stage I will run out of fuel and the remaining
	4 engines will shut down. Once the engines have all shut down then
	press the <shift><S> key to initiate staging. Stage I will be
	jettisoned and all 5 stage II engines will ignite, just verify that
	all engines started. For most of the stage II flight all you need
	to do is monitor the instruments and keep your u/r between 64.0
	and 65.0 degrees.
[=]
	6. While monitoring the other instruments, also be sure to be
	looking at the stage II fuel guage, when it hits 50%, which should
	happen about 00:02:59 into the burn (BU clock), we want to start
	preparing for the levelling off maneuver. Take a quick look at your
	Apo guage, it should be somewhere in the high 130s to low 140s if
	you have been doing a good job with your pitch angle. If this value
	is above 150 then you have been flying too low a pitch angle and
	are going to have to expidite your level off procedure. If you
	are below the low 130s then you have been flying too high a pitch
	angle and chances are pretty poor that you will be able to obtain
	a good parking orbit.
[=]
	Lets set the computer to give us some numbers to make the round
	out procedure a little easier. Enter this sequence:
	<V><1><6><N><1><7><enter> The two numbers we are interested in
	this mode are register 2, which shows us how fast our rate of climb
	is changing, and the number in register 3, which shows how much
	our apoapsis is changing.
[=]
[er]
	+--------------+
	| Apo:   157.3 |
	+--------------+
[ee]
	7. Keep an eye on the Apo gauge, when it reads about 157 then
	increase your u/r angle to 80. Hold the u/r to 80 and keep an
	eye on both the Apo gauge and register 3 of the guidance computer.
	As the Apo gauge gets closer to 166, our target alt, you will want
	to increase your u/r angle to slow down the change to apoapsis.
	Use register 3 of the guidance computer to see how much your
	apoapsis is changing. Be carefule not to chase register 3, only use
	it as a guide to what is happening, if you chase this number you
	will find you will just oscilate around it and be constantly
	adjusting your pitch.
[e-]
[=]
[er]
	+------------+
	| u/r:  92.9 |
	+------------+
[ee]
	You want to bring your change in apoapsis to zero just about the
	time that the Apo gauge reads 166.0. Note that it will take a u/r
	angle of about 93 degrees to stop the increase in apoapsis.
[=]
	Once you have stabalized your apopsis at around 166, next keep an
	eye on the Roc gauge. This should be positive at this point and
	decreasing. As it gets closer to zero you will need to decrease
	your u/r angle. Your goal from now until the end of the launch is
	to maintain an Roc of 0.
[=]
	Some time during this process of levelling off you will most
	likely need to initiate staging to stage III. So always be
	keeping an eye on your fuel guage. It will be in the neighborhood
	of 20% when you first start the levelling off phase and will most
	likely run out before the levelling phase is complete. Just be
	sure to press the <shift><S> to initiate staging when the stage
	II engines have all stopped.
[e-]
[=]
	8. At this point all your main work is done. All you need to do
	is keep your Roc at zero until stage III is done. The launch
	should complete about 11 minutes into the mission (GE clock).
	You will know the launch is complete when the stage III shuts
	down. Your stage III fuel remaining should be around 75%.
[=]
	If you did a good job with your pitch control then your Apo and Per
	gauges should be pretty close to 166.0. A clean parking orbit
	that is suitable for lunar missions requires both Apo and Per
	gauges to be between 165.0 and 167.0. If either of these gauges
	is outside this range, then your final orbit is not suitable for
	a Lunar mission. If you did not get a clean orbit, do not worry
	too much about it. It takes a bit of practice to be able to judge
	just how to control your pitch to get a clean orbit. Keep
	practicing launches and in no time you will become an expert at
	achieving clean orbits.
[=]
	If your Per guage is reading below 100.0 then you did not achieve
	orbit since your periapsis is still in the atmosphere. In this
	case set your RCS translation throttle to high by hitting <+>
	twice. Now you need to separate from the launch vehicle, press
	the <tab> key to arm the separation pyrotechnics and then press
	<shift><J> to jettison the launch vehicle. Now press <U> to
	activate the up RCS thruster, wait ten seconds and then press
	<U> to stop the RCS up thruster. Now go to the turoral on re-entry
	to learn how to perform a proper reentry.
[=] 
[c]	Summary of Launch
[=]
[lb1]
[li]	Launch
[li]	At 200 meters altitude, pitch back to u/r 20
[li]	At 8000 meters altitude pitch back and maintain u/r 60
[li]	At Apo 10km below target altitude, pitch back and maintain u/r 80
[li]	When Apo approaching target altitude, adjust pitch to stop Apo
	increase at target altitude
[li]	When Roc approaches 0, adjust pitch to maintain a ROC of 0
[le]
[=]
	Remember to keep an eye on all relavent instruments during launch
	and be sure to initate staging as each stage runs out of fuel.
[=]
[c]	Where to go from here
[=]
	If you are still reading this, I will assume that your periapsis
	was above 100.0, so congratulations for making orbit! At this point
	you are in a stable orbit and still connected to the launch vehicle.
	Since we did not launch at the correct time for a Lunar mission,
	you cannot perform any of the Lunar mission tutorials from this
	flight, however you can proceed with any of the Earth orbit tutorials.
[=]
	If you want you can do all the Earth orbit tutorials from this
	flight, or if you feel you would like more launch practice, you
	could spread them out over multiple flights. If you want to perform
	them all in a single flight, then do them in this order:
[=]
[lb1]
[li]	Booster Separation/TD&E
[li]	Orbital Maneuvers
[li]	Flying the LM
[li]	Deorbit/Reentry

