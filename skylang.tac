.table
.code
main:
mov $0, 2
seq $2, $0, 2
brz saida_if_0, $2
println 1
saida_if_0:
seq $3, $0, 3
brz saida_if_1, $3
println 2
saida_if_1:
add $4, $0, 2
mov $0, $4
println $0
