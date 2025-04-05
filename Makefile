build:
	g++ caboose.cpp -o caboose -O3

run:
	./caboose 999999999 >> out-"$(date)".txt

display:
	ls -lah; echo; cat out.txt | grep -v 'non-' | grep 'CABOOSE:' | wc -l

