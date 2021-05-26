.table
.code
main:
mov $0, 0
mov $1, 0
for0:
slt $2, $1, 3
brz fim_for_0, $2
add $3, $1, 1
mov $1, $3
add $4, $0, $1
println $4
jump for0
fim_for_0:
mov $1, 0
for1:
slt $5, $1, 3
brz fim_for_1, $5
add $6, $1, 1
mov $1, $6
mul $7, 1, 100
add $8, $0, $7
println $8
jump for1
fim_for_1:
slt $9, $0, 0
brz else_if_0, $9
print 1
jump saida_if_0
else_if_0:
print 1
saida_if_0:
jump end_program
end_program:
nop
