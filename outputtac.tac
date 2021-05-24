.table
.code
main:
mov $0, 0
mov $1, 0
mov $1, 100
mov $0, $1
sub $2, 2, 1
seq $2, 1, $2
not $2, $2
brz if_exit_1, $2
add $2, $0, 20
mov $0, $2
println $0
jump if_jump_1
if_exit_1:
seq $2, 10, 10
brz if_exit_2, $2
mov $3, 0
mov $3, 10
add $4, $3, $0
println $4
if_exit_2:
if_jump_1:
add $4, $0, $1
println $4
scani $0
add $4, $0, $1
println $4
