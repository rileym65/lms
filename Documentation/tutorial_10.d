[c]	Lunar Surface Operations
[=]
	In this tutorial we are going to go over Lunar surface operations.
	This tutorial assumes that you have just landed on the Moon.
[=]
	When first landing on the moon it is a good idea to take some
	rest actions so that your crew is all bright eyed and bushy tailed
	and ready to spend 8 hours working on the moon.
[=]
	1. Start by taking a short rest break with <shift><8>.  This allows
	the crew to rest for 2 hours.  Think of this as time to secure
	the spacecraft after landing, performing systems checks and to be
	sure a stay on the surface can proceed.
[=]
[=]
	2. Next lets a take a sleep session by pressing <shift><0>.  This
	allows the crew to sleep and regain their effeciency after the
	hard work of landing.
[=]
	3. Followed by another 2 hour break with <shift><8>.  Think of this
	one as the crew having a meal and preparing the spacecraft for
	the EVA to come.
[=]
[=]
[er]
	+-------+
	|  @SS  |
	+-------+
[ee]
	4. And now we are ready to prepare for the EVA itself.  First you
	will need to put on your EVA suit by pressing <shift><s>.  
	Donning the EVA suit takes about 20 minutes, so go ahead and
	speed up time until this task is done.  The SS flag in the lower
	left of the control panel will have an '@' symbol before it
	indicating that your EVA suit is on.
[e-]
[=]
[=]
[er]
        +------+
	|MB: 39|
        +------+
[ee]
	5. Notice that while putting on your EVA suit that your metabolic
	rate, MB on the right side of the panel, has been climbing.  It
	is important to keep an eye on your metabolic rate for two 
	reasons, first, increased metabolic rate decreases your efficicency,
        which translates into slower response to actions, which is not
	too critical to surface operations, but can be a real problem
	when needing to make quick control changes during flight.  The
	second effect from increased metabolic rate is a higher rate of
	oxygen use, lowering your EVA time.  Oxygen use begins to
	skyrocket when your metabolic rate exceeds 60, so when your
	metabolic rate is getting up their, take a break from any actions
	and allow it to come back down.  30 is the baseline metabolic rate.
[e-]
[=]
[=]
[er]
	+-------+
	|  @PL  |
	+-------+
[ee]
	6. Now that your EVA suit is on, it is time to put on the PLSS, or
	Portable Life Support System.  This is the backpack the astronauts
	wore that provides them with temperature regulation, oxygen and
	water during the EVA.  To put on your PLSS press <shift><p>.
	Putting on the PLSS takes about 35 minutes, so go ahead and activate
	time compression to speed things up.  When your PLSS is on you
	will see an '@' symbol before the PL flag in the lower right
	of the panel.
[e-]
[=]
[=]
[er]
	+------+
	|  CB  |
	+------+
[ee]
	7. By the time your PLSS is on, you will notice your MB rate is 
	getting pretty high.  Luckily we get to mostly rest during the
	next step, which is to depressurize the cabin.  Press <shift><c>
	to depressurize the cabin.  This process will take about 5 minutes.
	When the cabin is fully depressurized the '@' symbol before the 
	CB flag in the lower right of the panel will disappear.  You
	are now all set to step outside.
[e-]
[=]
[=]
	8. To step outside the LM, press <shift><m> to move outside.  Egress
	will take about 5 minutes, so go ahead and speed up time until you
	are outside.
[=]
	After you are out on the Lunar suface the screen will change to
	show the EVA panel.  Lets take a quick tour of this panel.
[=]
	On the left side you will have a large map showing you the lunar
	surface in your vicinity.  There is an '@' symbol in the center
	of this map, this is you.  The map is always centered on you and
	as you move about the lunar surface the map will scroll to keep
	you in its center.
[=]
	Will see various other symbols on the map:
[=]
[i4]
[lb]
[li]	m - This is the LM
[li]	O - Large crater
[li]	o - Medium crater
[li]	. - Small crater
[li]	* - Large rock
[li]	+ - Medium rock
[li]	, - Small rock
[li]	l - The LRV
[li]	_ - Laser reflector
[li]	f - Flag
[li]	" - Lunar surface experiments
[le]
[i-4]
[=]
	Each cell on the map represents about a 10 meter x 10 meter area.
[=]
	In the upper right corner is an axis display very similar to the
	ones seen in the CSM and LM.  Unlike the axis displays found in
	the CSM and LM, this axis display only shows down, therefore the
	up (U) face will always be in the middle and facing up, afterall
	you do not walk around with your head to the ground!  The left (L)
	and forward (F) faces will rotate around show which direction you
	are facing.  When first stepping out of the LM you will be facing
	north.
[=]
[er]
	+------+
	|  plss|
	|OXY:99|
	|BAT:99|
	|      |
	|CRT: 0|
	|CRY: -|
	+------+
[ee]
	Next is the plss info panel which shows four pieces of information:
[lb]
[li]	OXY - This is the amount of oxygen you have remaining in %.  Your
	PLSS normally contains 10 hours worth of Oxygen, but remember that
	your metabolic rate can reduce this time.  In general each 10% that
	you have remaining will give you 1 hour of EVA time.  There is no
	backup supply, so when this hits zero, you lose the ability to
	breathe!  So be back aboard the LM before letting this run out.
[li]	BAT - This is the amount of PLSS battery remaining.  A full charge
	will last about 10 hours.  Like oxygen, battery use will be higher
	if your metabolic rate is higher.
[li]	CRT - This shows how many samples are currently in your sample
	cart.  The sample cart can hold 10 samples.  While moving around
	on the surface you pull your sample cart behind you, this allows
	you to collect up to 10 samples before you must return to the LRV
	or LM to store your samples.
[li]	CRY - This shows what you are currently carrying, this will show
	as: '-' You are not carrying anything, 'S' you are carrying a
	sample, or 'B' you are carrying a sample box.
[le]
[e-]
[=]
[er]
	+------+
	|   lrv|
	|BAT:99|
	|BOX: 8|
	|ROK: -|
	+------+
[ee]
	Below the PLSS panel is the LRV status panel.  if the LRV has
	been deployed then there will be a '^' symbol in the upper left
	corner of this panel.  If this symbol is missing then the LRV
	is still stowed on the LM and needs to be deployed before it can
	be used.  The other information on this panel is as follows:
[lb]
[li]	BAT - The amount of battery remaining in %.  This in essence will
	let you know how much further you can drive.  The Mk I LRV, as
	found on the Apollo J has a range of 35km, so each 10% will give
	you 3.5km of travel.  The Mk II LRV, as found on the Apollo Mk II
	has a range of 200km, so each 10% will give you 20km.  If the
	battery has been damaged the available range will be decreased.
[li]	BOX - This tells you how many sample boxes remain.  Each mission
	has 8 sample boxes and each sample box can hold 30kg of samples.
	When the sample box becomes full you will need to transfer it to
	the LM before collecting more samples.  When you have run out of
	sample boxes you will no longer be able to store samples on the LRV,
	you can however still store samples in the LM.
[li]	ROK - This tells you how many kg of samples are in the current
	sample box.
[le]
[e-]
[=]
[er]
        +------------+
	|east: 104.69|
	|nrth:  12.60|
	|mode: ABS   |
	| thr:  0    |
	| spd:  0.0  |
        +------------+
[ee]
	Below the LRV panel is the EVA computer panel.  This panel gives
	you information about where you are and can operate in several
	modes:
[=]
[lb]
[li]	ABS - This gives you your abosolute longitude and latitude.
[li]	TAR - This gives your range in meters to the target landing site.
[li]	LM  - This gives your range in meters from the LM
[li]	LRV - This gives your range in meters to the LRV
[li]	PRI - This gives your range in maters to the primary sample site
[li]	SEC1 - This gives your range in meters to the first secondary
	sampling site.
[li]	SEC2 - This gives your range in meters to the second secondary
	sampling site.
[li]	SEC3 - This gives your range in meters to the third secondary
	sampling site.
[le]
[=]
	'thr' gives you your current movement speed setting, each
	number represents 10%, so if this shows 5, your throttle is
	set to 50%.  While walking this is essentially the speed you
	have selected to walk between standing still and being at a
	full run.  In the LRV this equates to actual throttle setting.
[=]
	'spd' tells you how fast you are moving over the Lunar surface
	in meters per second.
[e-]
[=]
	To the right of the EVA computer are the mission clocks.  The
	top three clocks are the same as you have seen in the CSM and
	LM.  The EV clock shows you how much time you have been on the
	current EVA.  the TE clock shows you the total EVA time that
	you have spent on this mission.
[=]
	To the right of the clocks is the metabolic panel and is the
	same as the one found in the LM.
[=]
	Now that you know what everything on the screen means, lets get
	to work.  For this EVA we will setup all the equipment and 
	collect a few samples.  Before actually beginnig work, make sure
	your metabolic (MB) rate is 30, just rest until it gets there.
[=]
[=]
	9. We will start by setting up the Lunar Surface Experiment package.
	While within 40 meters of the lm, press <shift><a> to unload the ALSEP
	equipment from the LM,  This step of setting up the surface
	experiments takes about 30 minutes.  When this step is complete
	the CRY indicator on the plss panel will show 'A'.
[=]
	The ALSEP equipment must be setup 150 meters or more from the LM.
	We will set it up north west of the LM so press <left arrow> to
	start turning, watch the axis display and press the <right arrow>
	when the 'f' is pointing towards the upper right corner of the 
	axis display, then press the <f3> key to beginning walking at
	30% speed.  This speed is selected because it will not increase
	your MB rate, and actually allow you MB rate to lower a little
	bit.  Press the <3> key to set the EVA computer to LM mode, this
	allows us to see how far from the LM we are.  When either the 
	east or nrth show 150, press the the <keypad 0> key to stop
	walking.
[=]
	When you are at the position where you want to setup the ALSEP
	and have stopped walking, press <shift><a> to begin setting up
	the ALSEP equipment.  This will take between 90 minutes and 2
	hours, depending on which version of the equipment you have.
[=]
	After the ALSEP is setup, return to where the LM is located.
	if you walked north west to setup the ALSEP, then press either
	the <left arrow> or <right arrow> to start turning and then
	the opposite arrow when the 'f' on the axis display is in the
	lower left corner of the display, press <f3> to begin walking
	back to the LM.  Press the <keypad 0> key when next to the LM.
[=]
[=]
	10. Next we will setup the laser reflector.  If your MB rate
	is above 30, then just rest until it is 30.  When ready to start
	setting up the laser reflector press <shift><l> when within
	40 meters of the LM to unpack it from the LM.
[=]
	the laser reflector must be setup 50 or more meters from the
	LM.  We will set it up 50 meters to the north of the LM.  Use
	the <left arrow> and <right arrow> keys to turn so the 'f'
	on the axis display is pointing to the right side of the panel
	and then press <f3> to begin walking.
[=]	When the EVA computer shows you 50 meters from the LM, press
	<numpad 0> to stop walking and <shift><l> to setup the laser
	reflector.  After the reflector is setup, return to the vicinity
	of the LM.
[=]
[=]
	11. Next we will setup the flag.  When within 40 meters of the
	LM, press <shift><f> to unpack the flag from the LM.  Like the
	laser reflector, the flag needs to be setup at least 50 meters
	away from the LM.  We will plant the flag 50 meters north east
	of the LM, so use the arrow keys to turn so the 'f' on the axis
	display is pointing towards the lower right corner of the panel
	and then press <f3> to begin walking.
[=]
	When you get to the place you want to plant the flag, press
	<numpad 0> to stop walking and then <shift><f> to plant the
	flag.  After the flag is planted, return to the vicinity of the
	LM.
[=]
[=]
[er]
	+------+
	|^  lrv|
	|BAT:99|
	|BOX: 8|
	|ROK: -|
	+------+
[ee]
	12. The last piece of equipment we need to setup is the LRV.
	The LRV takes quite an effort to setup so be sure your MB rate
	is at 30 before beginning.  Make sure you are within 40 meters
	of the LM and then press <shift><v> to begin LRV setup.  The
	LRV takes about 2 hours to setup, so feel free to use time
	compression.  When the LRV is all setup, a '^' marker will appear
	in the upper left corner of the LRV information panel.  Take a
	rest after setting up the LRV to get your MB rate back down.  If
	you have not been overworking yourself then you should have more
	than 45% remaining Oxygen.  If you have less than 20% you should
	end the EVA by pressing <shift><e>, otherwise continue.
[e-]
[=]
[=]
	At this point all the equipment setup is done and all remaining
	EVA time can be devoted to collecting samples.  We are going to
	hop in the LRV and drive away a little bit before collecting any
	samples.
[=]
[=]
	13. If you are still in the vicinity of the LM, and therefore
	the LRV, just press <shift><m> to move onto the LRV.  The EVA
	flag on the metabolic panel in the lower right corner of the
	instrument panel should change to LRV.  The LRV panel uses the
	same layout as the EVA panel so you should be good to go.  The
	nav computer for the LRV is seperate from the EVA one, so the
	mode is most likely in ABS right now, press <3> to change it
	to LM mode, we want to keep track of where we are in relation
	to the LM and not Lunar coordinates.
[=]
[=]
	14. When first setup the LM will be facing west, so we will
	drive west, but if you want to go off in a different direction
	just use the left and right arrow keys to adjust where the 'f'
	marker on the axis display is pointing.
[=]
	It is important to note that driving over rough terrain too fast
	can damage the LRV, so keep your speed below 2m/s when driving
	over any cell that contains any symbol, or steer around them.
	Press <f7> to set the throttle to 70%.  Before driving over rough
	terrain press <f3> to lower your speed to 30% and then throttle
	back up after passing the rough terrain, or, just steer around it.
[=]
	Keep going until you are about 500 meters from the LM and then
	press <numpad 0> to stop.
[=]
[=]
	15.  Ok, now that we have reached a spot for collecting samples,
	press <shift><m> to move out of the LRV.  Once off the LRV, press
	<8> to set the EVA guidance to LRV mode.  We want to be able to
	find our way back to the LRV right now rather than the LM.
[=]
	Now, using the left and right arrows and the f-keys for setting
	your walking speed, head towards one of the nearby symbols on the
	map, stop when you get right on top of it.
[=]
	press <c> to collect a sample from that spot and then <s> to 
	store the sample in the sample cart.  Then walk to another 
	location and <c>ollect and <s>tore more samples.  You can
	store up to 10 samples in the sample cart.  When collecting
	samples, do not collect more than 1 from the same location,
	samples are given a value when collected, a repeat sample
	will have a value of zero.  Also different types of locations
	give samples of different values, but rather than concentrating
	on the higher value samples, it is best to have a wide variety
	of sample types.
[=]
	When your sample cart is full, walk back to within 20 yards of
	the LRV.  When you get there press <t> to transfer the samples
	from your cart to the LRV.  At this point you can go and collect
	10 more, or hop back in the LRV, drive to a new location and
	collect some more.  When the LRV has 30 samples then you must
	return to the LM.
[=]
	When you are done sampling at a particular sample site and have
	transfered your samples to the LRV.  Press <shift><m> to move
	back onto the LRV.
[=]
[=]
	16. When you are done with collecting samples and back on the
	LRV, drive back to the LM.  Park about 20 meters away from the
	LM and then press <shift><m> to get off the LRV.
[=]
	Press <shift><b> to pick up the sample box from the LRV.  The
	CRY field on the plss panel will show B to show you are holding
	a sample box.
[=]
	Press <shift><s> to store the sample box in the LM.
[=]
[=]
	17. If you still have plenty of oxygen left then you could hop
	back on the LRV and head off to another sampleing site.  otherwise
	it is time to end the EVA.
[=]
	press <shift><e> to end the EVA and return to the LM.  You need to be
	within 30 meters of the LM to do this.
[=]
[=]
[er]
	+------+
	| @CB  |
	+------+
[ee]
	18. Once you are back aboard the LM you will need to repressurize the
	cabin, press <shift><c> to do this.  When the cabin has been
	fully preasurized an '@' symbol will appear before the CB
	indicator in the lower right corner of the instrument panel.
	Repressurization will take about 2 minutes
[e-]
[=]
[=]
[er]
	+-------+
	|   PL  |
	+-------+
[ee]
	19. After the cabin has finished depressurizing, press <shift><p>
	to remove the PLSS unit.  Removing the PLSS will take about
	45 minutes, so feel free to use time compression to speed this
	up.  After the PLSS has been removed the '@' symbol will no
	longer appear before the PL flag on the lower right corner
	of the instrument panel.  You mush remove the PLSS after each
	EVA in order to recharge it for the next EVA.
[e-]
[=]
[=]
[er]
	+-------+
	|   SS  |
	+-------+
[ee]
	20. After your PLSS is removed and you will NOT be performing any
	more EVAs on this mission you can press <shift><s> to remove your
	EVA suit.  You only need to remove your suit if you are done with
	EVAs for the rest of the mission, if you plan on performing
	another EVA then leave the suit on, you can sleep in it just fine
	and save the time that it takes to put on and remove your EVA
	suit.  Taking off the EVA suit will take about 35 minutes.  When
	your EVA suit is fully removed the '@' marker will be cleared
	from the SS flag in the lower right corner of the panel.
[e-]
[=]
[=]
	21. After your EVA you should perform a short rest by pressing
	<shift><8>.  This rest is 2 hours in length.  Think of this time
	as being used to stow samples away for flight, having a meal,
	systems checks to make sure everything is still ok with the
	vehicle, etc.
[=]
[=]
	22. Next take a full 8 hour sleep period by pressing <shift><0>.
	This recovers all your "soft" injury.
[=]
[=]
	23. Take another short rest period by pressing <shift><8>.
	Think of this time as being used for a meal, checking the
	spacecraft systems, and either getting things ready for the next
	EVA or preparing the spacecraft for lift off.
[=]
[=]
	From here you can either perform another EVA, or go to the
	tutorial on Liftoff and Rendevous.

