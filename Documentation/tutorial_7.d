[c]	Apollo 8, Getting to the Moon
[=]
	In this tutorial we are going to go to the Moon. Be sure to read
	the tutorial fully before starting. Since there is no pause function
	within the simulator, in many cases you will not have time to read
	ahead to the next step. If you feel you do need time to review the
	next step of the flight, you can always <shift><Q> out of the
	simulator, it will save your current state and reload it when you
	restart the simulator.
[=]
	Prerequisites for this tutorial:
[=]
[lb1]
[li]	Be able to launch into a clean parking orbit at 166km altitude
[li]	Be able to orient and maneuver the spacecraft
[le]
[=]
	Remove or rename any lms.sav file that may be present in the
	simulation directory, we want to start a new flight. Once the
	simulator starts, select option 7 "Apollo/LM-J/Saturn V" as the
	vehicle to fly. The real Apollo 8 mission did not take a LM with
	them, but they did put an equivalent weight on the launch vehicle
	to simulate the LM, this was mainly for validating flight
	performance of all the launch components that would be used for
	getting to the Moon. We will basicly do the same thing, we will
	carry a LM with us to orbit, but we will not perform the TD&E
	maneuver to pick it up.
[=]
	Before we start the flight, lets take a look at a few more
	instrument panel gauges that we will be using on this flight.
[=]
[er]
	+--------------------------+
	| Moon           G:   0.00 |
	| Dst: 370432  Ang: -42.21 |
	| Ra:   94.19  Dec:  29.52 |
	+--------------------------+
[ee]
	In the lower right corner of the screen is the Moon Information
	Panel. This panel gives us information on where the Moon is and
	contains the following gauges:
[=]
[lb2]
[li]	Dst:
[-]	This gauge shows the distance of the Moon from the Earth. At the
	start of the simulation this will be somewhere around 370,000km,
	the closest that the Moon gets to the Earth.
[li]	Ra:
[-]	This shows the current Right Ascenscion, or Celestial Longitude
	of the Moon.
[li]	Dec:
[-]	This shows the current Declination, or Celestial Latitude of the Moon.
[li]	G:
[-]	This gauge shows the amount of gravitational influence the Moon has
	on our spacecraft. This gauge will not normally show much until you
	get closer to the Moon. The Moon is always pulling on us at least a
	little bit, but this gauge will not show anything until that force
	gets larger.
[li]	Ang:
[-]	This gauge measures the angle between Moon's celestial longitude and
	that of the spacecraft. This will be explained more later.
[le]
[e-]
[=]
	Now it is time to begin our flight.
[=]
	1. Getting to the Moon is all about timing and there are two
	critical points in the flight where this timing is important. The
	first is when we launch. In order to get to the Moon, the phase of
	our orbit must be as close as possible to the phase of the Moon's
	orbit. Basicly this means that we want our Longitude of Ascending
	Node and Inclination to be as close as possible to that of the Moon.
[=]
[er]
	+--------------+
	| RtA:   90.00 |
	+--------------+
[ee]
	If we launch directly eastward, then our orbital inclination will
	be 28.50, the latitude of KSC. The Moon's inclination is 28.53, so
	as far as inclination goes, we are close enough. In this simulation
	the Longitude of Ascending Node (LAN) for the Moon is at 0 degrees,
	which means we want to launch when our LAN will be zero. With a
	direct eastward launch, the latitude of KSC will be our furthest
	point north, meaning that our LAN will be 90 degrees west of our
	launch point. Take a look at the RtA gauge in the position panel
	in the top center, it starts at zero at the start of the simulation
	and as the rotation of the Earth carries us eastwards this number
	slowly gets larger. When we launch our LAN will end up being 90
	degress smaller than what this gauge shows us. As such, we want to
	launch when this gauge reads 90.00, which will end up giving our
	orbit a LAN of 0.00, matching that of the Moon.
[e-]
[=]
	Setup your program 01 in the guidance computer, just as in the
	Launch to Orbit tutorial. Our launch window will not open til about
	6 hours from now, so you can press <shift><5> to speed up time. Keep
	an eye on the RtA gauge when it gets closer to 90.00 press
	<shift><1> to resume normal time.
[=]
	When the RtA gauge shows 90.00, then press <shift><L> to launch and
	then follow the launch procedures laid out in the Launch to Orbit
	tutorial and establish a parking orbit of 166.0km.
[=]
	If both your Apo and Per gauges are reading between 165.0 and 167.0
	then you are good to go. If either of these gauges is outside this
	range then your orbit is not quite good enough for a Lunar mission
	and you are best off starting over.
[=]
[er]
        +--------+
	| R    P |
	|     02 |
	|   V  N |
	|  37 02 |
	| +00500 |
	| +00000 |
	| +00000 |
	+--------+
[ee]
	2. Now that we are in orbit, we actually have a little bit of time
	before we need to make our next maneuver, Trans Lunar Injection
	(TLI), the second of the time critical maneuvers.
[=]
	Just like during launch where we used GC program 01 to give us a
	precision shut off of the main engine, we will also need a precision
	shut off of the engine during TLI. The GC gives us program 02 for
	this function. Program 02 needs to know what periapsis we want our
	transfer orbit to be at. So lets set that up, Press the following
	keys: <v><2><1><enter>. This prompts us to enter a value into
	register 1, press these keys: <0><0><5><0><0><enter>. This sets our
	target apoasis to 500,000km.
[=]

	Now we can start program 02: <v><3><7><n><0><2><enter>. The guidance
	computer panel should now show that program 02 is running.
[e-]
[=]
[er]
	+-------------+
	| Ang: 160.04 |
	+-------------+
[ee]
	3. Now we can take a breather for a bit. Keep an eye on the Ang
	gauge on the Moon Information Panel. When this gauge reads 160.00
	then orient the spacecraft to be prograde, from this point until
	the end of TLI you will need to keep the spacecraft oriented prograde.
[=]
	It takes some time for the Angle to get to 160.00, about GE 00:54:30
	so feel free to use the time compression controls.
[e-]
[=]
	4. At an angle of around 145.00 press the <tab> key to arm the
	engine. Remember to keep adjusting your orientation so that the
	spacecraft remains oriented prograde.
[=]
[er]
	+-------------+
	| Ang: 138.93 |
	+-------------+
[ee]
	When the angle reaches 138.95 press <shift><I> to ignite the engine.
	It is critical that at the point of ignition and during the entire
	TLI burn that the spacecraft remain oriented prograde. Keep an eye
	on the U: Elev gauge on the Prograde panel and keep that number as
	close to zero as you can keep it. When shooting for a target that
	is 370,000km away, a little error here ends up a really big error
	when you get out to the orbit of the moon.
[=]
	During the TLI burn, periodically look at the Apo gauge, you will
	see this increasing, slowly at first and near the end of the burn it
	changes pretty rapidly. You do not need to worry about shutting down
	the engine, program 02 will take care of that for you. The burn will
	end at about 00:05:10 on the BU clock, at which point you can relax,
	the hard part, for now, is done. Your velocity should now be in the
	neighborhood of 10,845m/s, Apo should be right around 500,000, give
	or take a kilometer.
[e-]
[=]
	5. When the GE clock gets to around 01:30:00, we will go ahead and
	separate from the launch vehicle. Orient the spacecraft prograde and
	set the translation throttle to medium. Press the <tab> key to arm
	the separation pyros and then <shift><j> to jettison the launch
	vehicle. Since we will not be picking up the LM, press the <u> key to
	activate the up thrusters, leave them on for 5 seconds and then press
	<u> again to stop the thrusters.
[=]
	6. At this point we are in Trans Lunar Coast and there is nothing to
	do for about the next 59 to 60 hours. Just hit <shift> <5> to
	activate maximum time compression and then sit back and relax. Just
	watch our altitude increase, our velocity decrease, the GE clock
	going up, etc. The simulation will automatically turn off time
	compression when we get to the sphere of influence of the Moon, so
	no need to look for any specific triggers for turning this off.
[=]
[er]
	+------+
	| Moon |
	+------+
[ee]
	7. When we enter the sphere of influence of the Moon, the point
	where the Moon is exerting more gravitational force on us than the
	Earth, the simulator will exit time compression mode. This should
	occur at an altitude of somewhere between 340,000km and 345,000km
	if your TLI was good. The GE clock should be reading around 60:00:00
	give or take an hour or two. The onboard navigation systems will
	automatically switch over to being Moon centric. This can be seen
	in the panel below the clocks, it will no longer say Earth, and
	now show Moon.
[e-]
[=]
[er]
	+-----------------------------+
	| Alt: 37169.4   Vel:  1190.7 |
	| Roc:   -1182   Acc:     0.0 |
	+-----------------------------+
[ee]
	With the navigation systems now using the Moon as the reference,
	lets take a look around our instrument panel. First look at our
	altitude, it should be somewhere in the neighborhood of 37,000km.
	Roc should be somewhere around -1100 indicating we are descending
	towards the Moon, our Velocity is probably something close to this
	number as well. Acc will probably be around 0.0, at this distance
	from the Moon our velocity is not going to be changing a whole lot.
[e-]
[=]
[er]
	+-----------------------------+
	| Apo:------.-   Lan:  171.17 |
	| Per:   828.3   Inc:  151.54 |
	| Ot:---:--:--   Gnd: -102.15 |
	+-----------------------------+
[ee]
	Now lets take a look at the orbit information panel, there are some
	interesting things to see here which you have not seen before. Start
	with the Apo guage, the lines indicate that we are in an open orbit,
	meaning we will not circle the moon, we will fly by it. The Per
	gauge is our closest approach to the moon, we will look at this
	more in depth shortly. The OT clock also is just lines, again
	because we are in an open orbit. Lan should be in the 170 to 180 range.
[=]
	Inc probably needs some explanation, how could we have an
	inclination greater than 90 degrees? Normally you cannot, and even
	here our inclination is less then 90 degrees. With the Inc gauge
	showing us a number greater than 90, we are in a retrograde orbit,
	orbiting in the opposite direction of rotation. If your Inc gauge
	is showing less than 90 then you are in a prograde orbit, while you
	can still establish a closed orbit from a prograde orbit, a free
	return is impossible, If you are in a prograde orbit and just fly
	by, you will never return to Earth, you will end up in a solar
	orbit. This is part of the reason why Nasa used retrograde orbits
	at the Moon, if the SPS did not fire then the spacecraft would just
	return to Earth. While in a retrograde orbit, you can calculate your
	actual inclination by subtracting the Inc value from 180, so in the
	example: 180-151.54=28.46, indicating our orbit inclination is 28.46
	degrees.
[e-]
[=]
	8. Ok, now back to the Per guage. At this point we need this to
	be about 265km to get a good Lunar Orbit Insertion (LOI). Very
	likely this is not the number you have. If your Per gauge is reading
	larger than 265km we will need a course correction towards the
	inside of the orbit, if the Per gauge is reading lower then 265km
	then you will need a course correction towards the outside of the
	orbit. If the number is negative, your periapsis is below the
	surface of the moon and without a course correction you are
	destined for a fiery death.
[=]
	To perform the course correction, first orient the spacecraft
	retrograde, then rotate the spacecraft so that the F face is
	towards the inside of your orbit (bottom of Prograde mode on the
	multi axis display) and the L face is towards the anorm.
[=]
	If your Per is too low, then pitch forward so that the U face of
	your spacecraft is pointing straight up (outside) on the multi axis
	display in prograde mode. Once the vehicle is properly oriented,
	press the <tab> key to arm the SPS engine and then press <shift><I>
	to ignite the engine. Keep an eye on the Per gauge, when it
	approaches 265km press the <i> key to stop the engine. Then use the
	RCS thrusters to fine tune your Per.
[=]
	If your Per is too high, then pitch back so that the U face of your
	spacecraft is pointing straight down (inside) on the multi axis
	display in prograde mode. Once the vehicle is properly oriented,
	press the <tab> key to arm the SPS engine and then press <shift><I>
	to ignite the engine. Keep an eye on the Per gauge, when it
	approaches 265km press the <i> key to stop the engine. Then use the
	RCS thrusters to fine tune your Per.
[=]
[er]
	+--------------+
	| Per:   265.3 |
	+--------------+
[ee]
	Once your course correction is made then reorient the spacecraft
	back to point retrograde with the F face towards the inside of the
	orbit. Now you can wait a bit. Periapsis is about 7 hours in the
	future. You can use time compression controls until your altitude
	is below 1000km. Note that during your descent to the Moon the Per
	guage will decrease, this is fine and should stabalize somewhere
	around 150km, leaving us plenty of room to perform our LOI burn.
[e-]
[=]
	9. At 1000km altitude it is time to start preparing for LOI. Take
	a look at the instruments. Our Roc should be around -1300m/s, Vel
	should be around 2175m/s, Per should be between 125km and 150km.
	Orient the spacecraft retrograde. From here until the end of the
	LOI burn you will need to keep the spacecraft oriented retrograde.
[=]
	When your altitude is 100km above your Per, press the <tab> key to
	arm your SPS engine, Do not forget to be maintaining a retrograde
	attitude.
[=]
[er]
	+--------------+
	| Alt:  183883 |
	| Roc:    -440 |
	| RtA:  148.54 |
	| ------------ |
	| Apo:------.- |
	| Per:   133.6 |
	+--------------+
[ee]
	When your altitude is 50km above your Per, press <shift><I> to
	ignite your SPS engine. For example, if your Per is 133km then you
	ignite your engine at 183km.
[=]
	During the burn be sure to keep your spacecraft oriented
	retrograde. The U: Elev gauge on the prograde panel should stay
	as close to 0.00 as you can keep it.
[=]
	You will want to keep your eyes on several instruments during the
	burn. First and foremost is the U: Elev gauge on the prograde panel
	to ensure that your are maintaining a good retrograde orientation.
	Second most important is the Per gauge, this is the gauge that will
	tell us when to stop our burn. Periodically look at the Vel gauge,
	at about 2270m/s your Apo gauge will start showing a real number,
	this is the point where you are technically in orbit of the Moon,
	but since we want a nice circular orbit around 100km altitude you
	will need to keep burning. As your Per gauge starts approaching
	100km, it will become your primary instrument to look at. When the
	Per gauge hits 100.0km then press the <i> key to stop your burn.
[e-]
[=]
[er]
	+--------------+
	| Alt:  127385 |
	| Roc:    -108 |
	| RtA:  133.90 |
	| ------------ |
	| Apo:   813.0 |
	| Per:   100.8 |
	+--------------+
[ee]
	Now that the LOI burn is complete it is time to assess our
	situation. Our Altitude should still be well above our periapsis
	altitude and the Roc gauge shouuld show that we are descending
	still. The Per gauge should show our periapsis right around 100km.
	The Apo gauge will likely be several 100km above the Per gauge.
[=]
	At this point we are in a stable orbit around the moon, but not an
	ideal orbit for a Lunar mission. Ideally we want to be in a
	ciruclar orbit, both our Per and Apo gauges reading about 100km.
	In order to circularize our orbit, we will need to execute another
	burn just before periapsis. Keep an eye on your altitude and Roc
	gauges. Continue to maintain a retrograde orientation. When your
	Roc gets close to 0, press the <tab> key to arm your SPS engine and
	when it hits zero press <shift><I> to ignite your engine. Keep a
	close eye on your Apo guage, it will change pretty rapidly, press
	the <i> key to stop your engine when Apo gets close to 100.0km.
	During the burn adjust your U: Elev to keep Roc at 0. After engine
	shutdown, use your Up or Down RCS thrusters to fine adjust your Per
	or Apo gauge, whichever one is changing when you use the thrusters,
	get it to 100.0km.
[=]
	If both the Apo and Per gauges are reading right around 100.0km then
	your LOI process is complete. If not, you should have one of them
	at 100.0km and the other maybe a few kilometers off. Use the orbit
	circularization procedures you learned in the maneuvering tutorials
	to get your orbit completely circular.
[e-]
[=]
[er]
        +-----------------------------+
	| Alt:   99954   Vel:  1633.4 |
	| Roc:       0   Acc:    -0.0 |
	| Rta:   38.56   Dec:   21.69 |
        +-----------------------------+
	| Apo:   100.3   Lan:  171.25 |
	| Per:   100.0   Inc:  151.58 |
	| OT:  1:57:52   Gnd:  -88.65 |
        +-----------------------------+
[ee]
	10. Here is what a good lunar orbit looks like. Your altitude
	should be right around 100km, velocity should be in the neighborhood
	of 1633.5m/s, Rate of climb should be 0, Acceleration should be 0,
	and Apo and Per altitudes should be close to 100.0km. If we had a
	LM with us, this is an orbit that would be suitable for a landing.
[=]
	At this point the hardest part of this mission is over. Getting from
	the Earth to the Moon and in an orbit suitable for a landing is a
	tough thing to do, it requires precision and proper timing to
	accomplish. If you made it to the moon and are in a good clean orbit
	at 100km and have 55% or more left of your SPS propellant then you
	are ready to try and tackle a full Lunar landing mission. If you did
	not meet these criteria, then after this mission is over give it
	another go and in no time you will be able to get to the Moon quite
	easily, it just takes some practice.
[=]
	During the real Apollo 8 mission, they remained in orbit of the
	Moon for 10 orbits before heading home. Considering you have no
	pretty scenery to look at in this simulator, just numbers changing
	on your screen, there is no reason for you to stay at the Moon for
	those 10 orbits. Proceed on to the next step when you are ready to
	return to Earth.
[e-]
[=]
	11. Returning to Earth requires us to perform a Trans Earth
	Injection (TEI) burn. This burn must be executed at the correct
	time and add enough delta v to get us out of Lunar orbit and on
	a transfer orbit That takes us the right distance from Earth. Again
	we will use the guidance computer to shutdown the engine at the
	correct time. First we need to specify how much delta v we want to
	add, we need to enter this into register 1: <v><2><1><enter>
	<0><0><9><6><0><enter>. Next start program 03:
	<v><3><7><n><0><3><enter>. Program 03 simply monitors how much
	delta V is being produced after the engine starts and when our
	requested delta V is reached it will shut off the engine.
[=]
	Now we must wait until the correct time to start our burn. The burn
	needs to occur when we are on the opposite side of the Moon from
	the Earth. there is an easy way for us to see when that occurs. In
	the position panel, our RtA gauge tells us at what celestial
	longitude we are around the moon, in the Moon panel the Ra gauge
	tells us the celestial longitude of the Moon around the Earth. When
	these two numbers are the same then it is time for our burn. It is
	important that when this burn is started and throughout the burn
	we maintain a prograde orientation of the spacecraft. When our RtA
	is about 15 degrees before the Moon's Ra, orient the spacecraft
	prograde and then maintain the prograde orientation until the burn
	is complete. At 5 degrees before these numbers match, press the
	<tab> key to arm the SPS engine, and when these numbers match press
	the <shift><I> key to iginte the SPS engine.
[=]
	All you have to do during the burn is to keep the spacecraft
	oriented prograde. Use the U: Elev gauge on the prograde panel to
	maintain your angle. Periodically look at register 2 on the GC panel,
	this tells you how much delta V is left on the burn, when this
	reaches 0 the computer will automatically shut off the engine. You
	can also periodically look at the Apo guage, you should see this
	increasing and eventually at a velocity or around 2300ms the Apo
	gauge will switch to lines, indicating that we have exceeded the
	Moon's escape velocity and are no longer in a closed orbit around
	it. After engine shutdown you can stop worring about your attitude
	for awhile.
[=]
	12. After the TEI burn, we can relax for a bit. It will take about
	7 hours to climb out of the Moon's gravity well, so go ahead and
	use <shift><5> to enter time compressed mode. The time compression
	will stop automatically when we leave the Moon's SOI and enter the
	SOI of the Earth. This transition should occur at around 38,000km
	altitude from the Moon.
[=]
[er]
	+-------+
	| Earth |
	+-------+
[ee]
	After you have transitioned to the Earth's SOI, you will notice
	that the navigation flag below the clocks now shows that the
	computer is referencing navigation data from the Earth. Your
	altitude from The Earth is going to be somewhere around 340,000km,
	Roc will show that we are falling towards the Earth, Vel should be
	somewhere between 950m/s and 1000m/s. Our Apo gauge again has a
	valid number, probably in the high 500,000s, indicating that we are
	in a closed orbit around the Earth.
[=]
	Just like when we first entered the Moon's SOI, we needed to make
	a correction burn to adjust our periapsis altitude, we need to now
	do one to adjust our Earth periapsis altitude. The periapsis we need
	is about -2500.0km. Negative you ask? Yes, as we fall towards Earth
	our periapsis altitude will increase, by a quite large amount so to
	avoid a large course correction near earth where course corrections
	are expensive in use of fuel, by setting this below ground periapsis
	way out here, by the time we get closer to the Earth our periapsis
	will be closer to what we need for reentry and less expensive in
	the use of fuel, which if we had done a landing mission, we would
	not have much fuel left by this point.
[=]
	Making this correction burn is very similar to the one we made
	coming into the Moon. First orient the spacecraft retrograde, then
	rotate the spacecraft so that the L face is towards the anorm side
	of the prograde axis display and that the F face is towards the
	bottom, or inside, edge of the axis display. Now, if your Per gauge
	is reading greater than -2500, then we need to decrease our
	periapsis, so pitch back so that the U face is towards the bottom
	of the prograde axis display. If your Per gauge is reading below
	-2500 then you need to increase it, so pitch forwards so that the
	U face is towards the top of the prograde axis display.
[e-]
[=]
[er]
	+--------------+
	| Per: -2500.6 |
	+--------------+
[ee]
	With your spacecraft oriented either inside or outside the orbit
	as needed, if your current Per is within about 200km of the -2500km
	we are looking for, just use your RCS thrusters to adjust it,
	adjusting the translation throttle as needed to get your Per to
	-2500km. If the amount you need to change is greater than 200km,
	you will need to use the SPS engine. At this distance one second of
	SPS burn makes a huge difference in your periapsis, so take note
	this burn may only be a few seconds. After you have gotten the
	periapsis within about 200km of the -2500km we want, shutdown the
	SPS engine and then use the RCS thrusters to fine tune your
	periapsis. After your course correction, reorient the spacecraft
	retrograde.
[e-]
[=]
	13. At this point we enter the Trans Earth Coast phase and for
	about the next 2 days we do not need to do anything. Go ahead and
	press <shift><5> to enter time compressed mode. During the Trans
	Earth Coast, just monitor the instruments, you should see altitude
	decreasing, velocity increasing, rate of climb increasing and Per
	increasing.
[=]
[er]
	+--------------+
	| Per:    55.0 |
	+--------------+
[ee]
	When altitude gets to about 100,000km, press <shift><1> to take
	the simulator out of time compress mode so that we can evaluate if
	we need to make any course corrections. Before you took it out of
	time compression you should have noticed that the rate of change on
	the Per gauge was slowing down considerably. At 100,000km there will
	still be some change yet to come but we are getting close to where
	it will be stable. The Per gauge needs to read about 60.0km at
	reentry, out here at 100,000km we want it to show about 55km.
	Chances are you should be within about 100km of this. If so then
	you should be able to adjust it using just your RCS thrusters. If it
	is more than 100km off then you will probably need a quick burst on
	the SPS to get it close and then fine adjust with the RCS thrusters.
	Be sure to orient the spacecraft appropriately for whatever
	adjustment you need to make.
[=]
	Again use time compression until you are about 50,000km altitude.
	Check your Per gauge, it should be pretty close to 60.0km. Use RCS
	thrusters as needed to adjust it to 60.0km. It may still change a
	little, so we will make a final adjustment during our pre-reentry
	procedures.
[e-]
[=]
	14. You can use time compression again until your altitude is
	10,000km. At 10,000km check your Per and adjust it as needed to be
	60.0km. At this point we will also prepare for reentry. Start by
	orienting the spacecraft retrograde. we also want the F face towards
	the bottom of the prograde axis display, and the L face towards the
	left, or anorm, side. Keep an eye on altitude and when we get to
	2000km altitude, pitch back so that the U: Elev gauge is reading
	-45.0, this sets us up for service module jettison. This is done so
	that the service module enters the atmosphere on a different
	trajectory as the command module, eliminating the possibility of a
	collision during reentry.
[=]
	At an altitude of 1000km, make any adjustment to your angle so that
	you have a U: Elev angle of -45, then press the <tab> key to arm
	the SM jettison pyros and then press <shift><J> to jettison the
	service module. After service module jettison reorient the
	spacecraft retrograde and keep it oriented retrograde until your
	altitude is 110km.
[=]
	Reentry occurs at 100km. At this point your velocity is over
	11000m/s. After reentry, stop adjusting any angles, the spacecraft
	will take care of its own orientation from this point forward. Just
	watch the altitude decrease, velocity decrease and the G forces
	(Acc) rapidly building up.
[=]
	All you need to do at this point is keep an eye on the altitude
	gauge. When the altitude drops below 3000 meters press the <shift><P>
	key to deploy your parachutes. Your job is done. The spacecraft will
	float gently down to splashdown and the simulation will end. You
	will be given a report number should you wish to review the mission.
[=]
	Good job! Getting to the Moon and back is not easy and once you can
	perform this with ease you will be ready for attempting an actual
	Moon landing.
[=]
[c]	Summary of Mission
[=]
[lb1]
[li]	Launch when RtA gauge shows 90.00
[li]	Establish a circular parking orbit at 166.0km
[li]	Perform TLI burn when Moon angle is 138.95
[li]	About 1/2 hour after TLI burn, jettison the launch vehicle
[li]	Trans Lunar Coast ends when entering SOI of the Moon
[li]	Course correction to set Per at 265km
[li]	At 50km above your periapsis altitude start your LOI burn
[li]	Stop your LOI burn when periapsis altitude is 100.0km
[li]	When you reach periapsis, circularize your orbit
[li]	Start your TEI burn when the RtA gauge matches the Ra gauge of the Moon
[li]	At Earth SOI, adjust Per to -2500km
[li]	At Altitude 100,000km, adjust Per to 55km
[li]	At Altitude 50,000km, adjust Per to 60km
[li]	At Altitude 10,000km, adjust Per to 60km
[li]	At Altitude 2,000km, pitch pack to -45 U: Elev
[li]	At Altitude 1,000km, jettison the service module, Orient to retrograde
[li]	Maintain retrograde until altitude of 110km
[li]	At 100km reentry begins. Stop adjusting any angles
[li]	At 3000 meters, deplay the parachutes
[li]	At 0 meters, Splashdown!
[le]

