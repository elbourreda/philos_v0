make re
./philo 5 800 200 200 $1 > reslt
x=1
while [ $x -le 5 ]
do
    cat reslt | grep "$x is eating" | wc -l
    x=$(( $x + 1 ))
done