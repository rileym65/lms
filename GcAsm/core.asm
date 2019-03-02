
; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 01                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^ABS    *****
; *****                                                               *****
; ***** This program displays the POS^ABS and ORB^ABS data from the   *****
; ***** INS                                                           *****
; *************************************************************************
            prog   P00V16N01
loop000001: call   posabs              ; Display POS^ABS data
            call   periapo             ; display perilune/apolune
            call   absorbit            ; display orbital information
            wait
            jmp    loop000001


; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 02                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^TAR    *****
; *****                                                               *****
; ***** This program displays the POS^TAR and ORB^TAR data from the   *****
; ***** INS                                                           *****
; *************************************************************************
            prog   P00V16N02
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
; ***** Prog: 00   Verb: 00   Noun: 03                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^REL    *****
; *************************************************************************
            prog   P00V16N03
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
; ***** Prog: 00   Verb: 00   Noun: 12                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^TAR    *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
            prog   P00V16N12
loop000012: call   postarmet           ; Display POS^TAR in meters
            wait
            jmp    loop000012


; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 13                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^REL    *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
            prog   P00V16N13
loop000013: call   posrelmet           ; Display POS^REL in meters
            wait
            jmp    loop000013


; *************************************************************************
; ***** Prog: 00   Verb: 01   Noun: 01                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^ABS    *****
; ***** Display ascent fuel info in R10,R11,R12                       *****
; *************************************************************************
            prog   P00V16N21
loop000101: call   posabs              ; Display POS^ABS data
            call   periapo             ; display perilune/apolune
            mov    afuel,R10
            ldi    r11,5
            div    r10,r11
            mov    afuel,r12
            wait
            jmp    loop000101


; *************************************************************************
; ***** Prog: 00   Verb: 01   Noun: 02                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^TAR    *****
; ***** Display descent fuel info in R10,R11,R12                      *****
; *****                                                               *****
; ***** This program is useful during powered descent as it shows     *****
; ***** distances to target in meters as well as the descent fuel     *****
; ***** remaining, burn rate and seconds of fuel remaining            *****
; *************************************************************************
            prog   P00V16N22
loop000102: call   postarmet           ; Display POS^TAR in meters
            call   periapo             ; display perilune/apolune
            mov    latvel,r6           ; Display latitude velocity
            mov    latacc,r9           ; Display latitude acceleration
            mov    dfuel,r12           ; Display remaining descent fuel
            mov    thrtl,R20           ; Get current throttle setting
            div    R20,C100            ; divide by 100
            ldi    R21,15              ; 15kg/s is maximum thrust
            mul    R20,R21             ; Now have fuel burn rate
            mov    R20,R11             ; Show burn rate in register 11

            vmov   tpos,r20            ; get target position
            vmov   pos,r23             ; get current position
            vsub   r20,r23             ; subtract
            vlen   r20,r13             ; get length
            div    r13,c1000           ; convert to kilometers

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

