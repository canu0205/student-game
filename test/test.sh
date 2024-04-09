#!/bin/bash

# Check if two arguments are passed
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 file1.txt file2.txt"
    exit 1
fi

# Assign arguments to variables
FILE1="$1"
FILE2="$2"

# Check if FILE1 exists
if [ ! -f "$FILE1" ]; then
    echo "Error: $FILE1 does not exist."
    exit 1
fi

# Check if FILE2 exists
if [ ! -f "$FILE2" ]; then
    echo "Error: $FILE2 does not exist."
    exit 1
fi

# Use the diff command to compare the two files
diff "$FILE1" "$FILE2" || exit 0

# If diff finds no differences, it will not output anything.
# You can uncomment the following line if you want confirmation in such cases.
echo "The files are identical."
