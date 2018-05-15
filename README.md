# lms
Text based lunar mission simulator

Back in the late 80s there was a shareware game called Apollo Mission Simulator written by Albert H. Reynolds III.  This was one of my favorite lunar lander type games.

Recently I have wanted to play this again and although AMS runs just fine in DosBox, there were some things about it that I would have liked to change.  I tried tracking down the author of AMS and was not successful.

This project is meant to create a lunar mission simulation game that gives a similar experience to AMS but has source code available and can be made to run on modern systems.

At this point in time the simulation is mostly operational.  Documentation is really poor at this point and it would be a good idea to look at the documentation for AMS (easily locatable on the web) before attempting to play this simulation.

As improvements over the original game, the metabolism/efficiency has been changed to be less frustrating.  The instrument panels can now difer depending on which vehicle the pilot is located in, and the panels are configured using simple text files which allows the player to arrange instrument panels in ways that make more sense to them.

This simulation will also give a mission report on the successful completion of a mission highlighting details of the mission.

All hardware left on the surface of the moon, for example the descent module, rover, flags, debris from crashes, etc are recorded in a user reference file so that these sites can be revisited on future missions and find the relevant hardware/debris at their original locations.

The physics for spacecraft motion is pretty solid, but some instruments have issues that still need to be resolved, for example the prograde modes of the axis displays tend to show erroneous information when orbits are way out of round, like during powered descent.

The lunar surface is currently randomly generated and is based upon position seeds, therefore future missions will encounter the same lunar features.  I have started a module to generate the lunar surface based upon lunar features.  The map generator currently uses this method for the high altitude maps and therefore generates a map that does resemble the moon, this method needs to be extended down to medium and low altitude maps.
