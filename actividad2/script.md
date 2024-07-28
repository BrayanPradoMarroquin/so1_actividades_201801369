# ACTIVIDAD 2

!/bin/bash

----

## Leer la variable GITHUB_USER

`read -p "Ingrese el nombre de usuario de GitHub: " BrayanPradoMarroquin`

## Consultar la URL GitHub

```
Url="https://api.github.com/users/$BrayanPradoMarroquin"

Respuesta=$(curl -s $Url)
```
## Obtener los valores del JSON
```
github_user=$(echo $Respuesta | jq -r '.login')

id=$(echo $Respuesta | jq -r '.id')

created_at=$(echo $Respuesta | jq -r '.created_at')
```

## Imprimir la Respuesta
```
echo "Hola $github_user. User ID: $id. Cuenta fue creada el: $created_at."
```

## Crear el directorio /tmp/fecha si no existe
```
date=$(date +"%Y%m%d")

directorio="/tmp/$date"

mkdir -p $directorio
```

## Crear el archivo de log
```
archivo="$directorio/saludos.log"

echo "Hola $github_user. User ID: $id. Cuenta fue creada el: $created_at." > $archivo

echo "Mensaje guardado en: $archivo"
```