[c]	Orbital Meneuvers
[=]
	Due to the amount of information on orbital maneuvering, this
	tutorial is going to be broken down into three parts.  The
	first will cover the instrumentation used, the second will
	cover spacecraft orientation, and the third will cover orbit
	change maneuvers.  All of these tutorials will assume that you
	are currently in orbit.  If you do not have a spacecraft in
	orbit then follow the tutorial on Launching to Orbit.

[=]
[=]
[er]
	+-------------------------+
	| u/r:  90.0   u/o:   0.0 |
	| f/r:   0.0   f/o:  90.0 |
	| l/r:  90.0   l/o:  90.0 |
	+-------------------------+
[ee]
	Lets start by taking a look at the angle reference panel.  This
	panel shows the angles between the primary spacecraft faces: Up (u),
	Front (f), and Left (l) and either the current radial (r) or
	relative to the orbital path (o).
[=]
	The column on the left shows the spacecraft faces in relation to
	the current radial.  The current radial is a line that starts
	at the center of the body being orbited (Earth if you are in
	Earth orbit) and extends through the current location of the
	spacecraft and out into space.  In essence this will give us
	a reference based upon the ground under the spacecraft.
[=]
	The numbers then indicate the angle in degrees from the face
	(u, r, or l) to that reference radial.  An angle of 0 would
	indicate that face is pointing directly away from the ground,
	an angle of 180 would indicate that face is pointing directly
	towards the ground and an angle of 90 would indicate that face
	is perpendicular to the ground.  So basicly, the lower this
	number is the more it is pointing away from the ground, with 0
	being pointed directly at the sky.  The higher the number is
	the more you are pointed directly at the ground, with 180 being
	pointed directly at the ground.
[=]
	The column on the right uses the current orbital path as the
	reference line.  Think of this line as starting from the center
	of the spacecraft and then extending in the direction that the
	spacecraft is going.  So in this column a number of 0 means that
	face is pointing directly in the direction of travel, 180 would
	mean directly opposite the direciton of travel and 90 would be
	perpendicular to the direction of travel.  So, the lower the
	number the more towards the direction of travel the face is 
	pointing, with 0 being pointed directly toward the path of
	travel.  The higher the number the more the faces away from the
	direction of travel, with 180 being directly away from the
	direction of travel.
[e-]
[=]
[=]
[er]
	+-------------------------+
	|     Elev     Norm       |
	| U:    0.01    -0.00  +  |
	| F:   89.99    -0.00  -  |
	| L:   -0.00   -90.00  +  |
	+-------------------------+
[ee]
	Next lets look at the precision prograde panel, located above
	the angle reference panel.  Since oribital flight primarily uses
	the direction of travel as the reference for so many things, this
	panel gives us precision information about how the faces relate
	to the direction of travel.  While the 'u/o', 'f/o', and 'l/o'
	allow you to see the angles between the primary faces and the
	direction of travel, they do not give precise information on
	exactly where a particular face is facing.  For example, if 'f/o'
	is showing 90, then you know the 'f'ront face is perpendicular
	to the direction of travel, but you do not know if the front 
	face is towards the ground, or towards the sky, or any other 
	direction for that matter.
[=]
	This panel solves that problem by giving you two reference
	angles for each face, Elevation and Norm.  Elevation gives you
	the angle of the face using the center point of the orbit as the
	reference.  If you were to draw the orbit on a piece of paper,
	you would have a closed ellipse (possibly a cirlce)  Anything on
	the inside of the line is inside the orbit while anything outside
	the line is outside the orbit.  The elevation is the angle between
	the face and the line representing the orbit at the location of
	the spacecraft.  If the elevation is 0 then the face is facing
	along the line of travel.  A negative number would indicate that
	the face is facing inside the orbit, with -90 boing pointed directly
	at the center point of the orbit.  A positive number would indicate
	the face is facing towards the outside of the orbit, with +90
	being faced directly away from the center of the orbit.
[=]
	The Norm column represents the angles between the face and the
	Orbit Normal.  To understand what the Orbit Normal is, again
	take that piece of paper with the orbit drawn on it.  The paper
	represents the plane of the orbit.  Now take a pencil and stand
	it up at the center of the orbit, pointing straight up from the
	paper.  The pencil represents the Orbit Normal.  So Elevation
	gives our angle to the orbit line in the same plane as the orbit,
	the Normal angle gives you the angle the face is facing in
	relation to the orbit plane.  An angle of 0 would indicate the
	face is facing along the orbit plane, a positive number means
	the face is facing above the plane, in the direction the pencil
	is pointing above the paper, a negative number indicates a
	facing that is below the orbital plane.  A number of +90 would
	indicate facing directly perpendicular to the orbit plane, or 
	straight up from the orbital plane.  -90 would indicate facing
	directly perpendicular to the orbit plane, facing straight down
	from the orbital plane.
[=]
	The final column of this panel will contain '+' and '-' symbols.
	These symbols tell you if the face is angled more towards the
	direction of travel (+) or more away from the direction of
	travel (-).  For example, if the Up face had an elevation of 10
	degrees and the norm had an angle of 5 degrees, there are actually
	two orientations that can have these numbers, one of them is angled
	close to the direction of travel and the other is angled close to
	the opposite of the direction of travel, the + and - signs tells
	you which one it is.  If the symbol was a '+' then face is angled
	in the direction of travel and if the symbol was '-' the face would
	be towards the opposite of the direction of travel.
[e-]
[=]
[=]
[er]
	+-------------------------+
	|    LOOKING   DOWN       |
	| +======west|==========+ |
	| |                     |n|
	| |                     |o|
	| |                     |r|
	| |                     |t|
	| |                     |h|
	|--          F          --|
	|s|                     | |
	|o|                     | |
	|u|                   l | |
	|t|                     | |
	|h|     u               | |
	| +==========|east======+ |
	+-------------------------+
[ee]
	Although we have looked at the multi-axis display in the 
	tutorial on sub-orbital flight we are going to go back and take
	a nice deep look at this instrument, for it is critical to
	spacecraft orientation to be able to fully understand this guage
	and what it shows.
[=]
	We will start with a quick review.  The multi-axis display can
	operate in 4 modes: Down, West, Prograde, and Absolute.  All
	the modes work the same they just use different reference points.
	The 'F', 'U', and 'L' symbols on the panel represent the primary
	faces of the spacecraft and show where they are oriented in
	relation to the references.  The symbols could be upper or lower
	case, when uppercase they are located closer to the observer
	reference point and when lowercase they are located further from
	the observer reference point.
[=]
	In the Down mode the reference line is the current radial, or
	the line that starts at the center of the primary body and then
	going through the center of the spacecraft and out into space.
	The observer reference point is on this line further from the
	center of the primary body than the spacecraft, so the result
	is as if the observer were looking down through the spacecraft
	to the ground.
[=]
	The axis references in this mode are the compass coordinates
	and represent the directions as if the spacecraft was sitting
	on the ground.  So in the sample shown here, the 'F'orward
	face is facing straight up away from the ground.  The 'L'eft
	face is facing northeast and angled away from the observer
	reference point and the 'U'p face is facing southeast and
	angled away from the observer reference point.
[=]
	The Down mode of the multi-axis display is mostly used during
	launch or splashdown, as well as in the LM during final phase
	of landing or the initial phase of liftoff.  It has little use
	during normal orbit operations.
[e-]
[=]
[=]
[er]
	+-------------------------+
	|    LOOKING   WEST       |
	| +========up|==========+ |
	| |          f          |n|
	| |                     |o|
	| |                     |r|
	| |                     |t|
	| |                     |h|
	|--     U             L --|
	|s|                     | |
	|o|                     | |
	|u|                     | |
	|t|                     | |
	|h|                     | |
	| +==========|down======+ |
	+-------------------------+
[ee]
	The west mode is related to the down mode but operates on a
	vector that starts at the spacecraft and that heads in the
	spacecraft's local west direction.  Think of this as if the
	spacecraft is sitting on the ground, the observer reference 
	point is directly East of the spacecraft looking through the
	spacecraft to the West.
[=]
	In this mode the North and South axis remains the same as the
	down mode, but now instead of East and West for the vertical
	axis, you now have up and down.  Up would be toward the sky
	and down is toward the ground.
[=]
	When the face symbols are uppercase then those faces are
	towards the East and when they are lowercase they are toward
	the West.
[=]
	The sample shows the same spacecraft as the one in the Down
	mode above.  In the down mode it was difficult to really 
	discern how far above or below the level line the Up and Left
	faces were, but in this mode you can now see they are both
	quite level with the ground.
[=]
	This mode is not terribly useful on its own, but when combined
	with the down mode it does make it easier to see the spacecraft
	orientation when related to the ground.
[e-]
[=]
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
	The prograde mode is the third mode and is the most used mode
	for orbital operations.  The reference vector for this mode
	starts at the spacecraft and goes in the direction the spacecraft
	is travelling.  The observer reference point for this mode is
	directly behind the spacecraft, think of it as a trailer that is
	following behind the spacecraft.
[=]
	The axis names are now relative to the spacecraft's orbit.  The
	left and right axis represent the Orbit Normal orientation of the
	spacecraft, when a face is centered then it is directly inline
	with the direction of travel, when the face is left or right then
	it is facing either above the orbital plane (norm) or below the
	orbital plane (anorm).  The top and bottom axis represents the
	inside/outside orientation of the face.  If the face is centered
	on this axis then it is oriented along the flight vector, else it
	is either oriented outside the orbit or inside the orbit.  
	Uppercase letters represent faces that are oriented away from the
	direction of travel and lowercase faces are those oriented closer
	to the direction of travel.
[=]
	The spacecraft shown in the sample is the same spacecraft shown
	in the first 2 modes.  From here we can see that the Up face
	is directly oriented with the direction of flight, the Forward
	face is on the orbtial plan, but oriented directly outside the
	orbit, away from the orbit center.  The Left face is way off the
	orbital plane and oriented in the Orbit Antinormal direction.
[e-]
[=]
[=]
[er]
	+-------------------------+
	|    LOOKING   -X         |
	| +========-Y|==========+ |
	| |                     | |
	| |                     | |
	| |                     | |
	| |                     |+|
	| |                     |Z|
	|--          F          --|
	|-|                     | |
	|Z|                     | |
	| |                   l | |
	| |                     | |
	| |     u               | |
	| +==========|+Y========+ |
	+-------------------------+
[ee]
	The final mode is absolute mode.  In the first three modes the
	reference vector constantly changes as the spacecraft orbits.
	This mode however uses a fixed reference vector and as such
	using this mode you can set an orientation that will remain
	constant no matter where in the orbit the spacecraft is.
[=]
	Space is divided up into 3 dimensions, X, Y, and Z.  In this
	mode the reference line extends from the spacecraft towards
	the negative X coordinate of space.  The observer reference
	point is then along the X axis in the positive direction looking
	through the spacecraft along the X axis in the negative direction.
[=]
	The face symbols then represent where in 3d space they are 
	pointing.  Left and right represent the Z axis, and is analogous
	to the North and South directions.  In fact if a face is facing
	in the +Z direction, it is facing towards the universal North.
[=]
	This mode is used when you want to put the spacecraft into a
	known orientation that will remain constant.  A good use of this
	is at the Moon.  By setting a known orientation before undocking
	then when you return from the Moon you will know exactly how the
	CSM is oriented for rendevous and docking.
[e-]
[=]
[=]

