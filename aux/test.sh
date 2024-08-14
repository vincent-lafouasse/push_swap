N_NUMBERS=$1

INPUT_MAKER="aux/input_maker/target/debug/input_maker"
NUMBERS="$(./${INPUT_MAKER} "${N_NUMBERS}")"

echo "For ${N_NUMBERS} numbers"

echo "Number of operations:"
./push_swap $NUMBERS | wc -l

./push_swap $NUMBERS | ./aux/checker_Mac $NUMBERS
