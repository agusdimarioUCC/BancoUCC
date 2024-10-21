# BancoUCC
Tema 2: Sistema de Gestión Bancaria
Banco UCC, necesita desarrollar un sistema de gestión que permita realizar el registro y
control de actividades que se llevan a cabo en la institución.
El sistema debe contemplar las siguientes consideraciones:
- Mantener la lista de Clientes. Altas y Bajas (En este caso considerar cambiar el estado
de ACTIVO a BAJA)
- Se deben registrar los siguientes datos correspondientes a los clientes y personal del
banco con sus correspondientes datos:
Clientes (DNI, Nombre, Tipo de Cliente, Año Ingreso, Estado)
- Los datos de Clientes se guardan en archivos de texto.
- Los clientes pueden realizar transacciones en sus cuentas de Caja de Ahorro en Pesos
o en Dólares.
- Las transacciones realizadas por los clientes deben ser registradas en un archivo de
texto.
- Los tipos de transacciones que se pueden realizar en ambas cajas de ahorro pueden
ser:
	- Depósitos
	- Extracciones
- Los clientes pueden acceder a tarjetas de crédito en función de las características del
mismo.
	- Clientes Plata, No tienen acceso a tarjeta de crédito.
	- Clientes Oro, acceden a la tarjeta de crédito Credix con límite de crédito
250000
	- Clientes Platino, acceden a la tarjeta de crédito Premium con límite de crédito
500000
Consideraciones:
El programa debe permitir realizar las siguientes operaciones:
- Registrar las transacciones generadas por Clientes (Extracciones y/o Depósitos).
- Realizar las siguiente consultas:
	- Detalle de Cliente por número de Cliente
	- Listado de todos los clientes del banco
	- Listado de transacciones por clientes
	- Informes de extracciones y depósitos según los siguiente criterios:
		- En un mes determinado
		- En un año determinado
		- Todas las operaciones
