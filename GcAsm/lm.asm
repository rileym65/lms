            prog   P00V00N00
            run    P00V00N00
idle:       mov    zero,prg
            end
            jmp    idle

; *************************************************************************
; ***** Prog: 00   Verb: 16   Noun: 51                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^ABS    *****
; *****                                                               *****
; ***** This program displays the POS^ABS and ORB^ABS data from the   *****
; ***** INS                                                           *****
; *************************************************************************
            prog   P00V16N51
loop000001: call   posabs              ; Display POS^ABS data
            call   periapo             ; display perilune/apolune
            call   absorbit            ; display orbital information
            wait
            jmp    loop000001


; *************************************************************************
; ***** Prog: 00   Verb: 16   Noun: 52                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^TAR    *****
; *****                                                               *****
; ***** This program displays the POS^TAR and ORB^TAR data from the   *****
; ***** INS                                                           *****
; *************************************************************************
            prog   P00V16N52
loop000002: call   postar              ; Display POS^TAR data
            call   periapo             ; display perilune/apolune
            call   tarorbit            ; display orbital information
            vmov   tpos,r20            ; get target position
            vmov   pos,r23             ; get current position
            vsub   r20,r23             ; subtract
            vlen   r20,r10             ; get length
            div    r10,c1000           ; convert to kilometers
            wait                       ; Wait for next cycle
            jmp    loop000002          ; Loop back to beginning


; *************************************************************************
; ***** Prog: 00   Verb: 16   Noun: 53                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^REL    *****
; *************************************************************************
            prog   P00V16N53
loop000003: call   posrel              ; Display POS^REL data
            call   periapo             ; display perilune/apolune
            call   relorbit            ; display orbital information
            mov    rotime,R15          ; Relative orbit time
            vmov   rpos,r20            ; Get relative postion to csm
            vlen   r20,r10             ; convert to distance
            div    r10,c1000           ; convert to kilometers
            wait
            jmp    loop000003


; *************************************************************************
; ***** Prog: 00   Verb: 16   Noun: 62                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^TAR    *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
            prog   P00V16N62
loop000012: call   postarmet           ; Display POS^TAR in meters
            wait
            jmp    loop000012


; *************************************************************************
; ***** Prog: 00   Verb: 16   Noun: 63                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^REL    *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
            prog   P00V16N63
loop000013: call   posrelmet           ; Display POS^REL in meters
            mov    dockx,R11           ; Show x position of docking port
            mov    docky,R10           ; Show y position of docking port
            mov    dockz,R12           ; show Z position of docking port
            mov    dockvy,R13          ; show y velocity of docking port
            mov    dockvx,R14          ; show x velocity of docking port
            mov    dockvz,R15          ; show z velocity of docking port
            wait
            jmp    loop000013


; *************************************************************************
; ***** Prog: 00   Verb: 16   Noun: 71                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^ABS    *****
; ***** Display ascent fuel info in R10,R11,R12                       *****
; *************************************************************************
            prog   P00V16N71
loop000101: call   posabs              ; Display POS^ABS data
            call   periapo             ; display perilune/apolune
            mov    afuel,R10
            ldi    r11,fflow
            div    r10,r11
            mov    afuel,r12
            wait
            jmp    loop000101


; *************************************************************************
; ***** Prog: 00   Verb: 16   Noun: 72                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^TAR    *****
; ***** Display descent fuel info in R10,R11,R12                      *****
; *****                                                               *****
; ***** This program is useful during powered descent as it shows     *****
; ***** distances to target in meters as well as the descent fuel     *****
; ***** remaining, burn rate and seconds of fuel remaining            *****
; *************************************************************************
            prog   P00V16N72
loop000102: call   postarmet           ; Display POS^TAR in meters
            call   periapo             ; display perilune/apolune
            mov    latvel,r6           ; Display latitude velocity
            mov    latacc,r9           ; Display latitude acceleration
            mov    dfuel,r12           ; Display remaining descent fuel
            mov    fflow,R11           ; show fuel flow in register 11

            vmov   tpos,r20            ; get target position
            vmov   pos,r23             ; get current position
            vsub   r20,r23             ; subtract
            vlen   r20,r13             ; get length
            div    r13,c1000           ; convert to kilometers

            vlen   ovel,r14            ; display orbital velocity in reg 14

            jeq    R11,ZERO,notrun     ; jump if engine not running
            mov    R12,R10             ; get Descent fuel
            div    R10,R11             ; divide by burn rate to get seconds
            wait
            jmp    loop000102
notrun:     mov    R12,R10             ; get current descent fuel
            div    R10,R21             ; Will use maximum thrust
            wait
            jmp    loop000102




            prog   P01V00N00
looptest:   norm   pos,r20
            norm   vel,r23
            crs    r20,r23
            vmov   vres,r13
            wait
            jmp    looptest
            end

; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** This subroutine displays the data associated with INS POS^ABS *****
; *************************************************************************
posabs:     mov    alt,r1
            mov    east,r2
            mov    nrth,r3
            call   absvel                  ; display absolute velocities
            call   absacc                  ; display absolute accelerations
            ret

; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** This subroutine displays the data associated with INS POS^TAR *****
; *************************************************************************
postar:     mov    alt,r1
            mov    tlng,r2
            mov    tlat,r3
            call   absvel                  ; display absolute velocities
            call   absacc                  ; display absolute accelerations
            ret

; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** This subroutine displays the data associated with INS POS^REL *****
; *************************************************************************
posrel:     mov    ralt,r1
            mov    rlng,r2
            mov    rlat,r3
            mov    ravel,r4
            mov    revel,r5
            mov    rnvel,r6
            call   absacc                  ; display absolute accelerations
            ret

; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** This subroutine displays the data associated with INS POS^TAR *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
postarmet:  mov    alt,r1
            mov    nrth,r20
            cos    r20,r20
            mul    r20,metr
            mov    tlng,r2
            mul    r2,r20
            mov    tlat,r3
            mul    r3,metr
            call   absvel                  ; display absolute velocities
            call   absacc                  ; display absolute accelerations
            ret

; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** This subroutine displays the data associated with INS POS^REL *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
posrelmet:  vmov   rpos,r20
            mov    r20,r1
            mov    r21,r2
            mov    r22,r3
            mov    ravel,r4
            mov    revel,r5
            mov    rnvel,r6
            call   absacc                  ; display absolute accelerations
            ret


; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** Display abosulute altitude, east, and north velocities        *****
; ***** Into regs 4,5,6                                               *****
; *************************************************************************
absvel:     mov    AVEL,R4
            mov    EVEL,R5
            mov    NVEL,R6
            ret


; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** Display abosulute altitude, east, and north Accelerations     *****
; ***** Into regs 7,8,9                                               *****
; *************************************************************************
absacc:     mov    AACC,R7
            mov    EACC,R8
            mov    NACC,R9
            ret


; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** Display orbital inclination and longitude of ascending node   *****
; ***** Into regs 11,12                                               *****
; *************************************************************************
absorbit:   mov    ANOD,R11
            mov    INCL,R12
            ret


; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** Display Perilune in kilometers in register 13                 *****
; ***** Display Apolune in kilometers in register 14                  *****
; *************************************************************************
periapo:    ldi    R20,1000
            mov    PERL,R13
            sub    R13,GRND
            div    R13,R20
            mov    APOL,R14
            sub    R14,GRND
            div    R14,R20
            mov    CLKOR,R15
            ret


; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** Display relative inclination and longitude of ascending node  *****
; ***** to target landing site Into regs 11,12                        *****
; *************************************************************************
tarorbit:   mov    TANOD,R11
            mov    TINCL,R12
            ret


; *************************************************************************
; ***** Type: Subroutine                                              *****
; ***** Display relative inclination and longitude of ascending node  *****
; ***** to CSM Into regs 11,12                                        *****
; *************************************************************************
relorbit:   mov    RANOD,R11
            mov    RINCL,R12
            ret




; *******************************************************
; ***** Informational displays that are same as CSM *****
; *******************************************************

; *************************************
; ***** Equivalent to CSM V16 N01 *****
; *************************************
            prog   P00V16N01
v16n01:     mov    apol,r1              ; put apoapsis into register 1
            sub    r1,grnd              ; convert radius to altitude
            mov    perl,r2              ; put periapsis into register 2
            sub    r2,grnd              ; convert radius to altitude
            mov    clkor,r3             ; put orbit time into register 3
            wait                        ; wait until next cycle
            jmp    v16n01               ; and repeat

; *************************************
; ***** Equivalent to CSM V16 N02 *****
; *************************************
            prog   P00V16N02
v16n02:     mov    east,r1              ; put longitude into register 1
            mov    nrth,r2              ; put latitude into register 2
            wait                        ; wait until next cycle
            jmp    v16n02               ; and repeat

; *************************************
; ***** Equivalent to CSM V16 N03 *****
; *************************************
            prog   P00V16N03
v16n03:     mov    mass,r1              ; put vehicle mass into register 1
            mov    fuel,r2              ; Put current stage fuel into register 2
            mov    rfuel,r3             ; Put rcs fuel into register 3
            wait                        ; wait until next cycle
            jmp    v16n03               ; and repeat

; *************************************
; ***** Equivalent to CSM V16 N04 *****
; *************************************
            prog   P00V16N04
v16n04:     mov    roll,r1              ; show roll gimbal in register 1
            mov    pitch,r2             ; show pitch gimbal in reigster 2
            mov    yaw,r3               ; show yaw gimbal in register 3
            wait                        ; wait until next cycle
            jmp    v16n04               ; and repeat

; *************************************
; ***** Equivalent to CSM V16 N05 *****
; *************************************
            prog   P00V16N05
v16n05:     mov    tanom,r1             ; put true anomaly into register 1
            mov    manom,r2             ; put mean anomaly into register 2
            mov    eanom,r3             ; put eccentric anomaly into register 3
            wait                        ; wait until next cycle
            jmp    v16n05               ; and repeat

; *************************************
; ***** Equivalent to CSM V16 N06 *****
; *************************************
            prog   P00V16N06
v16n06:     mov    anod,r1              ; put ascending node into register 1
            mov    argp,r2              ; put argument of periapsis into register 2
            mov    anod,r3              ; Get longitude of ascending node
            add    r3,argp              ; and add argument of periapsis
            wait                        ; wait until next cycle
            jmp    v16n06               ; and repeat

; *************************************
; ***** Equivalent to CSM V16 N07 *****
; *************************************
            prog   P00V16N07
v16n07:     mov    clkge,r20            ; get ground elapsed clock
            call   clkout               ; output clock elements
            wait                        ; wait until next cycle
            jmp    v16n07

; *************************************
; ***** Equivalent to CSM V16 N08 *****
; *************************************
            prog   P00V16N08
v16n08:     mov    clkut,r20            ; get universal clock
            call   clkout               ; output clock elements
            wait                        ; wait until next cycle
            jmp    v16n08

; *************************************
; ***** Equivalent to CSM V16 N09 *****
; *************************************
            prog   P00V16N09
v16n09:     mov    clkap,r20            ; get time til apoapsis
            call   clkout               ; output clock elements
            wait                        ; wait until next cycle
            jmp    v16n09

; *************************************
; ***** Equivalent to CSM V16 N10 *****
; *************************************
            prog   P00V16N10
v16n10:     mov    clkpe,r20            ; get time til apoapsis
            call   clkout               ; output clock elements
            wait                        ; wait until next cycle
            jmp    v16n10

; *************************************
; ***** Equivalent to CSM V16 N12 *****
; *************************************
            prog   P00V16N12
v16n12:     mov    alt,r1               ; get altitude
            mov    tlng,r2              ; get target longitude
            mov    tlat,r3              ; get target latitude
            wait
            jmp    v16n12

; *************************************
; ***** Equivalent to CSM V16 N14 *****
; *************************************
            prog   P00V16N14
v16n14:     mov    mass,r20             ; get mass of vehicle
            sub    r20,fuel             ; subtract fuel
            mov    mass,r1              ; need to divide mass by this
            div    r1,r20
            log    r1,r1                ; then take log of result
            mul    r1,isp               ; multiply by isp
            mul    r1,g                 ; and g
            mov    mass,r20             ; get mass of vehicle
            sub    r20,rfuel            ; subtract rcs fuel
            mov    mass,r2              ; get mass of vehicle
            div    r2,r20               ; divide by mass-fuel
            log    r2,r2                ; then take log of result
            mul    r2,risp              ; multiply by rcs isp
            mul    r2,g                 ; and g
            mov    fflow,r3             ; put fuel flow into register 3
            wait                        ; wait until next cycle
            jmp    v16n14               ; and repeat

; *************************************
; ***** Equivalent to CSM V16 N16 *****
; *************************************
            prog   P00V16N16
v16n16:     mov    clkev,r20            ; get event clock
            call   clkout               ; output clock elements
            wait                        ; wait until next cycle
            jmp    v16n16


; ************************************
; ***** Display orbital velocity *****
; ************************************
            prog   P00V16N17
v16n17:     vlen   ovel,r1
            wait
            jmp    v16n17

; *****************************
; ***** Show ORBvABS data *****
; *****************************
            prog   P00V16N75
v16n75:     call   periapo             ; display perilune/apolune
            call   absorbit            ; display orbital information
            wait
            jmp    v16n75

; **********************************************************************
; ***** Decompose clock in r20 to hh,mm,ss and display in r1,r2,r3 *****
; **********************************************************************
clkout:     ldi    r21,3600             ; seconds in an hour
            mov    r20,r1               ; move time to register 1
            div    r1,r21               ; convert to hours
            int    r1,r1                ; convert to integer
            mod    r20,r21              ; remaining seconds
            ldi    r21,60               ; seconds in a minute
            mov    r20,r2               ; move minutes
            div    r2,r21               ; convert to minutes
            int    r2,r2                ; and convert to integer
            mod    r20,r21              ; get remaining seconds
            int    r20,r3               ; write as integer to register 3
            ret                         ; return to caller


; **********************************
; ***** V21 - Input register 1 *****
; **********************************
            prog   P00V21N00
v21n00:     inp    r1                   ; Input register 1
            end                         ; and end


; **********************************
; ***** V22 - Input register 2 *****
; **********************************
            prog   P00V22N00
v22n00:     inp    r2                   ; Input register 2
            end                         ; and end


; **********************************
; ***** V23 - Input register 3 *****
; **********************************
            prog   P00V23N00
v23n00:     inp    r3                   ; Input register 3
            end                         ; and end

            prog   P00V37N00
            run    P00V00N00
            end

            prog   P00V37N31
            run    P31V00N00
            end

            prog   P00V37N32
            run    P32V00N00
            end

            prog   P00V37n33
            run    P33V00N00
            end

            prog   P00V37n34
            run    P34V00N00
            end

            prog   P00V37n35
            run    P35V00N00
            end

            prog   P00V37n36
            run    P36V00N00
            end


; ***********************************
; ***** V41 - Clear event clock *****
; ***********************************
            prog   P00V41N00
v41n00:     evclr                       ; clear event clock
            end                         ; then end


; **************************************************************
; ***** V42 - Set event clock to Reg1(H), Reg2(M), Reg3(S) *****
; **************************************************************
            prog   P00V42N00
v42n00:     evset                       ; set event clock to reg1,reg2,reg3
            end                         ; then end


; **********************************************
; ***** V43 - Start event clock in up mode *****
; **********************************************
            prog   P00V43N00
v43n00:     evup                        ; Start event clock in up mode
            end                         ; then end


; ************************************************
; ***** V44 - Start event clock in down mode *****
; ************************************************
            prog   P00V44N00
v44n00:     evdn                        ; Start event clock in down mode
            end                         ; then end


; **********************************
; ***** V45 - Stop event clock *****
; **********************************
            prog   P00V45N00
v45n00:     evstp                       ; Stop event clock
            end                         ; then end

; ***************************************************
; ***** P31 - orient and hold prograde attitude *****
; ***************************************************
            prog   P31V00N00
p31:        ornt   OPRO                 ; orient spacecraft prograde
            wait                        ; wait until next cycle
            jmp    p31                  ; keep looping

; *****************************************************
; ***** P32 - orient and hold retrograde attitude *****
; *****************************************************
            prog   P32V00N00
p32:        ornt   ORET
            wait
            jmp    p32

; *******************************************************
; ***** P33 - orient and hold orbit normal attitude *****
; *******************************************************
            prog   P33V00N00
p33:        ornt   ONORM
            wait
            jmp    p33

; ************************************************************
; ***** P34 - orient and hold orbit anti-normal attitude *****
; ************************************************************
            prog   P34V00N00
p34:        ornt   OANORM
            wait
            jmp    p34

; *******************************************************
; ***** P35 - orient and hold orbit inside attitude *****
; *******************************************************
            prog   P35V00N00
p35:        ornt   OIN
            wait
            jmp    p35

; ********************************************************
; ***** P36 - orient and hold orbit outside attitude *****
; ********************************************************
            prog   P36V00N00
p36:        ornt   OOUT
            wait
            jmp    p36

            prog   P60V00N00
p60lp1:     call   posrelmet            ; Display POS^REL in meters
            vlen   rpos,r20             ; get distance from CSM
            ldi    r21,50               ; need to compare to 50 meters
            jge    r20,r21,p60l1        ; jump if so
            wait                        ; wait for next cycle
            jmp    p60lp1               ; loop back
p60l1:      mov    c1,rcsth             ; set rcs translation throttle to low
            mov    c1,rcsd              ; activate down rcs thruster
p60lp2:     call   posrelmet           ; Display POS^REL in meters
            vlen   rvel,r20             ; get length of velocity vector
            ldi    r21,3                ; need 0.3
            div    r21,c10              ; r21 now has 0.3
            jge    r20,r21,p60l2        ; jump if velocity greater than 0.3
            wait                        ; wait for next cycle
            jmp    p60lp2               ; and loop back
p60l2:      mov    zero,rcsd            ; turn off rcs down thruster
            end                         ; end of program

