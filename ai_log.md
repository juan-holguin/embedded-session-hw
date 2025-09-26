# AI Interaction Log – Embedded Systems Programming Homework

Este archivo documenta cómo se usó ChatGPT (IA) para desarrollar el proyecto.  
Cada interacción incluye el **prompt**, la **respuesta resumida** y un **comentario reflexivo**.

---

## 📌 Interacción 1 – Guía inicial del proyecto
**Prompt:**  
“quiero que me guíes paso a paso a desarrollar esta tarea, teniendo en cuenta que tengo VS Code y GitHub Desktop”  

**Respuesta resumida:**  
La IA explicó cómo crear el repositorio, inicializar carpetas y archivos (`sensor/`, `actuators/`, `controller/`), y cómo integrar GitHub Desktop con VS Code.  

**Comentario:**  
Pregunté esto porque necesitaba una ruta clara para empezar el proyecto. La respuesta me dio un plan de trabajo organizado en pasos concretos.

---

## 📌 Interacción 2 – Uso de WSL y Ubuntu
**Prompt:**  
“también tengo Ubuntu y WSL por si se necesitan”  

**Respuesta resumida:**  
La IA sugirió usar WSL para la compilación en 32 y 64 bits, porque en Windows puro es más difícil configurar `gcc-multilib`.  

**Comentario:**  
Hice esta aclaración porque sé que WSL facilita la compilación cruzada. Ahora sé que la compilación funciona mejor en Linux.

---

## 📌 Interacción 3 – Compilación y Makefile
**Prompt:**  
“el paso 5 como lo hago” (sobre el Makefile)  

**Respuesta resumida:**  
La IA me dio un ejemplo de `Makefile` con las reglas `ctl64`, `ctl32` y `clean`, usando `gcc -Wall -Wextra -std=c11`.  

**Comentario:**  
Esto resolvió mi duda sobre cómo automatizar la compilación. Antes solo compilaba con `gcc` a mano.

---

## 📌 Interacción 4 – Confirmación del avance
**Prompt:**  
“ya tengo todo bien”  

**Respuesta resumida:**  
La IA me felicitó y sugirió enfocarme en la documentación final (`README.md`, `ai_log.md`, ejemplos de ejecución).  

**Comentario:**  
Aquí confirmé que ya tenía el código funcionando. El siguiente paso era preparar la entrega formal.

---

## 📌 Interacción 5 – Documentación del README
**Prompt:**  
“quiero que me armes un ejemplo completo de README ya escrito con logs y reflexiones”  

**Respuesta resumida:**  
La IA generó un README estructurado con:  
- Instrucciones de compilación y ejecución  
- Ejemplo de salida  
- Resultados de `file` y `readelf`  
- Reflexiones sobre compilación vs linking  
- Lecciones aprendidas  

**Comentario:**  
Esto me ayudó a entender cómo documentar un proyecto técnico en GitHub de forma clara.

---

## 📌 Interacción 6 – README en un solo bloque
**Prompt:**  
“quiero que todo me lo des en un solo código para poner en el readme”  

**Respuesta resumida:**  
La IA entregó el contenido completo del `README.md` en un único bloque de código para copiar y pegar.  

**Comentario:**  
Fue útil porque así no tenía que armarlo a pedazos. Pude pegarlo directo en mi repo.

---

## 📌 Interacción 7 – AI Log
**Prompt:**  
“quiero que me armes de la misma manera un bloque para ai_log.md”  

**Respuesta resumida:**  
La IA preparó este archivo `ai_log.md` con un registro claro de interacciones, prompts y reflexiones.  

**Comentario:**  
Esto cierra la entrega con la documentación de cómo usé la IA en el proyecto, cumpliendo con los requisitos de la tarea.

---

## ✅ Reflexión final
El uso de la IA fue clave para:  
- Organizar el proyecto en módulos.  
- Configurar correctamente headers, `extern`, y Makefile.  
- Documentar el proceso y los errores de compilación/linking.  

La interacción fue un ciclo de **preguntar → recibir guía → implementar → refinar**.  
Gracias a esto logré completar y documentar el proyecto de manera ordenada.
