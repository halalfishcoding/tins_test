$COMPILER g++
$OPTS -o main -ltins
$FILE main.cpp

if [$1 == build] 
then
    g++ main.cpp -o main -ltins
fi

if [$1 == run]
then
    g++ main.cpp -o main -ltins
    ./main
fi




