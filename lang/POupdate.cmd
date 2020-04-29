cd ../src/GeneticLibTest
dir /B *.c* > files.txt
xgettext --from-code=cp1251 -a -k_ --no-location -s -j --no-wrap --escape -ffiles.txt -o"../../lang/Cutting Expert.po" >log.txt

pause