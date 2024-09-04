#!/usr/bin/bash
read PName
FName="$(echo $PName | sed -r 's/[ .()?''""&/\-]+/_/g')"
dt=$(date '+%d/%m/%Y %H:%M:%S');
touch "$FName.cpp"
printf "/*\nProblem Name : $PName \nAuthor: Abdalrahman Shaban\nDate: $dt\n*/\n\n" > "$FName.cpp"

#for linux 
cat ~/git/Problem-Solving/temp.cpp >> "$FName.cpp"

#for wsl
#cat ~/git/Problem-Solving/temp.cpp >> "$FName.cpp"
#dos2unix "$FName.cpp"

#if you're using neovim (remove the n if not)
nvim "$FName.cpp"
