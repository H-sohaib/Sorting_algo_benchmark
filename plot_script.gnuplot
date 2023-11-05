set terminal windows
set title "Sorting Algorithm Comparison"
set xlabel "Array Size"
set ylabel "Time (Clock Ticks)"
set key left top
plot "sorting_times.txt" using 1:2 with lines title "Bubble Sort", \
     "sorting_times.txt" using 1:3 with lines title "Heap Sort", \
     "sorting_times.txt" using 1:4 with lines title "Insertion Sort" ,\
     "sorting_times.txt" using 1:5 with lines title "Selection Sort" ,\
     "sorting_times.txt" using 1:6 with lines title "Cycle Sort" ,\
     "sorting_times.txt" using 1:7 with lines title "Redix Sort" ,\
     "sorting_times.txt" using 1:8 with lines title "Quick Sort" ,\
     "sorting_times.txt" using 1:9 with lines title "Merge Sort" 

