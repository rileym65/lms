            prog   P00V00N01
loop000001: mov    ALT,R1
            mov    EAST,R2
            mov    NRTH,R3
            calp   P10V00N00
            wait
            jmp    loop000001

            prog   P00V00N02
loop000002: mov    ALT,R1               ; Move altitude to register 1
            mov    TLNG,R2
            mov    TLAT,R3
            calp   P10V00N00
            wait                        ; Wait for next cycle
            jmp    loop000002           ; Loop back to beginning

            prog   P00V00N03
loop000003: mov    RALT,R1
            mov    RLNG,R2
            mov    RLAT,R3
            mov    RAVEL,R4
            mov    REVEL,R5
            mov    RNVEL,R6
            calp   P10V00N01
            jmp    loop000003

            prog   P01V00N00
            mov    MASS,R10
            end

            prog   P10V00N00
            mov    AVEL,R4
            mov    EVEL,R5
            mov    NVEL,R6
            calp   P10V00N01
            ret

            prog   P10V00N01
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
