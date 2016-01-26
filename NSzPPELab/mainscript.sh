#!/bin/bash

extension=".png"
prefix="image"

for fileName in *;
do
    if [[ "$fileName" == "$prefix"*"$extension" ]]
    then

        echo "$fileName" - "ok, starting process.."
        ./NSzPPELab $fileName &
    else
        echo "$fileName" - "nope"

    fi
done    
