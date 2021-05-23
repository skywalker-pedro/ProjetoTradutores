.table
.code
teste:
main:
seq $4, 1, 1
mov $3, (null)
mul $7, 8, $5
div $8, $7, 2
add $9, 23, $6
mul $10, $9, 9
mul $11, $8, $10
add $12, $5, $11
mov $5, $12
add $15, $5, 2
mul $16, $15, 3
mov $5, $16
mov $3, 0
slt $17, $3, 232
add $18, $3, 1
mov $3, $18
seq $19, $5, 1
brz saida_if_0, $19
seq $20, $5, 2
print $5
print $5
