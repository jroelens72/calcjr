# calcjr

```
Reverse Polish notation calculator

Compile with gcc or VS (some environments don't need the M_PI definition)

Commands:
 q     quits
 c     removes last stack location
 C     clears whole stack
 s     swaps the last 2 stack locations
 sto   stores the last stack location
 rcl   recalls it
 sto[a-z]  and rcl[a-z] store/recall to/from location a (up to z)
 chs   changes sign
 0x    prefix for entering hex numbers

 operators are +,-,*,/,%% (+ and - also unary; %% is modulo)
 sqrt
 exp
 log
 ln
 pow    10 2pow gives 100
 pi     3.14
 d      considers current number as degrees and converts to radials
 sin,cos,tan  arguments in radials 
 asin,acos,atan  results in radials 
 rsp R2,R1,P1,Pivot,P2,S1,S2 given H,L,C 

examples:
 2 3+ <enter> gives 5
 2<enter>3+<enter> gives 5
 2<enter>3<enter>+<enter> gives 5
 3<enter><enter>*<enter> gives 9
 6.626e-34 gives Planck's constant
 1s/<enter> gives the reciproke of the last number
 2 sqrt<enter> gives 1.4
 1exp gives e ;  2exp gives the square of e

calc file   allows commands to be put in file
 extra commands: terse,verbose turns off/on full display
                 display       displays last stack location
                 input         prints until end of line and waits for
                 decimal number from standard input
                 print         prints untill end of line
                 #             ignored until end of line (comment)
                 repeat        reexecutes file
```