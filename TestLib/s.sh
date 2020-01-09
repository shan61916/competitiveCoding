for((i = 1; ; ++i)); do
    echo $i
    ./gen3 $i > int
    # ./a < int > out1
    # ./brute a< int > out2
    # diff -w out1 out2 || break
    diff -w <(./aa < int) <(./brute2 < int) || break
done