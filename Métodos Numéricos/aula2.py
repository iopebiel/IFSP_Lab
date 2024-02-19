#-> Verificar tamanho de um dado em bits e conveter um númerico decimal para binário
numero =  input("digite um  número inteiro===>")
#para verificar um  tipo  de varivel  usamos a função type()
numero  = int(numero)
bits  = numero.bit_length() #retorna a o tamanho  do dado em  bits
print("numero de bits:" ,bits)
numero2 = bin (numero) # converte o numero para binario
print("Em binario = ",  numero2)



#-> Conversão de Binário para Decimal
entrada = input('Digite o número binário: ')
print('O valor digitado é (' + entrada + ')_2')
lv = len(entrada)
saida = int(entrada[0])
for i in range(1,lv):
  print(i)
  saida = int(entrada[i]) + 2*saida
print("Valor (" + str(entrada) + ")_2 na base 10: " + str(saida))
x = input("numero")
print (len(x))



#-> Conversão de Decimal para Binário
entrada = input('Digite um número entre 0 e 1:')
# d parte inteira,  no caso estamos trabalhando 0.xyz...
d = [0]
# r é parte decimal a direita do "."
#iniclamente se dev multiplicar por 2 o valor inicial
r = 2*float(entrada)
#variavel iter contador de interações realizadas na conversão
iter = 0
while (r > 0.0)and(iter <= 20):
  if (r >= 1):
    dk = 1
  else:
    dk = 0
  print(dk)
  #atualiza o a variavel dk no final da lista
  d.append(dk)
  #aqui eleminamos o valor pocessado de r
  r = r - dk
  #atualiza o valor de r caso acha mais elmentos a serem processados
  if (r >= 0):
    r = 2*r
  iter = iter + 1
print("("+entrada+")10 = ("+str(d)+")2")



#Binário Fracionário
entrada = input("entre com número binário fracionario:===>")
fd = 0.0
#Dividir a fração binária em partes inteiras e fraccionárias
inteiro, fracionario = entrada.split('.')
# convertendo a parte inteira em decimal
fd += int(inteiro, 2) #aqui se converte direto para base 2
print(fd)
# Converting the fractional part to decimal
for i in range(len(fracionario)):
  #**->potencia base**expoente
    fd += int(fracionario[i]) * 2**-(i + 1)
print("("+entrada+")2 = ("+str(fd)+")10")