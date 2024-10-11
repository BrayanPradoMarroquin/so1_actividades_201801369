# Instalación de un ambiente local de Kubernetes y despliegue de un servidor web

## Paso 1: Instalar un ambiente local de Kubernetes

### Opción 1: Usar Minikube

1. **Instalar Minikube**  
   - En Linux:
     ```bash
     curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
     sudo install minikube-linux-amd64 /usr/local/bin/minikube
     ```
   - En macOS (con Homebrew):
     ```bash
     brew install minikube
     ```
   - En Windows (con Chocolatey):
     ```bash
     choco install minikube
     ```

2. **Iniciar Minikube**
   ```bash
   minikube start

**Verificar la instalacion** 
kubectl get nodes

**Paso 2: Desplegar un servidor web en el clúster local**

**Crear un archivo de Despliegue**
apiVersion: apps/v1
kind: Deployment
metadata:
  name: apache-deployment
spec:
  replicas: 1
  selector:
    matchLabels:
      app: apache
  template:
    metadata:
      labels:
        app: apache
    spec:
      containers:
      - name: apache
        image: httpd:latest
        ports:
        - containerPort: 80


**Paso 3: Respuesta**
¿Existen nodos masters y workers en un ambiente local de Kubernetes y cómo funciona?
En un ambiente local de Kubernetes, como cuando usamos Minikube o Kind, se emula un clúster de Kubernetes completo en una sola máquina. En una configuración de producción, un clúster de Kubernetes está compuesto por un nodo master (o plano de control) que gestiona el estado del clúster, y uno o más nodos workers que ejecutan los contenedores.

En el caso de un ambiente local, como Minikube, se crea un clúster de un solo nodo, donde tanto el plano de control como los nodos workers se ejecutan en la misma máquina. Aunque en realidad hay solo un nodo, este cumple ambos roles (master y worker), lo que permite ejecutar aplicaciones dentro del clúster de manera similar a un entorno distribuido