[c]	Lunar Mission Simulator
[c]	by
[c]	Michael H. Riley
[=]
	LMS is a retro style Lunar landing/mission simulator.  It is
	inspired by the text based lunar landing games from the early
	days of personal computers and more directly by the text based
	Apollo Mission Simulator (AMS) by Albert H. Reynolds III, which
	was released in the late 80s.
[=]
	Way back when I was playing these early games I had spent many
	hours playing AMS, although there were two changes I would have
	liked in the game.  First was the metabolic rate/efficiency used
	by the game was seriously flawed, leading to many crashes that
	were more an artifact of the RNG ignoring keystrokes for too long
	at critcal times rather than a failure in my decision making.
	The second thing I would have liked back then was a full mission
	simulator, where the mission started on Earth and you had to
	launch, fly to the moon, land, and then come back.  AMS started
	in Lunar orbit and the game ended back in Lunar orbit.
[=]
	With my recent desire to play AMS again I dug up my copy and once
	again desired to make changes to the game.  I tried to locate the
	author to see if source code was available, but after so much
	time since AMS was released my search was fruitless.  And so LMS
	was born.  My main goals were to maintain the retro text based
	experience that AMS provided, but with source code that would be
	available and be able to run on modern systems and to make the
	changes that I would have liked to have seen in AMS.
[=]
	This package is the current result of my work.  Although this
	package is not 100% complete, the simulator is quite playable and
	is in fact mostly complete.  The documentation on the other hand
	is horribly sparse, but will be improved upon over time.
[=]
	LMS can also simulate more than just the Apollo missions.  It can
	simulate the following vehicles:
[=]
[i4]
[lb]
[li]	Mercury/Redstone
[li]	Mercury/Atlas
[li]	Germini/Titan II
[li]	Apollo/Saturn 1B
[li]	Apollo/Saturn V
[li]	Apollo J/Saturn V
[li]	Apollo MkII/Saturn VB (fictional)
[le]
[i-4]
[=]
[h2]	Files:
[=]
	All of these files should be present in your distribution:
[=]
[i4]
[tb]
	| lms             | Lunar Mission Simulator executable           |
	| mapgen          | Program for creating Lunar surface maps      |
	| planner         | Program for creating mission profiles        |
	| gcasm           | Program for creating LM ccomputer cores      |
	| lm.asm          | Assembly source for LM computer core         |
	| core.lm         | Binary file for LM computer core             |
	| ams.pnl         | Generic panel based on AMS                   |
	| readme.doc      | This file                                    |
	| keys.doc        | Documentation for key commands               |
	| panel.doc       | Documentation for instrument panels          |
	| csmcomputer.doc | Documentation for the CSM computer           |
	| lmcomputer.doc  | Documentation for the LM computer            |
	| template.txt    | Template file for helping you create panels  |
	| tutorial_1.doc  | Tutorial for sub-orbital flight              |
	| tutorial_2.doc  | Tutorial for launch to orbit                 |
	| tutorial_7.doc  | Tutorial for getting to the Moon             |
	| tutorial_8.doc  | Tutorial for using the CSM guidance computer |
	| tutorial_9.doc  | Tutorial for Landing on the Moon             |
	| tutorial_10.doc | Tutorial on Lunar Surface Operations         |
	| tutorial_11.doc | Tutorial on Lunar Liftoff and Rendevous      |
[te]
[i-4]
[=]
[h2]	Additional files:
[=]
	These are files that do not come with the distribution. Some of
	these files are created by the various programs.  The .pnl files
	you can create for designing your own instrument panels.
[=]
[i4]
[tb]
	| csm.pnl     | Panel definition for the CSM                   |
	| lm.pnl      | Panel definition for the LM                    |
	| lrv.pnl     | Panel definition for the LRV                   |
	| plss.pnl    | Panel definition for EVA                       |
	| records.dat | This file holds the current mission records    |
	| records.txt | Mission records in a more human friendly form  |
	| lms.sav     | Save file from lms                             |
	| *.msn       | Mission profiles created from planner          |
	| userref.txt | File containing objects left on the moon       |
	| report*.txt | Mission reports                                |
[te]
[i-4]
[=]
[h2]	The documentation currently supplied:
[=]
[i4]
[tb]
	| csmcomputer.doc | Documents how to use the guidance computer
	                    in the CSM.  This document is mostly notes
	                    at this point and far from complete        |
	| lmcomputer.doc  | Documents how to use the guidance computer
	                    in the LM.  This document is mostly notes
	                    at this point and far from complete        |
	| panel.doc       | This describes all the possible guages that
	                    can be found on the various instrument panels.
	                    This document is mostly complete but currently
	                    lacks the information on how to create your
	                    own instrument panels.  This will be added
	                    at some point in the future                |
	| keys.doc        | This documents all the key commands used in
	                    the various vehicles.  This document is mostly
	                    complete                                   |
[te]
[i-4]
[=]
	Documentation will be updated more often at the website than
	in the distribution packages.  So keep an eye on the website for
	updates.
[=]
	www.LunarMissionSimulator.com
[=]
[h2]	Source code
[=]
	Full source code for this project may be found at github:
[=]
	https://github.com/rileym65/lms
[=]

