#!/bin/bash

# Print environment variables
echo "**Environment Variables:**"
printenv

# Print positional parameters
echo "\\n**Positional Parameters:**"
for arg in "$@" 
do
    echo "$arg"
done

# Print special parameters
echo "\\n**Special Parameters:**"
echo "Script name: $0"
echo "Number of arguments: $#"
echo "All arguments (as string): $*"
echo "All arguments (as array): $@"
echo "Process ID of the script: $$"
echo "Exit status of last command: $?"
