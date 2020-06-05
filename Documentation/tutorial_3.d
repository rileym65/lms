[c]	Booster Separation/TD&E
[=]
	This tutorial covers booster separation as well as the
	Transpoistion, Docking, and Extraction of the Lunar Module.
	This tutorial assumes that you are currently in orbit, still
	connected to the launch vehicle and that you have brought a
	LM with you into orbit.
[=]
[=]
[er]
	+--------------------------+
	|          ----------:     |
	|      ^                   |
	| +----|----+ pX: ---.---- |
	| |         | dX: ---.---- |
	| |         |              |
	|<-    +    - pY: ---.---- |
	| |         | dY: ---.---- |
	| |         |              |
	| +----|----+ pZ: ---.---- |
	|      v      dZ: ---.---- |
	+--------------------------+
[ee]
	Before we get started with the maneuvers, lets first get
	acquainted with the docking radar on the CSM.  The Docking
	Radar is located on the right side of the CSM panel and
	consists of several sections.
[=]
	On the left side of the radar panel is a graphic depiction of
	your alignment to the target (LM) and consists of 3 orientation
	arrows and lateral position crosshair.
[=]
	The orientation arrows are located on the outside edge of the
	radar graphic.  When the arrows are all pointing outwards, as
	in the sample here, it indicates the that radar does not have
	a lock on the target.  When the radar has acquired a target then
	the arrows will all face inwards and will be position along their
	respective edges in relation to the rotation angles of the CSM
	to the LM.
[=]
	The arrow on the top edge represents the roll angle and when it
	is centered the spacecraft's roll angle is correct for docking.
	The arrow on the left edge represents the pitch angle and when it
	is centered then the spacecraft's pitch angle is correct.  The
	arrow along the bottom represents the yaw angle and will be
	centered when the CSM's yaw is correct for docking.  All three
	arrows must be pointed inwards and centered for a successful
	docking to occur.
[=]
	The lateral position crosshair is positioned inside the radar
	graphic and represents your lateral, X and Y, position in relation
	to the target docking port.  When the crosshair is centered then
	you are aligned with the docking port.  If the crosshair is not
	centered then you will need to thrust towards where the crosshair
	is to center it.
[=]
	The right half of the radar panel has precision positioning
	information.  When the radar does not have a target lock all you
	will get are the lines, as shown here.  When the radar does have
	a target lock then these 6 values will show your precise position
	(pX, pY, and pZ) in relation to the docking port as well as the
	velocity information for each axis (dX, dY, dZ).
[=]
	Not shown in this graphics, but there is also an ALIGN annunciator
	that will be lit when the spacecrafts orientation and lateral
	position are correct for docking.  When the ALIGN indicator is lit
	then docking can be accomplished.  If the indicator is not lit then
	any docking attempt will fail.
[e-]
[=]
[=]
[er]
	+--------+
	| R    P |
	|     04 |
	|   V  N |
	|  37 04 |
	| +00137 |
	| +00000 |
	| +14480 |
	+--------+
[ee]
	1. At this point we are still attached to the booster vehichle.
	The LM is attached to the top of the SIVB below the Service
	Module.  In this configuration the docking radar cannot see the
	LM.  The docking radar needs to be angled towards the LM before
	it can acquire a target lock and begin to give us information.
[=]
	Since the docking radar cannot give us any distance information
	until after we have separated from the booster and turned around
	to point the docking radar at the LM we will need a different
	means to know how far from the LM we are.  Program 04 in the
	guidance computer will give us what we need, so execute [V37N04].
	When program 04 is running, register 1 shows our Z position to
	the LM in meters times 10.  So right now register 1 is showing
	us 00137, which is 13.7 meters, which is the distance from the
	center of the CM to the center of the ascent stage of the LM.
	When docked this distance is 5.2 meters, we are currently 13.7
	meters away because the SM module is between us and the LM.
	Register 2 shows the Z velocity in meters/second times 1000,
	so a velocity of 0.1m/s will show as 00100 in register 2.
[e-]
[=]
[=]
[er]
	+---------+
	| RTH:--  |
	| TTH:--  |
	+---------+
[ee]
	2. Now that we can see our distance from the LM we are ready
	to undock.  Press the <tab> key to arm the booster jettison pyros
	and then press <shift><j> to jettison the booster.  You will now
	see the number in reigster 1 of the guidance computer increasing
	slowly and register 2 should show that we are moving away from
	the LM at about 0.1m/s.
[=]
	We want to get about 20 to 25 meters away before our turn, which
	will take a moment.  During this time set the RCS translation
	throttle to medium using the <-> and <=> keys.  Also set the
	RCS rotation throttle to medium using the <shift><-> and 
	<shift><=> keys.
[e-]
[=]
[=]
[er]
	+--------+
	| R    P |
	|     04 |
	|   V  N |
	|  37 04 |
	| +00216 |
	| +00000 |
	| +14480 |
	+--------+
[ee]
	3. Keep an eye on register 1.  When it gets to +00200 (20 meters)
	then press <d> to activate the down RCS thruster to start slowing
	down.  You want to press the <d> again to stop the RCS thruster
	when the number in register 2 reaches 0.  You may not be able to
	get exactly 00000, and that is ok, but it is better to be in the
	negative numbers than the positive.  If the number is negative 
	then you are still moving away from the LM, whereas if the number
	is positive you are moving towards it.  It will take time to turn
	the CSM to face the LM as well as position it correctly and we
	do not want to be moving towards the LM until after we are
	properly oriented and position for docking.
[e-]
[=]
[=]
[er]
	+--------------------------+
	|          ----------:     |
	|      v                   |
	| +----|----+ pX:  -0.0000 |
	| |    +    | dX:  +0.0000 |
	| |         |              |
	|>-         - pY:  -0.6711 |
	| |         | dY:  -0.0071 |
	| |         |              |
	| +----|----+ pZ: +21.7554 |
	|      ^      dZ:  +0.0023 |
	+--------------------------+
[ee]
	4. After you have stopped, or at least slowed your Z velocity it
	is time to orient the spacecraft correctly for docking.  Coming
	off the booster the pitch and roll will already be correct, it
	is only the yaw angle we need to use.  Press the <numpad><4>
	key 4 times to begin a 2 degree per second left yaw.
[=]
	Now just watch the radar display, after the CSM has turned far
	enough the radar will acauire a target lock on the LM and you
	will see all the arrows flip inwards as well as the
	position/velociy values appear.  The roll (top) and pitch (left)
	arrows should be centered and the yaw arrow (bototm) will be to the 
	far right side.
[=]
	Keep watching the radar panel, when the yaw arrow starts to move
	press the <numpad><6> key twice to slow your yaw rate to 1
	degree per second and when the arrow centers then press the
	<numpad><6> key twice more to stop your yaw.
[=]
[=]
	5. Now lets look at the numbers in the pX and pY registers.  These
	need to be between -0.5 and +0.5 in order to dock, otherwise you
	are too far off from the center of the docking port.  The numbers
	in the dX and dY show your movement, if the sign of the d register
	is opposite the sign of the p register then you are moving closer
	to centerline, otherwise if they are the same you are moving away.
[=]
	In the sample, pX is perfect and it also shows we are not moving
	in the X direction, so nothing needs to be done with this.  pY
	on the other hand is outside the docking range and dY says we are
	moving further away so this we do need to fix.
[=]
	The X coordinate is controlled by the left and right thrusters,
	the Y coordinate is controlled by the forward and backward 
	thrusters.  So in the sample we need to fire the forward thruster
	so that we will be moving in the positive direction and then when
	pY nears zero you will need to fire the back thruster to null
	out the movement.  So in this case we would press the <f> 
	thruster until dY showed a positive value and then press the <f>
	key again to stop the thruster, then when pY neared zero we
	would press the <b> key to fire the backwards thruster until
	the velocity in dY nears zero and then press the <b> key again
	to stop the thruster.
[e-]
[=]
[=]
[er]
	+--------------------------+
	|          ----------:     |
	|      v      Align        |
	| +----|----+ pX:  +0.0000 |
	| |         | dX:  -0.0000 |
	| |         |              |
	|>-    +    - pY:  -0.0419 |
	| |         | dY:  +0.0018 |
	| |         |              |
	| +----|----+ pZ: +21.9440 |
	|      ^      dZ:  +0.0031 |
	+--------------------------+
[ee]
	6. Until you have gotten your X and Y into alignment, do not
	worry about your Z alignment.  The only thing you really care
	about the Z axis right now is that you are not moving towards
	the LM, nor moving away from it too quickly.  Just keep the value
	in dZ to some small positive number, as shown here.  The Z axis
	is controlled using the up and down thrusters.
[=]
	When your pX and pY position are in the correct range for docking
	you will see the "Align" annunciater show up, at this point you
	should bring the numbers in dX and dY close to zero and from here
	until the end of the docking keep the signs of pX and dX different
	and the signs of pY and dY different.
[e-]
[=]
[=]
[er]
	+--------------------------+
	|          ----------:     |
	|      v      Align        |
	| +----|----+ pX:  -0.0449 |
	| |         | dX:  +0.0037 |
	| |         |              |
	|>-    +    - pY:  +0.0090 |
	| |         | dY:  -0.0001 |
	| |         |              |
	| +----|----+ pZ: +11.3189 |
	|      ^      dZ:  -0.3060 |
	+--------------------------+
[ee]
	7. Once everything is aligned and you have your lateral X and
	Y velocities set low it is time for the docking approach.  Press
	the <u> key to activate the upwards thruster.  Keep an eye on
	the value in the dZ field, this is your closing velocity.  You
	want this number between -0.2 and -0.4, -0.3 is the preferred
	docking velocity.  When you get to the desired docking velocity
	press the <u> key again to disengage the upwards thruster.
[=]
	A docking velocity slower than -0.2 will be too slow for the
	docking clamps to engage once contact is made you you will
	bounce off the LM.  A docking velocity faster than -0.4 and the
	docking force will be too great for the docking clamps to engage
	before the CSM bounces off the LM.  Too fast a docking velocity
	also risks damaging either or both spacecraft, so keep it at -0.3
	to be right down the middle of the safe zone.
[=]
	During the docking approach keep an eye on your pX and pY
	positions and makes sure to keep them near zero all the way
	to the docking port.  Docking will occur when the value in pZ
	reaches +5.2.  
[e-]
[=]
[=]
[er]
	+-----------------------+
	| BSP         DCK       |
	|             BST       |
	|                       |
	+-----------------------+
[ee]
	8. Once contact with the LM docking port is made the docking
	clamps will latch and retraction will occur automatically.
	You will see a 'Docking:' message appear in the message area
	of the docking radar panel.
[=]
	The DCK lamp will also light on the annunciator panel to indicate
	the you are now docked with the LM.
[e-]
[=]
[=]
[er]
	+-----------------------+
	| BSP         DCK       |
	|                       |
	|                       |
	+-----------------------+
[ee]
	9. The last step is to extract the LM from the SIVB, this is
	accomplished by pressing the <shift><e> key.  The BST lamp
	on the annunciator panel will go out showing that the booster
	vehicle is no longer attached to the LM.
[=]
	At this point press the <d> to activate the down thruster so
	that we can get some separation between us and the SIVB.  Leave
	the down thruster on for about 5 seconds and then press the <d>
	key again to deactivate the down thruster.  TD&E is now complete.
[e-]
[=]
[=]
