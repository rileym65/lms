[h2]	Available in all modes:
[tb]
	| <shift> Q | - | Quit the simulator                                  |
	| <shift> 1 | - | Run at 1x speed                                     |
	| <shift> 2 | - | Run at 10x speed                                    |
	| <shift> 3 | - | Run at 100x speed                                   |
	| <shift> 4 | - | Run at 1000x speed                                  |
	| <shift> 5 | - | Run at 10000x speed                                 |
[te]
[=]
[h2]	Available in the CSM (full):
[tb]
	|>>>>>>>>>>>| # | ####################################################|
	| <shift> L | - | Launch mission                                      |
	| <shift> M | - | Move to LM                                          |
	| <shift> J | - | Jettison booster, service module, retro module.
	                  ARM must be set.                                    |
	| <shift> S | - | Perform staging during ascent. Engines must be off  |
	| <shift> C | - | Cut off launch vehicle engines                      |
	| <shift> E | - | Extract LM from launch vehicle.  Must be docked
	                  to LM                                               |
	| <shift> P | - | Deplay parachutes.  Must be in atmosphere below
	                  3000 meters                                         |
	| <shift> U | - | Undock from LM.  ARM must be set                    |
	| <shift> I | - | Ignite engine. ARM must be set                      |
	|         i | - | Turn off engine                                     |
	|         f | - | Turn on/off forward translation thruster            |
	|         b | - | Turn on/off backward translation thruster           |
	|         l | - | Turn on/off left translation thruster               |
	|         r | - | Turn on/off right translation thruster              |
	|         u | - | Turn on/off up translation thruster                 |
	|         d | - | Turn on/off down translation thruster               |
	| <space>   | - | Turn off all translation thrusters                  |
	|         = | - | Increase RCS translation throttle 1%->10%->100%     |
	|         - | - | Decrease RCS translation throttle 100%->10%->1%     |
	| <shift> + | - | Increase RCS rotation throttle 10%->50%->100%       |
	| <shift> _ | - | Decrease RCS rotation throttle 100%->50%->10%       |
	|<keypad> 8 | - | Pitch forward                                       |
	|<keypad> 2 | - | Pitch backward                                      |
	|<keypad> 4 | - | Yaw left                                            |
	|<keypad> 6 | - | Yaw right                                           |
	|<keypad> 7 | - | Roll left                                           |
	|<keypad> 9 | - | Roll right                                          |
	| <tab>     | - | Turn on/off ARM state                               |
[te]
[=]
[h2]	Available in LM:
[tb]
	|>>>>>>>>>>>| # | ####################################################|
	| <shift> M | - | Move to CSM if docked.  Start EVA if on Lunar
	                  surface, spacesuit and plss are on and cabin is
	                  depressurized                                       |
	| <shift> E | - | Start EVA if on Lunar surface, spacesuit and plss
	                  are on and cabin is depressurized                   |
	| <shift> U | - | Undock from CSM                                     |
	| <shift> S | - | Put on/Take off space suit                          |
	| <shift> P | - | Put on/Take off PLSS                                |
	| <shift> C | - | Pressurize/depressurize cabin                       |
	| <shift> ? | - | Select DSN for navigation source                    |
	| <shift> > | - | Select docking radar for navigation source          |
	| <shift> < | - | Select landing radar for navigation source          |
	| <shift> * | - | Rest for 2 hours.  Must be on Lunar surface         |
	| <shift> ) | - | Sleep for 8 hours.  Must be on Lunar surface        |
	| <shift> L | - | Liftoff from Lunar surface                          |
	| <shift> I | - | Ignite engine. ARM must be set                      |
	|         i | - | Turn off engine                                     |
	|         f | - | Turn on/off forward translation thruster            |
	|         b | - | Turn on/off backward translation thruster           |
	|         l | - | Turn on/off left translation thruster               |
	|         r | - | Turn on/off right translation thruster              |
	|         u | - | Turn on/off up translation thruster                 |
	|         d | - | Turn on/off down translation thruster               |
	| <space>   | - | Turn off all translation thrusters                  |
	|         = | - | Increase RCS translation throttle 1%->10%->100%     |
	|         - | - | Decrease RCS translation throttle 100%->10%->1%     |
	| <shift> + | - | Increase RCS rotation throttle 10%->50%->100%       |
	| <shift> _ | - | Decrease RCS rotation throttle 100%->50%->10%       |
	|<keypad> 8 | - | Pitch forward                                       |
	|<keypad> 2 | - | Pitch backward                                      |
	|<keypad> 4 | - | Yaw left                                            |
	|<keypad> 6 | - | Yaw right                                           |
	|<keypad> 7 | - | Roll left                                           |
	|<keypad> 9 | - | Roll right                                          |
	|<keypad> 1 | - | Decrease engine throttle 2%. Minimum 10%            |
	|<keypad> 3 | - | Increase engine throttle 2%. Maximum 100%           |
	| <F1>      | - | Set engine throttle to 10%                          |
	| <F2>      | - | Set engine throttle to 20%                          |
	| <F3>      | - | Set engine throttle to 30%                          |
	| <F4>      | - | Set engine throttle to 40%                          |
	| <F5>      | - | Set engine throttle to 50%                          |
	| <F6>      | - | Set engine throttle to 60%                          |
	| <F7>      | - | Set engine throttle to 70%                          |
	| <F8>      | - | Set engine throttle to 80%                          |
	| <F9>      | - | Set engine throttle to 90%                          |
	| <F10>     | - | Set engine throttle to 100%                         |
	| <tab>     | - | Turn on/off ARM state                               |
	| <shift> K | - | Activate sequencer Kill function to stop all
	                  rotation                                            |
	| <shift> Z | - | Damage report                                       |
	| <esc>     | - | Abort landing. ARM must be set                      |
[te]
[=]
[h2]	Available during EVA:
[tb]
	|>>>>>>>>>>>| # | ####################################################|
	| <shift> E | - | End EVA. Must be within 40 meters of LM             |
	| <shift> M | - | Move to LRV. Must be within 100 meters of LRV       |
	|         c | - | Collect sample                                      |
	| <shift> D | - | Drop sample                                         |
	|         s | - | Store sample in sample cart. Maximum of 10 samples  |
	| <shift> S | - | Store sample in LRV. Maximum of 30 samples 
	                  Store sample box in LM                              |
	|         t | - | Transfer cart contents to LRV                       |
	| <shift> T | - | Transfer cart contents to LM                        |
	| <shift> B | - | Get sample box from LRV                             |
	| <shift> V | - | Set up LRV                                          |
	| <shift> F | - | Get flag from LM. Plant flag in Lunar surface       |
	| <shift> F | - | Get flag from LM. Plant flag in Lunar surface       |
	| <shift> L | - | Get LLRE from LM. setup LLRE on Lunar surface       |
	| <shift> A | - | Get ALSEP from LM. setup ALSEP on Lunar surface     |
	|<keypad> 4 | - | Turn left                                           |
	|<keypad> 6 | - | Turn right                                          |
	|<keypad> 1 | - | Decrease throttle 10%. Minimum 0%                   |
	|<keypad> 3 | - | Increase throttle 10%. Maximum 100%                 |
	| <F1>      | - | Set throttle to 10%                                 |
	| <F2>      | - | Set throttle to 20%                                 |
	| <F3>      | - | Set throttle to 30%                                 |
	| <F4>      | - | Set throttle to 40%                                 |
	| <F5>      | - | Set throttle to 50%                                 |
	| <F6>      | - | Set throttle to 60%                                 |
	| <F7>      | - | Set throttle to 70%                                 |
	| <F8>      | - | Set throttle to 80%                                 |
	| <F9>      | - | Set throttle to 90%                                 |
	| <F10>     | - | Set throttle to 100%                                |
	| <shift> Z | - | Damage report                                       |
[te]
[=]
[h2]	Available in LRV:
[tb]
	|>>>>>>>>>>>| # | ####################################################|
	| <shift> M | - | Move from LRV to Lunar surface                      |
	|<keypad> 4 | - | Turn left                                           |
	|<keypad> 6 | - | Turn right                                          |
	|<keypad> 1 | - | Decrease throttle 10%. Minimum 0%                   |
	|<keypad> 3 | - | Increase throttle 10%. Maximum 100%                 |
	| <F1>      | - | Set throttle to 10%                                 |
	| <F2>      | - | Set throttle to 20%                                 |
	| <F3>      | - | Set throttle to 30%                                 |
	| <F4>      | - | Set throttle to 40%                                 |
	| <F5>      | - | Set throttle to 50%                                 |
	| <F6>      | - | Set throttle to 60%                                 |
	| <F7>      | - | Set throttle to 70%                                 |
	| <F8>      | - | Set throttle to 80%                                 |
	| <F9>      | - | Set throttle to 90%                                 |
	| <F10>     | - | Set throttle to 100%                                |
	| <shift> Z | - | Damage report                                       |
[te]
[=]
[h2]	Commands for Ground INS (EVA or LRV):
[tb]
	|>>>>>>>>>>>| # | ####################################################|
	|         1 | - | Set INS mode to absolute position                   |
	|         2 | - | Set INS mode to landing target                      |
	|         3 | - | Set INS mode to LM                                  |
	|         4 | - | Set INS mode to primary sampling site               |
	|         5 | - | Set INS mode to secondary sampling site 1           |
	|         6 | - | Set INS mode to secondary sampling site 2           |
	|         7 | - | Set INS mode to secondary sampling site 3           |
	|         8 | - | Set INS mode to LRV                                 |
[te]
[=]
[h2]	Commands for Multi-Axis display:
[tb]
	|>>>>>>>>>>>| # | ####################################################|
	|         ] | - | Increase mode. down->west->prograde->absolute       |
	|         [ | - | Decrease mode. absolute->prograde->west->down       |
[te]
[=]
[h2]	Commands for Precision-Axis display:
[tb]
	|>>>>>>>>>>>| # | ####################################################|
	|         . | - | Increase mode. down->west->prograde->absolute       |
	|         , | - | Decrease mode. absolute->prograde->west->down       |
[te]
[=]
[h2]	Commands for CSM computer:
[tb]
	|>>>>>>>>>>>| # | ####################################################|
	|         v | - | Activate Verb entry mode                            |
	|         n | - | Activate Noun entry mode                            |
	| <0> - <9> | - | Insert number while in any entry mode               |
	|         + | - | Set number mode to positive while in numeric entry  |
	|         - | - | Set number mode to negative while in numeric entry  |
	|         p | - | Process current Verb/Noun command                   |
[te]
[=]
[h2]	Commands for LM computer:
[tb]
	|>>>>>>>>>>>| # | ####################################################|
	|         p | - | Activate Program entry mode                         |
	|         v | - | Activate Verb entry mode                            |
	|         n | - | Activate Noun entry mode                            |
	| <0> - <9> | - | Insert number while in any entry mode               |
	|         + | - | Set number mode to positive while in numeric entry  |
	|         - | - | Set number mode to negative while in numeric entry  |
	|         g | - | Process current Program/Verb/Noun command
	                  or stop computer if it is running                   |
[te]
[=]
