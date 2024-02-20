#!/usr/bin/bash
read PName
FName="$(echo $PName | sed -r 's/[ .()?''""&/\-]+/_/g')"
dt=$(date '+%d/%m/%Y %H:%M:%S');
touch "$FName.cpp"
printf "/*\nProblem Name : $PName \nAuthor: Abdalrahman Shaban\nDate: $dt\n*/\n\n" > "$FName.cpp"

#for linux 
#cat ~/Documents/Problem-Solving/temp.cpp >> "$FName.cpp"

#for wsl
cat /mnt/c/Users/Abdalrahman/Documents/GitHub/Problem-Solving/temp.cpp >> "$FName.cpp"
dos2unix "$FName.cpp"

vim "$FName.cpp"
