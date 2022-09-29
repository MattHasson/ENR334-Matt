set term x11
set title "Fertilizer in tanks 1 & 2 over time (lbs)"
set xlabel "Time (minutes)"
set ylabel "Fertilizer (lbs)"
set ytics 10
set xrange [0:120]

T1(x) = 75 - 75*exp(-x/25)
T2(x) = 75 + 75*exp(-x/25)

plot 75 w l t "75 lbs",  T1(x) w l t "Tank 1", T2(x) w l t "Tank 2"\
, "tanks.dat" u 1:2 w l t "Tank 1 sim", "tanks.dat" u 1:3 w l t "Tank 2 sim"

