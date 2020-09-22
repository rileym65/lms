[c]	Calculating a Hohmann Transfer Rendevous
[=]
	In the last tutorial I showed you how to rendevous with a spacecraft
	that is in the same orbit you are.  But when returning from the Moon
	you will actually be in a different orbit than the CSM, requiring
	a different form of rendevous.  When returning from the Moon you
	first establish a circular orbit well below the altitude that the
	CSM is orbiting at and then at the correct time you start a
	Hohmann transfer.  Knowing when to start the Hohmann transfer is
	crucial to a successful rendevous.
[=]
	In this mini tutorial I am going to teach you how to find out when
	to start the Hohmann transfer.  We will not be flying any vehicles
	in this tutorial, this one is all about the math.  If you do not 
	want to learn the math, that is ok.  As long as you have your CSM
	in a 100km altitude circular orbit, and place the LM into a 20km
	altitude circular orbit after lifting off from the Moon, then my
	tutorials on returning from the Moon gives you the needed info	
	to get back to the CSM.  But if your CSM is not at 100km and your
	LM parking orbit is not 20km, then you will need to follow the
	process in this tutorial to find out how to get back to the CSM.
[=]
	First, lets look at a very important formula:
[=]
[i4]
	 T = 2 * pi * sqrt(S^3 / (G * M))
[=]
[i-4]
	Where:
[-]
[i4]
	T = Time to complete 1 orbit in seconds
[-]	S = Semi-major axis in meters
[-]	G = Universal gravitational constant: 6.67408e-11
[-]	M = Mass of the body you are orbiting, Moon=7.34767309e+22kg
[=]
[i-4]
	For purposes of calculation we can use a single number for GM,
	since that is just the multiplication of the gravitational constant
	with the mass of the Moon, we cann just say that GM = 4.9075e+12,
	and we can simplify the 2 * pi to be 2PI = 6.283185308.
[=]
	This gives us a new formula of:
[=]
[i4]
	T = 6.283185308 * sqrt(S^3 / 4.9075e+12)
[=]
[i-4]
	In order to figure out when we need to start our Hohmann transfer
	for rendevous we need to know two orbit times, first is the orbit
	time of the CSM and second is the orbit time of the Hohmann transfer
	orbit.  For these calculations we will assume the CSM to be in a
	100km altitude circular orbit and the LM to be in a 20km altitude
	circular orbit.  I am using these two altitudes since those are the
	ones I recommend in the my tutorials on Lunar missions.  You will
	be able to see how I came up with when to start the transfer in
	those tutorials.
[=]
	We will start by figuring out the orbit time of the CSM.  Just
	follow these steps:
[=]
[lb1]
[li]	Convert altitude to radius.  The radius of the Moon is 1738.3km.
	Since the CSM altitude is 100km, add this to get a final radius
	of 1838.3km.
[li]	Convert the radius to meters: 1838.3km * 1000 = 1,838,300 meters.
[li]	In a circular orbit your radius is the semi-major axis, so there
	is no need to compute the semi-major axis in this step, when we
	do the Hohmann transfer orbit time, I will show you how to calculate
	the semi-major axis for a non-circular orbit.
[li]	Multiply the semi-major axis by itself twice, so: 1,383,300 X
	1,383,300 X 1,383,300 = 6.2122533e+18.
[li]	Now take that number and divide it by GM: 6.2122533e+18 / 4.9075e+12
	= 1,265,869.259.
[li]	Now take the square root of that number: sqrt(1,265,869.259) =
	1,125.108554.
[li]	And now multiply this by 2PI: 1,125.108554 X 6.283185308 = 
	7,069.26 seconds.
[le]
[=]
	Now we know the orbit time of the CSM to be 7,069.26 seconds, or 1
	hour 57 minutes and 49 seconds.  Which if you looked at the orbit
	time of the CSM before you left it, will be right around this number.
[=]
	Next we need to calculate the time that the Hohmann transfer orbit
	will take.  Because the Hohmann transfer orbit is not circular it
	will need a little bit more work since we now have to figure out
	what the semi-major axis is, but do not worry, it is pretty easy.
	Here are the steps for determining the time of the Hohmann transfer
	orbit:
[=]
[lb1]
[li]	Start by calculating the radius of the LM's orbit. Remember the
	Moon's radius is 1738.3km and we need to add our orbit altitude,
	so 1738.3km + 20km = 1758.3 km.
[li]	Next we need the radius of the target orbit, the orbit the CSM
	is in, so 1738.3km + 100km = 1838.3km.  Which is also the same
	number from step 1 above where we were calculating the CSM's orbit
	time.
[li]	Now add this number to the one we got in step 1: 1758.3km + 1838.3km
	= 3,596.6km.  This is the major axis of the transfer orbit.
[li]	To get the semi-major axis, just divide that number by 2: 3,596.6km
	/ 2 = 1,798.2km.
[li]	Now we just need to follow the rest of the steps from above, first
	multiply the semi-major axis by 1000 to convert km to meters:
	1,798.2km = 1,798,200 meters.
[li]	Now multiply this number by itself twice: 1,798,200 X 1,798,200 X
	1,798,200 = 5.8154916e+18.
[li]	Divide this number by GM: 5.8154916e+18 / 4.9075e+12 = 1,185,021.213.
[li]	And take the square root: sqrt(1,185,021.213) = 1,088.586796.
[li]	Now multiply by 2PI: 1,088.586796 X 6.283185308 = 6,839.79.
[li]	That gives 6,839.79 seconds for one complete orbit, but for the
	Hohmann transfer we are only going to go half an orbit, so divide
	that number by two: 6,839.79 / 2 = 3,419.80 seconds.
[le]
[=]
	Ok, now we know that the Hohmann transfer will take 3,419.8 seconds.
	Now we need to know how far the CSM will travel during this time:
[=]
[lb1]
[li]	We need to know how for the CSM moves each second, to get this
	number we divide the number of degrees in a complete orbit, 360,
	by the number of seconds it takes to complete that orbit, so:
	360 / 7,069.26 = 0.050924708 degrees per second.
[li]	Now multiply this by the number of seconds for the transfer orbit:
	0.050924708 X 3,419.80 = 174.1523 degrees.
[le]
[=]
	Ok, now we know that for the amount of time that we need for the
	Hohmann transfer orbit the CSM will travel 174.1523 degrees along
	its own orbit.  During the Hohmann transfer orbit the LM will
	travel through 180 degrees, one half of an orbit.  Since the CSM
	will be travelling fewer degrees than we are, the CSM needs to
	be ahead of us when we start the transfer, how much ahead? That is
	easy to compute: 180 - 174.1523 = 5.847 degrees.
[=]
	Now we know that the CSM needs to be 5.847 degrees ahead of us in
	its orbit when we need to start the Hohmann transfer orbit.  This
	is called the "Phase Angle."  This angle can be seen in register
	10 of mode V16N54.
[=]

