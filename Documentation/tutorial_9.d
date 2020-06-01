[c]	Landing on the Moon
[=]
	At this point you should have learned how to launch to orbit,
	perform spacecraft maneuvers, and fly the LM.  Now it is time
	to actually land on the Moon!  This tutorial assumes that you
	are in Lunar orbit with a LM and that you have a landing site
	set in the computer.  You can use either of the two mini-tutorials
	to help you get to this state:
[=]
[i4]
[lb]
[li]	Start from the Earth - tutorial_9a.doc
[li]	Start from the Moon - tutorial_9b.doc
[le]
[i-4]
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
	|--          F         U--|
	|-|                     | |
	|Z|                     | |
	| |                     | |
	| |                     | |
	| |                     | |
	| +==========|+Y========+ |
	+-------------------------+
[ee]
	1. It is best not to start your landing before UT 12:00:00.  The
	reason for this is that when landing is complete it will be in the
	late afternoon and you will be able to take some rest periods and
	a sleep period and be ready for surface exploratino the following
	day, this also helps to sync things better with your circadian
	rhythms so that you are not tired at the wrong times.
[=]
	But while you wait until the right time to start you can start 
	getting ready for the landing.  In order to make rendevous 
	easier when your return, start by placing the CSM into a known
	orientation.  I use the orientation shown here since 'U' will
	be facing the Lunar north pole. I know that I need to be north
	of the CSM when setting up my docking approach.  You can use
	any orientation you like, just be sure you remember what it
	is when it comes time for the rendevous.
[e-]
[=]
[=]
[er]
	+--------+
	|      P |
	|     16 |
	|   V  N |
	|  16 12 |
	| +99932 |
	| +03601 |
	| -00457 |
	+--------+
[ee]
	2. Next execute V16N12 so that the guidance computer will give
	you your location relative to the landing site.
[=]
	Register 1 shows your altitude, which is not important here.
[=]
	Register 2 shows your longitude difference from the landing site.
	When this number is positive you are east of the landing site and
	when this number is negative you are west of the landing site.
[=]
	Register 3 shows your latitude difference from the landing site.
	When this number is positive you are north of the landing site and
	when negative you are south of the landing site.
[=]
	Since the landing procedure starts well west of the landing site
	we can make a check on our target landing coordinates using this
	mode.  When register 2 gets to 00000 then register 3 sould also
	be 00000, or at least close to it, which indicates that you are
	directly over the landing site.  If register 3 is far from 00000
	when register 2 says you are over the landing site then your
	landing coordinates were not properly set, follow the steps in
	tutorial_9a.doc to reset your landing site and then wait for the
	next orbit to recheck it.
[e-]
[=]
[=]
[er]
	+--------+
	|      P |
	|     16 |
	|   V  N |
	|  16 12 |
	| +99872 |
	| -06001 |
	| -01262 |
	+--------+
[ee]
	3. When register 3 shows that you are 60 degrees west of the landing
	site (-06000) then it is time to begin the landing process.
[=]
	Press <shift><m> to transfer to the LM.  It takes about 45 minutes
	to transfer to and power up the LM, so feel free to use time 
	compression to speed the process up.
[=]
	Once you are in the LM there are two additional things to do, first
	execute V16N52 so that the LM guidance computer will give you your
	position related to the landing site (similar to mode 12 in the CSM
	guidance computer).  Also press <shift><.> to activate the docking
	radar so that during the undocking/separation process we will know
	where we are in relation to the CSM.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 52  |
	|  99904.2   155.026  -51.3631|
	+-----------------------------+
[ee]
	4. Keep an eye on register 2 of the guidance computer, this shows
	our relative longitudinal position to the landing site.  We want
	to undock when this gets to 155 degrees east of the landing site.
	When register 2 shows you in this position, press <shift><u> to
	undock from the CSM.  Undocking will take about 1 minute.
[=]
	During the undocking countdown, execute V16N63 so that you will
	be able to get your position relative to the CSM in meters.
[e-]
[=]
[er]
	+-----------------------------+
	|   0.0008   -0.0004    1.8996|
	|   0.0001   -0.0000    0.1000|
	+-----------------------------+
[ee]
	We want to keep our eyes on the bottom 6 numbers on the guidance
	computer panel, these give our position relative to the docking
	port on the CSM.  We are mostly interested in register 12, which
	shows our distance and right below it in register 15, which is our
	relative velocity.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   0.4860   -0.3446   30.0942|
	|   0.0040   -0.0032    0.0972|
	+-----------------------------+
[ee]
	5. Now we need to perform some separation maneuvers so that there
	will be no risk of either running into the CSM or damaging it with
	rocket exhaust when it comes time to fire the descent engine.
[=]
	Be sure your translation throttle is set to minimum 'TTH:vv'.  Keep
	an eye on register 12, when it shows you at a distance of 30.0 meters
	press the <d> key to engage the down thruster.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   1.6765   -1.4208   68.4282|
	|   0.0087   -0.0087    0.3001|
	+-----------------------------+
[ee]
	6. Now watch register 15, or Z velocity.  When register 15 is showing
	a velocity of 0.3000 or more press the <d> key to turn off the
	down thruster.
[e-]
[=]
[=]

	7. Now to prepare for the next maneuver.  First execute
	V37N32, this will start the retrograde orientation program.  While
	the guidance computer is adjusting the orientation set the axis
	display to prograde mode by pressing the <]> key until the axis
	display shows "LOOKING PROGRADE".  Next set the precision axis
	display to prograde mode by pressing <.> until the precision axis
	display shows "LOOKING PROGRADE".  Next execute V16N52 so that
	the guidance computer will give us positional data relative to the 
	landing site.  Lastly set the translation throttle to medium 'TTH:--'
	and the rotation throttle to medium 'RTH:--'.
[=]
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
	|--L         U          --|
	|a|                     | |
	|n|                     | |
	|o|                     | |
	|r|                     | |
	|m|                     | |
	| +==========|inside====+ |
	+-------------------------+
[ee]
	8. Wait until the guidance computer is finished orienting the 
	spacecraft retrograde, the 'U' flag on the axis display will be
	exactly centered on the display.
[=]
	Once the spacecraft is oriented retrograde, use the roll controls
	<numpad><7> and <numpad><9> to roll the spacecraft so that the
	forward face 'F' is towards the top of the axis display.  Cross
	check with the precision axis display and be sure the 'F:' has
	a number as close to 0.00 in the 'Norm' column as you can get it.
[=]
	We will be maintaining this orientation until we get into powered
	descent.  By leaving the computer running P32, the computer will
	do all the work to keep this orientation for you.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 32      V 16      N 52  |
	|  99879.7   105.008  -34.2210|
	|   0.0401  -1470.58   705.016|
	+-----------------------------+

[ee]
	9. The second separation maneuver occurs when we are 105 degrees
	east of the landing site.  Keep an eye on register 2 and when it
	reads 105.0 press the <f> key to engage the forward translation
	thruster.  Your goal with this maneuver is to increase your ROC
	velocity by 1.0m/s.  So take note of the number in register 4, add
	1.0 to this number.  When you see this adjusted number in register
	4 then press the <f> key again to stop the forward thruster.
[=]
	In the sample, my ROC is 0.0401, so I would stop the forward
	thruster when register 4 shows 1.0401 or higher.
[e-]
[=]
[=]
	10. Since we are performing an in-plane landing in this tutorial,
	no plane change maneuver is required, so we can just sit tight
	for awhile until we get to the point of Descent Orbit Insertion (DOI)
	which occurs 165 degrees west of the landing site.
[=]
	While waiting until you get to the point of DOI, just double check
	that your translation throttle is set to medium 'TTH:--' and your
	rotation throttle is set to medium 'RTH:--'.  Also press the
	<shift></> key to set your radar data to 'DSN', soon we will be
	too far from the CSM for it to give us usable location data.
[=]
	Since DOI is some time ahead of us, go ahead and use time compression
	to speed things up.  Keep an eye on register 2, take it out of time
	compression when you get to around -155, which will occur at around
	ME: 1:42:00.
[=]
[=]
[er]
	+-----------------------------+
	|   P 32      V 16      N 52  |
	|  98976.3  -165.055  -52.7802|
	+-----------------------------+
[ee]
	11. We now need to perform the descent orbit insertion (DOI) burn.
	This burn will lower the periapsis of our orbit from 100km where it
	is now to 20km.  When register 2 shows you at -165.0 degrees from 
	the landing site, press <shift><i> to engage the descent engine.
	This will engage the engine at 10% thrust, which we will leave at
	this level.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 32      V 16      N 52  |
	|  98937.2  -168.930  -53.1344|
	|  -1.3034  -1609.69  -124.541|
	|  -0.0319   -0.0618    0.6449|
	|     RUN                     |
	|  3562.19    0.0131   89.9962|
	|  20.0173   98.9638   6839.40|
	+-----------------------------+
[ee]
	12. During the burn keep an eye on register 13, which shows the
	orbit periapsis.  When it gets to 20.0 press the <i> key to stop
	the descent engine.  If your periapsis is between 20.0 and 20.5
	then you are good to go for landing.  If you are not too far from
	this range then you can use the up/down thrusters to adjust it.
[=]
	The DOI burn should last just over a minute on the BU clock.
[=]
	It will take close to an hour before we get to the point of
	Powered Descent (PDI), so now is a good time to review the rest
	of the landing since after PDI you will be very busy until touch
	down.
[e-]
[=]
[=]
	The landing itself begins at PDI and is divided into three
	stages:
[=]
[lb1]
[li]	Braking phase - This phase begins at PDI and ends at pitch 
	over.  This phase reduces the spacecraft's velocity from
	the orbital speed of 1700+m/s down to about 100m/s.
[li]	Approach phase - This phase begins at pitch over and ends
	a few hundred meters above the surface of the Moon.  During
	this phase all remaining lateral velocity is reduced to zero
	and the LM positioned over the desired point of landing.
	Vertical velocity is generally also reduced in this phase.
[li]	Landing phase - Final descent and touch down occur in this
	phase.  Vertical velocity is reduced to execute a safe landing.
[le]
[=]
[=]
	If you have not done so, now would also be a good time to
	review the tutorial on aborts, just in case an abort becomes
	necessary.
[=]
[=]
	This is also a good time to get to know the deceleration
	schedule. Take a look at this table:
[=]
[tb]
	| >>>>>>>> | >>>>>>>> | >>>>>>>>>>>>> |
	| Altitude | Velocity | Decelleration |
	| 1715     | 40       | 0.50          |
	| 505      | 20       | 0.50          |
	| 200      | 10       | 0.50          |
	| 100      | 5        | 0.15          |
[te]
[=]
	The way to read this table is that when your altitude hits
	the level in the altitude column then you should not be going
	any faster than the value in the velocity column, and then
	set your deceleration to the value in the third column.  So
	for example, when you hit 505 meters altitude above the Moon
	you should not be travelling any faster than 20m/s and then
	set your deceleration to 0.5 m/s.
[=]
	If you hapeen to hit the velocity goal of the next lower altitude
	before you get to that altitude, then set your acceleration to 0.0
	until you reach the next altitude checkpoint.  For example if you
	are down to 10m/s but at 300 meters altitude, then keep your
	rate of descent at 10m/s until you hit 200 meters and then reset
	your decelleration to 0.5.
[=]
	It is a good idea to memorize this table so that during the
	busy time of the final landing phase you do not have to look
	up where you should be.
[=]
[=]
[er]
	+-----------------------------+
	|   P 32      V 16      N 52  |
	|  20234.2   18.6318   -1.2153|
	|  -3.0606  -1670.50   217.766|
	|   0.0346   -0.1133   -0.6843|
	|     RUN                     |
	|  509.731    0.0130   89.9962|
	|  20.0993   98.9456   6839.58|
	+-----------------------------+
[ee]
	13. Keep watching V16N52 and register 10 in particular.  When
	register 10 is showing 510.0 or less it is time to initiate
	powered descent.
[=]
	Start by hitting <shift><i> to activate the engine, followed
	as quickly as possible pressing <f9> to raise the throttle
	to 90%
[=]
	The computer should still be running program 32, the retrograde
	program, so for a little bit still you can just let the computer
	fly the spacecraft.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 32      V 16      N 72  |
	|  20222.2    503210  -35918.2|
	|  -2.9511  -1661.34   236.254|
	|   0.0181    2.2958   -1.0864|
	|     RUN                     |
	|  673.137   12.9555   8720.85|
	|  503.110   1678.37   6718.46|
	+-----------------------------+
[ee]
	14. Execute V16N72, this will give us the most useful information
	from now until we land.  Most of the numbers in this mode are
	vital information for landing, so I am going to go over them all:
[=]
[lb2]
[li]	Register 1 - Your altitude in meters
[li]	Register 2 - Distance East of the landing site in meters.  If
	this number is negative then you are West of the landing site,
	or in other words you passed it.
[li]	Register 3 - Distance North/South in meters from the landing
	site.  When this number is positive you are North of the landing
	site and when negative you are South of it.
[li]	Register 4 - Vertical velocity in meters/second.  When this is
	negative you are moving towards the surface and when positive you
	are moving away.
[li]	Register 5 - East/West velocity in meters/second.  When negative
	you are moving East to West, when positive you are moving West
	to East.
[li]	Register 6 - North/South velocity in meters/second. When positive
	you are moving South to North, when negative you are moving North
	to South.
[li]	Register 7 - Delta V for vertical velocity, or how many
	meters/second your vertical velocity is changing.
[li]	Register 8 - Delta V for East/West velocity in meters/second.
[li]	Register 9 - Delta V for North/South velocity in meters/second.
[li]	Register 10 - The number of seconds of fuel remaining at your
	current burn rate.  When this hits zero, you are out of fuel.
	This is the number to watch to know how much time you have left
	before you need to be on the ground.
[li]	Register 11 - The current fuel burn rate in kg/second.
[li]	Register 12 - The amount of fuel remaining in kg.
[li]	Register 13 - The distance remaining to the landing site in km.
[li]	Register 14 - While registers 4 through 6 give you component
	velocities along specific vectors, the number in register 14
	gives your true velocity along the path of flight.  This is the
	number you need to watch to determine when it is time for
	pitch-over.
[le]
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 32      V 16      N 72  |
	|  18227.3    300541  -12879.2|
	| -38.3613  -1327.80   114.196|
	|  -0.5030    2.6411   -0.7224|
	|     RUN                     |
	|  538.137   12.9555   6971.85|
	|  301.914   1333.33   4149.93|
	+-----------------------------+
[ee]
	15. Keep an eye on register 4.  When it hits -38 we will need
	to disengage the guidance computer and begin controlling the
	descent ourselves.
[=]
	Press the <p> key to put the guidance computer into pause and
	then hit <up arrow> several times to pitch forward.  When 
	register 7 shows a delta V at zero then press the <down arrow>
	key to stop the pitch movement.
[=]
	From this point until the pitch over at the end of the braking
	phase you need to manually use pitch control to keep your
	vertical speed around -38.0.
[=]
	Once you have your rate of descent stabilized, execute V00 to
	unload program 32 from the computer, this will prevent accidentally
	re-engaging the retrograde program.  Then execute V16N72 to
	once again show the landing data.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 32      V 16      N 72  |
	|  2887.43   2940.70   108.083|
	| -38.3043  -90.8683   -0.2862|
	|   0.0298    3.8956   -0.0049|
	|          IDL                |
	|  140.137   12.9555   1815.55|
	|   4.1245   98.6121   2310.78|
	+-----------------------------+
[ee]
	16. During the braking phase keep an eye on register 14, your
	true velocity.  When it gets down to 300 you will be coming up
	on pitch-over.
[=]
	Also keep an eye on registers 3 (North/South position) and
	register 6 (North/South velocity).  When the position nears
	zero, use the <left arrow> and <right arrow> keys to 
	minimize your North/South velocity.  Once your North/South
	velocity is near 0.00, then just keep it there throughout
	the rest of the landing by making small adjustments using
	the left and right arrows.  If the signs of register 6 and
	9 are oppostite then you will be moving towards a velocity
	of 0.  More than likely sometime near the end of the braking
	phase your North/South velocity will have gotten close enough
	to zero that you can finish nulling it out.  Be careful not
	to over-focus on this tho!
[=]
	When Register 14 is at or below 100.0 then it is time for
	pitch-over, this will occur around 9:00 minutes into powered
	descent.  This maneuver is a bit tricky and requires you
	to keep an eye on a number of things, so take a deep breath,
	life gets interesting from here until we touch down.
[=]
	The purpose of pitch-over is to transition our flight from the
	braking to the approach phase of the landing.  During the
	braking phase we are pitched back around 70 degrees from vertical,
	the pitch-over maneuver is done to change this angle to 30
	degrees from vertical.  Since we will be going through a
	considerable change in attitude, more of our rocket thrust will
	be angled downward, providing more lift, in order to maintain
	our descent rate we will have to throttle down during the
	pitch-over maneuver.
[=]
	When register 14 is at or below 100.0, use the <up arrow> key
	a couple times to set a pitch forward rate of 2.0 degrees/second.
	Watch the acceleration in register 7 and throttle down as needed
	to keep the acceleration near 0 and your descent rate at around
	-38.0.  You will also need to watch the 'u/r' guage, you will
	want to stop the pitch over maneuver when 'u/r' is at 30.0.
	To stop the pitch over you will press the <down arrow> key until
	the 'PT:' rate indicator shows 0.0.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 32      V 16      N 72  |
	|  2163.62   1655.09   102.158|
	| -38.7176  -53.7040   -0.3231|
	|   0.0337    0.9596   -0.0005|
	|          IDL                |
	|  289.558    5.7580   1667.28|
	|   2.7266   66.2063   2306.05|
	+-----------------------------+
[ee]
	17. At the end of pitch-over you are probably not far above the
	deceleration altitude of 1715 meters.  If you do happen to fall
	below the deceleration altitude before pitch-over is complete,
	be sure to follow the deceleration schedule outlined earlier in
	this tutorial.
[=]
	At this point you are in the approach phase and your main goal
	here is to stop all North/South motion as well as East/West
	motion avove the desired touch down point.  At this point you
	should press <shift><,> to activate the landing radar.
[=]
	There are two things that will happen during this phase, one
	is that you will hit the deceleration altitude and need to begin
	following the deceleration schedule.  You will also need to pitch
	forward to stop East/West motion once register 5 nears 0.0.  You
	should have all East/West and North/South motion at minimum before
	you are below a couple hundred meters.
[e-]
[=]
[=]
[er]
	+-----------------------------+
	|   P 32      V 16      N 72  |
	|   0.0000   445.443   60.3343|
	|   0.0000    0.0000    0.0000|
	|   0.0000    0.0000    0.0000|
	|          IDL                |
	|  186.623    4.3185   805.936|
	|   0.4495   1061.50   3211.27|
	+-----------------------------+
[ee]
	18. As you get close to the Lunar Surface make sure your descent
	rate is below 3.0ms.  Once contact with the Lunar surface is made
	the descent engine will automtically be switched off and the 'LCT'
	lamp on the annunciator panel will light.  Take a deep breath!
	If you got down and are still in one piece, Congratulations! and
	if not, well, give it another go, landing on the Moon is not an
	easy task, but once you got it down you will have a whole Moon
	to go and explore.
[e-]
[=]
[=]

