[c]	Realism of the Simulator
[=]
	LMS was designed primarily as a mission simulator as opposed to a
	space flight simulator, as such more emphasis was placed on the
	simulation of space missions than on the real physics of space
	flight. With that being said where possible I have endeavered to use
	as much real physics as possible within the framework of my current
	knowledge of space flight and mathematical skill. This page documents
	all the models in use by LMS describing what is more accurate and
	what is less. As I gain more knowledge into space flight and the
	related math, I will update the simulator. While my empahsis is on
	mission simulation, I also would like to keep the physics as real as
	possible.
[=]
[h2]	Coordinate System
[=]
	The coordinate system in use by this simulator is based upon the
	Right ascension/declination system, which
[=]
[h2]	Earth
[=]
	The real Earth has a mass of 5.972e+24kg, an equitoral radius of
	6,378.1km and a mean radius of 6,371.0km. The modeled Earth in FMS
	uses the correct mass value, but does not model the oblique spheroid
	shape of the real Earth. The simulator models a perfectly round Earth
	using 6,378.1km as the surface radius.
[=]
	The simulator does not model surface features of the Earth, as far
	as the simulator is considered the entire world has ground/sea at the
	same radius. Since this really only effects touch/splashdown I doubt
	I will do any Earth surface modelling in the future, but I would not
	rule it out.
[=]
	The Earth is not modeled in LMS and is at the center of the universe
	in FMS, being located at cartesian coordinates of 0,0,0. The Earth
	is not in motion but does rotate, completing one complete rotation
	in 0.99726968 days.
[=]
	The Earth's atmosphere is very simply modeled in this simulation.
	While I do use the real drag formula, which uses air density as one
	of the components to compute drag, the air density calculation used
	by the simulator is greatly simplified. The air density calculation
	is computed as a value between 1.0 (sea level) and 0.0 (in space).
	The atmosphere is divided into 5 altitude regions and a linear
	function is used to determine air density within each reagion. This
	table shows the regions:
[=]
[tb]
	| >>>>>>>>>>>>>>>>> | <<<<<<< | <<<<<<<<<<<<<<<<<<<<<<<< |
	| Altitude (meters) | Density | Decrease per meter above |
	| 100,000           | 0       | 0                        |
	| 50,000            | 0.001   | 0.00000018               |
	| 32,000            | 0.01    | 0.0000005                |
	| 16,000            | 0.1     | 0.000005625              |
	| 5,500             | 0.5     | 0.000038095              |
	| 0                 | 1.0     | 0.0000909                |
[te]
[=]
	So for example to compute the air density at 27,000 meters. 27,000
	meters is 11,000 meters above 16,000, so the decrease above 16,000
	would be 11,000 * 0.000005625 or 0.061874, subtracted from the air
	density at 16,000 meters, 0.1 - 0.061874 equals 0.038125, this
	would then be used in the drag calculation.
[=]
	While this model is very simplistic, it does give believable results
	in the drag experienced during launch or reentry. For example max-q
	occurs relatively close to the max-q figures published by NASA for
	their space flights.
[=]
	The air density calculation is in an isolated function so it would
	be pretty easy to replace it with something that gives more realistic
	values in the future. I figured for now, during launch atmospheric
	flight is usually under 5 minutes and re-entry to splash down is
	between 10 and 15 minutes, that this time is relatively short
	compared to a 200+ hour Lunar mission, and therefore not worth of
	spending too much time on it at present.
[=]
	Kennedy Space Center is correctly located at a longitude of 80.6077
	degrees west and at a latitude of 28.50 degrees north. Upon launch
	this imparts an eastward velocity of 408.75m/s. The position of KSC
	is correctly altered by the Earth's rotation in relation to the
	cartesian coordiantes used by the physics engine.
[=]
[h2]	The Moon
[=]
	The real Moon has a mass of 7.342+e22kg, an equitoral radius of
	1738.1km and a mean radius of 1737.1km. The simulator uses the
	correct mass for the Moon, but like the Earth uses the equitoral
	radius of 1738.1km for a perfectly spherical Moon. The Moon's
	surface does not currently model elevation above/below the mean
	radius, however in the future if I can find the correct data,
	I would like to model surface elevation for the moon more accurately.

[=]
	The real Moon orbits the Earth with a perigee ranging from 356,400km
	to 370,400km and a apogee that ranges from 404,000km to 406,700km.
	The Moon's inclination is 5.145 degress to the ecliptic. The Moon's
	declination compared to the Earth's equator changes between 18.5
	degrees to as much as 28.5 degrees, changing over an 18.6 year cycle.
	The longitude of ascending node of the Moon also changes over time
	by this 18.6 year cycle.  The Moon's rotational velocity at the
	equater is 4.627 meters per second.
[=]
	For this simulation, the Moon orbits the Earth with a perigee of
	370,400km and an apogee of 404,633km.  The longitude of ascending
	node is located at 0 degrees on the coordinate system and does
	not currently change.  The Moon's motion around the Earth is not
	"on rails", but rather governed by the correct gravitational
	formulas.  Since no other bodies in the Solar System are simulated,
	the only gravitational influence on the Moon is the Earth.  The
	Moon is not currently rotating.
[=]
	I do have plans to further work on the Moon's physical model.  I
	intend to be able to position the Moon based upon a simulator
	start date as well as add the Moon's rotation.
[=]
[h2]	Vehicles
[=]
	All vehicles modeled on real vehicles, Mercury, Gemini, Apollo, LM,
	LM-J, Redstone, Atlas, Titan II, Saturn 1B and Saturn V are all
	modeled using the specs published by NASA.  This includes vehicle
	mass and size, fuel loads, and engine performance.  All vehicles
	are governed by the actual gravitational formulas and are affected
	by the Earth and Moon at all times.  Real vehicle drag and thrust
	formulas are also used to govern spacecraft motion.
[=]
	Fictional spacecraft, Apollo Mk II, LM Mk II, and Saturn VB
	are marginal upgrades from the real vehicles.  The LM Mk II
	is equivalent of the lander from AMS.  The Saturn VB and the
	Apollo Mk II are upgrades of the Apollo and Saturn V to
	accomodate the higher weight of the Mk II Lander.
[=]

