set terminal windows
set title "Sorting Algorithm Comparison"
set xlabel "Array Size"
set ylabel "Time (Clock Ticks)"
set key left top
plot "sorting_times.txt" using 1:2 with lines title "Bubble Sort", \
     "sorting_times.txt" using 1:3 with lines title "Insertion Sort", \
     "sorting_times.txt" using 1:4 with lines title "Selection Sort"