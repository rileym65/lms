[c]	Mission Planning
[=]
	In the prior landing tutorial we ended up landing where it was most
	convenient from the Lunar orbit that we had achieved having arrived
	from Earth.  But if you would like to explore a specific spot on the
	Moon then you will need to have a proper Lunar orbit.  I do not 
	possess the requisite knowledge to plot out how to get to the Moon
	in the right orbit to explore a specific location, but LMS does
	allow us to start in Lunar orbit, in an orbit of our choosing, this
	allows us easily land anywhere on the Moon that we would like to
	explore.
[=]
	In this next series of tutorials we will plan and fly a mission to
	the Apollo XII landing site.  Since this mission will be starting
	in Lunar orbit, you will not need the prior knowledge of launching
	from Earth and getting to the Moon.  Although, going through the
	prior Lunar landing tutorial is probably a good idea.  I will be
	covering all the landing steps in this series, but probably not in
	as great a detail as the prior landing tutorial.
[=]
	There is however one important difference with this landing.  In
	the prior tutorials we landed at a location that was under our
	Lunar orbit.  In this tutorial we will be landing at a site that is
	not in the same plane as our Lunar orbit and therefore will require
	plane change maneuvers to land as well as to rendevous again with
	the CSM.
[=]
[er]
	+----------------------------------+
	|      Lunar Mission Simulator     |
	|                                  |
	|          Mission Planner         |
	|                                  |
	|                                  |
	| 1. Create new mission profile    |
	| 2. Load existing mission profile |
	| 3. Exit                          |
	|                                  |
	|       Option ?                   |
	+----------------------------------+
[ee]
	  Start by loading the mission planner.  You will be presented with the
	option of either creating a new mission, or loading an existing one.
	Select option 1 to start a new mission profile.
[e-]
[=]
[er]
	+----------------------------------------------+
	| A. Mission Name   :Not Defined               |
	| B. Description    :Not Defined               |
	| C. Landing Region :Not Defined               |
	| D. Landing Site   :Not Defined               |
	| E. Primary Site   :Not Defined               |
	| F. Secondary Site :Not Defined               |
	| G. Secondary Site :Not Defined               |
	| H. Secondary Site :Not Defined               |
	| I. Vehicle        :Apollo Mk II              |
	| J. Loadout                                   |
	| K. CSM Orbit      : LAN:  90.00  INC:   0.00 |
	+----------------------------------------------+
[ee]
	After you select to create a new mission, the mission profile
	screen will appear.  This screen shows all the current parameters
	for the mission.  At first these will mostly be 'Not Defined'.
	As we define each of the parameters this screen will update to
	show the parameters for the mission.  In general, when planning a
	mission, you should should just start from the top and work your
	way down the list.
[e-]
[=]
[er]
	+----------------------------------------------+
	| A. Mission Name   :Apollo XIIa               |
	+----------------------------------------------+
[ee]
	For this mission, we will be visiting the Apollo XII landing site,
	so select option 'A' and when prompted, type 'Apollo XIIa'
[e-]
[=]
[er]
	+--------------------------------------------------+
	| B. Description    :Visit Apollo XII Landing Site |
	+--------------------------------------------------+
[ee]
	Next we need to give our mission a description.  Select option 'B;
	and when prompted, enter 'Visit Apollo XII Landing Site'
[e-]
[=]
[er]
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
[ee]
	Next we need to specify the region of the Moon that we will be
	exploring.  Select option 'C'.  The planner will then bring up a
	list of categories.  The mission planner has a large database of
	various features on the Moon, all divided into categories to make
	landing site selection fairly easy.  Using the down arrow, scroll
	down to select the 'Manmade' category and the press <ENTER>
[e-]
[=]
[er]
	+-----------------------------------------------------+
	|     Manmade Apollo 11               0.67N    23.47E |
	|     Manmade LRRR-11                 0.67N    23.47E |
	|     Manmade Flag-11                 0.67N    23.47E |
	|---> Manmade Apollo 12               3.01S    23.42W |
	|     Manmade ALSEP-12                3.01S    23.42W |
	|     Manmade Flag-12                 3.01S    23.42W |
	|     Manmade Apollo 12 Ascent Debris 3.94S    21.20W |
	+-----------------------------------------------------+
[ee]
	You will then be presented with a list of potential landing sites.
	The 'Manmade' list contains all of the Apollo missions as well as
	many other probes that have been sent to the Moon.  The list contains
	the name of the feature as well as the coordinates of where this
	feature is located on the Moon.  Using the arrow keys, scroll down
	to the 'Apollo 12' entry and press <ENTER> to select it.
[e-]
[=]
[er]
	+--------------------------------------------------------------+
	| C. Landing Region :Manmade Apollo 12                         |
	| D. Landing Site   :Latitude:   -3.0128, Longitude:  -23.4219 |
	+--------------------------------------------------------------+
[ee]
	After selecting your site you will be returned to the planning screen
	and you will see that options 'C' and 'D' have now been filled in.
	The landing coordinates are currently right on top of the Apollo XII
	descent stage.  Since we do not want to damage the Apollo XII site,
	we want to land several hundred meters away from it, so we will
	reset our landing site.  Select option 'D'.
[e-]
[er]
	+-----------------------------------------------------------+
	|                o               .     "         ,          |
	| O     O                           ,   O                   |
	|                                                   ,       |
	|   .                                ,                 +    |
	|                      ,               ,                    |
	|        ^                                                 *|
	|                                              ,           ,|
	|                             |                             |
	|            , .   o          |      +        .          ,+ |
	|                   o       --2--       o                   |
	|    u               +        |                         o  ,|
	|    o      *                 |    ,        o         ,     |
	|                ,    o   ,                      ,          |
	|,   ,                ,        ,,  +  .        O  +*        |
	|              O                       ,                    |
	|                  +                        +     +         |
	|   ,   ,u ,  .        .                    *    , . O o    |
	|                      ,+    f                ,           . |
	|         + ,                    ,                       ,  |
	+-----------------------------------------------------------+
[ee]
[e-]
[=]
	This will take us to a map screen that allows us to select our landing
	site.  Lets take a quick look at this map before making any changes.
[=]
	First, in the center you will see a crosshair that is currently over
	the '2' character.  The crosshair shows our current coordinate pointer.
	The '2' represents the Apollo XII descent stage.  On this map we
	can also see two other things related to Apollo XII.  In the low
	center potion of the map there is an 'f' character, this is the flag
	that was planted by the Apollo XII crew.  In the upper portion of
	the map, and about halfway from center to the right edge there is an
	'"' character, this is the Apollo XII surface experiments package.
[=]
[er]
	+----------------+
	|  Latitude:     |
	|    -3.0128     |
	|                |
	|  Longitude:    |
	|   -23.4219     |
	|                |
	|  Dist North:   |
	|       0.00m    |
	|                |
	|  Dist East:    |
	|       0.00m    |
	+----------------+
[ee]
	To the right of the map you will see the pointer information panel,
	this shows the current latitude and longitude of the crosshair and
	how far the crosshair has been moved from the reference position.
	The reference position is what the latitude and longitude were when
	this screen is first entered.
[=]
	Since we have not yet moved the crosshair, the relative distance is
	zero meters.  We want to land 500 meters south of the Apollo XII
	site, so using the left arrow, move the crosshair to the left until
	the 'Dist North:' value shows -500.00m.  Once you have the North
	distance at -500 meters, the East distance should still be zero
	meters, press <ENTER> to confirm our new landing coordinates.
[e-]
[=]
	Now that our landing site has been selected, it is time to specify
	the sites we wish to explore.  Since this primary purpose of this
	mission is to visit the Apollo XII landing site, we will set that
	as our Primary site.  Select option 'E' to begin selection of our
	primary site.
[=]
[er]
	+----------------+
	|  Latitude:     |
	|    -3.0128     |
	|                |
	|  Longitude:    |
	|   -23.4219     |
	|                |
	|  Dist North:   |
	|     500.00m    |
	|                |
	|  Dist East:    |
	|       0.00m    |
	+----------------+
[ee]
	You will be taken to the same map screen that we used to select
	our landing site.  The crosshair will be located at our landing site,
	which is 500 meters south of the Apollo XII landing site, so using
	the right arrow, move the crosshair to the right until 'Dist North:'
	shows 500 meters, which should be back on top of the Apollo XII
	descent stage, the '2' symbol on the map.  Once the crosshair is on
	the '2' symbol, press <ENTER> to confirm this as our primary site.
[e-]
[=]
	The planner allows you to specify up to three secondary exploration
	sites.  There are two large craters in the vicinity of the Apollo XII,
	so we will set secondary sites to these two craters.  To set the
	first secondoary site, select the 'F' option.
[=]
[er]
	+----------------+
	|  Latitude:     |
	|    -3.2000     |
	|                |
	|  Longitude:    |
	|   -23.4176     |
	|                |
	|  Dist North:   |
	|   -5180.00m    |
	|                |
	|  Dist East:    |
	|     130.00m    |
	+----------------+
[ee]
	This will take us back to the map screen, again with the crosshair
	located at our landing site.  The first crater we want to explore
	is about 5km south of our landing site, and just a little bit east.
	Use the arrow keys to locate the crater.  If you set your landing
	site as described earlier, then the coordinates I show here should
	put you on the western rim of the crater.  After you have found the
	crater and positioned the crosshair on the site you want to explore,
	press the <ENTER> key to confirm your site selection.
[e-]
[=]
[er]
	+----------------+
	|  Latitude:     |
	|    -2.8997     |
	|                |
	|  Longitude:    |
	|   -23.4176     |
	|                |
	|  Dist North:   |
	|    3930.00m    |
	|                |
	|  Dist East:    |
	|     130.00m    |
	+----------------+
[ee]
	Now lets select the second crater as a secondary site, select option
	'G'.  This crater will be located almost 4km north of our landing
	site, and again a little bit east.  Here are the coordinates that
	should put you right on the western rim of the crater.  Select the
	site you want to explore, and then press <ENTER> to confirm your
	site your site selection.
[e-]
[=]
	If you want you can select option 'H' and look around for a third
	secondary site, but for this tutorial I will not define a third
	secondary site.
[=]
[er]
	+------------------------------+
	| Vehicle:    1. Apollo        |
	|          -->2. Apollo J      |
	|             3. Apollo Mk II  |
	|             4. Apollo Mk III |
	+------------------------------+
[ee]
	The next thing we need to do is to select the vehicle that we will
	be flying for this mission.  Select option 'I' to go to the vehicle
	selection screen.  The top part of the screen shows the available
	vehicles, the bottom portion shows the specifications of the
	selected vehicle.  For this mission, select 'Apollo J' as the
	vehicle to fly, then press <ENTER> to confirm your selection.
[e-]
[=]
	At this point all of the important items for our mission have been
	defined.  You can take a look at the 'Loadout' for the mission by
	selecting option 'J'.  Normally the mission loadout will be a
	fully fueled, fully provisioned, and contain all surface equipment.
	You do not normally need to change anything on this screen.
	You can just press the <ESC> key when you are done looking at this
	screen.
[=]
	Option K of the mission planner would allow you to change the
	orbit of the CSM around the Moon, but for this mission we will
	leave it in the default equitorial orbit.
[=]
[er]
	+--------------------------------------+
	|                                      |
	|           Save Mission As:           |
	|                                      |
	|         ApolloXIIa                   |
	|                                      |
	+--------------------------------------+
[ee]
	Now that our mission profile is complete, select option 'S' to
	save the profile, When prompted for a name, enter 'ApolloXIIa'
	and press <ENTER>
[e-]
[=]
	You can now exit from the mission planner.
[=]
	The mission we outlined in this tutorial is a bit more complicated
	to fly than the landing tutorial.  In the landing tutorial, no 
	plane change was required to land.  In this mission, the landing
	site is not on the flight path of the CSM and therefore a plane
	change maneuver will be required when landing this mission, and
	another plane change maneuver will be required when returning to		the CSM.  I will cover exactly how to fly this mission in the next
	couple tutorials.
[=]

