.table
.code
main:
mov $0, 3
inttofl $2, 4
mov $1, $2
fltoint $3, 2.5
seq $4, $0, $3
brz saida_if_0, $4
println 1
saida_if_0:
fltoint $5, 3.3
seq $6, $0, $5
brz saida_if_1, $6
println 2
saida_if_1:
add $7, $0, 2
mov $0, $7
add $8, 1, 1
add $9, $0, $8
add $10, $0, $9
div $11, $10, 2
fltoint $12, $1
mul $13, $11, $12
println $13
