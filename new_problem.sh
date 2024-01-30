#!/usr/bin/bash
read PName
FName="$(echo $PName | sed -r 's/[ .()?''""&/\-]+/_/g')"
dt=$(date '+%d/%m/%Y %H:%M:%S');
touch "$FName.cpp"
printf "/*\nProblem Name : $PName \nAuthor: Abdalrahman Shaban\nDate: $dt\n*/\n\n" > "$FName.cpp"
cat ~/Documents/Problem-Solving/temp.cpp >> "$FName.cpp"
vim "$FName.cpp"
