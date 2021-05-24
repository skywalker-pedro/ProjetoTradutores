.table
.code
main:
mov $0, 2
mov $1, 4
seq $3, $0, 2
brz saida_if_0, $3
println 1
saida_if_0:
seq $4, $0, 3
brz saida_if_1, $4
println 2
saida_if_1:
add $5, $0, 2
mov $0, $5
add $6, 1, 1
add $7, $0, $6
add $8, $0, $7
div $9, $8, 2
mul $10, $9, $1
println $10
