#!/bin/bash

sections=(start-up os)

rm -rf public

for section in "${sections[@]}"; do
    cd $section ; make
    mkdir -p public/
    mv -f $section/public/ public/$section
done
