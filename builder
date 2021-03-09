$COMPILER g++
$OPTS -o main -ltins
$FILE main.cpp

if [$1 == build] 
then
    $COMPILER $FILE $OPTS
fi

if [$1 == run]
then
    $COMPILER $FILE $OPTS
    ./main
fi




