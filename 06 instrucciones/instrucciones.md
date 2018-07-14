

# Uso de la red neuronal entrenada con un MLP y backPropagation****

Aqui aplicamos el mejor modelo obtenido durante los distintos entrenamientos de la red neuronal multicapa con los datos de **sexo, edad, estudios, clase social, situación laboral**, y **tamaño del municipio de residencia** **y sexo**. 

Para conocer la probabilidad de que usted tenga hipertensión arterial siga las siguientes instrucciones. 

- Abra el archivo [solicitudDatos.exe](https://github.com/monteroy/TFG/blob/master/05%20weka%20exe/solicitudDatos.exe) y rellene los datos que se piden.


- Abra el archivo [weka.exe](https://github.com/monteroy/TFG/blob/master/05%20weka%20exe/solicitudDatos.exe) o [weka. jar](https://github.com/monteroy/TFG/blob/master/05%20weka%20exe/weka.jar) ambos son ejecutables que realizan las mismas acciones, una vez abierto seleccione de la pestaña aplicaciones la opción de explorer.


![](C:\Users\yolanda\AppData\Local\Temp\1531493375687.png)



- En la pestraña preprocess haga click en open file y seleccione el archivo [cargarDatos.arff](https://github.com/monteroy/TFG/blob/master/05%20weka%20exe/cargarDatos.arff), este programa no funciona sin este paso.

![1531494119281](C:\Users\yolanda\AppData\Local\Temp\1531494119281.png)



- En la pestaña Classify pinche sobre choose y busque el clasificador MultilayerPerceptron

![1531494220680](C:\Users\yolanda\AppData\Local\Temp\1531494220680.png)



- Para el modelo entrenado sabemos que la mejor configuracion es dos capas ocultas de cuatro nodos cada una, una tasa de aprendizaje de 0.2 y 100 épocas. Pinche sobre el MultilayerPerceptron para cambiar estos parámetros


![1531494573819](C:\Users\yolanda\AppData\Local\Temp\1531494573819.png)

![1531494595415](C:\Users\yolanda\AppData\Local\Temp\1531494595415.png)

- Carge el modelo generado tras el entrenamiento [MODELO.model](https://github.com/monteroy/TFG/blob/master/05%20weka%20exe/MODELO.model) haciendo click en el botón derecho del ratón 


![1531494697354](C:\Users\yolanda\AppData\Local\Temp\1531494697354.png)



- Seleccione la opción de supplied test set, set open file, class no class y seleccione el archivo [persona.arrf](https://github.com/monteroy/TFG/blob/master/05%20weka%20exe/persona.arff), es el archivo que se ha generado automaticamente al contestar las preguntas del primer ejecutable.

![1531495617772](C:\Users\yolanda\AppData\Local\Temp\1531495617772.png)



- Click sobre more options y seleccione la salida de la predicción, en este caso hemos seleccionado texto plano.


![1531495916377](C:\Users\yolanda\AppData\Local\Temp\1531495916377.png)



- Pinche con el boton derecho sobre el modelo cargado y seleccione la opción re-evaluate model on current test set (reevaluar el modelo en el conjunto de prueba actual)


![1531495781274](C:\Users\yolanda\AppData\Local\Temp\1531495781274.png)



- Cuando aparezca el siguiente mensaje marque si (Weka detecta que la clase es un valor ausente)


![1531495987891](C:\Users\yolanda\AppData\Local\Temp\1531495987891.png)

- Al terminar se encuentra con la siguiente información


![1531496209664](C:\Users\yolanda\AppData\Local\Temp\1531496209664.png)

- Las clases predichas pueden ser 1 (personas que tienen posibilidad de padecer hipertensión) y 2 (personas que tienen posibilidad de estar sanas)
- El resultado muestra; el número de intancia, la clase que tiene antes de hacer la predicción (?, desconocida), la clase predicha, si se ha dado algun error y el porcentaje en tanto por uno de la precisión de la predicción (en este caso 99.8 %)


