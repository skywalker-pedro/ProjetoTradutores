.table
.code
main:
mov $0, 2
seq $1, $0, 2
brz saida_if_0, $1
println 1
saida_if_0:
seq $2, $0, 3
brz saida_if_1, $2
println 2
saida_if_1:
add $3, $0, 2
mov $0, $3
println $0
