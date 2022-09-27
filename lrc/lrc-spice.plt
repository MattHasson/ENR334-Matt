set terminal X11 noenhanced
set title "* lrc circuit simulation"
set xlabel "s"
set ylabel "A"
set grid
unset logscale x 
set xrange [0.000000e+00:5.000000e-03]
unset logscale y 
set yrange [-3.681232e-02:7.628809e-02]
#set xtics 1
#set x2tics 1
#set ytics 1
#set y2tics 1
set format y "%g"
set format x "%g"
plot 'lrc-spice.data' using 1:2 with lines lw 1 title "i(v0)"
