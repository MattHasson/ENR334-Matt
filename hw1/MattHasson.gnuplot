set term x11
set title "Object falling with and without air resistance"

plot "airres.dat" using 1:2 with lines title "With Air Resistance", "falling.dat" u 1:2 w l t "Without Air Resistance"
