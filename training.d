[c]	Lunar Mission Simulator
[c]	by
[c]	Michael H. Riley
[=]
[c]	Pilot Training Handbook
[c]	=======================
[=]
	LMS is a complicated program with a fairly steep learning curve.  It is 
	recommended that you go through this training series before attempting your
	first landing.  This training series will familiarize you with all the
	various controls of the spacecraft as well as how to perform essential
	maneuvers.
[=]
	The lessons in this training course assume that you are using the advanced
	instrument panels and the guidance computer instead of the INS display.  If
	you are using the AMS panel or the INS instead of the guidance computer then
	you will need to translate some if the information provided in these tutorials.
[=]
[h2]	Lesson 1
[=]
	In this first lession we will transfer to the LM and undock, move about 100
	meters north of the CSM and then approach and dock.
[=]
	Remove or rename any lms.sav file that may be in your game directory.  We will
	want to start out with a fresh game.
[=]
	Upon starting LMS, you will be asked for a target landing site.  Since we will
	not be landing in this lesson, the values here are irrelevent, you can just enter
	0 for both the latitude and longitude.
[=]
	After specifying the landing site, you will find yourself in the CSM.  As the CMS
	is not controllable in this simulation, there are very few instruments on the panel.
	A large orbital map will be displayed on the left of the screen, the current time
	in UTC will appear near the top on the right and the INS display will appear in the
	middle of the right panel.
[=]
	Ordinarily you would use the data from the INS to decide when to transfer to the
	LM, since we are not attempting a landing in this lesson, we can transfer to the
	LM at any time.  Go ahead and press the <M> key to transfer to the LM.  A message
	will appear in the message window showing that we are moving to the LM and how
	many seconds this will take to complete.  You can press <shift><5> to speed this up.
[=]
	After the move is complete you will be looking at the LM instrument panel.  The
	LM instrument panel contains a lot of information, but we only need to look at a
	couple of the instruments for now.
[=]
[er]
	+------+
	|MB: 45|
	|EF: 91|
	|IN:  0|
	|      |
	| LM   |
	+      |
	|RK:  0|
	+------+
[ee]
	Lets start by looking at the pilot information panel.  This is located on the 
	lower right corner of the instrument panel.  This instruments shows the metabolic
	information for the pilot.  the MB value shows the current Metabolic Rate of the
	pilot.  The higher this number the faster your heart is beating.  A high
	metabolic rate has a negative impact on efficiency, so it is a good idea to keep
	this number as low as possible.  When we moved from the CSM to the LM we had
	some physical exertion, this is why the metabolic rate has risen from its base
	rate of 30.  The metabolic rate will decrease over time so long as you are not
	performing any strenuous tasks.
[=]
	The EF indicator shows the efficiency of the pilot.  The higher this number the
	more efficient the pilot is at performing tasks.  This number will get smaller
	with a higher metabolic rate or increased injury.  The lower this number is the
	longer it takes for the pilot to perform a task.  So with a high efficiency, the
	simulator will respond quickly to your keypresses, when efficiency is low then
	it takes longer for your key presses to be performed.  Try to avoid time critical
	tasks while your efficiency is low.
[=]
	IN represents total pilot injury.  There are actually two injury values, hard 
	injury represents injuries sustained by the pilot from a hard landing or moving
	too quickly over rough lurrain.  Soft injury is increased while the pilot is awake
	and is used to simulate fatique from lack of sleep.  Sleeping will reduce soft
	injury.  The value shown in IN represents the accumulation of both hard and soft
	injury.  The higher the injury value, the lower your efficiency becomes.  So 
	remember to sleep each day to reset your soft injury.  Hard injuries will stay
	with you throughout the rest of the simulation, so you should try to avoid those.
[=]
	Next below the metabolic information we see the letters LM, this tells us that the
	pilot is currently located in the LM.
[=]
	The last value in this instrument is RK, which shows how many kilograms of samples
	have been loaded onto the LM.
[e-]
[=]
[er]
	+--------------------+
	|                    |
	|        DCK         |
	|                    |
	+--------------------+
[ee]
	The next place of interest is in the lower left of the panel where you will see a
	mostly empty box with the letters DCK in it.  This is the annunciator panel 
	and will show various status indicators for the spacecraft.  The DCK that is currently
	showing indicates that the LM is currently docked with the CSM.  After we undock from
	the CSM, this inidcator will go out.
[e-]
[=]
[er]
	+----+
	| LAN|
	| DOK|
	| DSN|
	+----+
[ee]
	Now just left of the middle of the screen you will see the radar indicators.  This
	instruments shows which of the three radar systems is feeding information to the INS.
	Currently no radars are on, so press the '>' key in order to turn on the docking radar.
	After turning on the docking radar a '@' symbol will appear before the DOK indicoator,
	showing that the docking radar is the currently active radar.
[e-]
[=]
[er]
	+-----------------------------+
	|   P 00      V 00      N 01  |
	|   0.0000    0.0000    0.0000|
	|   0.0000    0.0000    0.0000|
	|   0.0000    0.0000    0.0000|
	|          IDL                |
	|   0.0000    0.0000    0.0000|
	|   0.0000    0.0000    0.0000|
	+-----------------------------+
[ee]
	And now for the somewhat scarier guidance computer display.  This is located in the
	central bottom portion of the instrument panel.  The computer can display all kinds
	of different information depending on what program it is running.  Currently you
	can see the IDL flag showing, this indicates that the computer is currently idle,
	not running anything.  On the top line of the computer you see P 00, V00, and N 01
	these three values select which operation the computer is to perform.  The P00 V00 N01
	program is equivalent ot the POS^ABS mode from AMS.
[e-]
[=]
[er]
	+-----------------------------+
	|   P 00      V 00      N 01  |
	|   REG  1    REG  2    REG  3|
	|   REG  4    REG  5    REG  6|
	|   REG  7    REG  8    REG  9|
	|          IDL                |
	|   REG 10    REG 11    REG 12|
	|   REG 13    REG 14    REG 15|
	+-----------------------------+
[ee]
	The rest of the numbers on the computer display are referred to as registers.  The 
	computer documentation will explain what register shows what information for any
	given program.  To the right you can see what the register mapping is.  For this
	training mission we will only really be concerned about REG 3 and REG 6.  For this
	training mission we need to be running program P00 V00 N13.  P is already 00 and
	V is also already 00, so we do not need to change those.  We need to change N
	however to show 13.  This can be accmoplished by hitting these keys: <n><1><3>.
	The N regiser should now show 13.
[e-]
[=]
	Now to start the selected program running, hit <g>.  The IDL flag should disappear
	and now you should have a RUN flag showing.  You should also have seen that some
	of the numbers on the display have changed.  We are interested in REG 3, which 
	should now show the number 19.0000, This indicates how many meters the LM is from
	the CSM base.  While docked, this will always show 19 meters.  The other number
	we are interested in is in REG 6, which currently is 0.0000, indicating that we
	are not moving in relation to the CSM.
[=]
	We are now ready to undock.  Press the <U> key.  You will see a message display
	in the center of the screen indicating that the undock process has begun and 
	the number of seconds it will take to complete.  Undocking takes 60 seconds.  If
	you do not want to wait the full 60 seconds you can use one of the time acceleration
	keys (<@><#><$><%>) to speed it up.
[=]
	Once undocking has been completed you should see that REG 3 of the computer
	display is now becoming larger, as we move away from the CSM.  REG 6 will show
	a number similar to 0.0995 which is the speed we are moving away from the CSM.
	If this number were negative, then it would indicate that we are moving towards
	the CSM.
[=]
	For now we will wait until our distance from the CSM is 50 meters at which
	point we will be ready to perform the first separation maneuver.
[=]
[er]
	+--------------------+
	| F/B  PT: 0.0 RTH:^^|
	| L/R  RL: 0.0 TTH:vv|
	| U/D  YW: 0.0 PRP:99|
	+--------------------+
[ee]
	While you are waiting for the LM to reach 50 meters, take a look at the RCS control
	panel.  This is located on the left edge of the screen just above the annunciator
	panel.  This panel shows all the information related to the RCS system.  The F/B,
	L/R, and U/D indicators show any RCS thrusters that are currently on.  For now they
	should all be off.  The PT:, RL: and YW: indicators show the Pitch, Roll, and Yaw
	rates, which also should all be 0.0 at this point.  The RTH: indicator shows the
	RCS rotation throttle.  The ^^ indicator following RTH: indicates that the RCS
	rotation throttle is currently set to high.  Below RTH is the TTH: indicator, which
	shows the translation throttle setting.  The vv indicator following the TTH: indicates
	that the RCS translation throttle is currently set to low.  The last indicator on 
	this panel is PRP: which is the percentagle of RCS propellent remaining.
[e-]
[=]
	Keep an eye on REG 3 of the computer display.  Once it his 50 then press the <d>
	key to activate the RCS down thruster.  Once you activate the thruster you should
	see several things on the screen change.  First in the RCS control panel the U/D
	indicator should show a '>' symbol after the D, indicating that the down thruster
	is currently on.  In the annunciator panel, you should now see an RCS flag showing,
	indicating that an RCS thruster is currently on.  And you should also notice that
	REG 6 of the computer display is now slowly getting larger, indicating that we
	are now accelerating away from the CSM.  REG 9 of the computer display should show
	a number similar to 0.001, this is the amount of acceleration.
[=]
	Leave the Down thruster on until you see the number in REG 6 exceed 0.3.  When
	REG 6 shows 0.3 or higher, press the <u> key to turn off the down RCS thruster.
	When you turn off the thruster you should see the '>' symbol disappear from the
	U/D indicator in the RCS control panel, the RCS flag will disappear from the
	annunciator panel and the number in REG 9 should return to 0.0000.
[=]
	We have now completed the first separation maneuver.  Now for this training mission
	we will redock with the CSM.  Keep an eye on the number in REG 3 and wait for it to
	exceed 100.  After this number exceeds 100 press the <=> key to set the RCS
	translation thruster to medium.  In the RCS control panel you should now see a --
	flag following the TTH: indicator, showing that the translation throttle has been
	set to medium.
[=]
	Now press the <u> key to activate the RCS up thruster.  You should now see that the
	U/D display in the RCS control panel shows a '<' symbol before the U, indicating 
	that the RCS up thruster is on.  The annunciator panel should show the RCS flag
	indicating that an RCS thruster is on, and REG 9 should show a number similar to
	-0.0115, indicating that we are now accelerating in the southerly direction.
	Wait until REG 6 shows a number around -0.3 and then hit the <d> key to turn off
	the RCS up thruster.
[=]
	You should now see the number in REG 3 getting smaller.  If you have not accidentaly
	hit any other thrusters then you should be in line to redock with the CSM.  When
	the number in REG 3 hits 18 the docking process will begin.  You will see in the
	central message area the docking message and the number of seconds until the
	docking operation is completed.  Once docking is complete you should again see the
	DCK flag showing in the annunciator panel.
[=]
	Once docking is complete, press the <M> key to return to the CSM, which will end
	the mission.  Congratulations!  Your first space flight is complete.
[=]
[h2]	Lesson 2
[=]
	In the last lesson we undocked from the CSM, moved away and redocked.  During the
	last lesson we remained in perfect alignment for docking.  When returning from the
	lunar surface, you will never be prefectly aligned.  This lesson will teach you
	the following:
[=]
[lb]
[li]	How to use the RCS translation thrusters to align with the docking port
[li]	How to read positional information on the docking radar
[li]	Understand all the information provided by the P00V00N13 program.
[le]
[=]
	To start off, using what you learned in lesson 1, undock from the CSM and move
	out to 100 meters from the CSM and hold.  Throughout this lesson you will need
	to use small amounts of RCS up/down thrust to maintain your position around 100
	meters north of the CSM.
[=]
[er]
	+-------------+
	|    dock     |
	| +---f|----+ |
	| |    v    | |
	| |         |l|
	|--    *    --|
	|r|         | |
	| |    ^    | |
	| +----|b---+ |
	+-------------+

[ee]
	After you have setup your position 100 meters north of the CSM lets take a
	look at the docking radar.  This instrument is located in the upper middle
	section of the screen.  As shown on the right, this is what the docking
	radar will look like when you are properly aligned for docking.  In order for
	this instrument to give you valid data you must be within 200 meters of the
	CSM and the docking radar must be on.  The 'f', 'b', 'r', and 'l' indicators
	around the edge of the radar are reminders of which RCS thruster is needed
	to move in a given direction, given that the LM is properly oriented, which
	it is at the start.  The 'v', '^', and '*' indicators inside the radar provide
	position and orientation information related to alignment.  You could also see
	a '+' or 'X' indicator as well.  If the '+' and 'X' are at the same place on
	the radar display you will see the '*' symbol.
[e-]
[=]
	During this lesson we are only going to worry about positional alignment.  From
	undocking we are already oriented correctly, so long as you do not activate any
	pitch, roll, or yaw commands, you will remain in proper orientation for docking.
[=]
	Set the RCS translation throttle to medium, if it is not already.  <-> or <=>
	keys to change the RCS translation throttle.  Also set the computer to P00 V00
	N 13 mode.
[=]
[er]
	+-----------------------------+
	|   P 00      V 00      N 13  |
	|   REG  1    REG  2    REG  3|
	|   REG  4    REG  5    REG  6|
	|   REG  7    REG  8    REG  9|
	|          IDL                |
	|   REG 10    REG 11    REG 12|
	|   REG 13    REG 14    REG 15|
	+-----------------------------+
[ee]
	Now lets take another look at the guidance computer map.  P00V00N13 displays
	information in the first 9 registers.  This program also uses aboslute coordinates
	when it provides information.  This means that it is providing 3d positional 
	information between the LM and CSM irregardless of position around the moon.
	REG 1 shows the relative position along the X coordinate, REG 2 shows the
	relative position along the Y coordinate and REG 3 shows the relative position
	along the Z coordinate.
[e-]
[=]
	REG 4 shows the relative velocity difference between the LM and CSM along the X
	coordinate.  REG 5 shows the relative velocity difference along the Y coordinate.
	And REG 6 shows the relative velocity difference along the Z coordinate.  For
	docking REG 4 and REG 5 need to have near zero values, while REG 6 needs to be
	between -0.2 and -0.4.
[=]
	REG 7 shows your absolute acceleration along the X axis, REG 8 shows your
	absolute acceleration along the Y axis and REG 9 shows your absolute
	acceleration along the Z axis.  If any of these values are not near zero that
	means your relative velocity is likely changing.
[=]
	Ok, at this point REG 1 and REG 2 should be near zero while REG 3 should be 
	showing your position 100 meters or so north of the CSM.  Your RCS translation
	throttle should be set to medium.  Turn on the right thruster with the <r>
	key.  Watch the value in REG 5, it should now be increasing.  Turn off the 
	right thruster (with the <l>) key when this number is around 0.1.  You should
	now notice several things, first the number in REG 2 should be increasing as you 
	move to the right of the CSM.  On the docking radar display you should shortly
	see that the '*' symbol is gone and replaced with a 'X' symbol and there should
	be a '+' symbol drifting slowly towards the right of the radar.  We are no
	longer aligned.
[=]
	Watch the number in REG 2 and when you see it get to 10.0000 then use the left
	RCS thruster <l> and reduce your Y velocity (REG 5) to zero.  When you get close
	you can adjust the RCS translation throttle to low to have less impact on your
	velocity.
[=]
	Now you are 10 meters to the right of the CSM.  The '+' on the radar is all the
	way to the right.  The 'l' on the edge of the radar is the reminder that you 
	must move to the left to get back to center.  Make sure your RCS translation
	throttle is set to medium and activate your left thruster <l> until your
	Y velocity (REG 5) is -0.1 and then turn off the thruster with <r>.
[=]
	Keep an eye on the radar display and REG 2 on the computer.  As you come back
	into alignment on the Y axis you will see the '+' symbol move back towards the
	center and REG 2 will work its way back towards 0. As you near the center you
	will need to slow your velocity using the right thruster <r>, and remember
	to turn off the right thruster you use <l>.  Using combinations of right and
	left thrusters try to get the '+' back to the center and REG 2 as near zero
	as you can get it.  Note also that when REG 2 is as near zero as possible 
	you also want REG 5 to be near zero, indicating you are no longer moving.
[=]
	With all this use of the left and right thrusters you have been making subtle
	changes to your orbital velocity, and thanks to orbital mechanics very likely
	your X axis alignment is now off.  This can be seen in REG 1.  It may not
	have moved much, but it is certainly no longer the near zero you started at.
	Also check REG 4 for your velocity along the X axis.  In the same way that
	you used the left and right thrusters to manipulate your Y axis alignment, you
	can use the forward and back thrusters to modify your X axis alignment.  At
	this point using combinations of all 4 thrusters try to get REG 1 and REG 2
	as close to near zero as you can.  REG 5 and REG 6 should also be near zero
	when REG 1 and REG 2 are.  Ideally you do not want to see the '+' indicator
	on the docking radar, you want to see the '*' in the center.
[=]
	From a more numerical standpoint, you are aligned with the docking port if
	both REG 1 and REG 2 are in the numberic range of -0.5 to +-.5.  As long
	as you can keep these two numbers in that range, you are good to dock.
[=]
	After you have gotten yourself back to center, repeat the procedure using
	a different thruster, move 10 meters off center and then move back to center.
	Always keep an eye on your REG 3 as well, keep it around 100 meters throughout.
	this exercise.
[=]
	Once you have a good feel for positional realignment, get back to center and
	then use your up thruster to redock with the CSM.  Keep an eye on the docking
	radar while accelerating, you should see on the top of the left and right 
	frame '-' symbols when you are approaching too slowly and '+' symbols if you
	are approaching too quickly.  Your REG 6 velocity should be between -0.2 and
	-0.4 for proper docking.  Also make sure while closing to keep REG 1 and REG 2
	as near zero as you can.  You cannot avoid drift, so just make small corrections
	on your way back to the CSM.
[=]
	After you have redocked and moved back to the CSM this lesson is complete.
	Hopefully at this point you are well acquanted with the docking radar and 
	P00V00N13 mode of the computer.  Take a break and then you will be ready
	to move on to the next lesson, which will cover orientation with relation
	to the docking port.
[=]


