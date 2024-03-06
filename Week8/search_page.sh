#!/bin/bash

# Check for correct usage
if [[ $# -ne 1 ]]; then
    echo "usage: search_page command"
    exit 1
fi

# Get the command to search for
command_to_find="$1"

# Find all man page directories under /usr/share/man
man_dirs=$(find /usr/share/man -type d)

# Search for matching manual pages in each directory
for dir in $man_dirs; do
    match=$(find "$dir" -name "*$command_to_find*" -type f)
    if [[ -n "$match" ]]; then
        echo "$match"  # Print any matches found
    fi
done
