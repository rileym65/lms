
; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 01                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^ABS    *****
; *****                                                               *****
; ***** This program displays the POS^ABS and ORB^ABS data from the   *****
; ***** INS                                                           *****
; *************************************************************************
            prog   P00V00N01
loop000001: calp   P10V00N01           ; Display POS^ABS data
            calp   P11V00N03           ; display perilune/apolune
            calp   P11V00N02           ; display orbital information
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
            prog   P00V00N02
loop000002: calp   P10V00N02           ; Display POS^TAR data
            calp   P11V00N03           ; display perilune/apolune
            calp   P11V00N04           ; display orbital information
            wait                       ; Wait for next cycle
            jmp    loop000002          ; Loop back to beginning


; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 03                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^REL    *****
; *************************************************************************
            prog   P00V00N03
loop000003: calp   P10V00N03           ; Display POS^REL data
            calp   P11V00N03           ; display perilune/apolune
            calp   P11V00N02           ; display orbital information
            wait
            jmp    loop000003


; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 12                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^TAR    *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
            prog   P00V00N12
loop000012: calp   P10V00N12           ; Display POS^TAR in meters
            wait
            jmp    loop000012


; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 13                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^REL    *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
            prog   P00V00N13
loop000013: calp   P10V00N13           ; Display POS^REL in meters
            wait
            jmp    loop000013


; *************************************************************************
; ***** Prog: 00   Verb: 01   Noun: 01                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^ABS    *****
; ***** Display ascent fuel info in R10,R11,R12                       *****
; *************************************************************************
            prog   P00V01N01
loop000101: calp   P10V00N01           ; Display POS^ABS data
            calp   P11V00N03           ; Display perilune,apolune
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
            prog   P00V01N02
loop000102: calp   P10V00N12           ; Display POS^RAR in meters
            calp   P11V00N03           ; Display perilune,apolune
            mov    dfuel,r12           ; Display remaining descent fuel
            mov    thrtl,R20           ; Get current throttle setting
            div    R20,C100            ; divide by 100
            ldi    R21,15              ; 15kg/s is maximum thrust
            mul    R20,R21             ; Now have fuel burn rate
            mov    R20,R11             ; Show burn rate in register 11
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
; ***** Prog: 10   Verb: 00   Noun: 01                                *****
; ***** Type: Subroutine                                              *****
; ***** This subroutine displays the data associated with INS POS^ABS *****
; *************************************************************************
            prog   P10V00N01
            mov    alt,r1
            mov    east,r2
            mov    nrth,r3
            calp   P11V00N00               ; display absolute velocities
            calp   P11V00N01               ; display absolute accelerations
            ret

; *************************************************************************
; ***** Prog: 10   Verb: 00   Noun: 02                                *****
; ***** Type: Subroutine                                              *****
; ***** This subroutine displays the data associated with INS POS^TAR *****
; *************************************************************************
            prog   P10V00N02
            mov    alt,r1
            mov    tlng,r2
            mov    tlat,r3
            calp   P11V00N00               ; display absolute velocities
            calp   P11V00N01               ; display absolute accelerations
            ret

; *************************************************************************
; ***** Prog: 10   Verb: 00   Noun: 03                                *****
; ***** Type: Subroutine                                              *****
; ***** This subroutine displays the data associated with INS POS^REL *****
; *************************************************************************
            prog   P10V00N03
            mov    ralt,r1
            mov    rlng,r2
            mov    rlat,r3
            mov    ravel,r4
            mov    revel,r5
            mov    rnvel,r6
            calp   P11V00N01               ; display absolute accelerations
            ret

; *************************************************************************
; ***** Prog: 10   Verb: 00   Noun: 12                                *****
; ***** Type: Subroutine                                              *****
; ***** This subroutine displays the data associated with INS POS^TAR *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
            prog   P10V00N12
            mov    alt,r1
            mov    nrth,r20
            cos    r20,r20
            mul    r20,metr
            mov    tlng,r2
            mul    r2,r20
            mov    tlat,r3
            mul    r3,metr
            calp   P11V00N00               ; display absolute velocities
            calp   P11V00N01               ; display absolute accelerations
            ret

; *************************************************************************
; ***** Prog: 10   Verb: 00   Noun: 13                                *****
; ***** Type: Subroutine                                              *****
; ***** This subroutine displays the data associated with INS POS^REL *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
            prog   P10V00N13
            mov    ralt,r1
            mov    rlng,r2
            mul    r2,metr
            mov    rlat,r3
            mul    r3,metr
            mov    ravel,r4
            mov    revel,r5
            mov    rnvel,r6
            calp   P11V00N01               ; display absolute accelerations
            ret


; *************************************************************************
; ***** Prog: 11   Verb: 00   Noun: 00                                *****
; ***** Type: Subroutine                                              *****
; ***** Display abosulute altitude, east, and north velocities        *****
; ***** Into regs 4,5,6                                               *****
; *************************************************************************
            prog   P11V00N00
            mov    AVEL,R4
            mov    EVEL,R5
            mov    NVEL,R6
            ret


; *************************************************************************
; ***** Prog: 11   Verb: 00   Noun: 01                                *****
; ***** Type: Subroutine                                              *****
; ***** Display abosulute altitude, east, and north Accelerations     *****
; ***** Into regs 7,8,9                                               *****
; *************************************************************************
            prog   P11V00N01
            mov    AACC,R7
            mov    EACC,R8
            mov    NACC,R9
            ret


; *************************************************************************
; ***** Prog: 11   Verb: 00   Noun: 02                                *****
; ***** Type: Subroutine                                              *****
; ***** Display orbital inclination and longitude of ascending node   *****
; ***** Into regs 11,12                                               *****
; *************************************************************************
            prog   P11V00N02
            mov    ANOD,R11
            mov    INCL,R12
            ret


; *************************************************************************
; ***** Prog: 11   Verb: 00   Noun: 03                                *****
; ***** Type: Subroutine                                              *****
; ***** Display Perilune in kilometers in register 13                 *****
; ***** Display Apolune in kilometers in register 14                  *****
; *************************************************************************
            prog   P11V00N03
            ldi    R20,1000
            mov    PERL,R13
            sub    R13,GRND
            div    R13,R20
            mov    APOL,R14
            sub    R14,GRND
            div    R14,R20
            ret


; *************************************************************************
; ***** Prog: 11   Verb: 00   Noun: 04                                *****
; ***** Type: Subroutine                                              *****
; ***** Display relative inclination and longitude of ascending node  *****
; ***** to target landing site Into regs 11,12                        *****
; *************************************************************************
            prog   P11V00N04
            mov    TANOD,R11
            mov    TINCL,R12
            ret

