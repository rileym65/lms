[c]	Flying the LM away from the CSM
[=]
	In this tutorial we will be flying the LM a few hundred kilometers
	away from the CSM and then rendevous with it.  This tutorial
	assumes that you are currently in a 300km x 300km circular orbit
	and that you are located in the LM at the station keeping position
	of 100 meters away from the CSM on the approach vector.  Refer to
	prior tutorials if you need help getting into this position.
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
	|--l         U          --|
	|a|                     | |
	|n|                     | |
	|o|                     | |
	|r|                     | |
	|m|          f          | |
	| +==========|inside====+ |
	+-------------------------+
[ee]
	Ok, for the first maneuver we are going to change our orbit from
	the circular orbit we are in now to a 300km x 200km elliptical
	orbit, this will allow us to get over 400 kilometers away from the
	CSM.
[=]
	Since we will be lowering our periapsis, we will need to perform
	a retrograde burn which requires us to orient the spacecraft
	retrograde.
[=]
	After the spacecraft is retrograde, we will need to see what our
	orbit periapsis is, so press these keys <v><1><6> <n><5><3>
	<enter>.  This sets the guidance computer to show us position data
	relative to the CSM.  the main thing we want from this at this
	point is register 13, which shows our current periapsis.
[e-]
[=]
[er]
	+-----------------------------+
	|   0.5739   -0.0017   -0.0001|
	|  200.009   299.378  -61.2075|
	+-----------------------------+
[ee]
	After you have oriented yourself retrograde and selected the correct
	guidance computer mode, press <shift><i> to activate the descent
	engine and then <f9> to increase throttle to 90%.  Now keep an eye
	on register 13, when it approactes 200.0 press the <i> key to shut
	down the engine, then use <u>p or <d>own thrusters to fine tune
	your periapsis to 200.0km.
[=]
	After the burn is complete and you cleaned up the periapsis, take
	a look in register 15.  This registers shows the amount of time
	difference between our orbit period and the orbit period of the
	CSM.  If your orbits are similar to mine you should see roughly
	-61 seconds, in other words our new orbit is 61 seconds faster
	than the orbit of the CSM.  Write the number in this field down,
	we will want to use this number later.
[e-]
[=]
	Now you might be wondering, how is our orbit faster if we just
	slowed down with the retrograde burn?  This is one of those things
	about orbital mechanics that seems counter-intuitive until you
	understand why.  I will actually explain this a little bit later.
[=]
[er]
	+-----------------------------+
	|   1.0000   29.0000    3.0000|
	|  200.010   299.378  -61.2076|
	+-----------------------------+
[ee]
	Now lets switch the computer to a more useful mode by pressing
	<v><1><6> <n><8><1> <enter>.  This mode is useful for rendevous
	with the CSM at apoapsis.  Although we are not going to rendevous
	yet, it does give us information we will need when it comes times
	to circularize our current orbit.
[=]
	Registers 10, 11, and 12 gives us a countdown until we get to
	apoapsis.  In my sample I am 1 hour, 29 minutes and 3 seconds
	away from apoapsis.  Register 13 shows our current periapsis
	altitude in km, register 14 shows our current apoapsis in km
	and register 15 shows our relative orbit time to that of the
	CSM.
[e-]
[=]
[er]
	+-------------------------+
	|    LOOKING   PROGRADE   |
	| +===outside|==========+ |
	| |          f          | |
	| |                     |n|
	| |                     |o|
	| |                     |r|
	| |                     |m|
	|--l         u          --|
	|a|                     | |
	|n|                     | |
	|o|                     | |
	|r|                     | |
	|m|                     | |
	| +==========|inside====+ |
	+-------------------------+
[ee]
	When we get to apoapsis we are going to need to make a prograde
	burn to circularize our orbit, so when the countdown gets to about
	5 minutes left, orient the spacecraft prograde and then you will
	want to keep it oriented this way up to and throughout the burn
	to come.
[=]
	The deceleration burn we did earlier lasted for about 12 seconds,
	the circularization burn will also be around 12 seconds, so you
	will want to perform your burn about 6 seconds before apapsis.
	So when Registers 13, 14, and 15 are showing 0.0000 0.0000 6.0000,
	hit <shift><i> to engage your descent engine and then press <f9>
	to set 90% thrust, remember to keep oriented prograde throughout
	the maneuver.
[=]
	We are not actually going to watch register 13, which is our
	current periapsis, since we are actually more interested in syncing
	our orbit time to that of the CSM.  So for this burn keep an eye
	on register 15, which is our relative orbit time, when it gets near
	0.0 hit <i> to stop the descent engine, then use the <u>p and 
	<d>own thrusters to fine tune register 15, trying to get it as close
	to zero as you possibly can.  During this fine tuning remember to
	keep oriented prograde as well adjust your translation throttle as
	needed to get register 15 close to 0.0.
[e-]
[=]
[er]
	+-----------------------------+
	|   0.0000   44.0000   44.0000|
	|  299.148   300.763    0.0000|
	+-----------------------------+
[ee]
	After your circularization burn and fine adjustments, registers 13
	and 14 should show that you are again in a 300km x 300km orbit and
	register 15 should be showing near zero.
[e-]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 54  |
	|   0.7142    3.5835    1.9055|
	|  547.076    2.4176   -0.9731|
	|   0.0011    0.0682   -0.1643|
	|          IDL                |
	|   4.0568   -0.0017   -0.0001|
	|  299.148   300.764    0.0000|
	+-----------------------------+
[ee]
	Now lets take a look at where we are.  Press <v><1><6> <n><5><4>
	<enter>.  This will set the guidance computer to show our position
	relative to the CSM.
[=]
	First look at register 2, this shows that our longitude is East
	of the CSM, 3.5835 degrees in my case, which means we are now
	ahead of the CSM by some distance, which we will calculate shortly.
	Register 2 gives our longitude difference, but it is not the best
	number to use for figuring out distance, so take a look at register
	10, which shows how many degrees around our orbit we are in
	comparison to the CSM, in my case it is 4.0568 degrees ahead.  This
	number is relative to our plane of orbit and gives us a much
	better approximation of our position.
[=]
	Now there are two ways we can calculate how far ahead of the CSM
	we are.  First we can figure it out by time.  Remember our orbit
	was 61 seconds faster than that of the CSM, so we arrived at this
	spot 61 seconds before the CSM will arrive here.  Now at 300km
	altitude a circular orbit around Earth is about 7726 meters per
	second, so 61.2076 X 7726 = 472,889 meters, or 472.88km.
[=]
	The second way to calculate this is a little bit more labor 
	intensive.  The radius of the Earth is 6378.1 km, add our altitude
	to that of 300km and we get 6678.1km.  The actual distance of our
	orbit around the Earth can be calculated by multiplying this by
	two: 6678.1km X 2 = 13,356.2 and then multiplying that by the
	value of PI (3.14159265) which equals 41,959.72km.  Now we need
	to find the distance per degree travelled, so take this and divide
	by 360 degrees in a cirlce: 41959.72 / 360 = 116.55km.  Now 
	register 10 shows us how many degrees ahead of the CSM we are, so
	multiply the distance per degree by the number of degrees we are
	ahead of the CSM: 116.55 X 4.0568 = 472.83km, pretty close to the
	number we got from the time calculation!  Note that this second
	method of calculation is going to be the more accurate of the two,
	but either one will get you close enough.  The first you can only
	use tho if you know the time difference, the second method can
	always be used.
[e-]
[=]
	Now lets take a look at how we got here.  Remember we made a
	retrograde burn back at the CSM, in other words we burned to
	slow down, but now here we are 470km ahead!  So, how does that
	happen?  Well, when we burned retrograde we put ourselves into a
	lower orbit, a lower orbit covers less distance than a higher one.
	In our calculation above we saw an orbit at 300km altitude requires
	travelling 41,959km.  using the same calculation above but using an
	altitude of 200km instead you get a total orbit distance of 41,331km.
	almost 600km less.  Now our orbit was not 200km circular but rather
	an eliptical orbit, so we do not get quite as much savings in
	distance, but we still travelled less distance to complete one orbit.
	Next thing, the lower the orbit the faster the orbit velocity.
	So after we slowed down and started falling into a lower orbit our
	velocity started to increase again, when we were at periapsis of the
	new orbit we were travelling much faster than the CSM, and in a lower
	orbit, so that in the end when we got back to the same altitude we
	had enough advantage from the needing to travel less distance and
	the fact we were travelling faster for a good portion of our lower
	orbit, we were able to out-race the CSM and end up well ahead of.
[=]
	So an important rule, when you want to go faster than another object
	you need to slow down!  The opposite aplies too, now we need to
	slow down so that the CSM can catch up to us, in order for us to
	slow down we are first going to have to speed up!  By speeding up
	we will be increasing the size of our orbit, requiring to travel
	a greater distance, and since we will be in a higher orbit our
	velocity will slow down to well below that of the CSM which will
	allow the CSM to catch up.
[=]
[er]
	+-------------------------+
	|    LOOKING   PROGRADE   |
	| +===outside|==========+ |
	| |          f          | |
	| |                     |n|
	| |                     |o|
	| |                     |r|
	| |                     |m|
	|--l         u          --|
	|a|                     | |
	|n|                     | |
	|o|                     | |
	|r|                     | |
	|m|                     | |
	| +==========|inside====+ |
	+-------------------------+
[ee]
	Now what we are going to do is a same-orbit rendevous, in other
	words we want to rendevous with a target that is in the same
	orbit as we are.  Since our target is behind us we need to speed up.
	If the target were in front of us then we would need to slow down.
	So, how much do we need to speed up?  Well if you wrote down that
	orbit difference before, that is how much.  But if we do not have
	that number we can calculate it from our position.  We know that
	we are about 472.8km ahead of the CSM.  The CSM is travelling at
	7.726km per second. so 472.8 / 7.726 = 61.19 seconds.  Pretty
	close to that number from before huh?
[=]
	Since our target is behind us we need to slow down, remember that
	to slow down we need to speed up, so we need to perform a prograde
	burn, so go ahead and orient the spacecraft prograde.  You will
	need to maintain this prograde orientation up to and throughout
	the upcoming burn.
[e-]
[=]
[er]
	+-----------------------------+
	|   4.0327   -0.0017   -0.0001|
	|  299.148   400.911   61.1961|
	+-----------------------------+
[ee]
	When you are all ready then press <shift><i> to ignite your engine
	and then <f9> to increase throttle to 90%.  Now keep an eye on
	register 15, when it reaches the time you either wrote down or
	calculated, press the <i> key to stop the engine.  Use the <u>p
	and <d>own thrusters as needed to fine tune this value.
[=]
	After your burn take a look at your periapsis, it is now around
	400km, the higher orbit we were looking for.  
[e-]
[=]
[er]
	+-----------------------------+
	|   1.0000   30.0000   47.0000|
	|  299.148   400.913   61.1961|
	+-----------------------------+
[ee]
	Just like before we had a special mode in the computer to help us
	with apoapsis rendevous, we have one for periapsis rendevous as
	well.  Press <v><1><6> <n><8><2> <enter>.  This works just like
	the N82 program but now the countdown timer is to periapsis instead
	of apoapsis.
[=]
	With rendevous 90 minutes away, go ahead and use some time 
	compression to get closer.  When you have about 5 minutes left you
	will need to orient the spacecraft retrograde so that we will be
	able to lower our apoapsis.  The burn will last about 12 seconds
	so you will want to actually start the burn 6 seconds before
	periapsis.
[=]
	At 6 seconds to go, press <shift><i> to start the engine and then
	quickly press <f9> to throttle up to 90%.  Just like before we
	want to sync our orbit with the CSM, so watch register 15 and
	press <i> when it approaches 0.0.  Then use the <u>p and <d>own
	thrusters to fine tune this down to 0.0.
[e-]
[=]
[er]
	+-----------------------------+
	|   P 00      V 16      N 63  |
	|  21.1161  -83.7223   150.388|
	|   0.2328    0.0155   -0.0330|
	|   0.0014    0.2270   -0.5492|
	|          IDL                |
	|  18.7599  -88.9669   168.138|
	|   0.2333    0.0159   -0.0292|
	+-----------------------------+
[ee]
	Once you have synced your orbit time to that of the CSM, it is
	time to see how well we did on our rendevous.  Press <v><1><6>
	<n><6><3> <enter> to select the rendevous/docking mode of the
	guidance computer.  Also select the docking radar as your data
	source by pressing <shift><.>.
[=]
	In my sample here, my rendevous was pretty much spot on, in fact
	the best rendevous I have ever had.  I was in fact so close to
	the CSM that I was receiving docking port positioning data.  Usually
	I am anywhere between a few hundres and a couple thousand meters
	away.
[=]
	It does not matter whether you got this close or not, the procedure
	is still mostly the same.  If you are too far for docking port data
	the bottom six registers will all be 9999, indicating no data, in
	this case you just use the CSM positioning data from the upper 
	registers instead.  If you are close enough to receive docking port
	positioning data then you will use the bottom registers.
[=]
	If any of your positions in registers 1, 2, or 3 exceed 10,000
	meters then you are really too far to just translate over to the
	CSM, you really should repeat the same-orbit rendevous shown
	above to get closer.
[e-]
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
	|--u         F          --|
	|-|                     | |
	|Z|                     | |
	| |                     | |
	| |                     | |
	| |                     | |
	| +==========|+Y========+ |
	+-----+------------+------+
[ee]
	Before making any maneuvers to close your distance to the CSM, you
	need to orient your spacecraft correctly.  Switch the multi-axis
	display to the absolute mode.  You then want to orient the 
	spacecraft to the reference orientation that corresponds with the
	one you set on the CSM.  If you used my reference orientation then
	the orientation you need now is shown here.
[=]
	The thruster information I am going to give here is dependent on
	the reference orientation I have used.  If your orientation is
	different then you will need to use different thrusters than the
	ones I use here.
[=]
	Now go back to the guidance computer display, you need to find
	out which way you need to go.  Once you are close enough to receive
	docking data you will use registers 10, 11, and 12 as your X, Y,
	and Z positions, if you are too far then you will use registers 1,
	2, and 3 for your X, Y, and Z positions, once you are close enough
	to receive docking data then you will switch to the lower registers.
[=]
	Whichever registers you are referencing, the registers immediately
	below give your relative velocity in that dimenstion.  As mentioned
	in prior tutorials, if the position and the velocity have opposite
	signs then you will be getting closer to your target, if the signs
	are the same you will be getting farther away.
[e-]
[=]
	With that in mind it is time to complete the rendevous.  If you
	are further away from the CSM then use higher translation throttle
	settings since you will want to be moving faster, as you get closer
	you will want to slow your velocities and lower your translation
	throttle setting.
[=]
	If you are using my reference orientation then here is how the
	thrusters will function for you:
[=]
[tb]
	| F | Will make your X velocity more positive |
	| B | Will make your X velocity more negative |
	| R | Will make your Y velocity more positive |
	| L | Will make your Y velocity more negative |
	| D | Will make your Z velocity more positive |
	| U | Will make your Z velocity more negative |
[te]
[=]
	Now just make your velocities the opposites than the corresponding
	positions and start working your way back to the docking approach
	point.  The docking approach point is X=0, Y=0, and Z=100 meters.
[=]
[er]
	+-------------+
	|    dock     |
	| +---f|----+ |
	| -    v    - |
	| |         |r|
	|--    *    --|
	|l|         | |
	| |    ^    | |
	| +----|b---+ |
	+-------------+
	+-----------------------------+
	|  -0.1381   -0.1857   100.498|
	|   0.0016    0.0005   -0.0020|
	+-----------------------------+
[ee]
	Once you have arrived at the docking approach point and your docking
	radar shows that you are in the correct orientation all you have to
	do is use the <u>p thruster to set your closing Z velocity to -0.3
	and then keep your X and Y alignments near zero until you dock.
[e-]
[=]
	In this tutorial we did a same-orbit rendevous, which is something
	that you should not need to do in an actual Lunar mission.  The
	only reason to do this type of rendevous during a Lunar mission is
	because you did not time your initial rendevous correctly and end
	up too far ahead or behind the CSM, in which case you would go
	ahead and circulariaze your orbit and perform a same-orbit
	rendevous to get to the CSM.
[=]
	For normal Lunar rendevous, after leaving the Lunar surface you
	place yourself into an orbit considerably lower than that of the
	CSM and then initiate a Hohmann transfer at the correct time to
	rendevous with the CSM.  I will give a small mini-tutorial on
	how to perform this type of rendevous.
[=]

