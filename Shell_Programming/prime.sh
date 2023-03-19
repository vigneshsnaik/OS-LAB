isprime() {
    for ((i=2; i<($1)/2; i++))
    do
        if [ $(($1 % $i)) -eq 0 ]
        then
            return 1
        fi
    done
    return 0
}

echo "Enter a number: "
read num
if isprime $num; then
    echo "$num is prime"
else
    echo "$num is not prime"
fi
