ARGS="$(./aux/input_maker/target/debug/input_maker $1)"
echo "For $1 numbers"
echo "Number of operations:"
./push_swap $ARGS | wc -l
./push_swap $ARGS | ./aux/checker_Mac $ARGS
