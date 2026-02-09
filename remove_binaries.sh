#!/bin/sh

find . -type f -exec file {} \; |
  grep ELF |
  tr -d ':' |
  awk '{print $1}' |
  while read -r f; do
    rm -v "$f"
  done

find . -type f \( -name "*.in" -o -name "*.out" \) -exec rm -v {} \;
