[c]	Using the CSM Guidance Computer
[=]
	In prior tutorials we have only used the guidance computer to
	control engine shutdown on critical burns. But the guidance
	computer can do a whole lot more for you. In this tutorial we are
	again going to fly the Apollo 8 mission, but this time we are going
	to use the full capabilities of the guidance computer. Be sure to
	read the tutorial fully before starting. Since there is no pause
	function within the simulator, in many cases you will not have time
	to read ahead to the next step. If you feel you do need time to
	review the next step of the flight, you can always <shift><Q> out
	of the simulator, it will save your current state and reload it
	when you restart the simulator.
[=]
	Prerequisites for this tutorial:
[=]
[lb1]
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
	From this point forward I am going to use a shorter format for how
	you enter data to the guidance computer. When I say that you need
	to execute [V37N11] this indicates that you need to press these keys
	in sequence: <v><3><7><n><1><1><enter> I may also indicate exectuing
	a number, for example: [01660] This should be entered as:
	<0><1><6><6><0><enter>. I may also show several commands in
	sequence, like [V24 00500] this would indicate you need to press
	all of these keys in sequence: <v><2><4><enter>
	<0><0><5><0><0><enter>. Only when I show a command in square
	brackets [] should you actually execute it. I may talk about other
	commands, but if they are not in brackets, do not enter them into
	the computer. Also all commands end with a <enter> key and in the
	case of multiple commands, each command is also separated by
	pressing the <enter> key.
[=]
	1. If you have been having trouble getting clean parking orbits
	at 166km then the guidance computer has you covered. Program 11
	provides a full automated launch to orbit!
[=]
	Program 11 needs two pieces of information, the altitude of the
	orbit we want, and what we want for our flight azimuth. We provide
	these two pieces of information in registers 1 and 2. Start by
	executing [V24]. In past tutorials we have used V21 to set register
	1. V24 allows us to change both register 1 and register 2 in one
	operation. Register 1 will prompt you for a value so
	execute: [01660]. Now register 2 will prompt for a value,
	execute: [00900].  Here is what these values mean. the 01660 will
	tell the GC that we want our altitude to be 166.0km. The 00900 that
	we entered into register 2 tells the GC that we want to fly a
	heading of 90.0 degrees, or due east.
[=]

	Next start the launch program with: [V37N11] The P field of the GC
	panel should now show that program 11 is loaded and the R flag
	should light up to indicate that the program is running. At this
	point the program is waiting for you to launch. Since this is a
	mission to the Moon, we do not want to launch until our RtA gauge
	reads 90.0, about 6 hours in the future. Use time compression until
	your RtA gets near 90.0.
[=]
	2. When your RtA guage hits 90.0 then <shift><L> to launch. Now
	just sit back and relax and watch the guidance computer do all
	the work. The guidance computer will do all the necessary pitch
	changes and will also perform staging at the appropriate times.
	At about 11 minutes after launch you should find yourself in a
	nice clean parking orbit at 166km altitude.
[=]
	3. Now that we are in orbit, we can get ready for the next step in
	our journey, Trans Lunar Injection (TLI), the guidance computer has
	us covered here too with program 15. Program 15 needs to know two
	things, first, what the apoapsis of our transfer orbit should be,
	and second, when to start the TLI burn. To setup the parameters
	start with: [V24], Register 1 is now ready for input, here we input
	our desired transfer orbit apoapsis: [00500] for an apoapsis of
	500,000km. Now regitser 2 is ready for input, this is the Moon
	angle that we want TLI to begin, enter: [14487] for 144.87 degrees.
	And lastly load and start program 15: [V37N15].
[=]
	At this point the computer is controlling the spacecraft. The GC
	will orient the spacecraft prograde and keep it oriented prograde
	from now until the end of TLI. You can watch the Ang gauge on the
	Moon information panel and when it gets to 144.87 degrees you will
	see the engine of the SIVB start. Now you can watch the Apo gauge
	and the Vel gauge increasing as the engine fires. The GC will cutoff
	the engine when the Apo gauge shows a reading of 500,000km.
[=]
	4. At GE 1:30:00 lets get set to jettison the launch vehicle. For
	the jettison we want to orient the spacecraft prograde. In past
	tutorials you had to do this orientation yourself, but the computer
	can perform this maneuver for you too. Execute [V37N31]. Program 31
	will orient the spacecraft prograde and keep it prograde. For launch
	vehicle jettison we actually do not want to keep it prograde since
	we want no rotation on any axis during jettison. So once the
	spacecraft is prograde, press the <p> key to pause the computer.
	Now the spacecraft should be in a stable attitude very close to
	prograde.
[=]
	Once the spacecraft is prograde and you stopped the computer from
	controlling the vehicle, press the <tab> key to arm the jettison
	pyros and then <shift><J> key to jettison the launch vehicle. Set
	the translation throttle to medium and turn on the Up thruster for
	5 seconds and then turn it off, this separates us from the
	launch vehicle.
[=]
	5. Now comes the long coast to the Moon. Go ahead and turn on max
	time compression. The simulator will revert to real time when we
	reach the Moon's SOI
[=]
	6. When we reach the Moon's SOI we will need to perform the same
	kind of course correction we did in the Apollo 8 tutorial. The GC
	does not currently provide a program for doing this course
	correction, but we will still be able to use if for spacecraft
	orientation.
[=]
	If your periapsis is greater then 265.0km then we need to burn
	towards the inside of the orbit. Execute [V37N35] and the GC will
	orient the spacecraft towards the inside of the orbit and hold it
	there. Now you can use the SPS or RCS thrusters to adjust your
	periapsis altitude to 265.0km.
[=]
	If your periapsis is less then 265.0km then we need to burn towards
	the outside of the orbit. Execute [V37N36] and the GC will orient
	the spacecraft towards the outside of the orbit and hold it there.
	Now you can use the SPS or RCS thrusters to adjust your periapsis
	altitude to 265.0km.
[=]
	7. LOI is still about 7 hours away, but we can already prepare for
	it. The guidance computer has an automated LOI program to help you
	here, program 16. Program 16 needs to know at what altitude you want
	for your lunar orbit, so execute this: [V21 00100] to request an
	orbit at 100km. Now start program 16: [V37N16]. Program 16 will
	orient the spacecraft retrograde and keep it there until the LOI
	process is complete.
[=]
	Now you can just use time compression until you get closer to the
	Moon. When your altitude is 50km above the current periapsis altitude
	you will see the GC start the SPS and will keep the SPS burning until
	your periapsis altitude is 100km, the altitude we set. The GC will
	still maintain a retrograde attitude since an oribit circularization
	burn is yet to come. The circularization burn will be automatically
	performed by program 16, so you can just sit back and relax. If you
	want you can execute [V16N10], this will let you see how long it will
	be until the spacecraft reaches periapsis. register 1 contains the
	hours, register 2 shows the minutes, and register 3 shows the seconds.
[=]
	As the spacecraft gets to periapsis, program 16 will again fire the
	SPS to circularize the orbit. Once the burn is done the GC will stop
	program 16 and you will again have control of the spacecraft. The
	computer generally does a pretty good job of giving you a nice clean
	circular obit at the desired altitude, but if you want to clean it up
	a little bit, you can use the RCS thrusters to make fine adjustments
	to your orbit at either periapsis or apoapsis.
[=]
	Feel free to play around in Lunar orbit as long as you like. Proceed
	onto the next step when you are ready to return to Earth.
[=]
	8. The computer was quite helpful getting us to the Moon and it can
	also be quite helpful to get us home again. Program 17 gives us an
	automated Trans Earth Injection (TEI) burn. To set this up we need
	to specify how much delta v we wish to use for our TEI burn.
	Exectue [V21 00960]. This will tell the GC that we want to add
	960m/s to our velocity for our TEI burn. Next excecute [V37N17] to
	start program 17.
[=]
	Once program 17 starts it will orient the spacecraft prograde and
	maintain a prograde orientation until the TEI burn is completed.
	Program 17 will start the SPS engine automatically when the
	spacecraft reaches the correct position for the TEI burn, and will
	shutoff the SPS engine when the requested delta v has been added to
	our velocity. You can watch the RtA gauge on the position panel and
	compare it to the Ra gauge on the Moon information panel, when these
	two are in sync is when the GC will ignite the SPS engine.
[=]
	9. After the TEI burn is complete, the GC will release control of
	the spacecraft and the mission now proceeds from step 12 in the
	Apollo 8 tutorial. When making the course correction at Earth SOI,
	you can use program 35 if you need to hold an inside orbit
	orientation, or program 36 if you need to hold an outside orbit
	orientation for the correction burn. After the correction burn is
	made you can use program 32 to reorient the spacecraft retrograde,
	remember to use the <p> key to pause the computer when you need to
	make the service module jettison maneuver.

