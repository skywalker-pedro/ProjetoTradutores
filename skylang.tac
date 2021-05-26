.table
.code
main:
mov $0, 0
mov $1, 0
for0:
slt $3, $1, 4
brz fim_for_0, $3
add $4, $1, 1
mov $1, $4
add $5, $0, $1
println $5
jump for0
fim_for_0:
mov $2, 0
for1:
seq $6, $2, 3
brz fim_for_1, $6
add $7, $2, 1
mov $2, $7
mul $8, $2, $2
println $8
jump for1
fim_for_1:
println $2
jump end_program
end_program:
nop
