set term x11
set title "dude set a title for this"

v0=0
y0=100000
y(x)=-0.5*9.81*x*x+v0*x+y0

plot "falling.dat" using 1:2 with lines title "engineering guy", y(x) with lines title "math guy"
