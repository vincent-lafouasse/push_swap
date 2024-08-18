NUMBERS="$(./input_maker "$1")"

echo "For input:"
echo "$NUMBERS"

echo "Number of operations:"
./push_swap $NUMBERS | wc -l

./push_swap $NUMBERS | ./checker_Mac $NUMBERS
