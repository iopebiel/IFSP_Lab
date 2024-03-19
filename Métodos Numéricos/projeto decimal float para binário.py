entrada = input('Digite o número da sua matrícula: ')
entradaint = entrada[:5] 
entradafloat = entrada[5:7] 
entrada = entradaint +"."+ entradafloat 
entrada = float(entrada) 
print('O valor digitado é ('+str(entrada)+')_10')

#CONVERSÃO DOS NÚMEROS INTEIROS.
nint = int(entradaint) 
saidaint = [] 
saidaint.append(nint % 2) 
nint = int(nint/2) 
while (nint >= 1):
  saidaint.append(nint % 2)
  nint = int(nint/2)

saidaint.reverse() 



#CONVERSÃO DOS NÚMEROS FRACIONÁRIOS.

saidafloat = []
entradafloat = "0." + entradafloat 
entradafloat = float(entradafloat) 
nfloat = 2*float(entradafloat)
iter = 0 
while (nfloat > 0.0)and(iter <= 20): 
  if (nfloat >= 1): #se o número for maior ou igual que 1, número que aparecerá na saída é 1.
    dk = 1
  else: #senão será 0.
    dk = 0
  saidafloat.append(dk)  
  nfloat = nfloat - dk 

  if (nfloat >= 0): 
    nfloat = 2*nfloat
  iter = iter + 1 

print("Num = ("+str(saidaint)+"."+str(saidafloat)+")_2") 