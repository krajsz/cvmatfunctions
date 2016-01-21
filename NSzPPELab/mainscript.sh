#!/bin/bash

extension="png"
prefix="image"

for fileName in *;
do
    if [[ "$fileName" == "$prefix"*"$extension" ]]
    then

        echo "$fileName" - "ok"
    else
        echo "$fileName" - "nope"

    fi
done    
