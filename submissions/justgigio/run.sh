#!/bin/bash


if [ "$1" = "build" ]; then
    mkdir instances
    cp -r ../../resources/instances/* instances
    docker build -t rinha-run . --no-cache
    rm -rf instances
elif [ "$1" = "bash" ]; then
    docker run --rm -it --cpus=2 --memory=2GB -v $(pwd):/app rinha-run bash
else
    docker run --rm -it --cpus=2 --memory=2GB -v $(pwd):/app rinha-run /bin/bash -c "python run.py $1"
fi
