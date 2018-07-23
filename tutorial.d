[C]     Lunar Mission Simulator
[C]     by
[C]     Mike Riley
[=]
	In this tutorial we will go through all the steps for planning and
	executing a mission to the Apollo 11 landing site.  This tutorial
	assumes that you have done the training exercises and are familiar
	with the instrument panels.
[=]
[H2]	Mission Planning
[=]
	We will start by planning the mission.  Load the planner program.
[=]
[ER]
	+-----------------------------------+
	|       Lunar Mission Simulator     |
	|                                   |
	|           Mission Planner         |
	|                                   |
	|                                   |
	|  1. Create new mission profile    |
	|  2. Load existing mission profile |
	|  3. Exit                          |
	|                                   |
	|        Option ?                   |
	+-----------------------------------+
[EE]
	After starting the planner, you should see this menu.  Since we
	will be creating a new mission press <1>.
[E-]
[=]
[ER]
	+---------------------------------+
	| 1. Mission Name   :Not Defined  |
	| 2. Description    :Not Defined  |
	| 3. Landing Region :Not Defined  |
	| 4. Landing Site   :Not Defined  |
	| 5. Primary Site   :Not Defined  |
	| 6. Secondary Site :Not Defined  |
	| 7. Secondary Site :Not Defined  |
	| 8. Secondary Site :Not Defined  |
	| 9. Vehicle        :Apollo Mk II |
	+---------------------------------+
[EE]
	This will take us to the mission planning menu.  Currently the
	only thing defined is the vehicle to fly the mission in.  The
	Apollo Mk II lander is the default lander used by LMS and so
	it is selected here by default.  This mission could actually
	be flown with any of the available landers, but since we will
	want a rover on our mission, we will just use the default 
	lander.
[E-]
[=]
	We will start by giving our mission a name.  Press the <1> key
	to select Mission Name.  The line will clear and the cursor will
	be placed on the line ready for our input.  Enter this name:
[=]
[I+4]
	Lunar I
[=]
[I-4]
	When you are done entering the name, press <Enter> to record
	the name.
[=]
	Mission names are usually short, often a series name followed
	by a serial number, like Apollo 11, Apollo 12, etc.  I had a
	series of Zeus missions which I flew to each of the Apollo
	landing sites, Zeus I landed at the Apollo 11 site, Zeus II
	landed at the Apollo 12 landing site, and so forth.  I generally
	use a different series name for different types of missions.
[=]
	Next lets give our mission a description, press the <2> key
	to select the description line and then enger:
[=]
[I+4]
	Apollo 11 Landing Site
[=]
[I-4]
	While the name gives a identifier to the mission, the description
	should give the overall goal of the mission.
[=]
[ER]
	+--------------------------------------+
	|               Category:              |
	|     CraterR                          |
	|     CraterS                          |
	|     CraterT                          |
	|     CraterU                          |
	|     CraterV                          |
	|     CraterW                          |
	|     CraterX                          |
	|     CraterY                          |
	|     CraterZ                          |
	|     Craterl                          |
	|     Lacus                            |
	|---> Manmade                          |
	|     Mare                             |
	|     Mons                             |
	|     Mont                             |
	|     Montes                           |
	|     Palus                            |
	+--------------------------------------+
[EE]
	Now it is time to specify where we want to land.  Press the <3>
	key to begin landing region selection.  You will be presented
	with a list of categories to choose from.  There are nearly
	9,000 lunar features in LMS's database, divided up into 
	categories to make them easy to find.  Using the arrow keys
	go down the list until you reach 'Manmade' and then press the
	<Enter> key.
[E-]
[=]
[ER]
+------------------------------------------------------+
|---> Manmade Apollo 11                0.67N    23.47E |
|     Manmade LRRR-11                  0.67N    23.47E |
|     Manmade Flag-11                  0.67N    23.47E |
|     Manmade Apollo 12                3.01S    23.42W |
|     Manmade ALSEP-12                 3.01S    23.42W |
|     Manmade Flag-12                  3.01S    23.42W |
|     Manmade Apollo 12 Ascent Debris  3.94S    21.20W |
+------------------------------------------------------+
[EE]
	After you have selected a category, you will be given a list
	of features under the selected category.  The list will contain
	the name of the feature as well as the latitude and longitude
	where the feature is located.
[=]
	You can use the arrow keys to move up and down through the list.
	In the case of larger lists you can use the <PgUp> and <PgDn>
	keys to page forward and back to move quickly through the list.
	Go ahead and take a quick look through the list to see all the
	various manmade objects you can visit.
[=]
	After you are done browsing, move the arrow to the Apollo 11
	line and press the <Enter> key to select the site.
[E-]
[=]
	After selecting your target you will be taken back to the main
	planning screen, which should now look like:
[=]
[C]	+----------------------------------------------------------------+
[C]	|   1. Mission Name   :Lunar I                                   |
[C]	|   2. Description    :Apollo 11 Landing Site                    |
[C]	|   3. Landing Region :Manmade Apollo 11                         |
[C]	|   4. Landing Site   :Latitude:    0.6741, Longitude:   23.4731 |
[C]	|   5. Primary Site   :Not Defined                               |
[C]	|   6. Secondary Site :Not Defined                               |
[C]	|   7. Secondary Site :Not Defined                               |
[C]	|   8. Secondary Site :Not Defined                               |
[C]	|   9. Vehicle        :Apollo Mk II                              |
[C]	+----------------------------------------------------------------+
[=]
	Your landing Site has been filled in from the latitude and longitude
	of the selected feature.  We actually need to make an adjustment
	to this, since we do not want to land on top of the Apollo 11
	descent module.  Press the <4> to make an adjustment to the landing
	site.
[=]
[ER]
	+-------------------+
	|              o    |
	|   ,             . |
	|  ,            o   |
	|       OOO         |
	|         |         |
	|       _f|         |
	|       --1--  ,    |
	|         |  O      |
	|         |         |
	|                   |
	|               o   |
	|+           o  ,   |
	+-------------------+
	+---------------+
	| Latitude:     |
	|    0.6741     |
	|               |
	| Longitude:    |
	|   23.4731     |
	|               |
	| Dist North:   |
	|      0.00m    |
	|               |
	| Dist East:    |
	|      0.00m    |
	+---------------+
[EE]
	This will bring you to the map screen.  On the left side of the
	screen is a large map of the selected area.  On the map is a 
	targeting cross, that is currently centered on top of the Apollo
	11 descent mode, the '1' in the middle of the cross.
[=]
	On the right is a panel that shows the latitude and longitude of
	where the targeting cross is located.  Below the latitude and
	longitude the panel shows the distance north and east of the
	currently defined landing spot.
[=]
	You can use the arrow keys to move the targetting cross around
	the map.  If you move off the edge of the map, the map will
	scroll so that you can examine larger areas than what fit on
	the screen.
[E-]
[=]
[ER]
        +-------------------+
        |              o    |
        |   ,             . |
        |  ,            o   |
        |       OOO         |
        |                   |
        |       _f          |
        |         1    ,    |
        |    |       O      |
        |    |    ,         |
        |  -- --            |
        |    |          o   |
        |+   |       o  ,   |
        +-------------------+
[EE]
	Use the arrow keys to move the targetting cross to the open
	area to the left and below the Apollo 11 descent module.
[=]
	Pressing the <Enter> key will return to the mission planning 
	screen and set the coordinates to the selected item.  Pressing
	the <Esc> key will exit the map window without setting the
	coordinates.
[=]
	Since we want to keep this new position as our landing site,
	press the <Enter> key to record the new coordinates.
[E-]
[=]
	The mission planner allows you to define a primary sampling site
	and up to the 3 secondary sites.  Lets define our primary
	sampling site by pressing the <5> key.
[=]
[ER]
        +-------------------+
        |              o    |
        |   ,             . |
        |  ,            o   |
        |       OOO         |
        |                   |
        |       _f          |
        |         1    ,    |
        |    |       O      |
        |    |    ,         |
        |  -- --            |
        |    |          o   |
        |+   |       o  ,   |
        +-------------------+
[EE]
	This will take us back to the map screen.  Since the primary
	site had not yet been defined, the targetting cross will start
	out at our specified landing location.
[=]
	Take notice that while you move the targetting cross around that
	the Dist North and Dist East values change.  When selecting 
	sampling sites these numbers always tell you the distance to
	your defined landing location.  This lets you easily see how far
	you will have to travel to any of your sampling sites.
[E-]
[=]
[ER]
	+-------------------+
	|              o    |
	|   ,             . |
	|  ,            o   |
	|       OOO         |
	|         |         |
	|       _f|         |
	|       --1--  ,    |
	|         |  O      |
	|         |         |
	|                   |
	|               o   |
	|+           o  ,   |
	+-------------------+
[EE]
	Using the arrow keys, move the targetting cross over the top
	of the Apollo 11 descent module.  This will define the center
	of our primary sampling site.  Any sample that is collected
	within 200 meters of this location will be considered to have
	been collected from this sampling site.
[=]
	Once you have the targetting cross in the correct location
	press the <Enter> key to record the coordinates for our
	primary sampling site.
[E-]
[=]
	When you get back to the planning screen you can see that now
	our primary site has been defined:
[=]
[C]	+----------------------------------------------------------------+
[C]	|   1. Mission Name   :Lunar I                                   |
[C]	|   2. Description    :Apollo 11 Landing Site                    |
[C]	|   3. Landing Region :Manmade Apollo 11                         |
[C]	|   4. Landing Site   :Latitude:    0.6725, Longitude:   23.4741 |
[C]	|   5. Primary Site   :Latitude:    0.6741, Longitude:   23.4731 |
[C]	|   6. Secondary Site :Not Defined                               |
[C]	|   7. Secondary Site :Not Defined                               |
[C]	|   8. Secondary Site :Not Defined                               |
[C]	|   9. Vehicle        :Apollo Mk II                              |
[C]	+----------------------------------------------------------------+
[=]
	For this tutorial we will not define any of the secondary sites,
	but feel free to do so if you wish.  They are defined in exactly
	the same way as the primary site was defined.
[=]
	Once you are happy with the mission profile, press the <s> key
	to save to mission profile.  You will be asked for a name to
	save the mission under, for this tutorial enter:
[=]
[I+4]
	LunarI
[=]
[I-4]
	After the mission is saved you will be returned to the main menu
	for the mission planner.  As we are done defining missions, you
	can just press the <3> key to exit.
[=]



