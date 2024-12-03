#!/bin/bash

declare -a prime
sum=0
read N

for (( i = 2; i <= ${N}; i++ ));do
    if [[ ${prime[i]} -eq 0 ]];then
        echo ${i}
        prime[0]=$(( ${prime[0]} + 1 ))
        prime[${prime[0]}]=$i
        let sum+=$i
    fi
    for (( j = 1; j <= ${prime[0]}; j++ ));do
        if [[ $(( $i  * ${prime[$j]} )) -gt $N ]];then
            break
        fi
        prime[$(( $i * ${prime[$j]} ))]=1
        if [[ $(( $i % ${prime[$j]} )) -eq 0 ]];then
            break
        fi
    done
done
echo ${sum}

