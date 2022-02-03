#!/usr/bin/env bash

make re
./ft_containers > ft_containers.txt
./std_containers > std_containers.txt

printf "\n\t\033[95;1mChecking difference between ft & std files \t\033[93;1m--------->>>\033[0m\t";

if diff ft_containers.txt std_containers.txt > /dev/null;then {
    printf "\033[032;4;1m:) No difference!!!\033[0m\n\n";
    diff ft_containers.txt std_containers.txt > diff.txt
}
else {
    printf "\033[031;4;1m:( Check diff.txt !\033[0m\n\n";
    diff ft_containers.txt std_containers.txt > diff.txt
}
fi