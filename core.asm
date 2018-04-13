
; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 01                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^ABS    *****
; *************************************************************************
            prog   P00V00N01
loop000001: calp   P10V00N01
            wait
            jmp    loop000001


; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 02                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^TAR    *****
; *************************************************************************
            prog   P00V00N02
loop000002: calp   P10V00N02
            wait                        ; Wait for next cycle
            jmp    loop000002           ; Loop back to beginning


; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 03                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^REL    *****
; *************************************************************************
            prog   P00V00N03
loop000003: calp   P10V00N03
            wait
            jmp    loop000003


; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 12                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^TAR    *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
            prog   P00V00N12
loop000012: calp   P10V00N12
            wait
            jmp    loop000012


; *************************************************************************
; ***** Prog: 00   Verb: 00   Noun: 13                                *****
; ***** Type: Main program                                            *****
; ***** This program displays the data associated with INS POS^REL    *****
; ***** North and east are represented in meters instead of degrees   *****
; *************************************************************************
            prog   P00V00N13
loop000013: calp   P10V00N13
            wait
            jmp    loop000013



            prog   P01V00N00
            mov    MASS,R10
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
            calp   P11V00N00
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
            calp   P11V00N00
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
            calp   P11V00N01
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
            calp   P11V00N00
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
            calp   P11V00N01
            ret


            prog   P11V00N00
            mov    AVEL,R4
            mov    EVEL,R5
            mov    NVEL,R6
            calp   P11V00N01
            ret

            prog   P11V00N01
            mov    AACC,R7
            mov    EACC,R8
            mov    NACC,R9
            ldi    R20,1000
            mov    PERL,R13
            sub    R13,GRND
            div    R13,R20
            mov    APOL,R14
            sub    R14,GRND
            div    R14,R20
            mov    ANOD,R11
            mov    INCL,R12
            ret
