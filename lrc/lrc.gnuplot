set term x11
set title "Differential Equation: Aa + Bv + Cx = 0"
set xlabel "Time"
set ylabel "position/current"

plot "lrc.dat" u 1:2 w l lw 2 t "X" # "lrc.dat" u 1:3 w l lw 2 t "v", "lrc.dat" u 1:4 w l lw 2 t "a" 
