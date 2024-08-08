ARGS="$(./aux/input_maker/target/debug/input_maker $1)"
./push_swap $ARGS | wc -l
./push_swap $ARGS | ./aux/checker_Mac $ARGS
