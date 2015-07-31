suffix=.cpp
for f in *$suffix
do
	echo "Now compiling: $f"
	g++ --std=c++11 -Ofast -p -g -pg $f -o ${f%$suffix}
done

