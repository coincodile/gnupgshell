cd ../src
dir /B *.c* > files.txt
xgettext --from-code=cp1251 -k_ --no-location -s --no-wrap --escape -ffiles.txt -o../lang/wxGnuPGShell.po

pause