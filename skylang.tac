.table
.code
teste:
add $0, $-999, 1
mov $-999, $0
jump end_program
end_program:
nop
main:
mov $1, 1
mov $2, $1
mul $4, $1, $-999
mov $3, $4
mov $1, 2
mov $2, 4
seq $6, $1, 2
brz saida_if_0, $6
println 1
saida_if_0:
seq $7, $1, 3
brz saida_if_1, $7
println 2
saida_if_1:
add $8, $1, 2
mov $1, $8
add $9, 1, 1
add $10, $1, $9
add $11, $1, $10
div $12, $11, 2
mul $13, $12, $2
println $13
jump end_program
end_program:
nop
