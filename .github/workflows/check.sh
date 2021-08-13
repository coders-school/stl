#!/bin/bash

#RED="\e[41m"
#GREEN="\e[42m"
#BOLD="\e[1m"
#DEFAULT="\e[0m"

FILE=$1
failed=0

if [ ! -e "$FILE" ]; then
    echo -e "Given file does not exist - $FILE"
    exit 1
fi

function check()
{
    if [ "$1" != 0 ]; then
        echo -e ❌ $RED "FAILED ON" "$@" $DEFAULT
        ((failed+=1))
    else
        echo -e ✅ $GREEN "FOUND" $DEFAULT
    fi
}

function negative_check()
{
    if [ "$1" == 0 ]; then
        echo -e ❌ $RED "FAILED ON" "$@" $DEFAULT
        ((failed+=1))
    else
        echo -e ✅ $GREEN "NOT FOUND" $DEFAULT
    fi
}

function max_2_allowed_check()
{
    if [ "$1" -gt 2 ]; then
        echo -e ❌ $RED "FAILED ON" "$@" $DEFAULT
        ((failed+=1))
    else
        echo -e ✅ $GREEN "OK" $DEFAULT
    fi
}

function positive_lookup()
{
    echo -e "---"
    echo -e 🔍 $BOLD "CHECKING: $1" $DEFAULT
    egrep "$2" "$FILE"
    check $? $1
}

function negative_lookup()
{
    echo -e "---"
    echo -e 🔍 $BOLD "CHECKING: $1" $DEFAULT
    egrep "$2" "$FILE"
    negative_check $? $1
}

function max_2_allowed_lookup()
{
    echo -e "---"
    echo -e 🔍 $BOLD "CHECKING: $1" $DEFAULT
    max_2_allowed_check `egrep "$2" "$FILE" -c` $1
}

function does_file_exist()
{
    echo -e "---"
    echo -e 🔍 $BOLD "CHECKING: $1" $DEFAULT
    if [[ -f "$1" ]]; then
        echo -e ✅ $GREEN "FILE EXISTS" $DEFAULT
    else
        echo -e ❌ $RED "FILE DOES NOT EXIST" $DEFAULT
        ((failed+=1))
    fi
}

echo -e $BOLD "Performing checks on $FILE" $DEFAULT

does_file_exist $FILE
positive_lookup "should have #include <algorithm>" "\<algorithm\>"
max_2_allowed_lookup "should not have more than 2 for loops" "^\s*for\s*\("
negative_lookup "should not have while loop" "^\}?\s*while\s*\("

echo -e "==="

if [ $failed == 0 ]; then
    echo -e 💚💚💚 $GREEN "ALL CHECKS PASSED" 💚💚💚 $DEFAULT
else
    echo -e ❗️❗️❗️ $RED $failed "CHECKS FAILED" ❗️❗️❗️ $DEFAULT
fi

exit $failed
